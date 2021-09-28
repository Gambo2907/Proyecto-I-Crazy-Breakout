/**
*@file config.h
*@version 1.0
*@date 22-09-21
*@author Gustavo Gamboa // Adrian Rodríguez
*@brief Configuraciones del juego
*/

#ifndef crazyBreakout_config_h
#define crazyBreakout_config_h

#define TIMER 16.6          // 60 FPS

/**
 * @brief Configuraciones de la ventana del juego y su menú
 */
#define WINTITLE "Breakout Game"
const int WINWIDTH  = 800;
const int WINHEIGHT = 600;
const int WINWIDTH2  = 800;
const int WINHEIGHT2 = 600;

/**
 * @brief Configuraciones de las paredes para la creación de bloques
 */
const int WALLWIDTH = 700;                          // Ancho de la pared
const int WALLHEIGHT = 180;                         // Largo de la pared
const float WALLX = (WINWIDTH - WALLWIDTH) / 2.0f;  // Punto x de inicio de la pared
const float WALLY = WALLX + 40;                     // Punto y de inicio de la pared
const int WALLSPACE = 3;                            // Espacio entre bloques
const int WALLCOLS = 15;                            // Contador de las columnas de la pared
const int WALLROWS = 10;                            // Contador de las filas de la pared


const float PEDALWIDTH = 150.0f;
const float PEDALHEIGHT = 12.0f;

/**
 * @brief Configuraciones de la bola
 */
const float BALL_RADIUS = 6.0f;
const int CIRCLE_SEGMENTS = 50; 

#endif
