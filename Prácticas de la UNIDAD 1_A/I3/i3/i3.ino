// Practica Inicio 3.
//Secuenca de encendido/apagado de LEDs
void setup() {
 // put your setup code here, to run once:
 pinMode(13, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(5, OUTPUT);
}
void loop() {
 // put your main code here, to run repeatedly:
digitalWrite(13, HIGH);
 delay(500);
 digitalWrite(9, HIGH);
 delay(1000);
 digitalWrite(5, HIGH);
 delay(1500);
 digitalWrite(13, LOW);
 delay(1500);
 digitalWrite(9, LOW);
 delay(1000);
 digitalWrite(5, LOW);
 delay(500);
}
