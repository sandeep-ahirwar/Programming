//ced19i011-Sandeep Ahirwar

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

//global variable
int xmin, xmax, ymin, ymax;

// Initialize OpenGL Graphics
void initGL() {
    //set bg
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //black and opaque
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-800, 800, -600, 600);
}

void plot(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}


//dda line drawing algorithm
void DDA(int x_1, int y_1, int x_2, int y_2){
    int x,y,dx,dy;
    glColor3f(1,1,1);

    dx = abs(x_2-x_1);
    dy = abs(y_2-y_1);

    int len;
    if(dx>=dy) len = dx;
    else len = dy;

    dx = (x_2-x_1)/len;
    dy = (y_2-y_1)/len;

    x=x_1;
    y=y_1;

    for(int i=1; i<=len; i++){
        plot(x,y);
        x+=dx;
        y+=dy;
    }
}


void clip_points(){
    int x,y;
    int n = 200;
    glColor3f(1,1,0);

    while(n>0){
        x=rand()%1000-500;
        y=rand()%600-300;
        if(x>xmin && x<xmax && y>ymin && y<ymax) plot(x,y);

        n--;
    }
}


void display(){
    //drawing clipping rectangle
    
    xmin = -500;
    xmax = 500;
    ymin = -300;
    ymax = 300;

    DDA(xmin, ymin, xmax, ymin);
    DDA(xmax, ymin, xmax, ymax);
    DDA(xmax, ymax, xmin, ymax);
    DDA(xmin, ymax, xmin, ymin);

    clip_points();

    glFlush();
}




int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("CED19I011 - Points Clipping");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
 }
