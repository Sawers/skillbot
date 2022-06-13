//Código de prueba pára ver si los servomotores del brazo 2.0 funcionan correctamente.

#include <Servo.h>

//Asignamos de nombres para cada servomotor
Servo s1;//garra   
Servo s2;//antebrazo
Servo s3;//brazo
Servo s4;//base

//Definimos los pines digitales para cada servomotor, en este código ya están configurados de acuerdo a la placa del Brazo robótico 2.0, siempre y cuando estén conectados tal como indica su manual.
#define p1 5 //garra
#define p2 6 //antebrazo
#define p3 7 //brazo
#define p4 8 //base

/*definimos los límites de posición para los servomotores: El servomotor se mueve entre 0 y 180 grados, pero puede que un servomotor no tenga tanta libertad en su movimiento y a veces choque
con sus límites físicos, teóricamente solo el servo de la garra tiene ese problema y por eso es el único con límites (está entre 80 a 160, en lugar de 0 a 180)
pero los servomotores del brazo y antebrazo también pueden chocar entre ellos, esto ya depende de nuestra experiencia con el robot*/
byte s1L = 80;//garra
byte s1R = 160;
byte s2L = 60;//ante
byte s2R = 140;
byte s3L = 60;//brazo
byte s3R = 140;
byte s4L = 0;//base
byte s4R = 180;

byte v = 10; //esta variable controlará la velocidad de los servos, se recomienda utilizar un rango entre 5 y 20.

void setup() {
  //no utilizamos el comando servo.attach aquí, por seguridad el brazo controla siempre un solo motor a la vez, el cual activa y desactiva según sea necesario.

}

void loop() {
 movimientosimple(); /*Este void se encarga de mover cada uno de los servomotores desde sus límites mínimos hasta los máximos, y viceversa
                       Util para saber también si hay algún problema mecánico que impode el movimiento total del robot*/
}

void movimientosimple(){
  //Movimiento de la base

  //Este proceso se repetirá en los demás servomotores.
  s4.attach(p4); //Se conecta el servomotor al pin correspondiente
  s4.write(90); //Se envía al servomotor a su posición de origen, en este caso el límite menor colocado al inicio
  delay(300);    //el retardo de 300 milisegundos recomendado en movimientos planos de servomotor.

  for(byte i = 90 ; i < s4R ; i++){ //Este bucle for se encarga de mover el servomotor hasta el máximo.
    s4.write(i);
    delay(v);
  }

  for(byte i = s4R ; i > s4L ; i--){ //Este otro bucle hace lo contrario, mover hasta el mínimo.
    s4.write(i);
    delay(v);
  }
 
  for(byte i = s4L ; i < 90 ; i++){
    s4.write(i);
    delay(v);
  }
  
  
  s4.detach(); //Se desconecta el servomotor para evitar problemas con el amperaje.


  //Movimiento del brazo, observa como el código es exactamente el mismo, tan solo cambiando los numeros 4 por 3.
  s3.attach(p3);
  s3.write(90);
  delay(300);
  for(byte i = 90 ; i < s3R ; i++){ 
    s4.write(i);
    delay(v);
  }
  for(byte i = s3R ; i > s3L ; i--){
    s3.write(i);
    delay(v);
  } 
  for(byte i = s3L ; i < 90 ; i++){
    s3.write(i);
    delay(v);
  }
  s3.detach();

  //Movimiento del antebrazo
  s2.attach(p2);
  s2.write(90);
  delay(300);
  for(byte i = 90 ; i < s2R ; i++){ 
    s2.write(i);
    delay(v);
  }
  for(byte i = s2R ; i > s2L ; i--){
    s2.write(i);
    delay(v);
  } 
  for(byte i = s2L ; i < 90 ; i++){
    s2.write(i);
    delay(v);
  }
  s2.detach();

  //Movimiento de la garra
  s1.attach(p1);
  s1.write(90);
  delay(300);
  for(byte i = 90 ; i < s1R ; i++){ 
    s1.write(i);
    delay(v);
  }
  for(byte i = s1R ; i > s1L ; i--){
    s1.write(i);
    delay(v);
  } 
  for(byte i = s1L ; i < 90 ; i++){
    s1.write(i);
    delay(v);
  s1.detach();
 }
}
