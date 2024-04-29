import QtQuick 2.15
import QtQuick.Controls 1.4

Rectangle{
    id:itemRoot
    width: parent.width
    z:20

    property variant model: []
    property string showText : ""
    property bool checked: false
    property int listHeight: 0
    radius: 12
    color: "#20335E"
    height: listHeight

    Component.onCompleted: {
        addItem()
    }

    ListView{
        id: listViewRoot
        width: parent.width
        height: listHeight
        clip: true
        model:listModel
        delegate: Rectangle{
            width: listViewRoot.width
            height: 30
            color: "transparent"
            radius: 12
            id: recItem

            Text {
                id: txtCurrent
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 36
                color: "white"
                font.pixelSize: 18
                text: muneName
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onPressed: {
                    showText = itemRoot.model[index]
                    itemRoot.visible = false
                }

                onEntered: {
                    color = "#34456D"
                }
                onExited: {
                    color = "#20335E"
                }
            }
        }

    }
    ListModel{
        id: listModel
    }

    function addItem(){
        for(var i in model){
            var data = model[i];
            listModel.append({
                                 muneName: data
                             })
        }
    }

}
