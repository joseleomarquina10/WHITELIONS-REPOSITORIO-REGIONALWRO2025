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
  int CRUCES_ESQUINA = 0;
  int CRUCES_NIVELACION = 0;
  int DISTANCIAINICIAL;
  const int DISTANCIA_MINIMA = 50; // Distancia mínima antes de girar (en cm)
  const int TIEMPO_ESPERA_INICIAL = 1000; // 3 segundos de espera inicial
  const int CRUCES_MAXIMOS = 12;
  int Arranque=0;

  void setup() {
    pinMode(4,INPUT_PULLUP);
    while(Arranque==0){
      if(digitalRead(4)==LOW){
        Arranque=1;
      }
    }
    
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
    Serial.println("Sensor Ultrasonico Hc-SR04");
    Serial.println("Write by Guille and Leo");
    DISTANCIAINICIAL = sonar.ping_cm();
  }

  void loop() {
    // Medir la distancia
    int DISTANCIA = sonar.ping_cm();
    if (CRUCES_ESQUINA >= CRUCES_MAXIMOS) {
      if(DISTANCIA<=DISTANCIAINICIAL){
       detenerCarro();
       return; // Terminar la ejecución
      }
    }else{
      // Mover el carro hacia adelante
      moverAdelante();
    }
    
    // Medir la distancia
    DISTANCIA = sonar.ping_cm();
    // Si detecta un obstáculo, girar a la izquierda
    if ((DISTANCIA > 0) && (DISTANCIA <= DISTANCIA_MINIMA)) {
      girarIzquierda();
      CRUCES_ESQUINA++;
      delay(1000); // Esperar un segundo después de girar
      centrarDireccion();
      delay(500);
      apuntarFullDerecha();
      
      if (DISTANCIA > 15){
        nivelarParedD();
        CRUCES_NIVELACION++;
        delay(250);
      }
        else {
          centrarDireccion();
      }

      if (DISTANCIA <10){
        nivelarParedI();
        CRUCES_NIVELACION++;
        delay(250);
      }
        else {
          centrarDireccion();
      }
      delay(500);
      apuntarFullCentro();
      centrarDireccion();
      delay(100);
      Serial.print("Distancia: ");
      Serial.println(DISTANCIA);
      Serial.print("Cruces: ");
      Serial.println(CRUCES_ESQUINA);
    
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
    servo1Motor.write(90);
  }

  void apuntarFullDerecha() {
    Serial.println("FullDerecha");
    servo2Motor.write(1);
  }

  void apuntarFullIzquierda() {
    Serial.println("FullIzquierda");
    servo2Motor.write(135);
  }
  void apuntarFullCentro() {
    Serial.println("FullCentro");
    servo2Motor.write(90);
  }
  void nivelarParedD() {
    Serial.println("NivelandoD");
    servo1Motor.write(95);
  }
  void nivelarParedI() { 
    Serial.println("NivelandoI");
    servo1Motor.write(80);
  }