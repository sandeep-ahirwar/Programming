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
	else {
		for(int i=x1-1; i>x2; i--){
			y1-=m;
			glBegin(GL_POINTS);
	        glVertex2i(i,y1);
	        glEnd();
		}
	}

	glFlush();

}


void display(){
	dda(40,120,80,80);
	dda(80,80,140,80);
	dda(140,80,180, 120);
	dda(80,170,140,170);
	dda(180,120,140,170);
	dda(80,170, 40,120);
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
