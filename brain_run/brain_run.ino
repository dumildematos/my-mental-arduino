#include <Brain.h>

Brain brain(Serial);

void setup() {
  Serial.begin(9600);
  delay(10);
}

void loop() {
  if (brain.update()) {
    if(brain.readSignalQuality() <= 60){
       Serial.println(brain.readCSV()); 
    }
  }
}