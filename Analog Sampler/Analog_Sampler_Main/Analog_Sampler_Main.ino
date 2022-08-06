/*
 * This project uses a 500K pot and appears to be a good range for a tempo pot.
 * off-board LED can be used as visual indicator of BPM.
 */





int potPin = A3;    //Pot middle wiper connected to analog A3. pot top is wired to +5, bottom to GND
int ledPin = 9;     //output pin for external LED
int speakerPin = 7; //output pin for speaker.
int buttonPin = 13; //input pin for button signal

int potVal = 0;     //stored Pot value
int ledVal = 255;   //value for the LED brightness. 0-255
int buttonStat = 0; //off/on status of button. one side of switch tie to gnd and other to buttonPin. when button is pressed, stat will go to 0




void setup() {
  pinMode(LED_BUILTIN, OUTPUT);         //on board LED enable
  pinMode(ledPin, OUTPUT);              //external LED enable
  pinMode(speakerPin, OUTPUT);          //speaker high value. speaker other wire wired to GND
  pinMode(buttonPin, INPUT);            //button input. to kill LED output
  Serial.begin(9600);                   //initialize Serial port to 9600. Open Tools > Serial Monitor to view output
  
}

// the loop function runs over and over again forever
void loop() {
/*
 * turn on-board and off-board LEDs on.
 * update potValue by reading the pot wiper value. will be value 0-1023 as wiper voltage goes to 5+
 * write new potVal to serial port 
 * wait for potVal milliseconds
 * turn on-board and off-board LEDs off
 * wait for potVal milliseconds
 */

  
  digitalWrite(LED_BUILTIN, HIGH);      // turn the LED on (HIGH is the voltage level)
  //button is normally high so disable LED and speaker output when pressed
  if(buttonStat){
    analogWrite(ledPin, ledVal);          //turn LED on
    analogWrite(speakerPin, ledVal);      //enable speaker output on  
  }
  potVal = analogRead(potPin);          // Read the potPin value
  buttonStat = digitalRead(buttonPin);  // Read and store buttonStat
  //Serial.println(potVal);
  //Serial.println(buttonStat);
  delay(potVal);                        // wait
  digitalWrite(LED_BUILTIN, LOW);       // turn the LED off by making the voltage LOW
  analogWrite(ledPin, LOW);             //turn LED off
  analogWrite(speakerPin, LOW);         //enable speaker output off
  delay(potVal);                        // wait
}
