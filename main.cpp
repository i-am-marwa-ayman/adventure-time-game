//-lGL -lGLU -lglut
#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


int finX = -60;
int finY = -10;

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
void coloredPixel(int x, int y, float red, float green, float blue){
    glColor3f(red/255.0,green/255.0,blue/255.0);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
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
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-60, 60, -40, 40);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    background();
    drawfin();
    glFlush(); 
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    std::srand(std::time(nullptr)); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200,800);
    glutCreateWindow("window");
    glutDisplayFunc(display);
    glutMainLoop();
}