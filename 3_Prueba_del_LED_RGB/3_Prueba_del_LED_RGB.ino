//Código de prueba para comprobar si el LED RGB del brazo robótico 2.0 funciona correctamente

//Definimos los pines digitales para el led RGB (ya están configurados para la placa del robot), son pines PWM siempre.
#define R 11 //Rojo
#define G 10 //Verde
#define B 9 //Azul

/*Matriz RGB para guardar todas las combinaciones de colores y así no complicarnos mucho a futuro.
  Esta matriz utiliza el mismo tipo y número de colores que el robot, pero pueden cambiarse a gusto o incluso aumentar más colores (teniendo conocimientos de matrices en arduino)
  Los colores están configurados para un RGB de polo negativo común, pero puede que lleguen a existir versiones del robot que utilicen un RGB de polo positivo, en cuyo caso los datos simplemente deben ser invertidos (255 a 0, 150 a 105, 200 a 55, 0 a 255, etc)*/
byte RGB [7][3] = {{255,0,255},//Morado
                   {255,0,0},//rojo
                   {10,10,0},//Morado débil
                   {0,0,255},//Azul
                   {255,255,0},//Amarillo
                   {0,255,255},//celeste
                   {0,255,0}};//verde

byte color;//esta variable sirve para seleccionar los colores de la matriz, empieza contando desde arriba y desde 0, por tanto 0 sería el color Morado, 1 el rojo, 5 celeste, etc.
                   
void setup() {
 pinMode(R,OUTPUT); //configuramos los pines del LED como salidas
 pinMode(G,OUTPUT);
 pinMode(B,OUTPUT);
 color = 0; //Elegimos el color que deseamos
}

void loop() {
uncolor(); //este void encenderá solamente el color que elegimos.
todosloscolores(); //como su nombre indica, repasará todos los cores.
}

void uncolor() {
 analogWrite(R,RGB[color][0]);
 analogWrite(G,RGB[color][1]);
 analogWrite(B,RGB[color][2]);
 delay(300);  
}

void todosloscolores() {
 for(byte i = 0; i < 7 ; i++){
 analogWrite(R,RGB[i][0]);
 analogWrite(G,RGB[i][1]);
 analogWrite(B,RGB[i][2]);
 delay(300);
 }
}
