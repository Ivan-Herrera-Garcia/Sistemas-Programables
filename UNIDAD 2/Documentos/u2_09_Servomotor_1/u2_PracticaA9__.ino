#include <Servo.h> // Liberia usada para el manejo del servomotor

Servo myservo;  // Creamos un objeto de tipo Servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // Hara la lectura del servo desde el pin 9
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // gira de 0 a 180 grados
    // giro de grado por grado
    myservo.write(pos);              // hace que el servo gire en cuanto al valor de 'pos'
    delay(15);                       // El tiempo en que tardara en dar los 180 grados, 15 milisegundos, es decir, 0.15 segundos.
  }
  for (pos = 180; pos >= 0; pos -= 1) { /// Va desde los 180 grados a 0
    myservo.write(pos);              // Hace que el servo gire, pero ahora girara en sentido inverso
    delay(15);                       // El tiempo en que tardara en dar los 180 grados, 0.15 segundos
  }
}
