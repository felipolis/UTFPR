#include <stdio.h>
#include <GL/glut.h>

int init(void){
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 255, 0);
        glVertex2i(30, 10);

        glColor3ub(255, 0, 0);
        glVertex2i(150, 10);

        glColor3ub(0, 0, 255);
        glVertex2i(90, 120);
    glEnd();

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