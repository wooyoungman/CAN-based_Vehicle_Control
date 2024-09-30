#pragma once

#include <QObject>
#include <QtSql>

class DatabaseManager : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseManager(QObject* parent = nullptr);

    Q_INVOKABLE void startPolling();

    void insertCommand(const QString& cmd_string, const QString& arg_string);

signals:
    void sensingChanged(const QString& text);

private:
    QSqlDatabase db;
    QTimer timer;

    void init();
    void pollingQuery();
};

