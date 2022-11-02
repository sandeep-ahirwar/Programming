//ced19i011-Sandeep Ahirwar

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

int xmin = -300;
int xmax = 300;
int ymin = -200;
int ymax = 200;

// Initialize OpenGL Graphics
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //black and opaque
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600.0, 600.0, -480.0, 480.0);
    glMatrixMode(GL_MODELVIEW);
}

void plot(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}


void DDA(int x_1, int y_1, int x_2, int y_2){
    int x,y,dx,dy;

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
    glEnd();
}


void display(){
    //drawing clipping rectangle
    glColor3f(1,1,0);
    DDA(xmin, ymin, xmax, ymin);
    DDA(xmax, ymin, xmax, ymax);
    DDA(xmax, ymax, xmin, ymax);
    DDA(xmin, ymax, xmin, ymin);
    glColor3f(1,1,1);
    int n=10;
    while(n>0){
        int x1,y1,x2,y2,dx,dy;
        int x3,y3,x4,y4;
        float temp,t1,t2,p[4],q[4];
        x1=rand()%900-455;
        y1=rand()%780-410;
        x2=rand()%900-455;
        y2=rand()%780-410;
        dx=x2-x1;
        dy=y2-y1;
        p[0]=-dx; 
        p[1]=dx; 
        p[2]=-dy; 
        p[3]=dy;
        q[0]=x1-xmin; 
        q[1]=xmax-x1;
        q[2]=y1-ymin; 
        q[3]=ymax-y1;
        
        for(int i=0; i<4; i++){
            if(p[i]==0){
                if(q[i]>=0){
                    if(i<2){
                        if(y1<ymin) y1=ymin;
                        if(y2>ymax) y2=ymax;
                        DDA(x1,y1,x2,y2);
                    }
                    if(i>1){
                        if(x1<xmin) x1=xmin;
                        if(x2>xmax) x2=xmax;
                        DDA(x1,y1,x2,y2);
                    }
                }
            }
        }
        t1=0;
        t2=1;
        for(int i=0;i<4;i++){
            temp=q[i]/p[i];
            if(p[i]<0) {
                if(t1<=temp)
                t1=temp;
            }
            else {
                if(t2>temp) 
                t2=temp;
            }
        }

        if(t1<t2){
            x3=x1+t1*p[1];
            y3=y1+t1*p[3];
            x4=x1+t2*p[1];
            y4=y1+t2*p[3];
            DDA(x3,y3,x4,y4);
        }
    n--;
    }
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("CED19I011 - Lines Clipping by Liang Barsky");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
 }
