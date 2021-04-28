#ifndef CHAO_H
#define CHAO_H
#include <GL/glut.h>

class Chao
{
    public:
        Chao();
        virtual ~Chao();

        bool wire;

        void desenhaChao(bool wire);

    protected:
    private:
};

#endif // CHAO_H
