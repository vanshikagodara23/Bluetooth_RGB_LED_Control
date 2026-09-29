// Aim: Operate RGB LED using Bluetooth

#include <SoftwareSerial.h>

// HC-05 Bluetooth
SoftwareSerial Bluetooth(10, 11);  // RX, TX

// RGB LED pins
const int redLED = 3;
const int greenLED = 5;
const int blueLED = 6;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  Bluetooth.begin(9600);
  Serial.begin(9600);

  turnOffLED();

  Serial.println("RGB Bluetooth Controller Ready");
}

void loop()
{
  if (Bluetooth.available())
  {
    char command = Bluetooth.read();

    Serial.println(command);

    switch(command)
    {
      case 'R':
      case 'r':
        setColor(255, 0, 0);        // Red
        break;

      case 'G':
      case 'g':
        setColor(0, 255, 0);        // Green
        break;

      case 'B':
      case 'b':
        setColor(0, 0, 255);        // Blue
        break;

      case 'Y':
      case 'y':
        setColor(255, 220, 0);      // Bright Yellow
        break;

      case 'W':
      case 'w':
        setColor(255, 255, 255);    // White
        break;

      case 'C':
      case 'c':
        setColor(0, 255, 255);      // Cyan
        break;

      case 'M':
      case 'm':
        setColor(255, 0, 255);      // Magenta
        break;

      case 'P':
      case 'p':
        setColor(255, 80, 150);     // Pink
        break;

      case 'A':
      case 'a':
        setColor(255, 100, 0);      // Orange
        break;

      case 'V':
      case 'v':
        setColor(150, 0, 255);      // Violet
        break;

      case 'L':
      case 'l':
        setColor(120, 255, 0);      // Lime
        break;

      case 'T':
      case 't':
        setColor(0, 200, 180);      // Turquoise
        break;

      case 'S':
      case 's':
        setColor(0, 150, 255);      // Sky Blue
        break;

      case 'F':
      case 'f':
        rainbow();
        break;

      case 'O':
      case 'o':
        turnOffLED();              // OFF
        break;
    }
  }
}


// RGB color control
void setColor(int red, int green, int blue)
{
  analogWrite(redLED, red);
  analogWrite(greenLED, green);
  analogWrite(blueLED, blue);
}


// Turn OFF LED
void turnOffLED()
{
  analogWrite(redLED, 0);
  analogWrite(greenLED, 0);
  analogWrite(blueLED, 0);
}


// Rainbow effect
void rainbow()
{
  setColor(255,0,0);       // Red
  delay(500);

  setColor(255,220,0);     // Yellow
  delay(500);

  setColor(0,255,0);       // Green
  delay(500);

  setColor(0,255,255);     // Cyan
  delay(500);

  setColor(0,0,255);       // Blue
  delay(500);

  setColor(255,0,255);     // Magenta
  delay(500);

  turnOffLED();
}
