// constants won't change. Used here to set a pin number:
const int ledPin = 13;  // the number of the LED pin

// Variables will change:
int ledState = LOW;  // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
float stimulationFrequencyInHertz = 0.0; // Hertz
unsigned long pwmInterval;
void setup() 
{
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(100000);
  digitalWrite(ledPin, 0);
  while(0.0 == stimulationFrequencyInHertz)
  {

    Serial.print("\nPlease input your desired stimulation frequency in Hertz: ");
    stimulationFrequencyInHertz = Serial.parseFloat();
    Serial.print("\n");
    Serial.print("Received ");
    Serial.print(stimulationFrequencyInHertz);
    Serial.print("Hz \n");
    if(0.0 == stimulationFrequencyInHertz)
    {
      Serial.println("Cannot stimulate at frequency of 0. Please try again.");
    }
  }
  pwmInterval = int(((1.0/stimulationFrequencyInHertz) * 1000))/2;
  Serial.print("Will stimuate every ");
  Serial.print(pwmInterval*2);
  Serial.print(" milliseconds \n");
  Serial.println("Beginning stimulation at specified frequency");
}

void loop()
{
  unsigned long currentMillis = (millis());

  if (currentMillis - previousMillis >= pwmInterval) 
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }

}
