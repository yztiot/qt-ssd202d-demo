
import QtQuick 2.12

//主页面用于显示公司信息
Rectangle {
    id: mainPageRoot
    height: 540
    width: 1024
    color: "yellow"
   // property var fontFamily: "AlibabaPuHuiTi2"
    property var fontFamily: "微软雅黑"

    Text {
        id: txtTitle
        width: 603
        height: 96
        anchors.top: parent.top
        anchors.topMargin: 64
        anchors.left: parent.left
        anchors.leftMargin: 211
       // anchors.verticalCenter: parent.verticalCenter
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
       font.pixelSize: 30
       // font.pointSize: 30
        color: "white"
        anchors.left: txtTitle.left
        anchors.top: parent.top
        anchors.topMargin: 218
    }

    Text{
        id: txtContent
        font.pixelSize: 23
        opacity: 0.74
        text: qsTr("物联网平台及产品开发\n座机: 020-38813747\n网址: www.yztiot.com")
        font.family: fontFamily;
        anchors.left: txtCompant.left
        anchors.top: parent.top
        anchors.topMargin: 284

        color: "white"
    }

    Image {
        id: qRcodeRoot
        width: 189
        height: 189
        anchors.left: parent.left
        anchors.leftMargin: 626
        anchors.top: parent.top
        anchors.topMargin: 220
        source: "./src/yzQRCode"
    }

}
