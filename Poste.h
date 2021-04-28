#ifndef POSTE_H
#define POSTE_H
#include <GL/glut.h>

class Poste
{
    public:
        Poste();
        virtual ~Poste();

        bool wire;

        void desenhaTubos(float baseRadius, float topRadius, float size);
        void desenhaCone(bool wire);

    protected:
    private:
};

#endif // POSTE_H
