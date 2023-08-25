#include <WiFiNINA.h>
#include <utility/wifi_drv.h>

int looper = 0;

void setup() {
  WiFiDrv::pinMode(25, OUTPUT); // RED
  WiFiDrv::pinMode(26, OUTPUT); // GREEN
  WiFiDrv::pinMode(27, OUTPUT); // BLUE
}

void loop() {

  looper = looper + 1;
  looper = looper % 8;

  WiFiDrv::analogWrite(25, boolToPinState(looper % 2 == 0));
  WiFiDrv::analogWrite(26, boolToPinState(looper % 4 < 2));
  WiFiDrv::analogWrite(27, boolToPinState(looper % 8 < 4));

  delay(1000);
}

PinStatus boolToPinState(bool b) {
  if (b) {
    return HIGH;
  } else {
    return LOW;
  }
}