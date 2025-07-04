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


![BASES_CARRO](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/blob/main/ESQUEMAS/BASES_CARRO.jpeg)


### **BASE INFERIOR**

Esta es la base de tracción, dirección y donde se ubica la batería, además del ultrasonido central.

 Para la dirección Diseñamos un soporte en forma de bloque para ubicar el servo boca abajo, una barra para unir las dos ruedas delanteras y dos soportes en forma de triángulo (similar a las alas para colocar las ruedas) para sostenerlas y mantenerlas en un eje vertical. De esta forma ubicamos las ruedas a una distancia entre sus ejes verticales de 12 cm (Cada eje vertical dista 1cm del chasis de tal forma que las ruedas tengan el mayor radio de giro). Los ejes verticales de las ruedas y del servo deben estar alineados para moverse en paralelo. Ubicamos estos ejes a una distancia de 3,25 cm del borde frontal del chasis, y así dejar espacio para la barra de dirección, esta mide 13 cm (cubre la distancia entre eje a eje de cada rueda y un poco más). El eje del servo se encuentra a 6 cm de cada eje vertical de las ruedas delanteras. La distancia total de punta a punta de las ruedas de dirección es 19,5 cm.

 Para la tracción ubicamos el motor DC tal que su eje horizontal se encuentre a 3cm del borde posterior del chasis, una rueda la unimos directamente al motor mientras que la otra la conectamos por un eje compuesto por una barra metálica y esta se conecta al motor DC siendo envuelta por un cilindro hueco de lapicero y una pieza de lego negra, la barra se fija al cilindro con silicón para que no quede inestable al girar, además la barra también se fija a una rolinera de diámetro 2cm para asegurar que ambas ruedas estén a una misma altura. Luego se fija el soporte en forma de U en la rolinera para dejarla fija. Las ruedas traseras se encuentran a una distancia, cada una, de 1,5 cm del chasis y la distancia total de punta a punta de ambas ruedas de tracción es 18 cm.

 Note que en la parte central del chasis inferior aún queda un gran espacio aprovechale, allí ubicamos dos soportes con forma de pared para fijar la batería, estos soportes distan 1,5 cm del borde derecho del chassis y tienen una distancia entre sí de 2,8cm (el ancho de la batería). La batería se ubica con sus conectores apuntando hacía la izquierda y su puerto USB apuntando hacia la derecha, de manera que sea práctico cargarla sin desmontarla el carro.


![ESQUEMA_BASE_INFERIOR](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/blob/main/ESQUEMAS/ESQUEMA_BASE_INFERIOR.png)

### **BASE SUPERIOR**

Esta es la base de control, con las tarjetas controladoras y la mayaroría de sensores ultrasonidos junto a la cámara, además de la fuente de alimentación.

Instalamos la Arduino Nano y el driver L298N en la parte posterior de esta base, pusimos la Arduino en una base expansora para atornillar las conexiones de cables y para poder atornillar la tarjeta al chasis así como también el driver, de esta forma evitamos que se muevan y que se puedan desconectar los cables. Las líneas positiva y negativa de protoboard las fijamos con pega 2cm más adelante de las tarjetas para dejar espacio para la conexión de cables (pues las conexiones a las tarjetas se hacen horizontales). Diseñamos una abertura para esta base y así pasar los cables del chasis inferior al superior. Ahora bien, 2cm después de la abertura se instala verticalmente la fuente de alimentación. 

Los sensores ultrasonidos laterales se instalan justo detrás de las alas del chasis superior, deben estar apuntando ligeramnete hacia abajo para evitar detectar cosas externas a la pista. Similarmente la cámara se instala en la parte frontal de esta base, apuntando ligeramente hacia abajo.

Con respecto a las líneas de protoboard y la fuente de aliemntación, una línea corresponde al voltaje de 5v, es decir esta línea viene alimentada por los 5v de la fuente de alimentación y aquí se conectan la Arduino Nano, los sensores ultrasonidos y el servo de la dirección. Mientras que la segunda línea está alimentada directamente por la batería y aquí se conecta el driver L298N, pues requiere de los 9v. Por otro lado la ESP32 CAM se alimenta directamente por los 3.3v de la fuente de alimentación.

En general las conexiones se realizaron con cables dupont Macho-Macho, Hembra-Hembra y Macho-Hembra, evitamos usar cables sin cabeza pues pueden soltarse y complicar la conexiones.

![ESQUEMA_BASE_SUPERIOR](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/blob/main/ESQUEMAS/ESQUEMA_BASE_SUPERIOR.png)

### **CIRCUITO ELÉCTRICO**

A continuación se les presenta el circuito eléctrico de la tarjeta Arduino con los demás componentes (en este esquema no se incluye la ESP32 CAM)

![CIRCUITO_ELECTRICO](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/blob/main/ESQUEMAS/ESQUEMA-CIRCUITO-EL%C3%89CTRICO-ARDUINO.pdf)

Ahora bien, para la ESP32-CAM, TX y RX de la cámara se conecta con el TX y RX de la Arduino Nano respectivamente, el GND se conecta a la línea negativa GND de la protoborad. Esta se alimenta al conectarse directamente a los 3,3V de la fuente de alimentación.

Para más detalles sobre la definición de pines pueden ver [DEFINICIÓN DE PINES](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/tree/main/SRC#definici%C3%B3n-de-pines)


## **DESEMPEÑO DEL CARRO**

A continuación se tienen los esquemas del desempeño del carro en las vueltas:

### VUELTA LIBRE

- El carro siempre se mueve adelante. Se detiene cuando haya realizado 12 giros exactos.

- Al detectar un vacío lateral de más de 200 cm y que la distancia frontal es de 60 cm, gira hacia este lado de tal forma de mantenerse en paralelo a la pared, hasta quedar en 90 grados con respecto a su trayectoria inicial.

![ESQUEMA_GIRO_VUELTA_LIBRE](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/blob/main/ESQUEMAS/ESQUEMA_GIRO_VUELTA_LIBRE.pptx)

- Sí se encuentra a una distancia de menos de 20 cm de la pared (o queda apuntando a la pared) gira levemente para despegarse de ella y nivelarse.

![ESQUEMA_NIVELACIÓN_VUELTA_LIBRE](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/blob/main/ESQUEMAS/ESQUEMA_NIVELACI%C3%93N_VUELTA_LIBRE.pptx)






