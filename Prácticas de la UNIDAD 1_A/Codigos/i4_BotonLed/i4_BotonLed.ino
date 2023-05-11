  // Practica Inicio 4. Encendido/apagado de LED con boton
//Variables globales
int boton = 2;
int led = 13;
int estado = 0;
void setup() {
// put your setup code here, to run once:
pinMode(boton, INPUT); // boton como entrada
pinMode(led, OUTPUT);
Serial.begin(9600);
}
void loop() {
// put your main code here, to run repeatedly:
//Leemos el estado del boton
estado = digitalRead(boton);
//despliegue
Serial.println(estado);
//Cambiamos el estado del led
digitalWrite(led, estado);
}
