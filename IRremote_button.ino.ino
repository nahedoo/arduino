#include <Arduino.h>
#include"PinDefinitionsAndMore.h"
#include <IRremote.hpp>
#define DECODE_NEC
#define LED_BUILTIN 2

const byte ledPin = 2;       
const byte interruptPin = 0; 
volatile byte state = LOW;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println(F("START " _FILE_ " from "_DATE_"\r\nUsing library version " VERSION_IRREMOTE));
  IrSender.begin();
  Serial.print(F("Ready to send IR signals at Pin"));
  Serial.println(IR_SEND_PIN);
}

void loop() 
{
  digitalWrite(ledPin, state);
}

void blink() 
{
  state = !state;
}
