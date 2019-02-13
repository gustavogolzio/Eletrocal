#include "equipamento.h"
#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>
Equipamento::Equipamento()
{

}
Equipamento::Equipamento(QString n, float q, float p, float h)
{
    nome = n;
    potencia = p;
    horas = h;
    qnt = q;


}
QString Equipamento::getNome() const
{
    return nome;
}

void Equipamento::setNome(const QString &value)
{
    nome = value;
}

float Equipamento::getPotencia() const
{
    return potencia;
}

void Equipamento::setPotencia(float value)
{
    potencia = value;
}
float Equipamento::getHoras() const
{
    return horas;
}

void Equipamento::setHoras(float value)
{
    horas = value;
}
float Equipamento::getConsumo() const
{
    float potenciatotal=(potencia*horas*qnt*30);

    if(potenciatotal <=30){
        return potenciatotal*0.19;
    }else if(potenciatotal>30 and potenciatotal<=100){
        return potenciatotal*0.33;
    }else if(potenciatotal>100 and potenciatotal<=220){
        return potenciatotal*(0.49);
    }else if(potenciatotal>220){
        return potenciatotal*0.55;
    }

}
void Equipamento::setQuantidade(float value)
{
    qnt = value;
}
float Equipamento::getQuantidade() const
{
    return qnt;
}



