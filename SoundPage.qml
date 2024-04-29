import QtQuick 2.12
import QtMultimedia 5.12

GeneralBgPage{
    id: settingRoot
    iconPath: "./src/iconSound"
    titleName: qsTr("音频")

    property string currentDir: ""
    property var soundNameList
    property var lastSoundIndex
    property string currentSoundFile : ""
    property int nCurrentIndex: 0

    Component.onCompleted: {
        Sound.findSoundFile();
        updataSoundList();

    }

    function updataSoundList(){
        soundNameList  = Sound.getSoundFile()
        currentDir = Sound.getSoundPath();
        for(var i in soundNameList){
            listModel.append({
                                 name: soundNameList[i],
                                 playSoundIconVisble: false
                             })
        }
    }

//    function changeSong(value){
//        soundPlay.stop();
//      //  soundPlay.source(value);
//        soundPlay.play();
//        listModel.set(lastSoundIndex, {playSoundIconVisble: false})
//        listModel.set(nCurrentIndex, {playSoundIconVisble: true})
//    }

    function playMusic(name){
        Sound.musicPlay(name)
    }

    Rectangle{
        id: soundPage
        width: 945
        height: 600
        color: "transparent"
        anchors.horizontalCenter: parent.horizontalCenter
        VolLmPage{
            id: volRoot
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 89
            strName: "音量"
            logoPath: "./src/volMax"
            minPath: "./src/volMin"
            maxPath: "./src/volMax"
            model :2
        }

        Text {
            id: soundTip
            color: "white"
            font.pixelSize: 22
            anchors.left: volRoot.left
            anchors.top: volRoot.bottom
            anchors.topMargin: 10
            text: qsTr("歌曲")
        }
//        /*上一首歌*/
//        Image {
//            id: imgPrevious
//            width: 58
//            height: 58
//            visible: true
//            anchors.left: soundTip.left
//            anchors.leftMargin: 500
//            anchors.top: soundTip.top
//            source: "./src/previousSound"
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    if(nCurrentIndex > 0){
//                        var str = currentSoundFile = currentDir+"/"+ soundNameList[nCurrentIndex - 1]
//                        lastSoundIndex= nCurrentIndex
//                        nCurrentIndex = nCurrentIndex -1

//                        changeSong(str)
//                    }
//                }
//            }
//        }

//        /*播放*/
//        Image {
//            id: imgPlay
//            width: imgPrevious.width
//            height: imgPrevious.height
//            visible: true
//            anchors.left: imgPrevious.right
//            anchors.top: imgPrevious.top
//            source: "./src/playSound"
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    if(currentSoundFile !== ""){
//                        soundPlay.play()
//                        imgPause.visible = true;
//                        imgPlay.visible = false
//                        listModel.set(nCurrentIndex, {playSoundIconVisble: true})
//                    }
//                }
//            }
//        }

//        /*暂停*/
//        Image {
//            id: imgPause
//            width: imgPrevious.width
//            height: imgPrevious.height
//            visible: false
//            anchors.left: imgPrevious.right
//            anchors.top: imgPrevious.top
//            source: "./src/pauseSound"
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    soundPlay.stop()
//                    imgPause.visible = false;
//                    imgPlay.visible = true
//                    listModel.set(nCurrentIndex, {playSoundIconVisble: true})
//                }
//            }
//        }

//        /*下一首歌*/
//        Image {
//            id: imgNext
//            width: imgPrevious.width
//            height: imgPrevious.height
//            visible: true
//            anchors.left: imgPlay.right
//            anchors.top: imgPrevious.top
//            source: "./src/nextSound"
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    if(nCurrentIndex < soundNameList.length - 1){
//                        var str = currentSoundFile = currentDir+"/"+ soundNameList[nCurrentIndex + 1]
//                        lastSoundIndex= nCurrentIndex
//                        nCurrentIndex = nCurrentIndex + 1
//                        changeSong(str)
//                    }
//                }
//            }
//        }


        ListView{
            id: soundView
            width: parent.width
            height: 300
            spacing: 5
            anchors.top: soundTip.bottom
            anchors.topMargin: 70
            anchors.horizontalCenter: parent.horizontalCenter
            model: listModel

            delegate: Rectangle{
                width: 950
                height: 84
                color: "transparent"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {

                    }
                }

                Rectangle{
                    width: parent.width
                    height: parent.height
                    color: "#B2CEFF"
                    opacity: 0.23
                    radius: 12
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            listModel.set(lastSoundIndex, {playSoundIconVisble: false})
                            lastSoundIndex = index
                            listModel.set(index, {playSoundIconVisble: true})
                            currentSoundFile = currentDir+"/"+ soundNameList[index]
                            nCurrentIndex =index
                            console.log("source::" + currentSoundFile)
                          //  soundPlay.source = currentSoundFile
                          //  soundPlay.play();
                        /   playMusic(currentSoundFile);
                           // console.log("")
                        }
                    }
                }

                Image{
                    id: imgIcon
                    width: 16
                    height: 16
                    visible: playSoundIconVisble
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 29
                    source: "./src/soundPlaying"

                }
                Text {
                    id: soundName
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 66
                    color: "white"
                    font.pixelSize: 26
                    text: qsTr(name)
                }


                Image{
                    id: imgIconlast
                    width: 80
                    height: 80
                    visible: playSoundIconVisble
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 20
                    source: "./src/pauseSound"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            Sound.musicStop();
                            listModel.set(index, {playSoundIconVisble: false})
                        }
                    }
                }
            }
        }


        ListModel{
            id: listModel
        }

        MediaPlayer{
            id:soundPlay
            source: ""


        }

    }
}
