void sensor_sampling(){
  if (taree == 0){
  moisture = float(millis()%1000)/10;
  density = float(millis()%1033)/10;
  temperature = float(millis()%1234)/10;
  }
  else {
    moisture = 0;
    density = 0;
    temperature = 0;
  }
}
