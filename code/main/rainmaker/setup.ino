void setup()
{   
  Serial.begin(115200);
  setupRainMaker();

  bool status;

  // default settings BME280
  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);  
  if (!status) { // check for available sensors
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}