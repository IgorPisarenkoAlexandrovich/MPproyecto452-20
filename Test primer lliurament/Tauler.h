#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
    public:
        Tauler();
        void inicialitza(ColorFigura tauler[MAX_FILA][MAX_COL]);
        


    private:
        ColorFigura m_tauler[MAX_FILA][MAX_COL];
};
#endif