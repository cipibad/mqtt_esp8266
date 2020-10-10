#ifndef APP_MAIN_H
#define APP_MAIN_H

#if CONFIG_ESPTOOLPY_FLASHSIZE_1MB
#if CONFIG_MQTT_THERMOSTATS_NB > 0 //this is my brother's configuration, where esp8266 controls external module of 4 relays
#define RELAY_ON 0
#define RELAY_OFF 1
#else //CONFIG_MQTT_THERMOSTAT
#define RELAY_ON 1
#define RELAY_OFF 0
#endif //CONFIG_MQTT_THERMOSTAT

#else //CONFIG_ESPTOOLPY_FLASHSIZE_1MB
#define RELAY_ON 0
#define RELAY_OFF 1
#endif//CONFIG_ESPTOOLPY_FLASHSIZE_1MB

#define LED_ON 0
#define LED_OFF 1

#endif /* APP_MAIN_H */
