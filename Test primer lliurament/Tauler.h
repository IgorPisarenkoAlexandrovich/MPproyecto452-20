#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();
	ColorFigura getTauler(const int& posx, const int& posy) const { return m_tauler[posx][posy]; }
	int eliminaFiles(Figura& figura);
	void inicialitza(Figura& figura, const ColorFigura tauler[][MAX_COL]);
	bool baixaFigura(Figura& figura);
	bool comprovaMoviment(Figura& figura, int dir);
	bool mouFigura(Figura& figura, int dirX);
	bool girFigura(Figura& figura);
	void posForma(const Figura& figura, int& posx, int& posy) const;
	void setTauler(int i, int j, ColorFigura color) { m_tauler[i][j] = color; }

private:
	//metodes auxiliars
	void desplacaDreta(bool& collisiona, int& posx, int& posy, const Figura& figura);
	void desplacaEsquerra(bool& collisiona, int& posx, int& posy, const Figura& figura);
	void baixaFila(const int& fila);
	ColorFigura m_tauler[MAX_FILA][MAX_COL];
};

ofstream& operator<<(ofstream& output, const Tauler& t);

#endif