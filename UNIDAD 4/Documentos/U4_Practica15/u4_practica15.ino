/* SISTEMAS PRGRAMABLES AGOSTO-DICIEMBRE 2022
 *   UNIDAD 4 : Practica 15
Programa para el control del ENCENDIDO/APAGADO de un LED usando el ESP32
*/
#include "BluetoothSerial.h" // Incluimos la libreroa

// Verifica que la conexion sea exitosa
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#define LED 23

BluetoothSerial BT; // Objeto de Tipo SETUP SERIAL
void setup() {
  Serial.begin(9600); // Inicialización de la conexión en serie para la depuración
  BT.begin("ESP32_LED_Control"); // Nombre de su dispositivo Bluetooth.
  Serial.println("El dispositivo Bluetooth está listo para emparejarse");
  pinMode (LED, OUTPUT); // Cambie el pin LED a OUTPUT
}
void loop() {
  if (BT.available()) // Compruebe si recibimos algo de Bluetooth
  {
    int valor = BT.read(); // Lee lo que recibimos
    Serial.print("Recibido: ");
    Serial.println(valor);
    // Para practica 15 y 16 solo cambian los ascii
    /*VALORES EN ASCII DEL :
    0 : 48
    1 : 49*/
    if (valor == 49){ // 1 en ASCII
      digitalWrite(LED, HIGH); // LED Encendido
      BT.println("LED encendido"); // Envía el mensaje de texto a través de BT Serial
    }
    if (valor == 48){ // 0 en ASCII
      digitalWrite(LED, LOW); // LED Apagado
      BT.println("LED apagado"); // Envía el mensaje de texto a través de BT Serial
    }
  }
  delay(20); // espera 0.02 segundos.
}
