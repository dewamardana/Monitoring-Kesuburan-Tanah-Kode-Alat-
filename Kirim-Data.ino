void kirimData() {
  int id = 1;
  int ph = 7;
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient https;
    https.begin(API_URL + "/rest/v1/" + TableName);  // Specify the URL
    https.addHeader("Content-Type", "application/json");
    https.addHeader("apikey", API_KEY);
    https.addHeader("Authorization", "Bearer " + API_KEY);

    String jsonData = "{\"id_micro\":" + String(id) + ",\"ph\":" + String(ph) + ",\"suhu\":" + String(t) + ",\"lembab\":" + String(kelembapan) + "}";
    int httpCode = https.POST(jsonData);  // Send the request
    String payload = https.getString();   // Get the response payload

    Serial.println(httpCode);  // Print HTTP return code
    Serial.println(jsonData);
    Serial.println(payload);  // Print request response payload

    https.end();  // Close connection

    if (httpCode == 201) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Data Terkirim");
    }

    id++;
    if (id > 2) {
      id = 1;
    }

  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Err WiFi connect");
    delay(3000);
  }
}