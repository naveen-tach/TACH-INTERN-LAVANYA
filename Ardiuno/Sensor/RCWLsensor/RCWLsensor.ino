
#include<time.h>
int sensor = 2;
int LED =3;
int aux = 0;
void setup() {
  Serial.begin(115200);
  pinMode(sensor,INPUT);
  
} 

void loop() {
  int detect = digitalRead(sensor);
  if((detect>0) && aux==0){
    
    digitalWrite(LED,HIGH);
    Serial.println("LED glown as motion detected");
    aux=1; 
  }
  if(detect ==0){
    digitalWrite(LED,LOW);
   Serial.println("LED off as there is no motion");
    aux=0;
  }

}
