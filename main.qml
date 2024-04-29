import QtQuick 2.12
import QtQuick.Window 2.15
import QtQuick.Controls 2.2
import QtQuick.VirtualKeyboard 2.1

Window {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Demo")
    //  flags: Qt.FramelessWindowHint | Qt.CustomizeWindowHint
    // modality: Qt.WindowModal

    Component.onCompleted: {
        timer.start();
    }

    Connections{
        target: SystemSetting
        function onScreenSaveSig(){
            screenSaveimg.visible = true
        }
    }

    Image {
        id: screenSaveimg
        width: parent.width
        height: parent.height
        visible: true
        z:99
        source: "./src/introducePage"
      //  source: "./src/a2.png"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                screenSaveimg.visible = false;
            }
        }
    }

    // 判断时间是否小于10
    function addZero(zero){
        if(zero < 10)
            return "0"+zero;
        else
            return zero;
    }

    //获取时间字符;
    function currentDateTime(){

        var ti = new Date;
        var strDateMain = "";
        switch(ti.getDate()){
        case 1: strDateMain = qsTr("周一"); break;
        case 2: strDateMain = qsTr("周二"); break;
        case 3: strDateMain = qsTr("周三"); break;
        case 4: strDateMain = qsTr("周四"); break;
        case 5: strDateMain = qsTr("周五"); break;
        case 6: strDateMain = qsTr("周六"); break;
        default : strDateMain = qsTr("周日") ;

        };

        var year = ti.getFullYear();
        var mon  = addZero(ti.getMonth());
        var day  = addZero(ti.getDay());
        var hh   = addZero(ti.getHours());
        var mm   = addZero(ti.getMinutes());

        strDateMain = strDateMain+ "        "+ year+ "/"+ mon+ "/"+ day+ "  "+ hh+ ": "+ mm ;

        return strDateMain;
    }

    Timer{
        id: timer
        repeat: true
        interval: 60000
        onTriggered: {
            showTime.text = currentDateTime();
        }
    }

    Rectangle{
        id: rootRec
        width: parent.width
        height: parent.height

        //背景图
        Image {
            id: rootbg
            anchors.fill: parent
            source: "./src/mainBg"
        }

        //logo图
        Image {
            id: rootLogo
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.leftMargin: 58
            source: "./src/logo"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                }
            }
        }

        Text {
            id: yztiotName
            anchors.left: parent.left
            anchors.leftMargin: 455
            anchors.verticalCenter: rootLogo.verticalCenter
            font.pixelSize: 32
            color: "#2F97D2"
            font.bold: true
            text: qsTr("远众演示")
        }

        //显示时间
        Text {
            id: showTime
            anchors.left: parent.left
            anchors.leftMargin: 764
            anchors.verticalCenter: rootLogo.verticalCenter
            color: "white"
            text: currentDateTime()
        }

        SwipeView {
            id: swipeView
            width: 1024
            height: 600
            interactive : true
            orientation: Qt.Vertical

            Item{
                width: 1024
                height: 600
                FunctionPage{
                    id: functionPageRoot
                    visible: true
                    width: parent.width
                    height: parent.height
                }
            }
        }
    }

}
