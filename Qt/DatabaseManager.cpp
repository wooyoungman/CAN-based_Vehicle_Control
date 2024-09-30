#include "DatabaseManager.h"
#include <QDebug>

DatabaseManager::DatabaseManager(QObject* parent) : QObject(parent)
{
    init();
}

void DatabaseManager::init()
{
    qDebug() << "INIT";
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("xx.xx.xx.xx"); // id
    db.setUserName("wooyoung");
    db.setPort(3306);
    db.setPassword("xxxx"); // pwd
    db.setDatabaseName("wooDB");

    if (db.open()) {
        qDebug() << "Database connected successfully.";
    }
    else {
        qDebug() << "Failed to connect to database:" << db.lastError().text();
    }

    timer.setInterval(500); // 센서 값 500ms 주기로 갱신
    connect(&timer, &QTimer::timeout, this, &DatabaseManager::pollingQuery);
}

void DatabaseManager::startPolling() {
    timer.start();
}

void DatabaseManager::pollingQuery()
{
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        return;
    }

    QSqlQuery query(db);
    if (!query.exec("SELECT temperature, humidity FROM sensing WHERE id = (SELECT MAX(id) FROM sensing)")) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
        return;
    }

    QString text;
    if (query.next()) {
        text = QString("Temperature: %1°C \n Humidity: %2%")
            .arg(query.value(0).toInt())
            .arg(query.value(1).toInt());
    }
    else {
        text = "No data available";
    }

    emit sensingChanged(text);
    db.commit();
}

void DatabaseManager::insertCommand(const QString& cmd_string, const QString& arg_string)
{
    QDateTime time = QDateTime::currentDateTime();
    int is_finish = 0;

    QSqlQuery query;
    query.prepare("insert into command(time, cmd_string, arg_string, is_finish) values (:time, :cmd_string, :arg_string, :is_finish)");
    query.bindValue(":time", time);
    query.bindValue(":cmd_string", cmd_string);
    query.bindValue(":arg_string", arg_string);
    query.bindValue(":is_finish", is_finish);
    query.exec();
    db.commit();
}
