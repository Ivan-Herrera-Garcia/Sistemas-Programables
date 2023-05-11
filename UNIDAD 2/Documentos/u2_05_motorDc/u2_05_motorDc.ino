int pin2=9;   //Entrada 2 del L293D
int pin7=10;  //Entrada 7 del L293D
int pote=A0;   //Potenciómetro
int botonPin=7;   // Botonsito
//bool band = false;

int estadoBoton = 0;
int auxEstadoBoton = 0;

int valorpote;     //Variable que recoge el valor del potenciómetro
int pwm1;          //Variable del PWM 1
int pwm2;          //Variable del PWM 2


 
void setup()
{
  //Inicializamos los pins de salida
  pinMode(pin2,OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(botonPin, INPUT);

}

void loop()
{
 
  //Almacenamos el valor del potenciómetro en la variable
  valorpote=analogRead(pote);
  estadoBoton = digitalRead(botonPin);
  
  if(estadoBoton != auxEstadoBoton)
  {
    if(estadoBoton == HIGH)
    {
      pwm1 = map(valorpote, 0, 1023, 0, 255);
    }
    else
    {
       pwm2 = map(valorpote, 0, 1023, 255, 0); 
    }
      delay(50);
  }
  auxEstadoBoton = estadoBoton;

  //Como la entrada analógica del Arduino es de 10 bits, el rango va de 0 a 1023.
  //En cambio, la salidas del Arduio son de 8 bits, quiere decir, rango entre 0 a 255.
  //Por esta razón tenemos que mapear el número de un rango a otro usando este código.
 /* if(band=false){
  pwm1 = map(valorpote, 0, 1023, 0, 255);
  }
  else{
  pwm2 = map(valorpote, 0, 1023, 255, 0); //El PWM 2 esta invertido respecto al PWM 1
  }*/
  
  //Sacamos el PWM de las dos salidas usando analogWrite(pin,valor)
  analogWrite(pin2,pwm1);
  analogWrite(pin7,pwm2);
 
}
