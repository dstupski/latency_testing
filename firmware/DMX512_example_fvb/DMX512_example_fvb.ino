/*
 * Need TeensyDMX Library
 */

#include <TeensyDMX.h>
namespace teensydmx = ::qindesign::teensydmx;

// Create the DMX sender on Serial1.
teensydmx::Sender dmxTx{Serial2};

// Data for 5 channels.
uint8_t data[5]{128, 128, 128, 128, 128};

// timer
unsigned long now = millis();
unsigned long prev = millis();
unsigned long LEDvalue = 0;

void setup() {
  // Turn on the LED, for indicating activity
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWriteFast(LED_BUILTIN, HIGH);

  // Set channels 1-5 to the 5 values in 'data'
  dmxTx.set(1, data, 5);

  // Set a single channel, 1, to 0
  dmxTx.set(1, 0);

  // start dmx controller
  dmxTx.begin();
}

void loop() {
  // every 100 ms turn on and off all the channels
  
  if (1) {
    now = millis();
    if (now > prev + 100){
      if (LEDvalue > 200) {
        LEDvalue = 0;
      }
      else {
        LEDvalue = 250;
      }

      uint8_t data[5]{LEDvalue, LEDvalue, LEDvalue, LEDvalue}; // << there is definitely a faster / more correct way to do that but I could not remember the syntax!
      dmxTx.set(1, data, 5);
      prev = millis();
    }
  }
}
