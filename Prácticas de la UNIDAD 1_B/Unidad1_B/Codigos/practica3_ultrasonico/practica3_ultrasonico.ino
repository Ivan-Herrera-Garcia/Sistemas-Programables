
#define echoPin 11 
#define trigPin 12 

// definicion de variables
long duracion; // variable para la duracion de la onda 
int distancia; // variable para la distancia

void setup() {
  // Leemos los pines
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); // // Definimos los baudios
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Delay en microsegundos
  // Pone el trigPin activo durante 10 segundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);
  // Calculando la distancia
  distancia = duracion * 0.034 / 2; 
  // Mostramos los resultados en el monitor serial
  Serial.print("Distancia : ");
  Serial.print(distancia-);
  Serial.println(" cm");
  delay(200);
}
