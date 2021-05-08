#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "about.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_groupCancel_clicked();
    void on_groupOK_clicked();
    void printTable();
    void on_add_2_clicked();
    void on_open_triggered();
    bool IsWithoutText();
    void on_sortRate_clicked();
    void on_sortAlphabet_clicked();
    void on_deleteHigher4_5_clicked();
    void on_deleteNotSum_clicked();
    void on_deleteWithNumb_clicked();
    void on_groupOK_2_clicked();
    void on_groupCancel_2_clicked();
    void on_save_triggered();
    void on_action_triggered();
    void on_action_2_triggered();
    void on_delete_2_triggered();
    void on_END_triggered();
    void on_actionAddStudent_triggered();
    void on_groupOK_3_clicked();
    void on_DelStud_triggered();
    void on_groupCancel_3_clicked();
    void on_groupOK_4_clicked();
    void on_Sort_triggered();
    void on_groupCancel_4_clicked();
    void on_Exit_triggered();
    void on_action_Add_student_to_list_triggered();
    void on_actionDelete_student_from_list_triggered();
    void on_actionSort_student_list_triggered();
    void on_actionAbout_program_triggered();
    void on_actionDelete_students_not_in_the_summer_triggered();

    void on_actionDelete_students_higher_4_5_triggered();

    void on_actionSort_student_list_in_alphabetical_order_triggered();

private:
    Ui::MainWindow *ui;
    Student HeadStud;
};
#endif // MAINWINDOW_H
