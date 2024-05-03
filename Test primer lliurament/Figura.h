#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
#include <fstream>
using namespace std;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura();
    TipusFigura getTipus() const { return m_tipus; }
    void setFila() { m_fila++; }
    void setCol(int dir) { m_columna += dir; }
    void setDireccio(DireccioGir direccio) { m_direccio = direccio; }
    int getFila() const { return m_fila; }
    int getColumna() const { return m_columna; }
    int getGir() const { return m_gir; }
    DireccioGir getDireccio() const { return m_direccio; }
    ColorFigura getForma(const int& posx, const int& posy) const { return m_forma[posx][posy]; }
    int getNumCaselles() const { return m_nCaselles; }
    void inicialitza(const TipusFigura& tipus, const int& fila, const int& columna, const int& gir);
    void giraHorari();
    void giraAntiHorari();
    void operator=(const Figura& figura);
    ColorFigura getColor() const { return m_color; }

private:
    void trasposaMatriu();
    void inverteixFiles();
    void inverteixColumnes();
    DireccioGir m_direccio;
    TipusFigura m_tipus;
    ColorFigura m_color;
    int m_fila;
    int m_columna;
    int m_gir;
    ColorFigura m_forma[MAX_ALCADA][MAX_AMPLADA];
    int m_nCaselles;
};

ifstream& operator>>(ifstream& input, Figura& f);
ifstream& operator>>(ifstream& input, ColorFigura& color);
ofstream& operator<<(ofstream& output, const ColorFigura& color);
ifstream& operator>>(ifstream& input, TipusFigura& tipus);

#endif