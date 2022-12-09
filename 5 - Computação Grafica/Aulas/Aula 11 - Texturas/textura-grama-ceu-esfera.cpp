#include <GL/glew.h>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../stb-master/stb_image.h"
#define BASE 500

float aspect, X, Y; // Variáveis auxiliadoras para definir o tamanho do polígono sem distorcer a textura
float z = 0.0; // Controla a posição da câmera
static unsigned int texture[3]; // Armazena as informações sobre as texturas
static float d = 1.0; // Intensidade da luz do Sol
static float theta = 90.0; // Ângulo da luz do Sol

void keySpec(int key, int x, int y);
void setAspect(int width, int height);
void loadTextures();
void init();
void display();
void resize(int w, int h);

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Texturas, mipmaps e iluminacao");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutSpecialFunc(keySpec);
	glewInit();
	init();
	glutMainLoop();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(
        0.0, 18.0, 10.0 + z,
        0.0, 8.0, -1.0 + z,
        0.0, 1.0, 0.0);

    // Propriedades da luz do Sol
	float lightDifAndSpec[] = { d, d, d, 1.0 };
	float lightPos[] = { cos((M_PI / 180.0)*theta), sin((M_PI / 180.0)*theta), 0.0, 0.0 };

    // Define as propriedades da luz do Sol
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);

    // Define texture[0] como a textura ativa
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_POLYGON);
        glNormal3f(0.0, 1.0, 0.0);
        glTexCoord2f(0.0, 0.0); glVertex3f(-Y, 0.0, Y);
        glTexCoord2f(10.0, 0.0); glVertex3f(Y, 0.0, Y);
        glTexCoord2f(10.0, 10.0); glVertex3f(Y, 0.0, -Y);
        glTexCoord2f(0.0, 10.0); glVertex3f(-Y, 0.0, -Y);
    glEnd();

    // Define texture[1] como a textura ativa
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_POLYGON);
        glNormal3f(0.0, 1.0, 0.0);
        glTexCoord2f(0.0, 0.0); glVertex3f(-X/2, 0.0, -200.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(X/2, 0.0, -200.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(X/2, Y, -200.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(-X/2, Y, -200.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[2]);
    GLUquadricObj *qObj = gluNewQuadric();
    gluQuadricTexture(qObj, GL_TRUE);
    gluSphere(qObj, 5.0, 40, 40);


    // Desabilita a luz e a textura para desenhar a reta indicadora na tela
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	// Define as cores da reta e zera a matriz de projeção
    glColor3f(0.0, 0.0, 0.0);
	glLoadIdentity();
	glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, -6.0);
        glVertex3f(d * cos((M_PI / 180.0)*theta), d * sin((M_PI / 180.0)*theta), -6.0);
	glEnd();

    // Habilita novamente a luz e a textura
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	glutSwapBuffers();
}

void resize(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keySpec(int key, int x, int y){
    if (key == GLUT_KEY_DOWN)
		if (d > 0.0) d -= 0.05;
	if (key == GLUT_KEY_UP)
		if (d < 1.0) d += 0.05;
	if (key == GLUT_KEY_RIGHT)
		if (theta > 0.0) theta -= 1.0;
	if (key == GLUT_KEY_LEFT)
		if (theta < 180.0) theta += 1.0;
    if (key == GLUT_KEY_PAGE_UP)
        if (z > -50) z -= 0.5;
    if (key == GLUT_KEY_PAGE_DOWN)
        if (z < 50) z += 0.5;
    glutPostRedisplay();
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);

	// Ativa a iluminação
	glEnable(GL_LIGHTING);

	// Propriedades da luz ambiente
	float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
	float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };

	// Define as propriedades da luz LIGHT_0
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);

	// Habilita LIGHT_0
	glEnable(GL_LIGHT0);

	// Carrega a luz ambiente global independente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);

	// Propriedades de reflexão dos materiais
	float matAmbAndDif[] = { 1.0, 1.0, 1.0, 1.0 };
	float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
	float matShine[] = { 50.0 };

	// Define as propriedades de reflexão dos materiais
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShine);

    // Define a quantidade de texturas e o vetor que armazenará essas texturas
	glGenTextures(3, texture);

	// Função que carrega as texturas
	loadTextures();

	// Especifica a forma como a textura é aplicada sobre o objeto, nesse caso, interpolando
	// as cores da textura e a cor da luz
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Habilita as texturas
	glEnable(GL_TEXTURE_2D);
}

void setAspect(int width, int height){
    aspect = (float) width / (float) height;
    X = BASE * aspect;
    Y = BASE;
}

void loadTextures(){
    stbi_set_flip_vertically_on_load(true);
    int width, height, channels;
    unsigned char *data;

    // Importa o arquivo de imagem
    data = stbi_load("../Textures/grass.jpg", &width, &height, &channels, 0);
    setAspect(width, height);

    // Ativa a textura 0
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	// Gera a textura utilizando a imagem carregada
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glGenerateMipmap(GL_TEXTURE_2D);

    // Define os parâmetros de wrapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Define os parâmetros para a filtragem (magnification e minification)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);


    // Daqui para baixo são configurações da segunda textura
	data = stbi_load("../Textures/sky.jpg", &width, &height, &channels, 0);
	setAspect(width, height);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	    // Daqui para baixo são configurações da segunda textura
	data = stbi_load("../Textures/earth.bmp", &width, &height, &channels, 0);
	setAspect(width, height);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
};
