//Código de prueba para el control del brazo por medio de matrices y secuencias.

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

//Datos de posición
byte  w; //variable para la garra
byte  x; //variable para el antebrazo
byte  y; //variable para el brazo
byte  z; //variable para la base

byte v = 10; //velocidad, entre 5 a 20

//Matriz de datos y secuencias, cada fila pertenece a un servomotor, y cada columna representa una secuencia, los datos fueron colocados al azar y pueden cambiarse libremente.
//el ejemplo es de solo 10 secuecias, pero pueden aumentarse, modificando también la cantidad de columnas "10" en los corchetes de la matriz
byte sec[4][10] = {{80,160,90,150,100,140,110,130,120,130},//garra, respetar los límites de 80 - 160
                   {0,90,20,110,40,130,60,150,80,170},//antebrazo, mucho cuidado con el brazo y antebrazo, ambos son coodependientes y pueden chocar entre sí si no se cuidan las posiciones
                   {90,20,110,40,130,60,150,80,170,0},//brazo
                   {0,90,20,110,40,130,60,150,80,170}};//base

void setup() {
posiciondeorigen();

}

void loop() {
ejecutarsecuencia();
}

void ejecutarsecuencia(){
 for(byte k=0;k<10;k++){             //Si aumenta o disminuye el número total de pasos en la secuencia, es necesario modificar el "10" en este for de acuerdo al numero total de secuencias
    
    s1.attach(p1);                   //garra
    w = s1.read();
    if(w < sec[0][k]){               //lee la posición del servo, la compara con la posición a la que debe ir (según la lectura de la matriz), e inicia un bucle for que lo mueve hasta la posición indicada
      for(w; w< sec[0][k];w++){
        s1.write(w);
        delay(v);
      }
    }
    if(w > sec[0][k]){
     for(w; w> sec[0][k];w--){
        s1.write(w);
        delay(v);
      } 
    }
    s1.detach();
    
    
    s2.attach(p2);                    //antebrazo
    x= s2.read();
    if(x < sec[1][k]){
      for(x; x< sec[1][k];x++){
        s2.write(x);
        delay(v);
      }
    }
    if(x > sec[1][k]){
     for(x; x> sec[1][k];x--){
        s2.write(x);
        delay(v);
      } 
    }
    s2.detach();
    
    
    s3.attach(p3);               //brazo
    y = s3.read();
   if(y < sec[2][k]){
      for(y; y< sec[2][k];y++){
        s3.write(y);
        delay(v);
      }
    }
    if(y > sec[2][k]){
     for(y; y> sec[2][k];y--){
        s3.write(y);
        delay(v);
      } 
    }
    s3.detach();
   
    
    s4.attach(p4);             //base
    z = s4.read();
   if(z < sec[3][k]){
      for(z; z< sec[3][k];z++){
        s4.write(z);
        delay(v+10);             //la base debe moverse un poco más lento, por eso se le suman 10 al retardo
      }
    }
    if(z > sec[3][k]){
     for(z; z> sec[3][k];z--){
        s4.write(z);
        delay(v+10);
      } 
    }
    s4.detach();
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
  s3.write(60);
  delay(250);
  for(byte u = 60;u < 90;u++){ //El servomotor 3 es el único que utiliza un bucle For para moverse a una posición mas cómoda sin atorarse
    s3.write(u);
    delay(10);
  }
  s3.detach(); 
}
