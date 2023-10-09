# Quintetos
Desarrollado por:
Gonzalo José Peña Franco y Juan Pablo Diez.

Juego de dados similar a la tradicional generala.
El objetivo del juego es obtener al menos 500 puntos en la menor cantidad posible de  rondas, o sacar una escalera en un lanzamiento.

Una ronda está compuesta por 3 lanzamientos. 
Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje.
El puntaje de un lanzamiento está determinado por una serie de reglas que figuran en la sección "Combinaciones ganadoras".

El puntaje final de la ronda será el valor máximo obtenido entre los 3 lanzamientos, con las siguientes excepciones:

- Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento
- Si en un lanzamiento se obtiene una combinación de 6 dados con valor 6, el puntaje de la ronda entera será 0.

Para el caso de la opción para 2 jugadores, los jugadores debe completar una ronda (3 lanzamientos) alternativamente.

# CARACTERISTICAS Y FUNCIONALIDADES:

* Se inicia un juego nuevo para uno ó dos jugador/es.

* Antes de comenzar a jugar se solicita el nombre del jugador/es.

* A medida que avanza el juego,s e muestra el nombre del jugador, el número de ronda, y el puntaje correspondiente a ese momento.

* Cuando finaliza un turno y comienza el otro, se muestra en pantalla a quién le corresponde el próximo turno, el número de ronda y los puntajes de ambos jugadores. En el caso de que sea un juego para un jugador, se indica el número de ronda, el nombre del jugador y el puntaje.

* Existe la posibilidad de empate. Esto ocurre cuando ambos jugadores logran los 500 puntos o más en la misma ronda.

* Si luego de una cantidad de rondas establecidas al inicio de la partida no hubo ningún jugador que haya obtenido los 500 puntos, el ganador de la partida será aquel que haya obtenido el puntaje más alto.


* Una vez finalizada la partida, se muestra el nombre del jugador/es y el puntaje obtenido durante el juego.

* Si se desea comprobar el funcionamiento correcto el juego permite simular jugadas. 


*COMBINACIONES GANADORAS:

SUMA DE DADOS: Menos de 3 dados con valores iguales. Se suman los valores de todos los dados.
Ejemplo: 6+5+5+2+2+1= 21 puntos

TRIO X++(X es el numero del dado): 3 dados o más con el mismo valor (hasta 5 iguales). Se sumaría como X*10,
En el caso de que haya dos ternas de dados se debe elegir aquel que otorgue mayor cantidad de puntos.
Ejemplo:5,5,5,1,2,3 es decir 5*10=50 puntos.

SEXTETO X: Seis dados iguales, excepto el numero 6. Se sumaría como X*50.
Ejemplo:5,5,5,5,5,5 es decir 5*50= 250 puntos.

ESCALERA: 1,2,3,4,5,6. En este caso el jugador gana la partida en esa ronda.

SEXTETO6 6,6,6,6,6,6. El jugador pierde todos los puntos de esa ronda.
