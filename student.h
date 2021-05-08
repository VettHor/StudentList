#ifndef STUDENT_H
#define STUDENT_H

#include <QDate>
#include <QString>
#include <QStringList>
#include <QRegularExpression>

class Student
{
public:
    Student();
    class Node
    {
    public:
        QString m_szSurname;
        QString m_szName;
        QDate m_nYear;
        int m_nExam1, m_nExam2, m_nExam3, m_nExam4;
        double m_dRate;
        Node *pNext;

        void SetSurname(QString surname){ m_szSurname = surname; }
        void SetName(QString name) { m_szName = name; }
        void SetDate(QDate date){ m_nYear = date; }
        void SetExam1(int exam) { m_nExam1 = exam; }
        void SetExam2(int exam) { m_nExam2 = exam; }
        void SetExam3(int exam) { m_nExam3 = exam; }
        void SetExam4(int exam) { m_nExam4 = exam; }
        void SetRate(double rate) { m_dRate = rate; }

        QString GetSurname() { return m_szSurname; }
        QString GetName() { return m_szName; }
        QDate GetDate() { return m_nYear; }
        int GetExam1() { return m_nExam1; }
        int GetExam2() { return m_nExam2; }
        int GetExam3() { return m_nExam3; }
        int GetExam4() { return m_nExam4; }
        double GetRate() { return m_dRate; }

        Node()
        {
            this->m_szSurname = "";
            this->m_szName = "";
            QDate date;
            date.setDate(2000, 01, 01);
            this->m_nYear = date;
            this->m_nExam1 = 1;
            this->m_nExam2 = 1;
            this->m_nExam3 = 1;
            this->m_nExam4 = 1;
            this->m_dRate = 1;
            this->pNext = nullptr;
        }
        Node(QString m_szSurname, QString m_szName, QDate m_nYear, int m_nExam1, int m_nExam2, int m_nExam3, int m_nExam4, double m_dRate, Node *pNext)
        {
            this->m_szSurname = m_szSurname;
            this->m_szName = m_szName;
            this->m_nYear = m_nYear;
            this->m_nExam1 = m_nExam1;
            this->m_nExam2 = m_nExam2;
            this->m_nExam3 = m_nExam3;
            this->m_nExam4 = m_nExam4;
            this->m_dRate = m_dRate;
            this->pNext = pNext;
        }
    };
    void push_back(QString m_szSurname, QString m_szName, QDate m_nYear, int m_nExam1, int m_nExam2, int m_nExam3, int m_nExam4, double m_dRate);
    void pop_front();
    int GetSize() { return m_size;}
    void MakeNode(QString str);
    void FreeStudList();
    bool isEmptyList();
    int SortRateStudList(int *Same);
    int SortAlphabetStudList();
    bool comparator(QString a, QString b);
    int DeleteStudHigher4_5();
    int DeleteStudentsNotSummer();
    void DeleteStudWithNumber(int number);
    QString WriteToFile();
    int m_size = 0;
    Node *pHead = nullptr;
    Node *pTemp = nullptr;
};

#endif // STUDENT_H
