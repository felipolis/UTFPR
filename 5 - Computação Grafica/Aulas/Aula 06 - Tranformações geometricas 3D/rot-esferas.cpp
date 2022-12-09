#include <stdio.h>
#include <GL/glut.h>

void keyPressed_special(int key, int x, int y);

float angulo_x = 0, angulo_y = 0, escala = 1;

int init(void){
	glClearColor(0, 0, 0, 0);		// define a cor de fundo
	glEnable(GL_DEPTH_TEST);		// remoção de superfície oculta
	// define que a matriz é a de projeção
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();				// carrega a matriz identidade
	glOrtho(-5, 5, -5, 5, -5, 5);	// define uma projeção ortográfica
}


void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);	// define que a matriz é a de modelo
	glLoadIdentity();				// carrega a matriz identidade

	glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(3, 0, 0);
    glRotatef(angulo_x, 1, 0, 0);
    glRotatef(angulo_y, 0, 1, 0);
    glutWireSphere(1.0, 20, 20);
    glPopMatrix();

    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 0, 0);
    glRotatef(angulo_x, 1, 0, 0);
    glRotatef(angulo_y, 0, 1, 0);
    glutWireSphere(1.0, 20, 20);

	glFlush();						// desenha os comandos não executados
}

int main(int argc, char** argv){
    glutInit(&argc,argv);			//inicializa o GLUT
	//configura o modo de display
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200,0);	//seta a posição inicial da janela
    glutInitWindowSize(400,400); 	//largura e altura da janela
    glutCreateWindow("3D");			//cria a janela de exibição

    init();							//executa função de inicialização
    glutSpecialFunc(keyPressed_special);
    glutDisplayFunc(display);
    glutMainLoop();					//mostre tudo e espere
    return 0;
}

void keyPressed_special(int key, int x, int y){
    if (key == GLUT_KEY_UP){
        angulo_x += 0.5;
    }
    if (key == GLUT_KEY_DOWN){
        angulo_x -= 0.5;
    }
    if (key == GLUT_KEY_LEFT){
        angulo_y -= 0.5;
    }
    if (key == GLUT_KEY_RIGHT){
        angulo_y += 0.5;
    }
    if (key == GLUT_KEY_PAGE_DOWN){
        escala -= 0.1;
    }
    if (key == GLUT_KEY_PAGE_UP){
        escala += 0.1;
    }
    glutPostRedisplay();
}