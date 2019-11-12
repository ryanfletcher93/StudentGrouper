#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
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
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open Csv"), "", tr("*.csv"));
    }

    ui->csvFilePathDisplay->setText(fileName);


    try {
        bea.setConfigFileAndParse(fileName.toStdString());
    }
    catch (...) {
        QMessageBox box;
        box.setText("Invalid input csv, please check and enter again");
        box.exec();
    }
}

void MainWindow::on_analyseDataButton_clicked()
{
    if (!bea.hasValidInputFile()) {
        QMessageBox box;
        box.setText("No input csv chosen, please select input csv first");
        box.exec();

        return;
    }

    StudentSet ss = bea.getStudentSet();
    ss.randomize();

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
        qExportFilePath = QFileDialog::getSaveFileName(this,
                tr("Save Image"), "GroupedStudents", tr("*.csv"));
    }

    ui->exportCsvDisplay->setText(qExportFilePath);

    try {
        bea.writeOutputToFile(qExportFilePath.toStdString(), groupedStudents);
    }
    catch (...) {
        QMessageBox box;
        box.setText("No analysis performed, press analyse data before exporting.");
        box.exec();
    }
}

void MainWindow::on_numberGroupsDisplay_textEdited(const QString &textValue)
{
    bool isValid;
    int parsedValue = textValue.toInt(&isValid);
    if (!isValid || parsedValue <= 0 || parsedValue >= 50) {
        QMessageBox box;
        box.setText("Invalid group, please enter again");
        box.show();
        this->ui->numberGroupsDisplay->setText(QString(this->defaultNumberGroups));
    }
}
