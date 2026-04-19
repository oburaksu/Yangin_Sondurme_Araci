// Projemizde Kullandığımız Arduino Kodları
/*
   YANGIN SÖNDÜREN ROBOT - NodeMCU ESP8266
   Pin Bağlantıları:
   Sol Motor: D1, D2 (Hız: D5)
   Sağ Motor: D3, D4 (Hız: D6)
   Su Pompası: D7
*/
// --- BLYNK AYARLARI (Blynk Konsolundan aldığınız bilgileri buraya yapıştırın) ---
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME "YanginRobotu"
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// --- WIFI AYARLARI ---
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";       // Buraya WiFi adınızı yazın
char pass[] = "";     // Buraya WiFi şifrenizi yazın
// --- PIN TANIMLAMALARI ---
#define ENA D5
#define IN1 D1
#define IN2 D2
#define ENB D6
#define IN3 D3
#define IN4 D4
#define POMPA D7
int motorHizi = 900; 
void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(POMPA, INPUT); 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  Blynk.begin(auth, ssid, pass);
}
void loop() {
  Blynk.run();
}
// --- HAREKET FONKSİYONLARI ---
void ileri() {
  analogWrite(ENA, motorHizi);
  analogWrite(ENB, motorHizi);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void geri() {
  analogWrite(ENA, motorHizi);
  analogWrite(ENB, motorHizi);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void sag() {
  analogWrite(ENA, motorHizi);
  analogWrite(ENB, motorHizi);
  digitalWrite(IN1, HIGH); // Sol ileri
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  // Sağ geri
  digitalWrite(IN4, HIGH);
}
void sol() {
  analogWrite(ENA, motorHizi);
  analogWrite(ENB, motorHizi);
  digitalWrite(IN1, LOW);  // Sol geri
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); // Sağ ileri
  digitalWrite(IN4, LOW);
}
void dur() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
BLYNK_WRITE(V1) {
  int butonDurumu = param.asInt();
  if (butonDurumu == 1) ileri(); else dur();
}
BLYNK_WRITE(V2) {
  int butonDurumu = param.asInt();
  if (butonDurumu == 1) geri(); else dur();
}
BLYNK_WRITE(V3) {
  int butonDurumu = param.asInt();
  if (butonDurumu == 1) sag(); else dur();
}
BLYNK_WRITE(V4) {
  int butonDurumu = param.asInt();
  if (butonDurumu == 1) sol(); else dur();
}
BLYNK_WRITE(V5) {
  int butonDurumu = param.asInt();
  
  if (butonDurumu == 1) {
    pinMode(POMPA, OUTPUT);
    digitalWrite(POMPA, LOW); 
  } else {
    pinMode(POMPA, INPUT);
  }
}
