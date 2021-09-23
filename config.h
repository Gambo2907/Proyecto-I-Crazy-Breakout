/**
*@file config.h
*@version 1.0
*@date 22-09-21
*@author Gustavo Gamboa // Adrian Rodríguez
*@brief Configuraciones del juego
*/

#ifndef crazyBreakout_config_h
#define crazyBreakout_config_h

// Force Redraw timer
#define TIMER 16.6          // 60 frame per second

/**
 * @brief Configuraciones de la ventana del juego y su menú
 */
#define WINTITLE "Breakout Game"
const int WINWIDTH  = 800;
const int WINHEIGHT = 600;
#define WINTITLE2 "Breakout Game Menu"
const int WINWIDTH2  = 800;
const int WINHEIGHT2 = 600;

/**
 * @brief Configuraciones de las paredes para la creación de bloques
 */
const int WALLWIDTH = 700;                          // Wall width
const int WALLHEIGHT = 180;                         // Wall height
const float WALLX = (WINWIDTH - WALLWIDTH) / 2.0f;  // Wall start point(x)
const float WALLY = WALLX + 40;                     // Wall start point(y)
const int WALLSPACE = 3;                            // Space between bricks
const int WALLCOLS = 15;                            // Wall columns count
const int WALLROWS = 10;                            // Wall rows count


const float PEDALWIDTH = 150.0f;
const float PEDALHEIGHT = 12.0f;

/**
 * @brief Configuraciones de la bola
 */
const float BALL_RADIUS = 6.0f;
const int CIRCLE_SEGMENTS = 50; 

#endif
