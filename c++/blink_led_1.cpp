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

  if (looper % 2 == 0) {
    WiFiDrv::analogWrite(25, HIGH);
  } else {
    WiFiDrv::analogWrite(25, LOW);
  }
  if (looper % 4 < 2) {
    WiFiDrv::analogWrite(26, HIGH);
  } else {
    WiFiDrv::analogWrite(26, LOW);
  }
  if (looper % 8 < 4) {
    WiFiDrv::analogWrite(27, HIGH);
  } else {
    WiFiDrv::analogWrite(27, LOW);
  }

  delay(1000);
}