#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gastos.h"
#include "equipamento.h"
#include <QVector>
#include <QMessageBox>
#include <QtSql>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->salvar_2,SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->carregar,SIGNAL(triggered()), this, SLOT(carregar()));
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::salvar()
{

    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Produtos","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");

    if( GerenciadorDeArquivos::salvarProdutos(nomeArquivo,produtos)){
        QMessageBox::information(this, "Salvar produtos","Dados Salvos com Sucesso");
    }
    else{
        QMessageBox::information(this, "Salvar produtos","Não foi possível salvar os dados");
    }

}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Produtos","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");

    produtos.clear();

    if(GerenciadorDeArquivos::carregarProdutos(nomeArquivo,produtos)){

        ui->tbl_data->clearContents();
        for(int i=0;i<produtos.size();i++){

            if(i >= ui->tbl_data->rowCount())
                ui->tbl_data->insertRow(i);

            inserirEquipamentoNaTabela(produtos[i],i);
        }

    }else{
        QMessageBox::information(this, "Carregar Produtos","Não foi possível carregar os dados");
    }

}

void MainWindow::inserirEquipamentoNaTabela(Equipamento equipamento, int row)
{

    ui->tbl_data->setItem(row,0,new QTableWidgetItem(equipamento.getNome()));
    ui->tbl_data->setItem(row,1,new QTableWidgetItem(QString::number(equipamento.getQuantidade())));
    ui->tbl_data->setItem(row,2,new QTableWidgetItem(QString::number(equipamento.getPotencia())));
    ui->tbl_data->setItem(row,3,new QTableWidgetItem(QString::number(equipamento.getHoras())));
    ui->tbl_data->setItem(row,4,new QTableWidgetItem(QString::number(equipamento.getConsumo())));

}

void MainWindow::on_btn_add_clicked()
{

    if(ui->lne_equipamento_3->text().size() != 0 && ui->lne_quantidade_3->text().toFloat() >0 && ui->lne_potencia_3->text().toFloat() >0 && ui->lne_horas_3->text().toFloat() >0){

    Equipamento equipamento;


    equipamento.setNome(ui->lne_equipamento_3->text().toUpper());
    equipamento.setPotencia(ui->lne_potencia_3->text().toFloat());
    equipamento.setQuantidade(ui->lne_quantidade_3->text().toFloat());
    equipamento.setHoras(ui->lne_horas_3->text().toFloat());


    if(verificarEquipamento(equipamento) == false or qnt_produtos==0){

        int qnt_row = ui->tbl_data->rowCount();

        ui->tbl_data->insertRow(qnt_row);
        inserirEquipamentoNaTabela(equipamento, qnt_row);

        ui->lne_equipamento_3->clear();
        ui->lne_potencia_3->clear();
        ui->lne_quantidade_3->clear();
        ui->lne_horas_3->clear();

        produtos.inserirEquipamento(equipamento);
        total.push_back(equipamento.getNome());
        quant.push_back(equipamento.getQuantidade());

        atualizarEstatisticas();
       qnt_produtos++;

    }else{
        QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Item já presente!", "Deseja adicionar?",QMessageBox::Yes|QMessageBox::No);
        QMessageBox::warning(this, "ERRO", "achou");
            if (reply == QMessageBox::Yes) {

                float newqnt = equipamento.getQuantidade()+quant[indice];

                equipamento.setQuantidade(newqnt);

                inserirEquipamentoNaTabela(equipamento, indice);

                ui->lne_equipamento_3->clear();
                ui->lne_potencia_3->clear();
                ui->lne_quantidade_3->clear();
                ui->lne_horas_3->clear();

                produtos.inserirEquipamento(equipamento);
                total.push_back(equipamento.getNome());
                quant.push_back(equipamento.getQuantidade());

                atualizarEstatisticas();
               qnt_produtos++;


            } else {
              QMessageBox::warning(this, "ERRO", "Não fez nada");
            }
    }

    }
    else{
         QMessageBox::warning(this, "ERRO", "Insira os dados corretamente!");
    }
    }

void MainWindow::atualizarEstatisticas(){

    ui->lbl_consumototal->setText(QString::number(produtos.consumoTotal(),'f',2));
    ui->lbl_potenciatotal->setText(QString::number(produtos.potenciaTotal(),'f',2));
    ui->lbl_maiorconsumo->setText(QString::number(produtos.maiorConsumo(),'f',2));
    ui->lbl_menorconsumo->setText(QString::number(produtos.menorConsumo(),'f',2));

}


bool MainWindow::verificarEquipamento(Equipamento a)
{
    indice=0;
    bool tem = false;
    if(qnt_produtos>0){
    for(int aux=0;aux<total.size();aux++){
        if(a.getNome()==total[aux]){
            tem=true;
            indice=aux;
        }
    }
    }
    return tem;
}

