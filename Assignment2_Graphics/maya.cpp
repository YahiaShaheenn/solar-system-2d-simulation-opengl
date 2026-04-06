#include <GL/glew.h>
#include <GL/freeglut.h> 
#define _USE_MATH_DEFINES
#include <cmath>
#include "maya.h"

void DrawEarth() {

    float earthRadius = 19.6;

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.0468, 0.52, 0.1493);
    glVertex2f(0,0);

    for (int i = 0; i <= 100; i++)
    {
        glColor3f(0, 0.4667, 1);
        float angle = i * 2 * M_PI / 100;
        glVertex2f(0 + earthRadius * cos(angle), 0 + earthRadius * sin(angle));
    }

    glEnd();

}





