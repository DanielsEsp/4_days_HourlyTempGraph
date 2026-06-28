


void place_point() {

     tempTitreMin = 45;
     place = 10;      
     for (heures = 0; heures < 24; heures ++) { 
          u8f.setFont(u8g2_font_5x7_tf);
          if (tempDatas[jour][heures] > 35) { 
              u8f.setForegroundColor(TFT_PURPLE);
              tft.fillCircle(place, (200 - (tempDatas[jour][heures] * 4.5)), 2, TFT_PURPLE);
             }  
          if (tempDatas[jour][heures] <= 35) { 
              u8f.setForegroundColor(TFT_RED); 
              tft.fillCircle(place, (200 - (tempDatas[jour][heures] * 4.5)), 2, TFT_RED);
             }                
          if (tempDatas[jour][heures] <= 30) { 
              u8f.setForegroundColor(TFT_ORANGE); 
              tft.fillCircle(place, (200 - (tempDatas[jour][heures] * 4.5)), 2, TFT_ORANGE);
             } 
          if (tempDatas[jour][heures] <= 25) {
              u8f.setForegroundColor(TFT_YELLOW); 
              tft.fillCircle(place, (200 - (tempDatas[jour][heures] * 4.5)), 2, TFT_YELLOW);
             }           
          if (tempDatas[jour][heures] <= 20) { 
              u8f.setForegroundColor(TFT_GREEN); 
              tft.fillCircle(place, (200 - (tempDatas[jour][heures] * 4.5)), 2, TFT_GREEN);
             }     
          if (tempDatas[jour][heures] <= 5) {
              u8f.setForegroundColor(TFT_CYAN); 
              tft.fillCircle(place, (200 - (tempDatas[jour][heures] * 4.5)), 2, TFT_CYAN);
             }        
          if (tempDatas[jour][heures] <= -10) {
              u8f.setForegroundColor(TFT_BLUE); 
              tft.fillCircle(place, (200 - (tempDatas[jour][heures] * 4.5)), 2, TFT_BLUE);
             }   
          if (tempDatas[jour][heures] <= 15) {
              u8f.setForegroundColor(TFT_NAVY); 
              tft.fillCircle(place, (200 - (tempDatas[jour][heures] * 4.5)), 2, TFT_NAVY);
             }   
          decalePlace = !decalePlace;
          if (decalePlace == 0 ) { newPlace = (215 - (tempDatas[jour][heures]*4.5)); } else { newPlace = (190 - (tempDatas[jour][heures]*4.5)); }   
          u8f.setCursor(place - 10, newPlace);
          tempHeures = tempDatas[jour][heures];
          u8f.print(tempHeures, 1);
          u8f.setFont(u8g2_font_profont12_tf);
          u8f.setCursor(place - 2, 315); u8f.print(heures);          
          place = place + 20;           

          if (jour == 0) { periodeJour = "Température par heures du jour"; }
          if (jour == 1) { periodeJour = "Température par heures pour demain"; }
          if (jour == 2) { periodeJour = "Température par heures dans 2 jours"; }
          if (jour == 3) { periodeJour = "Température par heures dans 3 jours"; }
// Pour placer " Periode jour au bas de l'ecran "si les temperatures sont > 0               
          if (tempDatas[jour][heures] < tempTitreMin) { tempTitreMin = tempDatas[jour][heures]; }
          if (tempTitreMin > 0) {
              u8f.setFont(u8g2_font_helvR18_tf);
              u8f.setForegroundColor(TFT_DARKGREY);
              u8f.setCursor(70, 260); u8f.print(periodeJour);             
             }
         }
   
}


//
