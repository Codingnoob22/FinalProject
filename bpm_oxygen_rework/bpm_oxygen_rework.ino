#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

//-----------------------//
#include <SoftwareSerial.h>
//#include <ArduinoJson.h>
//-----------------------//

const int GSR = 1;
int sensorValue = 0;


MAX30105 particleSensor;

//-----------------------//
SoftwareSerial Oksigen(2, 3); //RX,TX
//-----------------------//


const byte RATE_SIZE = 4;
byte rates[RATE_SIZE]; 
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
float beatsPerMinute;
int beatAvg;

double avered = 0;
double aveir = 0;
double sumirrms = 0;
double sumredrms = 0;

double SpO2 = 0;
double ESpO2 = 90.0;
double FSpO2 = 0.7; //filter factor for estimated SpO2
double frate = 0.95; //low pass filter for IR/red LED value to eliminate AC component
int i = 0;
int Num = 30;



//Variable for sending the data 
String kirimdata;



#define FINGER_ON 7000 

 


void setup() {
  Serial.begin(115200);
  //----------------//
  Oksigen.begin(115200);
  //----------------//
  Serial.println("System Start");
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30102");
    while (1);
  }

  byte ledBrightness = 0x7F; 
  byte sampleAverage = 4; 
  byte ledMode = 2; 
  int sampleRate = 800; 
  int pulseWidth = 215; 
  int adcRange = 16384; 


  particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); 
  particleSensor.setPulseAmplitudeRed(0x0A); 
  particleSensor.setPulseAmplitudeGreen(0); 

}


void loop(){
  
  // put your main code here, to run repeatedly:
  //sensorValue = analogRead(GSR);
  sensorValue = random(100, 1000);
  beatAvg = random(50, 100);
  ESpO2 = random(50, 200);
  delay(100);
  /*
  long irValue = particleSensor.getIR();
  if (irValue > FINGER_ON ) {
    if (checkForBeat(irValue) == true) {
      long delta = millis() - lastBeat;
      lastBeat = millis();
      beatsPerMinute = 60 / (delta / 1000.0);
      if (beatsPerMinute < 255 && beatsPerMinute > 20) {
        rates[rateSpot++] = (byte)beatsPerMinute; 
        rateSpot %= RATE_SIZE;
        beatAvg = 0;
        for (byte x = 0 ; x < RATE_SIZE ; x++) beatAvg += rates[x];
        beatAvg /= RATE_SIZE;
      }
    }
 
    uint32_t ir, red ;
    double fred, fir;
    particleSensor.check(); 
    if (particleSensor.available()) {
      i++;
      red = particleSensor.getFIFOIR(); 
      ir = particleSensor.getFIFORed(); 
      fred = (double)red;
      fir = (double)ir;
      avered = avered * frate + (double)red * (1.0 - frate);//average red level by low pass filter
      aveir = aveir * frate + (double)ir * (1.0 - frate); //average IR level by low pass filter
      sumredrms += (fred - avered) * (fred - avered); //square sum of alternate component of red level
      sumirrms += (fir - aveir) * (fir - aveir);//square sum of alternate component of IR level
      if ((i % Num) == 0) {
        double R = (sqrt(sumredrms) / avered) / (sqrt(sumirrms) / aveir);
        SpO2 = -23.3 * (R - 0.4) + 100;
        ESpO2 = FSpO2 * ESpO2 + (1.0 - FSpO2) * SpO2;//low pass filter
      }
      particleSensor.nextSample(); 
    }
    */
    //
    
    Serial.print("Bpm: ");
    Serial.println(beatAvg);
    Serial.print("SpO2: ");
    Serial.println(ESpO2);
    Serial.print("Gsr: ");
    Serial.println(sensorValue);

       
    
    String kirimdata = ('#') + String (beatAvg) + (',') + String (ESpO2) +(',') + String (sensorValue);
    Oksigen.println(kirimdata);
    
    
    
    
  }/* else {
    for (byte rx = 0 ; rx < 4 ; rx++) rates[rx] = 0;
    beatsPerMinute = 0; rateSpot = 0; lastBeat = 0;
    avered = 0; aveir = 0; sumirrms = 0; sumredrms = 0;
    SpO2 = 0; ESpO2 = 90.0;
  }
}*/
