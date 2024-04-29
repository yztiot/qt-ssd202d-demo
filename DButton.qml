import QtQuick 2.12

//自定义主页按钮
Rectangle {
    id:buttonRoot
    width: 66;
    height: 66;
    color: "transparent";
    property int imageWidth: 33
    property int imageHeight: 33
    property string btName: ""
    property string btNameColor: "white"
    property string sourcePath: ""
    Image{
        id: btImage
        width: imageWidth
        height: imageHeight
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 3
        source: sourcePath
    }

    Text {
        id: txtName
        text: qsTr(btName)
        color: btNameColor
        anchors.horizontalCenter: btImage.horizontalCenter
        anchors.top: btImage.bottom
        font.pixelSize: 19
        font.family: ""
    }

}
