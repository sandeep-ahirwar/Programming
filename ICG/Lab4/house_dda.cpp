#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Initialize OpenGL Graphics
void initGL() {
    //set bg
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //black and opaque
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,400,0,400);
}

//DDA Algorithm

void dda(float x1, float y1, float x2, float y2){
    float m = (y2-y1)/(x2-x1);

    //for m = infinity
    if(x2-x1 == 0){
        for(int i = y1+1; i<=y2; i++){
            glBegin(GL_POINTS);
            glVertex2i(x1,i);
            glEnd();
        }
    }

    //for m<= 1
    if (abs(m) <= 1){
        glBegin(GL_POINTS);
        glVertex2i(x1,y1);
        glEnd();

        for(int i = x1+1; i<=x2; i++){
            y1+=m;
            glBegin(GL_POINTS);
            glVertex2i(i,y1);
            glEnd();
        }
    }
    //for m > 1
    else {
        for(int i=x1-1; i>=x2; i--){
            y1-=m;
            glBegin(GL_POINTS);
            glVertex2i(i,y1);
            glEnd();
        }
    }

    glFlush();

}


void display(){
    dda(100,40,300,40); //baseline
    dda(100,240, 300,240);//paralle to baseline & traingle base
    dda(100,240, 200,300); //triangle right line
    dda(200,300, 300,240); ///triangle right line
    dda(300,40, 300,240); //right line
    dda(100,40,100,240); //left line

    dda(180,40, 180, 140); //left door line
    dda(220,40, 220, 140); //right door line
    dda(180,140,220,140); //door upper line

    //window left
    dda(120, 140,160, 140); //upper line
    dda(120, 100,160, 100); //below line
    dda(120, 100,120,140); //left line
    dda(160, 100,160,140); //right line


    //window right
    dda(240, 140, 280, 140);
    dda(240, 100,280, 100);
    dda(240, 100,240,140);
    dda(280, 100,280,140);
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Regular Hexagon");
    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
 }