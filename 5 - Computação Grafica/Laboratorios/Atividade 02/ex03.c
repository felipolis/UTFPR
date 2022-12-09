#include <stdio.h>
#include <GL/glut.h>

// Desenhar uma casa

int init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhar a estrela
    glColor3ub(218, 165, 32);
    glBegin(GL_POLYGON);
        glVertex2i(40, 60);
        glVertex2i(10, 60);
        glVertex2i(30, 40);
        glVertex2i(20, 10);
        glVertex2i(50, 30);
        glVertex2i(80, 10);
        glVertex2i(70, 40);
        glVertex2i(90, 60);
        glVertex2i(60, 60);
        glVertex2i(50, 90);
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