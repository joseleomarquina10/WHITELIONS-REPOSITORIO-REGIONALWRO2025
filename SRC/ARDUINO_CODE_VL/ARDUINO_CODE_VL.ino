#include <Servo.h>
  #include <NewPing.h>
  Servo servo1Motor;

  // Definición de pines
  
  // ULTRASONIDOS 

  // DERECHO
  const int TRIGGER_DERECHA = 2;
  const int ECHO_DERECHA = 3;
  //CENTRAL
  const int TRIGGER_CENTRAL = 4;
  const int ECHO_CENTRAL = 5;
  //IZQUIERDO
  const int TRIGGER_IZQUIERDA = 6;
  const int ECHO_IZQUIERDA = 7;

  //TRACCION
  const int MOTOR_IN3 = 9;
  const int MOTOR_IN4 = 10;
  const int ENB = A0;
  int Arranque = 0;  //DIRECCION
  const int SERVO = 8;
  

  // CONFIGURACION DE SENSORES ULTRASONIDO
  const int MAX_DISTANCE = 300; // Distancia máxima a medir en cm
  NewPing sonarD(TRIGGER_DERECHA, ECHO_DERECHA, MAX_DISTANCE);
  NewPing sonarC(TRIGGER_CENTRAL, ECHO_CENTRAL, MAX_DISTANCE);
  NewPing sonarI(TRIGGER_IZQUIERDA, ECHO_IZQUIERDA, MAX_DISTANCE);

  // Variables globales
  int cruces = 0;
  const int DISTANCIA_CRUCE = 150; // Distancia mínima antes de girar (en cm)
  const int TIEMPO_ESPERA_INICIAL = 3000; // 3 segundos de espera inicial
  const int CRUCES_MAXIMOS = 12;

  // DISTANCIAS INICIALES
  int DISTANCIA_INICIAL_DERECHA = 0;
  int DISTANCIA_INICIAL_CENTRAL = 0;
  int DISTANCIA_INICIAL_IZQUIERDA = 0;

  // DISTANCIAS EN GENERAL
  int DISTANCIA_DERECHA = 0;
  int DISTANCIA_CENTRAL = 0;
  int DISTANCIA_IZQUIERDA = 0;

  void setup() {

    Serial.begin(9600);
    Serial.println("Ultrasonic Sensor Hc-SR04 Test");
    Serial.println("Write by Guille and Leo");

    // configurar pin del pulsador
    pinMode(11,INPUT_PULLUP);
    while(Arranque==0){
      if(digitalRead(11)==LOW){
        Arranque=1;
      }
    }


    // Configurar pines del motor
    pinMode(MOTOR_IN3, OUTPUT);
    pinMode(MOTOR_IN4, OUTPUT);
    // Configurar pines de la direccion
    servo1Motor.attach(SERVO);
   
    DISTANCIA_INICIAL_DERECHA = sonarD.ping_cm();
    DISTANCIA_INICIAL_CENTRAL = sonarC.ping_cm();
    DISTANCIA_INICIAL_IZQUIERDA = sonarI.ping_cm();

    // esperar 3 segundos antes de avanzar
     delay(TIEMPO_ESPERA_INICIAL);
     centrarDireccion();
     delay(500);
  }

  void loop() {

     // Medir la distancia
    DISTANCIA_DERECHA = sonarD.ping_cm();
    DISTANCIA_CENTRAL = sonarC.ping_cm();
    DISTANCIA_IZQUIERDA = sonarI.ping_cm();

    if (cruces >= CRUCES_MAXIMOS) {
      detenerCarro();
      return; // Terminar la ejecución
    }else{
      // Mover el carro hacia adelante
      moverAdelante();
    }

    // GIRAR DERECHA
    if ((DISTANCIA_DERECHA > 0) && (DISTANCIA_CENTRAL > 0) && (DISTANCIA_CENTRAL <= 100) && (DISTANCIA_DERECHA >= DISTANCIA_CRUCE)) {
      girarDerecha();
      cruces++;
      delay(1400); 
      centrarDireccion();
      delay(1000);
    }
    // GIRAR IZQUIERDA
    if ((DISTANCIA_IZQUIERDA > 0) && (DISTANCIA_CENTRAL > 0) && (DISTANCIA_CENTRAL <= 100) && (DISTANCIA_IZQUIERDA >= DISTANCIA_CRUCE)) {
      girarIzquierda();
      cruces++;
      delay(1400); 
      centrarDireccion();
      delay(1000);
    }
    // NIVELAR DERECHA
    if ((DISTANCIA_IZQUIERDA > 0) && (DISTANCIA_IZQUIERDA <= 15)){
    nivelarDerecha();
    delay(750);
    centrarDireccion();
    delay(200);
    }
    // NIVELAR IZQUIERDA
    if ((DISTANCIA_DERECHA > 0) && (DISTANCIA_DERECHA <= 15)){
    nivelarIzquierda();
    delay(750);
    centrarDireccion();
    delay(200);
    }

  }

  void moverAdelante() {
    Serial.println("Adelante");
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, HIGH);
    analogWrite(ENB, 130); 
  }

  void moverAtras() {
    Serial.println("Atras");
    digitalWrite(MOTOR_IN3, HIGH);
    digitalWrite(MOTOR_IN4, LOW);
    analogWrite(ENB, 130); 
  }

  void detenerCarro() {
    Serial.println("Detener");
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, LOW);
    analogWrite(ENB, 0); 
  }

  void girarIzquierda() {
    Serial.println("Izquierda");
    servo1Motor.write(50);
  }
  void girarDerecha() {
    Serial.println("Derecha");
    servo1Motor.write(144);
    
  }

  void centrarDireccion() {
    Serial.println("Centrar");
    servo1Motor.write(97);
    
  }
  void nivelarDerecha(){
    Serial.println("NivelarDerecha");
    servo1Motor.write(117);
    
  }
  void nivelarIzquierda(){
    Serial.println("NivelarIzuqierda");
    servo1Motor.write(77);
    
  }
