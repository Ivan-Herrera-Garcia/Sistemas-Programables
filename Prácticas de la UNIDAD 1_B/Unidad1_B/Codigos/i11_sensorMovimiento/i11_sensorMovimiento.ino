int SensorPIR = 2;
void setup() {
  Serial.begin(9600);
  pinMode(SensorPIR, INPUT);
}

void loop() {
  int valor = digitalRead(SensorPIR);
  Serial.println(valor);
  delay(150);
}
