package land.cookie.cordova.plugin.bluebirdreader;

import co.kr.bluebird.sled.SDConsts;

public class BluebirdMessageHandler extends Handler {
  private BluebirdReader mReader;

  BluebirdMessageHandler(BluebirdReader reader) {
    mReader = reader;
  }

  @Override
  public void handleMessage(Message msg) {
    // TODO
  }
}
