#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		fitxer >> m_figura;
		ColorFigura tauler[MAX_FILA][MAX_COL];
		for (int i = 0; i < MAX_FILA; i++)
			for (int j = 0; j < MAX_COL; j++)
				fitxer >> tauler[i][j];
		m_tauler.inicialitza(m_figura, tauler);
	}
	fitxer.close();
}

bool Joc::giraFigura(DireccioGir direccio)
{
	int posx, posy;
	m_figura.setDireccio(direccio);
	m_tauler.posForma(m_figura, posx, posy);
	for (int i = 0; i < m_figura.getNumCaselles(); i++) {
		for (int j = 0; j < m_figura.getNumCaselles(); j++) {
			int tablero_x = posx + i;
			int tablero_y = posy + j;
			if (m_tauler.getTauler(tablero_x, tablero_y) == m_figura.getColor() && (m_figura.getForma(i, j) == m_figura.getColor())) {
				m_tauler.setTauler(tablero_x, tablero_y, COLOR_NEGRE);
			}
		}
	}
	if (direccio == GIR_HORARI) {
		m_figura.giraHorari();
	}
	else if (direccio == GIR_ANTI_HORARI) {
		m_figura.giraAntiHorari();
	}
	return m_tauler.girFigura(m_figura);
}

bool Joc::mouFigura(int dirX)
{
	int col = dirX;
	m_figura.setCol(col);
	bool comprova = m_tauler.mouFigura(m_figura, col);
	return comprova;
}

int Joc::baixaFigura()
{
	int posx, posy;
	int filesEliminades = 0;
	m_tauler.posForma(m_figura, posx, posy);
	m_figura.setFila();
	for (int i = 0; i < m_figura.getNumCaselles(); i++) {
		for (int j = 0; j < m_figura.getNumCaselles(); j++) {
			int tablero_x = posx + i;
			int tablero_y = posy + j;
			if (m_tauler.getTauler(tablero_x, tablero_y) == m_figura.getColor() && (m_figura.getForma(i, j) == m_figura.getColor()) && tablero_x < MAX_FILA && tablero_y < MAX_COL) {
				m_tauler.setTauler(tablero_x, tablero_y, COLOR_NEGRE);
			}
		}
	}
	if (!m_tauler.baixaFigura(m_figura))
	{
		filesEliminades = m_tauler.eliminaFiles(m_figura);
	}
	m_puntuacio += filesEliminades;
	return filesEliminades;
}


void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		fitxer << m_tauler;
	}
	fitxer.close();
}