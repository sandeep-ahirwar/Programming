#include <GL/glut.h>
#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>
#include <math.h>
int n = 300;
int n1 = 300;
float alpha,Beta;
float rx,ry, cx, cy;

void changeViewPort(int w, int h);
void Draw_ellipse(int x,int y,int a,int b);
void Decision_oct(float x,float y);
void Decision_oct_ellipse(float x,float y);
void ellipse_drawing(float a,float b);
void display();

void myMouseHandleFunction(int button, int state, int x, int y){
   if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
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
   
    default:
        break;
    }
}

void randomPoints(){
    alpha  = rand()%180;
    Beta = rand()%360;
    rx = rand()%200;
    ry = rand()%200;
    cx = rand()%100;
    cy = rand()%100;
}


void drawPoint(int x, int y){
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2i(x,y);
    glEnd();
}

void display()
{
    glClearColor(1, 1, 1, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);

    glPointSize(3.0f);

    ellipse_drawing(0,0);

    glFlush(); // Render now
}



void changeViewPort(int w, int h)
{
if(w>=h)
glViewport(w/2-h/2, 0, h, h);
else
glViewport(0, h/2-w/2, w, w);
}


void Draw_ellipse(int x,int y,int a,int b)
{
    drawPoint(a+x, b+y);
    drawPoint(a-x, b+y);
    drawPoint(a-x, b-y);
    drawPoint(a+x, b-y);
}

void ellipse_drawing(float a,float b)
{

    randomPoints();
    float x = 0;
  float y = ry;
   
   int rys = ry*ry;
   int rxs = rx*rx;
   int p1 = rys - rxs*ry + (rxs/4);
   //region 1
   do
   {
        if(p1<0)
        {
            p1 = p1 + 2*rys*x + 3*rys;
        }
        else
        {
           y = y - 1;
           p1 = p1 +  2*rys*x + 3*rys - 2*rxs*y;  
        }
        x++;
        Decision_oct_ellipse(x,y);
   } while(rys*x<=rxs*y);


   //region 2
   float p2 = ((rys) * ((x + 0.5) * (x + 0.5))) + ((rxs) * ((y - 1) * (y - 1))) - (rxs * rys);

   do
   {
     if(p2>0) p2 = p2 - 2*rxs*y + 3*rxs;
     else
     {
        x = x + 1;
        p2 = p2 - 2*rxs*y + 3*rxs + 2*rys*x;
     }
    y--;

    Decision_oct_ellipse(x,y);
   } while (y>0);
}




void Decision_oct_ellipse(float x,float y)
{
    float low = 0;
    float high = Beta;

    float angle;
   
    angle = (180/M_PI) * atan2(y,x) + 0;
    if(angle>=low && angle<=high) drawPoint(x,y);

    angle = (180/M_PI) * atan2(y,-x) + 0;
    if(angle>=low && angle<=high) drawPoint(-x,y);

    angle = (180/M_PI) * atan2(-y,-x) + 360;
    if(angle>=low && angle<=high) drawPoint(-x,-y);

    angle = (180/M_PI) * atan2(-y,x) + 360;
    if(angle>=low && angle<=high) drawPoint(x,-y);


}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("Ellipse Arcs Drawing");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);// Create a window with the given title
    glutInitWindowSize(720,720);          // Set the window's initial width & height
    glutInitWindowPosition(100, 100);      // Position the window's initial top-left corner
    glutDisplayFunc(display);              // Register display callback handler for window re-paint
    glutMouseFunc(myMouseHandleFunction);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(changeViewPort);
    glutMainLoop();                        // Enter the event-processing loop
    return 0;
}