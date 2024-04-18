#include "Tauler.h"


Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; i++)
        {
            m_tauler[i][j] = NO_COLOR;
        }
        
    }
    
}

void Tauler::inicialitza(ColorFigura tauler[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; i++)
        {
            m_tauler[i][j] = tauler[i][j];
        }
        
    }
    
}