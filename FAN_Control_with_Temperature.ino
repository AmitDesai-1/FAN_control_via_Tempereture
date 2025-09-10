void setup() {
  pinMode(13,OUTPUT);  //FAN
  Serial.begin(9600);
}

void loop() {
  int Value = analogRead(13); //read sensor
  float voltage = Value*(5.0/1023.0); //voltage
  float temperature = (5.0- voltage)*20;

  // Print Temperature
  Serial.print("Temperature = ");
  Serial.print(temperature);

  // FAN condition
  if (temperature < 25){
    digitalWrite(13,LOW);
    Serial.println("fan is off");
    }
  else if (temperature < 30 and temperature >= 25){
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
    Serial.println("fan is 50% on");
    }
  else{
    digitalWrite(13,HIGH);
    Serial.println("fan is on");
  }
  delay(500);
}