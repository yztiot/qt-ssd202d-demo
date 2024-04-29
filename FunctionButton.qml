import QtQuick 2.15

Rectangle{
    id: buttonRoot
    width: 189
    height: 222
    color: "transparent"
    radius: 10

    property alias imgSource: buttonImg.source
    Image{
        id: buttonImg
        anchors.fill: parent
    }

}
