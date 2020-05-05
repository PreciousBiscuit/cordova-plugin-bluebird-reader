# Bluebird RFID/Barcode Reader Plugin
This plugin allows you to communicate with Bluebird rfid/barcode readers (RFR900) over bluetooth 2.0+.

Documentation will be updated later I hope.

## Requirements
* Cordova 6.4.0+
* Android 4.1+
* iOS 8.0+ [Not implemented yet]

## Limitations
* iOS is not implemented yet.
* Only one Bluebird reader can be connected. - Bluebird library issue
* This plugin does not handle searching for bluetooth devices.

## Issues
* Disconnecting different bluetooth device disconnects Bluebird reader as well.
  There is a bug inside library provided by Bluebird.

## Install
`cordova plugin add https://github.com/PreciousBiscuit/cordova-plugin-bluebird-reader.git`

## Methods
* [bluebirdReader.connect](#connect)
* [bluebirdReader.disconnect](#disconnect)
* [bluebirdReader.subscribe](#subscribe)
* [bluebirdReader.unsubscribe](#unsubscribe)
* [bluebirdReader.execute](#execute)

### connect
Connects to a bluebird device. If device is disconnected, errorCallback would be called with "disconnected" message.

`bluebirdReader.connect(successCallback, errorCallback, address)`

* address - MAC address of bluebird device.

##### Success
"connected"

##### Errors
* Different error messages explaining what went wrong.
* "disconnected" - when device was disconnected.

### disconnect
Disconnects a bluebird device. It will call errorCallback from connect() with "disconnected" message.

`bluebirdReader.disconnect(successCallback, errorCallback)`

##### Success
"success"

##### Errors
Different error messages explaining what went wrong.

### subscribe
Subscribes for device events. Bluebird device can read the same RFID tag several times in a second and for all those 
events is successCallback called. Duplicities are not handled.

`bluebirdReader.subscribe(successCallback, errorCallback)`

##### Success
```
{
  action: <string>,
  [data: <string>],
  [rssi: <string>],
  [type: <string>],
  [error: <string>] 
}
```

* action - ["rfidReadStart", "rfidReadStop", "rfidRead", "barcodeReadStart", "barcodeReadStop", "barcodeRead"]
* data:
    * RFID value - if "rfidRead" action
    * barcode data - if "barcodeRead" action
* rssi - rssi value for RFID tag in "rfidRead" action
* type - barcode type in "barcodeRead" action
* error - any action can have an error if something goes wrong

##### Errors
"No connected reader."

### unsubscribe
`bluebirdReader.unsubscribe(successCallback, errorCallback)`

##### Success
* "success"
* "No active subscription."

##### Errors
None

### execute
Executes a command on Bluebird device.

`bluebirdReader.execute(successCallback, errorCallback, command, params)`

