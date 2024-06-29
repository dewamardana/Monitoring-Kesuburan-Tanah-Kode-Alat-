// void SensorPH() {
//   int bacaan = analogRead(sensorPH);
//   if (bacaan >= 14) {
//     bacaan = 14;
//   }

//   if (bacaan <= 0) {
//     bacaan = 0;
//   }

// PH = map(bacaan, 0, 14, 14, 0);
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("PH : ");
//   lcd.setCursor(7, 0);
//   lcd.print(PH);

//   if (PH >= 14) {
//     bacaan = 14;
//   }
//   if (PH <= 6) {
//     lcd.setCursor(0, 1);
//     lcd.print("Rendah");
//   } else if (PH <= 8 && PH >= 4) {
//     lcd.setCursor(0, 1);
//     lcd.print("Baik");
//   } else {
//     lcd.setCursor(0, 1);
//     lcd.print("Tinggi");
//   }
//   delay(3000);
// }


void SensorPH() {
  lcd.clear();
  int sensorValue = 0;        //ADC value from sensor
  float outputValue = 0.0;        //pH value after conversion
  
  sensorValue = analogRead(analogInPin);
  outputValue = (-0.0693*sensorValue)+7.3855;
  lcd.setCursor(0, 0);
  lcd.print("ADC = ");
  lcd.setCursor(6, 0);
  lcd.print(sensorValue);
  lcd.setCursor(0, 1);
  lcd.print("Ph = ");
  lcd.setCursor(5, 1);
  lcd.print(outputValue);
  delay(3000);
}

