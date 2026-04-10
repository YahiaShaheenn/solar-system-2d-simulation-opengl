#include <GL/glew.h>
#include <GL/freeglut.h>
#define _USE_MATH_DEFINES
#include <cmath>

void DrawMercury()
{
    float mercuryRadius = 12.0;

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.85, 0.85, 0.85);
    glVertex2f(0, 0);

    int segments = 360; 

    for (int i = 0; i <= segments; i++)
    {
        float angle = i * 2.0f * M_PI / segments;

        glColor3f(0.5, 0.5, 0.5);

        glVertex2f(
            mercuryRadius * cos(angle),
            mercuryRadius * sin(angle)
        );
    }

    glEnd();
}