#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Initialize OpenGL Graphics
void initGL() {
	//set bg
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //black and opaque
}

 void display(){
 	glClear(GL_COLOR_BUFFER_BIT);

 	glBegin(GL_QUADS);
 		//big wall
 		glColor3f(0.2f, 0.7f, 0.9f);
 		glVertex2f(-0.5f, 0.0f);
 		glVertex2f(0.5f, 0.0f);
 		glVertex2f(0.5f, -1.0f);
 		glVertex2f(-0.5f, -1.0f);

 		//door	
 		glColor3f(1.0f, 1.0f, 1.0f);
 		glVertex2f(-0.1f, -0.5f);
 		glVertex2f(0.1f, -0.5f);
 		glVertex2f(0.1f, -1.0f);
 		glVertex2f(-0.1f, -1.0f);

 		//left window
 		glColor3f(1.0f, 1.0f, 1.0f);
 		glVertex2f(-0.4f, -0.5f);
 		glVertex2f(-0.2f, -0.5f);
 		glVertex2f(-0.2f, -0.7f);
 		glVertex2f(-0.4f, -0.7f);

 		//right window
 		glColor3f(1.0f, 1.0f, 1.0f);
 		glVertex2f(0.4f, -0.5f);
 		glVertex2f(0.2f, -0.5f);
 		glVertex2f(0.2f, -0.7f);
 		glVertex2f(0.4f, -0.7f);
 	glEnd();

 	glBegin(GL_TRIANGLES);
 		//shed
 		glColor3f(1.0f, 0.0f, 0.0f);
 		glVertex2f(-0.5f, 0.0f);
 		glVertex2f(0.5f, 0.0f);
 		glVertex2f(0.0f, 0.8f);
 	glEnd(); 

 	glFlush();
 }


 int main(int argc, char** argv){
 	glutInit(&argc, argv);
 	glutCreateWindow("Vertex, Primitive & Color");
 	glutInitWindowSize(720, 720);
 	glutInitWindowPosition(50,50);
 	glutDisplayFunc(display);
 	initGL();
 	glutMainLoop();
 	return 0;
 }