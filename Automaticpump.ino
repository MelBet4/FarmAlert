int sensor = A0; //soil moisture sensor
int sensorVal; //soil moisture value
int delayTime = 1000;
int pump = 3; //pin connected to water pump
int red = 4; //red led, visual rep of need for water
int green = 5; //green led, visual rep of watered plant

void setup() {
  Serial.begin(9600); //activate serial monitor
  pinMode(sensor, INPUT); //soil moisture sensor is used for input
}

void loop() {
  sensorVal = analogRead(sensor);
  sensorVal = map(sensorVal, 500, 10, 0, 100);
  Serial.print("Moisture: ");
  Serial.print(sensorVal);
  Serial.println("%");
  delay(delayTime);

  if(sensorVal < 50 ){
    digitalWrite(pump, HIGH); //pump automatically waters plant since moisture level is <50%
    digitalWrite(red, HIGH); //red led lights up
    digitalWrite(green, LOW);
    delay(delayTime);
  }
  
  else{
    digitalWrite(pump, LOW); //optimum moisture level is attained, pumps automatically switches off
    digitalWrite(green, HIGH); //green led lights up
    digitalWrite(red, LOW);
    delay(delayTime);
  }

}
