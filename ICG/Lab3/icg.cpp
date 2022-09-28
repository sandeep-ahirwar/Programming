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

struct Circle // centre (x,y) ; Radius (rx,ry) 
{
       
        float x;
        float y;
        float rx;
        float ry;
   
};

void display(){
 	glClear(GL_COLOR_BUFFER_BIT);

 	glBegin(GL_QUADS);
 		glColor3f(1.0f, 0.0f, 0.0f);
 		//lower rectangle
 		glVertex2f(-0.5f, -0.40f);
 		glVertex2f(-0.2f, -0.40f);
 		glVertex2f(-0.2f, -0.38f);
 		glVertex2f(-0.5f, -0.38f);
 		//upper rectangle
 		glVertex2f(-0.5f, 0.40f);
 		glVertex2f(-0.2f, 0.40f);
 		glVertex2f(-0.2f, 0.38f);
 		glVertex2f(-0.5f, 0.38f);
 		//middle rectangle
 		glVertex2f(-0.4f, -0.38f);
 		glVertex2f(-0.3f, -0.38f);
 		glVertex2f(-0.3f, 0.38f);
 		glVertex2f(-0.4f, 0.38f);
 	glEnd();

 	Circle inner_C = {0.05f,0.0f,0.1f,0.35f};
	Circle outer_C = {0.05f,0.0f,0.2f,0.4f};
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f);
	int flag=1;
	for(float i =M_PI*1.7;i>=M_PI*0.3;i-=0.001) // radians
	{
	    if(flag==0){
	    glVertex2f(outer_C.x +outer_C.rx*cos(i),outer_C.y+outer_C.ry*sin(i)); // x+r*cosA,y+r*sinA 
	    flag = 1;
		}

	else{
	    glVertex2f(inner_C.x +inner_C.rx*cos(i),inner_C.y+inner_C.ry*sin(i)); // x+r*cosA,y+r*sinA       
	    flag=0; 
	    }     
	}
   
	glEnd();


	inner_C = {0.45f,0.0f,0.1f,0.35f};
	outer_C = {0.45f,0.0f,0.2f,0.4f};
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f);
	flag=1;
	for(float i =M_PI*1.7;i>=M_PI*0.3;i-=0.001) // radians
	{
	    if(flag==0){
	    glVertex2f(outer_C.x +outer_C.rx*cos(i),outer_C.y+outer_C.ry*sin(i)); // x+r*cosA,y+r*sinA 
	    flag = 1;
		}

	else{
	    glVertex2f(inner_C.x +inner_C.rx*cos(i),inner_C.y+inner_C.ry*sin(i)); // x+r*cosA,y+r*sinA       
	    flag=0; 
	    }     
	}

   
	glEnd();

	glBegin(GL_QUADS);
 		glColor3f(1.0f, 0.0f, 0.0f);
 		glVertex2f(0.50f, -0.30f);
 		glVertex2f(0.57f, -0.33f);
 		glVertex2f(0.57f, -0.15f);
 		glVertex2f(0.50f, -0.15f);

 		glVertex2f(0.45f, -0.15f);
 		glVertex2f(0.62f, -0.15f);
 		glVertex2f(0.62f, -0.13f);
 		glVertex2f(0.45f, -0.13f);

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