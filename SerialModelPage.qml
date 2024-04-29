import QtQuick 2.12

Rectangle {
    id: serialModelRoot
    width: parent.width
    height: parent.height
    color:"transparent"

    //nSerialModel 0表示485 1表示232
    property int nSerialModel: 0
    property bool bOpen: false
    property alias btSource: btOpenSerial.source

    DRadioButton{
       id: bt485
       checked: true
       anchors.top: parent.top
       anchors.left: parent.left
       anchors.topMargin: 30
       anchors.leftMargin: 27
       txt:"RS485"
       font.pixelSize: 16
       onClicked: {
            nSerialModel = 0;
       }
   }

    DRadioButton{
        id: bt232
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 30
        anchors.leftMargin: 174
        txt:"RS232"
        font.pixelSize: 16
        onClicked: {
            nSerialModel = 1;
        }
    }

   //串口按钮
    Image {
        id: btOpenSerial
        width: 95
        height: 38
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 30
        anchors.topMargin: 100
        source: "./src/btOpenSerial"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                //判断是否打开串口通讯
                if(!bOpen){
                    SerialFunction.runOpenSerial(baudMenu.showText, bitMenu.showText, checkMenu.showText, stopMenu.showText)
                }else{
                    bOpen = false;
                    baseSettingRec.bOpenSerial = false
                    btOpenSerial.source =  "./src/btOpenSerial"
                    SerialFunction.closeSerial();
                }
            }
        }
    }

    //清屏按钮
    Image {
        id: btCleanUp
        width: 95
        height: 38
        anchors.left: parent.left
        anchors.top: btOpenSerial.top
        anchors.leftMargin: 180

        source: "./src/btCleanUp"
        MouseArea{
            anchors.fill: parent
            onPressed:{
                btCleanUp.source = "./src/btCleanUpPress"
            }
            onReleased: {
                btCleanUp.source = "./src/btCleanUp"
                comeBackStateEdit.text = ""
            }
        }
    }
}
