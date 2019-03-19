#define ledpin 9
int threshold = 3;
int volume;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  volume=analogRead(A0);
  Serial.println(volume);
  delay(500);
  if(volume>=threshold)
  {
    digitalWrite(ledpin,HIGH);
  }
  else
  {
    digitalWrite(ledpin,LOW);
  }
  // put your main code here, to run repeatedly:

}
