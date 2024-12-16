//-lGL -lGLU -lglut
#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

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
void coloredRec(int start, int end, float red, float green, float blue){
    glColor3f(red/255.0,green/255.0,blue/255.0);
    glBegin(GL_QUADS);
    glVertex2f(-60, start);
    glVertex2f(60, start);
    glVertex2f(60, end);
    glVertex2f(-60, end);
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
    coloredRec(40, 25, 80, 184, 231);
    coloredRec(25, 10, 132, 205 ,238);
    coloredRec(10, -5, 185, 226, 245);
    coloredRec(-5, -20, 220, 240, 260);

    coloredDotStrip(25, 132, 205, 238, 2);
    coloredDotStrip(24, 80, 184, 231, 3);

    coloredDotStrip(10, 185, 226, 245, 3);
    coloredDotStrip(9, 132, 205 ,238, 4);
    
    coloredDotStrip(-5, 220, 240, 260, 4);
    coloredDotStrip(-6, 185, 226, 245, 5);

    coloredDotStrip(-20, 34, 139, 34, 2);
    coloredRec(-20, -40, 34, 139, 34);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-60, 60, -40, 40);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    background();
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