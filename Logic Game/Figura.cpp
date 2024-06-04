#include "Figura.h"
#include "InfoJoc.h"




Figura::Figura() {
    m_y = 0;
    m_x = 0;
    m_orientacio = 0;
    m_tipus = NO_FIGURA;
    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        for (int j = 0; j < MAX_ALCADA; j++)
        {
            m_forma[i][j] = NO_COLOR;
        }
    }
}


Figura::Figura(const int& nColum, const int& nFil)
{
    m_y = 0;
    m_x = nFil / 2 - 2;
    m_orientacio = 0;
    m_tipus = NO_FIGURA;
    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        for (int j = 0; j < MAX_ALCADA; j++)
        {
            m_forma[i][j] = NO_COLOR;
        }
    }
}



void Figura::trasposaMatriu()
{
    ColorFigura transposada[MAX_ALCADA][MAX_AMPLADA];

    for (int i = 0; i < MAX_ALCADA; i++) {
        for (int j = 0; j < MAX_AMPLADA; j++) {
            if (m_tipus == FIGURA_I) {
                transposada[j][i] = m_forma[i][j];
            }
            else {
                if (i < MAX_ALCADA - 1 && j < MAX_AMPLADA - 1) {
                    transposada[j][i] = m_forma[i][j];
                }
                else {
                    transposada[i][j] = NO_COLOR;
                }
            }
        }
    }

    // Copiar la matriz transpuesta a la matriz original
    for (int i = 0; i < MAX_AMPLADA; i++) {
        for (int j = 0; j < MAX_ALCADA; j++) {
            m_forma[i][j] = transposada[i][j];
        }
    }
}

void Figura::inverteixColumnes()
{
    ColorFigura invertida[MAX_ALCADA][MAX_AMPLADA];

    for (int i = 0; i < MAX_ALCADA; i++) {
        for (int j = 0; j < MAX_AMPLADA; j++) {
            if (m_tipus == FIGURA_I) {
                invertida[i][j] = m_forma[MAX_ALCADA - 1 - i][j];
            }
            else {
                // Para todas las figuras que no sean FIGURA_I
                if (i < MAX_ALCADA - 1 && j < MAX_AMPLADA - 1) {
                    invertida[i][j] = m_forma[MAX_ALCADA - 2 - i][j];
                }
                else {
                    invertida[i][j] = NO_COLOR;
                }
            }
        }
    }

    // Copiar la matriz invertida a la matriz original
    for (int i = 0; i < MAX_ALCADA; i++) {
        for (int j = 0; j < MAX_AMPLADA; j++) {
            m_forma[i][j] = invertida[i][j];
        }
    }
}


void Figura::inverteixFiles()
{
    ColorFigura invertida[MAX_ALCADA][MAX_AMPLADA];

    for (int i = 0; i < MAX_ALCADA; i++) {
        for (int j = 0; j < MAX_AMPLADA; j++) {
            if (m_tipus == FIGURA_I) {
                invertida[i][j] = m_forma[i][MAX_AMPLADA - 1 - j];
            }
            else {
                // Para todas las figuras que no sean FIGURA_I
                if (i < MAX_ALCADA - 1 && j < MAX_AMPLADA - 1) {
                    invertida[i][j] = m_forma[i][MAX_AMPLADA - 2 - j];
                }
                else {
                    invertida[i][j] = NO_COLOR;
                }
            }
        }
    }

    // Copiar la matriz invertida a la matriz original
    for (int i = 0; i < MAX_ALCADA; i++) {
        for (int j = 0; j < MAX_AMPLADA; j++) {
            m_forma[i][j] = invertida[i][j];
        }
    }
}




void Figura::giraFigura(const DireccioGir& direccio)
{
    if (m_tipus != FIGURA_O) {
        this->trasposaMatriu();

        if (direccio == 0)
            this->inverteixFiles();

        else
            inverteixColumnes();



        m_orientacio -= 2 * direccio;
        m_orientacio++;

        if (m_orientacio > 3)
            m_orientacio = 0;

        else if (m_orientacio < 0)
            m_orientacio = 4 + m_orientacio;

    }
}



Figura Figura::operator=(const Figura& f)
{
    Figura res;
    m_tipus = f.m_tipus;
    m_orientacio = f.m_orientacio;
    m_x = f.m_x;
    m_y = f.m_y;


    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        for (int j = 0; j < MAX_ALCADA; j++)
        {
            m_forma[i][j] = f.m_forma[i][j];
        }
    }
    return *this;
}



void Figura::ferGir(const DireccioGir& direccio)
{
    if (m_tipus != FIGURA_O) {

        this->trasposaMatriu();

        if (direccio == 0)
            this->inverteixFiles();

        else
            inverteixColumnes();
    }
}



void Figura::resetFig()
{
    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        for (int j = 0; j < MAX_ALCADA; j++)
        {
            m_forma[i][j] = NO_COLOR;
        }
    }
}

void Figura::formaFig()
{

    this->resetFig();


    ColorFigura color = (ColorFigura)(int)m_tipus;
    switch (m_tipus)
    {
    case FIGURA_O:

        m_forma[0][0] = color;
        m_forma[1][0] = color;
        m_forma[0][1] = color;
        m_forma[1][1] = color;
        break;

    case FIGURA_I:

        m_forma[1][0] = color;
        m_forma[1][1] = color;
        m_forma[1][2] = color;
        m_forma[1][3] = color;
        break;

    case FIGURA_T:

        m_forma[0][1] = color;
        m_forma[1][0] = color;
        m_forma[1][1] = color;
        m_forma[1][2] = color;
        break;

    case FIGURA_L:

        m_forma[1][0] = color;
        m_forma[1][1] = color;
        m_forma[1][2] = color;
        m_forma[0][2] = color;
        break;


    case FIGURA_J:

        m_forma[0][0] = color;
        m_forma[1][0] = color;
        m_forma[1][1] = color;
        m_forma[1][2] = color;
        break;

    case FIGURA_Z:

        m_forma[0][0] = color;
        m_forma[0][1] = color;
        m_forma[1][1] = color;
        m_forma[1][2] = color;
        break;

    case FIGURA_S:

        m_forma[0][1] = color;
        m_forma[0][2] = color;
        m_forma[1][0] = color;
        m_forma[1][1] = color;
        break;
    }


}

void Figura::dibuixa()
{
    for (int i = 0; i < MAX_ALCADA; i++)
    {
        for (int j = 0; j < MAX_AMPLADA; j++)
        {
            if (m_forma[i][j] != NO_COLOR)
                GraphicManager::getInstance()->drawSprite((IMAGE_NAME)((int)m_forma[i][j] + 1), POS_X_TAULER + ((m_x + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_y - 1 + i) * MIDA_QUADRAT), false);
        }
    }

}

