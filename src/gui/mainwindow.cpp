
#include "mainwindow.h"

#include "groupvisualiser.h"
#include "ui_mainwindow.h"

#include "../algorithm/imperfectmergegrouper.h"

#include <QFileDialog>
#include <QGraphicsView>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->viewResultsGroupComboBox->addItem("1");
    ui->viewResultsGroupComboBox->addItem("2");
    ui->viewResultsGroupComboBox->addItem("3");
    ui->viewResultsGroupComboBox->addItem("4");
    ui->viewResultsGroupComboBox->addItem("5");

    ui->numGroupsSpinBox->setValue(defaultNumberGroups);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectStudentCsvButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Csv"), "", tr("*.csv"));

    try {
        algorithmBackend.parseConfigFile(fileName.toStdString());
        ui->csvFilePathDisplay->setText(fileName);
    }
    catch (...) {
        QMessageBox box;
        box.setText("Invalid input csv, please check and enter again");
        box.exec();
    }
}

void MainWindow::on_analyseDataButton_clicked()
{
    if (!algorithmBackend.hasValidUngroupedInputFile()) {
        QMessageBox box;
        box.setText("No input csv chosen, please select input csv first");
        box.exec();

        return;
    }

    // Group students
    int numGroups = ui->numGroupsSpinBox->value();
    BaseGrouper* algorithm = new ImperfectMergeGrouper();
    this->groupedStudents = algorithmBackend.groupStudents(algorithm, numGroups);

    // Calculate and show happiness score
    int happinessScore = groupedStudents->calculateHappinessScore();
    ui->happinessScoreDisplay->setText(QString::number(happinessScore));

    updateViewGroupOptions();

    delete algorithm;
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
        algorithmBackend.writeOutputToFile(qExportFilePath.toStdString(), *groupedStudents);
    }
    catch (...) {
        QMessageBox box;
        box.setText("No analysis performed, press analyse data before exporting.");
        box.exec();
    }
}

void MainWindow::on_viewResults_clicked()
{
    GroupVisualiser *wdg = new GroupVisualiser();

    int comboBoxIndex = ui->viewResultsGroupComboBox->currentIndex();

    int itIndex = 0;
    StudentSet studentSet;
    for (auto it : groupedStudents->getGroups()) {
        if (itIndex == comboBoxIndex) {
            studentSet = it;
        }

        itIndex++;
    }

    wdg->setStudentGroup(studentSet);
    wdg->setNodePositions();
    std::string groupLabel = "Group " + ui->viewResultsGroupComboBox->currentText().toStdString();
    wdg->setGroupIdentifier(groupLabel);
    wdg->show();
}

void MainWindow::on_numGroupsSpinBox_valueChanged(int value)
{
    if (value <= 0 || value >= 50) {
        QMessageBox box;
        box.setText("Invalid group, please enter again");
        box.exec();
        this->ui->numGroupsSpinBox->setValue(defaultNumberGroups);
    }
}

void MainWindow::on_selectGroupedStudentCsvButton_clicked()
{
    QString fileName;
    if (testing) {
        fileName = QString::fromStdString(inputCsvFilePath);
    }
    else {
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open Csv"), "", tr("*.csv"));
    }

    try {
        this->groupedStudents = algorithmBackend.parseGroupedConfigFile(fileName.toStdString());
        ui->csvFilePathDisplay_2->setText(fileName);

        updateViewGroupOptions();
    }
    catch (...) {
        QMessageBox box;
        box.setText("Invalid input csv, please check and enter again");
        box.exec();
    }
}

void MainWindow::updateViewGroupOptions() {
    ui->viewResultsGroupComboBox->clear();

    int numGroups = this->groupedStudents->getGroups().size();

    for (int groupIt = 1; groupIt <= numGroups; groupIt++) {
        ui->viewResultsGroupComboBox->addItem(QString::number(groupIt));
    }
}
