#include <Brain.h>
#include <ArduinoJson.h>

StaticJsonDocument<200> doc;

Brain brain(Serial);

void setup() {
  Serial.begin(9600);
  delay(10);

  

}

void loop() {
  if (brain.update()) {
    
    if(brain.readSignalQuality() <= 60){

      uint32_t * a = brain.readPowerArray();
      int i;
      String s = "";
      for(i = 0; i < 8 ; i++){
        s += ((float) a[i] / 10000);
       
        if(i == 0) {
          doc["delta"] = ((float) a[i] / 10000);
        }
        if(i == 1) {
          doc["theta"] = ((float) a[i] / 10000);
        }
        if(i == 2) {
          doc["low alpha"] = ((float) a[i] / 10000);
        }
        if(i == 3) {
          doc["high alpha"] = ((float) a[i] / 10000);
        }
        if(i == 4) {
          doc["low beta"] = ((float) a[i] / 10000);
        }
        if(i == 5) {
          doc["high beta"] = ((float) a[i] / 10000);
        }
        if(i == 6) {
          doc["low gamma"] = ((float) a[i] / 10000);
        }
        if(i == 7) {
          doc["high gamma"] = ((float) a[i] / 10000);
        }


       Serial.println();
      }

      //Serial.println(s);
      serializeJsonPretty(doc, Serial);

      // Serial.println(brain.readCSV()); 
    }
  }
}