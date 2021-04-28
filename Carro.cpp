#include "Carro.h"

Carro::Carro()
{

}

Carro::~Carro()
{
    //dtor
}

void Carro::desenhaTeto(bool wire){

    // Topo
    glPushMatrix();
        glColor3f(0.2, 0.6, 0.7);
        glTranslatef(0.0f, 12.0f, 0.0f);
        glScalef(14.0f, 0.1f, 8.0f);
        if (wire) glutWireCube(2);
            else glutSolidCube(2);
    glPopMatrix();

    // Frente
    glPushMatrix();
        glColor3f(0.2, 0.6, 0.7);
        glTranslatef(14.1f, 11.2f, 0.0f);
        glScalef(0.1f, 0.9f, 8.0f);
        if (wire) glutWireCube(2);
            else glutSolidCube(2);
    glPopMatrix();

    // Fundo com janela
    glPushMatrix();
        glColor3f(0.2, 0.6, 0.7);
        glTranslatef(-13.9f, 10.9f, 0.0f);
        glScalef(0.1f, 1.0f, 8.0f);
        if (wire) glutWireCube(2);
            else glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2, 0.6, 0.7);
        glTranslatef(-13.9f, 8.9f, -5.5f);
        glScalef(0.1f, 1.0f, 2.5f);
        if (wire) glutWireCube(2);
            else glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2, 0.6, 0.7);
        glTranslatef(-13.9f, 8.9f, 5.5f);
        glScalef(0.1f, 1.0f, 2.5f);
        if (wire) glutWireCube(2);
            else glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.2, 0.6, 0.7);
        glTranslatef(-13.9f, 7.3f, 0.0f);
        glScalef(0.1f, 0.6f, 8.0f);
        if (wire) glutWireCube(2);
            else glutSolidCube(2);
    glPopMatrix();
}

void Carro::desenhaCilindro(float baseRadius, float topRadius, float size){
    glPushMatrix();

	glBegin(GL_QUADS);
		GLUquadricObj *obj = gluNewQuadric();
		gluCylinder(obj, baseRadius, topRadius, size, 32, 30);
	glEnd();

	glPushMatrix();
		glPushMatrix();
			glScalef(1, 1, 0.001);
			//glutWireSphere(baseRadius + 0.048, 32, 5);
			glutSolidSphere(baseRadius + 0.048, 32, 5);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 0, 0.6f);
			glScalef(1, 1, 0.001);
			//glutWireSphere(topRadius + 0.048, 32, 5);
			glutSolidSphere(topRadius + 0.048, 32, 5);
		glPopMatrix();

	glPopMatrix();

}

void Carro::desenhaBancos(bool wire){
    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
		glTranslatef(-0.5f, 0.0f, 0.0f);
		glScalef(2.5f, 0.5f, 6.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
		glTranslatef(-2.5f, 3.0f, 0.0f);
		glScalef(0.5f, 3.5f, 6.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();
// --------------------------------------------------------------------------------
    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
		glTranslatef(-9.5f, 0.0f, 0.0f);
		glScalef(2.5f, 0.5f, 6.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
		glTranslatef(-11.5f, 3.0f, 0.0f);
		glScalef(0.5f, 3.5f, 6.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();
}

void Carro::desenhaFundo(bool wire){

    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
		glTranslatef(-5.0f, -1.0f, 0.0f);
		glScalef(7.0f, 0.5f, 6.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
		glTranslatef(10.0f, -1.0f, 0.0f);
		glScalef(2.0f, 0.5f, 6.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();
}

void Carro::desenhaPainel(bool wire){

    glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
		glTranslatef(11.5f, 1.5f, 0.0f);
		glScalef(0.5f, 2.0f, 6.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
		glTranslatef(9.5f, 0.5f, 0.0f);
		glScalef(0.5f, 1.0f, 6.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.9f, 0.9f, 0.9f);
		glTranslatef(10.5f, 2.5f, 0.0f);
		glScalef(0.5f, 3.0f, 6.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();
}

void Carro::desenhaLaterais(bool wire){

	glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(0.0f, 0.0f, 7.0f);
		glScalef(12.0f, 1.8f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(0.0f, 0.0f, -7.0f);
		glScalef(12.0f, 1.8f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();
// ----------------------------------------------------------------------------------
	glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(-15.0f, 1.2f, -7.0f);
		glScalef(3.0f, 0.6f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(15.0f, 1.2f, -7.0f);
		glScalef(3.0f, 0.6f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(-15.0f, 1.2f, 7.0f);
		glScalef(3.0f, 0.6f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(15.0f, 1.2f, 7.0f);
		glScalef(3.0f, 0.6f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();
// ----------------------------------------------------------------------------------
glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(-15.0f, -1.2f, -7.0f);
		glScalef(3.0f, 0.6f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(15.0f, -1.2f, -7.0f);
		glScalef(3.0f, 0.6f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(-15.0f, -1.2f, 7.0f);
		glScalef(3.0f, 0.6f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
        glColor3f(0.5f, 0.4f, 0.2f);
		glTranslatef(15.0f, -1.2f, 7.0f);
		glScalef(3.0f, 0.6f, 1.0f);
		glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		if (wire) glutWireCube(2);
            else glutSolidCube(2);
	glPopMatrix();
}
