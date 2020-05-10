package land.cookie.cordova.plugin.bluebirdreader;

import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import co.kr.bluebird.sled.BTReader;
import co.kr.bluebird.sled.SDConsts;
import java.lang.reflect.Method;

public class BluebirdCommands {
    private static final String TAG = "CLPB_BluebirdReader";

    private interface Command {
        PluginResult execute(JSONArray params, BTReader reader);
    }

    private static class RFMode {
        private String mName, mRTModulation, mTRModulation;
        private float mTari;
        private int mIndex, mLF;

        public RFMode(int index, String name, String rtModulation, float tari, String trModulation, int lf) {
            mIndex = index;
            mName = name;
            mRTModulation = rtModulation;
            mTari = tari;
            mTRModulation = trModulation;
            mLF = lf;
        }

        public JSONObject toJson() {
            JSONObject obj = new JSONObject();

            try {
                obj.put("index", mIndex);
                obj.put("name", mName);
                obj.put("rtModulation", mRTModulation);
                obj.put("tari", mTari);
                obj.put("trModulation", mTRModulation);
                obj.put("lf", mLF);
            }
            catch (JSONException ex) {}
            return obj;
        }
    }

    // Same naming as SDConsts.RFRegion enum
    private static final String[] sRegionList = {
        "KOREA",
        "ETSI",
        "FCC",
        "AUSTRALIA",
        "BANGLADESH",
        "BRAZIL",
        "BRUNEI",
        "CHINA",
        "HONGKONG",
        "INDIA",
        "INDONESIA",
        "IRAN",
        "ISRAEL",
        "JAPAN_1",
        "JAPAN_2",
        "JORDAN",
        "MALAYSIA",
        "MOROCCO",
        "NEW_ZEALAND",
        "PAKISTAN",
        "PERU",
        "PHILIPPINES",
        "SINGAPORE",
        "SOUTH_AFRICA",
        "TAIWAN",
        "THAILAND",
        "URUGUAY",
        "VENEZUELA",
        "VIETNAM",
        "RUSSIA",
        "ALGERIA",
        "EGYPT",
        "CHILE",
    };
    private static final RFMode[] sRFModeList = {
        new RFMode(0, "DSB_ASK_1", "DSB_ASK", 25f, "FM0", 40),
        new RFMode(1, "PB_ASK_1", "PB_ASK", 25f, "Miller-4", 250),
        new RFMode(2, "PB_ASK_2", "PB_ASK", 25f, "Miller-4", 300),
        new RFMode(3, "DSB_ASK_2", "DSB_ASK", 6.25f, "FM0", 400),
    };
    private static final String sRegionPattern = "(.+?)=\\d+;";
    private Map<String, Command> mCommandMap;
    private Pattern mRegionRegex = null;

    protected BluebirdCommands() {
        mCommandMap = new HashMap<>();
        mCommandMap.put("getSerialNumber",      this::getSerialNumber);
        mCommandMap.put("getBattery",           this::getBattery);
        mCommandMap.put("getAvailableRegions",  this::getAvailableRegions);
        mCommandMap.put("getRegion",            this::getRegion);
        mCommandMap.put("setRegion",            this::setRegion);
        mCommandMap.put("getAvailableRFModes",  this::getAvailableRFModes);
        mCommandMap.put("getRFMode",            this::getRFMode);
        mCommandMap.put("setRFMode",            this::setRFMode);
        mCommandMap.put("getAntennaPower",      this::getAntennaPower);
        mCommandMap.put("setAntennaPower",      this::setAntennaPower);
        mRegionRegex = Pattern.compile(sRegionPattern);
    }

    protected PluginResult execute(String commandName, JSONArray params, BTReader reader) {
        Command command = mCommandMap.get(commandName);

        if (command == null)
            return new PluginResult(PluginResult.Status.ERROR, "Unknown command");
        return command.execute(params, reader);
    }

    protected PluginResult getSerialNumber(JSONArray ignoreParams, BTReader reader) {
        String serialNumber = reader.SD_GetSerialNumber();

        if (serialNumber.startsWith("-")) {
            try {
                int eError = Integer.parseInt(serialNumber);
                return resultError(getRfError(eError, "Unknown error"));
            }
            catch (NumberFormatException ex) {
                return resultError("Unexpected value returned from the device");
            }
        }
        return resultSuccess(serialNumber);
    }

    protected PluginResult getBattery(JSONArray ignoreParams, BTReader reader) {
        int value = reader.SD_GetBatteryStatus();
        if (value < 0)
            return resultError(getRfError(value, "Unknown error"));
        return resultSuccess(value);
    }

    protected PluginResult getAvailableRegions(JSONArray ignoreParams, BTReader reader) {
        String regions = reader.RF_GetAvailableRegionAtThisDevice();

        if (regions.startsWith("-")) {
            try {
                int eError = Integer.parseInt(regions);
                return resultError(getRfError(eError, "No regions available at this device"));
            }
            catch (NumberFormatException ex) {
                return resultError("Unexpected value returned from the device");
            }
        }

        try {
            JSONArray response = new JSONArray();
            regions = regions.replaceFirst("RFRegion:", "");
            Matcher matcher = mRegionRegex.matcher(regions);

            while (matcher.find()) {
                JSONObject region = new JSONObject();
                region.put("index", Integer.parseInt(matcher.group(0)));
                region.put("name", matcher.group(1));
                response.put(region);
            }
            if (response.length() == 0)
                return resultError("No regions available at this device");
            return resultSuccess(response);
        }
        catch (JSONException ex) {}
        catch (NumberFormatException ex) {}
        return resultError("Error parsing region list format");
    }

    protected PluginResult getRegion(JSONArray ignoreParams, BTReader reader) {
        int value = reader.RF_GetRegion();
        if (value < 0)
            return resultError(getRfError(value, "Unknown error: " + Integer.toString(value)));

        try {
            JSONObject response = new JSONObject();
            response.put("index", value);
            response.put("name", sRegionList[value]);
            return resultSuccess(response);
        }
        catch (JSONException ex) {}
        catch (ArrayIndexOutOfBoundsException ex) {}
        return resultError("Error parsing value");
    }

    protected PluginResult setRegion(JSONArray params, BTReader reader) {
        try {
            int value = params.getInt(0);
            int result = reader.RF_SetRegion(value);
            if (result != 0)
                return resultError(getRfError(result, "Unknown error: " + Integer.toString(result)));
            return resultSuccess("Changing");
        }
        catch (JSONException ex) {}
        return resultError("Incorrect argument; expected integer");
    }

    protected PluginResult getAvailableRFModes(JSONArray ignoreParams, BTReader ignoreReader) {
        // There is no such method on the reader so all those values were taken from documentation.
        JSONArray response = new JSONArray();

        for (RFMode mode : sRFModeList) {
            response.put(mode.toJson());
        }
        return resultSuccess(response);
    }

    protected PluginResult getRFMode(JSONArray ignoreParams, BTReader reader) {
        int value = reader.RF_GetRFMode();
        if (value < 0)
            return resultError(getRfError(value, "Unknown error: " + Integer.toString(value)));

        try {
            return resultSuccess(sRFModeList[value].toJson());
        }
        catch (ArrayIndexOutOfBoundsException ex) {}
        return resultError("Error parsing value");
    }

    protected PluginResult setRFMode(JSONArray params, BTReader reader) {
        try {
            int value = params.getInt(0);
            int result = reader.RF_SetRFMode(value);
            if (result != 0)
                return resultError(getRfError(result, "Unknown error: " + Integer.toString(result)));
            return resultSuccess();
        }
        catch (JSONException ex) {}
        return resultError("Incorrect argument; expected integer");
    }

    protected PluginResult getAntennaPower(JSONArray ignoreParams, BTReader reader) {
        int value = reader.RF_GetRadioPowerState();
        if (value < 0)
            return resultError(getRfError(value, "Unknown error: " + Integer.toString(value)));
        return resultSuccess(value);
    }

    protected PluginResult setAntennaPower(JSONArray params, BTReader reader) {
        try {
            int value = params.getInt(0);
            int result = reader.RF_SetRadioPowerState(value);
            if (result != 0)
                return resultError(getRfError(result, "Unknown error: " + Integer.toString(result)));
            return resultSuccess();
        }
        catch (JSONException ex) {}
        return resultError("Incorrect argument; expected integer");
    }

    private PluginResult resultSuccess() {
        return new PluginResult(PluginResult.Status.OK);
    }

    private PluginResult resultSuccess(String value) {
        return new PluginResult(PluginResult.Status.OK, value);
    }

    private PluginResult resultSuccess(int value) {
        return new PluginResult(PluginResult.Status.OK, value);
    }

    private PluginResult resultSuccess(boolean value) {
        return new PluginResult(PluginResult.Status.OK, value);
    }

    private PluginResult resultSuccess(JSONObject value) {
        return new PluginResult(PluginResult.Status.OK, value);
    }

    private PluginResult resultSuccess(JSONArray value) {
        return new PluginResult(PluginResult.Status.OK, value);
    }

    private PluginResult resultError(String error) {
        return new PluginResult(PluginResult.Status.ERROR, error);
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
        case SDConsts.RFResult.ARGUMENT_ERROR:
            return "Wrong argument was specified.";
        default:
            return defaultErrorMsg;
        }
    }
}
