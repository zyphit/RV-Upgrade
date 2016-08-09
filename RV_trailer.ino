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
const int statusLED = 8;

int lightlevel, high = 0, low = 1023;


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
  pinMode(statusLED,OUTPUT);

// Shows user the system is running
  digitalWrite(statusLED,HIGH);
}

void loop() {

// CO sensor, if it reads a high value, it lights the CO LED, sounds the buzzer, and turns on the ceiling fan
if (analogRead(COgaspin) > 400) {
  digitalWrite(CO_LEDpin,HIGH);
  digitalWrite(fanrelay,HIGH);
  tone(alarmbuzz,500,500); // 500 Hz for 500 ms, with 250 ms break
  delay(250);
  }

// smoke sensor, if it reads a high value, it lights the smoke LED, sounds the buzzer, and turns on the ceiling fan
if (analogRead(smokepin) > 400) {
  digitalWrite(smokeLEDpin,HIGH);
  digitalWrite(fanrelay,HIGH);
  tone(alarmbuzz,1000,250); // 1000 Hz for 250ms, with 250 ms break
  delay(250);
  }

// manual switch-based fan control
if (digitalRead(fanswitch) == HIGH) {
  digitalWrite(fanrelay,HIGH);
  }

// turns off all LEDs, buzzers, and switches during normal conditions
if ((digitalRead(fanswitch) == LOW) && (analogRead(smokepin) < 400) && (analogRead(COgaspin) < 400)) {
  digitalWrite(fanrelay,LOW);
  digitalWrite(alarmbuzz,LOW);
  digitalWrite(smokeLEDpin,LOW);
  digitalWrite(CO_LEDpin,LOW);
  }

//photoresist nightlight, shines brightest in low-light conditions.
lightlevel = analogRead(photoresistpin);
lightlevel = map(lightlevel, 0, 1023, 0, 255);
lightlevel = constrain(lightlevel, 0, 255);
analogWrite(nightlightLED,lightlevel);


}







