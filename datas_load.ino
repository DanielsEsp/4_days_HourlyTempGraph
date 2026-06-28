


void datas_load() {
  
     if (WiFi.status() == WL_CONNECTED) {
         HTTPClient http; 
         String url = String("https://prevision-meteo.ch/services/json/Ichtratzheim");    
  
         http.begin(url);
         int httpCode = http.GET(); 
         Serial.println(httpCode);
         if (httpCode > 0) {
             if (httpCode == HTTP_CODE_OK) {
                 String payload = http.getString();
                 StaticJsonDocument<1024> doc;
                 DeserializationError error = deserializeJson(doc, payload);

                 if (!error) {
                     for (jour = 0; jour < 4; jour ++) {
                          for (heures = 0; heures <= 23; heures ++) {
                               tempHeuresTXT = String(doc["fcst_day_" + String(jour)]["hourly_data"][String(heures) + "H00"]["TMP2m"]);
                               tempHeures = tempHeuresTXT.toFloat();
                               tempDatas[jour][heures] = tempHeures;
                              }
                         }                     
                    } else {
                     Serial.print("deserializeJson() failed: ");
                     Serial.println(error.c_str());
                    }

                }
           } else {
            Serial.printf("GET request failed, error: %s\n", http.errorToString(httpCode).c_str());
            delay(9999);
            Serial.printf("Reset !");           
            esp_restart(); delay(100);
           }
       http.end(); // Close connection
      } else {
       Serial.println("Not connected to Wi-Fi");
      }
  
}


//
