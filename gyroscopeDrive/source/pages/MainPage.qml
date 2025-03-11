import QtQuick 2.0
import QtQuick 2.7
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import "../objects"
import QtSensors 5.0
Page {
    Timer{
        id:timerGyr
        running:false
        repeat: true
        interval: 1000
        onTriggered: {
            if (communication.isConnected(1)){readPositionTextDev1.text = "Dev1Pos:\n"+communication.readPosition(1)}
            else{readPositionTextDev1.text="Dev1Pos:\n--"}
            if (communication.isConnected(2)){readPositionTextDev2.text = "Dev2Pos:\n"+communication.readPosition(2)}
            else{readPositionTextDev2.text="Dev2Pos:\n--"}
        }
    }


    DialogObject{
        id:mes_dialog
    }

    ScrollView {
        anchors.fill: parent
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        Column{
            y:spacing*0.3
            spacing: window.height*0.06

            ComboBox {
                id:combobox
                x:window.width/2-width/2
                width:window.width *0.9
                height:window.height*0.06
                font.pixelSize: height*0.8
                font.wordSpacing: 100
                currentIndex: combobox_model
                model: ["Баскетбол", "Неваляшка", "Катапульта", "PullSmart"]
                onActivated: {
                    if (currentIndex==0){
                        ip1="192.168.0.90";
                        ip2="192.168.0.91";
                        maxPositionX=22000;
                        maxPositionY=23000;
                        if (communication.isConnected(1)){communication.btnDevDisable(1)}
                        if (communication.isConnected(2)){communication.btnDevDisable(2)}
                        if (communication.isConnected(1)){communication.btnDevDisconnect(1)}
                        if (communication.isConnected(2)){communication.btnDevDisconnect(2)}
                        btn_gyro_checked=false
                        btn_start_checked=false
                        timerGyroscope.running=false
                        stackView.push(Qt.resolvedUrl(pages[0].page))
                    }
                    if (currentIndex==1){
                        ip1="192.168.0.21";
                        ip2="192.168.0.22";
                        maxPositionX=70000;
                        maxPositionY=50000;
                        if (communication.isConnected(1)){communication.btnDevDisable(1)}
                        if (communication.isConnected(2)){communication.btnDevDisable(2)}
                        if (communication.isConnected(1)){communication.btnDevDisconnect(1)}
                        if (communication.isConnected(2)){communication.btnDevDisconnect(2)}
                        btn_gyro_checked=false
                        btn_start_checked=false
                        timerGyroscope.running=false
                        stackView.push(Qt.resolvedUrl(pages[0].page))
                    }
                    if (currentIndex==2){
                        ip1="";
                        ip2="192.168.0.10"
                        maxPositionX=0;
                        maxPositionY=3000;
                        if (communication.isConnected(1)){communication.btnDevDisable(1)}
                        if (communication.isConnected(2)){communication.btnDevDisable(2)}
                        if (communication.isConnected(1)){communication.btnDevDisconnect(1)}
                        if (communication.isConnected(2)){communication.btnDevDisconnect(2)}
                        btn_gyro_checked=false
                        btn_start_checked=false
                        timerGyroscope.running=false
                        stackView.push(Qt.resolvedUrl(pages[0].page))
                    }
                    if (currentIndex==3){
                        ip1="";
                        ip2="192.168.0.10"
                        maxPositionX=0;
                        maxPositionY=3000;
                        if (communication.isConnected(1)){communication.btnDevDisable(1)}
                        if (communication.isConnected(2)){communication.btnDevDisable(2)}
                        if (communication.isConnected(1)){communication.btnDevDisconnect(1)}
                        if (communication.isConnected(2)){communication.btnDevDisconnect(2)}
                        btn_gyro_checked=false
                        btn_start_checked=false
                        timerGyroscope.running=false
                        stackView.push(Qt.resolvedUrl(pages[0].page))
                    }
                        console.log(currentIndex)
                    combobox_model=combobox.currentIndex
                    }
            }
            Button {
                id:btnCommonConnect
                x:window.width/2-width/2
                width:window.width *0.9
                height:window.height / 10
                checked:(communication.isConnected(1) || communication.isConnected(2))? true:false
                checkable : true
                Rectangle{
                    id:btnCommonConnectColor
                    anchors.fill: parent
                    color:(communication.isConnected(1) || communication.isConnected(2))? "lightgreen":"silver"
                }
                TextControls{
                    id:btnCommonConnectText

                    text:(communication.isConnected(1) || communication.isConnected(2))?"Подключено\n"+(communication.isConnected(1)?"dev1;":"")+(communication.isConnected(2)?"dev2":""):"Подключиться"
                }
                onClicked: {
                    if (communication.isConnected(1) || communication.isConnected(2)){
                        if (communication.isConnected(1)){communication.btnDevDisconnect(1)}
                        if (communication.isConnected(2)){communication.btnDevDisconnect(2)}
                        btnCommonConnectText.text="Подключиться"
                        btnCommonConnectColor.color="silver"
                    }
                    else{
                        if (!communication.btnDevConnect(ip1,1)){
                            var text1="dev1"
                            var text3="+"

                        }
                        else{numberDevice+="dev1; ";mes_dialog.visible=true;text1="";text3=""}

                        if (!communication.btnDevConnect(ip2,2)){
                            var text2="dev2"
                        }
                        else{numberDevice+="dev2";mes_dialog.visible=true;text2="";text3=""}
                        if (text1!="" || text2!=""){
                            btnCommonConnectText.text="Подключено\n("+text1+text3+text2+")"
                            btnCommonConnectColor.color="lightgreen"
                        }
                        else{checked=false}
                        console.log(checked)
                    }
                }
            }
            Button {
                id:btnCommonStart
                x:window.width/2-width/2
                width:window.width *0.9
                height:window.height / 10
                checked:btn_start_checked? true:false
                checkable : true
                Rectangle{
                    id:btnCommonStartColor
                    anchors.fill: parent
                    color:btn_start_checked? "lightgreen":"silver"
                }
                TextControls{
                    id:btnCommonStartText
                    text:btn_start_checked?"Стоп":"Старт"
                }
                onClicked: {
                    if ((communication.isConnected(1) || communication.isConnected(2)) && !btnCommonStart.checked){
                        if (communication.isConnected(1)){communication.btnDevDisable(1)}
                        if (communication.isConnected(2)){communication.btnDevDisable(2)}
                        btnCommonStartText.text="Старт"
                        btnCommonStartColor.color="silver"
                        btn_start_checked=false
                    }
                    else if(btnCommonConnect.checked && btnCommonStart.checked){
                        if (combobox.currentIndex!=2){
                            communication.btnDevEnable(1)
                            communication.btnDevEnable(2)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                        }
                        else{//катапульта

                            communication.btnDevEnable2(1)
                            communication.btnDevEnable2(2)
                        }
                        btnCommonStartText.text="Стоп"
                        btnCommonStartColor.color="lightgreen"
                        btn_start_checked=true
                    }
                    else{
                        mes_dialog.visible=true
                        checked=false
                    }
                }
            }
            Row{
                height:window.height*0.1
                width:window.width-2*x
                x:spacing
                spacing: window.width*0.03
                Text {
                    id: readPositionTextDev1
                    color:"DimGray"
                    text: "Dev1Pos:\n--"
                    fontSizeMode: Text.Fit;
                    width:parent.width/2-parent.spacing*0.5
                    height: parent.height
                    minimumPixelSize: 5;
                    font.pixelSize: 500;
                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                }
                Text {
                    id: readPositionTextDev2
                    color:"DimGray"
                    text: "Dev2Pos:\n--"
                    fontSizeMode: Text.Fit;
                    width:parent.width/2-parent.spacing*0.5
                    height: parent.height
                    minimumPixelSize: 5;
                    font.pixelSize: 500;
                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                }
            }

            Button {
                id:btnGyro
                x:window.width/2-width/2
                width:window.width *0.75
                height:window.height / 10
                checked:btn_gyro_checked?true:false
                checkable : true
                Rectangle{
                    id:btnGyroColor
                    anchors.fill: parent
                    color:btn_gyro_checked? "lightgreen":"silver"
                }
                TextControls{
                    id:btnGyroText
                    text:btn_gyro_checked?"гироскоп(on)":"гироскоп(off)"
                }
                onClicked: {
                    if(btnCommonStart.checked){
                        if (!timerGyroscope.running){
                            previousX=1000000
                            previousY=1000000
                            timerGyroscope.running=true
                            btnGyroText.text="гироскоп(on)"
                            btnGyroColor.color="lightgreen"
                            btn_gyro_checked=true
                        }
                        else{
                            timerGyroscope.running=false
                            btnGyroText.text="гироскоп(off)"
                            btnGyroColor.color="silver"
                            checked=false
                            btn_gyro_checked=false
                        }
                    }
                    else{mes_dialog.visible=true; timerGyroscope.running=false; btnGyroText.text="гироскоп(off)"; btnGyroColor.color="silver";checked=false}
                }
            }
            Button {
                id:btnExtra
                x:window.width/2-width/2
                width:window.width *0.75
                height:window.height / 10
                TextControls{
                    id:btnExtraText
                    text:"Дополнительно"
                }
                onClicked: {
                    btn_gyro_checked=btnGyro.checked
                    btn_start_checked=btnCommonStart.checked
                    stackView.push(Qt.resolvedUrl(pages[1].page))
                }
            }
        }
    }
}
