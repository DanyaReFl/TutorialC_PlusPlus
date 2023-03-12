import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    minimumWidth: 640
    minimumHeight: 480
    visible: true
    title: "MakeTransition"

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "StartingPosition"

        Rectangle {
            id: leftRectangle
            x: 100
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            Text {
                id: moveText
                anchors.centerIn: parent
                anchors.verticalCenterOffset: -70
                font: font.pixelSize = 30
                text: "Move"
            }
            MouseArea {
                anchors.fill: parent
                onClicked:  {
                    ball.x += 30
                    if(ball.x >= rightRectangle.x) scene.state = "StartingPosition"
                    else scene.state = "IntermediatePosition"
                }
            }
        }
        Rectangle {
            id: rightRectangle
            x: 300
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            Text {
                id: returnText
                anchors.centerIn: parent
                anchors.verticalCenterOffset: -70
                font: font.pixelSize = 30
                text: "Return"
            }
            MouseArea {
                anchors.fill: parent
                onClicked:  scene.state = "StartingPosition"
            }
        }

        Rectangle {
            id: ball
            color: "darkgreen"
            x: leftRectangle.x + 5
            y: leftRectangle.y + 5
            width: leftRectangle.width -10
            height:  leftRectangle.height - 10
            radius: width / 2
        }

        states: [
            State {
                name: "StartingPosition"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + 5
                }
            } ,
            State {
                name: "IntermediatePosition"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }

        ]

        transitions:
            Transition {
                from: "IntermediatePosition"
                to: "StartingPosition"

                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.InOutExpo

                }
            }
    }

}
