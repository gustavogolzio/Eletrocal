#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include <QObject>

class Equipamento
{
private:
    QString nome;
    float potencia;
    float horas;
    float qnt;
    float consumo;

public:
    explicit Equipamento();
    Equipamento(QString n, float q,float p, float h);

    QString getNome() const;
    void setNome(const QString &value);

    float getPotencia() const;
    void setPotencia (float value);

    float getHoras() const;
    void setHoras(float value);

    float getConsumo() const;

    float getQuantidade() const;
    void setQuantidade(float value);
    int qnt_produtos;

signals:

public slots:
};

#endif // EQUIPAMENTO_H
