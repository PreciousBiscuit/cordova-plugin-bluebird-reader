package land.cookie.cordova.plugin.bluebirdreader;

import co.kr.bluebird.sled.SDConsts;
import android.util.Log;

public class BluebirdMessageHandler extends Handler {
    private static final String TAG = "CLPB_BluebirdReader";

    private BluebirdReader mReader;

    BluebirdMessageHandler(BluebirdReader reader) {
        mReader = reader;
    }

    @Override
    public void handleMessage(Message msg) {
        switch (msg.what) {
        case SDConsts.Msg.BTMsg:
            switch (msg.arg1) {
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_ESTABLISHED:
                Log.d(TAG, "Connection established: " + msg.arg2);
                mReader.notifyBluetoothAction("connected")
            break;
            case SDConsts.BTCmdMsg.SLED_BT_DISCONNECTED:
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_LOST:
                Log.d(TAG, "Connection lost: " + msg.arg2);
                mReader.notifyBluetoothAction("disconnected")
            break;
            }
        break;
        case SDConsts.Msg.SDMsg:
            switch (msg.arg1) {
            case SDConsts.SDCmdMsg.TRIGGER_PRESSED:
                Log.d(TAG, "Trigger pressed");
            break;
            case SDConsts.SDCmdMsg.TRIGGER_RELEASED:
                Log.d(TAG, "Trigger released");
            break;
            }
        break;
        case SDConsts.Msg.RFMsg:
            switch (msg.arg1) {
            case SDConsts.RFCmdMsg.INVENTORY:
            case SDConsts.RFCmdMsg.READ:
                Log.d(TAG, "Read somethind: " + (String) msg.obj)
            break;
            }
        break;
        }
    }
}
