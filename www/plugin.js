
var exec = require('cordova/exec');

var PLUGIN_NAME = 'CordovaSamanSEPPlugin';

var CordovaSamanSEPPlugin = {
  test: function(merchantId,cellphone,concatenatedPaymentParams,additionalData, cb) {
    exec(cb, null, PLUGIN_NAME, 'test', [merchantId,cellphone,concatenatedPaymentParams,additionalData]);
  },
  echo: function(phrase, cb) {
    exec(cb, null, PLUGIN_NAME, 'echo', [phrase]);
  },
  getDate: function(cb) {
    exec(cb, null, PLUGIN_NAME, 'getDate', []);
  }
};

module.exports = CordovaSamanSEPPlugin;
