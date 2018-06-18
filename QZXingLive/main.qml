import QtQuick 2.5
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import QtMultimedia 5.5

import QZXing 2.3

import cn.com.wanywhn 1.0

ApplicationWindow
{
    id: window
    visible: true
    width: 640
    height: 480
    title: "Qt QZXing Filter Test"

    property int detectedTags: 0
    property string lastTag: ""
    StackView{
        id:stackView
        initialItem: scanPage
        anchors.fill:parent

    }
    Component{
        id:consumePage
        Page{
        property string credit_card: "0"

        property int num: 0


        Column{

        ComboBox{
            id:cb_cate
            model: ["FOOD","CLOTHING","EDUCATION","HOUSING","MACHINE","TRANSOPRT","OTHER"]

        }
        TextField{
            id:input_money
            placeholderText: "Please Input Money"

        }
        Button{
            text: "Pay"
            onClicked: {
               pay();
            }

        }
        Button{
            text:"Back"
            onClicked: {
                stackView.pop()
            stackView.currentItem.camera_id.start();
        }
        }

}
        function pay(){
            console.log(cb_cate.currentText)
            console.log(input_money.text)
            ctrl.pay(credit_card,input_money.text,cb_cate.currentText);
        }
        CreditCtrl{
            id:ctrl

        }

        }



    }
    Component{
        id:scanPage
        Page{
        property Camera camera_id: camera
    Rectangle
    {
        id: bgRect
        color: "white"
        anchors.fill: videoOutput
    }

    Text
    {
        id: text1
        wrapMode: Text.Wrap
        font.pixelSize: 20
        anchors.top: parent.top
        anchors.left: parent.left
        z: 50
        text: "Tags detected: " + detectedTags
    }
    Text
    {
        id: fps
        font.pixelSize: 20
        anchors.top: parent.top
        anchors.right: parent.right
        z: 50
        text: (1000 / zxingFilter.timePerFrameDecode).toFixed(0) + "fps"
    }

    Camera
    {
        id:camera
        focus {
            focusMode: CameraFocus.FocusContinuous
            focusPointMode: CameraFocus.FocusPointAuto
        }
    }

    VideoOutput
    {
        id: videoOutput
        source: camera
        anchors.top: text1.bottom
        anchors.bottom: text2.top
        anchors.left: parent.left
        anchors.right: parent.right
        autoOrientation: true
        fillMode: VideoOutput.Stretch
        filters: [ zxingFilter ]
        MouseArea {
            anchors.fill: parent
            onClicked: {
                camera.focus.customFocusPoint = Qt.point(mouse.x / width,  mouse.y / height);
                camera.focus.focusMode = CameraFocus.FocusMacro;
                camera.focus.focusPointMode = CameraFocus.FocusPointCustom;
            }
        }
        Rectangle {
            id: captureZone
            color: "red"
            opacity: 0.2
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }
    }

    QZXingFilter
    {
        id: zxingFilter
        captureRect: {
            // setup bindings
            videoOutput.contentRect;
            videoOutput.sourceRect;
            return videoOutput.mapRectToSource(videoOutput.mapNormalizedRectToItem(Qt.rect(
                0.25, 0.25, 0.5, 0.5
            )));
        }

        decoder {
            enabledDecoders: QZXing.DecoderFormat_EAN_13 | QZXing.DecoderFormat_CODE_39 | QZXing.DecoderFormat_QR_CODE

            onTagFound: {
                console.log(tag + " | " + decoder.foundedFormat() + " | " + decoder.charSet());

                window.detectedTags++;
                window.lastTag = tag;
                stackView.push(consumePage,{"credit_card":tag})
                camera.stop()
            }

            tryHarder: false
        }

        onDecodingStarted:
        {
//            console.log("started");
        }

        property int framesDecoded: 0
        property real timePerFrameDecode: 0

        onDecodingFinished:
        {
           timePerFrameDecode = (decodeTime + framesDecoded * timePerFrameDecode) / (framesDecoded + 1);
           framesDecoded++;
           console.log("frame finished: " + succeeded, decodeTime, timePerFrameDecode, framesDecoded);
        }
    }

    Text
    {
        id: text2
        wrapMode: Text.Wrap
        font.pixelSize: 20
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        z: 50
        text: "Last tag: " + lastTag
    }
    Switch {
        text: "Autofocus"
        checked: camera.focus.focusMode === CameraFocus.FocusContinuous
        anchors {
            right: parent.right
            bottom: parent.bottom
        }
        onCheckedChanged: {
            if (checked) {
                camera.focus.focusMode = CameraFocus.FocusContinuous
                camera.focus.focusPointMode = CameraFocus.FocusPointAuto
            } else {
                camera.focus.focusPointMode = CameraFocus.FocusPointCustom
                camera.focus.customFocusPoint = Qt.point(0.5,  0.5)
            }
        }
        font.family: Qt.platform.os === 'android' ? 'Droid Sans Mono' : 'Monospace'
        font.pixelSize: Screen.pixelDensity * 5
    }
}
    }
}

