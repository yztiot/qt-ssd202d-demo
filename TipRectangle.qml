import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.VirtualKeyboard 2.1
import QtQuick.VirtualKeyboard.Settings 2.1

Rectangle {
    id: tipRoot
    width: parent.width
    height: parent.height
    color: "transparent"
    property string titleName: ""
    property string oldName: ""
    property bool  showDel: false
    //0为编辑，1为删除，2为添加 3为输入为wifi密码
    property int  tipModel: 0
    property string delName: ""
    property string addName: ""
    property string smallTip: "输入文件名称"
    property int inputX: 0 // 键盘x坐标(动态)
    property int inputY: tipRoot.height // 键盘y坐标(动态)
    signal waitingSig();


    Rectangle{
        width: parent.width
        height: parent.height
        color: "black"
        opacity: 0.64
        visible: true
        MouseArea{
            anchors.fill: parent
        }
    }

    Rectangle{
        id: tipEdit
        width: 584
        height: 354
        color: "#33496E"
        anchors.centerIn: parent
        Text {
            id: title
            anchors.top: parent.top
            anchors.topMargin: 23
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"
            font.pixelSize: 24
            text: qsTr(titleName)
        }
        Text{
            id: secondTitle
            visible: !showDel
            anchors.top: parent.top
            anchors.topMargin: 88
            anchors.left: parent.left
            anchors.leftMargin: 82
            color: "white"
            font.pixelSize: 20
            text: qsTr(smallTip)
        }
        Rectangle{
            id: inputRoot
            width: 421
            height: 48
            visible: !showDel
            anchors.left:parent.left
            anchors.leftMargin: 81
            anchors.top: parent.top
            anchors.topMargin: 122
            color:  "#C2D7f9"
            radius: 12

            TextField {
                id:inputTxt
                color: "black"
                focus: true
                width: parent.width// - 40
                height: parent.height
                anchors.left: parent.left
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                onPressed:{
                    inputX = x
                  //  inputY = 500//y //+ inputTxt.height
                    inputPanel.visible = true
                }
            }
        }

        Text {
            id: delTxt
            visible: showDel
            color: "white"
            font.pixelSize: 28
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 120
            text: qsTr("确定删除（" + delName + "）文件")

        }


        Rectangle{
            id: btCancel
            width: 113
            height: 42
            radius: height / 2
            anchors.left: parent.left
            anchors.leftMargin: 152
            anchors.top: parent.top
            anchors.topMargin: 252
            color: "white"
            Text {
                id: cancelTxt
                color: "black"
                font.pixelSize: 18
                anchors.centerIn: parent
                text: qsTr("取消")

            }
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    btCancel.color = "#0080FF"
                    cancelTxt.color = "white"

                }onReleased: {
                    btCancel.color = "white"
                    cancelTxt.color = "black"
                    inputTxt.text = ""
                    inputPanel.visible = false
                    waitingSig();

                    tipRoot.visible = false

                }
            }
        }

        Rectangle{
            id: btOk
            width: 113
            height: 42
            radius: height / 2
            anchors.left: parent.left
            anchors.leftMargin: 320
            anchors.top: parent.top
            anchors.topMargin: 252
            color: "white"
            Text {
                id: okTxt
                color: "black"
                font.pixelSize: 18
                anchors.centerIn: parent
                text: qsTr("确认")
            }

            MouseArea{
                anchors.fill: parent
                onPressed: {
                    btOk.color = "#0080FF"
                    okTxt.color = "white"
                }onReleased: {
                    btOk.color = "white"
                    okTxt.color = "black"
                    if(tipModel === 0){
                        Folder.editFolder(oldName, inputTxt.text)

                    }else if(tipModel === 1){
                        Folder.deleteFolder(delName)
                    }else if(tipModel === 2){
                        Folder.addFolder(inputTxt.text)
                    }else if(tipModel === 3){
                        WiFi.connectWiFi(smallTip, inputTxt.text)



                      //  waitingSig();

                    }
                    inputTxt.text = ""
                    inputPanel.visible = false
                    tipRoot.visible = false
                }
            }
        }

        Image {
            id: btClose
            width: 17
            height: 17
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 562
            anchors.topMargin: 8
            source: "./src/iconClose"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    inputTxt.text = ""
                    inputPanel.visible = false
                    tipRoot.visible = false
                }
            }
        }


    }

    // 嵌入式虚拟键盘
    InputPanel {
        id: inputPanel
        z: 98
        //更改x,y即可更改键盘位置
        x: 0//inputRoot.x
        y: 450 //parent.height / 3
        //更改width即可更改键盘大小
        width: parent.parent.width
        height: 200

        externalLanguageSwitchEnabled: false
        visible: false

        states: State {
            name: "visible"
            when: inputPanel.active
//                PropertyChanges {
//                    target: inputPanel
//                    // 将键盘顶部放在屏幕底部会使其隐藏起来
//                    x: inputX
//                    y: inputY
//                }
        }

        Component.onCompleted: {
            VirtualKeyboardSettings.locale = "eesti" // 复古键盘样式
            VirtualKeyboardSettings.wordCandidateList.alwaysVisible = true
        }

        //这种集成方式下点击隐藏键盘的按钮是没有效果的，只会改变active，因此我们自己处理一下
        onActiveChanged: {
            if(!active) { visible = false }
        }
    }
}
