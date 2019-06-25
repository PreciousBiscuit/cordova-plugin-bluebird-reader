package land.cookie.cordova.plugin.bluebirdreader;

import android.util.Log;
import android.os.Handler;
import android.os.Message;
import android.os.Bundle;
import co.kr.bluebird.sled.SDConsts;

public class BluebirdMessageHandler extends Handler {
    private static final String TAG = "CLPB_BluebirdReader";

    private BluebirdReader mReader;

    BluebirdMessageHandler(BluebirdReader reader) {
        mReader = reader;
    }

    @Override
    public void handleMessage(Message msg) {
        Log.d(TAG, "~~~~~ Message ~~~~~");
        Log.d(TAG, Integer.toString(msg.what));
        Log.d(TAG, Integer.toString(msg.arg1));
        Log.d(TAG, Integer.toString(msg.arg2));
        Bundle bundle = msg.getData();
        if (bundle != null) {
            for (String key : bundle.keySet()) {
              Log.d (TAG, key);
            }
        }
        Log.d(TAG, "~~~~~ /Message ~~~~~");
        switch (msg.what) {
        case SDConsts.Msg.BTMsg:
            switch (msg.arg1) {
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_STATE_CHANGED:
                if (msg.arg2 == 0)
                    mReader.notifyReaderMaybeDisconnected();
            break;
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_ESTABLISHED:
                mReader.notifyReaderConnected();
            break;
            case SDConsts.BTCmdMsg.SLED_BT_DISCONNECTED:
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_LOST:
                mReader.notifyReaderDisconnected();
            break;
            }
        break;
        case SDConsts.Msg.SDMsg:
            switch (msg.arg1) {
            case SDConsts.SDCmdMsg.TRIGGER_PRESSED:
                mReader.startRfidReading();
            break;
            case SDConsts.SDCmdMsg.TRIGGER_RELEASED:
                mReader.stopRfidReading();
            break;
            }
        break;
        case SDConsts.Msg.RFMsg:
            switch (msg.arg1) {
            case SDConsts.RFCmdMsg.INVENTORY:
                if (msg.arg2 == SDConsts.RFResult.SUCCESS && msg.obj != null) {
                    mReader.notifyRfidRead((String) msg.obj);
                }
            break;
            }
        break;
        case SDConsts.Msg.SBMsg:
            switch (msg.arg1) {
            case SDConsts.SBCmdMsg.BARCODE_TRIGGER_PRESSED_SLED:
                // TODO
            break;
            case SDConsts.SBCmdMsg.BARCODE_TRIGGER_RELEASED_SLED:
                // TODO
            break;
            case SDConsts.SBCmdMsg.BARCODE_READ:
                // TODO: there are no data sent with this message
                // mReader.notifyBarcodeRead();
            break;
            }
        break;
        }
    }
}
