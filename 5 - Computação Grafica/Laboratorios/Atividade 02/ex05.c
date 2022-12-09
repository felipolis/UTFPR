#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// Desenhar uma casa

int init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 50;
	GLfloat twicePi = 2.0f * 3.1415;

	glColor3ub(0, 0, 255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhar circulo
    drawFilledCircle(100, 75, 30);
    
        
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(400, 300);

    glutCreateWindow("Exemplo de programa OpenGL");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}