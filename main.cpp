//-lGL -lGLU -lglut
#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


int finX = -60;
int finY = -10;
int finMove = 0;
int coinX = 54;
int coinY = -2;
int coin = 1;
int batteryX = -56;
int batteryY = 36;
int gainedCoins = 0;

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
void drawfin(){
    //head
    coloredRec(finX + 2, finX + 12, finY - 1, finY - 11,255,255,255);
    coloredRec(finX + 4, finX + 10, finY - 3, finY - 8,253,220,179);
    coloredRec(finX + 3, finX + 11, finY - 4, finY - 7,253,220,179);
    
    //body
    coloredRec(finX + 2, finX + 12, finY - 9, finY - 13,161,212,255);
    coloredRec(finX + 2, finX + 12, finY - 13, finY - 15,38,160,241);
    
    //back
    coloredRec(finX + 1, finX + 3, finY - 8, finY - 11,149,203,79);
    coloredRec(finX + 11, finX + 13, finY - 8, finY - 11,149,203,79);

    //hand 
    coloredRec(finX + 1, finX + 2, finY - 9, finY - 12,253,220,179);
    coloredRec(finX + 12, finX + 13, finY - 9, finY - 12,253,220,179);
    

    //smile
    coloredRec(finX + 4, finX + 5, finY - 5, finY - 6,0,0,0);
    coloredRec(finX + 9, finX + 10, finY - 5, finY - 6,0,0,0);
    coloredRec(finX + 6, finX + 8, finY - 6, finY - 7,0,0,0);

    //black outline
    coloredRec(finX + 2, finX + 4, finY, finY - 1,0,0,0);
    coloredRec(finX + 10, finX + 12, finY, finY - 1,0,0,0);
    coloredRec(finX + 4, finX + 10, finY - 1, finY - 2,0,0,0);
    coloredRec(finX + 1, finX + 2, finY - 1, finY - 8,0,0,0);
    coloredRec(finX + 12, finX + 13, finY - 1, finY - 8,0,0,0);
    
    coloredRec(finX, finX + 1, finY - 8, finY - 12,0,0,0);
    coloredRec(finX + 13, finX + 14, finY - 8, finY - 12,0,0,0);

    coloredRec(finX + 1, finX + 2, finY - 12, finY - 15,0,0,0);
    coloredRec(finX + 12, finX + 13, finY - 12, finY - 15,0,0,0);
    
    coloredRec(finX + 2, finX + 5, finY - 15, finY - 16,0,0,0);
    coloredRec(finX + 9, finX + 12, finY - 15, finY - 16,0,0,0);
    coloredRec(finX + 5, finX + 9, finY - 14, finY - 15,0,0,0);
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
void drawBattery(){
    coloredRec(batteryX + 0, batteryX + 12, batteryY - 1, batteryY - 6,0,0,0);
    coloredRec(batteryX + 1, batteryX + 11, batteryY - 0, batteryY - 7,0,0,0);
    coloredRec(batteryX + 12, batteryX + 13, batteryY - 2, batteryY - 5,0,0,0);

    coloredRec(batteryX + 1, batteryX + 11, batteryY - 1, batteryY - 6,255,255,255);

    for (int i = 0; i < 3; i++){
        if (i < gainedCoins){
            coloredRec(batteryX + 2 + i * 3, batteryX + 4 + i * 3, batteryY - 2, batteryY - 4, 251, 2, 0);
            coloredRec(batteryX + 2 + i * 3, batteryX + 4 + i * 3, batteryY - 4, batteryY - 5, 169, 8, 14);
        } else{
            coloredRec(batteryX + 2 + i * 3, batteryX + 4 + i * 3, batteryY - 2, batteryY - 4, 215, 215, 215);
            coloredRec(batteryX + 2 + i * 3, batteryX + 4 + i * 3, batteryY - 4, batteryY - 5, 167, 167, 167);
        }
    }
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-60, 60, -40, 40);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    background();
    drawBattery();
    drawfin();
    if(coin){
        drawCoin();
    }
    glFlush(); 
}
bool touched(){
    return finX + 16 > coinX && finX < coinX && coinY - 3 < finY;
}
void timeC(int){
    glutPostRedisplay();
    glutTimerFunc(5000, timeC, 0);
    coin = 1;
}
void time(int){
    glutPostRedisplay();
    glutTimerFunc(30, time, 0);
    // mode 0 no specail move 
    // mode 1 jump up
    // mode 2 return down
    // keep moving x to make it more realistic
    //charX++;
    finX++;
    if(finMove == 1){
        finY++;
    } else if(finMove == 2){
        finY--;
    }
    if(finY == -10){
        finMove = 0;
    } else if(finY == 0){
        finMove = 2;
    }
    if(finX > 60){
        finX = -60;
    }

    if (coin){
        coinX--;
        if (coinX < -60){
            coin = 0;
            coinX = 60;
        }
        if(coin && touched()){
            gainedCoins++;
            coin = 0;
            coinX = 60;
        }
    }
}

void handleSpecialKeys(int key, int x, int y) {
    glutPostRedisplay();
    if(key == GLUT_KEY_UP){
        finMove = 1;
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
    glutTimerFunc(5000, timeC, 0);
    glutMainLoop();
}