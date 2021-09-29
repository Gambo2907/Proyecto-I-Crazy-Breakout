/**
*@file Breakout.h
*@version 1.0
*@date 22-09-21
*@author Gustavo Gamboa // Adrian Rodríguez
*@brief Funciones para el juego y el servidor
*/

#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#if defined(__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include "glut.h"
#endif

#include "MyObjects.h"      // Objetos del juego
#include "config.h"         // Configuraciones del juego

/**
 * @class Breakout
 * @brief Clase principal donde se crea todo el juego
 * 
 */
class Breakout {

public:
    // Class Constructor/Destructor
	Breakout();
	~Breakout();
    
    /**
     * @brief Crea la ventana de inicio del juego
     * 
     */
    void WelcomeScreen(void);
    /**
     * @brief Función por la cual pasan las ventanas que contiene el juego
     * 
     */
	void display(void);
    /**
     * @brief Inicializa el juego
     * 
     */
	void init(void);
    /**
     * @brief Crea la ventana de victoria
     * 
     */
    void WinScreen(void);
    /**
     * @brief Crea la ventana de derrota
     * 
     */
    void LoseScreen(void);
    /**
     * @brief Inicializa el tamaño de la ventana del juego
     * @param widht ancho
     * @param height largo
     */
	void reshape(int width, int height);
    /**
     * @brief Logra parametrizar los movimientos del mouse
     * @param x
     * @param y
     */
	void mouseMove(int x, int y);
    /**
     * @brief Logra conocer cuando se toca una tecla
     * @param key
     * @param x
     * @param y
     */
	void keyStroke(unsigned char key, int x, int y);
    /**
     * @brief Logra conocer cuando se toca el click derecho e izquierdo del mouse
     * @param key
     * @param x
     * @param y
     */
	void specialKeyPos(int key, int x, int y);
    
    
    
private:
    /**
     * @brief puntaje del juego
     */
    int score;
    /**
     * @brief niveles
     */
    int level;
    /**
     * @brief recompensa por los bloques destruídos
     */
    int reward;
    /**
     * @brief contador de vidas
     */
    int lifesCount;
    
    /**
     * @enum State
     * @brief Diferentes fases en la que la pantalla del juego puede estar
     * @param INIT inicializa el juego con el menú principal
     * @param Gameplay inicializa en juego con todos sus objetos
     * @param Win muestra la pantalla de victoria
     * @param LOSE muestra la pantalla de derrota
     */
    enum State {INIT, Gameplay, Win, LOSE};
    Breakout::State gameState;
    
    // Balls
    std::vector <Ball> balls;
    
    // Paddle
    Paddle paddle;
    
    // Bricks
    std::vector<Brick> bricks;
    
    // Private functions
    /**
     * @brief Crea el fondo del juego y de las ventanas
     * 
     */
    void drawBackground(void);
    /**
     * @brief Dibuja los elementos del juego
     * 
     */
    void drawGame(void);
    /**
     * @brief Crea una nueva bola
     * @param x posición x
     * @param y posición y
     */
    void newBall(float x, float y);
    /**
     * @brief Dibuja las bolas para mostrarlas en el juego
     * 
     */
    void drawBalls(void);
    /**
     * @brief Inicializa el paddle
     * 
     */
    void initPaddle(void);
    /**
     * @brief Crea el paddle para mostrarlo en el juego
     * 
     */
    void drawPaddle(void);
    /**
     * @brief Inicializa los bloques del juego
     * 
     */
    void initBricks(void);
    /**
     * @brief Creación de los bloques para el nivel 1 del juego
     * 
     */
    void bricksLevel1(void);
    /**
     * @brief Creación de los bloques para el nivel 2 del juego
     * 
     */
    void bricksLevel2(void);
    /**
     * @brief Muestra los bloques en la pantalla del juego
     * 
     */
    void drawBricks(void);
    /**
     *@brief iterador para corroborar las colisiones con la pared de la bola 
    */
    template <typename Iterator>
    /**
     * @brief Corrobora las colisiones con la pared de la bola
     * @param it
     */
    int wallCollision(Iterator it);
    /**
     *@brief iterador para corroborar las colisiones con los bloques de la bola 
    */
    template <typename Iterator>
    /**
     * @brief Corrobora las colisiones con los bloques de la bola
     * @param it 
     * @param br 
     */
    bool brickCollision(Iterator it, Iterator br);
    /**
     *@brief iterador para corroborar las colisiones con los bloques de la bola 
    */
    template <typename Iterator>
    /**
     * @brief Elimina los bloques de acuerdo a su estado
     * @param brick  
     * 
     */
    Iterator hitBrick(Iterator brick);
    
    /**
     * @brief Muestra la vidas restantes en pantalla
     * @param x posición x
     * @param y posición y
     * 
     */
    void drawLife(float x, float y);
    /**
     * @brief Muestra los stats del juego
     * 
     */
    void drawGameStats(void);
    /**
     * @brief Muestra el puntaje conseguido en el juego
     * 
     */
    void drawScore(void);
    /**
     * @brief Muestra las coordenadas del juego
     * 
     */
    void drawCoordinate(void);
};

#endif 
