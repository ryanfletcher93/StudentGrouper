#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "backendadaptor.h"

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

    const bool testing = false;

    /// TODO: Move to BackendAdaptor
    const int defaultNumberGroups = 5;

    /// Debug file paths used for testing
    const std::string inputCsvFilePath = "C:\\Users\\Ryan Fletcher\\Documents\\Programming Projects\\Qt\\StudentGrouper\\setup\\mockCsvInput.csv";
    const std::string exportCsvFilePath = "C:\\Users\\Ryan Fletcher\\Documents\\Programming Projects\\Qt\\StudentGrouper\\setup\\mockCsvOutput.csv";

private slots:
    void on_selectStudentCsvButton_clicked();

    void on_analyseDataButton_clicked();

    void on_exportCsvButton_clicked();

    void on_viewResults_clicked();

    void on_numGroupsSpinBox_valueChanged(int arg1);

    void on_selectGroupedStudentCsvButton_clicked();

private:
    Ui::MainWindow *ui;

    BackendAdaptor bea;
    GroupedStudents groupedStudents;
};
#endif // MAINWINDOW_H
