# **TABLA DE CONTENIDOS** 

- [**NUESTRO RECORRIDO**](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/tree/main?tab=readme-ov-file#nuestro-recorrido)
- [**IDEAS Y PRINCIPIOS**](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/tree/main/OTRO#ideas-y-principios)
- [**DOCUMENTACIÓN DEL HARDWARE**](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/tree/main/ESQUEMAS#esquemas-y-documentaci%C3%B3n-del-hardware)
- **DOCUMENTACIÓN DEL SOFTWARE**
- **DOCUMENTACIÓN DEL CÓDIGO ARDUINO**
- [**FOTOS DEL EQUIPO**](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/tree/main/FOTOS-EQUIPO)
- [**FOTOS DEL VEHÍCULO**](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/tree/main/FOTOS-VEH%C3%8DCULO)
- [**VIDEOS** ](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/tree/main/VIDEO)


# **NUESTRO RECORRIDO**

Mediante este repositorio les mostraremos detalladamente el proceso y recorrido del proyecto WHITELIONS, con esto buscamos explicar paso por paso y ordenadamente la construcción de nuestro carro llamado WHITELION, así como también destacar su evolución y nuestro aprendizaje de cada falla, pues para nosotros fallar no es fracaso sino una oportunidad para acercarnos más al éxito.

## **EQUIPO** 

Nuestro equipo consiste de dos miembros y un coach, somos WHITELIONS de Yaracuy. Este es nuestro tercer año participando juntos en WRO, pero esta es nuestra primera edición en la categoría Fututos Ingenieros.  A continuación, se les presenta los integrantes del equipo:

    MIEMBROS:

-	Guillermo Herrera del Colegio El Ángel 
    - guillermoaherrerab@gmail.com

-	José Leonardo Marquina del Colegio Los Ángeles
    - Joseleonardomarq10@gmail.com

    COACH:

-	Luis Barrios
    - luisgbarriosm@gmail.com

Les presentamos los links a nuestras redes:

- Youtube: https://www.youtube.com/@WhiteLions-r5q
    Aquí pueden encontrar videos del desenvolvimiento del vehículo.


- Instagram: https://www.instagram.com/whitelions.wro?igsh=MWYzM2lkdWxreDZrdw==
    Aquí pueden encontrar novedades de nosotros.


## **PRIMEROS PROTOTIPOS Y EVOLUCIÓN DEL DISEÑO**

- ### **Primer Prototipo**
![PRIMER PROTOTIPO](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/blob/main/PRIMER_PROTOTIPO.jpeg)

Originalmente, utlizamos un kit de carro de lego al cual le instalamos una tarjeta arduino nano y un sensor de ultrasonido, aprovechamos el sistema de dirección y tracción que contaba el carro. Por una parte la tracción funcionaba con un motor dc y por la otra parte la dirección también contaba con un motor dc pero controlaba su radio de giro con una pieza de abanico que limitaba el giro. Además el carro tenía un driver de motor para controlar estos.

Todo este mecanismo lo conectamos con la tarjeta Arduino y aquí nació el primer prototipo del WHITELION, el cual únicamente giraba a la izquierda al detectar una pared al frente y gracias al mecanismo de engranajes de la tracción iba a alta velocidad.

Este primer prototipo nos sirvió para realizar una gran cantidad de pruebas así como también para darnos cuenta de muchas cosas que debíamos mejorar. Rápidamente nos dimos cuenta de que la dirección presentaba muchos fallos pues era controlada por un motor dc, además el chasis del carro era demasido pequeño y estrecho, lo que iba a dificultar ubicar el resto de componentes necesarios. 

- ### **Primer Todelo en Tinkercad**
![PRIMER_MODELO_TINTERCAD](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/blob/main/PRIMER_MODELO_TINKERCAD.jpeg)

Por lo anterior, realizamos un rediseño para imprimir en 3D todo el chasis y la dirección, sin embargo nos quedamos con las ruedas delanteras y su mecanismo de giro, además la nueva dirección sería controlada por un servomotor para más precisión al girar.

Nuestro principio es que el carro sea pequeño por eso definimos el nuevo chasis de dimensiones de 10x15 cm, pero igualmente nos dimos cuenta del poco espacio, por ello decidimos hacerle un segundo chasis al carro y de esta forma habrían dos: Chasis superior, con los controladores y la batería; y chasis inferior, con la traccion, dirección y el sensorores. 

Del carro anterior, también definimos que el ultrasonido funcione como un radar y que se mueva constantemente por un servomotor para detectar su entorno y de alli decidir a donde girar, por ello pensamos en utilizar una torre arriba del servo para colocar el ultrasonido y una posible cámara, además utilizamos un solo motor dc para la tracción para no complicar la programación y porque al probar con dos constantemente se soltaban del eje.

Incorporamos el driver de motor dc L298N para poder controlar la velocidad a través del pwm y por sus conexiones atornilladas, para asegurar una conexión firme. por la misma razón incluimos una base expansora de arduino nano para atornillar.

- ### **Primer Carro Funcional**
![PRIMER_CARRO_FUNCIONAL](https://github.com/joseleomarquina10/WHITELIONS-REPOSITORIO-REGIONALWRO2025/blob/main/PRIMER_CARRO_FUNCIONAL.jpg)

Tras este rediseño notamos que aún era necesario más espacio por ello expandimos el chasis superior a las mismas dimensiones del inferior. 

Notamos que existía un espacio aprovechable en el chasis infeior por el uso de un solo motor así que allí ubicamos la batería y para que todos los cables pasaran de buena forma de chasis a chasis, hicimos una abertura en el superior.

Tras esta expasión del chasis superior ya no podíamos instalar el radar en el chasis inferior, por lo que decidimos hacerlo arriba y con impresión 3D llegamos a este nuevo prototipo, el cual usaríamos en nuestra primera regional.


### **DISEÑO ACTUAL**


## **TRABAJO EN EQUIPO**


# **CONCLUSIÓN**


# **AGRADECIMIENTOS**

Primeramente nos sentimos agradecidos con Dios, con nuestro tutor Luis Barrios y con nuestros padres, por apoyarnos siempre y formar parte de todo este recorrido en futuros ingenieros. Agradecemos de la misma forma a nuestra casa de las olimpiadas MATICES, por darnos sus espacios para poder armar y desarrollar el carro, a nuestros profesores Johan Goyo y Rafael Linarez por orientarnos y a nuestros colegios "El Ángel" y "Los Ángeles".
