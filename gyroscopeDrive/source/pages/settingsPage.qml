import QtQuick 2.0
import QtQuick 2.7
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import "../objects"
import QtSensors 5.0
Page {
    ScrollView {
        anchors.fill: parent
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        Column{
            y:spacing/2
            spacing: window.height*0.02
            Text {
                id:qweasd
                color:"DimGray"
                x:window.width/2-width/2
                text: "GyroscopeX:"+accelerometerX
                fontSizeMode: Text.Fit;
                width:window.width*0.9
                height: window.height*0.08
                minimumPixelSize: 5;
                font.pixelSize: 500;
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
            }
            Text {
                id:qweasd2
                x:window.width/2-width/2

                text: "GyroscopeY:"+accelerometerY
                fontSizeMode: Text.Fit;
                width:window.width*0.9
                height: window.height*0.08
                minimumPixelSize: 5;
                font.pixelSize: 500;
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
            }
            Text {
                id:maxPositionXText
                x:window.width/2-width/2

                text: "maxPositionX:"
                fontSizeMode: Text.Fit;
                width:window.width*0.9
                height: window.height*0.08
                minimumPixelSize: 5;
                font.pixelSize: 500;
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
            }
            TextField {
                id: titleMaxPositionXText
                x:window.width/2-width/2
                width:window.width*0.9
                height: window.height*0.08
                text:maxPositionX
                font.pixelSize: Math.min(height*0.5,window.width/1900*100)
                placeholderText: qsTr("")
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                onEditingFinished: {
                    maxPositionX=titleMaxPositionXText.text
                    console.log(maxPositionX)
                    console.log(maxPositionY)
                }
            }
            Text {
                id:maxPositionYText
                x:window.width/2-width/2
                text: "maxPositionY:"
                fontSizeMode: Text.Fit;
                width:window.width*0.9
                height: window.height*0.08
                minimumPixelSize: 5;
                font.pixelSize: 500;
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
            }
            TextField {
                id: titleMaxPositionYText
                x:window.width/2-width/2
                width:window.width*0.9
                height: window.height*0.08
                text:maxPositionY
                font.pixelSize: Math.min(height*0.5,window.width/1900*100)
                placeholderText: qsTr("")
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                onEditingFinished: {
                    maxPositionY=titleMaxPositionYText.text
                }
            }
            Text {
                id:intervalMovingXText
                x:window.width/2-width/2
                text: "Интервал движения X:"
                fontSizeMode: Text.Fit;
                width:window.width*0.9
                height: window.height*0.08
                minimumPixelSize: 5;
                font.pixelSize: 500;
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
            }
            TextField {
                id: titleIntervalMovingXText
                x:window.width/2-width/2
                width:window.width*0.9
                height: window.height*0.08
                text:intervalMovingX
                font.pixelSize: Math.min(height*0.5,window.width/1900*100)
                placeholderText: qsTr("")
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                onEditingFinished: {
                    intervalMovingX=titleIntervalMovingXText.text
                    console.log(intervalMovingX)
                }
            }
            Text {
                id:intervalMovingYText
                x:window.width/2-width/2
                text: "Интервал движения Y:"
                fontSizeMode: Text.Fit;
                width:window.width*0.9
                height: window.height*0.08
                minimumPixelSize: 5;
                font.pixelSize: 500;
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
            }
            TextField {
                id: titleIntervalMovingYText
                x:window.width/2-width/2
                width:window.width*0.9
                height: window.height*0.08
                text:intervalMovingY
                font.pixelSize: Math.min(height*0.5,window.width/1900*100)
                placeholderText: qsTr("")
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                onEditingFinished: {
                    intervalMovingY=titleIntervalMovingYText.text
                    console.log(intervalMovingY)
                }
            }
            Text {
                id:sensetiveText
                x:window.width/2-width/2
                text: "Чувствительность:"
                fontSizeMode: Text.Fit;
                width:window.width*0.9
                height: window.height*0.08
                minimumPixelSize: 5;
                font.pixelSize: 500;
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
            }
            TextField {
                id: titleSensetiveText
                x:window.width/2-width/2
                width:window.width*0.9
                height: window.height*0.08
                text:sensetive
                font.pixelSize: Math.min(height*0.5,window.width/1900*100)
                placeholderText: qsTr("")
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                onEditingFinished: {
                    sensetive=text
                    console.log(sensetive)
                }
            }
        }
        Timer{
            id:timerGyr
            running:true
            repeat: true
            interval: 50
            onTriggered: {
                qweasd.text="GyroscopeX: "+accelerometerX
                qweasd2.text="GyroscopeY: "+accelerometerY
            }
        }
    }

}
