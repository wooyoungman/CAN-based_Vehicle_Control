<h1 align="center"> CAN-based_Vehicle_Control </h1>
<h3 align="center"> CAN 통신 기반 차량 전장 제어 시스템  </h3>  

<table align="center">
  <tr>
    <td align="center">
      <img src="https://github.com/user-attachments/assets/9db990e8-c362-4cd5-b59d-04d7e84ec998">
      </a>
    </td>
  </tr>
</table>

<br>

<!-- TABLE OF CONTENTS -->
<h2 id="table-of-contents"> :book: Table of Contents</h2>

<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#about-the-project"> ➤ 프로젝트 소개</a></li>
    <li><a href="#prerequisites"> ➤ 기능 명세</a></li>
    <li><a href="#folder-structure"> ➤ 프로젝트 설계</a></li>
    <li><a href="#dataset"> ➤ 기능 설명</a></li>
    <li><a href="#roadmap"> ➤ 시연 영상</a></li>
  </ol>
</details>

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- ABOUT THE PROJECT -->
<h2 id="about-the-project"> :pencil: 프로젝트 소개</h2>

<p align="justify"> 
이 프로젝트는 GUI와 CAN 통신을 기반으로 차량 전장 제어를 구현한 시스템입니다. <br>
차량 내 전장 장치를 효율적으로 제어하고, 사용자 친화적인 인터페이스를 제공하여 차량 제어를 쉽게 할 수 있게 합니다. 
  <br>Qt Quick을 사용한 GUI는 직관적이고 반응이 빠르며, CAN 통신을 통해 안정적인 데이터 전송이 가능합니다.
</p>

### 🛠️기술 스택
### <p align="center">Frontend</p>
<p align="center">
  <img alt="HTML" src="https://img.shields.io/badge/HTML-E34F26.svg?&style=for-the-badge&logo=HTML5&logoColor=white"/>
  <img alt="CSS" src="https://img.shields.io/badge/CSS-1572B6.svg?&style=for-the-badge&logo=CSS3&logoColor=white"/>
  <img alt="JavaScript" src="https://img.shields.io/badge/JAVASCRIPT-F7DF1E.svg?&style=for-the-badge&logo=JavaScript&logoColor=white"/>
  <img src="https://img.shields.io/badge/Vue.js-4FC08D?style=for-the-badge&logo=Vue.js&logoColor=white">
  <img alt="Qt" src="https://img.shields.io/badge/Qt-41CD52.svg?&style=for-the-badge&logo=Qt&logoColor=white"/>
  <img alt="QML" src="https://img.shields.io/badge/QML-41CD52.svg?&style=for-the-badge&logo=QML&logoColor=white"/>
</p>

### <p align="center">Backend</p>
<p align="center">
  <img src="https://img.shields.io/badge/Node.js-5FA04E?style=for-the-badge&logo=Node.js&logoColor=white">
  <img src="https://img.shields.io/badge/MySQL-4479A1?style=for-the-badge&logo=MySQL&logoColor=white">
  <img src="https://img.shields.io/badge/C++-512BD4?style=for-the-badge&logo=Cplusplus&logoColor=white">
</p>

### <p align="center">Tools & Platforms </p>
<p align="center">
  <table align="center">
    <tr>
      <td>일정 관리, API 명세</td>
      <td>
        <a href="https://www.notion.so/seongmin-97/e67329f2603a470d9284ea3d0414cf56?v=889f29601fef496eab323786878d81c7&pvs=4">
        <img alt="RED" src ="https://img.shields.io/badge/Notion-000000.svg?&style=for-the-badge&logo=Notion&logoColor=white"/>
        </a>
      </td>
    </tr>
    <tr>
      <td>화면설계, 플로우차트</td>
      <td><img alt="draw.io" src ="https://img.shields.io/badge/Draw.io-F08705.svg?&style=for-the-badge&logo=diagramsdotnet&logoColor=white"/></td>
    </tr>
    <tr>
  </table>
</p>




### 차별점
<ol><li><p><strong>플랫폼 및 하드웨어 </strong>:</p><ul><li><strong>RENESAS</strong> 및 <strong>ESP32</strong> 사용: 실제 차량에 쓰이는 르네사스 보드를 활용, 무선 통신을 위해 ESP32를 이용함.</li></ul></li><li><p><strong>프로그래밍 및 GUI 구현</strong>:</p><ul><li><strong>Qt Quick </strong>: 기존의 Qt Widget (XML + Python)이 아닌, 더 직관적이고 현대적인 Qt Quick(QML + C++)을 사용하여 GUI를 개발.</li></ul></li><li><p><strong>통신 기술</strong>:</p><ul><li><strong>CAN 통신</strong>: UART, I2C, SPI와 같은 통신 기법 대신 차량 전장에 특화된 CAN 통신을 사용하여 안정적이고 빠른 데이터 버스 구축.</li></ul></li><li><p><strong>제어 기능</strong>:</p><ul><li><strong>GUI 입력과 센서 값 이용</strong>: 사용자는 GUI를 통해 차량의 여러 시스템을 제어할 수 있으며, 다양한 센서 값들을 실시간으로 모니터링하고 반영할 수 있음.</li></ul></li></ol>


![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- PREREQUISITES -->
<h2 id="prerequisites"> :fork_and_knife: 기능 명세</h2>


### 센서
* 온습도 센서 및 조도 센서 값 Read 후 CAN 통신을 통해 Main ESP32에 전송

### 통신
* Main ESP32(Client)로부터 센서 데이터를 받아 AWS IoT를 통해 AWS EC2의 DB에 센서 데이터 전송
  * AWS IoT Core Service에서 MySQL을 지원하지 않기 때문에 AWS Lambda를 이용
* Node.js를 활용해 Web Server를 구축하고 Main ESP32(Client)의 요청에 따라 DB의 센서 데이터 반환 및 수정
* Vue.js를 활용한 센서 데이터 분석 및 지표 시각화

### 사용자 GUI
* Qt Quick(QML / C++)을 활용한 GUI 기반의 원격 제어기 생성
* 차량 제어 명령어 DB에 전송
* 실시간으로 측정된 센서 값을 GUI에 표시

### 제어
* 차량 제어 : DB의 차량 제어 명령어에 따라 차량 구동 제어
* 센서 제어 : DB의 센서 데이터에 따라 방향 지시등, 상향등, 비상등 및 와이퍼 제어

### Open AI
* Aws EC2내에 ChatGPT 설치 및 Node.js으로부터 DB에 저장된 센서 값 읽어오기
* ChatGPT 활용하여 센서 값 데이터 분석 (현재 체감 온도 등) 및 시각화

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- :paw_prints:-->
<!-- 프로젝트 설계 -->
<h2 id="folder-structure"> :cactus: 프로젝트 설계</h2>

### 회로도
<p align="center">

#### 동작부 ESP32
  
<img src="https://github.com/user-attachments/assets/4d10cbd1-f72f-41c6-9b82-ac60e12db14d">
  
  #### 메인부 ESP32
  <img src="https://github.com/user-attachments/assets/c1196189-bf96-4acc-a516-51a1f08255cf">
  
  #### 센서부 ESP32
  
  <img src="https://github.com/user-attachments/assets/8e7639d0-415d-4703-a1a3-73ac81e41284">

  #### Renesas FPB-RA6E1
  <img src="https://github.com/user-attachments/assets/22c1059c-0aae-4b26-aec8-ecfc80897940">
</p>

---

### 차량 프레임
<p align="center">
<img src="https://github.com/user-attachments/assets/ff890672-eea5-467c-82df-370cc64380b7">
</p>

---

### 통신 아키텍처 및 프로토콜 
<p align="center">
<img src="https://github.com/user-attachments/assets/bdbf03ee-1c51-4705-90f8-e5901835ab6c">
</p>

---

### 프로토콜 별 사용 이유

#### CAN
* 3개의 ESP32 통신을 효율적으로 구축하기 위해 사용
  * 우선순위 기반의 메시지 전송을 통해 중요한 데이터가 먼저 전송되도록 하여 실시간 성능을 보장
  * 물리적 결함에 강한 네트워크 구조를 가지고 있어, 일부 노드의 장애가 전체 네트워크에 영향을 주지 않음
  * BUS를 기반으로, 각 장치가 고유한 메시지 ID를 사용하여 통신하기 때문에 시스템 확장이 용이함

#### MQTT
- 와이파이 환경을 위한 무선 통신 연결을 위함
    - 서버에 접근하기 위해 인터넷을 활용해야 했기 때문
    - 전송하는 데이터 양이 크지 않아, 가벼운 MQTT 프로토콜 사용

#### HTTP
- EC2 서버의 MySQL에 접근하는 Bridge로써 쉬운 데이터 전달과 저장을 위해 활용
    - `GET`/`PATCH` Method
 
#### SPI/I2C
* 차량의 확실한 제어를 위해 무선 통신보다 비교적 신뢰성이 높은 유선 통신 프로토콜 사용




![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<!-- 기능 설명 -->
<h2 id="dataset"> :floppy_disk: 기능 설명</h2>

### 센서 값 Read & DB 저장
<p align="center">
<img src="https://github.com/user-attachments/assets/02629660-354e-4c77-97f0-591d28a8cb7f"">
</p>

---

### 센서 값에 따른 제어
<p align="center">
  <img src="https://github.com/user-attachments/assets/6d0143f6-1429-4b05-9d69-57a3b154e52e" alt="Image 1" width="29%" height="29%">
  <img src="https://github.com/user-attachments/assets/91c3bbb7-3f74-42b6-8cbd-ac308b9c2077" alt="Image 2" width="45%">
</p>

---

### 사용자 조작에 따른 제어
<p align="center">
  <img src="https://github.com/user-attachments/assets/0e333b12-b13c-41b9-9b04-85916c9ab27e">
  <img src="https://github.com/user-attachments/assets/34aa78c5-6da8-46c2-8ba5-2c67a4108940">
</p>

---
### 측정 데이터 시각화
<p align="center">
  <img src="https://github.com/user-attachments/assets/95e5423f-316b-409c-bc61-19f638a99d3a">
</p>


<!-- ROADMAP -->
<h2 id="roadmap"> :dart: 시연 영상</h2>
<p align="center">
  <a href="https://www.youtube.com/watch?v=5BqMAm8ClnY">
    <img src="http://img.youtube.com/vi/5BqMAm8ClnY/0.jpg" alt="Video Label">
  </a>
</p>


