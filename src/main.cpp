#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup()
{
    Serial.begin(9200);
    Wire.begin(4, 5);

    rtc.begin();
}

void loop()
{
    DateTime now = rtc.now();

    Serial.printf(
        "%04d-%02d-%02d %02d:%02d:%02d\n",
        now.year(),
        now.month(),
        now.day(),
        now.hour(),
        now.minute(),
        now.second()
    );

    delay(1000);
}