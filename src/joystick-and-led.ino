#include <Servo.h>
Servo servo; 

int xPin = A1;
int yPin = A0;
int buttonPin = 2;
int xPosition = 0;
int yPosition = 0;
int buttonState = 0;
bool ledEnabled = false;

void setup() {
    servo.attach(10); 
  
    Serial.begin(9600);
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);

    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    xPosition = analogRead(xPin);
    yPosition = analogRead(yPin);
    buttonState = digitalRead(buttonPin);

    //Serial.print("X: ");
    //Serial.print(xPosition);
    //Serial.print(" | Y: ");
    //Serial.print(yPosition);
    //Serial.print(" | Button: ");
    //Serial.println(buttonState);

    if (yPosition >= 1023) {
        servo.write(0);
    }

    if (yPosition <= 1) {
        servo.write(180); 
    }

    if (xPosition >= 1021 || xPosition <= 2 || buttonState == 0) {
      ledEnabled = !ledEnabled;  
    }
    
    if (ledEnabled) {
        digitalWrite(LED_BUILTIN, HIGH);
    } else {
        digitalWrite(LED_BUILTIN, LOW);
    }

    delay(200); 
}
