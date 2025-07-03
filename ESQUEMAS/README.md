# **ESQUEMAS**

## **DOCUMENTACIÓN DEL HARDWARE**

### **LISTA DE COMPONENTES**
 
Instalamos una gran cantidad de sensores y componentes al vehículo. A continuación les presentamos una lista con cada uno de estos:

- Tarjeta Arduino Nano Ch340              x1
- Base Expansora para Arduino Nano        x1
- ESP32 cam Arduino                       x1
- Motor DC Caja Reductora 200 rpm         x1
- Ruedas de Motor DC (Tracción)           x2
- Ruedas de Motor DC (Dirección)          x2
- Micro ServoMotor Sg90 90g               x1
- Sensor Ultrasonido Hc-sr04              x3
- Driver de Motor DC L298N                x1
- Batería 9v y 5400 mAh                   x1
- Rolinera                                x1
- Barra Metálica (tracción)               x1
- cilindro hueco de plástico              x1
- Fuente de Alimentación Mb102            x1
- Pulsador                                X1
- Interruptor                             x1
- Línea positiva y negativa de protoboard x2 


### **ENSAMBLADO**

El carro se divide en dos bases: La base inferior y la base superior. Cada base lleva por dimensiones 17,5x14cm (se incluyen las alas para las ruedas de dirección).

En la siguente tabla se explica en que base se encuentra cada componente Y cada Material:

| BASE INFERIOR    | BASE SUPERIOR                                    |
|------------------|--------------------------------------------------|                                   
|Chasis Inferior   |Chasis Superior                                   |
|Motor DC          |Arduino Nano                                      |
|Micro ServoMotor  |Base expansora para arduino nano                  |
|Rolinera          |Driver de motor L298N                             |                                      
|Barra Metálica    |2 línea positiva y negativa de protoboard         |
|Cilindro Hueco    |Botón de encendido                                |
|4 Ruedas motor DC |Fuente de alimentación (con interruptor incluido) |
|Batería 9v        |2 sensores ultrasonido                            |
|Soporte Tracción  |Cámara ESP32 CAM                                  |
|Soporte Dirección |                                                  |
|Barra Dirección   |                                                  |      
|4 Soporte Cilindro|                                                  |     
|Sensor ultrasonido|                                                  |      
|Soporte Servo     |                                                  |
|2 Soporte Batería |                                                  |  



### **BASE INFERIOR**

Esta es la base de tracción, dirección y donde se ubica la batería, además del ultrasonido central.

 Para la dirección Diseñamos un soporte en forma de bloque para ubicar el servo boca abajo, una barra para unir las dos ruedas delanteras y dos soportes en forma de triángulo (similar a las alas para colocar las ruedas) para sostenerlas y mantenerlas en un eje vertical. De esta forma ubicamos las ruedas a una distancia entre sus ejes verticales de 12 cm (Cada eje vertical dista 1cm del chasis de tal forma que las ruedas tengan el mayor radio de giro). Los ejes verticales de las ruedas y del servo deben estar alineados para moverse en paralelo. Ubicamos estos ejes a una distancia de 3,25 cm del borde frontal del chasis, y así dejar espacio para la barra de dirección, esta mide 13 cm (cubre la distancia entre eje a eje de cada rueda y un poco más). El eje del servo se encuentra a 6 cm de cada eje vertical de las ruedas delanteras. La distancia total de punta a punta de las ruedas de dirección es 19,5 cm.

 Para la tracción ubicamos el motor DC tal que su eje horizontal se encuentre a 3cm del borde posterior del chasis, una rueda la unimos directamente al motor mientras que la otra la conectamos por un eje compuesto por una barra metálica y esta se conecta al motor DC siendo envuelta por un cilindro hueco de lapicero, la barra se fija al cilindro con silicón para que no quede inestable al girar, además la barra también se fija a una rolinera de diámetro 2cm para asegurar que ambas ruedas estén a una misma altura. Luego se fija el soporte en forma de U en la rolinera para dejarla fija. Las ruedas traseras se encuentran a una distancia, cada una, de 1,5 cm del chasis y la distancia total de punta a punta de ambas ruedas de tracción es 18 cm.

 Note que en la parte central del chasis inferior aún queda un gran espacio aprovechale, allí ubicamos dos soportes con forma de pared para fijar la batería, estos soportes distan 1,5 cm del borde derecho del chassis y tienen una distancia entre sí de 2,8cm (el ancho de la batería). La batería se ubica con sus conectores apuntando hacía la izquierda y su puerto USB apuntando hacia la derecha, de manera que sea práctico cargarla sin desmontarla el carro.

### **BASE SUPERIOR**



### **CIRCUITO ELÉCTRICO**
