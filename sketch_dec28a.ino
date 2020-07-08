#define MAX_HDLC_FRAME_LENGTH 32
#define MAX_HDLC_FRAME_LENGTH 32


#include "Arduhdlc.h"
#include "Koyn.h"

BitcoinAddress myAddress("muutGNozJxnA3z4nMrcKvZvSnz8WHFWNb2", ADDRESS_ENCODED);

Arduhdlc hdlc(&byteSender, &frameCallback, MAX_HDLC_FRAME_LENGTH);

void byteSender(uint8_t data) {
  Serial.write(data);
}

void frameCallback(const uint8_t *data, uint16_t length) {

}

void setup() {
  Serial.begin(115200);
  // CONNECT TO WIFI
  wifiConnect();
  Koyn.begin();
  Koyn.onNewTransaction(&paymentCallback);
  //  Koyn.onNewBlockHeader(&blockCallback);
}

void loop() {
  if (Koyn.isSynced()) {
    Koyn.trackAddress(&myAddress);
  }
  Koyn.run();
}

void paymentCallback(BitcoinTransaction tx) {
  Serial.println("Got Transaction");
  for (int j = 0; j < tx.getOutputsCount(); j++)
  {
    BitcoinAddress to;
    tx.getOutput(j, &to);
    if (to == myAddress) {
      Serial.println("My Address");
      uint64_t amount = tx.getOutputAmount(j);
      hdlc.frameDecode((uint8_t *)&amount,8);
      break;
    }
  }
}

void wifiConnect()
{
  WiFi.begin("SSID_NAME", "SSID_PASSWORD");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

#include "Arduhdlc.h"
#include "Koyn.h"

BitcoinAddress myAddress("muutGNozJxnA3z4nMrcKvZvSnz8WHFWNb2", ADDRESS_ENCODED);

Arduhdlc hdlc(&byteSender, &frameCallback, MAX_HDLC_FRAME_LENGTH);

void byteSender(uint8_t data) {
  Serial.write(data);
}

void FrameCallback(const uint8_t *data, uint16_t length) {

}

void setup() {
  Serial.begin(115200);
  // CONNECT TO WIFI
  wifiConnect();
  Koyn.begin();
  Koyn.onNewTransaction(&paymentCallback);
  //  Koyn.onNewBlockHeader(&blockCallback);
}

void loop() {
  if (Koyn.isSynced()) {
    Koyn.trackAddress(&myAddress);
  }
  Koyn.run();
}

void paymentCallback(BitcoinTransaction tx) {
  Serial.println("Got Transaction");
  for (int j = 0; j < tx.getOutputsCount(); j++)
  {
    BitcoinAddress to;
    tx.getOutput(j, &to);
    if (to == myAddress) {
      Serial.println("My Address");
      uint64_t amount = tx.getOutputAmount(j);
      hdlc.frameDecode((uint8_t *)&amount,8);
      break;
    }
  }
}

void wifiConnect()
{
  WiFi.begin("SSID_NAME", "SSID_PASSWORD");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}
