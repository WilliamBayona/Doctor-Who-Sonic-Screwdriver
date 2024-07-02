#define outputPin 13
#define ledPin 12  // Define el pin del LED
byte count;

int touchSensorPin = 2;  // Connect Touch sensor on Digital Pin 2

void setup()
{
  pinMode(outputPin, OUTPUT);    // Set outputPin to output mode
  pinMode(ledPin, OUTPUT);       // Set ledPin to output mode
  pinMode(touchSensorPin, INPUT);  // Set touchSensorPin to input mode
}

void loop()
{
  if (digitalRead(touchSensorPin) == HIGH)  // Read Touch sensor signal
  {
    count++;
    if (count < 5)
    {
      tone(outputPin, 1471);
      delay(10);
      tone(outputPin, 1575);
      delay(5);
    }
    else
    {
      tone(outputPin, 1470);
      delay(10);
      tone(outputPin, 1575);
      delay(5);
      if (count > 10)
      {
        count = 0;
      }
    }
    
    // Hacer que el LED parpadee rápidamente
    digitalWrite(ledPin, HIGH);
    delay(100);  // Ajusta este valor para cambiar la velocidad de parpadeo
    digitalWrite(ledPin, LOW);
    delay(100);  // Ajusta este valor para cambiar la velocidad de parpadeo
  }
  else
  {
    noTone(outputPin);  // Stop the tone when the touch sensor is not touched
    count = 0;          // Reset count when the sensor is not touched
    
    // Asegurarse de que el LED esté apagado cuando el sensor no está siendo tocado
    digitalWrite(ledPin, LOW);
  }
}
