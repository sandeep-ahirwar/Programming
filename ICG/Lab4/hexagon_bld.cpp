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

//BLD Algorithm

void bld(int x1, int y1, int x2, int y2){

    int x = x1;
    int y = y1;

    int dx = abs(x2-x1);
    int dy = abs(y2-y1);

    int p = 2*dx - dy;
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();

    while (x<=x2){
        
        x++;

        if(p<0){
            p += 2*dy;
        }
        else{
            p = p+(2*dy)-(2*dx);
            y++;
        }

        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }

    glFlush();
}


void display(){
	bld(40,120,80,80);
    // bld(200,80,80,80);

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