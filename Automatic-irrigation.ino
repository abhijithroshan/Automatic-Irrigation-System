int RelayPin = 13;  
int sensorPin = 0;  
int val; 
void setup() { 
pinMode(13,OUTPUT);
pinMode(0,INPUT);
} 
void loop() {  
val = digitalRead(0);  
if(val == LOW) { 
digitalWrite(13,LOW); 
} 
else{ 
digitalWrite(13,HIGH);
}
}