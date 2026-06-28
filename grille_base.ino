


void grille_base() {

     tft.fillScreen(TFT_BLACK);
     u8f.setFont(u8g2_font_profont12_tf);
     u8f.setCursor(0, 320); u8f.setForegroundColor(TFT_NAVY); u8f.print("-20°");
     u8f.setCursor(0, 295); u8f.setForegroundColor(TFT_BLUE); u8f.print("-15°");
     u8f.setCursor(0, 270); u8f.setForegroundColor(TFT_BLUE); u8f.print("-10°");
     u8f.setCursor(0, 245); u8f.setForegroundColor(TFT_CYAN); u8f.print("-5°");                    
     u8f.setCursor(0, 220); u8f.setForegroundColor(TFT_CYAN); u8f.print(" 0°");
     u8f.setCursor(0, 195); u8f.setForegroundColor(TFT_CYAN); u8f.print(" 5°");
     u8f.setCursor(0, 170); u8f.setForegroundColor(TFT_GREEN); u8f.print("10°");
     u8f.setCursor(0, 145); u8f.setForegroundColor(TFT_GREEN); u8f.print("15°");                    
     u8f.setCursor(0, 120); u8f.setForegroundColor(TFT_GREEN); u8f.print("20°");
     u8f.setCursor(0, 95); u8f.setForegroundColor(TFT_YELLOW); u8f.print("25°");
     u8f.setCursor(0, 70); u8f.setForegroundColor(TFT_ORANGE); u8f.print("30°");
     u8f.setCursor(0, 45); u8f.setForegroundColor(TFT_RED); u8f.print("35°");                    
     u8f.setCursor(0, 20); u8f.setForegroundColor(TFT_PURPLE); u8f.print("40°"); 
     
}


//
