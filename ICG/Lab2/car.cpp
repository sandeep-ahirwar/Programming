#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

// Initialize OpenGL Graphics
void initGL() {
	//set bg
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //black and opaque
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 3.1415926 * 2 / float(num_segments);
    float tangetial_factor = tanf(theta);//calculate the tangential factor 

    float radial_factor = cosf(theta);//calculate the radial factor 

    float x = r;//we start at angle = 0 

    float y = 0;
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //calculate the tangential vector 
        //remember, the radial vector is (x, y) 
        //to get the tangential vector we flip those coordinates and negate one of them 

        float tx = -y;
        float ty = x;

        //add the tangential vector 

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        //correct using the radial factor 

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

 void display(){
 	glClear(GL_COLOR_BUFFER_BIT);
    

 	glBegin(GL_LINE_LOOP);
 		//car base outline
 		glColor3f(1.0f, 1.0f, 1.0f);
 		glVertex2f(-0.8f, -0.45f);
 		glVertex2f(0.8f, -0.45f);
 		glVertex2f(0.8f, 0.0f);
 		glVertex2f(0.6f, 0.5f);
        glVertex2f(-0.1f,0.5f);
        glVertex2f(-0.3f, 0.0f);
        glVertex2f(-0.8f, 0.0f);
 		
 	glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.8f, 0.8f, 0.8f);
        glVertex2f(-0.27f, 0.03f);
        glVertex2f(0.235f, 0.03f);
        glVertex2f(0.235f, 0.48f);
        glVertex2f(-0.08f, 0.48f);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.77f,0.03f);
        glVertex2f(0.58f, 0.48f);
        glVertex2f(0.255f, 0.48f);
        glVertex2f(0.255f, 0.03f);
        
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    drawCircle(0.5, -0.45, 0.2, 100);
    drawCircle(-0.4, -0.45, 0.2, 100);


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