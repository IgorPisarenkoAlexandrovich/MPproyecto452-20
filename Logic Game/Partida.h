#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Cua
{
public:
    void afegeix_m(const int& valor);
    void ompleBossa();
    void generaFigura();
    int elimina_passa_seguent();
    void inicialitza_test();
    Figura seguentFigura();
    TipusFigura generaTipus();


private:
    int* f_next;
    int* m_next;
    queue <Figura> m_cola_figuras;
    queue <int> m_cola_movimientos;
    vector <TipusFigura> m_bossaFig;

};

class Llista
{
public:

    void setPuntos(const int& puntos) { m_puntuacio = puntos; }
    void setNom(const string& nom) { m_nom = nom; }
    string getNom() const { return m_nom; }
    int getPunt() const { return m_puntuacio; }
    bool operator<(const Llista& llista) { return m_puntuacio < llista.m_puntuacio; }

private:

    int m_puntuacio;
    string m_nom;
};

class Partida
{
public:
    Partida();
    int menu();
    void actualitza(double deltaTime);
    void inicialitza(const string& nomFitxer);
    void test();
    void mostraTauler();
    void mostraPuntuacions();
    void afegeixPuntuacio();
    void juga();
    bool isFinish() { return m_acabat; }
    bool isTest() { return modeTest; }

private:
    void jocNormal();
    void jocTest();
    void actualitzaPuntuacio(const int& linies);
    void actualitzaFigura();
    void drawScore();

    double m_temps;
    vector <TipusFigura> figura;
    string nombre;
    Joc Tetris;
    Cua cua;
    bool modeTest;
    int m_puntuacio;
    int m_nivell;
    bool m_acabat;
};

#endif 