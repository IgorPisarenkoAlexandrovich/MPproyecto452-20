#ifndef FIGURA_H
#define FIGURA_H

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
        Figura(): m_color(COLOR_NEGRE), m_tipus(NO_FIGURA), m_height(MAX_ALCADA), m_length(MAX_AMPLADA),
                    m_row(0), m_column(0), m_gir(0) {initForm();}

        void initForm();
        void giveFormFigura(TipusFigura tipus);
        void rotate(DireccioGir gir);

        void move(int dirX) {m_column += dirX;}
        void up() {m_row++;}
        void down() {m_row--;}

        int getHeight() {return m_height;}
        int getLength() {return m_length;}
        int getRow() {return m_row;}
        int getCol() {return m_column;}
        int getGir() {return m_gir;}
        ColorFigura getColor() {return m_color;}
        TipusFigura getTipus() {return m_tipus;}

        void setHeight(int height) {m_height = height;}
        void setLength(int length) {m_length = length;}
        void setRow(int row) {m_row = row;}
        void setCol(int col) {m_column = col;}
        void setGir(int gir) {m_gir = gir;}
        void setColor(ColorFigura color) {m_color = color;}
        void setTipus(TipusFigura tipus) {m_tipus = tipus;}

    private:
        ColorFigura m_color;
        TipusFigura m_tipus;

        int m_height;
        int m_length;
        int m_row;
        int m_column;
        bool m_form[MAX_ALCADA][MAX_AMPLADA];
        int m_gir;
};


#endif
