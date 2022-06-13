//Código de ejemplo para el movimiento del brazo por medio de ambos joysticks, es exactamente el mismo código que el que vimos para un solo servomotor, pero ahora multiplicado por 4.

#include <Servo.h>

//Nombres de servos
Servo s1;//garra   
Servo s2;//antebrazo
Servo s3;//brazo
Servo s4;//base

//Pines configurados
#define p1 5 //garra
#define p2 6 //antebrazo
#define p3 7 //brazo
#define p4 8 //base

//Límites de servomotores
byte s1L = 80;//garra
byte s1R = 160;
byte s2L = 0;//antebrazo
byte s2R = 180;
byte s3L = 0;//brazo
byte s3R = 180;
byte s4L = 0;//base
byte s4R = 180;

//Datos de posición
byte  w; //variable para la garra
byte  x; //variable para el antebrazo
byte  y; //variable para el brazo
byte  z; //variable para la base

byte v = 10;//velocidad (5-20)

//para los sensores joystick
int a1;
int a2;
int a3;
int a4;

//Límites mínimos y máximos de los sensores
int lim1 = 450;
int lim2 = 550;

void setup() {
//no utilizamos el comando servo.attach aquí.
posiciondeorigen(); //envía al servomotor a una posición media antes de controlarlo
}

void loop() {
leersensores();
delay(10);

//base
if(a4 < lim1){
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

else if(a4 > lim2){
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

//brazo
else if(a3 < lim1){
  s3.attach(p3);
  y = s3.read();
  while(a3 < lim1 && y > s3L){   
    y--;
    s3.write(y);
    delay(v);
    leersensores(); 
  }
  s3.detach();
}

else if(a3 > lim2){
  s3.attach(p3);
  y = s3.read();
  while(a3 > lim2 && y < s3R){   
    y++;
    s3.write(y);
    delay(v);
    leersensores(); 
  }
  s3.detach();
}

//antebrazo
else if(a2 < lim1){
  s2.attach(p2);
  x = s2.read();
  while(a2 < lim1 && x > s2L){   
    x--;
    s2.write(x);
    delay(v);
    leersensores(); 
  }
  s2.detach();
}

else if(a2 > lim2){
  s2.attach(p2);
  x = s2.read();
  while(a2 > lim2 && x < s2R){   
    x++;
    s2.write(x);
    delay(v);
    leersensores(); 
  }
  s2.detach();
}

//garra
else if(a1 < lim1){
  s1.attach(p1);
  w = s1.read();
  while(a1 < lim1 && w > s1L){   
    w--;
    s1.write(w);
    delay(v);
    leersensores(); 
  }
  s1.detach();
}

else if(a1 > lim2){
  s1.attach(p1);
  w = s1.read();
  while(a1 > lim2 && w < s1R){   
    w++;
    s1.write(w);
    delay(v);
    leersensores(); 
  }
  s1.detach();
}
}

void posiciondeorigen(){
  s1.attach(p1);
  s1.write(90);
  delay(250);
  s1.detach();
  s2.attach(p2);
  s2.write(30);
  delay(250);
  s2.detach(); 
  s4.attach(p4);
  s4.write(90);
  delay(250);
  s4.detach(); 
  s3.attach(p3);
  s3.write(150);
  delay(250);
  for(byte u = 150;u>90;u--){ //El servomotor 3 es el único que utiliza un bucle For para moverse a una posición mas cómoda sin atorarse
    s3.write(u);
    delay(10);
  }
  s3.detach(); 
}

void leersensores(){
 a1 = analogRead(A3);
 a2 = analogRead(A4);
 a3 = analogRead(A1);
 a4 = analogRead(A0);
}
