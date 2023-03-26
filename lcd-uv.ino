#include <LiquidCrystal.h>

LiquidCrystal lcd (8,9,4,5,6,7);

#define pinSensorUV    A5

char s [80];

void setup () {
    Serial.begin (9600);

    lcd.begin (16,2);
    lcd.setCursor (0,0);
    lcd.print ("INDICE ");
    lcd.setCursor (0,1);
    lcd.print ("UV :");
}

void loop ()
{
    int leituraUV = analogRead (pinSensorUV);     // read sensor
    int indiceUV  = map (leituraUV, 0,203,0,10);  // map from 0-10

    lcd.setCursor (8,1);
    lcd.print (indiceUV);

    sprintf (s, "leitura %4d, indice %3d", leituraUV, indiceUV);
    Serial.println (s);

    delay (500); // slow output
}
