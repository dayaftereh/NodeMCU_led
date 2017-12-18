#include <FS.h>

void file_system_init(){
  if (!SPIFFS.begin()) {
    Serial.println("SPIFFS not initialized!");
    while (true)  {
      delay(1000);
    }
  }
}
