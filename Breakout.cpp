
#include "Breakout.h"

using namespace std;

void recomputeFrame(int value);

Breakout::Breakout() {
    init();
}

Breakout::~Breakout() {

}

void Breakout::display(void) {

    // Limpiar buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Configuración del OpenGL para 2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
    glOrtho(0.0f, WINWIDTH, WINHEIGHT, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Dibujar fondo
    drawBackground();

    // Selecciona que estado del juego se va a mostrar
    switch (gameState) {
        case INIT:
            WelcomeScreen();
            break;
            
        case Gameplay:
            // Dibuja el juego
            drawGame();
            // Si no hay bolas, el jugador pierde
            if (balls.size() <= 0 & lifesCount > 0) {
                newBall(-1, -1);
                lifesCount--;
                
            } else if (balls.size() <= 0) {
                LoseScreen();
        
            }
            
            // Si no hay bloques el jugador gana
            if (bricks.size() <= 0 && level <= 2) {
                level++;
                initBricks();
            } else if (bricks.size() <= 0) {
                WinScreen();
            }
            break;
            
        case Win:
            WinScreen();
            break;

        case LOSE:
            LoseScreen();
            break;
        
        default:
            break;
    }
    
    glutTimerFunc(TIMER, recomputeFrame, 0);
    
    glutSwapBuffers();
}

void recomputeFrame(int value) {
	glutPostRedisplay();
}

void Breakout::WelcomeScreen(void){
    glColor3f(1,0,0);
    glRasterPos2f(315, 300);
    char msg1[]= "Crazy Breakout";
    for(int i=0; i<strlen(msg1); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);
    }
    glColor3f(1,1,1);
    glRasterPos2f(30, 50);
    char msg2[]= "Proyecto 1";
    for(int i=0; i<strlen(msg2); i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg2[i]);
    }
    glColor3f(1,1,1);
    glRasterPos2f(580,540);
    char msg3[]= "Presiona p para jugar";
    for(int i=0; i<strlen(msg3); i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg3[i]);
    }
    gameState = Breakout::INIT;
}
void Breakout::WinScreen(void){
    gameState = Breakout::Win;
    glColor3f(1,0,0);
    glRasterPos2f(315, 300);
    char msg1[]= "Ganaste";
    for(int i=0; i<strlen(msg1); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);
    }
    glColor3f(1,1,1);
    glRasterPos2f(190,380);
    char msg3[]= "Presiona p para volver a jugar y esc para salir";
    for(int i=0; i<strlen(msg3); i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg3[i]);
    }
    glutPostRedisplay;
}
void Breakout::LoseScreen(void){
    gameState = Breakout::LOSE;
    glColor3f(1,0,0);
    glRasterPos2f(315, 300);
    char msg1[]= "Perdiste";
    for(int i=0; i<strlen(msg1); i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);
    }
    glColor3f(1,1,1);
    glRasterPos2f(190,380);
    char msg3[]= "Presiona p para volver a jugar y esc para salir";
    for(int i=0; i<strlen(msg3); i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg3[i]);
    }
    glutPostRedisplay;
}

void Breakout::init(void) {
    // Resetea las estadísticas del juego
    score = 0;
    level = 1;
    reward = 0;
    lifesCount = 5;
    
    balls.clear();
    
    bricks.clear();
    
    initBricks();
    
    initPaddle();
    gameState = Breakout::Gameplay;
    // Inicia el juego
    
}


void Breakout::drawBackground(void) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);
    // Color de arriba
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(WINWIDTH, WINHEIGHT);
    glVertex2f(-WINWIDTH, WINHEIGHT);
    // Color de abajo
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();
}

void Breakout::drawGame(void) {
    
    //drawCoordinate();

    drawBalls();
    
    drawBricks();
    
    drawPaddle();
    
    drawGameStats();


}

void Breakout::newBall(float x = -1, float y = -1) {
    Ball b1;
    if (x < 0 || y < 0) {
        b1.xpos = WINWIDTH / 2.0;
        b1.ypos = WINHEIGHT - 30.0f;
    } else {
        b1.xpos = x;
        b1.ypos = y;
    }
    if ((float) rand() / (RAND_MAX) < 0.5)
        b1.xvel = 5.0f;
    else
        b1.xvel = -5.0f;
    b1.yvel = -10.0f;
    b1.radius = BALL_RADIUS;
    b1.r = 0.4f + (float) rand() / (RAND_MAX);
    b1.g = 0.25f + (float) rand() / (RAND_MAX);
    b1.b = 0.4f + (float) rand() / (RAND_MAX);
    balls.push_back(b1);
}

void Breakout::drawBalls(void) {
    for (std::vector<Ball>::iterator it = balls.begin(); it != balls.end(); ) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // use GL_LINE if no fill
        glBegin(GL_POLYGON);
        glColor3f(it->r, it->g, it->b);
        for(int j = 0; j < CIRCLE_SEGMENTS; j++) {
            float const theta = 2.0f * 3.1415926f * (float)j / (float)CIRCLE_SEGMENTS;
            float const x = it->radius * cosf(theta);
            float const y = it->radius * sinf(theta);
            glVertex2f(x + it->xpos, y + it->ypos);
        }
        glEnd();
        
        // Establece una nueva posición
        it->xpos += it->xvel;
        it->ypos += it->yvel;
        
        // Colisión con los lados izquierdo / derecho / superior de la ventana
        if ( (it->xpos <= (2 * it->radius)) || (it ->xpos >= (WINWIDTH - 2 * it->radius)) ) {
            it->xvel *= -1;
        }
        if ( (it->ypos <= (2 * it->radius)) ) {
            it->yvel *= -1;
        }
        if (it->ypos >= (WINHEIGHT - 2 * it->radius)) {
            it = balls.erase(it);
            paddle.width -= 15.0F;
            continue;
        }
        
        // Colisión con los bloques
        for (std::vector<Brick>::iterator br = bricks.begin(); br != bricks.end(); ) {
            
            // Comprueba la colisión entre la bola y los lados verticales del bloque.
            if (it->ypos >= br->ypos && it->ypos <= br->ypos + br->height) {
                
                // Borde derecho de bloque y punto izquierdo en la bola.
                if ((it->xpos - it->radius - br->xpos - br->width) <= 5 && (it->xpos - it->radius - br->xpos - br->width) >= 0) {
                    it->xvel *= -1;
                    br = hitBrick(br);

                    if(br->broke = true){
                        int reward_1;
                        int reward_2;
                        int reward_3;
                        if(br->score == 10){
                            reward_1 = 10;
                            score += reward_1;
                        }
                        else if(br->score == 15){
                            reward_2 = 15;
                            score += reward_2;
                        }
                        else if(br->score == 20){
                            reward_3 = 20;
                            score += reward_3;
                        }
                        else{
                            reward = 0;
                            score += reward;
                        }
                    }
                   
                
                    continue;
                   
                    
                } 
                
                // borde izquierdo del bloque y punto derecho en la bola.

                if ((it->xpos + it->radius - br->xpos) >= -5 && (it->xpos + it->radius - br->xpos) <= 0) {
                    it->xvel *= -1;
                    br = hitBrick(br);
                    if(br->broke = true){
                        int reward_1;
                        int reward_2;
                        int reward_3;
                        if(br->score == 10){
                            reward_1 = 10;
                            score += reward_1;
                        }
                        else if(br->score == 15){
                            reward_2 = 15;
                            score += reward_2;
                        }
                        else if(br->score == 20){
                            reward_3 = 20;
                            score += reward_3;
                        }
                        else{
                            reward = 0;
                            score += reward;
                        }
                    }
                    
                 
                    continue;
                    
                }
            }
            
            // Comprueba la colisión entre la bola y los lados horizontales del bloque.

            if (it->xpos >= br->xpos && it->xpos <= br->xpos + br->width) {
                // borde inferior del bloque y punto superior en la bola

                if ((it->ypos - it->radius - br->ypos - br->height) <= 10 && (it->ypos - it->radius - br->ypos - br->height) >= 0) {
                    it->yvel *= -1;
                    br = hitBrick(br);
                    if(br->broke = true){
                        int reward_1;
                        int reward_2;
                        int reward_3;
                        if(br->score == 10){
                            reward_1 = 10;
                            score += reward_1;
                        }
                        else if(br->score == 15){
                            reward_2 = 15;
                            score += reward_2;
                        }
                        else if(br->score == 20){
                            reward_3 = 20;
                            score += reward_3;
                        } 
                        else{
                            reward = 0;
                            score += reward;
                        }              
                    }
                   
                
                    continue;
                    
                }
                
                // borde superior del bloque y punto inferior en la bola
                if ((it->ypos + it->radius - br->ypos) >= -10 && (it->ypos + it->radius - br->ypos) <= 0) {
                    it->yvel *= -1;
                    br = hitBrick(br);
                    if(br->broke = true){
                        int reward_1;
                        int reward_2;
                        int reward_3;
                        if(br->score == 10){
                            reward_1 = 10;
                            score += reward_1;
                        }
                        else if(br->score == 15){
                            reward_2 = 15;
                            score += reward_2;
                        }
                        else if(br->score == 20){
                            reward_3 = 20;
                            score += reward_3;
                        }
                        else{
                            reward = 0;
                            score += reward;
                        }
                    }
                        
            
                    continue;
                   
                }
            }
            
            GLfloat d;
            // Comprueba la colisión con la esquina superior izquierda
            d = pow((it->xpos - br->xpos), 2.0) + pow((it->ypos - br->ypos), 2.0);
            if (d < it->radius + 5.0) {
                it->xvel *= -1;
                it->yvel *= -1;
                br = hitBrick(br);

                if(br->broke = true){
                    int reward_1;
                    int reward_2;
                    int reward_3;
                    if(br->score == 10){
                        reward_1 = 10;
                        score += reward_1;
                    }
                    else if(br->score == 15){
                        reward_2 = 15;
                        score += reward_2;
                    }
                    else if(br->score == 20){
                        reward_3 = 20;
                        score += reward_3;
                    }
                    else{
                        reward = 0;
                        score += reward;
                    }
                }
               
               
                continue;
                
                
            }

            // Comprueba la colisión con la esquina superior derecha
            d = pow((it->xpos - br->xpos - br->width), 2.0) + pow((it->ypos - br->ypos), 2.0);
            if (d < it->radius + 5.0) {
                it->xvel *= -1;
                it->yvel *= -1;
                br = hitBrick(br);
                if(br->broke = true){
                    int reward_1;
                    int reward_2;
                    int reward_3;
                    if(br->score == 10){
                        reward_1 = 10;
                        score += reward_1;
                    }
                    else if(br->score == 15){
                        reward_2 = 15;
                        score += reward_2;
                    }
                    else if(br->score == 20){
                        reward_3 = 20;
                        score += reward_3;
                    }
                    else{
                        reward = 0;
                        score += reward;
                    }
                }
                
                continue;
               
            }
           

            // Comprueba la colisión con la esquina inferior izquierda
            d = pow((it->xpos - br->xpos), 2.0) + pow((it->ypos - br->ypos - br->height), 2.0);
            if (d < it->radius + 5.0) {
                it->xvel *= -1;
                it->yvel *= -1;
                br = hitBrick(br);
                if(br->broke = true){
                    int reward_1;
                    int reward_2;
                    int reward_3;
                    if(br->score == 10){
                        reward_1 = 10;
                        score += reward_1;
                    }
                    else if(br->score == 15){
                        reward_2 = 15;
                        score += reward_2;
                    }
                    else if(br->score == 20){
                        reward_3 = 20;
                        score += reward_3;
                    }
                    else{
                        reward = 0;
                        score += reward;
                    }
                }
                
                
                continue;
             
            }
           
            
            // Comprueba la colisión con la esquina inferior derecha
            d = pow((it->xpos - br->xpos - br->width), 2.0) + pow((it->ypos - br->ypos - br->height), 2.0);
            if (d < it->radius + 5.0) {
                it->xvel *= -1;
                it->yvel *= -1;
                br = hitBrick(br);
                if(br->broke = true){
                    int reward_1;
                    int reward_2;
                    int reward_3;
                    if(br->score == 10){
                        reward_1 = 10;
                        score += reward_1;
                    }
                    else if(br->score == 15){
                        reward_2 = 15;
                        score += reward_2;
                    }
                    else if(br->score == 20){
                        reward_3 = 20;
                        score += reward_3;
                    }
                    else{
                        reward = 0;
                        score += reward;
                    }
                }
                
                continue;
                
            }
            
            ++br; // siguiente bloque
        }
        
        // Compruebe la colisión entre el borde superior del paddle y el punto inferior de la bola.
        if (it->xpos >= paddle.xpos && it->xpos <= paddle.xpos + paddle.width) {
            if ((it->ypos + it->radius - paddle.ypos) >= -10 && (it->ypos + it->radius - paddle.ypos) <= 0) {
                it->yvel *= -1;
                
                continue;
            }
        }
        
        ++it; // próxima bola
    }
}

void Breakout::initPaddle(void) {
    paddle.r = 0.2f;
    paddle.g = 0.5f;
    paddle.b = 1.0f;
    paddle.width = 150.0f;
    paddle.height = 12.0f;
    paddle.xpos = WINWIDTH / 2.0f - paddle.width / 2.0f;
    paddle.ypos = WINHEIGHT - 20.0f;
}

void Breakout::drawPaddle() {

    if (paddle.width < 25) {
        paddle.width = 25;
    }
    
    glColor3f(paddle.r, paddle.g, paddle.b);
    glRectf(paddle.xpos, paddle.ypos, paddle.xpos + 5.0f, paddle.ypos + paddle.height);
    glRectf(paddle.xpos + 10.0f, paddle.ypos, paddle.xpos + paddle.width - 10.0f, paddle.ypos + paddle.height);
    glRectf(paddle.xpos + paddle.width - 5.0f, paddle.ypos, paddle.xpos + paddle.width, paddle.ypos + paddle.height);
}

void Breakout::drawBricks(void) {
    for (std::vector<Brick>::iterator it = bricks.begin(); it != bricks.end(); ++it) {
        glColor3f(it->r, it->g, it->b);
        glRectf(it->xpos, it->ypos, it->xpos + it->width, it->ypos + it->height);
        
        
        glBegin(GL_QUADS);
        glColor3f(it->r-0.2f, it->g-0.2f, it->b-0.2f);
        glVertex2f(it->xpos, it->ypos);
        glColor3f(it->r-0.08f, it->g-0.08f, it->b-0.08f);
        glVertex2f(it->xpos + it->width, it->ypos);
        glColor3f(it->r-0.15f, it->g-0.15f, it->b-0.15f);
        glVertex2f(it->xpos + it->width, it->ypos + it->height);
        glVertex2f(it->xpos, it->ypos);
        glEnd();
    }
}

template <typename Iterator>
Iterator Breakout::hitBrick(Iterator brick) {
    
    
    // Decrece la salud del bloque
    if (brick->health > 2) {
        brick->health -= 1;
        return ++brick;
    }
    else if (brick->health > 1) {
        brick->health -= 1;
        return ++brick;
    }
    else {
        return bricks.erase(brick);
        brick->broke = true;
    }
    
    
}


void Breakout::initBricks(void) {
    if (level == 1)
        bricksLevel1();
    else if (level == 2)
        bricksLevel2();
    
}

void Breakout::bricksLevel1(void) {
    Brick newBrick;
    newBrick.r;
    newBrick.g;
    newBrick.b;
    newBrick.health;
    newBrick.score;
    newBrick.broke;
    newBrick.width = (WALLWIDTH - (WALLCOLS - 2) * WALLSPACE) / WALLCOLS;
    newBrick.height = (WALLHEIGHT - (WALLROWS - 2) * WALLSPACE) / WALLROWS;

    
    

    for (int i = 0; i < WALLROWS; ++i) {
        for (int j = 0; j < WALLCOLS; ++j) {

            if (i+1 > ceil(WALLROWS / 2.0) - 2 && i < ceil(WALLROWS / 2.0) + 2 && j+2 > ceil(WALLCOLS / 2.0) - 3 && j < ceil(WALLCOLS / 2.0) + 3) {
                newBrick.r = 1.0f;
                newBrick.g = 0.5f;
                newBrick.b = 0.5f;
                newBrick.health = 2;
                newBrick.score = 15;
                newBrick.broke = false;
               
            }
            else if (i+1 > ceil(WALLROWS / 2.0) - 2 && i < ceil(WALLROWS / 2.0) + 4 && j+4 > ceil(WALLCOLS / 2.0) - 2 && j < ceil(WALLCOLS / 2.0) + 3){
                newBrick.r = 6.0f;
                newBrick.g = 0.9f;
                newBrick.b = 0.4f;
                newBrick.health = 3;
                newBrick.score = 20;
                newBrick.broke = false;
  
            } 
            
            else {
                newBrick.r = 0.95f;
                newBrick.g = 0.95f;
                newBrick.b = 0.95f;
                newBrick.health = 1;
                newBrick.score = 10;
                newBrick.broke = false;
            
            }
            
            newBrick.xpos = WALLX + j * newBrick.width + j * WALLSPACE;
            newBrick.ypos = WALLY + i * newBrick.height + i * WALLSPACE;
            bricks.push_back(newBrick);
        }
    }
}

void Breakout::bricksLevel2(void) {
    Brick newBrick;
    newBrick.width = (WALLWIDTH - (WALLCOLS - 2) * WALLSPACE) / WALLCOLS;
    newBrick.height = (WALLHEIGHT - (WALLROWS - 2) * WALLSPACE) / WALLROWS;
    
    for (int i = 0; i < WALLROWS; i++) {
        for (int j = 0; j < WALLCOLS; j++) {
        
            if (i == 1 || i == WALLROWS - 2 || j == 1 || j == WALLCOLS - 2) {
                newBrick.r = 1.0f;
                newBrick.g = 0.5f;
                newBrick.b = 0.5f;
                newBrick.health = 2;
                newBrick.score = 15;
                newBrick.broke = false;
                 
            } 
            else if (i+1 > ceil(WALLROWS / 2.0) - 2 && i < ceil(WALLROWS / 2.0) + 4 && j+5 > ceil(WALLCOLS / 2.0) - 3 && j < ceil(WALLCOLS / 2.0) + 8){
                newBrick.r = 6.0f;
                newBrick.g = 0.9f;
                newBrick.b = 0.4f;
                newBrick.health = 3;
                newBrick.score = 20;
                newBrick.broke = false;
                
            } 
            else {
                newBrick.r = 0.95f;
                newBrick.g = 0.95f;
                newBrick.b = 0.95f;
                newBrick.health = 1;
                newBrick.score = 10;
                newBrick.broke = false;

            }
            
            newBrick.xpos = WALLX + j * newBrick.width + j * WALLSPACE;
            newBrick.ypos = WALLY + i * newBrick.height + i * WALLSPACE;
            bricks.push_back(newBrick);
        }
    }
}


void Breakout::drawGameStats(void) {
    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(20.0f, 30.0f);
    glVertex2f(WINWIDTH - 20.0f, 30.0f);
    glEnd();
    
    float offset = 25.0f;
    for (int i = 0; i < lifesCount & i < 10; ++i) {
        drawLife(35 + offset * i, 15);
    }
    
    drawScore();
}

void Breakout::drawLife(float x, float y) {

    float const scale = 0.5f;
    
    // Heart symbol equations from Walfram Mathworld: http://mathworld.wolfram.com/HeartCurve.html
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.2f, 0.2f);
    for(int j = 0; j < CIRCLE_SEGMENTS; j++) {
        float const theta = 2.0f * 3.1415926f * (float)j / (float)CIRCLE_SEGMENTS;
        float const xx = scale * 16.0f * sinf(theta) * sinf(theta) * sinf(theta);
        float const yy = -1 * scale * (13.0f * cosf(theta) - 5.0f * cosf(2.0f * theta) - 2 * cosf(3.0f * theta) - cosf(4.0f * theta));
        glVertex2f(x + xx, y + yy);
    }
    glEnd();
}

void Breakout::drawScore(void) {
    glPushMatrix();
    // Escribe la palabra "Score"
    glColor3f(1.0f, 0.7f, 0.7f);
    glRasterPos2f(WINWIDTH - 120, 20);
    char buf[300], *p;
    p = buf;
    sprintf(buf, "Score: ");
    do glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p); while(*(++p));
    // Muestra el score
    p = buf;
    sprintf(buf, "           %d", score);
    glColor3f(1.0f, 0.2f, 0.2f);
    glRasterPos2f(WINWIDTH - 120, 20);
    do glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p); while(*(++p));
    glPopMatrix();
}

void Breakout::drawCoordinate(void) {
    glBegin(GL_LINES);
        // Top left (white)
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(20.0f, 10.0f);
        glVertex2f(20.0f, 30.0f);
        glVertex2f(10.0f, 20.0f);
        glVertex2f(30.0f, 20.0f);
    
        // Bottom right (red)
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(WINWIDTH - 20.0f, WINHEIGHT - 10.0f);
        glVertex2f(WINWIDTH - 20.0f, WINHEIGHT - 30.0f);
        glVertex2f(WINWIDTH - 10.0f, WINHEIGHT - 20.0f);
        glVertex2f(WINWIDTH - 30.0f, WINHEIGHT - 20.0f);
    glEnd();
}

void Breakout::reshape(int width, int height) {
    if (width != WINWIDTH || height != WINHEIGHT)
        glutReshapeWindow(WINWIDTH, WINHEIGHT);
}



void Breakout::mouseMove(int x, int y) {
    y = WINHEIGHT - y;
    if (x - paddle.width / 2.0f >= 0 && x + paddle.width / 2.0f <= WINWIDTH) {
        paddle.xpos = x - paddle.width / 2.0f;
    } else if (x - paddle.width / 2.0f <= 0) {
        paddle.xpos = 0;
    } else if (x + paddle.width / 2.0f >= WINWIDTH) {
        paddle.xpos = WINWIDTH - paddle.width;
    }
	glutPostRedisplay();
}

void Breakout::keyStroke(unsigned char key, int x, int y) {
    switch (key) {
        case 'p': // New game
            init();
            break;
        case 27: // Esc button
            exit(0);
            break;
        default:
            break;
    }
}

void Breakout::specialKeyPos(int key, int x, int y) {
    switch(key)
	{
		case GLUT_KEY_LEFT:
            if (paddle.xpos > 0) {
                paddle.xpos -= 5.0f;
                paddle.xpos -= 5.0f;
                glutPostRedisplay();
                paddle.xpos -= 5.0f;
                paddle.xpos -= 5.0f;
                glutPostRedisplay();
            }
            break;
        case GLUT_KEY_RIGHT:
            if (paddle.xpos + paddle.width < WINWIDTH) {
                paddle.xpos += 5.0f;
                paddle.xpos += 5.0f;
                glutPostRedisplay();
                paddle.xpos += 5.0f;
                paddle.xpos += 5.0f;
                glutPostRedisplay();
            }
            break;
        default:
            break;
    }
}
