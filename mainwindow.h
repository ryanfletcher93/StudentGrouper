#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "backendadaptor.h"
#include "studentsetanalyser.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const bool testing = true;

    const std::string inputCsvFilePath = "C:\\Users\\Ryan Fletcher\\Documents\\Programming Projects\\Qt\\StudentGrouper\\setup\\mockCsvInput.csv";
    const std::string exportCsvFilePath = "C:\\Users\\Ryan Fletcher\\Documents\\Programming Projects\\Qt\\StudentGrouper\\setup\\mockCsvOutput.csv";

private slots:
    void on_selectStudentCsvButton_clicked();

    void on_analyseDataButton_clicked();

    void on_exportCsvButton_clicked();

private:
    Ui::MainWindow *ui;

    BackendAdaptor bea;

    GroupedStudents groupedStudents;
};
#endif // MAINWINDOW_H
