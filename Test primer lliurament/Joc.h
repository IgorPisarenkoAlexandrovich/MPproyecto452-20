#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>

typedef enum
{
	ACTIVA,
	FINAL_GUANYAT,
	FINAL_PERDUT
} EstatPartida;

class Joc
{
public:
	Joc() : m_puntuacio(0), m_nivell(0), m_estat(ACTIVA) {}
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
private:
	Tauler m_tauler;
	Figura m_figura;
	float m_puntuacio;
	int m_nivell;
	EstatPartida m_estat;
};

#endif