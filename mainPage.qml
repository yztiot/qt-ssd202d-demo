import QtQuick 2.15

//主页面用于显示公司信息
Rectangle {
    id: mainPageRoot
    height: 540
    width: 1024
    color: "yellow"
    property var fontFamily: "Ubuntu"

    Text {
        id: txtTitle
        anchors.top: parent.top
        anchors.topMargin: 64
        anchors.left: parent.left
        anchors.leftMargin: 211
        text: qsTr("远众开发版演示系统")
        font.family: fontFamily;
        font.bold: true
        font.pixelSize: 68
        color: "#D5F4FF"
    }

    Text {
        id: txtCompant
        text: qsTr("广东远众技术有限公司")
        font.family: fontFamily;
        font.pixelSize: 68
        color: "white"
    }

    Text{
        id: txtContent
        text: qsTr("物联网平台及产品开发\n座机: 020-38813747\n网址: www.yztiot.com")
        anchors.left: txtCompant.left
        anchors.top: txtCompant.bottom
        color: "white"
    }

}
