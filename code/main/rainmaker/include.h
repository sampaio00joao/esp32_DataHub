// ESP RainMaker includes
#include "RMaker.h"
#include "WiFi.h"
#include "WiFiProv.h"
#include "AppInsights.h"
// ESP BME280 includes
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

#define DEFAULT_POWER_MODE true
const char *service_name    = "PROV_1234";
const char *pop             = "abcd1234";

static uint8_t bme280_SDA      = 21; //apagar
float bmeTemperatureRead       = 0;
float bmeHumidityRead          = 0;
float bmeAltitudeRead          = 0;
float bmePressureRead          = 0;             
static TemperatureSensor temperature("Temperature");
static TemperatureSensor humidity("Humidity");
static TemperatureSensor altitude("Altitude");
static TemperatureSensor pressure("Pressure");
