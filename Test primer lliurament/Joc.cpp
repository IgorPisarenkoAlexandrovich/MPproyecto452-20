#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxer;

    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        int tipus, fila, columna, gir;
        fitxer >> tipus >> fila >> columna >> gir;

        TipusFigura tipusFigura = tipus;
        m_figura.inicialitza(tipusFigura, fila, columna);

        for (int i = 0; i < gir; i++)
        {
            m_figura.rotate();
        }

        ColorFigura tauler[MAX_FILA][MAX_COL];

        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                fitxer >> tauler[i][j];
            }
            
        }
        m_tauler.inicialitza(tauler);
        fitxer.close();
    }
    
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;

    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                fitxer << m_tauler[i][j] << " ";
            }
            
            fitxer << endl;
        }
        fitxer.close();    
    }
    
}