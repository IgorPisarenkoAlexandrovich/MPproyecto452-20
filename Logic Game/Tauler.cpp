#include "Tauler.h"
#include "InfoJoc.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_tauler[i][j] = COLOR_NEGRE;
		}
	}
}


bool Tauler::coincidencia(const Figura& f) const
{
	bool solapa = false;
	int i = 0;
	int j;
	int x;
	int y;
	switch (f.getTipus())
	{

	case FIGURA_O:
		x = f.getX() - 1;
		y = f.getY();
		break;

	default:
		x = f.getX() - 1;
		y = f.getY() - 1;
		break;
	}


	solapa = false;

	while (!solapa && i < 4)
	{
		j = 0;
		while (!solapa && j < 4)
		{
			solapa = ((f.getColor(i, j) != NO_COLOR) && ((x + j >= MAX_COL) || (x + j < 0) || (m_tauler[i + y][j + x] != COLOR_NEGRE) || (y + i + 1 > MAX_FILA)));
			j++;
		}
		i++;
	}

	return solapa;
}






void Tauler::eliminaFila(const int& index)
{
	for (int i = index; i >= 0; i--)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_tauler[i][j] = m_tauler[i - 1][j];
		}
	}
	for (int i = 0; i < MAX_COL; i++)
	{
		m_tauler[0][i] = COLOR_NEGRE;
	}
}


int Tauler::ComprovaFiles()
{

	int nCompletes = 0;
	int j;
	bool fCompleta;
	for (int i = 0; i < MAX_FILA; i++)
	{
		j = 0;
		fCompleta = true;

		while (fCompleta && j < MAX_COL)
		{
			fCompleta = (m_tauler[i][j] != COLOR_NEGRE);
			if (j == MAX_COL - 1 && fCompleta)
			{
				nCompletes++;
				this->eliminaFila(i);
			}
			j++;
		}
	}
	return nCompletes;
}


void Tauler::insertaFigura(const Figura& f)
{
	int x, y;
	switch (f.getTipus())
	{

	case FIGURA_O:
		x = f.getX() - 1;
		y = f.getY();
		break;

	case FIGURA_I:
		x = f.getX() - 1;
		y = f.getY() - 1;
		break;

	default:
		x = f.getX() - 1;
		y = f.getY() - 1;
		break;
	}
	ColorFigura fColor;
	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			fColor = f.getColor(i, j);

			if (fColor != NO_COLOR && m_tauler[i + y][j + x] == COLOR_NEGRE)
				m_tauler[i + y][j + x] = fColor;
		}
	}
}

void Tauler::dibuixa()
{
	// Obtenemos una instancia única de GraphicManager para evitar llamadas repetitivas
	GraphicManager* graphicManager = GraphicManager::getInstance();

	// Dibujamos el fondo del tablero
	graphicManager->drawSprite(GRAFIC_FONS, 0, 0, false);

	// Dibujamos el tablero en su posición
	graphicManager->drawSprite(GRAFIC_TAULER, 120, 100, false);

	// Iteramos sobre todas las celdas del tablero
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			// Obtenemos el color de la celda
			ColorFigura casella = m_tauler[i][j];

			// Verificamos si la celda no es negra para dibujarla
			if (casella != COLOR_NEGRE)
			{
				// Calculamos las coordenadas de dibujo de la celda
				int posX = POS_X_TAULER + ((1 + j) * MIDA_QUADRAT);
				int posY = POS_Y_TAULER + (i * MIDA_QUADRAT);

				// Dibujamos la celda
				graphicManager->drawSprite((IMAGE_NAME)((int)casella + 1), posX, posY, false);
			}
		}
	}
}


bool Tauler::finalJoc()
{
	// Inicializamos la bandera gameOver a falso
	bool finalJoc = false;

	// Iteramos sobre la primera fila del tablero
	for (int j = 0; j < MAX_COL; j++)
	{
		// Si encontramos algún bloque en la primera fila, el juego ha terminado
		if (m_tauler[0][j] != COLOR_NEGRE)
		{
			finalJoc = true;
			break; // Salimos del bucle tan pronto como encontramos un bloque
		}
	}
	return finalJoc;
}
