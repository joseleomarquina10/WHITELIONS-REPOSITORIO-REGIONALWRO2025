# **DOCUMENTACIÓN DEL SOFTWARE Y DEL CÓDIGO ARDUINO**

## **DEFINICIÓN DE PINES**

En las siguentes tablas se ve asignado cada pin con su funcionamiento:

- TARJETA ARDUINO NANO

| CONCEPTO DEL PIN   | PIN ASIGNADO |
|--------------------|--------------|
| TRIGGER_DERECHA    | d2           |
| ECHO_DERECHA       | d3           |
| TRIGGER_CENTRAL    | d4           |
| ECHO_CENTRAL       | d5           |
| TRIGGER_IZQUIERDA  | d6           |
| ECHO_IZQUIERDA     | d7           |
| SERVO              | d8           |
| MOTOR_IN3          | d9           |
| MOTOR_IN4          | d10          |
| ENB                | d11          |
| ENCENDIDO          | d12          |
| ALIMENTACIÓN 5V    | VCC          |
| NEGATIVO           | GND          |
| TRANSMISIÓN        | TX           |
| RECEPCIÓN          | RX           |

- DRIVER L298N 

| CONCEPTO DEL PIN    | PIN ASIGNADO |
|---------------------|--------------|
| MOTOR_IN3           | IN3          |
| MOTOR_IN4           | IN4          |
| ENB                 | ENB          |
| CONEXIÓN_OUT3       | OUT3         |
| CONEXIÓN_OUT4       | OUT4         |
| ALIMENTACIÓN 5V     | +5V          |
| ALIMENTACIÓN BATERíA| +12V         |
| NEGATIVO            | GND          |


- CÁMARA ESP32-CAM

| CONCEPTO DEL PIN    | PIN ASIGNADO |
|---------------------|--------------|
| TRANSMISIÓN         | TX           |
| RECEPCIÓN           | RX           |
| ALIMENTACIÓN        | 3.3V         |
| NEGATIVO            | GND          |

- FUENTE DE ALIMENTACIÓN

| CONCEPTO DEL PIN    | PIN ASIGNADO |
|---------------------|--------------|
| ALIMENTACIÓN 5V     | 5V           |
| NEGATIVO 5V         | GND 5V       |
| ALIMENTACIÓN 3.3V   | 3.3V         |
| NEGATIVO 3.3V       | GND 3.3V     |

## **ESTRUCTURA Y LÓGICA DEL CÓDIGO**
