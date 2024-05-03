#include "Figura.h"

Figura::Figura() : m_tipus(NO_FIGURA), m_color(NO_COLOR), m_fila(0), m_columna(0), m_gir(0), m_nCaselles(0), m_direccio(GIR_HORARI)
{
	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
			m_forma[i][j] = COLOR_NEGRE;
}

void Figura::inicialitza(const TipusFigura& tipus, const int& fila, const int& columna, const int& gir)
{
	m_tipus = tipus;
	m_fila = fila;
	m_columna = columna;
	m_gir = 0;
	switch (m_tipus)
	{
	case NO_FIGURA:
		m_color = COLOR_NEGRE;
		m_nCaselles = 0;
		break;
	case FIGURA_O:
		m_color = COLOR_GROC;
		m_nCaselles = 2;
		for (int i = 0; i < m_nCaselles; i++) {
			for (int j = 0; j < m_nCaselles; j++) {
				m_forma[i][j] = m_color;
			}
		}
		break;
	case FIGURA_I:
		m_color = COLOR_BLAUCEL;
		m_nCaselles = 4;
		for (int i = 0; i < m_nCaselles; i++) {
			for (int j = 0; j < m_nCaselles; j++) {
				if (i == 1) {
					m_forma[i][j] = m_color;
				}
				else {
					m_forma[i][j] = COLOR_NEGRE;
				}
			}
		}
		break;
	case FIGURA_T:
		m_color = COLOR_MAGENTA;
		m_nCaselles = 3;
		for (int i = 0; i < m_nCaselles; i++) {
			for (int j = 0; j < m_nCaselles; j++) {
				if ((i == 0 && j == 1) || (i == 1 && j >= 0 && j <= 2)) {
					m_forma[i][j] = m_color;
				}
				else {
					m_forma[i][j] = COLOR_NEGRE;
				}
			}
		}
		break;
	case FIGURA_L:
		m_color = COLOR_TARONJA;
		m_nCaselles = 3;
		for (int i = 0; i < m_nCaselles; i++) {
			for (int j = 0; j < m_nCaselles; j++) {
				if ((i == 0 && j == 2) || (i == 1 && j >= 0 && j <= 2)) {
					m_forma[i][j] = m_color;
				}
				else {
					m_forma[i][j] = COLOR_NEGRE;
				}
			}
		}
		break;
	case FIGURA_J:
		m_color = COLOR_BLAUFOSC;
		m_nCaselles = 3;
		for (int i = 0; i < m_nCaselles; i++) {
			for (int j = 0; j < m_nCaselles; j++) {
				if ((i == 0 && j == 0) || (i == 1 && j >= 0 && j <= 2)) {
					m_forma[i][j] = m_color;
				}
				else {
					m_forma[i][j] = COLOR_NEGRE;
				}
			}
		}
		break;
	case FIGURA_Z:
		m_color = COLOR_VERMELL;
		m_nCaselles = 3;
		for (int i = 0; i < m_nCaselles; i++) {
			for (int j = 0; j < m_nCaselles; j++) {
				if ((i == 0 && j <= 1) || (i == 1 && j >= 1 && j <= 2)) {
					m_forma[i][j] = m_color;
				}
				else {
					m_forma[i][j] = COLOR_NEGRE;
				}
			}
		}
		break;
	case FIGURA_S:
		m_color = COLOR_VERD;
		m_nCaselles = 3;
		for (int i = 0; i < m_nCaselles; i++) {
			for (int j = 0; j < m_nCaselles; j++) {
				if ((i == 0 && (j == 1 || j == 2)) || (i == 1 && (j == 0 || j == 1))) {
					m_forma[i][j] = m_color;
				}
				else {
					m_forma[i][j] = COLOR_NEGRE;
				}
			}
		}
		break;
		switch (m_tipus)
		{
		case FIGURA_I:
			switch (m_gir)
			{
			case 1:m_columna--;
				break;
			case 2: m_fila--;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	for (int i = m_gir; i < gir; i++)
	{
		giraHorari();
	}
}

void Figura::giraHorari()
{
	trasposaMatriu();
	inverteixColumnes();
	m_gir++;
	if (m_gir == 4)
		m_gir = 0;
}

void Figura::giraAntiHorari()
{
	trasposaMatriu();
	inverteixFiles();
	m_gir--;
	if (m_gir == -1)
	{
		m_gir = 3;
	}
}

void Figura::trasposaMatriu()
{
    for (int i = 0; i < m_nCaselles; i++)
    {
        for (int j = i + 1; j < m_nCaselles; j++)
        {
            ColorFigura temp = m_forma[i][j];
            m_forma[i][j] = m_forma[j][i];
            m_forma[j][i] = temp;
        }
    }
}

void Figura::inverteixFiles()
{
       for (int i = 0; i < m_nCaselles / 2; i++)
    {
        for (int j = 0; j < m_nCaselles; j++)
        {
            ColorFigura aux = m_forma[i][j];
            m_forma[i][j] = m_forma[m_nCaselles - 1 - i][j];
            m_forma[m_nCaselles - 1 - i][j] = aux;
        }
    }
}

void Figura::inverteixColumnes()
{
    for (int i = 0; i < m_nCaselles; i++)
	{
		int left = 0;                            
		int right = m_nCaselles - 1;             
		while (left < right)
		{
			ColorFigura aux = m_forma[i][left];
			m_forma[i][left] = m_forma[i][right];
			m_forma[i][right] = aux;
			left++;
			right--;
		}
	}
}

void Figura::operator=(const Figura& figura)
{
	m_tipus = figura.m_tipus;
	m_color = figura.m_color;
	m_fila = figura.m_fila;
	m_columna = figura.m_columna;
	m_gir = figura.m_gir;
	for (int i = 0; i < MAX_ALCADA; i++)
		for (int j = 0; j < MAX_AMPLADA; j++)
			m_forma[i][j] = figura.m_forma[i][j];
}

ifstream& operator>>(ifstream& input, Figura& f)
{
	TipusFigura tipus;
	int fila, columna, gir;
	input >> tipus >> fila >> columna >> gir;
	f.inicialitza(tipus, fila, columna, gir);
	return input;
}

ifstream& operator>>(ifstream& input, TipusFigura& tipus)
{
	int tipusFig;
	input >> tipusFig;
	switch (tipusFig)
	{
	case 0: tipus = NO_FIGURA;
		break;
	case 1: tipus = FIGURA_O;
		break;
	case 2: tipus = FIGURA_I;
		break;
	case 3: tipus = FIGURA_T;
		break;
	case 4: tipus = FIGURA_L;
		break;
	case 5: tipus = FIGURA_J;
		break;
	case 6: tipus = FIGURA_Z;
		break;
	case 7: tipus = FIGURA_S;
		break;
	}
	return input;
}

ifstream& operator>>(ifstream& input, ColorFigura& color)
{
	int colorFig;
	input >> colorFig;
	switch (colorFig)
	{
	case 0: color = COLOR_NEGRE;
		break;
	case 1: color = COLOR_GROC;
		break;
	case 2: color = COLOR_BLAUCEL;
		break;
	case 3: color = COLOR_MAGENTA;
		break;
	case 4: color = COLOR_TARONJA;
		break;
	case 5: color = COLOR_BLAUFOSC;
		break;
	case 6: color = COLOR_VERMELL;
		break;
	case 7: color = COLOR_VERD;
		break;
	case 8: color = NO_COLOR;
		break;
	}
	return input;
}

ofstream& operator<<(ofstream& output, const ColorFigura& color)
{
	switch (color)
	{
	case COLOR_NEGRE: output << 0;
		break;
	case COLOR_GROC: output << 1;
		break;
	case COLOR_BLAUCEL: output << 2;
		break;
	case COLOR_MAGENTA: output << 3;
		break;
	case COLOR_TARONJA: output << 4;
		break;
	case COLOR_BLAUFOSC: output << 5;
		break;
	case COLOR_VERMELL: output << 6;
		break;
	case COLOR_VERD: output << 7;
		break;
	case NO_COLOR: output << 8;
		break;
	}
	return output;
}