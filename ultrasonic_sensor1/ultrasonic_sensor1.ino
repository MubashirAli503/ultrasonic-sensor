
int echoPin=2;
int trigPin=3;
int red=4;
int green=5;
float duration;
float distance; 
void setup()
{
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin,LOW);
  delay(100);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  if(distance <10)
  {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  }
  else if (distance>20)
  {
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
  }
  else
  { digitalWrite(green,LOW);
    digitalWrite(red,LOW);
  }
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");
}
