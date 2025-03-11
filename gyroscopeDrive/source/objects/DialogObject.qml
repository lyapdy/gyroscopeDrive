import QtQuick 2.0
import QtQuick 2.7
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
Dialog {
    id:mes_dialog
    visible:false
    x:window.width/2-width/2
    y:window.height*0.38-mes_dialog.height/2
    width:window.width*0.9
    height:window.height*0.25
    onRejected: {
        numberDevice=""
    }

    Column{
        width: parent.width
        height: parent.height
        spacing:parent.height*0.15
        y:spacing
        Text {
            id:text
            color:"red"
            text:"ПОДКЛЮЧЕНИЕ НЕВОЗМОЖНО\n"+numberDevice
            x:parent.width/2-width/2
            fontSizeMode: Text.Fit;
            width:parent.width*0.96
            height: parent.height*0.37
            minimumPixelSize: 5;
            font.pixelSize: 500;
            horizontalAlignment: TextInput.AlignHCenter
            verticalAlignment: TextInput.AlignVCenter

        }

        Button {
            x:parent.width/2-width/2
            width: parent.width*0.8
            height: parent.height*0.33
            TextControls{
                text:"ОК"
            }
            onClicked: {
                mes_dialog.visible=false
                numberDevice=""
             }
        }
    }
}
