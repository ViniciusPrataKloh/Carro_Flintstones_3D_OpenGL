#include <GL/glut.h>
#include "Carro.h"
#include "Chao.h"
#include "Poste.h"

#define ROT_SENS    5.0
#define OBS_SENS    20.0
#define TRANSL_SENS 30.0

bool ortho = true;
float win = 10.0f;
float aspect;
float angle = 60.0f;
bool axis = true;
bool wire = true;

GLfloat rotX = 0.0, rotY = 0.0, rotX_ini, rotY_ini;
GLfloat obsX = 0.0, obsY = 0.0, obsZ = 30.0, obsX_ini, obsY_ini, obsZ_ini;
int x_ini, y_ini, bot;

GLfloat scaleX = 0.0f, scaleY = 0.0f, scaleZ = 0.0f;
GLfloat transX = 0.0f, transY = 0.0f, transZ = 0.0f;
//GLfloat rotX = 0.0f, rotY = 0.0f, rotZ = 0.0f;

Carro c;
Chao chao;
Poste p;

int object = 0;

float objectScale = 1;
float objectTranslate = 0;
float objectRotation = 0;

bool luz1 = false;
bool luz2 = false;
bool luz3 = false;
bool m = false;

void update();
void special(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void reshape(GLsizei w, GLsizei h);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void setProjection();
void drawAxis();
void inicializa();
void material();
void material2();

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(1024, 600);
	glutCreateWindow("Carro_3D");

	glutDisplayFunc(update);
	glutReshapeFunc(reshape);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

    inicializa();
	glutMainLoop();

	return 0;
}

void inicializa(){
    glEnable( GL_DEPTH_TEST );

        /* - - - Luz Pontual 1 - - - */
        GLfloat luzAmbient0[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat luzDifusa0[] = { 0.5, 0.5, 0.5, 1.0 };          // Cor
        GLfloat luzEspecular0[] = { 0.1, 0.1, 0.0, 1.0 };       // Brilho
        GLfloat luzPosicao0[] = { 0.0, 0.0, 1.0, 0.0 };

        // Capacidade de  brilho do material
        GLfloat especularidade0[] = { 1.0, 1.0, 1.0, 1.0 };
        GLint especMaterial0 = 60;

        // Ativa o uso da luz ambiente
        glLightModelfv( GL_LIGHT_MODEL_AMBIENT, luzAmbient0 );

        // Define os parâmetros da luz de número zero
        glLightfv( GL_LIGHT0, GL_DIFFUSE, luzAmbient0 );
        glLightfv( GL_LIGHT0, GL_DIFFUSE, luzDifusa0 );
        glLightfv( GL_LIGHT0, GL_SPECULAR, luzEspecular0 );
        glLightfv( GL_LIGHT0, GL_POSITION, luzPosicao0 );

        glMaterialfv( GL_FRONT, GL_SPECULAR, especularidade0 );
        glMateriali( GL_FRONT, GL_SHININESS, especMaterial0 );

        glEnable( GL_LIGHTING );

        /* - - - Luz Pontual 2 - - - */
        GLfloat luzAmbient1[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat luzDifusa1[] = { 0.5, 0.5, 0.5, 1.0 };          // Cor
        GLfloat luzEspecular1[] = { 0.1, 0.1, 0.0, 1.0 };       // Brilho
        GLfloat luzPosicao1[] = { 0.0, 0.0, 0.0, 0.0 };

        // Capacidade de  brilho do material
        GLfloat especularidade1[] = { 1.0, 1.0, 1.0, 1.0 };
        GLint especMaterial1 = 60;

        // Ativa o uso da luz ambiente
        glLightModelfv( GL_LIGHT_MODEL_AMBIENT, luzAmbient1 );

        // Define os parâmetros da luz de número um
        glLightfv( GL_LIGHT1, GL_DIFFUSE, luzAmbient1 );
        glLightfv( GL_LIGHT1, GL_DIFFUSE, luzDifusa1 );
        glLightfv( GL_LIGHT1, GL_SPECULAR, luzEspecular1 );
        glLightfv( GL_LIGHT1, GL_POSITION, luzPosicao1 );

        glMaterialfv( GL_FRONT, GL_SPECULAR, especularidade1 );
        glMateriali( GL_FRONT, GL_SHININESS, especMaterial1 );

        glEnable( GL_LIGHTING );

        /* - - - Luz Direcional - - - */
        GLfloat luzAmbient2[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat luzDifusa2[] = { 0.5, 0.5, 0.5, 1.0 };          // Cor
        GLfloat luzEspecular2[] = { 1.0, 1.0, 1.0, 1.0 };       // Brilho
        GLfloat luzPosicao2[] = { 20.0, 20.0, 0.0, 1.0 };


        // Ativa o uso da luz ambiente
        glLightModelfv( GL_LIGHT_MODEL_AMBIENT, luzAmbient2 );

        // Define os parâmetros da luz de número dois
        glLightfv( GL_LIGHT2, GL_DIFFUSE, luzAmbient2 );
        glLightfv( GL_LIGHT2, GL_DIFFUSE, luzDifusa2 );
        glLightfv( GL_LIGHT2, GL_SPECULAR, luzEspecular2 );
        glLightfv( GL_LIGHT2, GL_POSITION, luzPosicao2 );


        glEnable( GL_LIGHTING );


        /* - - - Luz Spot - - - */
        GLfloat luzDifusa3[4][4] = {
            { 0.0, 1.0, 0.0, 0.0 },
            { 1.0, 0.0, 0.0, 0.0 },
            { 0.0, 0.0, 1.0, 0.0 },
            { 1.0, 1.0, 0.0, 0.0 }
        };

        GLfloat luzEspecular3[4][4] = {
            { 0.0, 1.0, 1.0, 1.0 },
            { 0.0, 1.0, 1.0, 1.0 },
            { 0.0, 1.0, 1.0, 1.0 },
            { 0.0, 1.0, 1.0, 1.0 }
        };

        GLfloat luzPosicao3[4][3] = {
            { 38.0, 21.7, -20.0 },
            { 38.0, 21.7, 20.0 },
            { -38.0, 21.7, 20.0 },
            { -38.0, 21.7, -20.0 }
        };

        GLfloat luzDirecao3[4][3] = {
            { 0.0, -1.0, 0.0 },
            { 0.0, -1.0, 0.0 },
            { 0.0, -1.0, 0.0 },
            { 0.0, -1.0, 0.0 }
        };

        // Define os parâmetros das luzes spot.
        for (int cont = 0; cont < 4; cont++){
            glLightfv( GL_LIGHT3+cont, GL_DIFFUSE, luzDifusa3[cont] );
            glLightfv( GL_LIGHT3+cont, GL_SPECULAR, luzEspecular3[cont] );
            glLightfv( GL_LIGHT3+cont, GL_POSITION, luzPosicao3[cont] );
            glLightfv( GL_LIGHT3+cont, GL_SPOT_DIRECTION, luzDirecao3[cont] );
            glLightf( GL_LIGHT3+cont, GL_SPOT_CUTOFF, 110.0 );
            glLightf( GL_LIGHT3+cont, GL_SPOT_EXPONENT, 40.0 );
        }
        glEnable( GL_LIGHTING );

        if (!m){
            glEnable( GL_COLOR_MATERIAL );
        }
        glEnable( GL_DEPTH_TEST );
        glEnable( GL_NORMALIZE );
        if (m){
            material();
        }

}

void material(){
    GLfloat matDifusa[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat matEspecular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat matBrilho[] = { 50.0 };

    glMaterialfv( GL_FRONT, GL_DIFFUSE, matDifusa );
    glMaterialfv( GL_FRONT, GL_AMBIENT, matDifusa );
    glMaterialfv( GL_FRONT, GL_SPECULAR, matEspecular );
    glMaterialfv( GL_FRONT, GL_SHININESS, matBrilho );
}

void material2(){
    GLfloat matDifusa[] = { 1.0, 0.0, 1.0, 1.0 };
    GLfloat matEspecular[] = { 0.3, 0.3, 0.3, 1.0 };
    GLfloat matBrilho[] = { 50.0 };

    glMaterialfv( GL_FRONT, GL_DIFFUSE, matDifusa );
    glMaterialfv( GL_FRONT, GL_AMBIENT, matDifusa );
    glMaterialfv( GL_FRONT, GL_SPECULAR, matEspecular );
    glMaterialfv( GL_FRONT, GL_SHININESS, matBrilho );
}

void drawObject()
{
}

void update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (axis) drawAxis();

    glPushMatrix();
        glTranslatef(transX, 0.0f, 0.0f);

            glPushMatrix();
                c.desenhaLaterais(wire);
            glPopMatrix();

            glPushMatrix();
                c.desenhaFundo(wire);
            glPopMatrix();

            glPushMatrix();
                c.desenhaPainel(wire);
            glPopMatrix();

            glPushMatrix();
                    c.desenhaBancos(wire);
            glPopMatrix();

            glPushMatrix();
                c.desenhaTeto(wire);
            glPopMatrix();

            // Colunas Verticais:
            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glRotatef(-90, 1, 0, 0);
                glTranslatef(-8.0f, 7.0f, 1.8f);
                glScalef(0.5f, 0.5f, 12.0f);
                c.desenhaCilindro(1.0f, 1.0f, 1);
            glPopMatrix();

            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glRotatef(-90, 1, 0, 0);
                glTranslatef(-8.0f, -7.0f, 1.8f);
                glScalef(0.5f, 0.5f, 12.0f);
                c.desenhaCilindro(1.0f, 1.0f, 1);
            glPopMatrix();

            // Colunas Horizontais:
            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glRotatef(-90, 0, 1, 0);
                glTranslatef(-6.0f, 11.5f, -1.5f);
                glScalef(0.5f, 0.5f, 15.0f);
                c.desenhaCilindro(1.0f, 1.0f, 1);
            glPopMatrix();

            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glRotatef(-90, 0, 1, 0);
                glTranslatef(6.0f, 11.5f, -1.5f);
                glScalef(0.5f, 0.5f, 15.0f);
                c.desenhaCilindro(1.0f, 1.0f, 1);
            glPopMatrix();

            // Voltante
            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glRotatef(-90, 0, 1, 0);
                glTranslatef(-3.0f, 4.0f, -10.0f);
                glScalef(0.4f, 0.4f, 1.0f);
                c.desenhaCilindro(1.0f, 1.0f, 1);
            glPopMatrix();

            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glRotatef(-90, 0, 1, 0);
                glTranslatef(-3.0f, 4.0f, -9.0f);
                glScalef(1.5f, 1.5f, 0.5f);
                c.desenhaCilindro(1.0f, 1.0f, 1);
            glPopMatrix();


            // Rodas e Eixos:
            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                //glRotatef((transX+30), 0, 1, 0);
                glTranslatef(17.0f, 0.0f, -5.5f);
                glScalef(4.0f, 3.0f, 11.0f);
                c.desenhaCilindro(1.0f, 1.0f, 1.0f);
            glPopMatrix();

            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glTranslatef(16.5f, 0.0f, -8.0f);
                glScalef(0.5f, 0.5f, 16.0f);
                c.desenhaCilindro(1.0f, 1.0f, 1.0f);
            glPopMatrix();

            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glTranslatef(-17.0f, 0.0f, -5.5f);
                glScalef(4.0f, 3.0f, 11.0f);
                c.desenhaCilindro(1.0f, 1.0f, 1.0f);
            glPopMatrix();

            glPushMatrix();
                glColor3f(0.0f, 1.0f, 0.0f);
                glTranslatef(-16.5f, 0.0f, -8.0f);
                glScalef(0.5f, 0.5f, 16.0f);
                c.desenhaCilindro(1.0f, 1.0f, 1.0f);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix;

    // Chão
    glPushMatrix();
        chao.desenhaChao(wire);
    glPopMatrix();

    // Poste
    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(-90, 1, 0, 0);
        glTranslatef(44.0f, 20.0f, -3.0f);
        glScalef(1.0f, 1.f, 30.0f);
        p.desenhaTubos(1.0f, 1.0f, 1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(-90, 0, 1, 0);
        glTranslatef(-20.0f, 25.0f, -43.0f);
        glScalef(0.5f, 0.5f, 6.0f);
        p.desenhaTubos(1.0f, 1.0f, 1);
    glPopMatrix();
//-------------------------------------------
    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(-90, 1, 0, 0);
        glTranslatef(-44.0f, 20.0f, -3.0f);
        glScalef(1.0f, 1.f, 30.0f);
        p.desenhaTubos(1.0f, 1.0f, 1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(-90, 0, 1, 0);
        glTranslatef(-20.0f, 25.0f, 38.0f);
        glScalef(0.5f, 0.5f, 6.0f);
        p.desenhaTubos(1.0f, 1.0f, 1);
    glPopMatrix();
//-------------------------------------------
    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(-90, 1, 0, 0);
        glTranslatef(-44.0f, -20.0f, -3.0f);
        glScalef(1.0f, 1.f, 30.0f);
        p.desenhaTubos(1.0f, 1.0f, 1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(-90, 0, 1, 0);
        glTranslatef(20.0f, 25.0f, 38.0f);
        glScalef(0.5f, 0.5f, 6.0f);
        p.desenhaTubos(1.0f, 1.0f, 1);
    glPopMatrix();
//-------------------------------------------
    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(-90, 1, 0, 0);
        glTranslatef(44.0f, -20.0f, -3.0f);
        glScalef(1.0f, 1.f, 30.0f);
        p.desenhaTubos(1.0f, 1.0f, 1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(-90, 0, 1, 0);
        glTranslatef(20.0f, 25.0f, -43.0f);
        glScalef(0.5f, 0.5f, 6.0f);
        p.desenhaTubos(1.0f, 1.0f, 1);
    glPopMatrix();
    glPushMatrix();
        p.desenhaCone(wire);
    glPopMatrix();

    glutSwapBuffers();
}

void special(int key, int x, int y){
     switch(key){
          case GLUT_KEY_F1:
            if ( glIsEnabled( GL_LIGHT0 ) ){
                glDisable( GL_LIGHT0 );
                glDisable( GL_LIGHT1 );
            }
            else{
                glEnable( GL_LIGHT0 );
                glEnable( GL_LIGHT1 );
            }
          break;

          case GLUT_KEY_F2:
            if ( glIsEnabled( GL_LIGHT2 ) )
                glDisable( GL_LIGHT2 );
            else
                glEnable( GL_LIGHT2 );
          break;

          case GLUT_KEY_F3:
            if ( glIsEnabled( GL_LIGHT4 ) ){
                glDisable( GL_LIGHT4 );
                glDisable( GL_LIGHT5 );
                glDisable( GL_LIGHT6 );
                glDisable( GL_LIGHT7 );
            }
            else{
                glEnable( GL_LIGHT4 );
                glEnable( GL_LIGHT5 );
                glEnable( GL_LIGHT6 );
                glEnable( GL_LIGHT7 );
            }
          break;

          case GLUT_KEY_RIGHT:
                   transX += 1.0f;
          break;

          case GLUT_KEY_LEFT:
               transX -= 1.0f;
          break;
     }

     setProjection();
     glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:				exit(0); 							break;
		case 'p': case 'P':		ortho = false; setProjection(); 	break;
		case 'o': case 'O':		ortho = true; setProjection(); 		break;
		case 'a': case 'A':		axis = !axis; 						break;
		case 'w': case 'W':		wire = !wire; 						break;
		case 'm': case 'M':     m = !m;                             break;

	}

	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else
	{
		bot = -1;
	}
}

void motion(int x, int y)
{
	if (bot == GLUT_LEFT_BUTTON)
	{
		int deltaX = x_ini - x;
		int deltaY = y_ini - y;
		rotX = rotX_ini - deltaY / ROT_SENS;
		rotY = rotY_ini - deltaX / ROT_SENS;
	}
	else if (bot == GLUT_RIGHT_BUTTON)
	{
		int deltaZ = y_ini - y;
		obsZ = obsZ_ini + deltaZ / OBS_SENS;
	}
	else if (bot == GLUT_MIDDLE_BUTTON)
	{
		int deltaX = x_ini - x;
		int deltaY = y_ini - y;
		obsX = obsX_ini + deltaX / TRANSL_SENS;
		obsY = obsY_ini - deltaY / TRANSL_SENS;
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-obsX, -obsY, -obsZ);
	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0);
	glutPostRedisplay();
}

void drawAxis()
{
	glLineWidth(2.0f);

	glBegin(GL_LINES);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 2.0f, 0.0f);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 2.0f);

	glEnd();
}

void reshape(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);
	aspect = (float)w/h;

	setProjection();
}

void setProjection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (ortho)
	{
		glOrtho(-win*aspect, win*aspect, -win, win, -win, win);
	}
	else
	{
		gluPerspective(angle, aspect, 0.1f, 1000.0f);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsX, obsY, obsZ,
			   0.0,  0.0,  0.0,
			   0.0,  1.0,  0.0);
}
