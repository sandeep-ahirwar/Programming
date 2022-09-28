#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include <bits/stdc++.h>

using namespace std;

int Mode;
float focus;

void changeViewPort(int w, int h)
{
    if (w >= h)
        glViewport(w / 2 - h / 2, 0, h, h);
    else
        glViewport(0, h / 2 - w / 2, w, w);
}

void myinit(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D (0.0,1000.0,0.0,1000.0);
    glMatrixMode(GL_MODELVIEW);
}

float RandomColor()
{
    float color=(float)((rand() % 100))/99;
    return color;    
}

struct Parabola
{
    float c[2];
    float a;
};

void plot(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(round(x), round(y));
    glEnd();
}



void PlotQuandrants(float c[2], float x, float y, int q[4])
{
    if (q[0] == 1)
        plot(c[0] + x, c[1] + y); //Q1
    if (q[1] == 1)
        plot(c[0] - x, c[1] + y); //Q2
    if (q[2] == 1)
        plot(c[0] - x, c[1] - y); //Q3
    if (q[3] == 1)
        plot(c[0] + x, c[1] - y); //Q4
}

void PlotParabola(Parabola P, int x, int y)
{
    int quads[4] = {0};
    //x2=4ay
    if (P.a > 0)
        quads[0] = quads[1] = 1;
    else
        quads[2] = quads[3] = 1;
    PlotQuandrants(P.c, y, x, quads);
   
}

void PARAMETRIC(Parabola P)
{
    float a = abs(P.a);
    float x = 0;
    float y = 0;
    float t = 0;
    while (y < 2000)
    {
        x = a * t * t;
        y = 2 * a * t;
        PlotParabola(P, x, y);
        t += 0.001;
    }
}

void parabolaAlgo(Parabola P)
{
    float a = abs(P.a);
    float x = 0;
    float y = 0;

    float p = 1 - 2 * a;
    float ymid = 2 * a;
    while (y <= ymid)
    {
        PlotParabola(P, x, y);
        if (p < 0) p += 2 * y + 3;
        else
        {
            x++;
            p += 2 * y + 3 - 4 * a;
        }
        y++;
    }

    while (x < 2000)
    {
        PlotParabola(P, x, y);
        if (p > 0) p += -4 * a;

        else
        {
            p += -4 * a + 2 * y + 2;
            y++;
        }

        x++;
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(3);
    glColor3f(RandomColor(), RandomColor(), RandomColor());
    Parabola P = {{(400+float(rand()%200)), (400+float(rand()%200))}, focus};
    parabolaAlgo(P);
    glutSwapBuffers();
}

void PARA_plot()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(3);
    glColor3f(RandomColor(), RandomColor(), RandomColor());
    Parabola P = {{(400+float(rand()%200)), (400+float(rand()%200))}, focus};
    PARAMETRIC(P);
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        display();
    }

}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 97:
        display();
        break;

    case 100:
        display();
        break;

    case 115:
        display();
        break;

    case 119:
        display();
        break;


    default:
        break;
    }
}

int main(int argc, char **argv)
{
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);
 
    focus = 40 ;

    glutCreateWindow("Parabola using MidPoint Algo");
    glutInitWindowPosition(200, 200);
    myinit();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutReshapeFunc(changeViewPort);
    glutMainLoop();
}