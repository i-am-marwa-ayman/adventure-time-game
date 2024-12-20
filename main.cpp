//-lGL -lGLU -lglut
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


float finnX = -60;
float finnY = -10;
int finnMove = 0;
float batteryX = -56;
float batteryY = 36;
float wallX = 5;
float wallY = -18;
int wall = 0;
float coinX = 54;
float coinY = -2;
int gainedCoins = 0;
int coin = 1;
int dead = 0;


void coloredDotStrip(int start, float red, float green, float blue, int inc){
    glColor3f(red/255.0,green/255.0,blue/255.0);
    for(int i = -60;i < 60;i += inc){
        glBegin(GL_QUADS);
        glVertex2f(i, start);
        glVertex2f(i + 1, start);
        glVertex2f(i + 1, start + 1);
        glVertex2f(i, start + 1);
        glEnd();
    }
}
void coloredRec(int startX, int endX, int startY, int endY, float red, float green, float blue){
    glColor3f(red/255.0,green/255.0,blue/255.0);
    glBegin(GL_QUADS);
    glVertex2f(startX, startY);
    glVertex2f(endX, startY);
    glVertex2f(endX, endY);
    glVertex2f(startX, endY);
    glEnd();
}
void background(){
    coloredRec(-60,60,40, 25, 80, 184, 231);
    coloredRec(-60,60,25, 10, 132, 205 ,238);
    coloredRec(-60,60,10, -5, 185, 226, 245);
    coloredRec(-60,60,-5, -20, 220, 240, 260);

    coloredDotStrip(25, 132, 205, 238, 2);
    coloredDotStrip(24, 80, 184, 231, 3);

    coloredDotStrip(10, 185, 226, 245, 3);
    coloredDotStrip(9, 132, 205 ,238, 4);
    
    coloredDotStrip(-5, 220, 240, 260, 4);
    coloredDotStrip(-6, 185, 226, 245, 5);

    coloredDotStrip(-20, 34, 139, 34, 2);
    coloredRec(-60,60,-20, -40, 34, 139, 34);
}
void drawfinn(){
    // head
    coloredRec(finnX + 2, finnX + 12, finnY - 1, finnY - 11,255,255,255);
    coloredRec(finnX + 4, finnX + 10, finnY - 3, finnY - 8,253,220,179);
    coloredRec(finnX + 3, finnX + 11, finnY - 4, finnY - 7,253,220,179);
    
    // body
    coloredRec(finnX + 2, finnX + 12, finnY - 9, finnY - 13,161,212,255);
    coloredRec(finnX + 2, finnX + 12, finnY - 13, finnY - 15,38,160,241);
    
    // back
    coloredRec(finnX + 1, finnX + 3, finnY - 8, finnY - 11,149,203,79);
    coloredRec(finnX + 11, finnX + 13, finnY - 8, finnY - 11,149,203,79);

    // hand 
    coloredRec(finnX + 1, finnX + 2, finnY - 9, finnY - 12,253,220,179);
    coloredRec(finnX + 12, finnX + 13, finnY - 9, finnY - 12,253,220,179);
    

    // smile
    coloredRec(finnX + 4, finnX + 5, finnY - 5, finnY - 6,0,0,0);
    coloredRec(finnX + 9, finnX + 10, finnY - 5, finnY - 6,0,0,0);
    coloredRec(finnX + 6, finnX + 8, finnY - 6, finnY - 7,0,0,0);

    // black outline
    coloredRec(finnX + 2, finnX + 4, finnY, finnY - 1,0,0,0);
    coloredRec(finnX + 10, finnX + 12, finnY, finnY - 1,0,0,0);
    coloredRec(finnX + 4, finnX + 10, finnY - 1, finnY - 2,0,0,0);
    coloredRec(finnX + 1, finnX + 2, finnY - 1, finnY - 8,0,0,0);
    coloredRec(finnX + 12, finnX + 13, finnY - 1, finnY - 8,0,0,0);
    
    coloredRec(finnX, finnX + 1, finnY - 8, finnY - 12,0,0,0);
    coloredRec(finnX + 13, finnX + 14, finnY - 8, finnY - 12,0,0,0);

    coloredRec(finnX + 1, finnX + 2, finnY - 12, finnY - 15,0,0,0);
    coloredRec(finnX + 12, finnX + 13, finnY - 12, finnY - 15,0,0,0);
    
    coloredRec(finnX + 2, finnX + 5, finnY - 15, finnY - 16,0,0,0);
    coloredRec(finnX + 9, finnX + 12, finnY - 15, finnY - 16,0,0,0);
    coloredRec(finnX + 5, finnX + 9, finnY - 14, finnY - 15,0,0,0);
}
void drawCoin(){
    coloredRec(coinX + 1, coinX + 4, coinY - 0, coinY - 5,215,99,2);
    coloredRec(coinX + 0, coinX + 5, coinY - 1, coinY - 4,215,99,2);
    coloredRec(coinX + 2, coinX + 5, coinY - 0, coinY - 5,255,210,28);
    coloredRec(coinX + 1, coinX + 6, coinY - 1, coinY - 4,255,210,28);
    coloredRec(coinX + 2, coinX + 5, coinY - 1, coinY - 4,255,165,2);
    coloredRec(coinX + 3, coinX + 5, coinY - 1, coinY - 2,215,99,2);
    coloredRec(coinX + 4, coinX + 5, coinY - 1, coinY - 4,215,99,2);
}
void drawWall(){
    // upper part
    coloredRec(wallX , wallX + 10, wallY , wallY - 4,0,0,0);
    coloredRec(wallX + 1, wallX + 9, wallY - 1, wallY - 3,0,209,3);
    coloredRec(wallX + 1, wallX + 3, wallY - 1, wallY - 3,12,153,15);
    coloredRec(wallX + 7, wallX + 9, wallY - 1, wallY - 3,176,251,185);

    // lower part
    coloredRec(wallX + 1, wallX + 9, wallY - 4, wallY - 8,0,0,0);
    coloredRec(wallX + 2, wallX + 8, wallY - 4, wallY - 7,0,209,3);
    coloredRec(wallX + 2, wallX + 4, wallY - 4, wallY - 7,12,153,15);
    coloredRec(wallX + 6, wallX + 8, wallY - 4, wallY - 7,176,251,185);
}
void drawBattery(){
    // outlines
    coloredRec(batteryX + 0, batteryX + 18, batteryY - 1, batteryY - 6,0,0,0);
    coloredRec(batteryX + 1, batteryX + 17, batteryY - 0, batteryY - 7,0,0,0);
    coloredRec(batteryX + 18, batteryX + 19, batteryY - 2, batteryY - 5,0,0,0);
    
    // white rec
    coloredRec(batteryX + 1, batteryX + 17, batteryY - 1, batteryY - 6,255,255,255);
    
    // charge
    for (int i = 0; i < 5; i++){
        if (i < gainedCoins){
            coloredRec(batteryX + 2 + i * 3, batteryX + 4 + i * 3, batteryY - 2, batteryY - 4, 251, 2, 0);
            coloredRec(batteryX + 2 + i * 3, batteryX + 4 + i * 3, batteryY - 4, batteryY - 5, 169, 8, 14);
        } else{
            coloredRec(batteryX + 2 + i * 3, batteryX + 4 + i * 3, batteryY - 2, batteryY - 4, 215, 215, 215);
            coloredRec(batteryX + 2 + i * 3, batteryX + 4 + i * 3, batteryY - 4, batteryY - 5, 167, 167, 167);
        }
    }
}
void drawDeadfinn(){
    int x = -8;
    int y = -8;
    coloredRec(x ,x + 15, y - 3, y - 16,50,40,77);
    coloredRec(x + 1, x + 14, y - 2, y - 3,50,40,77);
    coloredRec(x + 2, x + 13, y - 1, y - 2,50,40,77);

    coloredRec(x + 1,x + 14, y - 3, y - 15,76,83,122); 
    coloredRec(x + 2,x + 13, y - 2, y - 15,76,83,122);
    
    coloredRec(x + 2,x + 13, y - 4, y - 14,118,171,172); 
    coloredRec(x + 3,x + 12, y - 3, y - 15,118,171,172);
    
    coloredRec(x + 4,x + 5, y - 3, y - 4,76,83,122);
    coloredRec(x + 5,x + 6, y - 4, y - 5,76,83,122);

    coloredRec(x + 11,x + 13, y - 13, y - 15,76,83,122);
    coloredRec(x + 10,x + 11, y - 13, y - 14,76,83,122);
    coloredRec(x + 9,x + 11, y - 12, y - 13,76,83,122);
    
    // P
    coloredRec(x + 9,x + 10, y - 7, y - 11,50,40,77);
    coloredRec(x + 9,x + 12, y - 7, y - 8,50,40,77);
    coloredRec(x + 9,x + 12, y - 9, y - 10,50,40,77);
    coloredRec(x + 11,x + 12, y - 7, y - 10,50,40,77);
    
    // I
    coloredRec(x + 7,x + 8, y - 7, y - 11,50,40,77);
    
    // R
    coloredRec(x + 3,x + 4, y - 7, y - 11,50,40,77);
    coloredRec(x + 3,x + 6, y - 7, y - 8,50,40,77);
    coloredRec(x + 3,x + 5, y - 9, y - 10,50,40,77);
    coloredRec(x + 5,x + 6, y - 8, y - 9,50,40,77);
    coloredRec(x + 5,x + 6, y - 10, y - 11,50,40,77);

}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-60, 60, -40, 40);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    background();
    drawBattery();
    if(dead){
        drawDeadfinn();
    } else {
        drawfinn();
        if (wall){
            drawWall();
        }
        if (coin){
            drawCoin();
        }
    }
    glFlush(); 
}
bool gained(){
    return finnX + 16 > coinX && finnX < coinX && coinY - 3 < finnY;
}
bool fall(){
    return finnX + 16 > wallX && finnX < wallX && wallY > finnY - 15;
}
void time(int){
    glutPostRedisplay();
    glutTimerFunc(30, time, 0);

    // mode 0 no specail move 
    // mode 1 jump up
    // mode 2 return down
    // keep moving x to make it more realistic

    finnX++;

    if(finnMove == 1){
        finnY+=1;
    } else if(finnMove == 2){
        finnY-=1;
    }
    if(finnY == -10){
        finnMove = 0;
    } else if(finnY == 5){
        finnMove = 2;
    }
    if(finnX > 60){
        finnX = -60;
        int s = std::rand() % 4;
        coin = s & 1;
        wall = s & 2;
        coinX = 60;
        wallX = 60;
    }
    if (coin){
        coinX -= 1;
        if(gained()){
            gainedCoins++;
            coin = 0;
            coinX = 60;
        }
    }
    if(wall){
        wallX -= 1;
        if(fall()){
            if(gainedCoins == 0){
                dead = 1;
            }
            gainedCoins--;
            wall = 0;
            wallX = 60;
        }
    }
}

void handleSpecialKeys(int key, int x, int y) {
    glutPostRedisplay();
    if(key == GLUT_KEY_UP && finnMove == 0){
        finnMove = 1;
    }
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    std::srand(std::time(NULL)); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200,800);
    glutCreateWindow("window");
    glutDisplayFunc(display);
    glutSpecialFunc(handleSpecialKeys);
    glutTimerFunc(30, time, 0);
    glutMainLoop();
}