//ThingSpeak Write API Key : XT1L25ULOPSHQFO3
//Channel ID: 600078
int pinValue = D7; //Analog pin from LDR //Digital Pin to LED
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

#include <DHT.h>

const char* ssid = "KZO8X53BOq8AQwFiYUKTI";
const char* password = "123456789";
WiFiClient client;

unsigned long myChannelNumber = 600078;
const char * myWriteAPIKey = "XT1L25ULOPSHQFO3";

int light=0, val = 0;
//WiFiClient client;
#define DHTPIN D3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
uint8_t temperature, humidity;
int thresh=100;

void setup(){
 pinMode(pinValue,INPUT);
  Serial.begin(9600);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
// Print the IP address
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);

  dht.begin();
  delay(10);
  Serial.println();
  Serial.println();
  pinMode(D7,INPUT);//LDR for testing ambient sunlight
  pinMode(D5,OUTPUT);//RGB
  pinMode(D6,OUTPUT);//RGB
  pinMode(D8,OUTPUT);//IN PIN of Relay
  digitalWrite(D8,HIGH);
  delay(2000);
}
void loop(){
   val=analogRead(A0);
  if(val>thresh)
  {
    Serial.println("LOW MOISTURE! - Please water the soil");
    digitalWrite(D5,HIGH);//RGB
    digitalWrite(D6,LOW);//RGB
    digitalWrite(D8,LOW);//Give LOW to Relay to start the pump
  }
  else{
   Serial.println("Moisture OK");
   digitalWrite(D5,LOW);
   digitalWrite(D6,HIGH);
   digitalWrite(D8,HIGH);
   //Give HIGH to Relay to stop the pump
  } 
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  delay(500);
  Serial.print("Temperature Value is :");
  Serial.print(temperature);
  Serial.print("C");
  Serial.print("  Humidity Value is :");
  Serial.print(humidity);
  Serial.println("%");
  delay(500);
  if(digitalRead(pinValue==LOW))
  Serial.println("AMBIENT LIGHT ");
  else
  Serial.println("POOR SUNLIGHT");
  
ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
Serial.println("Channel 1 transmitted");
ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);
Serial.println("Channel 2 transmitted");
ThingSpeak.writeField(myChannelNumber, 3, light , myWriteAPIKey);
Serial.println("Channel 3 transmitted");
ThingSpeak.writeField(myChannelNumber, 4, val, myWriteAPIKey);
Serial.println("Channel 4 transmitted");
delay(20000);
}
