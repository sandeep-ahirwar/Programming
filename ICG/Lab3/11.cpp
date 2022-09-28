#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

void initGL() {
	//set bg
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //black and opaque
}

void display(){
 	glClear(GL_COLOR_BUFFER_BIT);

 	glBegin(GL_QUADS);
 		glColor3f(1.0f, 0.0f, 0.0f);
 		//lower rectangle
 		glVertex2f(-0.5f, -0.40f);
 		glVertex2f(-0.2f, -0.40f);
 		glVertex2f(-0.2f, -0.38f);
 		glVertex2f(-0.5f, -0.38f);
 		
 		glVertex2f(-0.4f, -0.38f);
 		glVertex2f(-0.3f, -0.38f);
 		glVertex2f(-0.3f, 0.38f);
 		glVertex2f(-0.4f, 0.38f);

 		glVertex2f(0.5f, -0.40f);
 		glVertex2f(0.2f, -0.40f);
 		glVertex2f(0.2f, -0.38f);
 		glVertex2f(0.5f, -0.38f);
 		
 		glVertex2f(0.4f, -0.38f);
 		glVertex2f(0.3f, -0.38f);
 		glVertex2f(0.3f, 0.38f);
 		glVertex2f(0.4f, 0.38f);
 	glEnd();

 	glBegin(GL_TRIANGLES);
 		glColor3f(1.0f, 0.0f, 0.0f);
 		glVertex2f(-0.3f, 0.38f);
 		glVertex2f(-0.3f, 0.48f);
 		glVertex2f(-0.5f, 0.38f);

 		glVertex2f(0.4f, 0.38f);
 		glVertex2f(0.4f, 0.48f);
 		glVertex2f(0.2f, 0.38f);
 	glEnd();

 	glFlush();
 }


 int main(int argc, char** argv){
 	glutInit(&argc, argv);
 	glutCreateWindow("Lab 3 Custom Shapes");
 	glutInitWindowSize(1080, 720);
 	glutInitWindowPosition(50,50);
 	glutDisplayFunc(display);
 	initGL();
 	glutMainLoop();
 	return 0;
 }