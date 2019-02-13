#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>
#include <QFileDialog>

#include "equipamento.h"
#include "gastos.h"


class GerenciadorDeArquivos
{
public:

    GerenciadorDeArquivos();
    static bool salvarProdutos(QString &arquivo, Gastos &gastos);
    static bool carregarProdutos(QString &arquivo, Gastos &Gastos);
};

#endif // GERENCIADORDEARQUIVOS_H
