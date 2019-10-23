#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QString qFilePath = QString::fromStdString(inputCsvFilePath);
    ui->csvFilePathDisplay->setText(qFilePath);

    bea.setConfigFileAndParse(inputCsvFilePath);
}

void MainWindow::on_analyseDataButton_clicked()
{
    StudentSet ss = bea.getStudentSet();
    GroupedStudents gs = bea.convertStudentSetToGroupedStudents(ss);
    this->groupedStudents = StudentSetAnalyser::reduceGroups(gs);
}

void MainWindow::on_exportCsvButton_clicked()
{
    QString qExportFilePath = QString::fromStdString(exportCsvFilePath);
    ui->exportCsvDisplay->setText(qExportFilePath);

    bea.writeOutputToFile(exportCsvFilePath, groupedStudents);
}
