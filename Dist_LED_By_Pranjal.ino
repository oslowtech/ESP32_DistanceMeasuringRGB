const int trigPin = 5;
const int echoPin = 18;

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
#define PIN_RED    21 
#define PIN_GREEN  22 
#define PIN_BLUE   23 

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED/2;
  if (distanceCm>=0 && distanceCm<=10)
  {
    analogWrite(PIN_RED,   255);
    analogWrite(PIN_GREEN, 102);
    analogWrite(PIN_BLUE,  178);
  }
   else if (distanceCm>10 && distanceCm<=20)
  {
    analogWrite(PIN_RED,   255);
    analogWrite(PIN_GREEN, 102);
    analogWrite(PIN_BLUE,  255);
  }
  else if (distanceCm>20 && distanceCm<=30)
  {
    analogWrite(PIN_RED,   178);
    analogWrite(PIN_GREEN, 102);
    analogWrite(PIN_BLUE,  255);
  }
  else if (distanceCm>30 && distanceCm<=40)
  {
    analogWrite(PIN_RED,   102);
    analogWrite(PIN_GREEN, 102);
    analogWrite(PIN_BLUE,  255);
  }
  else if (distanceCm>40 && distanceCm<=50)
  {
    analogWrite(PIN_RED,   102);
    analogWrite(PIN_GREEN, 178);
    analogWrite(PIN_BLUE,  255);
  }
  else if (distanceCm>50 && distanceCm<=60)
  {
    analogWrite(PIN_RED,   102);
    analogWrite(PIN_GREEN, 255);
    analogWrite(PIN_BLUE,  255);
  }
  else if (distanceCm>60 && distanceCm<=70)
  {
    analogWrite(PIN_RED,   102);
    analogWrite(PIN_GREEN, 255);
    analogWrite(PIN_BLUE,  178);
  }
  else if (distanceCm>70 && distanceCm<=80)
  {
    analogWrite(PIN_RED,   102);
    analogWrite(PIN_GREEN, 255);
    analogWrite(PIN_BLUE,  102);
  }
  else if (distanceCm>80 && distanceCm<=90)
  {
    analogWrite(PIN_RED,   178);
    analogWrite(PIN_GREEN, 255);
    analogWrite(PIN_BLUE,  102);
  }
  else if (distanceCm>90 && distanceCm<=100)
  {
    analogWrite(PIN_RED,   255);
    analogWrite(PIN_GREEN, 255);
    analogWrite(PIN_BLUE,  102);
  }
  
  else if (distanceCm>=100)
  {
    analogWrite(PIN_RED,   255);
    analogWrite(PIN_GREEN, 102);
    analogWrite(PIN_BLUE,  102);
  }
  else
  {
    analogWrite(PIN_RED,   225);
    analogWrite(PIN_GREEN, 225);
    analogWrite(PIN_BLUE,  255);
  }
  distanceInch = distanceCm * CM_TO_INCH;
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  
  delay(100);
}