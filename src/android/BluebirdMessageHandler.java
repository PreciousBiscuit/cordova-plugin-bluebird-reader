package land.cookie.cordova.plugin.bluebirdreader;

// import android.util.Log;
import android.os.Handler;
import android.os.Message;
import android.bluetooth.BluetoothAdapter;
import co.kr.bluebird.sled.SDConsts;

public class BluebirdMessageHandler extends Handler {
    private static final String TAG = "CLPB_BluebirdReader";

    private BluebirdReader mReader;

    protected BluebirdMessageHandler(BluebirdReader reader) {
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
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_STATE_CHANGED: // 58
                if (msg.arg2 == 0)
                    mReader.notifyReaderMaybeDisconnected();
            break;
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_ESTABLISHED: // 60
                mReader.notifyReaderConnected();
            break;
            // case SDConsts.BTCmdMsg.SLED_BT_DISCONNECTED: // 61
            // case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_LOST: // 62
            case SDConsts.BTCmdMsg.SLED_BT_ACL_DISCONNECTED: // 65
                mReader.notifyReaderDisconnected();
            break;
            case SDConsts.BTCmdMsg.SLED_BT_STATE_CHANGED: { // 57
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
            case SDConsts.SDCmdMsg.TRIGGER_PRESSED: // 41
                mReader.startRfidReading();
            break;
            case SDConsts.SDCmdMsg.TRIGGER_RELEASED: // 42
                mReader.stopRfidReading();
            break;
            case SDConsts.SDCmdMsg.SLED_BATTERY_STATE_CHANGED:
                mReader.notifyBatterLevel(msg.arg2);
            break;
            }
        break;
        case SDConsts.Msg.RFMsg: // 0
            switch (msg.arg1) {
            case SDConsts.RFCmdMsg.INVENTORY: // 5
                if (msg.arg2 == SDConsts.RFResult.SUCCESS && msg.obj != null) {
                    mReader.notifyRfidRead(msg.obj.toString());
                }
            break;
            case SDConsts.RFCmdMsg.REGION_CHANGE_START:
                mReader.notifyRegionChange("start");
            break;
            case SDConsts.RFCmdMsg.REGION_CHANGE_END:
                mReader.notifyRegionChange("end");
            break;
            }
        break;
        case SDConsts.Msg.SBMsg: // 4
            switch (msg.arg1) {
            case SDConsts.SBCmdMsg.BARCODE_TRIGGER_PRESSED_SLED: // 86
                mReader.notifyBarcodeReadStart();
            break;
            case SDConsts.SBCmdMsg.BARCODE_TRIGGER_RELEASED_SLED: // 87
                mReader.notifyBarcodeReadStop();
            break;
            case SDConsts.SBCmdMsg.BARCODE_READ: // 88
                if (msg.obj != null) {
                    mReader.notifyBarcodeRead(msg.obj.toString());
                }
            break;
            }
        break;
        case SDConsts.Msg.BCMsg: // 2
            switch (msg.arg1) {
            case SDConsts.BCCmdMsg.BARCODE_TRIGGER_PRESSED: // 81
                mReader.notifyBarcodeReadStart();
            break;
            case SDConsts.BCCmdMsg.BARCODE_TRIGGER_RELEASED: // 82
                mReader.notifyBarcodeReadStop();
            break;
            case SDConsts.BCCmdMsg.BARCODE_READ: // 80
                if (msg.obj != null) {
                    mReader.notifyBarcodeRead(msg.obj.toString());
                }
            break;
            }
        break;
        }
    }
}
