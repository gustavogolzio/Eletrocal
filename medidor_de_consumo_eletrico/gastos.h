#ifndef GASTOS_H
#define GASTOS_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>

#include "equipamento.h"

class Gastos : public QObject
{
    Q_OBJECT
private:
    QVector<Equipamento> gastos;

    public:


    explicit Gastos(QObject *parent = nullptr);
    void inserirEquipamento(const Equipamento a);

    float potenciaTotal();
    float consumoTotal();
    float maiorConsumo();
    float menorConsumo();
    void ordenarPorNome();
    void ordenarPorPotencia();
    void ordenarPorConsumo();

    int size();
    void clear();

    Equipamento operator[](int i);
signals:

public slots:
};

#endif // GASTOS_H
