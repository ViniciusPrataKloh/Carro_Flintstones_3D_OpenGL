#include "Chao.h"

Chao::Chao()
{
    //ctor
}

Chao::~Chao()
{
    //dtor
}

void Chao::desenhaChao(bool wire){

    glPushMatrix();
        glColor3f(0.2f, 0.2f, 0.2f);
        glTranslatef(0.0f, -3.15f, 0.0f);
        glScalef(50.0f, 0.1f, 30.0f);
        if (wire) glutWireCube(2);
            else glutSolidCube(2);
    glPopMatrix();

}
