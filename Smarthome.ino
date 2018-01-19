int sensorPin = A0;
int sensorValue = 0; 
int outValue=0;
int pirPin=4;
int ledPin=3;
void setup()
{

  pinMode(pirPin,INPUT);
  pinMode(ledPin,OUTPUT);
	// Turn on the blacklight and print a message.
	Serial.begin(9600);
}

void loop()
{
  static bool toggle=0;
  static int pirValue;
  pirValue=digitalRead(pirPin);
  Serial.print("Pir Status.");
  Serial.println(pirValue);
  sensorValue = analogRead(sensorPin);
  outValue= 255-map(sensorValue,0,1023,0,255);
  if(pirValue==1){
    toggle=!toggle;
    if(toggle==1){
       analogWrite(ledPin,outValue);
    }
    else{
      analogWrite(ledPin,0);
    }
    while(digitalRead(pirPin)==1);
  }
   if(toggle==1){
       analogWrite(ledPin,outValue);
   }
  delay(500);
}
