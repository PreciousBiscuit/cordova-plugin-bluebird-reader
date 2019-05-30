package land.cookie.cordova.plugin.bluebirdreader;

import android.util.Log;
import java.util.ArrayList;
import java.util.List;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;
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
        mMessageHandler = new BluebirdMessageHandler(this);
        mReader = BTReader.getReader(cordova.getContext(), mMessageHandler);
    }

    @Override
    public boolean execute(String action, final JSONArray args, final CallbackContext callbackContext) throws JSONException {
        if ("connect".equals(action))
            connectAction(args, callbackContext);
        else if ("disconnect".equals(action))
            disconnectAction(callbackContext);
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
        if (mReader != null) {
            if (mReader.BT_GetConnectState() == SDConsts.BTConnectState.CONNECTED)
                mReader.BT_Disconnect();
            if (mIsCommunicationOpened)
                mReader.SD_Close();
        }
        mReader = null;
        mIsCommunicationOpened = false;
        mConnectionCallbackCtx = null;
        mSubscriptionCallbackCtx = null;
        mMessageHandler = null;
    }

    protected void notifyReaderConnected() {
        sendConnectionStatus("connected", false);
    }

    protected void notifyReaderDisconnected() {
        sendConnectionStatus("disconnected", true);
        mSubscriptionCallbackCtx = null;
        mConnectionCallbackCtx = null;
    }

    protected void startReading() {
        if (mSubscriptionCallbackCtx == null)
            return;

        int eResult = mReader.RF_PerformInventory(true, false, false);
        if (eResult == SDConsts.RFResult.SUCCESS) {
            sendReadStatus("read-start");
            return;
        }

        String error = getRfError(eResult, "Unable to start reading of RFID tags.");
        sendReadStatus("read-error", "reason", error);
    }

    protected void stopReading() {
        if (mSubscriptionCallbackCtx == null)
            return;

        int eResult = mReader.RF_StopInventory();
        if (eResult == SDConsts.RFResult.SUCCESS) {
            sendReadStatus("read-stop");
            return;
        }

        String error = getRfError(eResult, "Unable to stop reading of RFID tags.");
        sendReadStatus("read-error", "reason", error);
    }

    protected void notifyRead(String mode, String data) {
        if (mSubscriptionCallbackCtx == null)
            return;

        sendReadStatus("read", mode, data); // TODO: parse data <rfid data>;<rssi>
    }

    private void connectAction(JSONArray params, CallbackContext callbackContext) {
        String address = params.optString(0);
        if (address == null || address.trim().isEmpty()) {
            callbackContext.error("Device MAC address was not provided.");
            return;
        }

        boolean mIsCommunicationOpened = mReader.SD_Open(); // TODO: BUG unable to connect again
        if (!mIsCommunicationOpened) {
            callbackContext.error("Unable to open a communication with a reader.");
            return;
        }

        int eResult = mReader.BT_Connect(address);
        if (eResult == SDConsts.BTResult.SUCCESS) {
            mConnectionCallbackCtx = callbackContext;;
            return;
        }

        String error = getBtError(eResult, "Unable to connect to a reader.");
        callbackContext.error(error);
    }

    private void disconnectAction(CallbackContext callbackContext) {
        int eResult = mReader.BT_Disconnect();
        if (eResult == SDConsts.BTResult.SUCCESS) {
            callbackContext.success("success");
            mIsCommunicationOpened = !mReader.SD_Close();
            return;
        }

        String error = getBtError(eResult, "Unable to disconnect from a reader.");
        callbackContext.error(error);
    }

    private void subscribeAction(CallbackContext callbackContext) {
        if (mConnectionCallbackCtx == null) {
            callbackContext.error("No connected reader.");
            return;
        }

        mSubscriptionCallbackCtx = callbackContext;
    }

    private void unsubscribeAction(CallbackContext callbackContext) {
        if (mSubscriptionCallbackCtx == null)
            callbackContext.success("No active subscription.");
        else
            callbackContext.success("success");
        mSubscriptionCallbackCtx = null;
    }

    private void sendConnectionStatus(String msg, boolean isError) {
        if (mConnectionCallbackCtx == null)
            return;

        PluginResult message;
        if (isError) {
            message = new PluginResult(PluginResult.Status.ERROR, msg);
        }
        else {
            message = new PluginResult(PluginResult.Status.OK, msg);
            message.setKeepCallback(true);
        }
        mConnectionCallbackCtx.sendPluginResult(message);
    }

    private void sendReadStatus(String status) {
        sendReadStatus(status, null, null);
    }

    private void sendReadStatus(String status, String dataKey, String dataValue) {
        try {
            JSONObject data = new JSONObject();
            data.put("status", status);

            if (dataKey != null && !dataKey.isEmpty()) {
                data.put(dataKey, dataValue);
            }

            PluginResult message = new PluginResult(PluginResult.Status.OK, data);
            message.setKeepCallback(true);
            mSubscriptionCallbackCtx.sendPluginResult(message);
        }
        catch (JSONException e) {
            Log.e(TAG, "ERROR - Unable to send read status.");
        }
    }

    private String getBtError(int eError, String defaultErrorMsg) {
        switch (eError) {
        case SDConsts.BTResult.BT_NOT_ENABLE_STATE:
            return "Bluetooth is not turned on.";
        case SDConsts.BTResult.ALREADY_CONNECTED:
            return "Already connected to a reader.";
        case SDConsts.BTResult.ALREADY_DISCONNECTED:
            return "Reader was not connected.";
        default:
            return defaultErrorMsg;
        }
    }

    private String getRfError(int eError, String defaultErrorMsg) {
        switch (eError) {
        case SDConsts.RFResult.BLUETOOTH_NOT_ENABLED:
            return "Bluetooth is not turned on.";
        case SDConsts.RFResult.MODE_ERROR:
            return "Reader is in incorrect mode.";
        case SDConsts.RFResult.LOW_BATTERY:
            return "Reader has low battery.";
        case SDConsts.RFResult.NOT_INVENTORY_STATE:
            return "Reader is not currently reading.";
        default:
            return defaultErrorMsg;
        }
    }
}
