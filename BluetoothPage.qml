import QtQuick 2.15

GeneralBgPage{
    id: bluetoothRoot
    iconPath: "./src/iconBluetooth"
    titleName: qsTr("蓝牙")
    WifiBluetoothRec{
        id: recBluetooth

    }
}
