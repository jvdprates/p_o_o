#include "tempo.h"

Tempo::Tempo(int d, int hr, int m, int s)
{
    dia = d;

    hora = hr;

    min = m;

    seg = s;

    Tempo::checkConsis(*this);
}

Tempo::~Tempo()
{
    delete[] this;
}

void Tempo::checkConsis(Tempo &X)
{
    int aux;
    int res;

    if (X.seg > 60)
    {
        aux = X.seg / 60;
        res = X.seg % 60;
        X.seg = res;
        X.min += aux;
    } else if (X.seg < 0){
        if (X.seg > -60){
            X.min--;
            X.seg = 60 + X.seg;
        } else {
            while(X.seg < -60){
                X.min--;
                X.seg += 60;
            }
        }
    };

    if (X.min > 60)
    {
        aux = X.min / 60;
        res = X.min % 60;
        X.min = res;
        X.hora += aux;
    } else if (X.min < 0){
        if (X.min > -60){
            X.hora--;
            X.min = 60 + X.min;
        } else {
            while(X.min < -60){
                X.hora--;
                X.min += 60;
            }
        }
    };

    if (X.hora > 24)
    {
        aux = X.hora / 24;
        res = X.hora % 24;
        X.hora = res;
        X.dia += aux;
    } else if (X.hora < 0){
        if (X.hora > -24){
            X.dia--;
            X.hora = 24 + X.hora;
        } else {
            while(X.hora < -24){
                X.dia--;
                X.hora += 24;
            }
        }
    };
}

Tempo Tempo::sum(Tempo &A) const
{
    Tempo resultado(
        (dia + A.dia),
        (hora + A.hora),
        (min + A.min),
        (seg + A.seg));
    return resultado;
}

void Tempo::print() const
{
    std::cout
        << "Tempo:"
        << "\n"
        << "Dias: " << dia << "\n"
        << "Horas: " << hora << "\n"
        << "Minutos: " << min << "\n"
        << "Segundos:" << seg << "\n";
}

void Tempo::increment(int n, bool reverse)
{
    if (!reverse)
        seg += n;
    else
        seg -= n;
    Tempo::checkConsis(*this);
}