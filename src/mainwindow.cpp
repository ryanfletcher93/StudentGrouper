#include "groupvisualiser.h"
#include "imperfectmergegrouper.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QString fileName;
    if (testing) {
        fileName = QString::fromStdString(inputCsvFilePath);
    }
    else {
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open Csv"), "", tr("*.csv"));
    }

    try {
        bea.parseConfigFile(fileName.toStdString());
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
    if (!bea.hasValidUngroupedInputFile()) {
        QMessageBox box;
        box.setText("No input csv chosen, please select input csv first");
        box.exec();

        return;
    }

    StudentSet ss = bea.getStudentSet();
    ss.randomize();

    int numGroups = ui->numGroupsSpinBox->value();

    BaseGrouper *grouper = new ImperfectMergeGrouper();
    grouper->setStudentSet(ss);
    grouper->setNumberGroups(numGroups);

    this->groupedStudents = grouper->groupStudents();

    int happinessScore = groupedStudents.calculateHappinessScore();
    QString happinessScoreString = QString::number(happinessScore);
    ui->happinessScoreDisplay->setText(happinessScoreString);

    delete grouper;
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

void MainWindow::on_viewResults_clicked()
{
    GroupVisualiser *wdg = new GroupVisualiser();

    int comboBoxIndex = ui->viewResultsGroupComboBox->currentIndex();

    int itIndex = 0;
    std::list<Student> studentGroup;
    for (auto it = groupedStudents.begin(); it != groupedStudents.end(); it++) {
        if (itIndex == comboBoxIndex) {
            studentGroup = *it;
        }

        itIndex++;
    }

    wdg->setStudentGroup(studentGroup);
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
        this->groupedStudents = bea.parseGroupedConfigFile(fileName.toStdString());
        ui->csvFilePathDisplay_2->setText(fileName);
    }
    catch (...) {
        QMessageBox box;
        box.setText("Invalid input csv, please check and enter again");
        box.exec();
    }
}
