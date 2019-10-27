#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectStudentCsvButton_clicked()
{
    QString fileName;
    /*
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/jana", tr("*.csv"));
        */
    fileName = QString::fromStdString(inputCsvFilePath);

    ui->csvFilePathDisplay->setText(fileName);

    bea.setConfigFileAndParse(fileName.toStdString());
}

void MainWindow::on_analyseDataButton_clicked()
{
    StudentSet ss = bea.getStudentSet();
    this->groupedStudents = StudentSetAnalyser::groupStudents(ss);
}

void MainWindow::on_exportCsvButton_clicked()
{
    QString qExportFilePath;
    /*
    QString qExportFilePath = QFileDialog::getSaveFileName(this,
            tr("Save Image"), "abc", tr("*.csv"));
            */
    qExportFilePath = QString::fromStdString(exportCsvFilePath);

    ui->exportCsvDisplay->setText(qExportFilePath);

    bea.writeOutputToFile(qExportFilePath.toStdString(), groupedStudents);
}
