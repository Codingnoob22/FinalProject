//----------------------------------------//
#include <Wire.h>
#include <WiFi.h>
#include "HTTPClient.h"
//----------------------------------------//

//----------Arduino Communication---------//
#include <SoftwareSerial.h>

SoftwareSerial Oksigen(35, 34); //RX, TX
//----------------------------------------//


//----------------------------------------//
String dataIn;
String dt[10];
int i;
boolean parsing=false;
//----------------------------------------//


//------------WIFI Configuration---------//
const char *ssid = "G22";
const char *password = "DragonflyHigh";
const char *host ="192.168.110.123";
HTTPClient http;
//----------------------------------------//


//---------------SET NILAI FUZZY------------------//
#include <Fuzzy.h>
Fuzzy *fuzzy = new Fuzzy();

//Fuzzy INPUT
FuzzySet *relax1      =new FuzzySet(0, 0, 70, 75);
FuzzySet *calm1       =new FuzzySet(70, 75, 80, 85);
FuzzySet *anxiety1    =new FuzzySet(80, 85, 90, 95);
FuzzySet *stress1     =new FuzzySet(90, 95, 140, 140);

//spo2
FuzzySet *relax2       =new FuzzySet(120, 120, 100, 95);
FuzzySet *calm2        =new FuzzySet(100, 95, 90, 85);
FuzzySet *anxiety2     =new FuzzySet(90, 85, 80, 75);
FuzzySet *stress2      =new FuzzySet(80, 75, 0, 0);
 

FuzzySet *relax3      =new FuzzySet(0, 0, 200, 300);
FuzzySet *calm3       =new FuzzySet(200, 300, 400, 500);
FuzzySet *anxiety3    =new FuzzySet(400, 500, 600, 700);
FuzzySet *stress3     =new FuzzySet(600, 700, 100, 1000);

//Fuzzy OUTPUT
FuzzySet *r  =new FuzzySet(0, 0, 0.10, 0.25);
FuzzySet *c  =new FuzzySet(0.10, 0.25, 0.4, 0.55);
FuzzySet *a  =new FuzzySet(0.4, 0.55, 0.70, 0.85);
FuzzySet *s  =new FuzzySet(0.70, 0.85, 1, 1);


void fuzzySet(){  
  //------------------FUZZY INPUT & OUT PUT----------------------//
  FuzzyInput *heartrate =new FuzzyInput(1);
  heartrate->addFuzzySet(relax1);
  heartrate->addFuzzySet(calm1);
  heartrate->addFuzzySet(anxiety1);
  heartrate->addFuzzySet(stress1);
  fuzzy->addFuzzyInput(heartrate);


  //FUZZY INPUT SPO2
  FuzzyInput *oksigen =new FuzzyInput(2);
  oksigen->addFuzzySet(relax2);
  oksigen->addFuzzySet(calm2);
  oksigen->addFuzzySet(anxiety2);
  oksigen->addFuzzySet(stress2);
  fuzzy->addFuzzyInput(oksigen);

  
  //FUZZY INPUT GSR
  FuzzyInput *gsr =new FuzzyInput(3);
  gsr->addFuzzySet(relax3);
  gsr->addFuzzySet(calm3);
  gsr->addFuzzySet(anxiety3);
  gsr->addFuzzySet(stress3);
  fuzzy->addFuzzyInput(gsr);

  //FUZZY OUTPUT
  FuzzyOutput *klasifikasi =new FuzzyOutput(1);
  klasifikasi->addFuzzySet(r);
  klasifikasi->addFuzzySet(c);
  klasifikasi->addFuzzySet(a);
  klasifikasi->addFuzzySet(s);
  fuzzy->addFuzzyOutput(klasifikasi);
  
  //----------------------FUZZY RULES----------------------//
  
  //rule1
  FuzzyRuleAntecedent *relax1_stress2_1 = new FuzzyRuleAntecedent();
  relax1_stress2_1 ->joinWithAND(relax1, stress2);

  FuzzyRuleAntecedent *relax3_1 = new FuzzyRuleAntecedent();
  relax3_1->joinSingle(relax3);

  FuzzyRuleAntecedent *relax1_stress2_1_relax3_1_1 = new FuzzyRuleAntecedent();
  relax1_stress2_1_relax3_1_1->joinWithAND(relax1_stress2_1, relax3_1);

  FuzzyRuleConsequent *a_1 = new FuzzyRuleConsequent();
  a_1->addOutput(a);

  FuzzyRule *fuzzyRule1 = new FuzzyRule(1, relax1_stress2_1_relax3_1_1, a_1);
  fuzzy->addFuzzyRule(fuzzyRule1);

  //rule1
  FuzzyRuleAntecedent *relax1_stress2_2 = new FuzzyRuleAntecedent();
  relax1_stress2_2 ->joinWithAND(relax1, stress2);

  FuzzyRuleAntecedent *calm3_2 = new FuzzyRuleAntecedent();
  calm3_2->joinSingle(calm3);

  FuzzyRuleAntecedent *relax1_stress2_2_calm3_2_2 = new FuzzyRuleAntecedent();
  relax1_stress2_2_calm3_2_2->joinWithAND(relax1_stress2_2, calm3_2);

  FuzzyRuleConsequent *a_2 = new FuzzyRuleConsequent();
  a_2->addOutput(a);

  FuzzyRule *fuzzyRule2 = new FuzzyRule(2, relax1_stress2_2_calm3_2_2, a_2);
  fuzzy->addFuzzyRule(fuzzyRule2);

  //rule3
  FuzzyRuleAntecedent *relax1_stress2_3 = new FuzzyRuleAntecedent();
  relax1_stress2_3 ->joinWithAND(relax1, stress2);

  FuzzyRuleAntecedent *anxiety3_3 = new FuzzyRuleAntecedent();
  anxiety3_3->joinSingle(anxiety3);

  FuzzyRuleAntecedent *relax1_stress2_3_anxiety3_3_3 = new FuzzyRuleAntecedent();
  relax1_stress2_3_anxiety3_3_3->joinWithAND(relax1_stress2_3, anxiety3_3);

  FuzzyRuleConsequent *s_3 = new FuzzyRuleConsequent();
  s_3->addOutput(s);

  FuzzyRule *fuzzyRule3 = new FuzzyRule(3, relax1_stress2_3_anxiety3_3_3, s_3);
  fuzzy->addFuzzyRule(fuzzyRule3);

  //rule4
  FuzzyRuleAntecedent *relax1_stress2_4 = new FuzzyRuleAntecedent();
  relax1_stress2_4 ->joinWithAND(relax1, stress2);

  FuzzyRuleAntecedent *stress3_4 = new FuzzyRuleAntecedent();
  stress3_4->joinSingle(stress3);

  FuzzyRuleAntecedent *relax1_stress2_4_stress3_4_4 = new FuzzyRuleAntecedent();
  relax1_stress2_4_stress3_4_4->joinWithAND(relax1_stress2_4, stress3_4);

  FuzzyRuleConsequent *s_4 = new FuzzyRuleConsequent();
  s_4->addOutput(s);

  FuzzyRule *fuzzyRule4 = new FuzzyRule(4, relax1_stress2_4_stress3_4_4, s_4);
  fuzzy->addFuzzyRule(fuzzyRule4);

  //rule5
  FuzzyRuleAntecedent *relax1_anxiety2_5 = new FuzzyRuleAntecedent();
  relax1_anxiety2_5 ->joinWithAND(relax1, anxiety2);

  FuzzyRuleAntecedent *relax3_5 = new FuzzyRuleAntecedent();
  relax3_5->joinSingle(relax3);

  FuzzyRuleAntecedent *relax1_anxiety2_5_relax3_5_5 = new FuzzyRuleAntecedent();
  relax1_anxiety2_5_relax3_5_5->joinWithAND(relax1_anxiety2_5, relax3_5);

  FuzzyRuleConsequent *c_5 = new FuzzyRuleConsequent();
  c_5->addOutput(c);

  FuzzyRule *fuzzyRule5 = new FuzzyRule(5, relax1_anxiety2_5_relax3_5_5, c_5);
  fuzzy->addFuzzyRule(fuzzyRule5);

  //rule6
  FuzzyRuleAntecedent *relax1_anxiety2_6 = new FuzzyRuleAntecedent();
  relax1_anxiety2_6 ->joinWithAND(relax1, anxiety2);

  FuzzyRuleAntecedent *calm3_6 = new FuzzyRuleAntecedent();
  calm3_6->joinSingle(calm3);

  FuzzyRuleAntecedent *relax1_anxiety2_6_calm3_6_6 = new FuzzyRuleAntecedent();
  relax1_anxiety2_6_calm3_6_6->joinWithAND(relax1_anxiety2_6, calm3_6);

  FuzzyRuleConsequent *c_6 = new FuzzyRuleConsequent();
  c_6->addOutput(c);

  FuzzyRule *fuzzyRule6 = new FuzzyRule(6, relax1_anxiety2_6_calm3_6_6, c_6);
  fuzzy->addFuzzyRule(fuzzyRule6);
  
  //rule7
  FuzzyRuleAntecedent *relax1_anxiety2_7 = new FuzzyRuleAntecedent();
  relax1_anxiety2_7 ->joinWithAND(relax1, anxiety2);

  FuzzyRuleAntecedent *anxiety3_7 = new FuzzyRuleAntecedent();
  anxiety3_7->joinSingle(anxiety3);

  FuzzyRuleAntecedent *relax1_anxiety2_7_anxiety3_7_7 = new FuzzyRuleAntecedent();
  relax1_anxiety2_7_anxiety3_7_7->joinWithAND(relax1_anxiety2_7, anxiety3_7);

  FuzzyRuleConsequent *a_7 = new FuzzyRuleConsequent();
  a_7->addOutput(a);

  FuzzyRule *fuzzyRule7 = new FuzzyRule(7, relax1_anxiety2_7_anxiety3_7_7, a_7);
  fuzzy->addFuzzyRule(fuzzyRule7);
  
  //rule8
  FuzzyRuleAntecedent *relax1_anxiety2_8 = new FuzzyRuleAntecedent();
  relax1_anxiety2_8 ->joinWithAND(relax1, anxiety2);

  FuzzyRuleAntecedent *stress3_8 = new FuzzyRuleAntecedent();
  stress3_8->joinSingle(stress3);

  FuzzyRuleAntecedent *relax1_anxiety2_8_stress3_8_8 = new FuzzyRuleAntecedent();
  relax1_anxiety2_8_stress3_8_8->joinWithAND(relax1_anxiety2_8, stress3_8);

  FuzzyRuleConsequent *s_8 = new FuzzyRuleConsequent();
  s_8->addOutput(s);

  FuzzyRule *fuzzyRule8 = new FuzzyRule(8, relax1_anxiety2_8_stress3_8_8, s_8);
  fuzzy->addFuzzyRule(fuzzyRule8);
 
  //rule9
  FuzzyRuleAntecedent *relax1_calm2_9 = new FuzzyRuleAntecedent();
  relax1_calm2_9 ->joinWithAND(relax1, calm2);

  FuzzyRuleAntecedent *relax3_9 = new FuzzyRuleAntecedent();
  relax3_9->joinSingle(relax3);

  FuzzyRuleAntecedent *relax1_calm2_9_relax3_9_9 = new FuzzyRuleAntecedent();
  relax1_calm2_9_relax3_9_9->joinWithAND(relax1_calm2_9, relax3_9);

  FuzzyRuleConsequent *r_9 = new FuzzyRuleConsequent();
  r_9->addOutput(r);

  FuzzyRule *fuzzyRule9 = new FuzzyRule(9, relax1_calm2_9_relax3_9_9, r_9);
  fuzzy->addFuzzyRule(fuzzyRule9);
 
  //rule10
  FuzzyRuleAntecedent *relax1_calm2_10 = new FuzzyRuleAntecedent();
  relax1_calm2_10 ->joinWithAND(relax1, calm2);

  FuzzyRuleAntecedent *calm3_10 = new FuzzyRuleAntecedent();
  calm3_10->joinSingle(calm3);

  FuzzyRuleAntecedent *relax1_calm2_10_calm3_10_10 = new FuzzyRuleAntecedent();
  relax1_calm2_10_calm3_10_10->joinWithAND(relax1_calm2_10, calm3_10);

  FuzzyRuleConsequent *c_10 = new FuzzyRuleConsequent();
  c_10->addOutput(c);

  FuzzyRule *fuzzyRule10 = new FuzzyRule(10, relax1_calm2_10_calm3_10_10, c_10);
  fuzzy->addFuzzyRule(fuzzyRule10); 

  //rule11
  FuzzyRuleAntecedent *relax1_calm2_11 = new FuzzyRuleAntecedent();
  relax1_calm2_11 ->joinWithAND(relax1, calm2);

  FuzzyRuleAntecedent *anxiety3_11 = new FuzzyRuleAntecedent();
  anxiety3_11->joinSingle(anxiety3);

  FuzzyRuleAntecedent *relax1_calm2_11_anxiety3_11_11 = new FuzzyRuleAntecedent();
  relax1_calm2_11_anxiety3_11_11->joinWithAND(relax1_calm2_11, anxiety3_11);

  FuzzyRuleConsequent *c_11 = new FuzzyRuleConsequent();
  c_11->addOutput(c);

  FuzzyRule *fuzzyRule11 = new FuzzyRule(11, relax1_calm2_11_anxiety3_11_11, c_11);
  fuzzy->addFuzzyRule(fuzzyRule11);

  //rule12
  FuzzyRuleAntecedent *relax1_calm2_12 = new FuzzyRuleAntecedent();
  relax1_calm2_12 ->joinWithAND(relax1, calm2);

  FuzzyRuleAntecedent *stress3_12 = new FuzzyRuleAntecedent();
  stress3_12->joinSingle(stress3);

  FuzzyRuleAntecedent *relax1_calm2_12_stress3_12_12 = new FuzzyRuleAntecedent();
  relax1_calm2_12_stress3_12_12->joinWithAND(relax1_calm2_12, stress3_12);

  FuzzyRuleConsequent *a_12 = new FuzzyRuleConsequent();
  a_12->addOutput(a);

  FuzzyRule *fuzzyRule12 = new FuzzyRule(12, relax1_calm2_12_stress3_12_12, a_12);
  fuzzy->addFuzzyRule(fuzzyRule12);

  //rule13
  FuzzyRuleAntecedent *relax1_relax2_13 = new FuzzyRuleAntecedent();
  relax1_relax2_13 ->joinWithAND(relax1, relax2);

  FuzzyRuleAntecedent *relax3_13 = new FuzzyRuleAntecedent();
  relax3_13->joinSingle(relax3);

  FuzzyRuleAntecedent *relax1_relax2_13_relax3_13_13 = new FuzzyRuleAntecedent();
  relax1_relax2_13_relax3_13_13->joinWithAND(relax1_relax2_13, relax3_13);

  FuzzyRuleConsequent *r_13 = new FuzzyRuleConsequent();
  r_13->addOutput(r);

  FuzzyRule *fuzzyRule13 = new FuzzyRule(13, relax1_relax2_13_relax3_13_13, r_13);
  fuzzy->addFuzzyRule(fuzzyRule13);

  //rule14
  FuzzyRuleAntecedent *relax1_relax2_14 = new FuzzyRuleAntecedent();
  relax1_relax2_14 ->joinWithAND(relax1, relax2);

  FuzzyRuleAntecedent *calm3_14 = new FuzzyRuleAntecedent();
  calm3_14->joinSingle(calm3);

  FuzzyRuleAntecedent *relax1_relax2_14_calm3_14_14 = new FuzzyRuleAntecedent();
  relax1_relax2_14_calm3_14_14->joinWithAND(relax1_relax2_14, calm3_14);

  FuzzyRuleConsequent *r_14 = new FuzzyRuleConsequent();
  r_14->addOutput(r);

  FuzzyRule *fuzzyRule14 = new FuzzyRule(14, relax1_relax2_14_calm3_14_14, r_14);
  fuzzy->addFuzzyRule(fuzzyRule14);

  //rule15
  FuzzyRuleAntecedent *relax1_relax2_15 = new FuzzyRuleAntecedent();
  relax1_relax2_15 ->joinWithAND(relax1, relax2);

  FuzzyRuleAntecedent *anxiety3_15 = new FuzzyRuleAntecedent();
  anxiety3_15->joinSingle(anxiety3);

  FuzzyRuleAntecedent *relax1_relax2_15_anxiety3_15_15 = new FuzzyRuleAntecedent();
  relax1_relax2_15_anxiety3_15_15->joinWithAND(relax1_relax2_15, anxiety3_15);

  FuzzyRuleConsequent *c_15 = new FuzzyRuleConsequent();
  c_15->addOutput(c);

  FuzzyRule *fuzzyRule15 = new FuzzyRule(15, relax1_relax2_15_anxiety3_15_15, c_15);
  fuzzy->addFuzzyRule(fuzzyRule15);
 
  //rule16
  FuzzyRuleAntecedent *relax1_relax2_16 = new FuzzyRuleAntecedent();
  relax1_relax2_16 ->joinWithAND(relax1, relax2);

  FuzzyRuleAntecedent *stress3_16 = new FuzzyRuleAntecedent();
  stress3_16->joinSingle(stress3);

  FuzzyRuleAntecedent *relax1_relax2_16_stress3_16_16 = new FuzzyRuleAntecedent();
  relax1_relax2_16_stress3_16_16->joinWithAND(relax1_relax2_16, stress3_16);

  FuzzyRuleConsequent *a_16 = new FuzzyRuleConsequent();
  a_16->addOutput(a);

  FuzzyRule *fuzzyRule16 = new FuzzyRule(16, relax1_relax2_16_stress3_16_16, a_16);
  fuzzy->addFuzzyRule(fuzzyRule16);

  //rule17
  FuzzyRuleAntecedent *calm1_stress2_17 = new FuzzyRuleAntecedent();
  calm1_stress2_17 ->joinWithAND(calm1, stress2);

  FuzzyRuleAntecedent *relax3_17 = new FuzzyRuleAntecedent();
  relax3_17->joinSingle(relax3);

  FuzzyRuleAntecedent *calm1_stress2_17_relax3_17_17 = new FuzzyRuleAntecedent();
  calm1_stress2_17_relax3_17_17->joinWithAND(calm1_stress2_17, relax3_17);

  FuzzyRuleConsequent *a_17 = new FuzzyRuleConsequent();
  a_17->addOutput(a);

  FuzzyRule *fuzzyRule17 = new FuzzyRule(17, calm1_stress2_17_relax3_17_17, a_17);
  fuzzy->addFuzzyRule(fuzzyRule17);

  //rule18
  FuzzyRuleAntecedent *calm1_stress2_18 = new FuzzyRuleAntecedent();
  calm1_stress2_18 ->joinWithAND(calm1, stress2);

  FuzzyRuleAntecedent *calm3_18 = new FuzzyRuleAntecedent();
  calm3_18->joinSingle(calm3);

  FuzzyRuleAntecedent *calm1_stress2_18_calm3_18_18 = new FuzzyRuleAntecedent();
  calm1_stress2_18_calm3_18_18->joinWithAND(calm1_stress2_18, calm3_18);

  FuzzyRuleConsequent *a_18 = new FuzzyRuleConsequent();
  a_18->addOutput(a);

  FuzzyRule *fuzzyRule18 = new FuzzyRule(18, calm1_stress2_18_calm3_18_18, a_18);
  fuzzy->addFuzzyRule(fuzzyRule18);

  //rule19
  FuzzyRuleAntecedent *calm1_stress2_19 = new FuzzyRuleAntecedent();
  calm1_stress2_19 ->joinWithAND(calm1, stress2);

  FuzzyRuleAntecedent *anxiety3_19 = new FuzzyRuleAntecedent();
  anxiety3_19->joinSingle(anxiety3);

  FuzzyRuleAntecedent *calm1_stress2_19_anxiety3_19_19 = new FuzzyRuleAntecedent();
  calm1_stress2_19_anxiety3_19_19->joinWithAND(calm1_stress2_19, anxiety3_19);

  FuzzyRuleConsequent *a_19 = new FuzzyRuleConsequent();
  a_19->addOutput(a);

  FuzzyRule *fuzzyRule19 = new FuzzyRule(19, calm1_stress2_19_anxiety3_19_19, a_19);
  fuzzy->addFuzzyRule(fuzzyRule19);

  //rule20
  FuzzyRuleAntecedent *calm1_stress2_20 = new FuzzyRuleAntecedent();
  calm1_stress2_20 ->joinWithAND(calm1, stress2);

  FuzzyRuleAntecedent *stress3_20 = new FuzzyRuleAntecedent();
  stress3_20->joinSingle(stress3);

  FuzzyRuleAntecedent *calm1_stress2_20_stress3_20_20 = new FuzzyRuleAntecedent();
  calm1_stress2_20_stress3_20_20->joinWithAND(calm1_stress2_20, stress3_20);

  FuzzyRuleConsequent *s_20 = new FuzzyRuleConsequent();
  s_20->addOutput(s);

  FuzzyRule *fuzzyRule20 = new FuzzyRule(20, calm1_stress2_20_stress3_20_20, s_20);
  fuzzy->addFuzzyRule(fuzzyRule20);

  //rule21
  FuzzyRuleAntecedent *calm1_anxiety2_21 = new FuzzyRuleAntecedent();
  calm1_anxiety2_21 ->joinWithAND(calm1, anxiety2);

  FuzzyRuleAntecedent *relax3_21 = new FuzzyRuleAntecedent();
  relax3_21->joinSingle(relax3);

  FuzzyRuleAntecedent *calm1_anxiety2_21_relax3_21_21 = new FuzzyRuleAntecedent();
  calm1_anxiety2_21_relax3_21_21->joinWithAND(calm1_anxiety2_21, relax3_21);

  FuzzyRuleConsequent *c_21 = new FuzzyRuleConsequent();
  c_21->addOutput(c);

  FuzzyRule *fuzzyRule21 = new FuzzyRule(21, calm1_anxiety2_21_relax3_21_21, c_21);
  fuzzy->addFuzzyRule(fuzzyRule21);

  //rule22
  FuzzyRuleAntecedent *calm1_anxiety2_22 = new FuzzyRuleAntecedent();
  calm1_anxiety2_22 ->joinWithAND(calm1, anxiety2);

  FuzzyRuleAntecedent *calm3_22 = new FuzzyRuleAntecedent();
  calm3_22->joinSingle(calm3);

  FuzzyRuleAntecedent *calm1_anxiety2_22_calm3_22_22 = new FuzzyRuleAntecedent();
  calm1_anxiety2_22_calm3_22_22->joinWithAND(calm1_anxiety2_22, calm3_22);

  FuzzyRuleConsequent *c_22 = new FuzzyRuleConsequent();
  c_22->addOutput(c);

  FuzzyRule *fuzzyRule22 = new FuzzyRule(22, calm1_anxiety2_22_calm3_22_22, c_22);
  fuzzy->addFuzzyRule(fuzzyRule22);

  //rule23
  FuzzyRuleAntecedent *calm1_anxiety2_23 = new FuzzyRuleAntecedent();
  calm1_anxiety2_23 ->joinWithAND(calm1, anxiety2);

  FuzzyRuleAntecedent *anxiety3_23 = new FuzzyRuleAntecedent();
  anxiety3_23->joinSingle(anxiety3);

  FuzzyRuleAntecedent *calm1_anxiety2_23_anxiety3_23_23 = new FuzzyRuleAntecedent();
  calm1_anxiety2_23_anxiety3_23_23->joinWithAND(calm1_anxiety2_23, anxiety3_23);

  FuzzyRuleConsequent *a_23 = new FuzzyRuleConsequent();
  a_23->addOutput(a);

  FuzzyRule *fuzzyRule23 = new FuzzyRule(23, calm1_anxiety2_23_anxiety3_23_23, a_23);
  fuzzy->addFuzzyRule(fuzzyRule23);

  //rule24
  FuzzyRuleAntecedent *calm1_anxiety2_24 = new FuzzyRuleAntecedent();
  calm1_anxiety2_24 ->joinWithAND(calm1, anxiety2);

  FuzzyRuleAntecedent *stress3_24 = new FuzzyRuleAntecedent();
  stress3_24->joinSingle(stress3);

  FuzzyRuleAntecedent *calm1_anxiety2_24_stress3_24_24 = new FuzzyRuleAntecedent();
  calm1_anxiety2_24_stress3_24_24->joinWithAND(calm1_anxiety2_24, stress3_24);

  FuzzyRuleConsequent *a_24 = new FuzzyRuleConsequent();
  a_24->addOutput(a);

  FuzzyRule *fuzzyRule24 = new FuzzyRule(24, calm1_anxiety2_24_stress3_24_24, a_24);
  fuzzy->addFuzzyRule(fuzzyRule24);

  //rule25
  FuzzyRuleAntecedent *calm1_calm2_25 = new FuzzyRuleAntecedent();
  calm1_calm2_25 ->joinWithAND(calm1, calm2);

  FuzzyRuleAntecedent *relax3_25 = new FuzzyRuleAntecedent();
  relax3_25->joinSingle(relax3);

  FuzzyRuleAntecedent *calm1_calm2_25_relax3_25_25 = new FuzzyRuleAntecedent();
  calm1_calm2_25_relax3_25_25->joinWithAND(calm1_calm2_25, relax3_25);

  FuzzyRuleConsequent *c_25 = new FuzzyRuleConsequent();
  c_25->addOutput(c);

  FuzzyRule *fuzzyRule25 = new FuzzyRule(25, calm1_calm2_25_relax3_25_25, c_25);
  fuzzy->addFuzzyRule(fuzzyRule25);

  //rule26
  FuzzyRuleAntecedent *calm1_calm2_26 = new FuzzyRuleAntecedent();
  calm1_calm2_26 ->joinWithAND(calm1, calm2);

  FuzzyRuleAntecedent *calm3_26 = new FuzzyRuleAntecedent();
  calm3_26->joinSingle(calm3);

  FuzzyRuleAntecedent *calm1_calm2_26_calm3_26_26 = new FuzzyRuleAntecedent();
  calm1_calm2_26_calm3_26_26->joinWithAND(calm1_calm2_26, calm3_26);

  FuzzyRuleConsequent *c_26 = new FuzzyRuleConsequent();
  c_26->addOutput(c);

  FuzzyRule *fuzzyRule26 = new FuzzyRule(26, calm1_calm2_26_calm3_26_26, c_26);
  fuzzy->addFuzzyRule(fuzzyRule26);

  //rule27
  FuzzyRuleAntecedent *calm1_calm2_27 = new FuzzyRuleAntecedent();
  calm1_calm2_27 ->joinWithAND(calm1, calm2);

  FuzzyRuleAntecedent *anxiety3_27 = new FuzzyRuleAntecedent();
  anxiety3_27->joinSingle(anxiety3);

  FuzzyRuleAntecedent *calm1_calm2_27_anxiety3_27_27 = new FuzzyRuleAntecedent();
  calm1_calm2_27_anxiety3_27_27->joinWithAND(calm1_calm2_27, anxiety3_27);

  FuzzyRuleConsequent *c_27 = new FuzzyRuleConsequent();
  c_27->addOutput(c);

  FuzzyRule *fuzzyRule27 = new FuzzyRule(27, calm1_calm2_27_anxiety3_27_27, c_27);
  fuzzy->addFuzzyRule(fuzzyRule27);

  //rule28
  FuzzyRuleAntecedent *calm1_calm2_28 = new FuzzyRuleAntecedent();
  calm1_calm2_28 ->joinWithAND(calm1, calm2);

  FuzzyRuleAntecedent *stress3_28 = new FuzzyRuleAntecedent();
  stress3_28->joinSingle(stress3);

  FuzzyRuleAntecedent *calm1_calm2_28_stress3_28_28 = new FuzzyRuleAntecedent();
  calm1_calm2_28_stress3_28_28->joinWithAND(calm1_calm2_28, stress3_28);

  FuzzyRuleConsequent *a_28 = new FuzzyRuleConsequent();
  a_28->addOutput(a);

  FuzzyRule *fuzzyRule28 = new FuzzyRule(28, calm1_calm2_28_stress3_28_28, a_28);
  fuzzy->addFuzzyRule(fuzzyRule28);

  //rule29
  FuzzyRuleAntecedent *calm1_relax2_29 = new FuzzyRuleAntecedent();
  calm1_relax2_29 ->joinWithAND(calm1, relax2);

  FuzzyRuleAntecedent *relax3_29 = new FuzzyRuleAntecedent();
  relax3_29->joinSingle(relax3);

  FuzzyRuleAntecedent *calm1_relax2_29_relax3_29_29 = new FuzzyRuleAntecedent();
  calm1_relax2_29_relax3_29_29->joinWithAND(calm1_relax2_29, relax3_29);

  FuzzyRuleConsequent *r_29 = new FuzzyRuleConsequent();
  r_29->addOutput(r);

  FuzzyRule *fuzzyRule29 = new FuzzyRule(29, calm1_relax2_29_relax3_29_29, r_29);
  fuzzy->addFuzzyRule(fuzzyRule29);

  //rule30
  FuzzyRuleAntecedent *calm1_relax2_30 = new FuzzyRuleAntecedent();
  calm1_relax2_30 ->joinWithAND(calm1, relax2);

  FuzzyRuleAntecedent *calm3_30 = new FuzzyRuleAntecedent();
  calm3_30->joinSingle(calm3);

  FuzzyRuleAntecedent *calm1_relax2_30_calm3_30_30 = new FuzzyRuleAntecedent();
  calm1_relax2_30_calm3_30_30->joinWithAND(calm1_relax2_30, calm3_30);

  FuzzyRuleConsequent *c_30 = new FuzzyRuleConsequent();
  c_30->addOutput(c);

  FuzzyRule *fuzzyRule30 = new FuzzyRule(30, calm1_relax2_30_calm3_30_30, c_30);
  fuzzy->addFuzzyRule(fuzzyRule30);

  //rule31
  FuzzyRuleAntecedent *calm1_relax2_31 = new FuzzyRuleAntecedent();
  calm1_relax2_31 ->joinWithAND(calm1, relax2);

  FuzzyRuleAntecedent *anxiety3_31 = new FuzzyRuleAntecedent();
  anxiety3_31->joinSingle(anxiety3);

  FuzzyRuleAntecedent *calm1_relax2_31_anxiety3_31_31 = new FuzzyRuleAntecedent();
  calm1_relax2_31_anxiety3_31_31->joinWithAND(calm1_relax2_31, anxiety3_31);

  FuzzyRuleConsequent *c_31 = new FuzzyRuleConsequent();
  c_31->addOutput(c);

  FuzzyRule *fuzzyRule31 = new FuzzyRule(31, calm1_relax2_31_anxiety3_31_31, c_31);
  fuzzy->addFuzzyRule(fuzzyRule31);

  //rule32
  FuzzyRuleAntecedent *calm1_relax2_32 = new FuzzyRuleAntecedent();
  calm1_relax2_32 ->joinWithAND(calm1, relax2);

  FuzzyRuleAntecedent *stress3_32 = new FuzzyRuleAntecedent();
  stress3_32->joinSingle(stress3);

  FuzzyRuleAntecedent *calm1_relax2_32_stress3_32_32 = new FuzzyRuleAntecedent();
  calm1_relax2_32_stress3_32_32->joinWithAND(calm1_relax2_32, stress3_32);

  FuzzyRuleConsequent *a_32 = new FuzzyRuleConsequent();
  a_32->addOutput(a);

  FuzzyRule *fuzzyRule32 = new FuzzyRule(32, calm1_relax2_32_stress3_32_32, a_32);
  fuzzy->addFuzzyRule(fuzzyRule32);

  //rule33
  FuzzyRuleAntecedent *anxiety1_stress2_33 = new FuzzyRuleAntecedent();
  anxiety1_stress2_33 ->joinWithAND(anxiety1, stress2);

  FuzzyRuleAntecedent *relax3_33 = new FuzzyRuleAntecedent();
  relax3_33->joinSingle(relax3);

  FuzzyRuleAntecedent *anxiety1_stress2_33_relax3_33_33 = new FuzzyRuleAntecedent();
  anxiety1_stress2_33_relax3_33_33->joinWithAND(anxiety1_stress2_33, relax3_33);

  FuzzyRuleConsequent *a_33 = new FuzzyRuleConsequent();
  a_33->addOutput(a);

  FuzzyRule *fuzzyRule33 = new FuzzyRule(33, anxiety1_stress2_33_relax3_33_33, a_33);
  fuzzy->addFuzzyRule(fuzzyRule33);

  //rule34
  FuzzyRuleAntecedent *anxiety1_stress2_34 = new FuzzyRuleAntecedent();
  anxiety1_stress2_34 ->joinWithAND(anxiety1, stress2);

  FuzzyRuleAntecedent *calm3_34 = new FuzzyRuleAntecedent();
  calm3_34->joinSingle(calm3);

  FuzzyRuleAntecedent *anxiety1_stress2_34_calm3_34_34 = new FuzzyRuleAntecedent();
  anxiety1_stress2_34_calm3_34_34->joinWithAND(anxiety1_stress2_34, calm3_34);

  FuzzyRuleConsequent *a_34 = new FuzzyRuleConsequent();
  a_34->addOutput(a);

  FuzzyRule *fuzzyRule34 = new FuzzyRule(34, anxiety1_stress2_34_calm3_34_34, a_34);
  fuzzy->addFuzzyRule(fuzzyRule34);


  //rule35
  FuzzyRuleAntecedent *anxiety1_stress2_35 = new FuzzyRuleAntecedent();
  anxiety1_stress2_35 ->joinWithAND(anxiety1, stress2);

  FuzzyRuleAntecedent *anxiety3_35 = new FuzzyRuleAntecedent();
  anxiety3_35->joinSingle(anxiety3);

  FuzzyRuleAntecedent *anxiety1_stress2_35_anxiety3_35_35 = new FuzzyRuleAntecedent();
  anxiety1_stress2_35_anxiety3_35_35->joinWithAND(anxiety1_stress2_35, anxiety3_35);

  FuzzyRuleConsequent *a_35 = new FuzzyRuleConsequent();
  a_35->addOutput(a);

  FuzzyRule *fuzzyRule35 = new FuzzyRule(35, anxiety1_stress2_35_anxiety3_35_35, a_35);
  fuzzy->addFuzzyRule(fuzzyRule35);

  //rule36
  FuzzyRuleAntecedent *anxiety1_stress2_36 = new FuzzyRuleAntecedent();
  anxiety1_stress2_36 ->joinWithAND(anxiety1, stress2);

  FuzzyRuleAntecedent *stress3_36 = new FuzzyRuleAntecedent();
  stress3_36->joinSingle(stress3);

  FuzzyRuleAntecedent *anxiety1_stress2_36_stress3_36_36 = new FuzzyRuleAntecedent();
  anxiety1_stress2_36_stress3_36_36->joinWithAND(anxiety1_stress2_36, stress3_36);

  FuzzyRuleConsequent *s_36 = new FuzzyRuleConsequent();
  s_36->addOutput(s);

  FuzzyRule *fuzzyRule36 = new FuzzyRule(36, anxiety1_stress2_36_stress3_36_36, s_36);
  fuzzy->addFuzzyRule(fuzzyRule36);

  //rule37
  FuzzyRuleAntecedent *anxiety1_anxiety2_37 = new FuzzyRuleAntecedent();
  anxiety1_anxiety2_37 ->joinWithAND(anxiety1, anxiety2);

  FuzzyRuleAntecedent *relax3_37 = new FuzzyRuleAntecedent();
  relax3_37->joinSingle(relax3);

  FuzzyRuleAntecedent *anxiety1_anxiety2_37_relax3_37_37 = new FuzzyRuleAntecedent();
  anxiety1_anxiety2_37_relax3_37_37->joinWithAND(anxiety1_anxiety2_37, relax3_37);

  FuzzyRuleConsequent *a_37 = new FuzzyRuleConsequent();
  a_37->addOutput(a);

  FuzzyRule *fuzzyRule37 = new FuzzyRule(37, anxiety1_anxiety2_37_relax3_37_37, a_37);
  fuzzy->addFuzzyRule(fuzzyRule37);

  //rule38
  FuzzyRuleAntecedent *anxiety1_anxiety2_38 = new FuzzyRuleAntecedent();
  anxiety1_anxiety2_38 ->joinWithAND(anxiety1, anxiety2);

  FuzzyRuleAntecedent *calm3_38 = new FuzzyRuleAntecedent();
  calm3_38->joinSingle(calm3);

  FuzzyRuleAntecedent *anxiety1_anxiety2_38_calm3_38_38 = new FuzzyRuleAntecedent();
  anxiety1_anxiety2_38_calm3_38_38->joinWithAND(anxiety1_anxiety2_38, calm3_38);

  FuzzyRuleConsequent *a_38 = new FuzzyRuleConsequent();
  a_38->addOutput(a);

  FuzzyRule *fuzzyRule38 = new FuzzyRule(38, anxiety1_anxiety2_38_calm3_38_38, a_38);
  fuzzy->addFuzzyRule(fuzzyRule38);

  //rule39
  FuzzyRuleAntecedent *anxiety1_anxiety2_39 = new FuzzyRuleAntecedent();
  anxiety1_anxiety2_39 ->joinWithAND(anxiety1, anxiety2);

  FuzzyRuleAntecedent *anxiety3_39 = new FuzzyRuleAntecedent();
  anxiety3_39->joinSingle(anxiety3);

  FuzzyRuleAntecedent *anxiety1_anxiety2_39_anxiety3_39_39 = new FuzzyRuleAntecedent();
  anxiety1_anxiety2_39_anxiety3_39_39->joinWithAND(anxiety1_anxiety2_39, anxiety3_39);

  FuzzyRuleConsequent *a_39 = new FuzzyRuleConsequent();
  a_39->addOutput(a);

  FuzzyRule *fuzzyRule39 = new FuzzyRule(39, anxiety1_anxiety2_39_anxiety3_39_39, a_39);
  fuzzy->addFuzzyRule(fuzzyRule39);

  //rule40
  FuzzyRuleAntecedent *anxiety1_anxiety2_40 = new FuzzyRuleAntecedent();
  anxiety1_anxiety2_40 ->joinWithAND(anxiety1, anxiety2);

  FuzzyRuleAntecedent *stress3_40 = new FuzzyRuleAntecedent();
  stress3_40->joinSingle(stress3);

  FuzzyRuleAntecedent *anxiety1_anxiety2_40_stress3_40_40 = new FuzzyRuleAntecedent();
  anxiety1_anxiety2_40_stress3_40_40->joinWithAND(anxiety1_anxiety2_40, stress3_40);

  FuzzyRuleConsequent *s_40 = new FuzzyRuleConsequent();
  s_40->addOutput(s);

  FuzzyRule *fuzzyRule40 = new FuzzyRule(40, anxiety1_anxiety2_40_stress3_40_40, s_40);
  fuzzy->addFuzzyRule(fuzzyRule40);

  //rule41
  FuzzyRuleAntecedent *anxiety1_calm2_41 = new FuzzyRuleAntecedent();
  anxiety1_calm2_41 ->joinWithAND(anxiety1, calm2);

  FuzzyRuleAntecedent *relax3_41 = new FuzzyRuleAntecedent();
  relax3_41->joinSingle(relax3);

  FuzzyRuleAntecedent *anxiety1_calm2_41_relax3_41_41 = new FuzzyRuleAntecedent();
  anxiety1_calm2_41_relax3_41_41->joinWithAND(anxiety1_calm2_41, relax3_41);

  FuzzyRuleConsequent *c_41 = new FuzzyRuleConsequent();
  c_41->addOutput(c);

  FuzzyRule *fuzzyRule41 = new FuzzyRule(41, anxiety1_calm2_41_relax3_41_41, c_41);
  fuzzy->addFuzzyRule(fuzzyRule41);

  //rule42
  FuzzyRuleAntecedent *anxiety1_calm2_42 = new FuzzyRuleAntecedent();
  anxiety1_calm2_42 ->joinWithAND(anxiety1, calm2);

  FuzzyRuleAntecedent *calm3_42 = new FuzzyRuleAntecedent();
  calm3_42->joinSingle(calm3);

  FuzzyRuleAntecedent *anxiety1_calm2_42_calm3_42_42 = new FuzzyRuleAntecedent();
  anxiety1_calm2_42_calm3_42_42->joinWithAND(anxiety1_calm2_42, calm3_42);

  FuzzyRuleConsequent *c_42 = new FuzzyRuleConsequent();
  c_42->addOutput(c);

  FuzzyRule *fuzzyRule42 = new FuzzyRule(42, anxiety1_calm2_42_calm3_42_42, c_42);
  fuzzy->addFuzzyRule(fuzzyRule42);

  //rule43
  FuzzyRuleAntecedent *anxiety1_calm2_43 = new FuzzyRuleAntecedent();
  anxiety1_calm2_43 ->joinWithAND(anxiety1, calm2);

  FuzzyRuleAntecedent *anxiety3_43 = new FuzzyRuleAntecedent();
  anxiety3_43->joinSingle(anxiety3);

  FuzzyRuleAntecedent *anxiety1_calm2_43_anxiety3_43_43 = new FuzzyRuleAntecedent();
  anxiety1_calm2_43_anxiety3_43_43->joinWithAND(anxiety1_calm2_43, anxiety3_43);

  FuzzyRuleConsequent *a_43 = new FuzzyRuleConsequent();
  a_43->addOutput(a);

  FuzzyRule *fuzzyRule43 = new FuzzyRule(43, anxiety1_calm2_43_anxiety3_43_43, a_43);
  fuzzy->addFuzzyRule(fuzzyRule43);

  //rule44
  FuzzyRuleAntecedent *anxiety1_calm2_44 = new FuzzyRuleAntecedent();
  anxiety1_calm2_44 ->joinWithAND(anxiety1, calm2);

  FuzzyRuleAntecedent *stress3_44 = new FuzzyRuleAntecedent();
  stress3_44->joinSingle(stress3);

  FuzzyRuleAntecedent *anxiety1_calm2_44_stress3_44_44 = new FuzzyRuleAntecedent();
  anxiety1_calm2_44_stress3_44_44->joinWithAND(anxiety1_calm2_44, stress3_44);

  FuzzyRuleConsequent *a_44 = new FuzzyRuleConsequent();
  a_44->addOutput(a);

  FuzzyRule *fuzzyRule44 = new FuzzyRule(44, anxiety1_calm2_44_stress3_44_44, a_44);
  fuzzy->addFuzzyRule(fuzzyRule44);

  //rule45
  FuzzyRuleAntecedent *anxiety1_relax2_45 = new FuzzyRuleAntecedent();
  anxiety1_relax2_45 ->joinWithAND(anxiety1, relax2);

  FuzzyRuleAntecedent *relax3_45 = new FuzzyRuleAntecedent();
  relax3_45->joinSingle(relax3);

  FuzzyRuleAntecedent *anxiety1_relax2_45_relax3_45_45 = new FuzzyRuleAntecedent();
  anxiety1_relax2_45_relax3_45_45->joinWithAND(anxiety1_relax2_45, relax3_45);

  FuzzyRuleConsequent *c_45 = new FuzzyRuleConsequent();
  c_45->addOutput(c);

  FuzzyRule *fuzzyRule45 = new FuzzyRule(45, anxiety1_relax2_45_relax3_45_45, c_45);
  fuzzy->addFuzzyRule(fuzzyRule45);

  //rule46
  FuzzyRuleAntecedent *anxiety1_relax2_46 = new FuzzyRuleAntecedent();
  anxiety1_relax2_46 ->joinWithAND(anxiety1, relax2);

  FuzzyRuleAntecedent *calm3_46 = new FuzzyRuleAntecedent();
  calm3_46->joinSingle(calm3);

  FuzzyRuleAntecedent *anxiety1_relax2_46_calm3_46_46 = new FuzzyRuleAntecedent();
  anxiety1_relax2_46_calm3_46_46->joinWithAND(anxiety1_relax2_46, calm3_46);

  FuzzyRuleConsequent *c_46 = new FuzzyRuleConsequent();
  c_46->addOutput(c);

  FuzzyRule *fuzzyRule46 = new FuzzyRule(46, anxiety1_relax2_46_calm3_46_46, c_46);
  fuzzy->addFuzzyRule(fuzzyRule46);

  //rule47
  FuzzyRuleAntecedent *anxiety1_relax2_47 = new FuzzyRuleAntecedent();
  anxiety1_relax2_47 ->joinWithAND(anxiety1, relax2);

  FuzzyRuleAntecedent *anxiety3_47 = new FuzzyRuleAntecedent();
  anxiety3_47->joinSingle(anxiety3);

  FuzzyRuleAntecedent *anxiety1_relax2_47_anxiety3_47_47 = new FuzzyRuleAntecedent();
  anxiety1_relax2_47_anxiety3_47_47->joinWithAND(anxiety1_relax2_47, anxiety3_47);

  FuzzyRuleConsequent *a_47 = new FuzzyRuleConsequent();
  a_47->addOutput(a);

  FuzzyRule *fuzzyRule47 = new FuzzyRule(47, anxiety1_relax2_47_anxiety3_47_47, a_47);
  fuzzy->addFuzzyRule(fuzzyRule47);

  //rule48
  FuzzyRuleAntecedent *anxiety1_relax2_48 = new FuzzyRuleAntecedent();
  anxiety1_relax2_48 ->joinWithAND(anxiety1, relax2);

  FuzzyRuleAntecedent *stress3_48 = new FuzzyRuleAntecedent();
  stress3_48->joinSingle(stress3);

  FuzzyRuleAntecedent *anxiety1_relax2_48_stress3_48_48 = new FuzzyRuleAntecedent();
  anxiety1_relax2_48_stress3_48_48->joinWithAND(anxiety1_relax2_48, stress3_48);

  FuzzyRuleConsequent *a_48 = new FuzzyRuleConsequent();
  a_48->addOutput(a);

  FuzzyRule *fuzzyRule48 = new FuzzyRule(48, anxiety1_relax2_48_stress3_48_48, a_48);
  fuzzy->addFuzzyRule(fuzzyRule48);

  //rule49
  FuzzyRuleAntecedent *stress1_stress2_49 = new FuzzyRuleAntecedent();
  stress1_stress2_49 ->joinWithAND(stress1, stress2);

  FuzzyRuleAntecedent *relax3_49 = new FuzzyRuleAntecedent();
  relax3_49->joinSingle(relax3);

  FuzzyRuleAntecedent *stress1_stress2_49_relax3_49_49 = new FuzzyRuleAntecedent();
  stress1_stress2_49_relax3_49_49->joinWithAND(stress1_stress2_49, relax3_49);

  FuzzyRuleConsequent *s_49 = new FuzzyRuleConsequent();
  s_49->addOutput(s);

  FuzzyRule *fuzzyRule49 = new FuzzyRule(49, stress1_stress2_49_relax3_49_49, s_49);
  fuzzy->addFuzzyRule(fuzzyRule49);

  //rule50
  FuzzyRuleAntecedent *stress1_stress2_50 = new FuzzyRuleAntecedent();
  stress1_stress2_50 ->joinWithAND(stress1, stress2);

  FuzzyRuleAntecedent *calm3_50 = new FuzzyRuleAntecedent();
  calm3_50->joinSingle(calm3);

  FuzzyRuleAntecedent *stress1_stress2_50_calm3_50_50 = new FuzzyRuleAntecedent();
  stress1_stress2_50_calm3_50_50->joinWithAND(stress1_stress2_50, calm3_50);

  FuzzyRuleConsequent *s_50 = new FuzzyRuleConsequent();
  s_50->addOutput(s);

  FuzzyRule *fuzzyRule50 = new FuzzyRule(50, stress1_stress2_50_calm3_50_50, s_50);
  fuzzy->addFuzzyRule(fuzzyRule50);

  //rule51
  FuzzyRuleAntecedent *stress1_stress2_51 = new FuzzyRuleAntecedent();
  stress1_stress2_51 ->joinWithAND(stress1, stress2);

  FuzzyRuleAntecedent *anxiety3_51 = new FuzzyRuleAntecedent();
  anxiety3_51->joinSingle(anxiety3);

  FuzzyRuleAntecedent *stress1_stress2_51_anxiety3_51_51 = new FuzzyRuleAntecedent();
  stress1_stress2_51_anxiety3_51_51->joinWithAND(stress1_stress2_51, anxiety3_51);

  FuzzyRuleConsequent *s_51 = new FuzzyRuleConsequent();
  s_51->addOutput(s);

  FuzzyRule *fuzzyRule51 = new FuzzyRule(51, stress1_stress2_51_anxiety3_51_51, s_51);
  fuzzy->addFuzzyRule(fuzzyRule51);

  //rule52
  FuzzyRuleAntecedent *stress1_stress2_52 = new FuzzyRuleAntecedent();
  stress1_stress2_52 ->joinWithAND(stress1, stress2);

  FuzzyRuleAntecedent *stress3_52 = new FuzzyRuleAntecedent();
  stress3_52->joinSingle(stress3);

  FuzzyRuleAntecedent *stress1_stress2_52_stress3_52_52 = new FuzzyRuleAntecedent();
  stress1_stress2_52_stress3_52_52->joinWithAND(stress1_stress2_52, stress3_52);

  FuzzyRuleConsequent *s_52 = new FuzzyRuleConsequent();
  s_52->addOutput(s);

  FuzzyRule *fuzzyRule52 = new FuzzyRule(52, stress1_stress2_52_stress3_52_52, s_52);
  fuzzy->addFuzzyRule(fuzzyRule52);

  //rule53
  FuzzyRuleAntecedent *stress1_anxiety2_53 = new FuzzyRuleAntecedent();
  stress1_anxiety2_53 ->joinWithAND(stress1, anxiety2);

  FuzzyRuleAntecedent *relax3_53 = new FuzzyRuleAntecedent();
  relax3_53->joinSingle(relax3);

  FuzzyRuleAntecedent *stress1_anxiety2_53_relax3_53_53 = new FuzzyRuleAntecedent();
  stress1_anxiety2_53_relax3_53_53->joinWithAND(stress1_anxiety2_53, relax3_53);

  FuzzyRuleConsequent *a_53 = new FuzzyRuleConsequent();
  a_53->addOutput(a);

  FuzzyRule *fuzzyRule53 = new FuzzyRule(53, stress1_anxiety2_53_relax3_53_53, a_53);
  fuzzy->addFuzzyRule(fuzzyRule53);

  //rule54
  FuzzyRuleAntecedent *stress1_anxiety2_54 = new FuzzyRuleAntecedent();
  stress1_anxiety2_54 ->joinWithAND(stress1, anxiety2);

  FuzzyRuleAntecedent *calm3_54 = new FuzzyRuleAntecedent();
  calm3_54->joinSingle(calm3);

  FuzzyRuleAntecedent *stress1_anxiety2_54_calm3_54_54 = new FuzzyRuleAntecedent();
  stress1_anxiety2_54_calm3_54_54->joinWithAND(stress1_anxiety2_54, calm3_54);

  FuzzyRuleConsequent *a_54 = new FuzzyRuleConsequent();
  a_54->addOutput(a);

  FuzzyRule *fuzzyRule54 = new FuzzyRule(54, stress1_anxiety2_54_calm3_54_54, a_54);
  fuzzy->addFuzzyRule(fuzzyRule54);

  //rule55
  FuzzyRuleAntecedent *stress1_anxiety2_55 = new FuzzyRuleAntecedent();
  stress1_anxiety2_55 ->joinWithAND(stress1, anxiety2);

  FuzzyRuleAntecedent *anxiety3_55 = new FuzzyRuleAntecedent();
  anxiety3_55->joinSingle(anxiety3);

  FuzzyRuleAntecedent *stress1_anxiety2_55_anxiety3_55_55 = new FuzzyRuleAntecedent();
  stress1_anxiety2_55_anxiety3_55_55->joinWithAND(stress1_anxiety2_55, anxiety3_55);

  FuzzyRuleConsequent *a_55 = new FuzzyRuleConsequent();
  a_55->addOutput(a);

  FuzzyRule *fuzzyRule55 = new FuzzyRule(55, stress1_anxiety2_55_anxiety3_55_55, a_55);
  fuzzy->addFuzzyRule(fuzzyRule55);

  //rule56
  FuzzyRuleAntecedent *stress1_anxiety2_56 = new FuzzyRuleAntecedent();
  stress1_anxiety2_56 ->joinWithAND(stress1, anxiety2);

  FuzzyRuleAntecedent *stress3_56 = new FuzzyRuleAntecedent();
  stress3_56->joinSingle(stress3);

  FuzzyRuleAntecedent *stress1_anxiety2_56_stress3_56_56 = new FuzzyRuleAntecedent();
  stress1_anxiety2_56_stress3_56_56->joinWithAND(stress1_anxiety2_56, stress3_56);

  FuzzyRuleConsequent *s_56 = new FuzzyRuleConsequent();
  s_56->addOutput(s);

  FuzzyRule *fuzzyRule56 = new FuzzyRule(56, stress1_anxiety2_56_stress3_56_56, s_56);
  fuzzy->addFuzzyRule(fuzzyRule56);

  //rule57
  FuzzyRuleAntecedent *stress1_calm2_57 = new FuzzyRuleAntecedent();
  stress1_calm2_57 ->joinWithAND(stress1, calm2);

  FuzzyRuleAntecedent *relax3_57 = new FuzzyRuleAntecedent();
  relax3_57->joinSingle(relax3);

  FuzzyRuleAntecedent *stress1_calm2_57_relax3_57_57 = new FuzzyRuleAntecedent();
  stress1_calm2_57_relax3_57_57->joinWithAND(stress1_calm2_57, relax3_57);

  FuzzyRuleConsequent *a_57 = new FuzzyRuleConsequent();
  a_57->addOutput(a);

  FuzzyRule *fuzzyRule57 = new FuzzyRule(57, stress1_calm2_57_relax3_57_57, a_57);
  fuzzy->addFuzzyRule(fuzzyRule57);

  //rule58
  FuzzyRuleAntecedent *stress1_calm2_58 = new FuzzyRuleAntecedent();
  stress1_calm2_58 ->joinWithAND(stress1, calm2);

  FuzzyRuleAntecedent *calm3_58 = new FuzzyRuleAntecedent();
  calm3_58->joinSingle(calm3);

  FuzzyRuleAntecedent *stress1_calm2_58_calm3_58_58 = new FuzzyRuleAntecedent();
  stress1_calm2_58_calm3_58_58->joinWithAND(stress1_calm2_58, calm3_58);

  FuzzyRuleConsequent *a_58 = new FuzzyRuleConsequent();
  a_58->addOutput(a);

  FuzzyRule *fuzzyRule58 = new FuzzyRule(58, stress1_calm2_58_calm3_58_58, a_58);
  fuzzy->addFuzzyRule(fuzzyRule58);
  
  //rule59
  FuzzyRuleAntecedent *stress1_calm2_59 = new FuzzyRuleAntecedent();
  stress1_calm2_59 ->joinWithAND(stress1, calm2);

  FuzzyRuleAntecedent *anxiety3_59 = new FuzzyRuleAntecedent();
  anxiety3_59->joinSingle(anxiety3);

  FuzzyRuleAntecedent *stress1_calm2_59_anxiety3_59_59 = new FuzzyRuleAntecedent();
  stress1_calm2_59_anxiety3_59_59->joinWithAND(stress1_calm2_59, anxiety3_59);

  FuzzyRuleConsequent *a_59 = new FuzzyRuleConsequent();
  a_59->addOutput(a);

  FuzzyRule *fuzzyRule59 = new FuzzyRule(59, stress1_calm2_59_anxiety3_59_59, a_59);
  fuzzy->addFuzzyRule(fuzzyRule59);

  //rule60
  FuzzyRuleAntecedent *stress1_calm2_60 = new FuzzyRuleAntecedent();
  stress1_calm2_60 ->joinWithAND(stress1, calm2);

  FuzzyRuleAntecedent *stress3_60 = new FuzzyRuleAntecedent();
  stress3_60->joinSingle(stress3);

  FuzzyRuleAntecedent *stress1_calm2_60_stress3_60_60 = new FuzzyRuleAntecedent();
  stress1_calm2_60_stress3_60_60->joinWithAND(stress1_calm2_60, stress3_60);

  FuzzyRuleConsequent *s_60 = new FuzzyRuleConsequent();
  s_60->addOutput(s);

  FuzzyRule *fuzzyRule60 = new FuzzyRule(60, stress1_calm2_60_stress3_60_60, s_60);
  fuzzy->addFuzzyRule(fuzzyRule60);

  //rule61
  FuzzyRuleAntecedent *stress1_relax2_61 = new FuzzyRuleAntecedent();
  stress1_relax2_61 ->joinWithAND(stress1, relax2);

  FuzzyRuleAntecedent *relax3_61 = new FuzzyRuleAntecedent();
  relax3_61->joinSingle(relax3);

  FuzzyRuleAntecedent *stress1_relax2_61_relax3_61_61 = new FuzzyRuleAntecedent();
  stress1_relax2_61_relax3_61_61->joinWithAND(stress1_relax2_61, relax3_61);

  FuzzyRuleConsequent *a_61 = new FuzzyRuleConsequent();
  a_61->addOutput(a);

  FuzzyRule *fuzzyRule61 = new FuzzyRule(61, stress1_relax2_61_relax3_61_61, a_61);
  fuzzy->addFuzzyRule(fuzzyRule61);

  //rule62
  FuzzyRuleAntecedent *stress1_relax2_62 = new FuzzyRuleAntecedent();
  stress1_relax2_62 ->joinWithAND(stress1, relax2);

  FuzzyRuleAntecedent *calm3_62 = new FuzzyRuleAntecedent();
  calm3_62->joinSingle(calm3);

  FuzzyRuleAntecedent *stress1_relax2_62_calm3_62_62 = new FuzzyRuleAntecedent();
  stress1_relax2_62_calm3_62_62->joinWithAND(stress1_relax2_62, calm3_62);

  FuzzyRuleConsequent *a_62 = new FuzzyRuleConsequent();
  a_62->addOutput(a);

  FuzzyRule *fuzzyRule62 = new FuzzyRule(62, stress1_relax2_62_calm3_62_62, a_62);
  fuzzy->addFuzzyRule(fuzzyRule62);

  //rule63
  FuzzyRuleAntecedent *stress1_relax2_63 = new FuzzyRuleAntecedent();
  stress1_relax2_63 ->joinWithAND(stress1, relax2);

  FuzzyRuleAntecedent *anxiety3_63 = new FuzzyRuleAntecedent();
  anxiety3_63->joinSingle(anxiety3);

  FuzzyRuleAntecedent *stress1_relax2_63_anxiety3_63_63 = new FuzzyRuleAntecedent();
  stress1_relax2_63_anxiety3_63_63->joinWithAND(stress1_relax2_63, anxiety3_63);

  FuzzyRuleConsequent *a_63 = new FuzzyRuleConsequent();
  a_63->addOutput(a);

  FuzzyRule *fuzzyRule63 = new FuzzyRule(63, stress1_relax2_63_anxiety3_63_63, a_63);
  fuzzy->addFuzzyRule(fuzzyRule63);

  //rule64
  FuzzyRuleAntecedent *stress1_relax2_64 = new FuzzyRuleAntecedent();
  stress1_relax2_64 ->joinWithAND(stress1, relax2);

  FuzzyRuleAntecedent *stress3_64 = new FuzzyRuleAntecedent();
  stress3_64->joinSingle(stress3);

  FuzzyRuleAntecedent *stress1_relax2_64_stress3_64_64 = new FuzzyRuleAntecedent();
  stress1_relax2_64_stress3_64_64->joinWithAND(stress1_relax2_64, stress3_64);

  FuzzyRuleConsequent *s_64 = new FuzzyRuleConsequent();
  s_64->addOutput(s);

  FuzzyRule *fuzzyRule64 = new FuzzyRule(64, stress1_relax2_64_stress3_64_64, s_64);
  fuzzy->addFuzzyRule(fuzzyRule64);
  //-------------------------------------------------------//
}


void setup() {
    //----------------//
    Serial.begin(115200);
    Oksigen.begin(115200);
    dataIn="";
    //----------------//
  Serial.println("System Start");
  fuzzySet();

  //---------------------------//
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  delay(1000);
  WiFi.disconnect();
  delay(1000);
  WiFi.begin(ssid, password);
  delay(1000);

  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print('.');
  }
  //---------------------------//
}

int value = 0;
void loop(){
  
  
  if(Oksigen.available()>0)
  {
      char inChar = (char)Oksigen.read();
      dataIn += inChar;
      if(inChar == '\n') {parsing = true;}
  }
  if(parsing)
  {
      parsingData();
      parsing=false;
      dataIn="";

        //fuzzy
          fuzzy->setInput(1, dt[0].toInt());
          fuzzy->setInput(2, dt[1].toInt());
          fuzzy->setInput(3, dt[2].toInt());
        
          fuzzy->fuzzify();
            
          float output = fuzzy->defuzzify(1);
          String Klasifikasi;
          //---------------------------------------//
            if(output <= 0.25){
               Serial.println(Klasifikasi = "relax");
             }
            else if((output > 0.25) && (output <= 0.50)){
               Serial.println(Klasifikasi = "calm");
               }
            else if((output > 0.50) && (output <= 0.75)){
               Serial.println(Klasifikasi = "anxiety");
               }
            else {
               Serial.println(Klasifikasi = "stress");
            }
            Serial.print("Nilai Klasifikasi : ");
            Serial.println(output);
            dt[3] = Klasifikasi;
  
  delay(10);
  ++value;

 
  Serial.print("connecting to : ");
  Serial.println(host);

 
  WiFiClient client;
  if(!client.connect(host, 80)){
    Serial.println("connection failed");
    return;
  }
 
  String url = "/ex/write_data.php?data1=";
  url += dt[0];
  url += "&data2=";
  url += dt[1].toInt();
  url += "&data3=";
  url += dt[2].toInt();
  url += "&data4=";
  url += dt[3];


  Serial.print("Requesting URL: ");
  Serial.println(url);

  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host +"\r\n" +
               "Connection: close\r\n\r\n");

  
  unsigned long timeout = millis();
  while (client.available() == 0){
    if(millis() - timeout > 1000){
      Serial.println("Client Timeout");
      client.stop();
      return;
    }
  }

  
  while (client.available() == 0){
    String line = client.readStringUntil('\r');
    Serial.print(line);
    }

    Serial.println("Closing connection");
    }

} 

void parsingData()
{
  int j=0;
  dt[j]="";

  for(i=1;i<dataIn.length();i++)
  {
      
      if((dataIn[i] == ','))
      {
        
        j++;
        dt[j]="";
      }
      else 
      {
        
        dt[j] = dt[j] + dataIn[i];
      }
  }
 
  //---------------------------------------//
  
  

  Serial.print("data 1 : ");
  Serial.print(dt[0].toInt());
  Serial.print("\n");
  Serial.print("data 2 : ");
  Serial.print(dt[1].toInt());
  Serial.print("\n");
  Serial.print("data 3 : ");
  Serial.print(dt[2].toInt());
  Serial.print("\n");
  
  
  
}
