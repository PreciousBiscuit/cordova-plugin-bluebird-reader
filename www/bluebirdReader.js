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
}

module.exports = bluebirdReader
