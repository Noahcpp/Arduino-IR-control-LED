// Written by: Noahcpp
// This code is for controlling an LED with IR remote control

#include <IRremote.h>      //must copy IRremote library to arduino libraries
int on = 0; //Put the button's HEX value here
int off = 0; //Put the button's HEX value here

int RECV_PIN = 2;       //IR receiver pin

IRrecv irrecv(RECV_PIN);

decode_results results;

int LEDpin = 13;   //LED pin

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

  pinMode(LEDpin, OUTPUT);
}

void loop() 
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

    if (results.value == on)   //Check value
    {
      digitalWrite(LEDpin, HIGH);
    }

    else if (results.value == off)
    {
      digitalWrite(LEDpin, LOW);
    }
  }
}
