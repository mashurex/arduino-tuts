/**
 * Author: Mustafa Ashurex <mustafa@ashurex.com>
 * 
 * Cycles through three different LEDs when the digital button is pushed.
 * Created: 02-Feb 2014
 */

const int buttonPin = 2;
const int GreenLEDPin = 3;
const int YellowLEDPin = 4;
const int RedLEDPin = 5;

int pressCounter = 0;
int litLED = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(GreenLEDPin, OUTPUT);
  pinMode(YellowLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
}

void toggleLED(int LEDPin){ digitalWrite(LEDPin, !digitalRead(LEDPin)); }

int incrementLED(int litLED)
{
  litLED++;
  if(litLED > RedLEDPin){ litLED = (GreenLEDPin - 1); }
  else if(litLED < GreenLEDPin){ litLED = GreenLEDPin; }
 
  digitalWrite(RedLEDPin, LOW);
  digitalWrite(YellowLEDPin, LOW);
  digitalWrite(GreenLEDPin, LOW);
  
  if((litLED >= GreenLEDPin)&&(litLED <= RedLEDPin))
  {  
    digitalWrite(litLED, HIGH);
  }
  
  return litLED;
}

void loop()
{
  int button = digitalRead(buttonPin);
  
  if(button == LOW)
  {
    pressCounter++;
    Serial.print("Total presses: ");
    Serial.println(pressCounter);
    
    litLED = incrementLED(litLED);
    Serial.print("Lit led pin: ");
    Serial.println(litLED);
    
    delay(250);  
  }
}
