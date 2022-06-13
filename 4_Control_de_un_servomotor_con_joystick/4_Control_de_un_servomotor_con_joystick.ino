//Código de ejemplo para el movimiento de un servomotor por medio del joystick

#include <Servo.h>

//para este código utilizaremos únicamente el servomotor de la base
Servo s4;//servo base nombre

#define p4 8 //servo base pin

byte s4L = 0;//servo base límites mínimos y máximos
byte s4R = 180;

//Creamos las variables para guardar los datos de posición de cada servomotor
byte  z; //variable para la base

byte v = 10;//velocidad (5-20)

int a4;//para sensor joystick A eje x

/*Límites mínimos y máximos de los sensores (joystick)cuando el joystick se encuentra en su posición media manda una señal de 512 aproximadamente, estos límites ponen una barrera que se debe
cruzar antes de que la señal del joystick pueda tomarse en cuenta y evitar que se lean pequeños movimientos accidentales*/
int lim1 = 450;
int lim2 = 550;

void setup() {
//no utilizamos el comando servo.attach aquí.
posiciondeorigen(); //envía al servomotor a una posición media antes de controlarlo
}

void loop() {
leersensores();
delay(10);
if(a4 < lim1 && z > s4L ){ //El motor se moverá solo mientras el joystick esté inclinado y mientras el motor no alcance su límite
  s4.attach(p4);
  z = s4.read();
  while(a4 < lim1 && z > s4L){   
    z--;
    s4.write(z);
    delay(v);
    leersensores(); 
  }
  s4.detach();
}

else if(a4 > lim2 && z < s4R){
  s4.attach(p4);
  z = s4.read();
  while(a4 > lim2 && z < s4R){   
    z++;
    s4.write(z);
    delay(v);
    leersensores(); 
  }
  s4.detach();
}
}

void posiciondeorigen(){
 s4.attach(p4);
 s4.write(90);
 delay(300);
 s4.detach();
}

void leersensores(){
 a4 = analogRead(A0);
}
