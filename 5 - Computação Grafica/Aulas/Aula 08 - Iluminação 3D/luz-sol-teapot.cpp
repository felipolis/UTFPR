#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

GLfloat x_ini = 0, y_ini = 0, anguloX = 0, anguloY = 0, anguloX_ini = 0,
anguloY_ini = 0, xluz = 0, yluz = 0, raio = 10.0, anguloluz = 0.0;
GLfloat luzR = 1.0, luzG = 1.0 ,luzB = 1.0;

void lighting(){
    GLfloat position[4] = {xluz, yluz, 2.0, 0.0};
    GLfloat black[4] = {0.0, 0.0, 0.0, 1.0};
    GLfloat white[4] = {luzR, luzG, luzB, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

int init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade

    glMatrixMode(GL_MODELVIEW); //define que a matriz é a model view
    glLoadIdentity(); //carrega a matriz de identidade
    gluLookAt(0.0, 0.0, 1.0, //posição da câmera
              0.0, 0.0, 0.0, //para onde a câmera aponta
              0.0, 1.0, 0.0); //vetor view-up
    glMatrixMode(GL_PROJECTION); //define que a matriz é a de projeção
    glLoadIdentity(); //carrega a matriz de identidade
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

    lighting();
}
void sol(){
    xluz = raio * cos(anguloluz);
    yluz = raio * sin(anguloluz);

    anguloluz += 0.01;
    lighting();
    glutPostRedisplay();
}

void display(){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//define que a matriz é a model view
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
        glRotatef(-anguloY, 1, 0, 0);
        glRotatef(-anguloX, 0, 1, 0);
        glutSolidTeapot(1.0);
    glPopMatrix();
    //força o desenho das primitivas
    glutSwapBuffers();
}

void gerenciaMouse(int button, int state, int x, int y){
    x_ini = x;
    y_ini = y;
    anguloX_ini = anguloX;
    anguloY_ini = anguloY;
}

void gerenciaMov(int x, int y){
    GLfloat deltax = x_ini - x;
    GLfloat deltay = y_ini - y;

    anguloX = anguloX_ini + deltax;
    anguloY = anguloY_ini + deltay;
    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB | GLUT_DEPTH);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(400,400);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("Exemplo 1 - Especificando as Cores da Fonte de Luz");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    glutDisplayFunc(display);
    glutIdleFunc(sol);
    glutMouseFunc(gerenciaMouse);
    glutMotionFunc(gerenciaMov);
    glutMainLoop();                                  //mostre tudo e espere

    return 0;
}