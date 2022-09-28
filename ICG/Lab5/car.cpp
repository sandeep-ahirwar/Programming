#include <GL/glut.h>
using namespace std;
#include <bits/stdc++.h>
#include <math.h>

int x_1;
int y_1;
int r;


void drawPoint(int x, int y){
	glBegin(GL_POINTS);
	glColor3f(0.5f, 0.5f, 0.0f);
	glVertex2i(x,y);
	glEnd();
}

void circlePoint(int x, int y){
	glBegin(GL_POINTS);
	glColor3f(0.5f, 0.5f, 0.0f);
	glVertex2i(x+x_1,y+y_1);
	glEnd();
}

void MCD(){
	int x = r;
	int y = 0;

	float dp = 5/4 -r;
	circlePoint(x,y);

	while(x>y){
		if(dp<0){
			y++;
			dp += 2*y +1;
		}
		else{
			x--;
			y++;
			dp += 2*(y-x) +1;
		}

		circlePoint(x,y);
		circlePoint(x,-y);
		circlePoint(-x,y);
		circlePoint(-x,-y);
		circlePoint(y,x);
		circlePoint(y,-x);
		circlePoint(-y,x);
		circlePoint(-y,-x);
	}
}


void BLD(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1,step;
	float x, y;
	
	x = x1;
	y = y1;

	int x_add = dx/abs(dx);
	int y_add = dy/abs(dy);
	    drawPoint(x,y);
		glEnd();
		if (abs(dx) > abs(dy))
		{
			float p = (2 * abs(dy)) - abs(dx);
			for (int i = 0; i < abs(dx); i++)
			{
				// cout << p << " ";
				if (p >= 0)
				{
					y = y + y_add;
					p = p + 2 * abs(dy) - 2*abs(dx);
				}
				else
				{
					p = p + 2 * abs(dy);
				}
				x = x + x_add;
				drawPoint(x,y);
			}
	    }
		else
		{
			float p = (2 * abs(dx)) - abs(dy);
			for (int i = 0; i < abs(dy); i++)
			{
				// cout << p << " ";
				if (p >= 0)
				{
					x = x + x_add;
					p = p + 2 * abs(dx) - 2 * abs(dy);
				}
				else
				{
					p = p + 2 * abs(dx);
				}
				y = y + y_add;
				drawPoint(x,y);
			}
		}
}

void car(){

	BLD(-100,-50, 100, -50);
	BLD(-100, 0, -40, 0);
	BLD(-100,-50, -100, 0);
	BLD(100,-50, 100, 0);
	BLD(100, 0, 80, 50);
	BLD(-40, 0, -10, 50);
	BLD(-10, 50, 80, 50);

	BLD(-5, 45, 30, 45);
	BLD(40, 45, 75, 45);
	BLD(30, 45, 30, 5);
	BLD(40, 45, 40, 5);
	BLD(40, 5, 90, 5);
	BLD(30, 5, -30, 5);
	BLD(-30, 5, -5, 45);
	BLD(90, 5, 75, 45);

   //right wheel
	r = 20;
	x_1= 70;
	y_1 = -50;
	MCD();  //circle function

	//left wheel
	r = 20;
	x_1= -40;
	y_1 = -50;
	MCD();  //circle function

	// for(int i=20; i>=0; i--){
	// 	x_1 = 70;
	// 	y_1 = -50;
	// 	r = i;
	// 	MCD();
	// }

	// for(int i=20; i>=0; i--){
	// 	x_1= -40;
	// 	y_1 = -50;
	// 	r = i;
	// 	MCD();
	// }
}

void display()
{
    glClearColor(0, 0, 0, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-120, 120, -120,120);
    glPointSize(2.0f);

    car();

    glFlush(); // Render now
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                 		// Initialize GLUT
    glutCreateWindow("Car using BLD and MCD");  // Create a window with the given title
    glutInitWindowSize(320, 320);          		// Set the window's initial width & height
    glutInitWindowPosition(100, 100);      		// Position the window's initial top-left corner
    glutDisplayFunc(display);             		// Register display callback handler for window re-paint
    glutMainLoop();                       		// Enter the event-processing loop
    return 0;
}