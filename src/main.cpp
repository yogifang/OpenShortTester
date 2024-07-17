#include <Arduino.h>
#include <stdio.h>

const int analogPin0 = A0;
const int analogPin1 = A1;
const int analogPin2 = A2;
const int analogPin3 = A3;

const int ledError0 = 4;
const int ledError1 = 5;
const int ledError2 = 6;
const int ledError3 = 7;

const int led0 = 2;
const int led1 = 3;

// put function declarations here:

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println("Hello World");
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(analogPin0, INPUT);
  pinMode(analogPin1, INPUT);
  pinMode(analogPin2, INPUT);
  pinMode(analogPin3, INPUT);
  pinMode(ledError0, OUTPUT);
  pinMode(ledError1, OUTPUT);
  pinMode(ledError2, OUTPUT);
  pinMode(ledError3, OUTPUT);

  // put your setup code here, to run once:
}

void loop()
{
  // put your main code here, to run repeatedly:
  int sensorValue0 = analogRead(analogPin0) & 0x3F0;
  int sensorValue1 = analogRead(analogPin1) & 0x3F0;
  int sensorValue2 = analogRead(analogPin2) & 0x3F0;
  int sensorValue3 = analogRead(analogPin3) & 0x3F0;

  bool bErros = false;

  if (sensorValue0 == sensorValue1)
  {
    digitalWrite(ledError0, HIGH);
    digitalWrite(ledError1, HIGH);
    bErros = true;
  }
  if (sensorValue0 == sensorValue2)
  {
    digitalWrite(ledError0, HIGH);
    digitalWrite(ledError2, HIGH);
    bErros = true;
  }
  if (sensorValue0 == sensorValue3)
  {
    digitalWrite(ledError0, HIGH);
    digitalWrite(ledError3, HIGH);
    bErros = true;
  }
  if (sensorValue1 == sensorValue2)
  {
    digitalWrite(ledError1, HIGH);
    digitalWrite(ledError2, HIGH);
    bErros = true;
  }
  if (sensorValue1 == sensorValue3)
  {
    digitalWrite(ledError1, HIGH);
    digitalWrite(ledError3, HIGH);
    bErros = true;
  }
  if (sensorValue2 == sensorValue3)
  {
    digitalWrite(ledError2, HIGH);
    digitalWrite(ledError3, HIGH);
    bErros = true;
  }

  if (!bErros)
  {
    digitalWrite(ledError0, LOW);
    digitalWrite(ledError1, LOW);
    digitalWrite(ledError2, LOW);
    digitalWrite(ledError3, LOW);
    digitalWrite(led0, HIGH);
  }
  else
  {
    digitalWrite(led0, LOW);
  }
  digitalWrite(led1, digitalRead(led1) ^ 1);
  Serial.print("sensor 0 = ");
  Serial.println(sensorValue0);
  Serial.print("sensor 1 = ");
  Serial.println(sensorValue1);
  Serial.print("sensor 2 = ");
  Serial.println(sensorValue2);
  Serial.print("sensor 3 = ");
  Serial.println(sensorValue3);
  delay(200);
}
