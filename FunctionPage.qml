import QtQuick 2.12

Rectangle{
    id: functionPageRoot
    width: 1024
    height: 600
    color: "transparent"
    /*wifi 按钮*/

    FunctionButton{
        id: btWifi
        anchors.left: parent.left
        anchors.top: parent.top
       // anchors.leftMargin:120
        anchors.leftMargin:90
        anchors.topMargin: 91
        imgSource:"./src/btWifi"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                btWifi.border.color = "yellow"
            }
            onReleased: {
                btWifi.border.color = "transparent"

                var createWifiPage = Qt.createComponent("WifiPage.qml").createObject(functionPageRoot);
                createWifiPage.destroySig.connect(onDestroySig);
            }
        }
    }


    /*蓝牙按钮*/
    FunctionButton{
        id: btBluetooth
        anchors.left: parent.left
        anchors.top: btWifi.top
       // anchors.leftMargin: 340
        anchors.leftMargin: 240
        imgSource:"./src/btBluetooth"
        visible: false
        MouseArea{
            anchors.fill: parent
            onPressed: {
                btBluetooth.border.color = "yellow"
            }
            onReleased: {
                btBluetooth.border.color = "transparent"
                var createBluetoothPage = Qt.createComponent("BluetoothPage.qml").createObject(functionPageRoot);
                createBluetoothPage.destroySig.connect(onDestroySig);
            }
        }
    }

    /*文件夹按钮*/
    FunctionButton{
        id: btFolder
        anchors.left: parent.left
        anchors.top: btWifi.top
       // anchors.leftMargin: 340
        anchors.leftMargin: 310
        imgSource:"./src/btFolder"

        MouseArea{
            anchors.fill: parent
            onPressed: {
                btFolder.border.color = "yellow"
            }
            onReleased: {
                btFolder.border.color = "transparent"
                var createFolderPage = Qt.createComponent("FolderPage.qml").createObject(functionPageRoot);
                createFolderPage.folderDestroySig.connect(onDestroySig);
            }
        }
    }

    /*GPIO按钮*/
    FunctionButton{
        id: btGPIO
        anchors.left: parent.left
        anchors.top: btWifi.top
        anchors.leftMargin: 529
        imgSource:"./src/btGpio"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                btGPIO.border.color = "yellow"
            }
            onReleased: {
                btGPIO.border.color = "transparent"
                var createGPIOPage = Qt.createComponent("GPIOPage.qml").createObject(functionPageRoot);
                createGPIOPage.destroySig.connect(onDestroySig);
            }
        }
    }

    /*串口按钮*/
    FunctionButton{
        id: btSerial
        anchors.left: parent.left
        anchors.top: btWifi.top
        anchors.leftMargin: 749
        imgSource: "./src/btSerial"

        MouseArea{
            anchors.fill: parent
            onPressed: {
                btSerial.border.color = "yellow"
            }
            onReleased: {
                btSerial.border.color = "transparent"
                var createSerialPage = Qt.createComponent("SerialPage.qml").createObject(functionPageRoot);
                createSerialPage.destroySig.connect(onDestroySerialSig);
            }
        }
    }

    /*以太网按钮*/
    FunctionButton{
        id: btNet
        anchors.left: btWifi.left
        anchors.top: parent.top
        anchors.topMargin: 342
        imgSource: "./src/btNet"

        MouseArea{
            anchors.fill: parent
            onPressed: {
                btNet.border.color = "yellow"
            }
            onReleased: {
                btNet.border.color = "transparent"
                var createNetPage = Qt.createComponent("NetPage.qml").createObject(functionPageRoot);
                createNetPage.destroySig.connect(onDestroySig);
            }
        }
    }

    /*画板*/
    FunctionButton{
        id: btDraw
        anchors.left: btFolder.left
        anchors.top: btNet.top
        imgSource: "./src/btDraw"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                btDraw.border.color = "yellow"

            }
            onReleased: {
                btDraw.border.color = "transparent"
                var createDraw = Qt.createComponent("DrawPage.qml").createObject(functionPageRoot);

            }
        }
    }

    /*音频*/
    FunctionButton{
        id: btSound
        anchors.left: btGPIO.left
        anchors.top: btNet.top
        imgSource: "./src/btSound"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                btSound.border.color = "yellow"

            }
            onReleased: {
                btSound.border.color = "transparent"
                var createDraw = Qt.createComponent("SoundPage.qml").createObject(functionPageRoot);
                createDraw.destroySig.connect(stopPlay);

            }
        }
    }

    /*系统设置*/
    FunctionButton{
        id: btSetting
        anchors.left: btSerial.left
        anchors.top: btNet.top
        imgSource: "./src/btSetting"

        MouseArea{
            anchors.fill: parent
            onPressed: {
                btSetting.border.color = "yellow"

            }
            onReleased: {
                btSetting.border.color = "transparent"
                var createSettingPage = Qt.createComponent("SettingPage.qml").createObject(functionPageRoot);
              //  createSettingPage.destroySig.connect(onDestroySig);
            }
        }
    }

    function onDestroySig(){
      //  swipeView.interactive = true
    }
    function stopPlay(){
      //  swipeView.interactive = true
        Sound.musicStop()
    }


    function onDestroySerialSig(){

        swipeView.interactive = true
        SerialFunction.closeSerial();
    }

}
