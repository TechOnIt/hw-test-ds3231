# TechOnIt Hardware Test — 🕜 DS3231
A simple hardware test project for the **DS3231 Real-Time Clock (RTC)** module using an **ESP32**.


<img width="400" height="121" alt="misc-03-003-new-4 (1)" src="https://github.com/user-attachments/assets/81d1a5f5-c22a-4c59-b09d-8a1d931be0ac" />

The project:

* Connects the ESP32 to Wi-Fi.
* Retrieves the current time from an NTP server.
* Synchronizes the DS3231 clock.
* Reads the time from the DS3231 every second.
* Prints the current date and time to Serial Monitor.

## Hardware

* ESP32 / NodeMCU ESP32
* DS3231 RTC module

## Wiring

| DS3231 | ESP32  |
| ------ | ------ |
| VCC    | 3.3V   |
| GND    | GND    |
| SDA    | GPIO 4 |
| SCL    | GPIO 5 |

## Dependencies

* Arduino Framework
* `RTClib`
* ESP32 Wi-Fi library
* ESP32 Wire (I2C)

## Configuration

Update the Wi-Fi credentials in the source code:

```cpp
const char* WIFI_SSID = "YOUR_WIFI";
const char* WIFI_PASSWORD = "YOUR_PASSWORD";
```

The current implementation uses:

```cpp
Wire.begin(4, 5);
```

So:

```text
SDA → GPIO 4
SCL → GPIO 5
```

## How It Works

```text
ESP32
  │
  ├── Connect to Wi-Fi
  │
  ├── Get current time from NTP
  │
  ├── Set DS3231 time
  │
  └── Read DS3231 every second
          │
          └── Serial Monitor
```

## Serial Output

Example:

```text
Connecting...
WiFi connected
RTC updated!

2026-10-01 21:37:01
2026-10-01 21:37:02
2026-10-01 21:37:03
```

## Purpose

This repository is part of the **TechOnIt Hardware Test** collection and is intended for validating individual hardware modules before integrating them into the TechOnIt Edge Node system.

## Related Projects

* `agent-node` — TechOnIt Edge Node firmware
* `agent-controller` — Raspberry Pi Controller
* `agent-sdk` — Shared SDK and communication contracts

## License

Part of the TechOnIt open-source ecosystem.
