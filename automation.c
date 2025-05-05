#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

const int vibra1 = 3;
const int vibra2 = 2;

const int trigger1=13; 
const int echo1=10; 
const int trigger2=9; 
const int echo2=8; 
float dist1;
float dist2;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2); 
  lcd.clear();
  pinMode(vibra1,OUTPUT);
  pinMode(vibra2,OUTPUT);
  pinMode(trigger1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trigger2,OUTPUT);
  pinMode(echo2,INPUT);
}
void loop()
{
  digitalWrite(trigger1,LOW);
  digitalWrite(trigger2,LOW);
  delayMicroseconds(5);        
  digitalWrite(trigger1,HIGH); 
  digitalWrite(trigger2,HIGH);  

  delayMicroseconds(10);      
  digitalWrite(trigger1,LOW); 
  dist1=pulseIn(echo1,HIGH);   
  digitalWrite(trigger2,LOW); 
  dist2=pulseIn(echo2,HIGH); 
  dist1 = dist1/58.2;
  dist2 = dist2/58.2;

  
  if (dist1 >= 20.0 && dist2 >= 20.0 ){
    if ( dist2 >= 120.0){
      digitalWrite(vibra2,LOW);  
    } if (dist2 >=100.0 && dist2 < 120.0){
      digitalWrite(vibra2,HIGH);  
   	  delay(500);
      digitalWrite(vibra2,LOW);  
    } if (dist2 >=80.0 && dist2 < 100.0){
      digitalWrite(vibra2,HIGH);  
      delay(1000);
      digitalWrite(vibra2,LOW);
    } if (dist2 >=60.0 && dist2 < 80.0){
      digitalWrite(vibra2,HIGH);  
   	  delay(2000);
      digitalWrite(vibra2,LOW);
    } if (dist2 >=40.0 && dist2 < 60.0){
      digitalWrite(vibra2,HIGH);  
   	  delay(2500);
      digitalWrite(vibra2,LOW);
    } if (dist2 >=20.0 && dist2 < 40.0){
      digitalWrite(vibra2,HIGH);  
   	  delay(3000);
      digitalWrite(vibra2,LOW);
    } if (dist1 >=120.0){
      digitalWrite(vibra1,LOW);  
    } if (dist1 >=100.0 && dist1 < 120.0){
      digitalWrite(vibra1,HIGH);  
   	  delay(500);
      digitalWrite(vibra1,LOW);
    } if (dist1 >=80.0 && dist1 < 100.0){
      digitalWrite(vibra1,HIGH);  
      delay(1000);
      digitalWrite(vibra1,LOW);
    } if (dist1 >=60.0 && dist1 < 80.0){
      digitalWrite(vibra1,HIGH);  
   	  delay(2000);
      digitalWrite(vibra1,LOW);
    } if (dist1 >=40.0 && dist1 < 60.0){
      digitalWrite(vibra1,HIGH);  
   	  delay(2500);
      digitalWrite(vibra1,LOW);
    } if (dist1 >=20.0 && dist1 < 40.0){
      digitalWrite(vibra1,HIGH);  
   	  delay(3000);
      digitalWrite(vibra1,LOW);
    }
    
    lcd.setCursor(0,0);
    lcd.print("Dist.E: ");
    lcd.print(dist1);
    lcd.print(" cm");

    Serial.print("\ndistancia esquerda: ");
    Serial.print(dist1);

    lcd.setCursor(0,1);
    lcd.print("Dist.D: ");
    lcd.print(dist2);
    lcd.print(" cm");

    Serial.print("\ndistancia direita: ");
    Serial.print(dist2);
    
    delay(1000);
  } 	else if (dist1 < 20.0 && dist2 < 20.0){
    digitalWrite(vibra1,HIGH); 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("batida eminente");
    digitalWrite(vibra2,HIGH); 
    lcd.setCursor(0,1);
    lcd.print("batida eminente");
    delay(100);

  } else if (dist1 < 20.0 && dist2 >= 20.0){
    digitalWrite(vibra1,HIGH); 
    digitalWrite(vibra2,LOW); 

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("batida eminente");
    delay(100);

  } else if (dist1 >= 20.0 && dist2 < 20.0){
    digitalWrite(vibra2,HIGH);
    digitalWrite(vibra1,LOW); 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("batida eminente");
    delay(100);

  }

}
