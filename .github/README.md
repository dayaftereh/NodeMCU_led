# NodeMCU_led

Simple sketch to control with an `EPS8266` three MOSFETs over `PWM` for a LED strips, including a webbased control to picker and fading colors.

## Get Started

Before deploying the wifi configuration needs to be setup. Create a file with the name `config_wifi.ino` in the project root containg:

```cpp
#define WIFI_SSID "WIFI_NAME"
#define WIFI_PASSWD "WIFI_PASSWD"
```

## SPIFS

The next step is to upload the `index.html` to the `SPIFS` of the `EPS8266`.
For this step the Arduino Plugin [arduino-esp8266fs](https://github.com/esp8266/arduino-esp8266fs-plugin) is needed.
Follow the instruction of the plugin and upload the sketch `data` folder.
