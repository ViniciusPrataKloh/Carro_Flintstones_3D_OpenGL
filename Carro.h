#ifndef CARRO_H
#define CARRO_H
#include <GL/glut.h>


class Carro
{
    public:
        Carro();
        virtual ~Carro();

         bool wire = true;

         void desenhaCilindro(float baseRadius, float topRadius, float size);
         void desenhaFundo(bool wire);
         void desenhaLaterais(bool wire);
         void desenhaPainel(bool wire);
         void desenhaBancos(bool wire);
         void desenhaTeto(bool wire);
         void desenhaVolante(float baseRadius, float topRadius, float size);
         void material();

    protected:
    private:
};

#endif // CARRO_H
