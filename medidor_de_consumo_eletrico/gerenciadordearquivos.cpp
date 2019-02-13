#include "gerenciadordearquivos.h"

GerenciadorDeArquivos::GerenciadorDeArquivos()
{

}

bool GerenciadorDeArquivos::salvarProdutos(QString &arquivo, Gastos &gastos)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<gastos.size();i++){

        out << gastos[i].getNome()<<","
            <<gastos[i].getPotencia()<<","
            <<gastos[i].getQuantidade()<<","
            <<gastos[i].getHoras()<<"\n";
    }

    file.close();
    return true;
}

bool GerenciadorDeArquivos::carregarProdutos(QString &arquivo, Gastos &gastos)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        Equipamento e(dados[0],dados[1].toFloat(),dados[2].toInt(),dados[3].toFloat());
        gastos.inserirEquipamento(e);

    }
    file.close();
    return true;
}
