#include <GL/freeglut.h>


int init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //limpa o buffer
    glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
    glLoadIdentity(); //carrega a matrix de identidade
    glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view

    
    glutSwapBuffers();			//força o desenho das primitivas
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                       //inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //configura o modo de
												 //display
    glutInitWindowPosition(300,0);     //seta a posição inicial da janela
    glutInitWindowSize(width,height);       //configura a largura e altura da
									   // janela de exibição
	//cria a janela de exibição
    glutCreateWindow("Exercício 1 – Viewports múltiplas");

    init();                           //executa função de inicialização
    glutDisplayFunc(display);
    glutIdleFunc(gira);               //executa a função enquanto o programa está ocioso
    glutMainLoop();                   //mostre tudo e espere
    return 0;
}
