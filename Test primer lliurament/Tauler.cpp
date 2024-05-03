#include "Tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
		for (int j = 0; j < MAX_COL; j++)
			m_tauler[i][j] = COLOR_NEGRE;
}

void Tauler::inicialitza(Figura& figura, const ColorFigura tauler[][MAX_COL]) {
	for (int i = 0; i < MAX_FILA; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			m_tauler[i][j] = tauler[i][j];
		}
	}
	int posx, posy;
	posForma(figura, posx, posy);
	for (int i = posx; i < posx + figura.getNumCaselles() && i < MAX_FILA; i++) {
		for (int j = posy; j < posy + figura.getNumCaselles() && j < MAX_COL; j++) {
			if (figura.getForma(i - posx, j - posy) != COLOR_NEGRE)
				m_tauler[i][j] = figura.getForma(i - posx, j - posy);
		}
	}
}

void Tauler::posForma(const Figura& figura, int& posx, int& posy) const
{
	posx = figura.getFila() - 1;
	posy = figura.getColumna() - 1;
}

bool Tauler::girFigura(Figura& figura) {
	int posx, posy;
	posForma(figura, posx, posy);
	bool comprova = comprovaMoviment(figura, -3);
	if (!comprova)
	{
		if (figura.getDireccio() == GIR_HORARI) {
			figura.giraAntiHorari();
		}
		else {
			figura.giraHorari();
		}
	}
	for (int i = 0; i < figura.getNumCaselles(); i++) {
		for (int j = 0; j < figura.getNumCaselles(); j++) {
			int tablero_x = posx + i;
			int tablero_y = posy + j;

			if (tablero_x >= 0 && tablero_x < MAX_FILA && tablero_y >= 0 && tablero_y < MAX_COL) {
				if (figura.getForma(i, j) != COLOR_NEGRE) {
					m_tauler[tablero_x][tablero_y] = figura.getForma(i, j);
				}
			}
		}
	}

	return comprova;
}

ofstream& operator<<(ofstream& output, const Tauler& t)
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
			output << t.getTauler(i, j) << " ";
		output << endl;
	}
	return output;
}
void Tauler::baixaFila(const int& fila)
{
	for (int i = fila; i >= 0; i--)
		for (int j = 0; j < MAX_COL; j++)
			m_tauler[i][j] = m_tauler[i - 1][j];
	for (int j = 0; j < MAX_COL; j++)
		m_tauler[0][j] = COLOR_NEGRE;

}

int Tauler::eliminaFiles(Figura& figura) // retorna el nombre de files completades
{
	int nFiles = 0;
	int j;
	bool completa;
	for (int i = MAX_FILA - 1; i >= 0; i--)
	{
		j = 0;
		completa = true;
		while (j < MAX_COL && completa)
			if (m_tauler[i][j] == COLOR_NEGRE)
				completa = false;
			else
				j++;
		if (completa)
		{
			baixaFila(i);
			nFiles++;
			i++;
		}
	}
	return nFiles;
}
bool Tauler::baixaFigura(Figura& figura)
{
	bool comprova = comprovaMoviment(figura, -2);
	return comprova;
}

void Tauler::desplacaDreta(bool& collisiona, int& posx, int& posy, const Figura& figura)
{
	int i = 0;
	if ((posy + figura.getNumCaselles() - 1) >= MAX_COL)
	{
		while (i < figura.getNumCaselles() && !collisiona)
			if (figura.getForma(i, figura.getNumCaselles() - 1) == figura.getColor())
			{
				collisiona = true;
			}
			else { i++; }
		if (!collisiona && (posy + figura.getNumCaselles() - 1) > MAX_COL)
			i = 0;
		while (i < figura.getNumCaselles() && !collisiona)
			if (figura.getForma(i, figura.getNumCaselles() - 2) == figura.getColor())
			{
				collisiona = true;
			}
			else { i++; }

	}
	if (!collisiona)
	{
		i = 0;
		while (i < figura.getNumCaselles() && !collisiona)
		{
			int tablero_x = posx + i;
			int tablero_y = posy + figura.getNumCaselles() - 1;
			int j = tablero_y;
			while (j >= posy && !collisiona)
			{

				if (m_tauler[tablero_x][j] != COLOR_NEGRE && figura.getForma(i, j - posy) != COLOR_NEGRE && m_tauler[tablero_x][j] != figura.getColor())
				{
					collisiona = true;
				}
				else
					j--;
			}
			i++;
		}
		if (!collisiona)
		{
			posy--;
			for (int i = 0; i < figura.getNumCaselles(); i++) {
				for (int j = 0; j < figura.getNumCaselles(); j++) {
					int tablero_x = posx + i;
					int tablero_y = posy + j;
					if (m_tauler[tablero_x][tablero_y] == figura.getColor() && (figura.getForma(i, j) == figura.getColor())) {
						m_tauler[tablero_x][tablero_y] = COLOR_NEGRE;
					}
				}
			}
			posy++;
			for (int i = 0; i < figura.getNumCaselles(); i++) {
				for (int j = 0; j < figura.getNumCaselles(); j++) {
					int tablero_x = posx + i;
					int tablero_y = posy + j;

					if (tablero_x >= 0 && tablero_x < MAX_FILA && tablero_y >= 0 && tablero_y < MAX_COL) {
						if (figura.getForma(i, j) != COLOR_NEGRE) {
							m_tauler[tablero_x][tablero_y] = figura.getForma(i, j);
						}
					}
				}
			}
		}
	}
}

void Tauler::desplacaEsquerra(bool& collisiona, int& posx, int& posy, const Figura& figura)
{
	int i = 0;
	if (posy < 0)
	{
		while (i < figura.getNumCaselles() && !collisiona)

			if (figura.getForma(i, 0) == figura.getColor())
			{
				collisiona = true;
			}
			else { i++; }
		if (!collisiona && (posy + 1) < 0)
		{
			i = 0;
			while (i < figura.getNumCaselles() && !collisiona)
				if (figura.getForma(i, 1) == figura.getColor())
				{
					collisiona = true;
				}
				else { i++; }
		}
		if (!collisiona && (posy + 2) < 0)
		{
			i = 0;
			while (i < figura.getNumCaselles() && !collisiona)
				if (figura.getForma(i, 2) == figura.getColor())
				{
					collisiona = true;
				}
				else { i++; }
		}
	}
	if (!collisiona)
	{
		i = 0;
		while (i < figura.getNumCaselles() && !collisiona)
		{
			int tablero_x = posx + i;
			int tablero_y = posy;
			if (m_tauler[tablero_x][tablero_y] != COLOR_NEGRE && figura.getForma(i, 0) != COLOR_NEGRE)
			{
				collisiona = true;
			}
			else { ++i; }
		}
		if (!collisiona)
		{
			posy++;
			for (int i = 0; i < figura.getNumCaselles(); i++)
			{
				for (int j = 0; j < figura.getNumCaselles(); j++)
				{
					int tablero_x = posx + i;
					int tablero_y = posy + j;
					if (m_tauler[tablero_x][tablero_y] == figura.getColor() && (figura.getForma(i, j) == figura.getColor()))
					{
						m_tauler[tablero_x][tablero_y] = COLOR_NEGRE;
					}
				}
			}
			posy--;
			for (int i = 0; i < figura.getNumCaselles(); i++)
			{
				for (int j = 0; j < figura.getNumCaselles(); j++)
				{
					int tablero_x = posx + i;
					int tablero_y = posy + j;

					if (tablero_x >= 0 && tablero_x < MAX_FILA && tablero_y >= 0 && tablero_y < MAX_COL)
					{
						if (figura.getForma(i, j) == figura.getColor())
						{
							m_tauler[tablero_x][tablero_y] = figura.getForma(i, j);
						}
					}
				}
			}
		}
	}
}

bool Tauler::comprovaMoviment(Figura& figura, int dir)
{
	int posx, posy;
	posForma(figura, posx, posy);
	bool collisiona = false;
	int i = 0;
	if (dir == 1)
	{
		desplacaDreta(collisiona, posx, posy, figura);
	}
	else if (dir == -1)
	{
		desplacaEsquerra(collisiona, posx, posy, figura);
	}
	else if (dir == -2)
	{
		if ((posx + figura.getNumCaselles() - 1) >= MAX_FILA)
		{
			while (i < figura.getNumCaselles() && !collisiona)
				if (figura.getForma(figura.getNumCaselles() - 1, i) == figura.getColor())
				{
					collisiona = true;
				}
				else { i++; }
		}
		if (!collisiona)
		{
			i = 0;
			while (i < figura.getNumCaselles() && !collisiona)
			{
				int tablero_x = posx + figura.getNumCaselles() - 1;
				int tablero_x2 = posx + figura.getNumCaselles() - 2;
				int tablero_x3 = posx + figura.getNumCaselles() - 3;
				int tablero_y = posy + i;
				if (m_tauler[tablero_x3][tablero_y] != COLOR_NEGRE && figura.getForma(figura.getNumCaselles() - 3, i) == figura.getColor())
				{
					collisiona = true;
				}
				else if (m_tauler[tablero_x2][tablero_y] != COLOR_NEGRE && figura.getForma(figura.getNumCaselles() - 2, i) == figura.getColor())
				{
					collisiona = true;
				}
				else if (m_tauler[tablero_x][tablero_y] != COLOR_NEGRE && figura.getForma(figura.getNumCaselles() - 1, i) == figura.getColor())
				{
					collisiona = true;
				}
				else { ++i; }
			}
		}
		if (collisiona)
		{
			posx--;
		}
		for (int i = 0; i < figura.getNumCaselles(); i++) {
			for (int j = 0; j < figura.getNumCaselles(); j++) {
				int tablero_x = posx + i;
				int tablero_y = posy + j;

				if (tablero_x >= 0 && tablero_x < MAX_FILA && tablero_y >= 0 && tablero_y < MAX_COL) {
					if (figura.getForma(i, j) == figura.getColor() && m_tauler[tablero_x][tablero_y] == COLOR_NEGRE) {
						m_tauler[tablero_x][tablero_y] = figura.getForma(i, j);
					}
				}
			}

		}

	}
	else if (dir == -3)
	{
		if (posy < 0)
		{
			int i = 0;
			while (i < figura.getNumCaselles() && !collisiona)
			{
				if (figura.getForma(i, figura.getNumCaselles() - 1) == figura.getColor())
				{
					collisiona = true;
				}
				i++;
			}
		}
		else if ((posy + figura.getNumCaselles() - 1) >= MAX_COL)
		{
			int i = 0;
			while (i < figura.getNumCaselles() && !collisiona)
			{
				if (figura.getForma(i, 0) == figura.getColor())
				{
					collisiona = true;
				}
				i++;
			}
		}
		else if (!collisiona)
		{
			int i = 0;
			while (i < figura.getNumCaselles() && !collisiona)
			{
				int j = 0;
				while (j < figura.getNumCaselles() && !collisiona)
				{
					int tablero_x = posx + j;
					int tablero_y = posy + i;
					if ((m_tauler[tablero_x][tablero_y] != COLOR_NEGRE) && (figura.getForma(j, i) == figura.getColor()))
					{
						collisiona = true;
					}
					else
					{
						j++;
					}
				}
				i++;
			}
		}
	}
	return !collisiona;
}
bool Tauler::mouFigura(Figura& figura, int dirX)
{
	bool comprova = comprovaMoviment(figura, dirX);
	return comprova;
}