#include "Figura.h"

void Figura::initForm()
{
    for (int i = 0; i < m_height; i++)
    {
        for(int j = 0; j < m_length; j++)
        {
            m_form[i][j] = 0;
        }
    }   
}

void Figura::giveFormFigura(TipusFigura tipus)
{
    switch (tipus)
    {
    case FIGURA_O:
        m_color = COLOR_GROC;
        m_length = 2;
        m_height = 2;
        m_form[0][0] = 1;
        m_form[0][1] = 1;
        m_form[1][0] = 1;
        m_form[1][1] = 1;
        break;

    case FIGURA_I:
        m_color = COLOR_BLAUCEL;
        m_length = 4;
        m_height = 4;
        initForm();
        m_form[1][0] = 1;
        m_form[1][1] = 1;
        m_form[1][2] = 1;
        m_form[1][3] = 1;
        break;
    
    case FIGURA_T:
        m_color = COLOR_MAGENTA;
        m_length = 3;
        m_height = 3;
        initForm();
        m_form[0][1] = 1;
        m_form[1][0] = 1;
        m_form[1][1] = 1;
        m_form[1][2] = 1;
        break;
    
    case FIGURA_L:
        m_color = COLOR_TARONJA;
        m_length = 3;
        m_height = 3;
        initForm();
        m_form[0][2] = 1;
        m_form[1][0] = 1;
        m_form[1][1] = 1;
        m_form[1][2] = 1;
        break;

    case FIGURA_J:
        m_color = COLOR_BLAUFOSC;
        m_length = 3;
        m_height = 3;
        initForm();
        m_form[0][0] = 1;
        m_form[1][0] = 1;
        m_form[1][1] = 1;
        m_form[1][2] = 1;
        break;
    
    case FIGURA_Z:
        m_color = COLOR_VERMELL;
        m_length = 3;
        m_height = 3;
        initForm();
        m_form[0][0] = 1;
        m_form[0][1] = 1;
        m_form[1][1] = 1;
        m_form[1][2] = 1;
        break;

    case FIGURA_S:
        m_color = COLOR_VERD;
        m_length = 3;
        m_height = 3;
        initForm();
        m_form[0][1] = 1;
        m_form[0][2] = 1;
        m_form[1][0] = 1;
        m_form[1][1] = 1;
        break;
    }
}

void Figura::rotate(DireccioGir gir)
{
    int buffer;
    int mirror[2];

    for (int i = 0; i < m_height; i++)
    {
        for(int j = 0; j < m_length; j++)
        {
            buffer = m_form[i][j];
            m_form[i][j] = m_form[j][i];
            m_form[j][i] = buffer;
        }
    }

    buffer = 0;

    if (gir == GIR_HORARI)
    {
        //invertir columnes
    }
    else
    {
        //invertir files
    }
    
}