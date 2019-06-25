package land.cookie.cordova.plugin.bluebirdreader;

// import android.util.Log;
import android.os.Handler;
import android.os.Message;
import android.bluetooth.BluetoothAdapter;
import co.kr.bluebird.sled.SDConsts;

public class BluebirdMessageHandler extends Handler {
    private static final String TAG = "CLPB_BluebirdReader";

    private BluebirdReader mReader;

    BluebirdMessageHandler(BluebirdReader reader) {
        mReader = reader;
    }

    @Override
    public void handleMessage(Message msg) {
        // Log.d(TAG, "~~~~~ Message ~~~~~");
        // Log.d(TAG, Integer.toString(msg.what));
        // Log.d(TAG, Integer.toString(msg.arg1));
        // Log.d(TAG, Integer.toString(msg.arg2));
        // if (msg.obj != null) {
        //     Log.d(TAG, "Has object: " + msg.obj.getClass().getSimpleName());
        // }
        // Log.d(TAG, "~~~~~ /Message ~~~~~");
        switch (msg.what) {
        case SDConsts.Msg.BTMsg: // 3
            switch (msg.arg1) {
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_STATE_CHANGED:
                if (msg.arg2 == 0)
                    mReader.notifyReaderMaybeDisconnected();
            break;
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_ESTABLISHED:
                mReader.notifyReaderConnected();
            break;
            // case SDConsts.BTCmdMsg.SLED_BT_DISCONNECTED:
            // case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_LOST:
            case SDConsts.BTCmdMsg.SLED_BT_ACL_DISCONNECTED:
                mReader.notifyReaderDisconnected();
            break;
            case SDConsts.BTCmdMsg.SLED_BT_STATE_CHANGED: {
                // Disconnect the reader when bluetooth is turned off.
                // Somehow the reader manages to communicate with a mobile phone even though bluetooth is turned off.
                BluetoothAdapter btAdapter = BluetoothAdapter.getDefaultAdapter();
                if (btAdapter != null && !btAdapter.isEnabled())
                    mReader.disconnectReader();
            } break;
            }
        break;
        case SDConsts.Msg.SDMsg: // 1
            switch (msg.arg1) {
            case SDConsts.SDCmdMsg.TRIGGER_PRESSED:
                mReader.startRfidReading();
            break;
            case SDConsts.SDCmdMsg.TRIGGER_RELEASED:
                mReader.stopRfidReading();
            break;
            }
        break;
        case SDConsts.Msg.RFMsg: // 0
            switch (msg.arg1) {
            case SDConsts.RFCmdMsg.INVENTORY:
                if (msg.arg2 == SDConsts.RFResult.SUCCESS && msg.obj != null) {
                    mReader.notifyRfidRead(msg.obj.toString());
                }
            break;
            }
        break;
        case SDConsts.Msg.SBMsg: // 4
            switch (msg.arg1) {
            case SDConsts.SBCmdMsg.BARCODE_TRIGGER_PRESSED_SLED:
                mReader.notifyBarcodeReadStart();
            break;
            case SDConsts.SBCmdMsg.BARCODE_TRIGGER_RELEASED_SLED:
                mReader.notifyBarcodeReadStop();
            break;
            case SDConsts.SBCmdMsg.BARCODE_READ:
                if (msg.obj != null) {
                    mReader.notifyBarcodeRead(msg.obj.toString());
                }
            break;
            }
        break;
        }
    }
}
