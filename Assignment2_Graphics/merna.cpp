#include <GL/glew.h>
#include <GL/freeglut.h> 
#define _USE_MATH_DEFINES
#include <cmath>
#include "Merna.h"

void DrawMars() {
    float marsRadius = 20.6;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.69f, 0.25f, 0.10f);  
    glVertex2f(0, 0);
    for (int i = 0; i <= 100; i++)
    {
        glColor3f(0.85f, 0.35f, 0.15f);  
        float angle = i * 2 * M_PI / 100;
        glVertex2f(marsRadius * cos(angle), marsRadius * sin(angle));
    }
    glEnd();
}