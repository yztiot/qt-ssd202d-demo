import QtQuick 2.12
//import QtQuick.Controls 1.2
//import QtGraphicalEffects 1.0

GeneralBgPage {
    id: drawRoot
    iconPath: "./src/iconDraw"
    titleName: qsTr("画板")

    Rectangle{
        id: drawRec
        width:parent.width
        height: parent.height - 60
        anchors.top: parent.top
        anchors.topMargin: 60
        property alias mouseX: area.mouseX
        property alias mouseY: area.mouseY

        //画板
        Canvas {
            id: canvas
            anchors.fill: parent
            antialiasing: true
            property real lastX //画笔的终止位置
            property real lastY
            property double lineWidth: 1 //线宽
            property color paintColor: "#000000" //画笔颜色

            Image{
                id: btClean
                width: 50
                height: 72
                anchors.bottom:  parent.bottom
                anchors.left: parent.left
                anchors.bottomMargin: 20
                anchors.leftMargin: 946

                z:50
                source: "./src/btDrawClean"

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        console.log("clean")
                        var ctx = canvas.getContext("2d")
                        ctx.clearRect(0,0,canvas.width,canvas.height)
                        canvas.requestPaint()
                    }
                }
            }

            onPaint: {
                var ctx = canvas.getContext("2d")
                ctx.lineWidth = lineWidth
                ctx.strokeStyle = paintColor
                ctx.beginPath()
                ctx.moveTo(lastX, lastY)
                lastX = area.mouseX
                lastY = area.mouseY
                ctx.lineTo(lastX, lastY)
                ctx.stroke()
            }
            MouseArea {
                id: area
                anchors.fill: parent
                acceptedButtons: Qt.AllButtons
                onPressed: {
                    canvas.lastX = mouseX
                    canvas.lastY = mouseY
                }
                onPositionChanged: {
                    canvas.requestPaint()
                }

            }
        }
    }

}
