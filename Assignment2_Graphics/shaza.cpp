#include <GL/glew.h>
#include <GL/freeglut.h> 
#define _USE_MATH_DEFINES
#include <cmath>
#include "shaza.h"

void DrawVenus()
{
	float VenusRadius = 18.6;

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.95f, 0.85f, 0.55f);
    glVertex2f(0, 0);

    for (int i = 0; i <= 100; i++)
    {
        
    glColor3f(0.75f, 0.3101f, 0.2325);
        float a = i * 2 * M_PI / 100;
        glVertex2f (VenusRadius * cos(a),  VenusRadius * sin(a));
    }

    glEnd();
}
