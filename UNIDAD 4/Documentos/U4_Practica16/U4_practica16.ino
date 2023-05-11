/* SISTEMAS PRGRAMABLES AGOSTO-DICIEMBRE 2022
 *   UNIDAD 4 : Practica 16
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
    /*VALORES ASCII DE :
    f : 102 
    F : 70
    n : 110
    N : 78*/
    
    if (valor == 110 || valor == 78){ // n y N en ASCII respectivamente.
      digitalWrite(LED, HIGH); // LED Encendido
      BT.println("LED encendido"); // Envía el mensaje de texto a través de BT Serial
    }
    if (valor == 102 || valor == 70 ){ // f y F en ASCII respectivamente
      digitalWrite(LED, LOW); // LED Apagado
      BT.println("LED apagado"); // Envía el mensaje de texto a través de BT Serial
    }
  }
  delay(20); // espera 0.02 segundos.
}
