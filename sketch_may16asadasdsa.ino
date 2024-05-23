//Coded By Harun Bulbul & Furkan Atılgan

//KÜTÜPHANELER
#include <Adafruit_NeoPixel.h>

// TANIMLAMALAR
#define LED_COUNT 32 // Led Sayısı
#define LED_PIN 6 // Ledlerin Takıldığı Pin
int LDRpin = A3; // LDR Sensörünün Takıldığı Pin
int pirpin = 4; // Hareket Sensörü Pini
int deger = 0; // Hareket Sensöründen gelecek analog değer

// NEOPIXEL TANIMLAMA
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//ARDUINO ÇALIŞIĞINDA OLACAKLAR
void setup() {
  pixels.begin(); // NeoPixel aktive etme
  pinMode(pirpin, INPUT); //Hareket Sensörü Aktive Etme
  Serial.begin(9600); //Arduino Aktive Etme
}

void loop() {
  deger = digitalRead(pirpin); //Hareket sensöründen gelen değer
  int isik_degeri = analogRead(LDRpin); //LDR sensöründen gelen değer
  pixels.fill(pixels.Color(255, 255, 255)); //Işıkların rengini beyaz yap
  delay(100); //1 Salise bekle
  if (isik_degeri>450) {
    if(deger == HIGH){
      pixels.setBrightness(100); //Parlaklığı Maksimum yap
    }else{
      pixels.setBrightness(20); //Parlaklığı Düşür
    }
  }
  else {
  pixels.setBrightness(0); //Işığı Kapat
  }
  pixels.show(); //Ledleri Güncelle
}
