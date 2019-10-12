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
    std::string filePath = "C:\\Users\\Ryan Fletcher\\Documents\\Programming Projects\\Qt\\StudentGrouper\\testData.csv";
    QString qFilePath = QString::fromStdString(filePath);
    ui->csvFilePathDisplay->setText(qFilePath);

    bea.setConfigFileAndParse(filePath);
}
