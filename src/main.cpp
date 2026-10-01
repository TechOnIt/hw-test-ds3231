#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <RTClib.h>

const char* WIFI_SSID = "YOUR_WIFI";
const char* WIFI_PASSWORD = "YOUR_PASSWORD";

RTC_DS3231 rtc;

void setup()
{
    Serial.begin(9200);

    Wire.begin(4, 5);
    rtc.begin();

    // Connect WiFi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi connected");

    // Get time from NTP
    configTime(0, 0, "pool.ntp.org", "time.nist.gov");

    struct tm timeinfo;

    if (getLocalTime(&timeinfo))
    {
        // Iran timezone: UTC+3:30 / +4:30 DST historically
        setenv("TZ", "IRST-3:30", 1);
        tzset();

        getLocalTime(&timeinfo);

        rtc.adjust(DateTime(
            timeinfo.tm_year + 1900,
            timeinfo.tm_mon + 1,
            timeinfo.tm_mday,
            timeinfo.tm_hour,
            timeinfo.tm_min,
            timeinfo.tm_sec
        ));

        Serial.println("RTC updated!");
    }
    else
    {
        Serial.println("Failed to get time");
    }
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