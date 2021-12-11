/*
  LDR Sensor with Arduino
*/


int sensorValue1=0;
int sensorValue2=0;
int counter=0;
const int buzzer=13;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
   sensorValue1 = analogRead(A0);
   sensorValue2 = analogRead(A1);
   //int ledValue1=analogRead(10);
  //int ledValue2=analogRead(ledPin2);
  Serial.print("sensor value 1: ");
  Serial.println(sensorValue1);
  Serial.print("sensor value 2: ");
  Serial.println(sensorValue2);
  Serial.print("the counter is: ");
  Serial.println(counter);

  analogWrite(10,map(sensorValue1,0,1023,0,255));
  delay(1000);
  analogWrite(9,map(sensorValue2,0,1023,0,255));
  delay(1000);
  if(sensorValue1>0 && sensorValue1<=100){
    counter++;
    
  }
  if(sensorValue2>0 && sensorValue2<=100){
    counter--;
  }
  if(counter > 5){
    tone(buzzer,1000);
    delay(1000);
    noTone(buzzer);
    delay(1000);
    tone(buzzer,1000);
    delay(1000);
    noTone(buzzer);
    delay(1000);
  }
  noTone(buzzer);
  if(counter <=0 ){
    counter=0;
  }
}
