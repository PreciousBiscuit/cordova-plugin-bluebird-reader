/* global cordova, module */
const serviceName = 'BluebirdReader'

const bluebirdReader = {
  // search(successCallback, errorCallback) {
  //   cordova.exec(successCallback, errorCallback, serviceName, arguments.callee.name, []);
  // },
  connect(successCallback, errorCallback, params) {
    cordova.exec(successCallback, errorCallback, serviceName, arguments.callee.name, [params]);
  },
  disconnect(successCallback, errorCallback) {
    cordova.exec(successCallback, errorCallback, serviceName, arguments.callee.name, []);
  },
  subscribe(successCallback, errorCallback) {
    cordova.exec(successCallback, errorCallback, serviceName, arguments.callee.name, []);
  },
  unsubscribe(successCallback, errorCallback) {
    cordova.exec(successCallback, errorCallback, serviceName, arguments.callee.name, []);
  },
  commands: {
    getSerialNumber: 'getSerialNumber',
    getBattery: 'getBattery',
    getAvailableRegions: 'getAvailableRegions',
    getRegion: 'getRegion',
    setRegion: 'setRegion',
    getRFMode: 'getRFMode',
    setRFMode: 'setRFMode',
    getAntennaPower: 'getAntennaPower',
    setAntennaPower: 'setAntennaPower',
  },
  execute(successCallback, errorCallback, command, params) {
    cordova.exec(successCallback, errorCallback, serviceName, arguments.callee.name, [command, params])
  }
}

module.exports = bluebirdReader
