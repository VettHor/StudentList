#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpression re("^[a-zA-Zа-яА-ЯіІїЇЄє]*$");
    QValidator *validator = new QRegularExpressionValidator(re, this);
    ui->surname->setValidator(validator);
    ui->name->setValidator(validator);

    ui->groupAdd->hide();
    ui->DeleteNumb->hide();
    ui->groupBox->hide();
    ui->groupBox_2->hide();
    ui->comboBox->addItem("1");
    ui->comboBox->addItem("2");
    ui->comboBox->addItem("3");
    ui->comboBox->addItem("4");
    ui->comboBox->addItem("5");

    ui->comboBox_2->addItem("1");
    ui->comboBox_2->addItem("2");
    ui->comboBox_2->addItem("3");
    ui->comboBox_2->addItem("4");
    ui->comboBox_2->addItem("5");

    ui->comboBox_3->addItem("1");
    ui->comboBox_3->addItem("2");
    ui->comboBox_3->addItem("3");
    ui->comboBox_3->addItem("4");
    ui->comboBox_3->addItem("5");

    ui->comboBox_4->addItem("1");
    ui->comboBox_4->addItem("2");
    ui->comboBox_4->addItem("3");
    ui->comboBox_4->addItem("4");
    ui->comboBox_4->addItem("5");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_groupCancel_clicked()
{
    ui->surname->setText("");
    ui->name->setText("");
    QDate date (2000, 01, 01);
    ui->dateEdit->setDate(date);
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);
    ui->groupAdd->hide();
    ui->add_2->show();
    ui->sortRate->show();
    ui->sortAlphabet->show();
    ui->deleteHigher4_5->show();
    ui->deleteNotSum->show();
    ui->deleteWithNumb->show();
    ui->label->show();
}

void MainWindow::on_groupOK_clicked()
{
      QString sur = ui->surname->text();
      QString nam = ui->name->text();
      if(sur == "" && nam != "")
      {
          QMessageBox::critical(0,"Error","You have to enter all columns! Enter surname!", QMessageBox::Close);
          return;
      }
      if(sur != "" && nam == "")
      {
          QMessageBox::critical(0,"Error","You have to enter all columns! Enter name!", QMessageBox::Close);
          return;
      }
      if(sur == "" && nam == "")
      {
          QMessageBox::critical(0,"Error","You have to enter all columns! Enter surname and name!", QMessageBox::Close);
          return;
      }
      QDate dat = ui->dateEdit->date();
      int ex1 = ui->comboBox->currentText().toInt();
      int ex2 = ui->comboBox_2->currentText().toInt();
      int ex3 = ui->comboBox_3->currentText().toInt();
      int ex4 = ui->comboBox_4->currentText().toInt();
      double rat = (ex1 + ex2 + ex3 + ex4) / 4.0;
      HeadStud.push_back(sur, nam, dat, ex1, ex2, ex3, ex4, rat);
      printTable();
      on_groupCancel_clicked();
}

void MainWindow::printTable()
{
    if(HeadStud.isEmptyList())
    {
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);
        QMessageBox::information(0, "Information", "The list is empty now!", QMessageBox::Close);
        return;
    }
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(HeadStud.GetSize());
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("№:"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Surname:"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Name:"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Birth:"));
    ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("Exams:"));
    ui->tableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem("Rate:"));
    QString styleSheet = "::section {" // "QHeaderView::section {"
                         "spacing: 10px;"
                         "background-color: #3F3F3F;"
                         "color: white;"
                         "font: bold;"
                         "border: 1px solid white;"
                         "margin: 1px;"
                         "text-align: right;"
                         "font-family: arial;"
                         "font-size: 16px; }";
    ui->tableWidget->horizontalHeader()->setStyleSheet(styleSheet);
    HeadStud.pTemp = HeadStud.pHead;
    for(int i = 0; i < HeadStud.GetSize(); ++i)
    {
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(i + 1));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 0, item);

        item = new QTableWidgetItem(HeadStud.pTemp->GetSurname());
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 1, item);

        item = new QTableWidgetItem(HeadStud.pTemp->GetName());
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 2, item);

       item = new QTableWidgetItem(HeadStud.pTemp->GetDate().toString("dd.MM.yyyy"));
       item->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->setItem(i, 3, item);

       item = new QTableWidgetItem(QString::number(HeadStud.pTemp->GetExam1()) + ", " + QString::number(HeadStud.pTemp->GetExam2()) + ", " + QString::number(HeadStud.pTemp->GetExam3()) + ", " + QString::number(HeadStud.pTemp->GetExam4()));
       item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 4, item);

        item = new QTableWidgetItem(QString::number(HeadStud.pTemp->GetRate()));
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 5, item);
        HeadStud.pTemp = HeadStud.pTemp->pNext;
        ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
    ui->tableWidget->verticalHeader()->setVisible(false);
}

void MainWindow::on_add_2_clicked()
{
    ui->groupAdd->show();
    ui->add_2->hide();
    ui->sortRate->hide();
    ui->sortAlphabet->hide();
    ui->deleteHigher4_5->hide();
    ui->deleteNotSum->hide();
    ui->deleteWithNumb->hide();
    ui->label->hide();
    ui->groupBox->hide();
}

bool MainWindow::IsWithoutText()
{
    QString mFilename = "C:\\Users\\VETAL\\Desktop\\QT\\StudentList\\input.txt";
    QFile sFile(mFilename);
    sFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&sFile);
    QString text = in.readAll();
    sFile.close();
    if(text.trimmed().isEmpty()) return true;
    return false;
}

void MainWindow::on_open_triggered()
{
    if(!HeadStud.isEmptyList()) HeadStud.FreeStudList();
    QString mFilename = "C:\\Users\\VETAL\\Desktop\\QT\\StudentList\\input.txt";
    if(!QFileInfo::exists(mFilename))
    {
        QMessageBox::critical(0,"Existing file","The file 'input.txt' doesn't exist! Create it!", QMessageBox::Close);
        return;
    }
    if(IsWithoutText())
    {
        QMessageBox::critical(0,"File warning","File 'input.txt' is empty! Fill the file!", QMessageBox::Close);
        return;
    }
    QFile sFile(mFilename);
    sFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&sFile);
    int iteration = 1;
    unsigned mistake = 0;
    QString resMistake = "";
    unsigned skip = 0;
    unsigned checkergrade = 0;
    while(!in.atEnd())
    {
        int symb = 0;
        QString line = in.readLine();
        QStringList words = line.split(' ');
        int numWords = words.length();
        if(numWords < 7)
        {
            resMistake += "Check line [" + QString::number(iteration) + "]! Not enough arguments!\n";
            mistake++;
            skip++;
        }
        if(numWords > 7)
        {
            resMistake += "Check line [" + QString::number(iteration) + "]! Too many arguments!\n";
            mistake++;
            skip++;
        }
        if(!skip)
        {
            QString sur = words[0];
            for(int i = 0; i < sur.length(); ++i)
            {
                if(!((sur[i] >= 'a' && sur[i] <= 'z') || (sur[i] >= 'A' && sur[i] <= 'Z')))
                {
                    symb++;
                }
            }
            if(symb != 0)
            {
                resMistake += "Check line [" + QString::number(iteration) + "]! Wrong symbols in the surname!\n";
                mistake++;
            }
            symb = 0;
            QString name = words[1];
            for(int i = 0; i < name.length(); ++i)
            {
                if(!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')))
                {
                    symb++;
                }
            }
            if(symb != 0)
            {
                resMistake += "Check line [" + QString::number(iteration) + "]! Wrong symbols in the name!\n";
                mistake++;
            }
            QStringList checkDate = words[2].split('.');
            QDate cheeckDate = QDate::fromString(words[2], "dd.MM.yyyy");
            if(cheeckDate.isNull() || checkDate[2].toInt() <= 0)
            {
                resMistake += "Check line [" + QString::number(iteration) + "]! Wrong year of birth!\n";
                mistake++;
            }


            for(int i = 0; i < words[3].length(); ++i)
            {
                if(words[3].at(i).isLetter())
                {
                    mistake++;
                    checkergrade++;
                    break;
                }
            }
            for(int i = 0; i < words[4].length(); ++i)
            {
                if(words[4].at(i).isLetter())
                {
                    mistake++;
                    checkergrade++;
                    break;
                }
            }
            for(int i = 0; i < words[5].length(); ++i)
            {
                if(words[5].at(i).isLetter())
                {
                    mistake++;
                    checkergrade++;
                    break;
                }
            }
            for(int i = 0; i < words[6].length(); ++i)
            {
                if(words[6].at(i).isLetter())
                {
                    mistake++;
                    checkergrade++;
                    break;
                }
            }
            if(words[4].toInt() <= 0 || words[3].toInt() >=6 ||
               words[5].toInt() <= 0 || words[4].toInt() >=6 ||
               words[6].toInt() <= 0 || words[5].toInt() >=6 ||
               words[6].toInt() <= 0 || words[6].toInt() >=6)
            {
                checkergrade++;
                mistake++;
            }
            if(checkergrade)
            {
                resMistake += "Check line [" + QString::number(iteration) + "]! Wrong grades of exams!\n";
            }
        }
        if(!mistake) HeadStud.MakeNode(line);
        iteration++;
        skip = 0;
        checkergrade = 0;
    }
    if(mistake)
    {
       resMistake += "\nRight format :\nSurname Name dd.MM.yyyy Exam1 Exam2 Exam3 Exam4";
       QMessageBox::critical(0, "Error", resMistake, QMessageBox::Close);
       HeadStud.FreeStudList();
       return;
    }
    printTable();
    sFile.close();
}

void MainWindow::on_sortRate_clicked() // check
{
    if(HeadStud.isEmptyList())
    {
        QMessageBox::critical(0, "Error", "You can't sort empty list! Create it!", QMessageBox::Close);
        return;
    }
    if(HeadStud.pHead->pNext == nullptr)
    {
        QMessageBox::critical(0, "Error", "You can't sort list with only one student! Add more!", QMessageBox::Close);
        return;
    }
    int same = 0;
    int count = HeadStud.SortRateStudList(&same);
    if(same == HeadStud.m_size - 1)
    {
        QMessageBox::information(0, "Information", "Everyone has the same rate!", QMessageBox::Close);
        return;
    }
    if(count == 0)
    {
        QMessageBox::information(0, "Information", "It is already sorted!", QMessageBox::Close);
        return;
    }
    printTable();
}

void MainWindow::on_sortAlphabet_clicked() // check
{
    if(HeadStud.isEmptyList())
    {
        QMessageBox::critical(0, "Error", "You can't sort empty list! Create it!", QMessageBox::Close);
        return;
    }
    if(HeadStud.pHead->pNext == nullptr)
    {
        QMessageBox::critical(0, "Error", "You can't sort list with only one student! Add more!", QMessageBox::Close);
        return;
    }
    int count = HeadStud.SortAlphabetStudList();
    if(count == 0)
    {
        QMessageBox::information(0, "Information", "It is already sorted!", QMessageBox::Close);
        return;
    }
    printTable();
}

void MainWindow::on_deleteHigher4_5_clicked()
{
    if(HeadStud.isEmptyList())
    {
        QMessageBox::critical(0, "Error", "You can't delete students! The list is empty!", QMessageBox::Close);
        return;
    }
    QMessageBox::StandardButton reply = QMessageBox::warning(0, "Warning", "Are you sure to delete studets? You can't go back!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        int count = HeadStud.DeleteStudHigher4_5();
        if(count == 0)
        {
            QMessageBox::critical(0, "Error", "Nobody has grades higher 4.5!", QMessageBox::Close);
        }
        printTable();
    }
}

void MainWindow::on_deleteNotSum_clicked()
{
    if(HeadStud.isEmptyList())
    {
        QMessageBox::critical(0, "Error", "You can't delete students! The list is empty!", QMessageBox::Close);
        return;
    }
    QMessageBox::StandardButton reply = QMessageBox::warning(0, "Warning", "Are you sure to delete studets? You can't go back!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        int count = HeadStud.DeleteStudentsNotSummer();
        if(count == 0)
        {
            QMessageBox::critical(0, "Error", "Nobody is born in the winter, spring and autumn!", QMessageBox::Close);
            return;
        }
        printTable();
    }
}

void MainWindow::on_deleteWithNumb_clicked()
{
    if(HeadStud.isEmptyList())
    {
        QMessageBox::critical(0, "Error", "You can't delete student! The list is empty!", QMessageBox::Close);
        return;
    }
    ui->comboBox_5->clear();
    ui->DeleteNumb->show();
    ui->add_2->hide();
    ui->sortRate->hide();
    ui->sortAlphabet->hide();
    ui->deleteHigher4_5->hide();
    ui->deleteNotSum->hide();
    ui->deleteWithNumb->hide();
    ui->label->hide();

    QString item = "1";
    for(int i = 0; i < HeadStud.m_size; ++i)
    {
        item = QString::number(i+1);
        ui->comboBox_5->addItem(item);
    }
    printTable();
}

void MainWindow::on_groupOK_2_clicked()
{
    HeadStud.DeleteStudWithNumber(ui->comboBox_5->currentText().toInt());
    on_groupCancel_2_clicked();
    printTable();
}

void MainWindow::on_groupCancel_2_clicked()
{
    ui->comboBox_5->setCurrentIndex(0);
    ui->DeleteNumb->hide();
    ui->add_2->show();
    ui->sortRate->show();
    ui->sortAlphabet->show();
    ui->deleteHigher4_5->show();
    ui->deleteNotSum->show();
    ui->deleteWithNumb->show();
    ui->label->show();
}

void MainWindow::on_save_triggered()
{
    QString mFilename = "C:\\Users\\VETAL\\Desktop\\QT\\Lab_VIPZ\\output.txt";
    QFile sFile(mFilename);
    if(!QFileInfo::exists(mFilename))
    {
        QMessageBox::critical(0,"Error","The file 'output.txt' doesn't exist! Create it!", QMessageBox::Close);
        return;
    }
    if(HeadStud.isEmptyList())
    {
        QMessageBox::critical(0, "Error", "You can't save list! The list is empty!", QMessageBox::Close);
        return;
    }
    sFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&sFile);
    out << HeadStud.WriteToFile();
    sFile.close();
    QMessageBox::information(0, "Information", "Data is successfully written to the file!", QMessageBox::Close);
}

void MainWindow::on_action_triggered()
{
    on_open_triggered();
}

void MainWindow::on_action_2_triggered()
{
    on_save_triggered();
}

void MainWindow::on_delete_2_triggered()
{
    if(HeadStud.isEmptyList())
    {
        QMessageBox::critical(0, "Error", "You can't delete student list! The list is already empty!", QMessageBox::Close);
        return;
    }
    QMessageBox::StandardButton reply = QMessageBox::warning(0, "Warning", "Are you sure to make list empty? You can't go back!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        HeadStud.FreeStudList();
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);
    }
}

void MainWindow::on_END_triggered()
{
    if(!HeadStud.isEmptyList())
    {
        QMessageBox box;
        QMessageBox::StandardButton reply;
        reply = box.question(0, "Closing the program", "Do you want to save current list?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Close);
        if(reply == box.Close)
        {
            return;
        }
        if (reply == box.Yes)
        {
            QString mFilename = "C:\\Users\\VETAL\\Desktop\\QT\\Lab_VIPZ\\output.txt";
            QFile sFile(mFilename);
            if(!QFileInfo::exists(mFilename))
            {
                box.critical(0,"Error","The file 'output.txt' doesn't exist! Create it!");
                return;
            }
            sFile.open(QFile::WriteOnly | QFile::Text);
            QTextStream out(&sFile);
            out << HeadStud.WriteToFile();
            sFile.close();
        }
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);
    }
    HeadStud.FreeStudList();
    this->close();
}

void MainWindow::on_actionAddStudent_triggered()
{
    on_add_2_clicked();
    ui->DeleteNumb->hide();
    ui->groupBox->hide();
}

void MainWindow::on_groupOK_3_clicked()
{
    if(!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked() && !ui->radioButton_3->isChecked())
    {
        QMessageBox::warning(0, "Warning", "Nothing will be happened! Choose button!", QMessageBox::Close);
        return;
    }
    ui->groupBox->hide();
    ui->add_2->show();
    ui->sortRate->show();
    ui->sortAlphabet->show();
    ui->deleteHigher4_5->show();
    ui->deleteNotSum->show();
    ui->deleteWithNumb->show();
    ui->label->show();
    if(ui->radioButton->isChecked()) on_deleteHigher4_5_clicked();
    if(ui->radioButton_2->isChecked()) on_deleteNotSum_clicked();
    if(ui->radioButton_3->isChecked()) on_deleteWithNumb_clicked();
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton->setAutoExclusive(true);

    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setAutoExclusive(true);

    ui->radioButton_3->setAutoExclusive(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_3->setAutoExclusive(true);
}

void MainWindow::on_DelStud_triggered()
{
    if(HeadStud.isEmptyList())
    {
        QMessageBox::critical(0, "Error", "The list is empty! You can't delete students", QMessageBox::Close);
        return;
    }
    ui->groupAdd->hide();
    ui->groupBox_2->hide();
    ui->DeleteNumb->hide();
    ui->add_2->hide();
    ui->sortRate->hide();
    ui->sortAlphabet->hide();
    ui->deleteHigher4_5->hide();
    ui->deleteNotSum->hide();
    ui->deleteWithNumb->hide();
    ui->label->hide();
    ui->groupBox->show();
}

void MainWindow::on_groupCancel_3_clicked()
{
    ui->groupBox->hide();
    ui->add_2->show();
    ui->sortRate->show();
    ui->sortAlphabet->show();
    ui->deleteHigher4_5->show();
    ui->deleteNotSum->show();
    ui->deleteWithNumb->show();
    ui->label->show();
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton->setAutoExclusive(true);

    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setAutoExclusive(true);

    ui->radioButton_3->setAutoExclusive(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_3->setAutoExclusive(true);
}

void MainWindow::on_groupOK_4_clicked()
{
    if(!ui->radioButton_4->isChecked() && !ui->radioButton_5->isChecked())
    {
        QMessageBox::warning(0, "Warning", "Nothing will be happened! Choose button!", QMessageBox::Close);
        return;
    }
    ui->groupBox_2->hide();
    ui->groupBox->hide();
    ui->add_2->show();
    ui->sortRate->show();
    ui->sortAlphabet->show();
    ui->deleteHigher4_5->show();
    ui->deleteNotSum->show();
    ui->deleteWithNumb->show();
    ui->label->show();
    if(ui->radioButton_4->isChecked())
    {
        on_sortRate_clicked();
    }
    if(ui->radioButton_5->isChecked())
    {
        on_sortAlphabet_clicked();
    }
}

void MainWindow::on_Sort_triggered()
{
    if(HeadStud.isEmptyList())
    {
        QMessageBox::critical(0, "Error", "The list is empty! You can't sort student list!", QMessageBox::Close);
        return;
    }
    ui->groupAdd->hide();
    ui->DeleteNumb->hide();
    ui->groupBox->hide();
    ui->add_2->hide();
    ui->sortRate->hide();
    ui->sortAlphabet->hide();
    ui->deleteHigher4_5->hide();
    ui->deleteNotSum->hide();
    ui->deleteWithNumb->hide();
    ui->label->hide();
    ui->groupBox_2->show();
    ui->radioButton_4->setAutoExclusive(false);
    ui->radioButton_4->setChecked(false);
    ui->radioButton_4->setAutoExclusive(true);

    ui->radioButton_5->setAutoExclusive(false);
    ui->radioButton_5->setChecked(false);
    ui->radioButton_5->setAutoExclusive(true);
}

void MainWindow::on_groupCancel_4_clicked()
{
    ui->groupBox_2->hide();
    ui->add_2->show();
    ui->sortRate->show();
    ui->sortAlphabet->show();
    ui->deleteHigher4_5->show();
    ui->deleteNotSum->show();
    ui->deleteWithNumb->show();
    ui->label->show();
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton->setAutoExclusive(true);

    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setAutoExclusive(true);

    ui->radioButton_3->setAutoExclusive(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_3->setAutoExclusive(true);
}

void MainWindow::on_Exit_triggered()
{
    this->close();
}

void MainWindow::on_action_Add_student_to_list_triggered()
{
    on_add_2_clicked();
}

void MainWindow::on_actionDelete_student_from_list_triggered()
{
    on_deleteWithNumb_clicked();
}

void MainWindow::on_actionSort_student_list_triggered()
{
    on_sortRate_clicked();
}

void MainWindow::on_actionAbout_program_triggered()
{
    About window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_actionDelete_students_not_in_the_summer_triggered()
{
    on_deleteNotSum_clicked();
}

void MainWindow::on_actionDelete_students_higher_4_5_triggered()
{
    on_deleteHigher4_5_clicked();
}

void MainWindow::on_actionSort_student_list_in_alphabetical_order_triggered()
{
    on_sortAlphabet_clicked();
}
