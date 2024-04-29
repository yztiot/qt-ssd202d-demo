import QtQuick 2.15
import Qt.labs.platform 1.1
import QtQuick.Controls 2.15

//import QtQuick.VirtualKeyboard 2.15

GeneralBgPage{
    id: wifiRoot
    iconPath: "./src/iconSerial"
    titleName: qsTr("串口测试")

    Rectangle{
        z:10
        id: baseSettingRec
        width: 312
        height: 314
        anchors.left: parent.left
        anchors.top:parent.top
        anchors.leftMargin: 37
        anchors.topMargin: 84
        color: "transparent"
        radius: 12
        property bool bOpenSerial: false

        Connections{
            target: SerialFunction
            function onSerialDataSig(value){
                comeBackStateEdit.text = comeBackStateEdit.text +"\n"+  value
                comeBackStateEdit.persistentSelection = true;
            }
            function onWriteSig(value){
                comeBackStateEdit.text = comeBackStateEdit.text +"\n"+  value
            }
            function onOpenSerialSuccessful(value){
                serialModel.bOpen = true;
                baseSettingRec.bOpenSerial = true;
                serialModel.btSource =  "./src/btCloseSerial"
                comeBackStateEdit.text = comeBackStateEdit.text +"\n"+  value

            }
            function onOpenSerialFail(value){
                serialModel.bOpen = false;
                baseSettingRec.bOpenSerial = false;
                serialModel.btSource =  "./src/btOpenSerial"
                comeBackStateEdit.text = comeBackStateEdit.text +"\n"+  value
            }

            function onTipSig(value){
                comeBackStateEdit.text = comeBackStateEdit.text +"\n"+  value
            }
        }

        Rectangle{
            anchors.fill: parent
            color: "#82CEFF"
            opacity: 0.23
            radius: 12
        }

        Text {
            id: txtBaud
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 34
            anchors.topMargin: 41
            font.pixelSize: 18
            color: "white"
            text: qsTr("波特率")
        }

        Rectangle{
            id: recBaud
            z:6
            width: 150
            height: 52
            anchors.verticalCenter: txtBaud.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 118
            color: "#11234A"
            radius: 12
            DMenu{
                id: baudMenu
                anchors.top: recBaud.bottom
                visible: false
                listHeight: 250
                showText: "9600"
                model:[1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200]
            }
            Text {
                id: txtBaudChose
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 20
                font.pixelSize: 18
                color: "white"
                text: qsTr(baudMenu.showText)
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(baseSettingRec.bOpenSerial){
                        baudMenu.visible = false;
                    }else{
                        if(baudMenu.visible){
                            baudMenu.visible = false;
                        }else{
                            baudMenu.visible = true;
                        }
                    }
                }
            }
        }

        Text {
            id: txtBit
            anchors.left: txtBaud.left
            anchors.top: parent.top
            anchors.topMargin: 110
            font.pixelSize: 18
            color: "white"
            text: qsTr("数据位")
        }

        Rectangle{
            id: recBit
            width: 150
            height: 52
            z:5
            anchors.verticalCenter: txtBit.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 118
            color: "#11234A"
            radius: 12
            DMenu{
                id: bitMenu
                anchors.top: recBit.bottom
                visible: false
                listHeight: 120
                showText: "8"
                model:[5, 6, 7, 8]
            }

            Text {
                id: txtBitChose
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 20
                font.pixelSize: 18
                color: "white"
                text: qsTr(bitMenu.showText)
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(baseSettingRec.bOpenSerial){
                        bitMenu.visible = false;
                    }else{
                        if(bitMenu.visible){
                            bitMenu.visible = false;
                        }else{
                            bitMenu.visible = true;
                        }
                    }
                }
            }


        }

        Text {
            id: txtCheck
            anchors.left: txtBaud.left
            anchors.top: parent.top
            anchors.topMargin: 181
            font.pixelSize: 18
            color: "white"
            text: qsTr("校验位")
        }

        Rectangle{
            id: recCheck
            width: 150
            height: 52
            z:4
            anchors.verticalCenter: txtCheck.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 118
            color: "#11234A"
            radius: 12
            DMenu{
                id: checkMenu
                anchors.top: recCheck.bottom
                visible: false
                listHeight: 150
                showText: "None"
                model:["None", "Odd", "Eyen Mark", "Space"]
            }
            Text {
                id: txtCheckChoose
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 20
                font.pixelSize: 18
                color: "white"
                text: qsTr(checkMenu.showText)
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(baseSettingRec.bOpenSerial){
                        checkMenu.visible = false;
                    }else{
                        if(checkMenu.visible){
                            checkMenu.visible = false;
                        }else{
                            checkMenu.visible = true;
                        }
                    }
                }
            }


        }

        Text {
            id: txtStop
            anchors.left: txtBaud.left
            anchors.top: parent.top

            anchors.topMargin: 250
            font.pixelSize: 18
            color: "white"
            text: qsTr("停止位")
        }

        Rectangle{
            id: recStop
            width: 150
            height: 52
            z:3
            anchors.verticalCenter: txtStop.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 118
            color: "#11234A"
            radius: 12
            DMenu{
                id: stopMenu
                anchors.top: recStop.bottom
                visible: false
                listHeight: 100
                showText: "1"
                model:[1, 1.5, 2]

            }
            Text {
                id: txtStopChose
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 20
                font.pixelSize: 18
                color: "white"
                text: qsTr(stopMenu.showText)
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(baseSettingRec.bOpenSerial){
                        stopMenu.visible = false;
                    }else{
                        if(stopMenu.visible){
                            stopMenu.visible = false;
                        }else{
                            stopMenu.visible = true;
                        }
                    }
                }
            }


        }

    }

    //模式485/232选择模式框
    Rectangle{
        id: modelRec
        width: 312
        height: 164
        anchors.left: parent.left
        anchors.top:parent.top
        anchors.leftMargin: 37
        anchors.topMargin: 406
        color: "transparent"
        radius: 12
        Rectangle{
            anchors.fill: parent
            color: "#82CEFF"
            radius: 12
            opacity: 0.23
        }

        SerialModelPage{
            id: serialModel
        }

    }

    //返回状态框
    Rectangle{
        id: stateRec
        width: 630
        height: 243
        anchors.left: parent.left
        anchors.top:parent.top
        anchors.leftMargin: 357
        anchors.topMargin: 84
        color: "transparent"
        radius: 12
        Rectangle{
            anchors.fill: parent
            color: "#82CEFF"
            radius: 12
            opacity: 0.23
        }

        Text {
            id: txtState
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            color:"white"
            font.pixelSize: 20

            text: qsTr("状态")
        }

        ScrollView {
            id: textedit_1_view
            width: 600
            height: 200
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top: txtState.bottom
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            clip: true

            TextEdit{
                id: comeBackStateEdit
                width: textedit_1_view.width
                color: "white"
                //鼠标选取文本默认为false
                selectByMouse: true
                //键盘选取文本默认为true
                selectByKeyboard: true
                //选中文本的颜色
                selectedTextColor: "white"
                //选中文本背景色
                selectionColor: "black"
                //截取超出部分
                //clip: true
                //默认Text.QtRendering看起来比较模糊
                renderType: Text.NativeRendering
                //文本换行，默认NoWrap
                wrapMode: TextEdit.Wrap
            }
        }

    }

    //键盘框
    Rectangle{
        id: keyBoardec
        width: 630
        height: 235
        anchors.left: parent.left
        anchors.top:parent.top
        anchors.leftMargin: 357
        anchors.topMargin: 335
        color: "transparent"
        radius: 12
        Rectangle{
            anchors.fill: parent
            color: "#82CEFF"
            radius: 12
            opacity: 0.23
        }

        KeyBoardPage{
            id: keyboard
        }

    }

}
