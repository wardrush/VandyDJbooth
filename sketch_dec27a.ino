int inputPin = 5;
int sensPin = 2;
int ledPin = 2;
int sensitivity;
int intensity;
int timer = 75;
bool prevState = false;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
intensity = analogRead(inputPin);
Serial.print(sensitivity);
Serial.print("\n");
sensitivity = analogRead(sensPin);
sensitivity = map(sensitivity, 370, 450, 0, 40);

if (intensity > sensitivity){
  digitalWrite(ledPin, HIGH);
  delay(timer);
  prevState = true;
  digitalWrite(ledPin, LOW);
}

delay(3*timer);
prevState = false;


}
