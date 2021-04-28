#include <GL/glut.h>

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
GLfloat obsX = 0.0, obsY = 0.0, obsZ = 40.0, obsX_ini, obsY_ini, obsZ_ini;
int x_ini, y_ini, bot;

GLfloat scaleX = 0.0f, scaleY = 0.0f, scaleZ = 0.0f;
GLfloat transX = 0.0f, transY = 0.0f, transZ = 0.0f;
//GLfloat rotX = 0.0f, rotY = 0.0f, rotZ = 0.0f;

int object = 0;

float objectScale = 1;
float objectTranslate = 0;
float objectRotation = 0;

void update();
void keyboard(unsigned char key, int x, int y);
void drawObject();
void drawCube1();
void drawCube2();
void drawCube3();
void drawCube4();
void drawCube5();
void drawBottom();
void drawTop();
void drawWallFar();
void drawWallLeft();
void drawWallRight();
void drawWallWindowFar();
void drawWallWindowRight();
void reshape(GLsizei w, GLsizei h);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void setProjection();
void drawAxis();

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(1024, 600);
	glutCreateWindow("Mesa_3D");

	glutDisplayFunc(update);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glutMainLoop();

	return 0;
}

void drawObject()
{
}

void drawCube1(){
     if (wire)	glutWireCube(1);
     else		glutSolidCube(1);
}

void drawCube2(){
     if (wire)	glutWireCube(1);
     else		glutSolidCube(1);
}

void drawCube3(){
     if (wire)	glutWireCube(1);
     else		glutSolidCube(1);
}

void drawCube4(){
     if (wire)	glutWireCube(1);
     else		glutSolidCube(1);
}

void drawCube5(){
     if (wire)	glutWireCube(3);
     else		glutSolidCube(3);
}

void drawWallFar(){
     if (wire)	glutWireCube(10);
     else		glutSolidCube(10);
}

void drawWallLetf(){
     if (wire)	glutWireCube(10);
     else		glutSolidCube(10);
}

void drawWallRight(){
     if (wire)	glutWireCube(10);
     else		glutSolidCube(10);
}

void drawWindowFar(){
     if (wire)	glutWireCube(10);
     else		glutSolidCube(10);
}

void drawWindowRight(){
     if (wire)	glutWireCube(10);
     else		glutSolidCube(10);
}

void drawBottom(){
     if (wire)	glutWireCube(10);
     else		glutSolidCube(10);
}

void drawTop(){
     if (wire)	glutWireCube(10);
     else		glutSolidCube(10);
}

void update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (axis) drawAxis();

	glPushMatrix();
        glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(0.0f, -5.0f, 1.2f);
		glScalef(2.5f, 0.02f, 1.5f);
		glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);
		drawBottom();
	glPopMatrix();

	glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(0.0f, 0.0f, -6.0f);
		glScalef(2.5f, 1.0f, 0.05f);
		glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);
		drawWallFar();
	glPopMatrix();

	glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(-12.2f, 0.0f, 1.2f);
		glScalef(0.05f, 1.0f, 1.5f);
		glRotatef(objectRotation, 0.0f, 0.0f, 0.0f);
		drawWallLetf();
	glPopMatrix();

	glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(12.2f, 0.0f, 1.2f);
		glScalef(0.05f, 1.0f, 1.5f);
		glRotatef(objectRotation, 0.0f, 0.0f, 0.0f);
		drawWallRight();
	glPopMatrix();

	glPushMatrix();
        glColor3f(1.0f, 1.0f, 0.0f);
		glTranslatef(6.1f, 0.0f, -6.0f);
		glScalef(1.2f, 0.95f, 0.05f);
		glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);
		drawWindowFar();
	glPopMatrix();

	glPushMatrix();
        glColor3f(1.0f, 1.0f, 0.0f);
		glTranslatef(12.2f, 0.0f, -2.8f);
		glScalef(0.05f, 0.95f, 0.6f);
		glRotatef(objectRotation, 0.0f, 0.0f, 0.0f);
		drawWindowRight();
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.0f, 1.0f, 0.0f);
		glTranslatef(-1.0f, -3.6f, -2.0f);
		glScalef(0.2, 2.8f, 0.2f);
		glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);
		drawCube1();
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.0f, 1.0f, 0.0f);
		glTranslatef(-8.0f, -3.6f, -2.0f);
		glScalef(0.2, 2.8f, 0.2f);
		glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);
		drawCube2();
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.0f, 1.0f, 0.0f);
		glTranslatef(-1.0f, -3.6f, -5.0f);
		glScalef(0.2, 2.8f, 0.2f);
		glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);
		drawCube3();
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.0f, 1.0f, 0.0f);
		glTranslatef(-8.0f, -3.6f, -5.0f);
		glScalef(0.2, 2.8f, 0.2f);
		glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);
		drawCube4();
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.0f, 1.0f, 0.0f);
		glTranslatef(-4.5f, -2.2f, -3.4f);
		glScalef(3.0f, 0.1f, 1.5f);
		glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);
		drawCube5();
	glPopMatrix();

    glPushMatrix();
        glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(0.0f, 5.0f, 1.2f);
		glScalef(2.5f, 0.02f, 1.5f);
		glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);
		drawTop();
	glPopMatrix();

	glutSwapBuffers();
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

		case 'e':				objectScale -= 0.1f; 				break;
		case 'E':				objectScale += 0.1f; 				break;
		case 't':				objectTranslate -= 0.2f; 			break;
		case 'T':				objectTranslate += 0.2f; 			break;
		case 'r':				objectRotation -= 0.3f; 			break;
		case 'R':				objectRotation += 0.3f; 			break;

		case 'g':               transX += 0.1f;                     break;
		case 'G':               transX -= 0.1f;                     break;
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
		gluPerspective(angle, aspect, 0.0f, 1000.0f);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsX, obsY, obsZ,
			   0.0,  0.0,  0.0,
			   0.0,  1.0,  0.0);
}
