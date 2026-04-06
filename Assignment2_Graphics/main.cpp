#include <GL/glew.h>
#include <GL/freeglut.h> 
#define _USE_MATH_DEFINES
#include <cmath>



const int NUM_STARS = 200;
float starX[NUM_STARS];
float starY[NUM_STARS];

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)w / (float)h;

    if (aspect >= 2.5f) {  
        float orthoHeight = 100.0f;
        float orthoWidth = orthoHeight * aspect;
        glOrtho(-orthoWidth, orthoWidth, -orthoHeight, orthoHeight, -1, 1);
    }
    else {
        float orthoWidth = 250.0f;
        float orthoHeight = orthoWidth / aspect;
        glOrtho(-orthoWidth, orthoWidth, -orthoHeight, orthoHeight, -1, 1);
    }

    glutPostRedisplay();
}

void initStars()
{
    for (int i = 0; i < NUM_STARS; i++)
    {
        starX[i] = rand() % 500;
        starY[i] = rand() % 200;
    }
}


void drawStars()
{
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);

    for (int i = 0; i < NUM_STARS; i++)
    {
        glVertex2f(starX[i]-250 , starY[i]-100);
    }
    glEnd();
}


void drawSun()
{
    
	glBegin(GL_TRIANGLE_FAN);

    int numVert = 500;
    float R = 40;
    float t = 0.0;

	glColor3f(250.0/255, 215.0 / 255, 17.0 / 255);
    glVertex2f(0, 0);

    for (int i = 0; i <= numVert; ++i) {
        glColor3f(227.0/255, 120.0 / 255, 14.0 / 255);
        float x = 0 + R * cos(t);
        float y = 0 + R * sin(t);
        glVertex2f(x, y);
        t += 2.0 * M_PI / numVert;
    }

    glEnd();
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

    glFlush();
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


    glutMainLoop();
}