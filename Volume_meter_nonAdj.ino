int pinArray[] = {2, 3, 4, 5, 6, 7};
int count = 0;
int timer = 8;
int sensorValue = 0;
int countmax;
int musicInput = 5;
int val = 0;
int statePin = LOW;
int THRESHOLD = 13;




void setup(){
  for (count=0;count<6;count++) {
    pinMode(pinArray[count], OUTPUT);
  }
  Serial.begin(9600);

}
void loop() {

  sensorValue = analogRead(musicInput);
  if (sensorValue < 1.5*THRESHOLD) {
  countmax=1;
}
  else if (sensorValue < (1.5*THRESHOLD)) {
  countmax = 2;
}
  else if (sensorValue < (2*THRESHOLD)) {
  countmax = 3;
}
  else if (sensorValue < (3*THRESHOLD)) {
  countmax = 4;
}
  else if (sensorValue < (5*THRESHOLD)) {
  countmax = 5;
}
  else if (sensorValue < (6*THRESHOLD)) {
  countmax = 6;
} 
  for (count=0;count <= countmax;count++) {
   digitalWrite(pinArray[count-1], HIGH);
   delay(2*timer);
  }
  for (count=6;count > countmax;count--) {
   digitalWrite(pinArray[count-1], LOW);
   delay(2*timer);
  }  
  delay(timer);
  
  Serial.print(sensorValue);
  Serial.print("\n");
 

  
}
