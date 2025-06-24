//CARRO-ARDUINO

#include <Servo.h>
  #include <NewPing.h>
  Servo servo1Motor;
  Servo servo2Motor;

  // Definición de pines
  const int TRIGGER_PIN = 2;
  const int ECHO_PIN = 3;
  //TRACCION
  const int MOTOR_IN1 = 9;
  const int MOTOR_IN2 = 7;
  //DIRECCION
  const int SERV1 = 11;
  //ULTRASONIDO
  const int SERV2 = 12;

  // Configuración del sensor ultrasónico
  const int MAX_DISTANCE = 300; // Distancia máxima a medir en cm
  NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

  // Configuración del servo
 // Servo direccion;

  // Variables globales
  int cruces = 0;
  const int DISTANCIA_MINIMA = 50; // Distancia mínima antes de girar (en cm)
  const int TIEMPO_ESPERA_INICIAL = 3000; // 3 segundos de espera inicial
  const int CRUCES_MAXIMOS = 12;

  void setup() {
  
    
    // Configurar pines del motor
    pinMode(MOTOR_IN1, OUTPUT);
    pinMode(MOTOR_IN2, OUTPUT);
    // Configurar pines de la direccion
    servo1Motor.attach(SERV1);
    //Direccion ulson
    servo2Motor.attach(SERV2);

    // Esperar 3 segundos antes de arrancar
    delay(TIEMPO_ESPERA_INICIAL);
    Serial.begin(9600);
    Serial.println("Ultrasonic Sensor Hc-SR04 Test");
    Serial.println("Write by Guille and Luis");
    moverAdelante();
    delay(500);
    moverAtras();
    delay(500);
    detenerCarro();
    delay(1000);
    girarIzquierda();
    delay(1000);
    girarDerecha();
    delay(1000);
    centrarDireccion();
    delay(1000);
  }

  void loop() {
    if (cruces >= CRUCES_MAXIMOS) {
      detenerCarro();
      return; // Terminar la ejecución
    }else{
      // Mover el carro hacia adelante
      moverAdelante();
    }

    // Medir la distancia
    int distancia = sonar.ping_cm();
    // Si detecta un obstáculo, girar a la izquierda
    if ((distancia > 0) && (distancia <= DISTANCIA_MINIMA)) {
      girarIzquierda();
      cruces++;
      delay(1000); // Esperar un segundo después de girar
      centrarDireccion();
      delay(100);
      Serial.print("Distancia: ");
      Serial.println(distancia);
      Serial.print("Cruces: ");
      Serial.println(cruces);
    }
  }

  void moverAdelante() {
    Serial.println("Adelante");
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
  }

  void moverAtras() {
    Serial.println("Atras");
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
  }

  void detenerCarro() {
    Serial.println("Detener");
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
  }

  void girarIzquierda() {
    Serial.println("Izquierda");
    servo1Motor.write(47);
  }
  void girarDerecha() {
    Serial.println("Derecha");
    servo1Motor.write(133);
  }

  void centrarDireccion() {
    Serial.println("Centrar");
    servo1Motor.write(88);
  }
