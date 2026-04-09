#include <GL/glew.h>
#include <GL/freeglut.h> 
#define _USE_MATH_DEFINES
#include <cmath>
#include "maya.h"
#include "shaza.h"
#include "Merna.h"

const int NUM_STARS = 400;
float starX[NUM_STARS];
float starY[NUM_STARS];
static bool isAnimate = 0;
static int animationPeriod = 25;
float earthAngle = 0.0;
float VenusAngle = 0.0;
float MarsAngle = 0.0;



void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)w / (float)h;

    if (aspect >= 2.5f) {
        float orthoHeight = 270.0f;
        float orthoWidth = orthoHeight * aspect;
        glOrtho(-orthoWidth, orthoWidth, -orthoHeight, orthoHeight, -1, 1);
    }
    else {
        float orthoWidth = 675.0f;
        float orthoHeight = orthoWidth / aspect;
        glOrtho(-orthoWidth, orthoWidth, -orthoHeight, orthoHeight, -1, 1);
    }

    glutPostRedisplay();
}

void initStars()
{
    for (int i = 0; i < NUM_STARS; i++)
    {
        starX[i] = rand() % 1350;
        starY[i] = rand() % 540;
    }
}


void drawStars()
{
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);

    for (int i = 0; i < NUM_STARS; i++)
    {
        glVertex2f(starX[i] - 675, starY[i] - 270);
    }
    glEnd();
}


void drawSun()
{

    glBegin(GL_TRIANGLE_FAN);

    int numVert = 500;
    float R = 40;
    float t = 0.0;

    glColor3f(250.0 / 255, 215.0 / 255, 17.0 / 255);
    glVertex2f(0, 0);

    for (int i = 0; i <= numVert; ++i) {
        glColor3f(227.0 / 255, 120.0 / 255, 14.0 / 255);
        float x = 0 + R * cos(t);
        float y = 0 + R * sin(t);
        glVertex2f(x, y);
        t += 2.0 * M_PI / numVert;
    }

    glEnd();
}



void increaseEarthAngle() {

    earthAngle += 0.01;

    if (earthAngle > 360) {
        earthAngle -= 360;
    }

    glutPostRedisplay();


}

void increaseVenusAngle()
{
    VenusAngle += 0.01 * (365.25 / 224.7);

    if (VenusAngle > 360) {
        VenusAngle -= 360;
    }

    glutPostRedisplay();

}
void increaseMarsAngle() {
    MarsAngle += 0.01 * (365.25 / 686.97);  
    if (MarsAngle > 360) {
        MarsAngle -= 360;
    }
    glutPostRedisplay();
}

void animate(int value) {

    if (isAnimate) {

        increaseEarthAngle();

        increaseVenusAngle();

		increaseMarsAngle(); 

        glutPostRedisplay();

        glutTimerFunc(animationPeriod, animate, 1);

    }
}


void init()
{
    glClearColor(19.0 / 255, 19.0 / 255, 33.0 / 255, 1.0);
    initStars();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    drawStars();

    drawSun();

    glTranslatef(175 * (cos(earthAngle)), 175 * (sin(earthAngle)), 0);
   
    DrawEarth();

    glLoadIdentity();

    glTranslatef(113.5 * cos(VenusAngle), 113.5 * sin(VenusAngle), 0);

    DrawVenus();

    glLoadIdentity();

    glTranslatef(240 * cos(MarsAngle), 240 * sin(MarsAngle), 0);  

    DrawMars();

    glFlush();


}


void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case ' ':
        if (isAnimate) {
            isAnimate = false;
            glutIdleFunc(NULL);
        }
        else
        {
            isAnimate = true;
            animate(1);
        }
        break;
    }
}

void specialKeyInput(int key, int x, int y)
{
    if (key == GLUT_KEY_DOWN)
    {
        animationPeriod += 1;
    }
    if (key == GLUT_KEY_UP)
    {
        if (animationPeriod > 1) {
            animationPeriod -= 1;
        }
    }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 200);
    glutCreateWindow("Solar System");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
    animate(1);


    glutMainLoop();
}