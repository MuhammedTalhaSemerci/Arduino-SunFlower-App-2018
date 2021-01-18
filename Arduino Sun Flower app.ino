 #include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define x A0
#define y A1
#define z A2
#define m A3

LiquidCrystal_I2C lcd(0x3f , 16 , 2);



Servo servo;



int sayi  = 0;


int step1 = 4;
int step2 = 5;
int step3 = 6;
int step4 = 7;

void setup() {


Serial.begin(9600);
lcd.begin();
lcd.backlight();

servo.attach(3);


 
}

void loop() {

int ldrbilgi = analogRead(x);
int ldr1bilgi = analogRead(y);

int ldr2bilgi = analogRead(z);
int ldr3bilgi = analogRead(m);


 int ldr = map(ldrbilgi,0,1023,0,20000); 
 int ldr1 = map(ldr1bilgi,0,1023,0,20000);
        

int ldr2 = map(ldr2bilgi,0,1023,0,20000); 
 int ldr3 = map(ldr3bilgi,0,1023,0,20000);
      



if (ldr - ldr1 > 10 || ldr1 - ldr > 10 || ldr2 - ldr3 > 20 || ldr3 - ldr2 > 20 ){

        
        
        if (ldr > ldr1  &&  ldr - ldr1 > 10 ){


if(sayi < 160){ 
 
  servo.attach(3);

    
  sayi++;
  delay(5);
  servo.write(sayi);

  
}
  

else {


  sayi = 160;
  
  }

  }




         if (ldr1 > ldr&& ldr1 - ldr > 10  ){
 
if(sayi > 0) {

servo.attach(3);
   
    
  sayi--;
delay(5);
  servo.write(sayi);
 

}
else {
  

    
   sayi = 0 ;
  
  }

  
  }





if(ldr2 > ldr3 && ldr2 - ldr3 > 20 ){
  
  
            
  digitalWrite(step4,LOW);
digitalWrite(step1,HIGH);
delay (4);

digitalWrite(step1,LOW);
digitalWrite(step3,HIGH);

delay (4);

digitalWrite(step3,LOW);
digitalWrite(step2,HIGH);  

delay (4);

digitalWrite(step2,LOW);
digitalWrite(step4,HIGH);
delay (4);
          
       
  
  
  
  
  
  }







if(ldr3 > ldr2 && ldr3 - ldr2 > 20 ){
  
  
            
  digitalWrite(step1,LOW);
digitalWrite(step4,HIGH);
delay (4);

digitalWrite(step4,LOW);
digitalWrite(step2,HIGH);

delay (4);

digitalWrite(step2,LOW);
digitalWrite(step3,HIGH);  
delay (4);

digitalWrite(step3,LOW);
digitalWrite(step1,HIGH);
delay (4);
          
       
  
  
}
  
  
  }


  
 else { 



servo.detach();

             
digitalWrite(step1,LOW);
digitalWrite(step4,LOW);
digitalWrite(step4,LOW);
digitalWrite(step2,LOW);
digitalWrite(step2,LOW);
digitalWrite(step3,LOW);  
digitalWrite(step3,LOW);
digitalWrite(step1,LOW);

          
  
  
 }

















lcd.home();
lcd.print("ldr :");


lcd.setCursor(5,0);
lcd.print(ldr2);


lcd.setCursor(0,1);
lcd.print("ldr1:");

lcd.setCursor(5,1);
lcd.print(ldr3); 


lcd.setCursor(10,0);
lcd.print("aci:");


lcd.setCursor(11,1);
lcd.print(sayi);



delay(30);
lcd.clear();
  

}






















