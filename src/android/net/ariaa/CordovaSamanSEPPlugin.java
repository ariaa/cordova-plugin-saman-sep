/**
 */
package net.ariaa;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;
import org.apache.cordova.PluginResult;
import org.apache.cordova.PluginResult.Status;
import org.json.JSONObject;
import org.json.JSONArray;
import org.json.JSONException;
import ir.sep.Sdk724;

import android.util.Log;

import java.util.Date;

public class CordovaSamanSEPPlugin extends CordovaPlugin {
  private static final String TAG = "CordovaSamanSEPPlugin";

  public void initialize(CordovaInterface cordova, CordovaWebView webView) {
    super.initialize(cordova, webView);

    Log.d(TAG, "Initializing CordovaSamanSEPPlugin");
  }

  public boolean execute(String action, JSONArray args, final CallbackContext callbackContext) throws JSONException {
    if(action.equals("test")) {
      Log.d(TAG, "test function called");
      String merchantId = args.getString(0);
      String cellphone = args.getString(1);
      String concatenatedPaymentParams = args.getString(2);
      String additionalData = args.getString(3);

      Sdk724.instance().activity(this) .request(new Sdk724.Request()
        .msisdn(cellphone) .mPin(merchantId) .additionalData(additionalData) .paymentParams(concatenatedPaymentParams) .nightMode(true))
        .listener(new Sdk724.OnResultListener() {
        @Override
        public void onAuditFailed(String error) {
          Log.d(TAG, "the device security cannot be confirmed. * Use alternative methods for payment.");
        }
        @Override
        public void onPaymentFailed(Sdk724.Response response) {
          Log.d(TAG, "payment failure");
        }
        @Override
        public void onPaymentSucceed(Sdk724.Response response) {
          Log.d(TAG, "successful payment");
        }
      }).start();
    } else if(action.equals("echo")) {
      String phrase = args.getString(0);
      // Echo back the first argument
      Log.d(TAG, phrase);
    } else if(action.equals("getDate")) {
      // An example of returning data back to the web layer
      final PluginResult result = new PluginResult(PluginResult.Status.OK, (new Date()).toString());
      callbackContext.sendPluginResult(result);
    }
    return true;
  }

}
