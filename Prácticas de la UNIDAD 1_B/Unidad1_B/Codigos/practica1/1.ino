//** Definiciones **// 
const int sensor = 0; // entrada del sensor de temperatura
const int ledRojo = 5; // pin del LED rojo
const int ledAzul = 3; // pin del LED azul

long miliVolts;
long temperatura;
int brillo;

long calctemp(int datosSensor){
  /*Calculamos los mV en la entrada*/
  miliVolts = (analogRead(datosSensor) * 5000L) / 1023; 
  /* Calculamos la temperatura*/
  temperatura = miliVolts / 10;
  /*Regresamos el valor de temperatura*/
  return temperatura;
}

//** Programa **// 
void setup () {
  Serial.begin(9600); // iniciamos la comunicación serial
  /*Declaramos los LEDs como salida*/
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}
void loop () {//bucle a repetir continuamente 
  /*Llamamos a la función para calcular temperatura
   y guardamos el valor*/
  temperatura = calctemp(sensor);

  /*Ajustamos la escala de temperatura para poder usar analoWrite*/
  brillo = map(temperatura, 24,30, 0, 255);
  /*Restringimos el rango de brillo entre 0 y 255*/
  brillo = constrain(brillo, 0, 255);

  /*Ajustamos el color de los LED*/
  analogWrite(ledRojo, (250 - brillo));
  analogWrite(ledAzul, brillo);

  /*Mandamos el valor de la temperatura al monitor serial
  y agregamos un delay para no saturar el monitor*/
  Serial.print("Temperatura: "); 
  Serial.print(temperatura);
  Serial.println("grados");
  delay(200);
}
