package land.cookie.cordova.plugin.bluebirdreader;

import android.util.Log;
import android.util.Pair;
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
    private boolean mIsConnecting = false;
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
        if (mReader != null && mReader.BT_GetConnectState() == SDConsts.BTConnectState.CONNECTED) {
            mReader.BT_Disconnect();
        }
        mReader = null;
        mConnectionCallbackCtx = null;
        mSubscriptionCallbackCtx = null;
        mMessageHandler = null;
    }

    protected void notifyReaderConnected() {
        if (mConnectionCallbackCtx == null)
            return;

        PluginResult message = new PluginResult(PluginResult.Status.OK, "connected");
        message.setKeepCallback(true);
        mConnectionCallbackCtx.sendPluginResult(message);

        mIsConnecting = false;
    }

    protected void notifyReaderDisconnected() {
        if (mConnectionCallbackCtx == null)
            return;

        PluginResult message = new PluginResult(PluginResult.Status.ERROR, "disconnected");
        mConnectionCallbackCtx.sendPluginResult(message);

        mSubscriptionCallbackCtx = null;
        mConnectionCallbackCtx = null;
        mIsConnecting = false;
    }

    protected void notifyReaderMaybeDisconnected() {
        if (mIsConnecting) {
            notifyReaderDisconnected();
        }
    }

    protected void startRfidReading() {
        if (mSubscriptionCallbackCtx == null)
            return;

        int eResult = mReader.RF_PerformInventory(true, false, false);
        if (eResult == SDConsts.RFResult.SUCCESS) {
            sendReadAction("rfidReadStart");
            return;
        }

        String error = getRfError(eResult, "Unable to start reading of RFID tags.");
        Pair<String, String>[] data = new Pair[] { new Pair("error", error) };
        sendReadAction("rfidReadStart", data);
    }

    protected void stopRfidReading() {
        if (mSubscriptionCallbackCtx == null)
            return;

        int eResult = mReader.RF_StopInventory();
        if (eResult == SDConsts.RFResult.SUCCESS) {
            sendReadAction("rfidReadStop");
            return;
        }

        String error = getRfError(eResult, "Unable to stop reading of RFID tags.");
        Pair<String, String>[] data = new Pair[] { new Pair("error", error) };
        sendReadAction("rfidReadStop", data);
    }

    protected void notifyRfidRead(String rfidData) {
        if (mSubscriptionCallbackCtx == null)
            return;

        Pair<String, String>[] data = parseRfidData(rfidData);
        if (data != null) {
            sendReadAction("rfidRead", data);
        }
    }

    // protected void notifyBarcodeRead() {
    //     // TODO
        // JSONObject barcode = new JSONObject();
        // barcode.put("type", barcodeType);
        // barcode.put("data", barcodeData);
        // data.put("barcode", barcode);
    // }

    private void connectAction(JSONArray params, CallbackContext callbackContext) {
        String address = params.optString(0);
        if (address == null || address.trim().isEmpty()) {
            callbackContext.error("Device MAC address was not provided.");
            return;
        }

        // NOTE: Must NOT call SD_Close() or the library gets stuck.
        //       Or I wasn't able to figure out the magic combination how to close it properly yet.
        boolean isCommunicationOpened = mReader.SD_Open();
        if (!isCommunicationOpened) {
            callbackContext.error("Unable to open a communication with a reader.");
            return;
        }

        int eResult = mReader.BT_Connect(address);
        if (eResult == SDConsts.BTResult.SUCCESS) {
            mIsConnecting = true;
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

    private void sendReadAction(String action) {
        sendReadAction(action, null);
    }

    private void sendReadAction(String action, Pair<String, String>[] data) {
        try {
            JSONObject msgData = new JSONObject();
            msgData.put("action", action);

            if (data != null) {
                for (Pair<String, String> pair : data) {
                    msgData.put(pair.first, pair.second);
                }
            }

            PluginResult message = new PluginResult(PluginResult.Status.OK, msgData);
            message.setKeepCallback(true);
            mSubscriptionCallbackCtx.sendPluginResult(message);
        }
        catch (JSONException e) {
            Log.e(TAG, "ERROR - Unable to send a read action.");
        }
    }

    private Pair<String, String>[] parseRfidData(String rfidData) {
        if (rfidData == null || rfidData.isEmpty()) {
            Log.e(TAG, "ERROR - Received incorrect RFID Data.");
            return null;
        }

        String[] parts = rfidData.split(";");
        Pair<String, String>[] data = new Pair[parts.length];
        data[0] = new Pair("data", parts[0]);

        for (int i = 1; i < parts.length; i++) {
            String[] info = parts[i].split(":");
            if (info.length == 2)
                data[i] = new Pair(info[0], info[1]);
        }
        return data;
    }

    private String getBtError(int eError, String defaultErrorMsg) {
        switch (eError) {
        // case SDConsts.BTResult.BT_NOT_ENABLE_STATE:
        //     return "Bluetooth is not turned on.";
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

