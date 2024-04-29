import QtQuick 2.12

Rectangle{
    id: bgRoot
//    width: parent.width
//    height: parent.height
    width: 1024
    height: 600

    property string titleName: ""
    property string iconPath: ""

    signal destroySig();

    //屏蔽穿透点击
    MouseArea{
        anchors.fill: parent
    }

    Component.onCompleted: {
        timer.start();
    }

    Connections{
        target: SystemSetting
        function onUpdateTimeSig(){
            showTime.text = currentDateTime();
        }
    }

    Image {
        id: imgBg
        anchors.fill: parent
        source: "./src/secondBg"
    }

    Rectangle{
        id: recTurnLeft
        width: 70
        height: 60
        anchors.left: parent.left
        anchors.top: parent.top
        color: "transparent"
        Image {
            id: imgTurnLeft
            width: 34
            height: 34
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
           // anchors.centerIn: parent
            source: "./src/turnLeft"

        }
        MouseArea{
            id: destroyMouse
            anchors.fill: parent
            onClicked: {
                console.log("destory page")
                bgRoot.destroySig()
                bgRoot.destroy();
            }
        }
    }

    Rectangle{
        id: recTitleIcon
        width: 60
        height: 60
        anchors.verticalCenter: recTurnLeft.verticalCenter
        anchors.left: recTurnLeft.right
        color: "transparent"
        Image {
            id: titleIcon
            width: 34
            height: 34
            anchors.centerIn: parent
            source: iconPath
        }
    }

    Text {
        id: titleNameText
        anchors.verticalCenter: recTitleIcon.verticalCenter
        anchors.left: recTitleIcon.right
        anchors.leftMargin: 10
        text: titleName
        color: "white"
        font.pixelSize: 28
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
        var strDateBG = "";
        switch(ti.getDate()){
            case 1: strDateBG = qsTr("周一"); break;
            case 2: strDateBG = qsTr("周二"); break;
            case 3: strDateBG = qsTr("周三"); break;
            case 4: strDateBG = qsTr("周四"); break;
            case 5: strDateBG = qsTr("周五"); break;
            case 6: strDateBG = qsTr("周六"); break;
            default : strDateBG = qsTr("周日") ;

        };

        var year = ti.getFullYear();
        var mon  = addZero(ti.getMonth());
        var day  = addZero(ti.getDay());
        var hh   = addZero(ti.getHours());
        var mm   = addZero(ti.getMinutes());

        strDateBG = strDateBG+ "     "+ year+ "/"+ mon+ "/"+ day+ "    "+ hh+ ": "+ mm ;

        return strDateBG;
    }

    Timer{
        id: timer
        repeat: true
        interval: 60000
        onTriggered: {
            showTime.text = currentDateTime();
        }
    }

    //显示时间
    Text {
        id: showTime
        anchors.left: parent.left
        anchors.leftMargin: 764
        anchors.verticalCenter: recTurnLeft.verticalCenter
        color: "white"
        text: currentDateTime()
    }

}
