// void SensorDHT(){
//   int bacaan = analogRead(sensorSuhu);
//   if (bacaan >= 125) {
//     bacaan = 125;
//   }
//   if (bacaan <= -40) {
//     bacaan = -40;
// }


// suhu = map(bacaan, -40, 125, 40, 0);
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Suhu : ");
//   lcd.setCursor(7, 0);
//   lcd.print(suhu);

//  if (suhu >= 125) {
//     bacaan = 125;
//   }
//   if (suhu <= 23) {
//     lcd.setCursor(0, 1);
//     lcd.print("Dingin");
//   } else if (suhu <= 35 && suhu >= 23) {
//     lcd.setCursor(0, 1);
//     lcd.print("Normal");
//   } else {
//     lcd.setCursor(0, 1);
//     lcd.print("panas");
//   }
//   delay(3000);
// }


void SensorDHT() {
  lcd.clear();
  h = dht.readHumidity();
  t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Failed to read");
    lcd.setCursor(0, 1);
    lcd.print("From DHT Sensor!");
  }
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.setCursor(6, 0);
  lcd.print(t);
  lcd.setCursor(9, 0);
  lcd.print((char)223);  // degree symbol
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.setCursor(5, 1);
  lcd.print(h);
  lcd.setCursor(8, 1);
  lcd.print("%");
  delay(3000);
}