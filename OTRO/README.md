# **IDEAS Y PRINCIPIOS**

##  **CONSTRUCCIÓN Y MECANISMO DEL CARRO**

- Decidimos que el carro fuera pequeño para que pudiera maniobrar más fácilmente y tuviera mejor tiempo de reacción. De allí fijamos las dimensiones para el chasis de 15x13 cm y lo imprimimos en 3D.

- Con estas dimensiones, claramente no podíamos instalar todos los componentes necesarios en la base; por tanto, implementamos un segundo piso para el carro. Así dejamos dos chasis: el inferior de mecanismo, con la tracción, la dirección y la batería; y el superior de control, con la tarjeta Arduino Nano, el driver de motor y los sensores.

- Para la dirección consideramos usar un servomotor para controlar el giro de las ruedas delanteras mediante una barra que conecte ambas ruedas con el servo. Tomamos en cuenta que fuera una barra metálica, pero al notar que dificultaba mucho el proceso de armado y desarmado, además de provocar fallas en las conexiones, decidimos imprimir esta barra en 3D. Reutilizamos unas ruedas de un kit de LEGO y replicamos los soportes de estas en 3D junto a la barra.

- Para la tracción, decidimos no usar dos motores DC, pues se soltaban constantemente. De allí decidimos dejar solo un motor DC para simplificar la programación y el mecanismo. Usamos ruedas de motor DC amarillo, una conectada directamente al motor y otra unida por una barra metálica a un lapicero que funcionó como eje. Para centrar esta rueda, utilizamos una rolinera para dejar fijo el eje y evitar rebotes.

- Como aún había espacio en el chasis inferior debido al uso de solo un motor, decidimos colocar la batería en ese espacio.

- Notamos que habría dificultades para conectar los cables de batería, motor y servo a los controladores del chasis superior. Por ello dejamos una abertura en el chasis superior para los cables.

- La ubicación del Arduino y el driver la dejamos en la parte trasera del chasis superior, mientras que los sensores los dejamos en la parte frontal; además, el pulsador y el interruptor los ubicamos a los costados.

- Decidimos utilizar el driver L298N por su capacidad para PWM y porque las conexiones se atornillan, garantizando buena conexión de los cables y que no se suelten. Por la misma razón, utilizamos una base expansora de atornillado para el Arduino.

- Originalmente pensamos en utilizar un radar en la parte frontal del chasis superior, constituido por un servomotor y un sensor de ultrasonido, para que el carro detectara y diferenciara la pared del vacío. Sin embargo, esto no resultó y complicó el proyecto.

- Tras nuestra primera regional, descartamos la idea anterior e implementamos al carro tres sensores de ultrasonido fijos (uno apuntando a la derecha, otro hacia el centro y el otro a la izquierda), además de una cámara ESP32-CAM para detectar los colores en la vuelta de obstáculos.

- Rápidamente notamos que el ultrasonido central y la cámara coincidían en ubicación; por ello, dejamos el ultrasonido en la parte delantera del chasis inferior y la cámara en la parte superior.

- Además, decidimos alargar los chasis a nuevas dimensiones de 17,5x15 cm para poder implementar una fuente de alimentación y distribuir el voltaje: 5V para el Arduino y 3,3V para la ESP32-CAM.

- También notamos en esa primera regional que los sensores de ultrasonido deben apuntar hacia abajo, pues si están en la parte superior pueden detectar objetos externos a la pista. Utilizamos el mismo razonamiento para ubicar la cámara apuntando hacia abajo.

##  **PARA LA VUELTA LIBRE**

- Originalmente pensamos que el carro se detuviera al detectar la primera pared y, con el radar, definir hacia qué dirección tenía que girar. Esto lo realizaría una sola vez y después, con el sentido definido, giraría automáticamente en esa dirección al detectar una pared a unos 50 cm de distancia. Sin embargo, esta idea no funcionó bien, pues la programación se complicó y el servo, junto con el ultrasonido, fallaban constantemente.

- Tras la primera regional, decidimos dejar atrás la idea del radar e implementar los tres sensores de ultrasonido y la cámara ESP32-CAM tal y como fue explicado anteriormente. Con esto, desarrollamos un nuevo plan para la vuelta libre como se detalla a continuación.

- El carro debe guardar las tres distancias que detectan los sensores de ultrasonido al encenderse, de tal forma que pueda definir en qué recuadro de los seis posibles se encuentra el punto de salida.

- Cuando el carro avance y uno de los ultrasonidos laterales detecte una distancia mayor a un metro, es porque debe haber un vacío y, por tanto, debe girar hacia ese vacío.

- Si el carro no queda en paralelo a las paredes o queda apuntando hacia una pared después del giro, entonces debe acomodarse. Por tanto, si la distancia de un ultrasonido lateral a la pared es menor a 15 cm, debe girar un poco al lado contrario para despegarse de la pared.

- Después de dar las tres vueltas, el carro —a una velocidad lenta— debe buscar llegar a las medidas iniciales para estacionarse en el punto de inicio.

- En general, el carro debe ir a una velocidad controlada para dar suficiente tiempo a los sensores de detectar el entorno.

## **PARA LA VUELTA DE OBSTÁCULOS**

- Dividimos los cuadros grandes de la pista en tres carriles: derecho, central e izquierdo. Con esto definimos tres funciones para el carro: ir al carril derecho, al central y al izquierdo. De esta forma, si detecta un obstáculo rojo irá al carril derecho y, tras pasarlo, se devolverá al carril central; análogamente, hará lo mismo pero hacia la izquierda si detecta un obstáculo verde.

- La función de volver al carril central después de evadir un obstáculo es necesaria, pues en un cuadro grande puede haber varios y lo ideal es que el carro se mantenga en el centro para evadirlos y girar más fácilmente. Además, el carro puede encontrarse con el aparcadero y provocar una falla de lógica, por ello debe mantenerse siempre en el carril central.

- Al llegar a un cuadro grande de esquina (es decir, una pared), el carro debe girar hacia atrás en sentido contrario al vacío y quedar centrado apuntando hacia él. Esto asegura que cuando llegue a una nueva pared vuelva a quedar centrado.

- Después de dar las tres vueltas, el carro debe dar otra vuelta adicional y mantenerse pegado a la pared, de tal forma que no se desalineé. Cuando detecte el aparcadero debe ejecutar una función de aparcado, que consiste en evadirlo, quedarse quieto con el aparcadero al lado, girar hacia atrás en sentido opuesto a donde se encuentra el aparcadero (de tal forma que quede viendo hacia él de frente, similar a como se explica cuando el carro llega a un cruce), y finalmente moverse hacia adelante hasta entrar en el aparcadero.

- En general, el carro debe ir a una velocidad muy controlada para dar suficiente tiempo a la cámara de detectar el entorno.

- No se utilizan mucho los sensores de ultrasonido en la vuelta de obstáculos, pues pueden confundirse fácilmente con los mismos obstáculos. Se prioriza el uso de la cámara.