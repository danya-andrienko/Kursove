#define PIN_LED 12
int8_t conPin1 = 5;
int8_t conPin2 = 7;
int8_t conPin3 = 4;
int ligh;
String command;
void setup() {
  Serial.begin(9600);
      pinMode(7, INPUT_PULLUP); 
     pinMode(4, INPUT_PULLUP);
     pinMode(5, INPUT_PULLUP);
    pinMode(10, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
}
void loop() {
  Serial.print(digitalRead(conPin1));
  Serial.print(",");
  Serial.print(digitalRead(conPin2));
  Serial.print(",");
  Serial.print(digitalRead(conPin3));
   Serial.print(",");
    Serial.print(digitalRead(10));
     Serial.print(",");
  Serial.println(ligh);
  Serial.println("");
   if(Serial.available()){
    command = Serial.readStringUntil('_');
       if(command.equals("HOLOD")){
                 digitalWrite(13, LOW);
      }
      else if(command.equals("TEPLO")){
         digitalWrite(13, HIGH);
              }  
       if(command.equals("SIREN")){
         digitalWrite(10, HIGH);
         
      }
      else if(command.equals("KVIT")){
         digitalWrite(10, LOW);
         
      }
      if(command.equals("ONLH")){
                 digitalWrite(12, HIGH);
                 ligh = 1;
  }
  else if(command.equals("OFFLH")){
    digitalWrite(12,LOW);
    ligh = 0;
  }
  }
   delay(2000); 
    }
  
 
  
 
   
  
