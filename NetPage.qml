import QtQuick 2.3
import QtQuick.Controls 2.3

GeneralBgPage{
    id: wifiRoot
    iconPath: "./src/iconNet"
    titleName: qsTr("以太网")
    property int nGetNetWorkInformation: 0
    property int nTest: 0


    function getIfconfig(){
           textEdit.text = InternetSetting.ifconfig()
    }

    Connections{
        target: InternetSetting
        function onPingSig(){
            editPing.text = editPing.text + InternetSetting.getPingStr()
        }
    }

    //获取网络信息按钮
    Image{
        id: btNetInf
        width: 159
        height: 74
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 37
        anchors.topMargin: 158
        source: "./src/btNetInf"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(nGetNetWorkInformation === 0){
                    nGetNetWorkInformation = 1;
                    btNetInf.source = "./src/btPause"
                    textEdit.clear()
                    getIfconfig();
                }else{
                    nGetNetWorkInformation = 0;
                    btNetInf.source = "./src/btNetInf"
                    InternetSetting.closeIfconfig();
                }
            }
        }
    }

    Rectangle{
        id: recPortStatus
        width: 754
        height: 211
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 89
        anchors.leftMargin: 228
        color: "#B2CEFF"
        opacity: 0.3
        radius: 10
    }

    Text {
        id: txtPortStatus
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 93
        anchors.leftMargin: 565
        color: "white"
        font.pixelSize: 20
        text: qsTr("端口状态")
    }

    ScrollView {
        id: texteditview
        width: recPortStatus.width
        height: recPortStatus.height -30
        anchors.horizontalCenter: recPortStatus.horizontalCenter
        anchors.top: recPortStatus.top
        anchors.topMargin: 30
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        clip: true

        TextEdit{
            id: textEdit
            width: texteditview.width
            color: "white"
            font.pixelSize: 12
            //截取超出部分
            //clip: true
            //默认Text.QtRendering看起来比较模糊
            renderType: Text.NativeRendering
            //文本换行，默认NoWrap
            wrapMode: TextEdit.Wrap
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

    //获取联通测试按钮
    Image{
        id: btTest
        width: 159
        height: 74
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 37
        anchors.topMargin: 419
        source: "./src/btTest"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(nTest === 0){
                    nTest = 1;
                    btTest.source = "./src/btPause"
                    editPing.text = ""
                    InternetSetting.ping();
                }else{
                    nTest = 0;
                    btTest.source = "./src/btTest"

                    InternetSetting.closePing();
                }
            }
        }
    }

    //扫描结果
    Rectangle{
        id: recScan
        width: 754
        height: 211
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 350
        anchors.leftMargin: 228
        color: "#B2CEFF"
        opacity: 0.3
        radius: 10

    }

    Text {
        id: txtScanResult
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 354
        anchors.leftMargin: 565
        color: "white"
        font.pixelSize: 20
        text: qsTr("扫描结果")
    }

    ScrollView {
        id: pingview
        width: recScan.width
        height: recScan.height -30
        anchors.horizontalCenter: recScan.horizontalCenter
        anchors.top: recScan.top
        anchors.topMargin: 30
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        clip: true

        TextEdit{
            id: editPing
            width: pingview.width
            color: "white"
            font.pixelSize: 12
            //截取超出部分
            //clip: true
            //默认Text.QtRendering看起来比较模糊
            renderType: Text.NativeRendering
            //文本换行，默认NoWrap
            wrapMode: TextEdit.Wrap
        }
    }

}
