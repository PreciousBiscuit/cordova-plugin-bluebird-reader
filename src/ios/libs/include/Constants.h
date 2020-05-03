//
//  Constants.h
//  BluebirdRfid Application
//
//  Created by BluebirdCorp on 28/12/16.
//  Copyright © 2016-2017 Bluebirdcorp... All rights reserved.
//

#ifndef Constants_h
#define Constants_h


#endif /* Constants_h */

////////////////////////////////////////////////////////////////////////
// User Open Constants
////////////////////////////////////////////////////////////////////////
#define RF_OPEN_SUCCESS					true
#define RF_OPEN_FAIL							false
#define KILL_PASSWORD_LENGTH		8
#define LOCK_PASSWORD_LENGTH		8
#define ACCESS_PASSWORD_LENGTH	8
#define LOCK_MASK_LENGTH				4
#define LOCK_ACTION_LENGTH			4
#define RSSI_PREFIX_IN_TAG				"rssi:"
#define SYM_PREFIX_IN_BARCODE		"sym:"

/**
 * Only for Bluetooth interface
 */
#define BT_NAME_MAX_LENGTH						9
#define SLED_INTERFACE_ERROR						-1

#define LOW_BATTERY_PERCENT						7	// 5 -> 7 Because of battery gauge is moving in inventory state.(Can't check gauge level correctly in inventory state.)
#define BARCODE_LOW_BATTERY_PERCENT		4

//+sb barcode feature
#define SB_PRESET_VALUE_MAX_LENGTH			15
#define SB_ILLUMINATION_DATA_MAX_SIZE	251
//-sb barcode feature
/**
 * BB RF callback message values.
 */
#define Msg_RFMsg 0
#define Msg_SDMsg 1
#define Msg_BCMsg 2
#define Msg_BTMsg 3
#define Msg_SBMsg 4

/**
 * BB RF callback command message values.
 */
#define RFCmdMsg_INVENTORY              5
#define RFCmdMsg_STOP_INVENTORY         6
#define RFCmdMsg_READ                   7
#define RFCmdMsg_WRITE                  8
#define RFCmdMsg_WRITE_ACCESS_PASSWORD  9
#define RFCmdMsg_WRITE_KILL_PASSWORD    10
#define RFCmdMsg_WRITE_TAG_ID           11
#define RFCmdMsg_BLOCK_WRITE            12
#define RFCmdMsg_BLOCK_PERMALOCK        13
#define RFCmdMsg_BLOCK_ERASE            14
#define RFCmdMsg_LOCK                   15
#define RFCmdMsg_KILL                   16
#define RFCmdMsg_LOCATE                 17
#define RFCmdMsg_RESPONSE_CODE          20
#define RFCmdMsg_REGION_CHANGE_START    21
#define RFCmdMsg_REGION_CHANGE_END      22
#define RFCmdMsg_UPDATE_RF_FW_START     23
#define RFCmdMsg_UPDATE_RF_FW           24
#define RFCmdMsg_UPDATE_RF_FW_END       25
#define RFCmdMsg_UNKNOWN                50

/**
 * BB RF Get command common result values.
 */
#define RFCommonResult_BLUETOOTH_NOT_ENABLED    -15
#define RFCommonResult_ACCESS_TIMEOUT           -32
#define RFCommonResult_NOT_SUPPORTED_API        -36
#define RFCommonResult_ERROR_HOTSWAP_STATE      -37
#define RFCommonResult_STOP_FAILED_TRY_AGAIN    -17
#define RFCommonResult_COMMUNICATION_ERROR      -16
#define RFCommonResult_CHARGING_STATE_ERROR     -14
#define RFCommonResult_FILE_IS_NOT_EXIST        -13
#define RFCommonResult_LOW_BATTERY              -12
#define RFCommonResult_NOT_INVENTORY_STATE      -11
#define RFCommonResult_ALREADY_CONNECTED        -10
#define RFCommonResult_ALREADY_DISCONNECTED      -9
#define RFCommonResult_DUP_CMD_ERROR             -8
#define RFCommonResult_READER_OR_SERIAL_STATUS_ERROR  -7
#define RFCommonResult_MODE_ERROR               -6
#define RFCommonResult_SD_NOT_CONNECTED         -5
#define RFCommonResult_OTHER_CMD_RUNNING_ERROR  -4
#define RFCommonResult_ARGUMENT_ERROR           -3
#define RFCommonResult_ALREADY_OPENED           -2
#define RFCommonResult_OTHER_ERROR              -1

/**
 * BB RF Access and Set command result values.
 */
#define RFResult_SUCCESS                        0
#define RFResult_MODE_ERROR                     -6
#define RFResult_LOW_BATTERY                    -12
#define RFResult_STOP_FAILED_TRY_AGAIN          -17
#define RFResult_NOT_INVENTORY_STATE            -11
#define RFResult_READER_OR_SERIAL_STATUS_ERROR  -7
#define RFResult_HANDLE_MISMATCH_ERROR           1
#define RFResult_UNDEFINED                       2
#define RFResult_MEMORY_OVERRUN                  3
#define RFResult_MEMORY_LOCKED                  4
#define RFResult_ZERO_KILL_PASSWORD             5
#define RFResult_TAG_LOST                       6
#define RFResult_COMMAND_FORMAT_ERROR           7
#define RFResult_READ_COUNT_INVALID             8
#define RFResult_OUT_OF_RETRIES                 9
#define RFResult_OPERATION_FAILED               10
#define RFResult_INSUFFICIENT_POWER             11
#define RFResult_CRC_ERROR_ON_TAG_RESPONSE      12
#define RFResult_NO_TAG_REPLY                   13
#define RFResult_INVALID_PASSWORD               14
#define RFResult_NONSPECIFIC_ERROR              15


/**
 * RF Dutycycle values.
 */
#define RFDutyCycle_RFCommonResult_MIN_DUTY 0
#define RFDutyCycle_RFCommonResult_MAX_DUTY 1000

/**
 * RF AccessTimeout values.
 */
#define RFAccessTimeout_RFCommonResult_MIN_ACCESS_TIMEOUT 100
#define RFAccessTimeout_RFCommonResult_MAX_ACCESS_TIMEOUT 10000

/**

/**
 * RF Power values.
 */
#define RFPower_MAX_POWER 30
#define RFPower_MIN_POWER 5

/**
 * RF Selection Flag
 */
#define RFSelectionFlag_RFCommonResult_ALL 1
#define RFSelectionFlag_RFCommonResult_DEASSERTED 2
#define RFSelectionFlag_RFCommonResult_ASSERTED 3
 
/**
 * Max power  values.
 */

#define RFMAXPOWER_RFCommonResult_MIN_POWER 0
#define RFMAXPOWER_RFCommonResult_MAX_POWER 300


/*
 * [0xB67] R-T Modulation : 0 = DSB, 1=SSB, 2 = PR_ASK
 * [0xB68] Tari : 6250, 12500, 25000
 * [0xB6E] Miller Number : 0 = FM0, 1 = M2, 2 = M4, 3 = M8
 * [0xB6F] Link Freq : Hz
 *
 * [0xB69] X : 0 = 0.5, 1 = 1
 * [0xB6A] PW : 3125, 6250, 12500
 * [0xB6B] RTCal : 2.5Tari(if X = 0.5) <= RTCal <= 3Tari(if X = 1)
 * [0xB6C] TRCal : 1.1RTCal <= TRCal <= 3RTCal
 * [0xB6D] Divide Ratio : 0 = DR 8, 1 = DR 64/3
 *
 *
 * DSB_ASK_1(0) : R2T mode type = 0, Tari = 25000, X = 1, PW = 12500, RTCal = 75000, TRCal = 200000, DR = 2(0), Miller Number = 0,
 *     TRLink Freq = 40000, Var T2 Delay = 51, Rx Delay = 577, Min To T2 Delay = 75, Tx Prop Delay = 24
 *
 * PR_ASK_1(1) : R2T mode type = 2, Tari = 25000, X = 0, PW =  8250, RTCal = 62500, TRCal =  85333, DR = 3(1), Miller Number = 2,
 *     TRLink Freq = 250000, Var T2 Delay = 0, Rx Delay = 337, Min To T2 Delay = 12, Tx Prop Delay = 14
 *
 * PR_ASK_2(2) : R2T mode type = 2, Tari = 25000, X = 0, PW =  8250, RTCal = 62500, TRCal =  71111, DR = 3(1), Miller Number = 2,
 *     TRLink Freq = 300000, Var T2 Delay = 0, Rx Delay = 337, Min To T2 Delay = 10, Tx Prop Delay = 14
 *
 * DSB_ASK_2(3) : R2T mode type = 0, Tari = 6250, X = 0, PW = 3125, RTCal = 15625, TRCal = 20000, DR = 2(0), Miller Number = 0,
 *     TRLink Freq = 400000, Var T2 Delay = 0, Rx Delay = 313, Min To T2 Delay = 8, Tx Prop Delay = 7
 */


/**
 * RF Mode values.
 */
#define RFMode_RFCommonResult_DSB_ASK_1 0
#define RFMode_RFCommonResult_PR_ASK_1 1
#define RFMode_RFCommonResult_PR_ASK_2 2
#define RFMode_RFCommonResult_DSB_ASK_2 3

/**
 * RF Singulation values.
 */
#define RFSingulation_RFCommonResult_MIN_SINGULATION  0
#define RFSingulation_RFCommonResult_MAX_SINGULATION 15

/**
 * RF Region values.
 */
// EU Variation, RFR900WXXXX
// Regions : INDIA, IRAN, JORDAN, MOROCCO, PAKISTAN
// Same Region : 1. Iran, Jordan, Pakistan
// FCC Variation RFR900NXXXX
// Same Region : 1. Brunei, Indonesia
//               2. Hongkong, Singapore, Thailand, Vietnam
//               3. Taiwan, Venezuela
/**
 * RF Region values.
 */
#define RFCommonResult_RFRegion_UNKNOWN -1
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_KOREA 0
//EU module(same region : ETSI, Ukraine, Tunisia, Egypt)
/**
 Available only on RFR900W model.
 */
#define RFCommonResult_RFRegion_ETSI 1
//FCC module(same region : Canada, Costa Rica, Mexico)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_FCC 2
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_AUSTRALIA 3
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_BANGLADESH  4
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_BRAZIL  5
//FCC module(same region : Brunei, Indonesia)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_BRUNEI 6

//CHINA module
/**
 * Available only on RFR900C model.
 */
#define RFCommonResult_RFRegion_CHINA  7
//FCC module(same region : Hongkong, Singapore, Thailand, Vietnam)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_HONGKONG 8
//EU module
/**
 * Available only on RFR900W model.
 */
#define RFCommonResult_RFRegion_INDIA 9
//FCC module(same region : Brunei, Indonesia)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_INDONESIA 10
//EU module(same region : Iran, Jordan, Pakistan)
/**
 * Available only on RFR900W model.
 */
#define RFCommonResult_RFRegion_IRAN 11
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_ISRAEL 12
//JAPAN_1 module
/**
 * Available only on RFR900J1 model.
 */
#define RFCommonResult_RFRegion_JAPAN_1  13
//JAPAN_2 module
/**
 * Available only on RFR900J2 model.
 */
#define RFCommonResult_RFRegion_JAPAN_2  14

//EU module(same region : Iran, Jordan, Pakistan)
/**
 * Available only on RFR900W model.
 */
#define RFCommonResult_RFRegion_JORDAN  15
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_MALAYSIA  16
//EU module - 500mW Power limitation -> 26dBm
/**
 * Available only on RFR900MA model.
 */
#define RFCommonResult_RFRegion_MOROCCO 17
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_NEW_ZEALAND 18
//EU module(same region : Iran, Jordan, Pakistan)
/**
 * Available only on RFR900W model.
 */
#define RFCommonResult_RFRegion_PAKISTAN 19
//FCC module(same region : Peru, Chile)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_PERU  20
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_PHILIPPINES 21
//FCC module(same region : Hongkong, Singapore, Thailand, Vietnam)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_SINGAPORE 22
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_SOUTH_AFRICA 23
//FCC module(same region : Taiwan, Venezuela)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_TAIWAN 24
//FCC module(same region : Hongkong, Singapore, Thailand, Vietnam)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_THAILAND 25
//FCC module
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_URUGUAY 26
//FCC module(same region : Taiwan, Venezuela)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_VENEZUELA 27
//FCC module(same region : Hongkong, Singapore, Thailand, Vietnam)
/**
 * Available only on RFR900N model.
 */
#define RFCommonResult_RFRegion_VIETNAM  28
//EU module
/**
 * Available only on RFR900W model.
 */
#define RFCommonResult_RFRegion_RUSSIA  29
//FCC module - 100mW Power limitation -> 17dBm
/**
 * Available only on RFR900DZ model.
 */
#define RFCommonResult_RFRegion_ALGERIA 30
//EU module(same region : ETSI, Ukraine, Tunisia, Egypt) - 100mW Power limitation -> 17dBm
/**
 * Available only on RFR900EG model.
 */
#define RFCommonResult_RFRegion_EGYPT	31
//FCC module(same region : Peru, Chile) - 100mW Power limitation -> 17dBm
//Original RF band = 902 - 928, but change to 915 - 928 for certificaiton
/**
 * Available only on RFR900CL model.
 */
#define RFCommonResult_RFRegion_CHILE	32

/**
 * RF RSSI values.
 */
#define RFRssi_RFCommonResult_OFF 0
#define RFRssi_RFCommonResult_ON 1

/**
 * RF Session values.
 */
#define RFSession_RFCommonResult_SESSION_S0 0
#define RFSession_RFCommonResult_SESSION_S1 1
#define RFSession_RFCommonResult_SESSION_S2 2
#define RFSession_RFCommonResult_SESSION_S3 3

/**
 * RF Toggle values.
 */
#define RFToggle_RFCommonResult_OFF 0
#define RFToggle_RFCommonResult_ON 1

/**
 * RF Dwelltime values.
 */
#define RFDwell_RFCommonResult_MIN_DWELL    100
#define RFDwell_RFCommonResult_MAX_DWELL    400

/**
 * RF Inventory SessionTarget values.
 */
#define RFInvSessionTarget_RFCommonResult_TARGET_A  0
#define RFInvSessionTarget_RFCommonResult_TARGET_B  1


/**
 * RF Memory Type values.
 */
#define RFMemType_RESERVED  0
#define RFMemType_EPC       1
#define RFMemType_TID       2
#define RFMemType_USER      3

/**
 * BB Sled callback command message values.
 */
#define SDCmdMsg_TRIGGER_PRESSED                    41
#define SDCmdMsg_TRIGGER_RELEASED                   42
#define SDCmdMsg_SLED_BATTERY_STATE_CHANGED         43
#define SDCmdMsg_SLED_BATTERY_STATE_HOTSWAP         69
#define SDCmdMsg_SLED_MODE_CHANGED                  45
#define SDCmdMsg_SLED_SLED_INVENTORY_STATE_CHANGED  46
#define SDCmdMsg_SLED_SLED_WAKEUP                   47
#define SDCmdMsg_SLED_UPDATE_SD_FW_START            48
#define SDCmdMsg_SLED_UPDATE_SD_FW                  49
#define SDCmdMsg_SLED_UPDATE_SD_FW_END              50
#define SDCmdMsg_SLED_UPDATE_SD_BOOT_START          66
#define SDCmdMsg_SLED_UPDATE_SD_BOOT                67
#define SDCmdMsg_SLED_UPDATE_SD_BOOT_END            68
#define SDCmdMsg_SLED_UNKNOWN_DISCONNECTED          51

/**
 * BB Sled callback  Error String result values.
 */
#define ERROR_STR  "Error"

/**
 * BB Sled callback Not Supported or Not Supported yet  String result value.
 */
#define NOT_SUPPORTED_API_STR  "Not Supported API"

/**
 * BB Sled Get command common result values.
 */
#define SDCommonResult_NOT_SUPPORTED_API        -36
#define SDCommonResult_ACCESS_TIMEOUT           -32
#define SDCommonResult_BT_NAME_LENGTH_ERROR     -19
#define SDCommonResult_COMMUNICATION_ERROR      -16
#define SDCommonResult_BLUETOOTH_NOT_ENABLED    -15
#define SDCommonResult_CHARGING_STATE_ERROR     -14
#define SDCommonResult_FILE_IS_NOT_EXIST        -13
#define SDCommonResult_LOW_BATTERY              -12
#define SDCommonResult_ALREADY_CONNECTED        -10
#define SDCommonResult_ALREADY_DISCONNECTED     -9
#define SDCommonResult_DUP_CMD_ERROR            -8
#define SDCommonResult_READER_OR_SERIAL_STATUS_ERROR    -7
#define SDCommonResult_MODE_ERROR               -6
#define SDCommonResult_SD_NOT_CONNECTED         -5
#define SDCommonResult_OTHER_CMD_RUNNING_ERROR  -4
#define SDCommonResult_ARGUMENT_ERROR           -3
#define SDCommonResult_OTHER_ERROR              -1

/**
 * SD Battery State values.
 */
#define SDBatteryState_SDCommonResult_MIN  0
#define SDBatteryState_SDCommonResult_MAX  100

/**
 * SD Trigger State values.(BB SLED mode values.)
 */
#define SDTriggerMode_SDCommonResult_RFID      0
#define SDTriggerMode_SDCommonResult_BARCODE   1

/**
 * AUTORECONNECT
 */
#define SDAutoconnect_SDCommonResult_ENABLE   1
#define SDAutoconnect_SDCommonResult_DISABLE  0
/**
 * SD Buzzer Level values.
 */
#define SDBuzzerLevel_SDCommonResult_LOW    0
#define SDBuzzerLevel_SDCommonResult_MID    1
#define SDBuzzerLevel_SDCommonResult_HIGH   2


/**
 * SD Sleep Timeout values.
 */
#define SDSleepTimeout_SDCommonResult_NO_SLEEP  0
#define SDSleepTimeout_SDCommonResult_SEC_15    1
#define SDSleepTimeout_SDCommonResult_SEC_30    2
#define SDSleepTimeout_SDCommonResult_MIN_1     3
#define SDSleepTimeout_SDCommonResult_MIN_3     4
#define SDSleepTimeout_SDCommonResult_MIN_5     5
#define SDSleepTimeout_SDCommonResult_MIN_10    6


/**
 * SD Buzzer State values.
 */
#define SDBuzzerState_SDCommonResult_MUTE   0
#define SDBuzzerState_SDCommonResult_NOISY  1


/**
 * SD Charge State values.
 */
#define SDChargeState_OFF   0
#define SDChargeState_ON    1

/**
 * SD Mode Key Enable State values.
 */
#define SDModeKeyState_SDCommonResult_DISABLE 0
#define SDModeKeyState_SDCommonResult_ENABLE 1

/**
 * SD Trigger Key Enable State values.
 */
#define SDTriggerKeyState_SDCommonResult_DISABLE    0
#define SDTriggerKeyState_SDCommonResult_ENABLE     1

/**
 * SD Wakeup State values.(BB SLED State values.)
 */
#define SDState_SDCommonResult_SLEEP    0
#define SDState_SDCommonResult_WAKEUP   1

/**
 * BB Barcode command message values.
 * Occurs only in models that do not have a barcode on SLED
 */
#define BCCmdMsg_BARCODE_READ               80
#define BCCmdMsg_BARCODE_TRIGGER_PRESSED    81
#define BCCmdMsg_BARCODE_TRIGGER_RELEASED   82
#define BCCmdMsg_BARCODE_ACCESS_TIMEOUT     84
#define BCCmdMsg_BARCODE_ERROR              85


/**
 * BB Barcode callback result values.
 * Uses only in models that have a barcode on Bluebird Android Device
 */
#define BCResult_NOT_SUPPORTED_API              -36
#define BCResult_BARCODE_NOT_ACTIVE             -35
#define BCResult_ALREADY_PAUSE                  -34
#define BCResult_ALREADY_RESUME                 -33
#define BCResult_ACCESS_TIMEOUT                 -32
#define BCResult_LOW_BATTERY                    -12
#define BCResult_READER_OR_SERIAL_STATUS_ERROR  -7
#define BCResult_MODE_ERROR                     -6
#define BCResult_SD_NOT_CONNECTED               -5
#define BCResult_OTHER_CMD_RUNNING_ERROR        -4
#define BCResult_ARGUMENT_ERROR                 -3
#define BCResult_OTHER_ERROR                    -1
#define BCResult_SUCCESS                         0

/**
 * BB Barcode HW key format value.
 * Uses only in models that have a barcode on Bluebird Android Device
 */
#define BCKeyFormat_PTT_SCAN    0
#define BCKeyFormat_SCAN_PTT    1
#define BCKeyFormat_PTT_PTT     2
#define BCKeyFormat_SCAN_SCAN   3


/**
 * BB Barcode State value
 * Uses only in models that have a barcode on Bluebird Android Device
 */
#define BCState_ACTIVE      0
#define BCState_PAUSED      1
#define BCState_NOT_ACTIVE  2

//barcode feature
/**
 * BB Barcode attached to SLED command message values.
 * Occurs only in models that do not have a barcode on SLED
 */
#define BARCODE_TRIGGER_PRESSED_SLED    86
#define BARCODE_TRIGGER_RELEASED_SLED   87
#define BARCODE_READ                    88
#define BARCODE_RESET_CONFIG_START      89
#define BARCODE_RESET_CONFIG_END        90

//barcode feature
/**
 * BB Barcode attached to SLED callback result values.
 * Uses only in models that have a barcode on Bluebird Android Device
 */
#define SBResult_NOT_SUPPORTED_API          -36
#define SBResult_BARCODE_NOT_ACTIVE         -35
#define SBResult_ALREADY_PAUSE              -34
#define SBResult_ALREADY_RESUME             -33
#define SBResult_ACCESS_TIMEOUT             -32
#define SBResult_BLUETOOTH_NOT_ENABLED      -15
#define SBResult_LOW_BATTERY                -12
#define SBResult_READER_OR_SERIAL_STATUS_ERROR  -7
#define SBResult_MODE_ERROR                 -6
#define SBResult_SD_NOT_CONNECTED           -5
#define SBResult_OTHER_CMD_RUNNING_ERROR    -4
#define SBResult_ARGUMENT_ERROR             -3
#define SBResult_OTHER_ERROR                -1
#define SBResult_SUCCESS                     0

/**
 * SB Preset text type values
 */
#define SBPresetType_PREFIX         0
#define SBPresetType_SUFFIX         1
#define SBPresetType_PREAMBLE       2
#define SBPresetType_POSTAMBLE      3

//barcode feature
/**
 * BB SB Barcode Trigger Mode
 */
# define SBBarcodeTriggerMode_LEVEL      0
# define SBBarcodeTriggerMode_PULSE      1
# define SBBarcodeTriggerMode_EDGE       2
# define SBBarcodeTriggerMode_AUTOSTAND  3

//barcode feature
/**
 * UPC-A
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_UPC_A  0x0001                             //enable (1:enable, 0:disable)

/**
 * UPC-E
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_UPC_E  0x0002                             //enable (1:enable, 0:disable)

/**
 * UPC-E1
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_UPC_E1  0x000C                            //enable (1:enable, 0:disable)

/**
 * EAN-8/JAN-8
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_EAN8  0x0004                             //enable (1:enable, 0:disable)

/**
 * EAN-13/JAN-13
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_EAN13  0x0003                            //enable (1:enable, 0:disable)

/**
 * Bookland EAN
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_BOOKLAND_EAN  0x0053                     //enable (1:enable, 0:disable)

/**
 * Bookland ISBN Format
 * default = Bookland ISBN-10
 * range = 0:Bookland ISBN-10, 1:Bookland ISBN-13
 */
#define SBParam_BOOKLAND_ISBN_FORMAT  0xF140                      //ISBN-10 (0:Bookland ISBN-10, 1:Bookland ISBN-13)


/**
 * default  Ignore Supplemental
 * range  0:Ignore Supplemental,
 *          1:Decode UPC/EAN/JAN Only With Supplementals,
 *          2:Autodiscriminate UPC/EAN/JAN Supplementals,
 *          3:Enable Smart Supplemental Mode,
 *          4:Enable 378/379 Supplemental Mode,
 *          5:Enable 978/979 Supplemental Mode,
 *          6:Enable 414/419/434/439 Supplemental Mode,
 *          7:Enable 977 Supplemental Mode,
 *          8:Enable 491 Supplemental Mode,
 *          9:Supplemental User-Programmable Type 1,
 *          A:Supplemental User-Programmable Type 1 and 2,
 *          B:Smart Supplemental Plus User-Programmable 1,
 *          C:Smart Supplemental Plus User-Programmable 1 and 2
 */
#define SBParam_DECODE_UPC_EAN_SUPPLEMENTAL  0x0010                     //ignore
//0:Ignore Supplemental
//1:Decode UPC/EAN/JAN Only With Supplementals
//2:Autodiscriminate UPC/EAN/JAN Supplementals
//3:Enable Smart Supplemental Mode
//4:Enable 378/379 Supplemental Mode
//5:Enable 978/979 Supplemental Mode
//6:Enable 414/419/434/439 Supplemental Mode
//7:Enable 977 Supplemental Mode
//8:Enable 491 Supplemental Mode
//9:Supplemental User-Programmable Type 1
//A:Supplemental User-Programmable Type 1 and 2
//B:Smart Supplemental Plus User-Programmable 1
//C:Smart Supplemental Plus User-Programmable 1 and 2

//skip - F1 43

//skip - F1 44

/**
 * UPC/EAN/JAN Supplemental Redundancy
 * default : 10
 * range : 2 ~ 16
 * If you selected Autodiscriminate UPC/EAN/JAN Supplementals,
 * this option adjusts the number of times to decode a symbol without supplementals before transmission.
 * The range is from two to 16 times. Five or above is recommended when decoding a mix of UPC/EAN/JAN symbols with and without supplementals.
 */
#define SBParam_UPC_EAN_SUPPLEMENTAL_REDUNDANCY  0x0050          //10 (2 ~ 30)

/**
 * UPC/EAN/JAN Supplemental AIM ID Format
 * default : Combined
 * range : 0:separate, 1:combined, 2:separate transmissions
 * Separate - transmit UPC/EAN with supplementals with separate AIM IDs but one transmission,
 * i.e.:
 * ]E<0 or 4><data>]E<1 or 2>[supplemental data]
 * Combined - transmit UPC/EAN with supplementals with one AIM ID and one transmission,
 * i.e.:
 * ]E3<data+supplemental data>
 * Separate Transmissions - transmit UPC/EAN with supplementals with separate AIM IDs and separate transmissions,
 * i.e.:
 * ]E<0 or 4><data>
 * ]E<1 or 2>[supplemental data]
 */
#define SBParam_DECODE_UPC_EAN_SUPPLEMENTAL_AIM_ID  0xF1A0              //COMBINED  (BUT EF400 ENABLE/DISABLE)

/**
 * Transmit UPC-A Check Digit
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_TRANSMIT_UPC_A_CHK_DIGIT  0x0028                        //enable (1:enable, 0:disable)

/**
 * Transmit UPC-E Check Digit
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_TRANSMIT_UPC_E_CHK_DIGIT  0x0029                        //enable (1:enable, 0:disable)

/**
 * Transmit UPC-E1 Check Digit
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_TRANSMIT_UPC_E1_CHK_DIGIT  0x002A                       //enable (1:enable, 0:disable)

/**
 * UPC-A Preamble
 * default = System Character
 * range = 0:No Preamble, 1:System Character, 2: System Character& Country Code
 * Preamble characters are part of the UPC symbol, and include Country Code and System Character.
 * There are three options for transmitting a UPC-A preamble to the host device: transmit System Character only,
 * transmit System Character and Country Code ("0" for USA), and transmit no preamble.
 * Select the option that matches the host system.
 */
#define SBParam_UPC_A_PREAMBLE  0x0022                   //1:System Character(0:No Preamble, 1:System Character, 2: System Character& Country Code)

/**
 * UPC-E Preamble
 * default = System Character
 * range = 0:No Preamble, 1:System Character, 2: System Character& Country Code
 * Preamble characters are part of the UPC symbol, and include Country Code and System Character.
 * There are three options for transmitting a UPC-E preamble to the host device: transmit System Character only,
 *  transmit System Character and Country Code ("0" for USA), and transmit no preamble.
 *  Select the option that matches the host system.
 */
#define SBParam_UPC_E_PREAMBLE  0x0023                   //1:System Character(0:No Preamble, 1:System Character, 2: System Character& Country Code)

/**
 * UPC-E1 Preamble
 * default = System Character
 * range = 0:No Preamble, 1:System Character, 2: System Character& Country Code
 * Preamble characters are part of the UPC symbol, and include Country Code and System Character.
 * There are three options for transmitting a UPC-E1 preamble to the host device: transmit System Character only,
 * transmit System Character and Country Code ("0" for USA), and transmit no preamble.
 * Select the option that matches the host system.
 */
#define SBParam_UPC_E1_PREAMBLE  0x0024                  //1:System Character(0:No Preamble, 1:System Character, 2: System Character& Country Code)

/**
 * Convert UPC-E to UPC-A
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_CONVERT_UPC_E_TO_A  0x0025               //disable (1:enable, 0:disable)

/**
 * Convert UPC-E1 to UPC-A
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_CONVERT_UPC_E1_TO_A  0x0026              //disable (1:enable, 0:disable)

/**
 * EAN-8/JAN-8 Extend
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_EAN8_EXTEND  0x0027                      //disable (1:enable, 0:disable)

//skip

/**
 * Coupon Report
 * default = New Coupon Symbols
 * range = 0:Old Coupon Symbol, 1:New Coupon Symbols, 2:Both Coupon Formats
 * Old Coupon Symbols - Scanning an old coupon symbol reports both UPC and Code 128, scanning an interim coupon symbol reports UPC, and scanning a new coupon symbol reports nothing (no decode).
 * New Coupon Symbols - Scanning an old coupon symbol reports either UPC or Code 128, and scanning an interim coupon symbol or a new coupon symbol reports Databar Expanded.
 * Both Coupon Formats - Scanning an old coupon symbol reports both UPC and Code 128, and scanning an interim coupon symbol or a new coupon symbol reports Databar Expanded.
 */
#define SBParam_COUPON_REPORT  0xF1DA                    //new (0:Old Coupon Symbol, 1:New Coupon Symbols, 2:Both Coupon Formats)

/**
 * ISSN EAN
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_ISSN_EAN  0xF169                //disable (1:enable, 0:disable)

/**
 * Code 128
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODE128  0x0008                          //enable (1:enable, 0:disable)

/**
 * Set Lengths for Code 128
 * default = 3
 * range = 0 ~ 255
 */
#define SBParam_CODE128_LEN_MIN  0x00D1                  //3
/**
 * Set Lengths for Code 128
 * default = 30
 * range = 0 ~ 255
 */
#define SBParam_CODE128_LEN_MAX  0x00D2                  //30

/**
 * GS1-128 (formerly UCC/EAN-128)
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_GS1_128  0x000E                          //enable(1:enable, 0:disable)

/**
 * ISBT 128
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_ISBT128  0x0054                          //enable(1:enable, 0:disable)

/**
 * ISBT Concatenation
 * default = disable
 * range = 0:Disable ISBT Concatenation, 1:Enable ISBT Concatenation, 2:Autodiscriminate ISBT Concatenation
 */
#define SBParam_ISBT128_CONCATENATION  0xF141            //disable(0:Disable ISBT Concatenation, 1:Enable ISBT Concatenation, 2:Autodiscriminate ISBT Concatenation)
/**
 * Check ISBT Table
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_ISBT128_CHECK_TABLE  0xF142              //enable(1:enable, 0:disable)
/**
 * ISBT Concatenation Redundancy
 * default = 10
 * range = 2 ~ 20
 * If you set ISBT Concatenation to Autodiscriminate,
 * use this parameter to set the number of times the decoder must decode an ISBT symbol before determining that there is no additional symbol.
 */
#define SBParam_ISBT128_CONCATENATION_REDUNDANCY  0x00DF //10 (2~20 BUT EF400 enable/disable)

/**
 * Code 39
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODE39  0x0000                           //enable (1:enable, 0:disable)

/**
 * Trioptic Code 39
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_TRIOPTIC_CODE39  0x000D                  //enable (1:enable, 0:disable)


/**
 * Convert Code 39 to Code 32
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_CONVERT_CODE39_32  0x0056                //disable (1:enable, 0:disable)

/**
 * Code 32 Prefix
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODE32_PREFIX  0x00E7                           //enable (1:enable, 0:disable)

/**
 * Set Lengths for Code 39
 * default = 3
 * range = length within range: 0 ~ 255
 */
#define SBParam_CODE39_LEN_MIN  0x0012                   //3
/**
 * Set Lengths for Code 39
 * default = 30
 * range = length within range: 0 ~ 255
 */
#define SBParam_CODE39_LEN_MAX  0x0013                   //30

/**
 * Code 39 Check Digit Verification
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODE39_CHK_DIGIT_VERIFICATION  0x0030                        //disable (1:enable, 0:disable)

/**
 * Transmit Code 39 Check Digit
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_TRANSMIT_CODE39_CHK_DIGIT  0x002B                       //disable (1:enable, 0:disable)

/**
 * Code 39 Full ASCII Conversion
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODE39_FULL_ASCII  0x0011                //disable (1:enable, 0:disable)

//skip

/**
 * Code 93
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODE93  0x0009                          //enable (1:enable, 0:disable)

/**
 * Set Lengths for Code 93
 * default = 3
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_CODE93_LEN_MIN  0x001A                   //3
/**
 * Set Lengths for Code 93
 * default = 30
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_CODE93_LEN_MAX  0x001B                   //30

/**
 * Code 11
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODE11  0x000A                           //enable (1:enable, 0:disable)

/**
 * Set Lengths for Code 11
 * default = 3
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_CODE11_LEN_MIN  0x001C                   //3
/**
 * Set Lengths for Code 11
 * default = 30
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_CODE11_LEN_MAX  0x001D                   //30

/**
 * Code 11 Check Digit Verification
 * default = disable
 * range = 0:Disable, 1:One Check Digit, 2:Two Check Digits
 */
#define SBParam_CODE11_CHK_DIGIT_VERIFICATION  0x0034                        //disable (0:Disable, 1:One Check Digit, 2:Two Check Digits)
/**
 * Transmit Code 11 Check Digits
 * default = disable
 * range = 1:Transmit Code 11 Check Digit(s) (Enable), 0:Do Not Transmit Code 11 Check Digit(s) (Disable)
 */
#define SBParam_TRANSMIT_CODE11_CHK_DIGIT  0x002F                       //disable (1:enable, 0:disable)

/**
 * Interleaved 2 of 5 (ITF)
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_INTERLEAVED2OF5  0x0006                  //disable (1:enable, 0:disable)

/**
 * Set Lengths for Interleaved 2 of 5
 * default = 3
 * range = Length Within Range: 0 ~ 55
 */
#define SBParam_INTERLEAVED2OF5_LEN_MIN  0x0016          //3?????
/**
 * Set Lengths for Interleaved 2 of 5
 * default = 30
 * range = Length Within Range: 0 ~ 55
 */
#define SBParam_INTERLEAVED2OF5_LEN_MAX  0x0017          //30?????

/**
 * I 2 of 5 Check Digit Verification
 * default = disable
 * range = 0:disable, 1:USS Check Digit, 2:OPCC Check Digit
 */
#define SBParam_INTERLEAVED2OF5_CHK_DIGIT  0x0031               //disable (0:disable, 1:USS Check Digit, 2:OPCC Check Digit)
/**
 * Transmit I 2 of 5 Check Digit
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_TRANSMIT_INTERLEAVED2OF5_CHK_DIGIT  0x002C              //disable (1:enable, 0:disable)

/**
 * Convert I 2 of 5 to EAN-13
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_CONVERT_INTERLEAVED_EAN13  0x0052        //disable (1:enable, 0:disable)

/**
 * Discrete 2 of 5 (DTF)
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_DISCRETE2OF5  0x0005                     //enable (1:enable, 0:disable)

/**
 * Set Lengths for Discrete 2 of 5
 * default = 3
 * range = Length Within Range: 0 ~ 55
 */
#define SBParam_DISCRETE2OF5_LEN_MIN  0x0014             //3?????
/**
 * Set Lengths for Discrete 2 of 5
 * default = 30
 * range = Length Within Range: 0 ~ 55
 */
#define SBParam_DISCRETE2OF5_LEN_MAX  0x0015             //30?????

/**
 * Codabar (NW - 7)
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODABAR  0x0007                          //enable (1:enable, 0:disable)

/**
 * Set Lengths for Codabar
 * default = 3
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_CODABAR_LEN_MIN  0x0018                  //3?????
/**
 * Set Lengths for Codabar
 * default = 30
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_CODABAR_LEN_MAX  0x0019                  //30?????

/**
 * CLSI Editing
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODABAR_CLSI_EDIT  0x0036                //disable (1:enable, 0:disable)

/**
 * NOTIS Editing
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_CODABAR_NOTIS_EDIT  0x0037               //disable (1:enable, 0:disable)

//skip

/**
 * MSI
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_MSI  0x000B                              //enable (1:enable, 0:disable)

/**
 * Set Lengths for MSI
 * default = 3
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_MSI_LEN_MIN  0x001E                      //3?????
/**
 * Set Lengths for MSI
 * default = 30
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_MSI_LEN_MAX  0x001F                      //30?????

/**
 * MSI Check Digits
 * default = One MSI Check Digit
 * range = 0:One MSI Check Digit, 1:Two MSI Check Digits
 */
#define SBParam_MSI_CHK_DIGIT  0x0032                           //One MSI Check Digit(0:One MSI Check Digit, 1:Two MSI Check Digits)

/**
 * Transmit MSI Check Digit(s)
 * default = disable
 * range = 0:Do Not Transmit MSI Check Digit(s) (Disable), 1:Transmit MSI Check Digit(s) (Enable)
 */
#define SBParam_TRANSMIT_MSI_CHK_DIGIT  0x002E                          //disable(0:Do Not Transmit MSI Check Digit(s) (Disable), 1:Transmit MSI Check Digit(s) (Enable))

/**
 * MSI Check Digit Algorithm
 * default = MOD 10/10
 * range = 0:MOD 10/MOD 11, 1:MOD 10/MOD 10
 */
#define SBParam_MSI_CHK_DIGIT_ALGORITHM  0x0033                 //MOD 10/10(0:MOD 10/MOD 11, 1:MOD 10/MOD 10)

/**
 * Chinese 2 of 5
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_CHINESE_POST  0xF098                     //enable (1:enable, 0:disable)

/**
 * Matrix 2 of 5
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_MATRIX2OF5  0xF16A                       //enable (1:enable, 0:disable)

/**
 * Set Lengths for Matrix 2 of 5
 * default = 3
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_MATRIX2OF5_LEN_MIN  0xF16B               //3???
/**
 * Set Lengths for Matrix 2 of 5
 * default = 30
 * range = Length Within Range: 0 ~ 255
 */
#define SBParam_MATRIX2OF5_LEN_MAX  0xF16C               //20???

/**
 * Matrix 2 of 5 Check Digit
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_MATRIX2OF5_CHK_DIGIT  0xF16E                    //disable (1:enable, 0:disable)

/**
 * Transmit Matrix 2 of 5 Check Digit
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_TRANSMIT_MATRIX2OF5_CHK_DIGIT  0xF16F                   //disable (1:enable, 0:disable)

/**
 * Korean 3 of 5
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_KOREA_POST  0xF145                       //enable (1:enable, 0:disable)

/**
 * Inverse 1D
 * default = Regular
 * range = 0:Regular, 1:Inverse Only, 2:Inverse Autodetect
 */
#define SBParam_INVERSE_1D  0xF14A                       //Regular (0:Regular, 1:Inverse Only, 2:Inverse Autodetect)

/**
 * US Postnet
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_US_POSTNET  0x0059                       //enable (1:enable, 0:disable)


/**
 * US Planet
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_US_PLANET  0x005A                        //enable (1:enable, 0:disable)

/**
 * Transmit US Postal Check Digit
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_TRANSMIT_US_POSTNET_CHK_DIGIT  0x005F                   //enable (1:enable, 0:disable)

/**
 * UK Postal
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_UK_POST  0x005B                          //enable (1:enable, 0:disable)

/**
 * Transmit UK Postal Check Digit
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_TRANSMIT_UK_POST_CHK_DIGIT  0x0060                      //enable (1:enable, 0:disable)

/**
 * Japan Postal
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_JAPANESE_POST  0xF022                    //enable (1:enable, 0:disable)

/**
 * Australia Post
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_AUSTRAILA_POST  0xF023                   //enable (1:enable, 0:disable)

/**
 * Australia Post Format
 * default = Autodiscriminate
 * range = 0:Autodiscriminate, 1:Raw Format, 2:Alphanumeric Encoding, 3:Numeric Encoding
 */
#define SBParam_AUSTRAILA_POST_FORMAT  0xF1CE            //Autodiscriminate(0:Autodiscriminate, 1:Raw Format, 2:Alphanumeric Encoding, 3:Numeric Encoding)

/**
 * Netherlands KIX Code
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_NETHELANS_POST  0xF046                   //enable (1:enable, 0:disable)

/**
 * USPS 4CB/One Code/Intelligent Mail
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_USPS_4  0xF150                           //enable (1:enable, 0:disable)

/**
 * UPU FICS Postal
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_UPI_FICS_POST  0xF163                    //enable (1:enable, 0:disable)

/**
 * GS1 DataBar
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_GS1_DATABAR  0xF052                      //enable (1:enable, 0:disable)

/**
 * GS1 DataBar Limited
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_GS1_LIMIT  0xF053                        //disable (1:enable, 0:disable)

/**
 * GS1 DataBar Limited Security Level
 * default = 3
 * range = 1:Security Level 1, 2:Security Level 2, 3:Security Level 3, 4:Security Level 4
 * Level 1 - No clear margin required.
 * This complies with the original GS1 standard,
 * yet might result in erroneous1 decoding of the DataBar Limited bar code when scanning some UPC symbols that start with the digits "9" and "7".
 * Level 2 - Automatic risk detection.
 * This level of security may result in erroneous decoding of DataBar Limited bar codes when scanning some UPC symbols.
 * If a misdecode is detected, the decoder operates in Level 3 or Level 1.
 * Level 3 - Security level reflects newly proposed GS1 standard that requires a 5X trailing clear margin.
 * Level 4 - Security level extends beyond the standard required by GS1.
 * This level of security requires a 5X leading and trailing clear margin.
 */
#define SBParam_GS1_LIMIT_SECURITY  0xF1D8               //3
//1:Security Level 1
//2:Security Level 2
//3:Security Level 3
//4:Security Level 4

/**
 * GS1 DataBar Expanded
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_GS1_EXPAND  0xF054                       //disable (1:enable, 0:disable)

/**
 * Convert GS1 DataBar to UPC/EAN
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_CONVERT_GS1_UPCEAN  0xF08D               //disable (1:enable, 0:disable)

/**
 * Composite CC-C
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_COMPOSIT_CC_C  0xF055                     //disable (1:enable, 0:disable)

/**
 * Composite CC-A/B
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_COMPOSIT_CC_AB  0xF056                  //disable (1:enable, 0:disable)

/**
 * Composite TLC-39
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_COMPOSIT_TCL39  0xF073               //disable (1:enable, 0:disable)

/**
 * UPC Composite Mode
 * default = UPC Always Linked
 * range = 0:UPC Never Linked, 1:UPC Always Linked, 2:Autodiscriminate UPC Composites
 */
#define SBParam_UPC_COMPOSIT_MODE  0xF058            //UPC Always Linked(0:UPC Never Linked, 1:UPC Always Linked, 2:Autodiscriminate UPC Composites)

//skip

/**
 * GS1-128 Emulation Mode for UCC/EAN Composite Codes
 * default = disable
 * range = 0:disable, 1:enable
 */
#define SBParam_GS1128_EMULATION_MODE  0xF0AB            //disable (1:enable, 0:disable)

/**
 * PDF417
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_PDF417  0x000F                           //enable (1:enable, 0:disable)

/**
 * MicroPDF417
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_MICRO_PDF  0x00E3                        //enable (1:enable, 0:disable)

//skip

/**
 * Data Matrix
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_DATA_MATRIX  0xF024                      //enable (1:enable, 0:disable)

/**
 * Data Matrix Inverse
 * default = Regular
 * range = 0:Regular, 1:Inverse Only, 2: Inverse Autodetect
 */
#define SBParam_DATA_MATRIX_INVERSE  0xF14C              //Regular(0:Regular, 1:Inverse Only, 2: Inverse Autodetect)

/**
 * Decode Mirror Images (Data Matrix Only)
 * default = Never
 * range = 0:Never, 1:Always, 2:Auto
 */
#define SBParam_DATA_MATRIX_DECODE_MIRROR  0xF119        //Never(0:Never, 1:Always, 2:Auto)

/**
 * Maxicode
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_MAXICODE  0xF026                         //enable (1:enable, 0:disable)

/**
 * QR Code
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_QR_CODE  0xF025                          //enable (1:enable, 0:disable)

//	 /**
//         * default = Regular
//         * range = 0:Regular, 1:Inverse Only, 2:Inverse Autodetect
//         */
//#define SBParam_QR_CODE_INVERSE  0xF14B                  //Regular (0:Regular, 1:Inverse Only, 2:Inverse Autodetect)


/**
 * MicroQR
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_MICRO_QR  0xF13D                         //enable (1:enable, 0:disable)

/**
 * Aztec
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_AZTECCODE  0xF13E                        //enable (1:enable, 0:disable)

/**
 * Aztec Inverse
 * default = Regular
 * range = 0:Regular, 1:Inverse Only, 2:Inverse Autodetect
 */
#define  SBParam_AZTECCODE_INVERSE  0xF14D                //Regular (0:Regular, 1:Inverse Only, 2:Inverse Autodetect)

/**
 * Han Xin
 * default = enable
 * range = 0:disable, 1:enable
 */
#define  SBParam_HANXIN  0xF8048F                           //enable (1:enable, 0:disable)

/**
 * Han Xin Inverse
 * default = Regular
 * range = 0:Regular, 1:Inverse Only, 2:Inverse Autodetect
 */
#define SBParam_HANXIN_INVERSE  0xF80490                   //Regular (0:Regular, 1:Inverse Only, 2:Inverse Autodetect)

/**
 * Redundancy Level
 * default = Redundancy 1
 * range = 1:Redundancy level 1, 2:Redundancy level 2, 3:Redundancy level 3, 4:Redundancy level 4
 * Level1 : Codebar(code type) =  8 characters or less(length)
 *          MSI(code type) =  4 characters or less(length)
 *          D 2 of 5(code type) =  8 characters or less(length)
 *          I 2 of 5(code type) =  8 characters or less(length)
 * Level2 :  All(code type) = All(length)
 * Level3 : MSI(code type) =  4 characters or less(length)
 *          D 2 of 5(code type) =  8 characters or less(length)
 *          I 2 of 5(code type) =  8 characters or less(length)
 *          Codebar(code type) =  8 characters or less(length)
 * Level4 :  All(code type) = All(length)
 */
#define  SBParam_REDUNDANCY_LEVEL  0x004E                 //1 (1:level 1, 2:level 2, 3:level 3, 4:level 4)
/**
 * Security Level
 * default = Security level 1
 * range = 0:Security level 0, 1:Security level 1, 2:Security level 2, 3:Security level 3
 * Security Level 0: This setting allows the decoder to operate in its most aggressive state,
 * while providing sufficient security in decoding most "in-spec" bar codes.
 * Security Level 1: This default setting eliminates most misdecodes.
 * Security Level 2: Select this option if Security level 1 fails to eliminate misdecodes.
 * Security Level 3: If you selected Security Level 2 and misdecodes still occur,
 * select this security level. Be advised, selecting this option is an extreme measure against mis-decoding severely out of spec bar codes.
 * Selecting this level of security significantly impairs the decoding ability of the decoder.
 * If you need this level of security, try to improve the quality of the bar codes.
 */
#define SBParam_SECURITY_LEVEL  0x004D                   //1 (0:Security level 0, 1:Security level 1, 2:Security level 2, 3:Security level 3)

/**
 * Intercharacter Gap Size
 * default = Normal Intercharacter Gaps
 * range = 06:Normal Intercharacter Gaps , 0A:Large Intercharacter Gaps
 */
#define SBParam_INTERCHARATER_GAP_SIZE  0xF07D           //normal 6(06:Normal Intercharacter Gaps , 0A:Large Intercharacter Gaps)

//         #define SBParam_USER_SUPPLEMENTALS_1  0xF143             //NA (BUT EF400 DISABLE)
//         #define SBParam_USER_SUPPLEMENTALS_2  0xF144             //NA (BUT EF400 DISABLE)



//////////////////////////////////////////////PARAMETER ETC DEFINE////////////////////////////////////////////////////

//        Decode Session Timeout
//        Parameter # 88h
//        This parameter sets the maximum time decode processing continues during a scan attempt. It is
//        programmable in 0.1 second increments from 0.5 to 9.9 seconds. The default timeout is 9.9 seconds.
//        To set a Decode Session Timeout, scan the bar code below. Next, scan two numeric bar codes from
//        Appendix D, Numeric Bar Codes that correspond to the desired on time. Provide a leading zero for single digit
//        numbers. For example, to set a Decode Session Timeout of 0.5 seconds, scan the bar code below, then scan
//        the 0 and 5 bar codes. To correct an error or change the selection, scan Cancel on page D-2.
/**
 * Decode Session Timeout
 * default = 30 (3 sec)
 * range = 5 ~ 99 (ex 5sec = 50(integer). 5.3sec = 53(integer)
 */
#define  SBParam_DECODE_TIMEOUT  0x0088                   //3sec (0.5 to 9.9) default 9.9

//        Parameter # 89h
//        Use this option in Presentation Mode or Continuous Bar Code Read to prevent multiple reads of a symbol
//        left in the decoder’s field of view. The timeout begins when you remove the symbol from the field of view.
//        To select the timeout between decodes for the same symbol, available in 0.1 second increments from 0.0 to
//        9.9 seconds, scan the bar code below, then scan two numeric bar codes from Appendix D, Numeric Bar Codes
//        that correspond to the desired interval. The default interval is 0.6 seconds.
/**
 * Timeout Between Decodes, Same Symbol
 * default = 6 (0.6 sec)
 * range = 0 ~ 99 (ex 5sec = 50(integer). 5.3sec = 53(integer)
 */
#define SBParam_TIMEOUT_SAME_SYMBOL  0x0089              //0.6sec (0.5 to 9.9) default 0.6


/**
 * Decode Aiming Pattern
 * default = enable
 * range = 0:disable, 2:enable
 */
#define SBParam_AIMER_MODE  0xF032                       //enable (2:enable, 0:disable)

/**
 * Decoding Illumination
 * default = enable
 * range = 0:disable, 1:enable
 */
#define SBParam_ILLUMINATION_MODE  0xF02A                //enable (1:enable, 0:disable)

/**
 * Picklist Mode
 * default = disable
 * range = 0:disable, 2:enable
 */
#define SBParam_PICKLIST_MODE  0xF092                    //disable (2:enable, 0:disable)

/**
 * BB Barcode Symbology value.
 */
#define SymbologyType_SYMBOLOGY_UNKNOWN         -1
#define SymbologyType_SYMBOLOGY_UPC_A           1
#define SymbologyType_SYMBOLOGY_UPC_E           2
#define SymbologyType_SYMBOLOGY_UPC_E1          3
#define SymbologyType_SYMBOLOGY_EAN8            4
#define SymbologyType_SYMBOLOGY_EAN13           5
#define SymbologyType_SYMBOLOGY_BOOKLAND        6
#define SymbologyType_SYMBOLOGY_CODE39          8
#define SymbologyType_SYMBOLOGY_CODE93          9
#define SymbologyType_SYMBOLOGY_CODE128         10
#define SymbologyType_SYMBOLOGY_INTERLEAVED2OF5  11
#define SymbologyType_SYMBOLOGY_CODABAR         12
#define SymbologyType_SYMBOLOGY_CODE11          13
#define SymbologyType_SYMBOLOGY_MSI             14
#define SymbologyType_SYMBOLOGY_PDF417          16
#define SymbologyType_SYMBOLOGY_ISBT128         17
#define SymbologyType_SYMBOLOGY_MATRIX2OF5      19
#define SymbologyType_SYMBOLOGY_DATAMATRIX      20
#define SymbologyType_SYMBOLOGY_MAXICODE        21
#define SymbologyType_SYMBOLOGY_AZTECCODE       22
#define SymbologyType_SYMBOLOGY_MICROPDF        23
#define SymbologyType_SYMBOLOGY_QRCODE          24
#define SymbologyType_SYMBOLOGY_TRIOPTIC_CODE   25
#define SymbologyType_SYMBOLOGY_DISCRETE2OF5    26
#define SymbologyType_SYMBOLOGY_USPS4CB         27
#define SymbologyType_SYMBOLOGY_AUSTRALIA_POST  28
#define SymbologyType_SYMBOLOGY_UK_POST         29
#define SymbologyType_SYMBOLOGY_CHINESE_POST    30
#define SymbologyType_SYMBOLOGY_JAPANESE_POST   31
#define SymbologyType_SYMBOLOGY_NETHERLANDS_POST  32
#define SymbologyType_SYMBOLOGY_KOREAN_POST     33
#define SymbologyType_SYMBOLOGY_US_POSTNET      34
#define SymbologyType_SYMBOLOGY_US_PLANET       35
#define SymbologyType_SYMBOLOGY_EAN_TRANSMIT_ISSN  43
#define SymbologyType_SYMBOLOGY_CODE39_FULL_ASCII  51
#define SymbologyType_SYMBOLOGY_GS1_LIMITED     74
#define SymbologyType_SYMBOLOGY_ISBT128_CONCATENATION  76
#define SymbologyType_SYMBOLOGY_COMPOSITE_TLC_39        85
#define SymbologyType_SYMBOLOGY_COUPON_REPORT           95
#define SymbologyType_SYMBOLOGY_GS1_DATABAR_EXPANDED    101
#define SymbologyType_SYMBOLOGY_UPU_FICS_POSTAL         104
#define SymbologyType_SYMBOLOGY_MICROQR                 113
#define SymbologyType_SYMBOLOGY_CODE49                  114
#define SymbologyType_SYMBOLOGY_OCR                     115
#define SymbologyType_SYMBOLOGY_CANADIAN_POST           116
#define SymbologyType_SYMBOLOGY_CODE32                  119
#define SymbologyType_SYMBOLOGY_CODE16K                 123
#define SymbologyType_SYMBOLOGY_HANXIN                  134
#define SymbologyType_SYMBOLOGY_IATA                    136
#define SymbologyType_SYMBOLOGY_EAN128                  137
#define SymbologyType_SYMBOLOGY_UPC_D                   138
#define SymbologyType_SYMBOLOGY_GS1_DATABAR             139
#define SymbologyType_SYMBOLOGY_SCANLET                 140
#define SymbologyType_SYMBOLOGY_CUECODE                 141
#define SymbologyType_SYMBOLOGY_SIGNATURE_CAPTURE       142
#define SymbologyType_SYMBOLOGY_FRENCH_LOT              149
#define SymbologyType_SYMBOLOGY_PARAMETER_FNC3          151
#define SymbologyType_SYMBOLOGY_MULTI_PKT_FORM          179
#define SymbologyType_SYMBOLOGY_GS1_DATAMATIRIX         182
#define SymbologyType_SYMBOLOGY_GS1_QR                  183
#define SymbologyType_SYMBOLOGY_RFID_RAW                184
#define SymbologyType_SYMBOLOGY_RFID_URI                185


/**
 * BB Sled BT callback command message values.
 */

/**
 * This callback message occur when SLED found device after scanning and always contains bundle data.
 <BR/>1) Name - Key : ConstantsBT.BT_BUNDLE_NAME_KEY, Format : String
 <BR/>2) Address - Key : ConstantsBT.BT_BUNDLE_ADDR_KEY, Format : String
 <BR/>3) Bond state - Key : ConstantsBT.BT_BUNDLE_BOND_STATE_KEY, Format : Int
 */
#define BTCmdMsg_BTCmdMsg_SLED_BT_DEVICE_FOUND  52
/**
 * This callback message occur when Pairing status change and always contains bundle data.
 <BR/>1) Name - Key : ConstantsBT.BT_BUNDLE_NAME_KEY, Format : String
 <BR/>2) Address - Key : ConstantsBT.BT_BUNDLE_ADDR_KEY, Format : String
 <BR/>3) Bond state - Key : ConstantsBT.BT_BUNDLE_BOND_STATE_KEY, Format : Int
 <BR/>4) Bond new state - Key : ConstantsBT.BT_BUNDLE_BOND_NEW_STATE_KEY, Format : Int
 <BR/>5) Bond previous state - Key : ConstantsBT.BT_BUNDLE_BOND_PREV_STATE_KEY, Format : Int
 */
#define BTCmdMsg_SLED_BT_BOND_STATE_CHAGNED  53
/**
 * This callback message occur when Receive pair request and not contains bundle data.
 */
#define BTCmdMsg_SLED_BT_PAIRING_REQUEST  54
/**
 * This callback message occur when Start the scan and not contains bundle data.
 */
#define BTCmdMsg_SLED_BT_DISCOVERY_STARTED  55
/**
 * This callback message occur when The scan complete and not contains bundle data
 */
#define BTCmdMsg_SLED_BT_DISCOVERY_FINISHED  56
/**
 * This callback message occur when Changed device's Bluetooth state and always contains bundle data.
 <BR/>1) Bond new state - Key : ConstantsBT.BT_BUNDLE_BOND_NEW_STATE_KEY, Format : Int
 <BR/>2) Bond previous state - Key : ConstantsBT.BT_BUNDLE_BOND_PREV_STATE_KEY, Format : Int
 */
#define BTCmdMsg_SLED_BT_STATE_CHANGED  57

#define BTCmdMsg_SLED_BT_CONNECTION_STATE_CHANGED  58

#define BTCmdMsg_SLED_BT_ADAPTER_CONNECTION_STATE_CHANGED  59
//        #define BTCmdMsg_SLED_BT_PAIRED_DEVICE = 59;

#define BTCmdMsg_SLED_BT_CONNECTION_ESTABLISHED  60

#define BTCmdMsg_SLED_BT_DISCONNECTED  61

#define BTCmdMsg_SLED_BT_CONNECTION_LOST  62

/**
 * This callback message occur when Changing to a connected state and always contains bundle data.
 <BR/>1) Name - Key : ConstantsBT.BT_BUNDLE_NAME_KEY, Format : String
 <BR/>2) Address - Key : ConstantsBT.BT_BUNDLE_ADDR_KEY, Format : String
 <BR/>3) Bond state - Key : ConstantsBT.BT_BUNDLE_BOND_STATE_KEY, Format : Int
 */
#define BTCmdMsg_SLED_BT_ACL_CONNECTED  63
/**
 * This callback message occur when Receive disconnect request and always contains bundle data.
 <BR/>1) Name - Key : ConstantsBT.BT_BUNDLE_NAME_KEY, Format : String
 <BR/>2) Address - Key : ConstantsBT.BT_BUNDLE_ADDR_KEY, Format : String
 <BR/>3) Bond state - Key : ConstantsBT.BT_BUNDLE_BOND_STATE_KEY, Format : Int
 */
#define BTCmdMsg_SLED_BT_ACL_DISCONNECT_REQUESTED  64
/**
 * This callback message occur when Changing to a disconnect state and always contains bundle data. Bundle data
 <BR/>1) Name - Key : ConstantsBT.BT_BUNDLE_NAME_KEY, Format : String
 <BR/>2) Address - Key : ConstantsBT.BT_BUNDLE_ADDR_KEY, Format : String
 <BR/>3) Bond state - Key : ConstantsBT.BT_BUNDLE_BOND_STATE_KEY, Format : Int
 */
#define BTCmdMsg_SLED_BT_ACL_DISCONNECTED  65

/**
 * BB Sled Get command common result values.
 */
#define BTCommonResult_ACCESS_TIMEOUT  -32
#define BTCommonResult_ALREADY_CONNECTING  -18
#define BTCommonResult_COMMUNICATION_ERROR  -16
#define BTCommonResult_BLUETOOTH_NOT_ENABLED  -15
#define BTCommonResult_CHARGING_STATE_ERROR  -14
#define BTCommonResult_FILE_IS_NOT_EXIST  -13
#define BTCommonResult_LOW_BATTERY  -12
#define BTCommonResult_ALREADY_CONNECTED  -10
#define BTCommonResult_ALREADY_DISCONNECTED  -9
#define BTCommonResult_DUP_CMD_ERROR  -8
#define BTCommonResult_READER_OR_SERIAL_STATUS_ERROR  -7
#define BTCommonResult_MODE_ERROR  -6
#define BTCommonResult_SD_NOT_CONNECTED  -5
#define BTCommonResult_OTHER_CMD_RUNNING_ERROR  -4
#define BTCommonResult_ARGUMENT_ERROR  -3
#define BTCommonResult_OTHER_ERROR  -1


/**
 * BB Sled Set command result values.
 */
#define BTResult_BTCommonResultBT_NOT_ENABLE_STATE   -40
#define BTResult_BTCommonResultSUCCESS                 0


/**
 * BB SLED BT State
 */
#define BTState_STATE_OFF               10
#define BTState_STATE_TURNING_ON        11
#define BTState_STATE_ON                12
#define BTState_STATE_TURNING_OFF       13

/**
 * BB SLED BT State
 */
#define BTBondState_BOND_NONE           10
#define BTBondState_BOND_BONDING        11
#define BTBondState_BOND_BONDED         12

/**
 * Bluetooth Connect State
 */
#define BTConnectState_BTCommonResult_NONE         0
#define BTConnectState_BTCommonResult_CONNECTING   1
#define BTConnectState_BTCommonResult_CONNECTED    2

//+ bgjun Certification

#define RFHopping_ON    1
#define RFHopping_OFF   0



#define RFHoppingChannel_MAXCHANNEL  49
#define RFHoppingChannel_MINCHANNEL  0


#define RFSimpleMode_OFF    0
#define RFSimpleMode_ON     1

//+ bgjun Certification

