import QtQuick 2.7
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import QtQuick.LocalStorage 2.0
import "../objects"
Page {
    DialogObject{
        id:mes_dialog
    }
    ScrollView {
        anchors.fill: parent
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        Column{
            y:spacing
            spacing: window.height*0.02


            TextField {
                id: title1
                x:window.width/2-width/2
                width:window.width*0.9
                height: window.height*0.08
                text:ip1
                font.pixelSize: Math.min(height*0.5,window.width/1900*100)
                placeholderText: qsTr("ip dev1")
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter

            }


            Button {
                    id:btn1
                    x:window.width/2-width/2
                    width:window.width *0.75
                    height:window.height / 10
                    TextControls{
                        id:btnText1
                        text:communication.isConnected(1)?"Подключено(dev1)":"Подключиться(dev1)"
                    }
                    onClicked: {
                        if (communication.isConnected(1)){
                            communication.btnDevDisconnect(1)
                            btnText1.text="Подключиться(dev1)"

                        }
                        else{
                            if (!communication.btnDevConnect(title1.text,1)){
                                btnText1.text="Подключено(dev1)"
                            }
                            else{mes_dialog.visible=true}
                        }
                   }
                }
            Button {
                    id:btn1Start
                    x:window.width/2-width/2
                    width:window.width *0.75
                    height:window.height / 10
                    TextControls{
                        id:btn1StartText
                        text:communication.isConnected(1) && btn_start_checked?"Стоп":"Старт(dev1)"
                    }
                    onClicked: {
                        if (communication.isConnected(1)){
                            if (btn1StartText.text=="Стоп"){
                                btn1StartText.text="Старт(dev1)"
                                communication.btnDevDisable(1)
                                if (btn2Start.text=="Старт(dev2)"){
                                    btn_start_checked=false
                                }
                            }
                            else{
                                btn1StartText.text="Стоп"
                                communication.btnDevEnable(1)
                                btn_start_checked=true
                            }
                        }
                        else{
                            mes_dialog.visible=true
                        }
                   }
                }
            TextField {
                id: title2
                x:window.width/2-width/2
                width:window.width*0.9
                text:ip2
                height: window.height*0.08
                font.pixelSize: Math.min(height*0.5,window.width/1900*100)
                placeholderText: qsTr("ip dev2")
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter

            }


            Button {
                    id:btn2
                    x:window.width/2-width/2
        //            y:window.height*0.1
                    width:window.width *0.75
                    height:window.height / 10
                    TextControls{
                        id:btnText2
                        text:communication.isConnected(2)?"Подключено(dev2)": "Подключиться(dev2)"
                    }
                    onClicked: {
                        if (communication.isConnected(2)){
                            communication.btnDevDisconnect(2)
                            btnText2.text="Подключиться(dev2)"
                        }
                        else{
                            if (!communication.btnDevConnect(title2.text,2)){
                                btnText2.text="Подключено(dev2)"
                            }
                            else{mes_dialog.visible=true}
                        }
                   }
                }
            Button {
                    id:btn2Start
                    x:window.width/2-width/2
                    width:window.width *0.75
                    height:window.height / 10
                    TextControls{
                        id:btn2StartText
                        text: communication.isConnected(2) && btn_start_checked?"Стоп":"Старт(dev2)"
                    }
                    onClicked: {
                        if (communication.isConnected(2)){
                            if (btn2StartText.text=="Стоп"){
                                btn2StartText.text="Старт(dev2)"
                                communication.btnDevDisable(2)
                                if (btn1Start.text=="Старт(dev1)"){
                                    btn_start_checked=false
                                }
                            }
                            else{
                                btn2StartText.text="Стоп"
                                communication.btnDevEnable(2)
                                btn_start_checked=true
                            }
                        }
                        else{
                            mes_dialog.visible=true
                        }
                   }
                }
            TextField {
                id: titleDev1Pos
                x:window.width/2-width/2
                width:window.width*0.9
                height: window.height*0.08
                font.pixelSize: Math.min(height*0.5,window.width/1900*100)
                placeholderText: qsTr("задать dev1")
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
            }
            TextField {
                id: titleDev2Pos
                x:window.width/2-width/2
                width:window.width*0.9
                height: window.height*0.08
                font.pixelSize: Math.min(height*0.5,window.width/1900*100)
                placeholderText: qsTr("задать dev2")
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
            }
            Button {
                    id:btnChangePos
                    x:window.width/2-width/2
                    width:window.width *0.75
                    height:window.height / 10
                    text:"Start(pos)"
                    onClicked: {
                        communication.btnDev1SetPos(parseInt(titleDev1Pos.text))
                        communication.btnDev2SetPos(parseInt(titleDev2Pos.text))
                    }
            }


        }
    }
}
