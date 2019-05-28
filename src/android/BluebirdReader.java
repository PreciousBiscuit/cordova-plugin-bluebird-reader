package land.cookie.cordova.plugin.bluebirdreader; // TODO

import java.util.ArrayList;
import java.util.List;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import co.kr.bluebird.sled.BTReader;
import co.kr.bluebird.sled.SDConsts;

public class BluebirdReader extends CordovaPlugin {
    private static final String TAG = "CLPB_BluebirdReader";

    private BTReader mReader = null;
    private BluebirdMessageHandler mMessageHandler = null;
    private boolean mIsCommunicationOpened = false;
    private CallbackContext mConnectionCallbackCtx = null;
    private CallbackContext mSubscriptionCallbackCtx = null;

    @Override
    public void initialize(CordovaInterface cordova, CordovaWebView webView) {
        super.initialize(cordova, webView);
        mMessageHandler = new mMessageHandler(this);
        mReader = BTReader.getReader(cordova.getContext(), mBluebirdMessageHandler);
    }

    @Override
    public boolean execute (
        String action, final JSONArray args, final CallbackContext callbackContext
    ) throws JSONException {
        if ("openCommunication".equals(action))
            openAction(callbackContext);
        else if ("closeCommunication".equals(action))
            closeAction(callbackContext);
        else if ("connect".equals(action))
            connectAction(args, callbackContext);
        else if ("disconnect".equals(action))
            disconnectAction(args, callbackContext);
        else if ("subscribe".equals(action))
            subscribeAction(callbackContext);
        else if ("unsubscribe".equals(action))
            unsubscribeAction(callbackContext);
        else
            return false;
        return true;
    }

    @Override
    public void onDestroy() {
        if (mIsCommunicationOpened) {
            mReader.SD_Close();
        }
        mReader = null;
        mConnectionCallbackCtx = null;
        mSubscriptionCallbackCtx = null;
        mMessageHandler = null;
    }

    private boolean openAction(CallbackContext callbackContext) {
        mIsCommunicationOpened = mReader.SD_Open();
        if (mIsCommunicationOpened == true)
            callbackContext.success("success");
        else
            callbackContext.error("Unable to open a communication with a reader.");
        return mIsCommunicationOpened;
    }

    private boolean closeAction(CallbackContext callbackContext) {
        mIsCommunicationOpened = mReader.SD_Close();
        if (mIsCommunicationOpened == true)
            callbackContext.success("success");
        else
            callbackContext.error("Unable to close a communication with a reader.");
        return mIsCommunicationOpened;
    }

    private void connectAction(JSONArray params, CallbackContext callbackContext) {
        String address = params.optString(0);
        if (address == null || str.trim().isEmpty()) {
            callbackContext.error("Device MAC address was not provided.");
            return;
        }

        if (!mIsCommunicationOpened && !openAction(callbackContext))
            return;

        int eConnectResult = mReader.BT_Connect();
        if (eConnectResult == SDConsts.BTResult.SUCCESS) {
            mConnectionCallbackCtx = callbackContext;

            PluginResult message = new PluginResult(PluginResult.Status.OK, "connected");
            message.setKeepCallback(true);
            mConnectionCallbackCtx.sendPluginResult(message);
        }
        else if (eConnectResult == SDConsts.BTResult.ALREADY_CONNECTED) {
            callbackContext.error("Already connected to a reader.");
        }
        else if (eConnectResult == SDConsts.BTResult.BT_NOT_ENABLE_STATE) {
            callbackContext.error("Bluetooth is not turned on.");
        }
        else {
            callbackContext.error("Unable to connect to a reader.");
        }
    }

    private void disconnectAction(CallbackContext callbackContext) {
        int eDisconnectResult = mReader.BT_Disconnect();
        if (eDisconnectResult == SDConsts.BTResult.SUCCESS) {
            callbackContext.success("success");
        }
        else if (eDisconnectResult == SDConsts.BTResult.ALREADY_DISCONNECTED) {
            callbackContext.error("Reader was not connected.");
        }
        else if (eConnectResult == SDConsts.BTResult.BT_NOT_ENABLE_STATE) {
            callbackContext.error("Bluetooth is not turned on.");
        }
        else {
            callbackContext.error("Unable to disconnect from a reader.");
        }
    }

    private void subscribeAction(CallbackContext callbackContext) {
        if (mConnectionCallbackCtx == null) {
            callbackContext.error("No connected reader.");
            return;
        }

        mSubscriptionCallbackCtx = callbackContext;
    }

    private void unsubscribeAction(CallbackContext callbackContext) {
        if (mSubscriptionCallbackCtx == null) {
            callbackContext.error("No active subscription.");
            return;
        }

        mSubscriptionCallbackCtx = null;
        callbackContext.success("success");
    }
}
