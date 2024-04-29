import QtQuick 2.12
import QtQuick.Controls 2.12

GeneralBgPage{
    id: wifiRoot
    iconPath: "./src/iconGPIO"
    titleName: "GPIO"

    property int nLevel : 0
 //   property int iOModel: 0
    // 0:输入 1：输出
    property int nIO    : 1

    property string strName    : "gpio11"
    
    Connections{
        target: GPIO
        function onGpioSig(value){
            if(comeBackStateEdit.text === ""){
                comeBackStateEdit.text = value;
            }else{
                comeBackStateEdit.text = comeBackStateEdit.text + "\n" + value
            }
        }
    }

    DRadioButton{
       id: btGpio7
       anchors.top: parent.top
       anchors.left: parent.left
       anchors.topMargin: 120
       anchors.leftMargin: 37
       txt:"GPIO7"
       onClicked: {
           strName = "gpio7";
           GPIO.gpioModel(strName);
       }
   }

    DRadioButton{
        id: btGpio11
        checked: true
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 120
        anchors.leftMargin: 224
        txt:"GPIO11"
        onClicked: {
            strName = "gpio11";
            GPIO.gpioModel(strName);
        }
    }

    //电平按钮
    Rectangle{
        id: btLevel
        width: 159
        height: 74
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: 37
        anchors.topMargin: 177
        color: "transparent"
        Image {
            id: imgLevel
            anchors.fill: parent
            source: "./src/btLowLevel"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(nLevel == 0){
                        nLevel = 1;
                        imgLevel.source = "./src/btHeightLevel"
                        GPIO.setHighLowLevel(strName, "0")
                    }else{
                        nLevel = 0;
                        imgLevel.source = "./src/btLowLevel"
                        GPIO.setHighLowLevel(strName, "1")
                    }
                }
            }
        }
    }

    //IODirection按钮
    Rectangle{
        id: btIO
        width: 159
        height: 74
        color: "transparent"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: 231
        anchors.topMargin: 177
        Image {
            id: imgIO
            anchors.fill: parent
            source: "./src/btOutput"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(nIO == 0){
                        nIO = 1;
                        imgIO.source = "./src/btOutput"
                        GPIO.setIODirection(strName, "in")
                    }else{
                        nIO = 0;
                        imgIO.source = "./src/btInput"
                        GPIO.setIODirection(strName, "out")
                    }
                }
            }
        }
    }

    //端口状态
    Rectangle{
        id: recPortStatus
        width: 530
        height: 211
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 89
        anchors.leftMargin: 452
        color: "#B2CEFF"
        opacity: 0.3
        radius: 10

    }

    Text {
        id: txtPortStatus
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 93
        anchors.leftMargin: 677
        color: "white"
        font.pixelSize: 20
        text: qsTr("端口状态")
    }

    Rectangle{
        id: texteditRec
        width: 520
        height: 161
        anchors.top: txtPortStatus.top
        anchors.left: parent.left
        anchors.topMargin: 40
        anchors.leftMargin: 462
        color: "transparent"
        ScrollView {
            id: texteditview
            width: 520
            height: parent.height
            anchors.left: parent.left
            anchors.top: parent.top
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            clip: true

            TextEdit{
                id: comeBackStateEdit
                width: texteditview.width

                color: "white"
                //键盘选取文本默认为true
                selectByKeyboard: true
                //选中文本的颜色
                selectedTextColor: "white"
                //选中文本背景色
                selectionColor: "black"
                renderType: Text.NativeRendering
                //文本换行，默认NoWrap
                wrapMode: TextEdit.Wrap
            }
        }

    }


    Rectangle{
        id: recLine
        width: 942
        height: 1
        color: "white"
        opacity: 0.42
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 37
        anchors.topMargin: 319

    }

    Image {
        id: iconScan
        width: 25
        height: 25
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 37
        anchors.topMargin: 371
        source: "./src/iconScan"
    }

    Text {
        id: txtScan
        anchors.verticalCenter: iconScan.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 73
        font.pixelSize: 24
        color: "white"
        text: qsTr("扫描")
    }

    //I2C1 按钮
    Rectangle{
        id: btI2C1
        width: 159
        height: 74
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: 37
        anchors.topMargin: 427
        color: "transparent"
        Image {
            id: imgI2C1
            anchors.fill: parent
            source: "./src/btI2C1"
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    btI2C1.opacity = 0.5
                }
                onReleased: {
                    btI2C1.opacity = 1
                    scanStateEdit.text += I2C.checkI2C("i2c-1") +"\n"
                }
            }
        }
    }

    //I2CO按钮
    Rectangle{
        id: btI2C0
        width: 159
        height: 74
        color: "transparent"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: 231
        anchors.topMargin: 427
        radius: 8
        Image {
            id: imgI2C0
            anchors.fill: parent
            source: "./src/btI2C0"
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    btI2C0.opacity = 0.5
                }
                onReleased: {

                    btI2C0.opacity = 1
                    scanStateEdit.text += I2C.checkI2C("i2c-0")+"\n"
                }
            }
        }
    }

    //扫描结果
    Rectangle{
        id: recScan
        width: 530
        height: 211
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 350
        anchors.leftMargin: 452
        color: "#B2CEFF"
        opacity: 0.3
        radius: 10

    }

    Text {
        id: txtScanResult
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 354
        anchors.leftMargin: 677
        color: "white"
        font.pixelSize: 20
        text: qsTr("扫描结果")
    }

    Rectangle{
        id: scantxtRec
        width: 520
        height: 161
        anchors.top: txtScanResult.top
        anchors.left: parent.left
        anchors.topMargin: 40
        anchors.leftMargin: 462
        color: "transparent"
        ScrollView {
            id: scanTexteditview
            width: 520
            height: parent.height
            anchors.left: parent.left
            anchors.top: parent.top
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            clip: true

            TextEdit{
                id: scanStateEdit
                width: texteditview.width

                color: "white"
                //键盘选取文本默认为true
                selectByKeyboard: true
                //选中文本的颜色
                selectedTextColor: "white"
                //选中文本背景色
                selectionColor: "black"
                renderType: Text.NativeRendering
                //文本换行，默认NoWrap
                wrapMode: TextEdit.Wrap
            }
        }

    }


}
