
void Sensorkelembapan() {
  int bacaan = analogRead(sensorLembab);
  if (bacaan >= 2646) {
    bacaan = 2646;
  }

  if (bacaan <= 1100) {
    bacaan = 1100;
  }


  kelembapan = map(bacaan, 1100, 2646, 100, 0);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Kelembapan : ");
  lcd.setCursor(12, 0);
  lcd.print(kelembapan);

  if (kelembapan >= 2646) {
    bacaan = 2646;
  }
  if (kelembapan > 40) {
    lcd.setCursor(0, 1);
    lcd.print("Basah");
  } else if (kelembapan <= 40 && kelembapan >= 12) {
    lcd.setCursor(0, 1);
    lcd.print("Normal");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("kering");
  }
  delay(3000);
}