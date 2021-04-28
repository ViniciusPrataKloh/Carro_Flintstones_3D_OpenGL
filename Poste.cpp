#include "Poste.h"

Poste::Poste()
{
    //ctor
}

Poste::~Poste()
{
    //dtor
}

void Poste::desenhaTubos(float baseRadius, float topRadius, float size){
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
	glPopMatrix();
}

void Poste::desenhaCone(bool wire){
    glPushMatrix();
        glTranslatef(38.0, 21.7, -20.0);
        glRotatef(-90, 1, 0, 0);
        if (wire)
            glutWireCone(3, 3, 10, 1);
        else
            glutSolidCone(3, 3, 10, 1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-38.0, 21.7, -20.0);
        glRotatef(-90, 1, 0, 0);
        if (wire)
            glutWireCone(3, 3, 10, 1);
        else
            glutSolidCone(3, 3, 10, 1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-38.0, 21.7, 20.0);
        glRotatef(-90, 1, 0, 0);
        if (wire)
            glutWireCone(3, 3, 10, 1);
        else
            glutSolidCone(3, 3, 10, 1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(38.0, 21.7, 20.0);
        glRotatef(-90, 1, 0, 0);
        if (wire)
            glutWireCone(3, 3, 10, 1);
        else
            glutSolidCone(3, 3, 10, 1);
    glPopMatrix();
}
