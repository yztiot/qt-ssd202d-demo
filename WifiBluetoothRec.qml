import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle{
    id: root
    width: parent.width
    height: parent.height
    color: "transparent"
    property string stateText: "未打开"

    //nState: 0为关闭wifi或蓝牙，1为开启wifi或蓝牙
    property int nState:0
    property string strFontFamily: ""

    Connections{
        target: WiFi
        function onWifiNameQml(value){
            for(var i = 0; i < value.length; i++ ){
                listModel.append({
                                     name: value[i]
                                 })
            }
        }
    }

    Text {
        id: txtState
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 90
        anchors.leftMargin: 37
        color: "white"
        font.family: strFontFamily
        font.pixelSize: 23
        text: qsTr(stateText)
    }

    /* 蓝牙或wifi打开关闭按钮 */
    Rectangle{
        id: btOpen
        width: 61
        height: 34

        anchors.verticalCenter: txtState.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 144
        color: "transparent"

        Image {
            id: imgOpenWifi
            anchors.fill: parent
            source: "./src/btSlideOff"
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(nState === 0){
                    imgOpenWifi.source= "./src/btSlideOn"
                    txtState.text = "已打开"
                    nState = 1;
                    scanTexteditview.visible = true
                    WiFi.scanWiFi();
                }else{
                    imgOpenWifi.source = "./src/btSlideOff"
                    txtState.text = "未打开"
                    nState = 0;
                    scanTexteditview.visible = false
                }
            }
        }
    }

    ScrollView {
        id: scanTexteditview
        width: 1000
        height: 460//parent.height
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 40
        anchors.topMargin: 140
    //    ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
    //    ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        clip: true
        Rectangle{
            width: 950
            height: 84
            color: "#31447B"
            radius: 5
            Text {
                id: txtConnect
                anchors.verticalCenter: parent.verticalCenter
                color: "white"
                font.pixelSize: 26
                text: qsTr("未连接")
            }
            Rectangle{
                id: btDisconnet
                width: 119
                height: 44
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 20
                radius: 8
                color: "#5A6D99"
                Text {
                    id: txtdisConnect
                    anchors.centerIn: parent
                    color: "white"
                    font.pixelSize: 22
                    text: qsTr("断开连接")
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {

                    }
                }
            }
        }

        Text{
            id: txtOtherDev
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 128
            color: "white"

            text: "其他设备"

        }

        ListView{
            id: wifiBluetoothList
            spacing: 10
            clip: true
            anchors.top: txtOtherDev.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            height: 300
            model:listModel
            delegate: Rectangle{
                width: 950
                height: 84
              //  anchors.horizontalCenter: parent.horizontalCenter
                color: "#313A6F"
                radius: 5
                Text {
                    id: txtDisConnect
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 66
                    color: "white"
                    font.pixelSize: 26
                    text: qsTr(name)
                }
            }
        }


    }




    ListModel{
        id: listModel
//        ListElement{
//            name: "未连接"
//        }
    }
}
