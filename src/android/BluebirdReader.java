package land.cookie.cordova.plugin.bluebirdreader;

import java.util.ArrayList;
import java.util.List;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class BluebirdReader extends CordovaPlugin {
    private static final String TAG = "CLPB_BluebirdReader"

    @Override
    public boolean execute (
        String action, final JSONArray args, final CallbackContext callbackContext
    ) throws JSONException {
        return false;
    }
}
