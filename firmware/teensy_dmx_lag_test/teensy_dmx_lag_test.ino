/*
 * Need TeensyDMX Library
 */

#include <TeensyDMX.h>
namespace teensydmx = ::qindesign::teensydmx;

// Create the DMX sender on Serial1.
teensydmx::Sender dmxTx{Serial2};

// Data for 5 channels.
uint8_t data[5]{0, 0, 0, 0, 0};

// timer
unsigned long now = millis();
unsigned long prev = millis();
unsigned long LEDvalue = 0;
unsigned long tcall = millis();
int incomingByte;
int light_state =0;
int dur =1000;
void setup() {
  
  
  // Turn on the LED, for indicating activity
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWriteFast(LED_BUILTIN, HIGH);
  Serial.begin(19200);
  // Set channels 1-5 to the 5 values in 'data'
  dmxTx.set(1, data, 5);

  // Set a single channel, 1, to 0
  dmxTx.set(1, 0);

  // start dmx controller
  dmxTx.begin();
}

void loop() {
  // look for a serial signal
  if (Serial.available()){
    incomingByte = Serial.read();
  }
  
  //if that signal has arrived turn on the LEDs for one second
  if (incomingByte=='a' and light_state ==0) {
    
        LEDvalue = 250;
        tcall = millis();

      uint8_t data[5]{LEDvalue, LEDvalue, LEDvalue, LEDvalue}; // << there is definitely a faster / more correct way to do that but I could not remember the syntax!
      dmxTx.set(1, data, 5);
      incomingByte=' ';
      light_state =1;
  }
  if (light_state ==1 and millis() > tcall+dur){
    LEDvalue = 0;
    uint8_t data[5]{LEDvalue, LEDvalue, LEDvalue, LEDvalue}; 
    light_state=0;
    dmxTx.set(1, data, 5);
     
    }
  }
