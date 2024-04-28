void printValuesBME280() {

  bmeTemperatureRead  = bme.readTemperature();
  if(bmeTemperatureRead != NULL){
    temperature.updateAndReportParam("Temperature", bmeTemperatureRead);
  }


  bmeHumidityRead = bme.readHumidity();
  if(bmeHumidityRead != NULL)
  {
    float roundedHumidity = round(bmeHumidityRead * 100.0) / 100.0;
    humidity.updateAndReportParam("Temperature", roundedHumidity);
  }

  bmePressureRead = bme.readPressure() / 100.0F;
  if(bmePressureRead != NULL)
  {
    float roundedPressure = round(bmePressureRead * 100000.0) / 100000.0;
    pressure.updateAndReportParam("Temperature",  roundedPressure);
  }
  
  bmeAltitudeRead = bme.readAltitude(SEALEVELPRESSURE_HPA);
  if(bmeAltitudeRead != NULL)
  {
    float roundedAltitude = round(bmeAltitudeRead * 100.0) / 100.0;
    altitude.updateAndReportParam("Temperature", roundedAltitude);
  }

}