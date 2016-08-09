/*
This sketch runs the added electronics for a small RV trailer
This new circuit running off the RV 12VDC battery will add:
  -12VDC circular power socket
  -2xUSB power sockets
  -RV battery voltmeter (checked with a momentary SPST switch)
  -This arduino
    -CO detector
    -smoke/propane detector
    -gas alarm LEDs and buzzer
    -photoresist night light
    -ceiling vent fan (12v, powered by switching relay)

  This entire panel will be subject to a master 3PST switch
    3P = 12V/usb power, arduino power (via DC converter), 12V to relay for fan.

  If either gas sensor reads above a threshold value: a unique LED will light,
    the buzzer will sound, and the ceiling fan will activate.
  
 Analog inputs:
  photoresistor
  MQ-2 (smoke/propane)
  MQ-7 (CO)
  
 
 Digital Outputs:
  LED - nightlight (PWM)
  LED - smoke/propane alarm
  LED - CO alarm
  buzzer - gas alarm (PWM)
  relay - fan activation
  switch - manual fan activation
 
  */

const int COgaspin = A0;
const int smokepin = A1;
const int photoresistpin = A2;

const int nightlightLED = 3;
const int CO_LEDpin = 4;
const int smokeLEDpin = 2;
const int alarmbuzz = 5;
const int fanswitch = 6;
const int fanrelay = 7;





void setup() {
  pinMode(COgaspin,INPUT);
  pinMode(smokepin,INPUT);
  pinMode(photoresistpin,INPUT);
  pinMode(smokeLEDpin,OUTPUT);
  pinMode(nightlightLED,OUTPUT);
  pinMode(CO_LEDpin,OUTPUT);
  pinMode(alarmbuzz,OUTPUT);
  pinMode(fanswitch,INPUT);
  pinMode(fanrelay,OUTPUT);

}

void loop() {




}
