#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float anguloSol = 0, anguloLua = 0, anguloTerra = 0, anguloTerraRot = 0;

void Timer(int value){
    float incrementoSol = 360.0/27.0/24.0;
    anguloSol += incrementoSol;

    float incrementoLua = 360.0/28.0/24.0;
    anguloLua += incrementoLua;

    float incrementoTerraRot = 360.0/24.0;
    anguloTerraRot += incrementoTerraRot;

    float incrementoTerra = 360.0/365.0/24.0;
    anguloTerra += incrementoTerra;

    glutPostRedisplay();
    glutTimerFunc(100, Timer, 1);
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);     //define a cor de fundo
    glMatrixMode(GL_PROJECTION);          //define que a matriz é a de projeção
    glLoadIdentity();
    glOrtho(-5.2,5.2,-5.2,5.2,-5.2,5.2);          //define uma projeção ortográfica
}

void display(void){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,1.0,0.0, //posição da câmera
              0.0,0.0,0.0, //para onde a câmera aponta
              1.0,0.0,0.0); //vetor view-up

    glPushMatrix(); //desenha sol
        glColor4f(1.0, 1.0, 0.0, 1.0);
        glRotatef(anguloSol,0,1,0);
        glutWireSphere(1,20,20);
    glPopMatrix();

    glPushMatrix(); //desenha terra
        glColor4f(0.0, 0.0, 1.0, 1.0);
        glRotatef(anguloTerra,0,1,0);
        glTranslatef(4,0,0);
        glRotatef(anguloTerraRot,0,1,0);
        glutWireSphere(0.5,10,10);

        glColor4f(0.81, 0.78, 0.79, 1.0); // cor da lua
        glRotatef(anguloLua, 0, 1, 0);
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef(anguloLua, 0, 1, 0);

        glutWireSphere(0.2,10,10);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(800,800);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("Projeto 3 - Sistema Solar");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    glutDisplayFunc(display);
    glutTimerFunc(100,Timer, 1);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}