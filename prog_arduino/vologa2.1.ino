#include <DHT.h>
#define PIN_LED 11
#define PIN_PHOTO_SENSOR A1
//Constants
#define DHTPIN 2     
#define DHTTYPE DHT11   

int outputValue = A2;
int Value = 0;

String command;

DHT dht(DHTPIN, DHT11);



int chk;
float hum;  
float temp; 


void setup()
{
    Serial.begin(9600);
    dht.begin();
    pinMode(outputValue, INPUT_PULLUP);
         
  }
int light; 

String hum1;
String temp1;

void loop(){
    delay(2000);  
       
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    hum1 = String(hum);
    temp1 = String(temp);
  
   
   
    
    
  int val = analogRead(PIN_PHOTO_SENSOR);
if(Serial.available()){
    command = Serial.readStringUntil('_');
     if(command.equals("ON")){
      digitalWrite(10, HIGH);
    light = 1;
  }
    else if(command.equals("OFF")){
    light = 0;
    digitalWrite(10, LOW);
  }  
     
  else if(command.equals("ONLD")){
                 digitalWrite(10, HIGH);
                 light = 1;
  }
  else if(command.equals("OFFLD")){
    digitalWrite(10,LOW);
    light = 0;
  }
  }

  Value = map(analogRead(outputValue), 0, 1023, -80, 110);
  
  Serial.print(hum1);
    Serial.print(",");
    Serial.print(temp1);
    Serial.print(",");
  Serial.print(light);
   Serial.print(",");
       Serial.print(Value);
    Serial.print(",");
    Serial.println(analogRead(1));
}    
