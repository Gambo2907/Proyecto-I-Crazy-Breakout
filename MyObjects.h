/**
*@file MyObjects.h
*@version 1.0
*@date 22-09-21
*@author Gustavo Gamboa // Adrian Rodríguez
*@brief Objetos principales del juego
*/

#ifndef crazyBreakout_MyObjects_h
#define crazyBreakout_MyObjects_h

/**
 * @struct Ball
 * @brief Parametiza los atributos que necesita la bola
 * 
 */
struct Ball {
        /**
 * @param xpos posición x de la bola
 * @param ypos posición y de la bola
 */
    GLfloat xpos, ypos;
    /**
 * @param xvel velocidad x de la bola
 * @param yvel velocidad y de la bola
 */
    GLfloat xvel, yvel;
        /**
 * @param radius radio de la bola 
 */
    GLfloat radius;
        /**
 * @brief colores de la bola
 */
    GLfloat r, g, b;
};

/**
 * @struct Paddle
 * @brief Parametiza los atributos que necesita el paddle
 * 
 */
struct Paddle {
       /**
 * @param xpos posición x del paddle
 * @param ypos posición y del paddle
 */
    GLfloat xpos, ypos;
       /**
 * @param width ancho del paddle
 * @param height largo y del paddle
 */
    GLfloat width, height;
       /**
 * @brief color del paddle
 */
    GLfloat r, g, b;
};

/**
 * @struct Brick
 * @brief Parametiza los atributos que necesitan los bloques
 * 
 */
struct Brick {
    /**
 * @param xpos posición x del bloque
 * @param ypos posición y del bloque
 * 
 */
    GLfloat xpos, ypos;
       /**
 * @param width ancho del bloque
 * @param height largo del bloque
 * 
 */
    GLfloat width, height;
       /**
 * @brief colores de los bloques
 * 
 */
    GLfloat r, g, b;
   /**
 * @param health salud del bloque, con esto se crean bloques 
 * que necesiten más de un golpe para ser borrados 
 * 
 */
    GLint health;
   /**
 * @param score puntaje que genera el bloque
 * 
 */
    GLint score;
       /**
 * @param broke confirma si el bloque está eliminado o no
 */
    GLboolean broke;
};

#endif
