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
    if (testing) {
        fileName = QString::fromStdString(inputCsvFilePath);
    }
    else {
        QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Image"), "/home/jana", tr("*.csv"));
    }

    ui->csvFilePathDisplay->setText(fileName);

    bea.setConfigFileAndParse(fileName.toStdString());
}

void MainWindow::on_analyseDataButton_clicked()
{
    StudentSet ss = bea.getStudentSet();

    int numGroups = ui->numberGroupsDisplay->text().toInt();
    this->groupedStudents = StudentSetAnalyser::groupStudents(ss, numGroups);

    int happinessScore = groupedStudents.calculateHappinessScore();
    QString happinessScoreString = QString::number(happinessScore);
    ui->happinessScoreDisplay->setText(happinessScoreString);
}

void MainWindow::on_exportCsvButton_clicked()
{
    QString qExportFilePath;
    if (testing) {
        qExportFilePath = QString::fromStdString(exportCsvFilePath);
    }
    else {
        QString qExportFilePath = QFileDialog::getSaveFileName(this,
                tr("Save Image"), "abc", tr("*.csv"));
    }

    ui->exportCsvDisplay->setText(qExportFilePath);

    bea.writeOutputToFile(qExportFilePath.toStdString(), groupedStudents);
}
