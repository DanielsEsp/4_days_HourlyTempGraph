


#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "SPI.h"
#include "TFT_eSPI.h"
#include "U8g2_for_TFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();                  // tft instance
               U8g2_for_TFT_eSPI u8f;       // U8g2 font instance
#define     TFT_LED 33

const char* ssid = "Bbox-E295749E-2,4GHz";
const char* password = "Mb&2427242711";
                     
      int jour, heures, place, newPlace;
   String tempHeuresTXT, periodeJour;
    float tempHeures, tempTitreMin, tempDatas[4][24];
     bool decalePlace;
     

void setup() {

     Serial.begin(115200); Serial.println(); Serial.println();

     WiFi.begin(ssid, password);
     Serial.print("Connecting");
     while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
           }
     Serial.print("\nConnected to Wi-Fi network with IP Address: ");
     Serial.println(WiFi.localIP()); Serial.println(); Serial.println();

     Serial.println(); Serial.println();

     datas_load();
     for (jour = 0; jour < 4; jour ++) {          
          for (heures = 0; heures < 24; heures ++) {
               Serial.print(" A "); Serial.print(heures);
               Serial.print(" heures temperature de ");
               Serial.print(tempDatas[jour][heures]); Serial.println(" degres");
              }
          Serial.println();         
         }
        
     pinMode(TFT_LED, OUTPUT);
     digitalWrite(TFT_LED, HIGH);

     tft.begin();
     u8f.begin(tft);        
     tft.setRotation(1);
     tft.fillScreen(TFT_BLACK);
     u8f.setForegroundColor(TFT_WHITE);
 
}


void loop() {
     
     for (jour = 0; jour < 4; jour ++) {
          grille_base();
          place_point(); 
          delay(9999);               
         }

}


//
