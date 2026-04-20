#include <Servo.h>

// Creamos los objetos para los servomotores
Servo servoBase;  // Pin 7
Servo servoBrazo; // Pin 6

void setup() {
  // Configuramos los pines de control de los servos
  servoBase.attach(7);
  servoBrazo.attach(6);
  
  // Posición inicial de seguridad (al centro)
  servoBase.write(90);
  servoBrazo.write(90);
}

void loop() {
  // 1. Leer los valores del Joystick (rango de 0 a 1023)
  int lecturaX = analogRead(A0); // Eje VRX
  int lecturaY = analogRead(A1); // Eje VRY

  // 2. Convertir (mapear) el valor del Joystick al rango del Servo (0 a 180)
  // map(valor_entrada, min_entrada, max_entrada, min_salida, max_salida)
  int anguloBase = map(lecturaX, 0, 1023, 0, 180);
  int anguloBrazo = map(lecturaY, 0, 1023, 0, 180);

  // 3. Enviar la posición a los servomotores
  servoBase.write(anguloBase);
  servoBrazo.write(anguloBrazo);

  // Pequeña pausa para que los servos tengan tiempo de llegar a la posición
  // y para no saturar el procesador del Arduino
  delay(15); 
}