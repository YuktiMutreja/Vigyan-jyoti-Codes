int pinValue = A0; //Analog pin from LDR
int ledPin=16; //Digital Pin to LED
int ldrValue;
int map_ldrValue;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600); //Set communication speed
pinMode(pinValue,INPUT);
pinMode(ledPin,OUTPUT);                       
}

void loop() {
int ldrValue=analogRead(pinValue); //Get analog value from LDR
  
Serial.print(ldrValue);//print the value to the Serial Monitor and Plotter
  
map_ldrValue=map(ldrValue,0,1023,0,255); //Map the values

Serial.print(",");
Serial.println(map_ldrValue); //print mapped value on Serial monitor
 
analogWrite(ledPin,map_ldrValue); 
//Output to LED
}
