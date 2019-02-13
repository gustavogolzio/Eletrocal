#include "gastos.h"


Gastos::Gastos(QObject *parent) : QObject (parent)
{

}

void Gastos::inserirEquipamento(const Equipamento a)
{
    gastos.push_back(a);


}

float Gastos::potenciaTotal()
{
    return std::accumulate(gastos.begin(),gastos.end(),0.0, [](float acc, Equipamento a){return acc+=a.getPotencia();});
}

float Gastos::consumoTotal()
{
    return std::accumulate(gastos.begin(),gastos.end(),0.0, [](float acc, Equipamento a){return acc+=a.getConsumo();});
}

float Gastos::maiorConsumo()
{
    Equipamento *maior = std::max_element(gastos.begin(),gastos.end(),[](Equipamento a, Equipamento b){ return a.getConsumo() < b.getConsumo();});
    return maior->getConsumo();
}

float Gastos::menorConsumo()
{
    Equipamento *menor = std::min_element(gastos.begin(),gastos.end(),[](Equipamento a, Equipamento b){return a.getConsumo() < b.getConsumo();});
    return menor->getConsumo();
}

void Gastos::ordenarPorNome()
{
    std::sort(gastos.begin(), gastos.end(), [](Equipamento a, Equipamento b){return a.getNome()<b.getNome();});

}

void Gastos::ordenarPorPotencia()
{
    ordenarPorNome();
    std::sort(gastos.begin(), gastos.end(), [](Equipamento a, Equipamento b){return a.getPotencia()>b.getPotencia();});

}

void Gastos::ordenarPorConsumo()
{
ordenarPorNome();
    std::sort(gastos.begin(), gastos.end(), [](Equipamento a, Equipamento b){return a.getConsumo()>b.getConsumo();});

}

int Gastos::size()
{
    return gastos.size();
}

void Gastos::clear()
{
    gastos.clear();
}

Equipamento Gastos::operator[](int i)
{
    return gastos[i];
}
