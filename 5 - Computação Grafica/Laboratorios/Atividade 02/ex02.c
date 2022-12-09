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

    // Desenhar a grama
    glColor3ub(0, 255, 0);
    glBegin(GL_LINES);
        glVertex2i(0, 5);
        glVertex2i(200, 5);
    glEnd();

    // Desenhar a estutura da casa
    glColor3ub(139,69,19);
    glBegin(GL_LINE_LOOP);
        glVertex2i(66, 5);
        glVertex2i(132, 5);
        glVertex2i(132, 71);
        glVertex2i(66, 71);
    glEnd();

    // Desenhar a porta
    glColor3ub(139,69,19);
    glBegin(GL_QUADS);
        glVertex2i(89, 5);
        glVertex2i(109, 5);
        glVertex2i(109, 40);
        glVertex2i(89, 40);
    glEnd();

    // Desenhar a janela da esquerda
    glColor3ub(0,250,154);
    glBegin(GL_QUADS);
        glVertex2i(72, 29);
        glVertex2i(83, 29);
        glVertex2i(83, 40);
        glVertex2i(72, 40);
    glEnd();

    // Desenhar a janela da direita
    glColor3ub(0,250,154);
    glBegin(GL_QUADS);
        glVertex2i(115, 29);
        glVertex2i(126, 29);
        glVertex2i(126, 40);
        glVertex2i(115, 40);
    glEnd();



    // Desenhar o telhado
    glBegin(GL_TRIANGLES);
        glColor3ub(255,0,0);
        glVertex2i(66, 71);
        glColor3ub(255,0,0);
        glVertex2i(132, 71);
        glColor3ub(255,0,0);
        glVertex2i(99, 127);
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