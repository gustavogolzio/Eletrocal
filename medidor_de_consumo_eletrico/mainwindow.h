#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QtSql>
#include <QDialog>
#include <QInputDialog>

#include "gerenciadordearquivos.h"
#include "equipamento.h"
#include "gastos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Gastos produtos;

private:

    QVector <QString> total;
    QVector <float> quant;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void atualizarEstatisticas();
private slots:



    void on_btn_add_clicked();

    void salvar();
    void carregar();


private:
    Ui::MainWindow *ui;
    void inserirEquipamentoNaTabela(Equipamento equipamento, int row);
    bool verificarEquipamento( Equipamento a);
    int qnt_produtos =0;
    int indice=0;
};

#endif // MAINWINDOW_H
