import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.2
import QtQml 2.0
import qwe 1.0
import QtSensors 5.0
import "objects"
ApplicationWindow {
    id:window
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Scroll")
    property var accelerometerX;
    property var accelerometerY;
    property int maxPositionX:22000;
    property int maxPositionY:23000;
    property string ip1:"192.168.0.90";
    property string ip2:"192.168.0.91";
    property int combobox_model:0;
    property bool btn_start_checked:false;
    property bool btn_gyro_checked:false;
    property int intervalMovingX:15
    property int intervalMovingY:15
    property int previousX:10000000
    property int previousY:10000000
    property double sensetive:0.05
    property string numberDevice: ""
    property int device:1
    property int state:0

    property list<PageObject> pages: [
        /* 0  */             PageObject { title: "PullSmart!";                             page: "qrc:/pages/MainPage.qml"                     },
        /* 1  */             PageObject { title: "PullSmart!";                             page: "qrc:/pages/ExtraPage.qml"                     },
        /* 2  */             PageObject { title: "PullSmart!";                             page: "qrc:/pages/SettingsPage.qml"                     }

    ]

    Communication {
        id: communication
    }

    header: ToolBar {
        id: mainToolbar
        height: window.height/16
        Rectangle{
            anchors.fill: parent
            color: "silver"
        }

        MouseArea {
            id:btnback
            visible:true
            width:height
            height:parent.height
            anchors.left: parent.left
               Image {
                   anchors.fill: parent
                   source: "images/back.png"
               }
               onClicked:  {stackView.push(Qt.resolvedUrl(pages[0].page))}
           }

        MouseArea {
            id:btnsettings
            width:height
            height:parent.height
            anchors.right: parent.right

            Image {
                anchors.fill: parent
                source: "images/settings.png"
            }
            onClicked:  {stackView.push(Qt.resolvedUrl(pages[2].page))}
        }
    }





    StackView {
        id: stackView
        anchors.fill: parent
        Component.onCompleted: {
            stackView.push(Qt.resolvedUrl(pages[0].page))
        }
    }
    Timer{
        id:timerGyroscope
        running:false //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        repeat: true
        interval: 100
        onTriggered: {
            gyroscopeMove(accelerometerX,accelerometerY)
        }
    }

    Accelerometer {

        id: gyroscope
        //alwaysOn: true
        //axesOrientationMode: Gyroscope.FixedOrientation
        //skipDuplicates: true
        active: true

        onReadingChanged: {
            accelerometerX=reading.x
            accelerometerY=reading.y

        }
    }




    function gyroscopeMove(x,y){
        if (combobox_model!==2){
            var x1=maxPositionX/2-maxPositionX/2/intervalMovingX*parseInt(x)
            var y1=maxPositionY/2+maxPositionY/2/intervalMovingY*parseInt(y)
            if (sensetive<Math.abs((previousX-x1))/maxPositionX){
                previousX=x1
                communication.btnDev1SetPos(parseInt(x1))//!!!!!!!!!!
            }
            if (sensetive<Math.abs((previousY-y1))/maxPositionY){
                previousY=y1
                communication.btnDev2SetPos(parseInt(y1))//!!!!!!!
            }
        }
        else{
            var startPos=8000;
            var y1=startPos+maxPositionY/2+maxPositionY/2/10*parseInt(y)
            var flag=false;

            if (Math.abs(y1-previousY)<maxPositionY/20){flag=true}

            if (y1<startPos+maxPositionY/4 && flag){
                state=0
            }
            if (y1>startPos+maxPositionY/4 && y1<startPos+maxPositionY/4*2 && flag){
                state=1
            }
            if (y1<startPos+maxPositionY/4*3 && y1>startPos+maxPositionY/4*2 && flag){
                state=2
            }
            if (y1>startPos+maxPositionY/4*3 && flag){
                state=3
            }
            console.log(state)
            if (flag){
                communication.btnDev2SetPos(startPos+maxPositionY/4*state)

            }
            previousY=y1
        }
    }


}
