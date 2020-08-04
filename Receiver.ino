#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

#define relay1 7;
RH_ASK driver;

void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  //digitalWrite(relay1,LOW);
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    //Serial.print("DEVICE is Ready \n");
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("got it: ");
      Serial.println((char*)buf);     
      //digitalWrite(relay1,HIGH);
          
    }
}
