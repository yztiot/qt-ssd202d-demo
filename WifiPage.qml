import QtQuick 2.12
import QtQuick.Controls 2.12


GeneralBgPage{
    id: wifiRoot
    iconPath: "./src/iconWifi"
    titleName: "WiFi"
    property string stateText: "未打开"

    //nState: 0为关闭wifi或蓝牙，1为开启wifi或蓝牙
    property bool nState:false
    property string strFontFamily: ""
    property var wifiNameList
    property int currentChooseWifi: 0


    Component.onCompleted: {

        nState = WiFi.getWifiCurrentState();
      //  console.log("hello nState::"+ nState);
        if(!nState){
            imgOpenWifi.source = "./src/btSlideOff"
            txtState.text = "未打开"
            WiFi.setWifiCurrentState(false)
            wifiBluetoothList.visible = false
        }else{
            imgOpenWifi.source= "./src/btSlideOn"
            txtState.text = "已打开"
            WiFi.setWifiCurrentState(true)
            wifiBluetoothList.visible = true


           // var wifiNameList;
            wifiNameList = WiFi.getWifiNameList()
            listModel.clear()
            for(var i = 0; i < wifiNameList.length; i++ ){
                listModel.append({
                                     name: wifiNameList[i],
                                     loadVisible: false
                                 })
            }
        }
    }

    function onWaitingSig(){
        console.log("on loading::"+ index +"::"+ wifiBluetoothList.currentIndex);
    }

    Connections{
        target: WiFi
        function onWifiNameQml(value){
            wifiNameList = ""
            wifiNameList = value
            listModel.clear()
            for(var i = 0; i < wifiNameList.length; i++ ){
                listModel.append({
                                     name: wifiNameList[i],
                                     loadVisible: false
                                 })
            }
        }

        function onConnectCurrentNameSig(value){
            txtConnect.text = value//"已连接"
            listModel.clear()
            for(var i = 0; i < wifiNameList.length; i++ ){
                listModel.append({
                                     name: wifiNameList[i],
                                     loadVisible: false
                                 })
            }
        }

        function onDisCurrentWifiSigQml(){
            listModel.set(currentChooseWifi, {loadVisible: false})
            txtConnect.text = qsTr("未连接")
            listModel.clear()
        }
    }

    Connections{
        target: connectTip
        function onWaitingSig(){
            console.log("waiting current::"+ currentChooseWifi)
         //   listModel.set(currentChooseWifi, {"loadVisible": false})
            listModel.clear()
            for(var i = 0; i < wifiNameList.length; i++ ){
                listModel.append({
                                     name: wifiNameList[i],
                                     loadVisible: false
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
                nState = WiFi.getWifiCurrentState();
                if(!nState){
                    imgOpenWifi.source= "./src/btSlideOn"
                    txtState.text = "已打开"
                    WiFi.setWifiCurrentState(true)
                    wifiBluetoothList.visible = true
                //    waittingPage.visible = true
                    WiFi.runScanWiFi();
                }else{
                    imgOpenWifi.source = "./src/btSlideOff"
                    txtState.text = "未打开"
                    WiFi.setWifiCurrentState(false)
                    wifiBluetoothList.visible = false
                    WiFi.closeWiFi()
                }
            }
        }
    }

    ScrollView {
        id: scanTexteditview
        width: 1000
        height: 460
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 40
        anchors.topMargin: 140
        clip: true
        Rectangle{
            id: currentWifiBg
            width: 950
            height: 84
            color:"#B2CEFF"
            opacity: 0.23
            radius: 12
        }

        Rectangle{
            width: 950
            height: 84
         //   color: "#31447B"
            color:"transparent"
            radius: 5
            Image{
                id: smallWifiImg

                width:25
                height: 25
                source: "./src/iconSmallWiFi"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 29
            }
            Text {
                id: txtConnect
                anchors.verticalCenter: parent.verticalCenter
                color: "white"
                font.pixelSize: 26
                anchors.left: parent.left
                anchors.leftMargin: 66
                text: qsTr("未连接")
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
                id: wifiDelegateRoot
                property variant mymodel: model
                Rectangle{
                    id: listViewBg
                    width: 950
                    height: 84
                    color:"#B2CEFF"
                    opacity:0.23
                    radius: 12
                }

                width: 950
                height: 84
                color:"transparent"
                radius: 5

                Image{
                    id: listSmallWifiImg
                    width:25
                    height: 25
                    source: "./src/iconSmallWiFi"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 29
                }

                Text {
                    id: txtDisConnect
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 66
                    color: "white"
                    font.pixelSize: 26
                    text: qsTr(name)
                }

                Image {
                    id: loadingImg
                    width: 34
                    height: 34
                    anchors.right: parent.right
                    anchors.rightMargin: 28
                    anchors.verticalCenter: parent.verticalCenter

                    source: "./src/loading"
                    transformOrigin: Item.Center // 设置变换中心为图像中心点
                    visible: loadVisible

                    RotationAnimator {
                        target: loadingImg // 动画目标为Image组件
                        duration: 2000 // 动画持续时间1秒
                        from: 0 // 起始角度为0度
                        to: 360 // 结束角度为360度，即一圈完整的旋转
                        loops: Animation.Infinite // 循环播放动画
                        running: true // 启动动画
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        connectTip.showDel = false;
                        connectTip.tipModel = 3
                        connectTip.titleName = "输入密码"
                        connectTip.smallTip = wifiNameList[index]
                        connectTip.visible = true
                        loadingImg.visible = true
                        currentChooseWifi = index;
                        listModel.set(index, {loadVisible: true})
                    }
                }
            }
        }
        ListModel{
            id: listModel
        }
    }

    TipRectangle{
        id:connectTip
        visible: false
    }

}
