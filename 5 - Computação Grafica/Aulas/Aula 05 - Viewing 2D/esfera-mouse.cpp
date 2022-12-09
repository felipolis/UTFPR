#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>


// Função responsável por fazer a movimentação da esfera na tela.
// A função deve implementar a fórmula disponível no Slide 08 sobre Viewing 2D.
// Essa fórmula transforma a coordenada do mouse na janela (que varia de 0 a 500
// para os dois eixos) para a coordenada do plano 3D (que varia de -100 a 100 nos
// dois eixos).
void gerenciaMouse(int button, int state, int x, int y) {

}



void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Coloque aqui as funções para desenhar a WireSphere
    // e a função para fazer a translação da esfera

    glutSwapBuffers();
}

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);     //define a cor de fundo
    glMatrixMode(GL_PROJECTION);          //define que a matriz é a de projeção
    glLoadIdentity();
    glOrtho(-100,100,-100, 100,-100,100);
}


int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(500,500);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("Cubo Colorido");                 //cria a janela de exibição
    init();                                         //executa função de inicialização
    glutDisplayFunc(display);
    glutMouseFunc(gerenciaMouse);                   // captura o botão pressionado, o status (pressionado ou não) e as coordenadas do mouse
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}
