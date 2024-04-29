import QtQuick 2.12

Rectangle {
    id: keyboardRoot
    width: 630
    height: 235
    color: "transparent"

    //输入框
    Rectangle{
        id: recInput
        width: 396
        height: 52
        color: "#11234A"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 30
        border.color: "white"
        radius: 12
        TextInput{
            id: inputTxt
            width: 280
            height: parent.height
            verticalAlignment: Text.AlignVCenter
            color: "white"
            clip: true
            font.pixelSize: 20
            maximumLength: 25
            cursorVisible: true
        }

        //发送按钮
        Rectangle{
            id: btSend
            width: 95
            height: 38
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 10
            color: "transparent"
            Image {
                id: imgSend
                anchors.fill: parent
                source: "./src/btSend"
            }
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    imgSend.source = "./src/btSendPress"
                    SerialFunction.writeSerialSig(inputTxt.text)
                }
                onReleased: {
                    imgSend.source = "./src/btSend"
                }
            }
        }
    }

    //以下image为键盘按钮

    Image {
        id: btOne
        width: 70
        height: 47
        anchors.top: recInput.bottom
        anchors.topMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 80
        source: "./src/btOne"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("1")
                btOne.source = "./src/btOnePress"
            }
            onReleased: {
                btOne.source = "./src/btOne"
            }
        }
    }

    Image {
        id: btTwo
        width: 70
        height: 47
        anchors.top: btOne.top
        anchors.left: btOne.right
        anchors.leftMargin: 10
        source: "./src/btTwo"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("2")
                btTwo.source = "./src/btTwoPress"
            }
            onReleased: {
                btTwo.source = "./src/btTwo"
            }
        }
    }

    Image {
        id: btThree
        width: 70
        height: 47
        anchors.top: btOne.top
        anchors.left: btTwo.right
        anchors.leftMargin: 10
        source: "./src/btThree"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("3")
                btThree.source = "./src/btThreePress"
            }
            onReleased: {
                btThree.source = "./src/btThree"
            }
        }
    }

    Image {
        id: btFour
        width: 70
        height: 47
        anchors.top: btOne.top
        anchors.left: btThree.right
        anchors.leftMargin: 10
        source: "./src/btFour"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("4")
                btFour.source = "./src/btFourPress"
            }
            onReleased: {
                btFour.source = "./src/btFour"
            }
        }
    }

    Image {
        id: btFive
        width: 70
        height: 47
        anchors.top: btOne.top
        anchors.left: btFour.right
        anchors.leftMargin: 10
        source: "./src/btFive"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("5")
                btFive.source = "./src/btFivePress"
            }
            onReleased: {
                btFive.source = "./src/btFive"
            }
        }
    }

    Image {
        id: btSix
        width: 70
        height: 47
        anchors.top: btOne.top
        anchors.left: btFive.right
        anchors.leftMargin: 10
        source: "./src/btSix"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("1")
                btSix.source = "./src/btSixPress"
            }
            onReleased: {
                btSix.source = "./src/btSix"
            }
        }
    }

    Image {
        id: btSeven
        width: 70
        height: 47
        anchors.top: btOne.bottom
        anchors.topMargin: 10
        anchors.left: btOne.left
        source: "./src/btSeven"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("7")
                btSeven.source = "./src/btSevenPress"
            }
            onReleased: {
                btSeven.source = "./src/btSeven"
            }
        }
    }

    Image {
        id: btEight
        width: 70
        height: 47
        anchors.top: btSeven.top
        anchors.left: btTwo.left
        source: "./src/btEight"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("8")
                btEight.source = "./src/btEightPress"
            }
            onReleased: {
                btEight.source = "./src/btEight"
            }
        }
    }

    Image {
        id: btNine
        width: 70
        height: 47
        anchors.top: btEight.top
        anchors.left: btThree.left
        source: "./src/btNine"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("9")
                btNine.source = "./src/btNinePress"
            }
            onReleased: {
                btNine.source = "./src/btNine"
            }
        }
    }

    Image {
        id: btZero
        width: 70
        height: 47
        anchors.top: btNine.top
        anchors.left: btFour.left
        source: "./src/btZero"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                addText("0")
                btZero.source = "./src/btZeroPress"
            }
            onReleased: {
                btZero.source = "./src/btZero"
            }
        }
    }

    Image {
        id: btDel
        width: 149
        height: 47
        anchors.top: btNine.top
        anchors.left: btFive.left
        source: "./src/btDel"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                delText()
                btDel.source = "./src/btDelPress"
            }
            onReleased: {
                btDel.source = "./src/btDel"
            }
        }
    }


    function addText(value){
        var i = inputTxt.text.length
        var add = inputTxt.text + value
        inputTxt.text = add;

    }

    function delText(){
        var i = inputTxt.text.length
        var j = inputTxt.text.substring(0, i - 1)
        inputTxt.text = j;

    }


}
