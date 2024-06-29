#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <DHT.h>
#include <ArduinoJson.h>


#define sensorLembab 34
#define DHTPIN 2       // DHT PIN 2
#define DHTTYPE DHT22  // DHT 22  (AM2302), AM2321
#define Pompa 5
#define analogInPin 4

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Replace with your network credentials
const char* ssid = "Kelompok1A";
const char* password = "12345678";

// Supabase credentials
String API_URL = "https://jchndtdkbmzgppgxpfio.supabase.co";
String API_KEY = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImpjaG5kdGRrYm16Z3BwZ3hwZmlvIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MTY4NzQ3MDQsImV4cCI6MjAzMjQ1MDcwNH0.WsZKLhMuQNy6ghqX_-kJdAmMobzAmb1wDO4POjNsFOI";
String TableName = "data";
Srtring ML = "Hasil"
const int httpsPort = 5432;

const char* supabase_url = "https://jchndtdkbmzgppgxpfio.supabase.co/rest/v1/Hasil?select=keterangan&order=id.desc&limit=1";
const char* supabase_key = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImpjaG5kdGRrYm16Z3BwZ3hwZmlvIiwicm9sZSI6ImFub24iLCJpYXQiOjE3MTY4NzQ3MDQsImV4cCI6MjAzMjQ1MDcwNH0.WsZKLhMuQNy6ghqX_-kJdAmMobzAmb1wDO4POjNsFOI";

int t, h;
int value, THRESHOLD = 0;  // cari nilai THRESHOLD untuk nilai kering dan basah
int kelembapan;


void setup() {
  lcd.init();  // initialize the lcd
  lcd.backlight();

  Serial.begin(9600);

  WiFi.begin(ssid, password);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connecting");
  delay(2000);
  lcd.setCursor(10, 0);
  int c = 10;
  while (WiFi.status() != WL_CONNECTED) {
    lcd.setCursor(c, 0);
    lcd.print(".");
    c++;
    delay(500);
    if (c == 15) {
      c = 10;
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CONNECTED :)");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IP : ");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
  delay(5000);

  pinMode(sensorLembab, INPUT);
  pinMode(Pompa, OUTPUT);
  digitalWrite(Pompa, HIGH);

  dht.begin();
}

void loop() {
  SensorDHT();
  SensorPH();
  Sensorkelembapan();
  POMPA();
  delay(1000);
  kirimData();
  delay(1000);
  ambilData();
  delay(3000);
}