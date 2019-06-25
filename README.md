# Bluebird RFID/Barcode Reader Plugin [Android]
This plugin allows you to communicate with Bluebird rfid/barcode readers (RFR900) over bluetooth 2.0+.

## Requirements
* Cordova 5.0.0 or higher
* Android 4.1 or higher

## Limitations
* iOS is not supported. I'm still waiting on response from Bluebird if they have any SDK for iOS that I could use for
 implementation.
* Only one Bluebird reader can be connected.

## Issues
* Bluebird SDK issue - Disconnecting different bluetooth device disconnects bluebird reader as well.

## Notice
* Reading of RFID is working.

## TODO (Barcode, Documentation)
Will be done soon (I hope).

## Install
`cordova plugin add https://github.com/PreciousBiscuit/cordova-plugin-bluebird-reader.git`

## Methods
* [bluebirdReader.connect](#connect)
* [bluebirdReader.disconnect](#disconnect)
* [bluebirdReader.subscribe](#subscribe)
* [bluebirdReader.unsubscribe](#unsubscribe)

### connect

### disconnect

### subscribe

### unsubscribe
