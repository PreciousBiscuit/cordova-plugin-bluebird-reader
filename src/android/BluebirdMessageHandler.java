package land.cookie.cordova.plugin.bluebirdreader;

// import android.util.Log;
import android.os.Handler;
import android.os.Message;
import co.kr.bluebird.sled.SDConsts;

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
                // Log.d(TAG, "Connection established");
                mReader.notifyReaderConnected();
            break;
            // case SDConsts.BTCmdMsg.SLED_BT_DISCONNECTED:
            case SDConsts.BTCmdMsg.SLED_BT_CONNECTION_LOST:
                // Log.d(TAG, "Connection lost");
                mReader.notifyReaderDisconnected();
            break;
            }
        break;
        case SDConsts.Msg.SDMsg:
            switch (msg.arg1) {
            case SDConsts.SDCmdMsg.TRIGGER_PRESSED:
                // Log.d(TAG, "Trigger pressed");
                mReader.startReading();
            break;
            case SDConsts.SDCmdMsg.TRIGGER_RELEASED:
                // Log.d(TAG, "Trigger released");
                mReader.stopReading();
            break;
            }
        break;
        case SDConsts.Msg.RFMsg:
            switch (msg.arg1) {
            case SDConsts.RFCmdMsg.INVENTORY:
            case SDConsts.RFCmdMsg.READ:
                if (msg.arg2 == SDConsts.RFResult.SUCCESS && msg.obj != null) {
                    // Log.d(TAG, "Read: " + (String) msg.obj);
                    mReader.notifyRead("rfid", (String) msg.obj);
                }
            break;
            }
        break;
        }
    }
}
