int potPin = A3;  //Pot output connected to analog A3
int potVal = 0;   //stored Pot value

//want to just display potVal in serial terminal...




void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  potVal = analogRead(potPin);        // Read the potPin value
  Serial.println(potVal);
  delay(potVal+5);                       // wait
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(potVal+5);                       // wait
}
