/*Código de prueba para comprobar si funcionan correctamente los joysticks y botones del mando (para el Brazo robótico 2.0), utilizar la conexión y el monitor serial para verificar
los datos enviados por el mando.*/

//variables para guardar los datos de los sensores. 
int a1; //Variables para los sensores analógicos (potenciómetros) del joystick
int a2;
int a3;
int a4;
byte boton1; //variables para los botones centrales del joystick
byte boton2;

void setup() {
 pinMode(12,INPUT);//boton1;
 pinMode(16,INPUT);//boton2, en realidad este botón utiliza la entrada analógica A2, pero que puede utilizarse como pin digital número 16
 Serial.begin(9600);//para poder ver los datos de las lecturas en el monitor serial
}

void loop() {
 leerpulsadores();
 leersensores();
 imprimirdatos();
 delay(10);
}

//Los pines ya están configurados de acuerdo a las conexiones de la placa 2.0, para versiones posteriores u otras placas, modificar dichos pines.
void leerpulsadores(){
  boton1 = digitalRead(12); //pin D12
  boton2 = digitalRead(16); //pin A2
}

void leersensores(){
 a1 = analogRead(A3); //los pines de los sensores no están en orden debido a los caprichos del puerto RJ45 del mando
 a2 = analogRead(A4);
 a3 = analogRead(A1);
 a4 = analogRead(A0);
}

void imprimirdatos(){ //El joystick A es el de la izquierda, y el B el de la derecha, igual que los botones.
 Serial.println(" ");
 Serial.print("Joystick Ax  ");
 Serial.print(a4);
 Serial.print("    ;Joystick Ay  ");
 Serial.print(a3);
 Serial.print("    ;Joystick Bx  ");
 Serial.print(a1);
 Serial.print("    ;Joystick By  ");
 Serial.print(a2);
 Serial.print("    ;botón A  ");
 Serial.print(boton1);
 Serial.print("    ;botón B  ");
 Serial.print(boton2);
}
