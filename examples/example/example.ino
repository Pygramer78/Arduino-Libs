#include <Wire.h>
#include <BetterTSL2951.h>
#include <BetterAHT20.h>
#include <BetterBMP280.h>
#include <BetterMLX90615.h>

void setup() {
  MLX90615_begin();
  BMP280_init(); // Iniciar antes de configurar
  BMP280_configure(); // Config (Se cambia en el .cpp)
  AHT20_init();
  TSL2591_init();
}

void loop() {
  // Functions
  /*___/ BMP280 \____________*/
  BMP280_readTemperature();
  BMP280_readPressure();
  BMP280_readAltitude();
  /*___/ AHT20 \______________*/
  AHT20_readTemperature();
  AHT20_readHumidity();
  AHT20_read(); // Lo lee todo
  /*___/ MLX90615 \___________*/
  MLX90615_readObjectTemperature();
  MLX90615_readAmbientTemperature();
  /*___/ TSL2951 \____________*/
  TSL2591_read();
  TSL2591_displayDetails(); // Te dice detalles sobre el sensor
}
