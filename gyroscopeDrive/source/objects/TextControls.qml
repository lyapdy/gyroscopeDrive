import QtQuick 2.0

Text {
    color:"DimGray"
    x:parent.width/2-width/2
    y:parent.height/2-height/2
    fontSizeMode: Text.Fit;
    width:parent.width*0.9
    height: parent.height*0.9
    minimumPixelSize: 5;
    font.pixelSize: 500;
    horizontalAlignment: TextInput.AlignHCenter
    verticalAlignment: TextInput.AlignVCenter

}
