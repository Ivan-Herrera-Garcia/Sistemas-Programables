#include <LiquidCrystal.h> // Incluimos la libreria LiquidCrystal para poder programar nuestra LCD
#define Trigger 13 // Trigger en el pin 13
#define Echo 12 // Echo en el pin 12
LiquidCrystal lcd(2,3,8,9,10,11) // definios los pines en donde conectamos los pines de datos, RS y E

void setup() {
    lcd.begin(16,2); // Indicamos que es una pantalla lcd 16x2
    pinMode(Trigger,OUTPUT); // definimos el pin trigger como salida
    pinMode(Echo,INPUT); // definimos el pin como entrada
    digitalWrite(Trigger,LOW); // Inicializamos el pin con 0
}

void loop() {
  long t; // tiempo que demora en llegar el eco
  long d; // distancia en centimetros

  digitalWrite(Trigger,HIGH); // Mandamos un pulso a Trigger
  delayMicroseconds(10);  

  digitalWrite(Trigger,LOW);  
  t = pulseIn(Echo,HIGH); // encontramos el ancho del pulso
  d = t/59;     // hacemos la relacion de distancia segun el tiempo
  
  /*Mandamos a imprimir al lcd*/
  lcd.clear();
  lcd.print("Distancia= ");
  lcd.setCursor(0,1);
  lcd.print(d);
  delay(1000);
}
