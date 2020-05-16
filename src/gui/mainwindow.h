#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../algorithm/algorithmbackend.h"
#include "../students/groupedstudents.h"

#include "../ui_mainwindow.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum AnalysisMode {
    None,
    GeneratedAnalysis,
    ExternalAnalysis
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const bool testing = false;

    const int defaultNumberGroups = 5;

    /// Debug file paths used for testing
    const std::string inputCsvFilePath;
    const std::string exportCsvFilePath;

private slots:
    void on_selectStudentCsvButton_clicked();

    void on_analyseDataButton_clicked();

    void on_exportCsvButton_clicked();

    void on_viewResults_clicked();

    void on_numGroupsSpinBox_valueChanged(int arg1);

    void on_externalGroupedFileSelectButton_clicked();

    void updateViewGroupOptions(AnalysisMode analysisMode);

private:
    Ui::MainWindow *ui;

    AlgorithmBackend algorithmBackend;

    std::unique_ptr<GroupedStudents> groupedStudents;

    AnalysisMode analysisMode = AnalysisMode::None;
};
#endif // MAINWINDOW_H
