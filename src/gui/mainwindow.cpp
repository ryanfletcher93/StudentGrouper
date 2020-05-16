
#include "mainwindow.h"

#include "groupvisualiser.h"
#include "ui_mainwindow.h"

#include "../algorithm/kernighanlingrouper.h"

#include <QFileDialog>
#include <QGraphicsView>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->numGroupsSpinBox->setValue(defaultNumberGroups);

    // Disable results until grouped students are generated
    ui->viewResultsGroupComboBox->setEnabled(false);
    ui->viewResults->setEnabled(false);
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
    BaseGrouper* algorithm = new KernighanLinGrouper();
    this->groupedStudents = algorithmBackend.groupStudents(algorithm, numGroups);

    // Calculate and show happiness score
    int happinessScore = groupedStudents->calculateHappinessScore();
    ui->happinessScoreDisplay->setText(QString::number(happinessScore));

    updateViewGroupOptions(AnalysisMode::GeneratedAnalysis);

    delete algorithm;
}

void MainWindow::on_exportCsvButton_clicked()
{
    QString qExportFilePath;
    if (testing) {
        qExportFilePath = QString::fromStdString(exportCsvFilePath);
    }
    else {
        qExportFilePath = QFileDialog::getSaveFileName(
            this,
            tr("Save Image"),
            "GroupedStudents",
            tr("*.csv")
        );
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
            break;
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

void MainWindow::on_externalGroupedFileSelectButton_clicked()
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
        ui->externalGroupedFile->setText(fileName);

        updateViewGroupOptions(AnalysisMode::ExternalAnalysis);
    }
    catch (...) {
        QMessageBox box;
        box.setText("Invalid input csv, please check and enter again");
        box.exec();
    }
}

void MainWindow::updateViewGroupOptions(AnalysisMode analysisMode) {
    ui->viewResultsGroupComboBox->setEnabled(true);
    ui->viewResults->setEnabled(true);

    ui->viewResultsGroupComboBox->clear();

    int numGroups = this->groupedStudents->getGroups().size();

    for (int groupIt = 1; groupIt <= numGroups; groupIt++) {
        ui->viewResultsGroupComboBox->addItem(QString::number(groupIt));
    }

    QPalette activatedAnalysisMethod;
    activatedAnalysisMethod.setColor(QPalette::Background, Qt::green);

    QPalette deactivateAnalysisMethod;

    if (analysisMode == AnalysisMode::GeneratedAnalysis){
        ui->analysisFrame->setPalette(activatedAnalysisMethod);
        ui->analysisFrame->setAutoFillBackground(true);

        ui->externalFrame->setPalette(deactivateAnalysisMethod);
        ui->externalFrame->setAutoFillBackground(true);
    }
    else if (analysisMode == AnalysisMode::ExternalAnalysis) {
        ui->externalFrame->setPalette(activatedAnalysisMethod);
        ui->externalFrame->setAutoFillBackground(true);

        ui->analysisFrame->setPalette(deactivateAnalysisMethod);
        ui->analysisFrame->setAutoFillBackground(true);
    }
}
