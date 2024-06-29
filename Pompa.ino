void POMPA() {
  lcd.clear();
  if (kelembapan > 40) {
    lcd.print("Pompa Off");
    digitalWrite(Pompa,HIGH);
    delay(2000);
  } else {
    digitalWrite(Pompa,LOW);
    lcd.print("Pompa on");
    delay(2000);
    digitalWrite(Pompa,HIGH);
    
  }
}