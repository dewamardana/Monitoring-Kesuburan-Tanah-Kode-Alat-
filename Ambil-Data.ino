// void getDataFromSupabase() {
//   int keterangan = 2;

//   if (WiFi.status() == WL_CONNECTED) {
//     HTTPClient http;
//     http.begin(supabase_url);
//     http.addHeader("apikey", supabase_key);
//     http.addHeader("Content-Type", "application/json");

//     int httpResponseCode = http.GET();

//     if (httpResponseCode > 0) {
//       String payload = http.getString();
//       Serial.println(httpResponseCode);
//       Serial.println(payload);

//       // Parsing JSON
//       DynamicJsonDocument doc(1024);
//       DeserializationError error = deserializeJson(doc, payload);
//       if (error) {
//         Serial.print("JSON Parsing Error: ");
//         Serial.println(error.c_str());
//         return;
//       }

//       // Ambil nilai keterangan
//       if (!doc.is<JsonArray>()) {
//         lcd.clear();
//         lcd.setCursor(0, 0);
//         lcd.print("Data Diambil");
//         return;
//       }

//       JsonArray array = doc.as<JsonArray>();
//       if (array.size() == 0) {
//         lcd.clear();
//         lcd.setCursor(0, 0);
//         lcd.print("Data Kosong");
//         keterangan = 2;
//         return;
//       }

//       if (keterangan != 2) {
//         keterangan = array[0]["keterangan"];
//       }else{
//         keterangan = 2;
//       }
       
//       lcd.clear();
//       // Tentukan apakah menyiram atau tidak
//       if (keterangan == 1) {
//         digitalWrite(Pompa, LOW);  // Menyiram
//         lcd.setCursor(0, 0);
//         lcd.print("Menyiram Tanaman");
//         delay(2000);
//         lcd.clear();
//       }
//       if (keterangan == 0) {
//         digitalWrite(Pompa, HIGH);  // Tidak menyiram
//         lcd.setCursor(0, 0);
//         lcd.print("Tidak Menyiram");
//       }

//       if (keterangan == 2) {
//         lcd.setCursor(0, 1);
//         lcd.print("Tidak Ada");
//         lcd.setCursor(0, 0);
//         lcd.print("Data");
//       }
      


//     } else {
//       lcd.clear();
//       lcd.setCursor(1, 0);
//       lcd.print("Data Tidak");
//       lcd.setCursor(4, 1);
//       lcd.print("Terkirim");
//     }

//     http.end();
//   } else {
//     lcd.clear();
//     lcd.setCursor(0, 0);
//     lcd.print("Wifi Disconnect");
//   }
// }
void ambilData() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient https;
    String url = API_URL + "/rest/v1/" + ML + "?select=id,keterangan";
    https.begin(url);  // Specify the URL
    https.addHeader("Content-Type", "application/json");
    https.addHeader("apikey", API_KEY);
    https.addHeader("Authorization", "Bearer " + API_KEY);

    int httpCode = https.GET();  // Send the request

    if (httpCode > 0) {  // Check for the returning code
      String payload = https.getString();  // Get the response payload
      Serial.println(httpCode);  // Print HTTP return code
      Serial.println(payload);  // Print response payload

      // Parse the JSON payload
      StaticJsonDocument<1024> doc;
      DeserializationError error = deserializeJson(doc, payload);

      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
      }

      // Iterate through the JSON array
      for (JsonObject data : doc.as<JsonArray>()) {
        int id = data["id"];
        int keterangan = data["keterangan"];

        // Print the values
        Serial.print("id: ");
        Serial.println(id);
        Serial.print("Keterangan: ");
        Serial.println(keterangan);
      }
    } else {
      Serial.println("Error on HTTP request");
    }

    https.end();  // Close connection
  } else {
    Serial.println("Tidak terhubung ke WiFi");
  }
}
