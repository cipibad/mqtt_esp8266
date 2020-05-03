#ifndef APP_THERMOSTAT_H
#define APP_THERMOSTAT_H

#include "freertos/FreeRTOS.h"

#define BIT_THERMOSTAT 1
#define BIT_HEAT (1 << 1)

enum ThermostatType {
  THERMOSTAT_TYPE_NORMAL = 1,
  THERMOSTAT_TYPE_CIRCUIT,
};


enum ThermostatMode {
  THERMOSTAT_MODE_UNSET = 0, //0
  THERMOSTAT_MODE_OFF = BIT_THERMOSTAT, //1
  THERMOSTAT_MODE_HEAT = BIT_THERMOSTAT | BIT_HEAT, //3
};

enum ThermostatState {
  THERMOSTAT_STATE_IDLE = 1,
  THERMOSTAT_STATE_HEATING = 3,
};

enum HeatingState {
  HEATING_STATE_IDLE = 1,
  HEATING_STATE_ENABLED = 3,
};

union ThermostatData {
  enum ThermostatMode thermostatMode;
  int targetTemperature;
  int tolerance;
  short currentTemperature;
};

#define THERMOSTAT_SENSORS_MSG 2
#define THERMOSTAT_ROOM_0_MSG 3
#define THERMOSTAT_LIFE_TICK 4


//new modes
//FIXME: translate this to enum values
#define THERMOSTAT_CMD_MODE 6
#define THERMOSTAT_CMD_TARGET_TEMPERATURE 8
#define THERMOSTAT_CMD_TOLERANCE 10
#define THERMOSTAT_CURRENT_TEMPERATURE 14

struct ThermostatMessage {
  unsigned char msgType;
  unsigned char thermostatId;
  union ThermostatData data;
};

void publish_thermostat_data();

esp_err_t read_thermostat_nvs(const char * tag, int * value);

void handle_thermostat_cmd_task(void* pvParameters);
void read_nvs_thermostat_data(void);

#define SENSOR_LIFETIME 10

#endif /* APP_THERMOSTAT_H */
