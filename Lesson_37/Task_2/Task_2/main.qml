    import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12

Window {
    width: 500
    height: 110
    visible: true
    title: qsTr("Video Player")
    Button {
        text:"▶️"
        font.pointSize: 36
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 10
    }
    Button {
        text:"⏸️"
        font.pointSize: 36
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -100
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 10
    }
    Button {
        text:"⏹"
        font.pointSize: 36
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 10
    }
    Button {
        text:"⏪️"
        font.pointSize: 36
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 100
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 10
    }
    Button {
        text:"⏩️"
        font.pointSize: 36
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 200
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 10
    }

    ProgressBar {
        indeterminate: true
        scale: 2.5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -50
    }
}
