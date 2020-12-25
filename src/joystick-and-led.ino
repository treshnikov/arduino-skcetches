#include <Servo.h>
Servo servo; 

int xPin = A1;
int yPin = A0;
int buttonPin = 2;
int xPosition = 0;
int yPosition = 0;
int buttonState = 0;
bool ledEnabled = false;

void setup() 
{
    // control servo motor using port #10
    servo.attach(10); 
  
    Serial.begin(9600);
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);

    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
    xPosition = analogRead(xPin);
    yPosition = analogRead(yPin);
    buttonState = digitalRead(buttonPin);

    //logJoystickInfo();

    // control servo motor by joystick Y-axis
    if (yPosition >= 1020) {
        servo.write(0);
    } else
    if (yPosition <= 5) {
        servo.write(180); 
    }

    // control led by joystick X-axis and joystick button
    if (xPosition >= 1020 || xPosition <= 5 || buttonState == 0) {
      ledEnabled = !ledEnabled;  

        if (ledEnabled) {
            digitalWrite(LED_BUILTIN, HIGH);
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
    
    delay(200); 
}

void logJoystickInfo()
{
    Serial.print("X: ");
    Serial.print(xPosition);
    Serial.print(" | Y: ");
    Serial.print(yPosition);
    Serial.print(" | Button: ");
    Serial.println(buttonState);    
}
