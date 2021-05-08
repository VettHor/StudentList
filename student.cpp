#include "student.h"

Student::Student()
{
    m_size = 0;
    pHead = nullptr;
}

void Student::push_back(QString m_szSurname, QString m_szName, QDate m_nYear, int m_nExam1, int m_nExam2, int m_nExam3, int m_nExam4, double m_dRate)
{
    if(pHead == nullptr)
    {
       pHead = new Node(m_szSurname, m_szName, m_nYear, m_nExam1, m_nExam2, m_nExam3, m_nExam4, m_dRate, nullptr);
    }
    else
    {
        Node* current = this->pHead;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(m_szSurname, m_szName, m_nYear, m_nExam1, m_nExam2, m_nExam3, m_nExam4, m_dRate, nullptr);
    }
    m_size++;
}

void Student::pop_front()
{
    Node *temp = pHead;
    pHead = pHead->pNext;
    delete temp;
    m_size--;
}

void Student::MakeNode(QString str)
{
    QString surname, name;
    QDate year;
    int ex1, ex2, ex3, ex4;
    QStringList data = str.split(QRegularExpression("\\s+"));
    for(int i = 0; i < 7; ++i)
    {
        if(i == 0) surname = data[i];
        if(i == 1) name = data[i];
        if(i == 2) year = QDate::fromString(data[i], "dd.MM.yyyy");
        if(i == 3) ex1 = data[i].toInt();
        if(i == 4) ex2 = data[i].toInt();
        if(i == 5) ex3 = data[i].toInt();
        if(i == 6) ex4 = data[i].toInt();
    }
    double rate = (ex1 + ex2 + ex3 + ex4) / 4.0;
    push_back(surname, name, year, ex1, ex2, ex3, ex4, rate);
}

void Student::FreeStudList()
{
  while (m_size)
  {
    pop_front();
  }
}

bool Student::isEmptyList()
{
    if(pHead == NULL) return true;
    return false;
}

int Student::SortRateStudList(int *Same)
{
    int count = 0;
    Node *pStudent1 = pHead;
    while((pStudent1->pNext) != NULL)
    {
        if(pStudent1->m_dRate == (pStudent1->pNext)->m_dRate)
        {
           *Same += 1;
        }
        pStudent1 = pStudent1->pNext;
    }
    if(*Same == m_size - 1)
    {
        return 1;
    }
    pStudent1 = pHead;
    Node *pStudent2 = pHead;
      QString copyText;
      double copyData;
      QDate copyDate;
      while (pStudent1 != NULL) {
        while ((pStudent2->pNext) != NULL) {
          if (pStudent2->m_dRate > (pStudent2->pNext)->m_dRate) {
              count++;
            copyText = pStudent2->m_szSurname;
            pStudent2->m_szSurname = (pStudent2->pNext)->m_szSurname;
            pStudent2->pNext->m_szSurname = copyText;

            copyText = pStudent2->m_szName;
            pStudent2->m_szName = (pStudent2->pNext)->m_szName;
            pStudent2->pNext->m_szName = copyText;

            copyDate = pStudent2->m_nYear;
            pStudent2->m_nYear = (pStudent2->pNext)->m_nYear;
            pStudent2->pNext->m_nYear = copyDate;

            copyData = pStudent2->m_nExam1;
            pStudent2->m_nExam1 = (pStudent2->pNext)->m_nExam1;
            (pStudent2->pNext)->m_nExam1 = copyData;

            copyData = pStudent2->m_nExam2;
            pStudent2->m_nExam2 = (pStudent2->pNext)->m_nExam2;
            (pStudent2->pNext)->m_nExam2 = copyData;

            copyData = pStudent2->m_nExam3;
            pStudent2->m_nExam3 = (pStudent2->pNext)->m_nExam3;
            (pStudent2->pNext)->m_nExam3 = copyData;

            copyData = pStudent2->m_nExam4;
            pStudent2->m_nExam4 = (pStudent2->pNext)->m_nExam4;
            (pStudent2->pNext)->m_nExam4 = copyData;

            copyData = pStudent2->m_dRate;
            pStudent2->m_dRate = (pStudent2->pNext)->m_dRate;
            (pStudent2->pNext)->m_dRate = copyData;
            }
          if(pStudent2->m_dRate == (pStudent2->pNext)->m_dRate)
          {
              *Same += 1;
          }
            pStudent2 = pStudent2->pNext;
            }
            pStudent1 = pStudent1->pNext;
            pStudent2 = pHead;
      }
      return count;
}

bool Student::comparator(QString a, QString b)
{
    return a>b;
}

int Student::SortAlphabetStudList()
{
    int count = 0;
  Node *pStudent1 = pHead, *pStudent2 = pHead;
  QString copyText;
  QDate copyDate;
  double copyData;
  while (pStudent1 != NULL) {
    while ((pStudent2->pNext) != NULL) {
      if (comparator(pStudent2->m_szSurname, (pStudent2->pNext)->m_szSurname)){
          count++;
          copyText = pStudent2->m_szSurname;
          pStudent2->m_szSurname = (pStudent2->pNext)->m_szSurname;
          pStudent2->pNext->m_szSurname = copyText;

          copyText = pStudent2->m_szName;
          pStudent2->m_szName = (pStudent2->pNext)->m_szName;
          pStudent2->pNext->m_szName = copyText;

          copyDate = pStudent2->m_nYear;
          pStudent2->m_nYear = (pStudent2->pNext)->m_nYear;
          pStudent2->pNext->m_nYear = copyDate;

          copyData = pStudent2->m_nExam1;
          pStudent2->m_nExam1 = (pStudent2->pNext)->m_nExam1;
          (pStudent2->pNext)->m_nExam1 = copyData;

          copyData = pStudent2->m_nExam2;
          pStudent2->m_nExam2 = (pStudent2->pNext)->m_nExam2;
          (pStudent2->pNext)->m_nExam2 = copyData;

          copyData = pStudent2->m_nExam3;
          pStudent2->m_nExam3 = (pStudent2->pNext)->m_nExam3;
          (pStudent2->pNext)->m_nExam3 = copyData;

          copyData = pStudent2->m_nExam4;
          pStudent2->m_nExam4 = (pStudent2->pNext)->m_nExam4;
          (pStudent2->pNext)->m_nExam4 = copyData;

          copyData = pStudent2->m_dRate;
          pStudent2->m_dRate = (pStudent2->pNext)->m_dRate;
          (pStudent2->pNext)->m_dRate = copyData;
            }
        pStudent2 = pStudent2->pNext;
        }
        pStudent1 = pStudent1->pNext;
        pStudent2 = pHead;
  }
  return count;
}

int Student::DeleteStudHigher4_5()
{
    int count = 0;
  Node *pStudent = pHead;
  while (true)
  {
        Node *pp = pStudent;
        pStudent = pStudent->pNext;
        if (pStudent == nullptr)
        {
            break;
        }
        else if (pStudent->m_dRate > 4.5)
        {
            count++;
            if (pStudent->pNext == nullptr)
            {
              pp->pNext = nullptr;
              m_size--;
              break;
            }
            pp->pNext = pStudent->pNext;
            delete pStudent;
            m_size--;
            pStudent = pp;
        }

  }

  pStudent = pHead;
  if (pStudent->m_dRate > 4.5)
  {
      count++;
    if (pStudent->pNext != nullptr)
    {
        pHead = pStudent->pNext;
    }
    else
    {
        pHead = nullptr;
    }
    m_size--;
  }
  return count;
}

int Student::DeleteStudentsNotSummer()
{
  int count = 0;
  Node *pStudent = pHead;
  while (true)
  {
    Node *pp = pStudent;
    pStudent = pStudent->pNext;
    if (pStudent == nullptr)
    {
        break;
    }
    else if ((pStudent->m_nYear.month() >= 1 && pStudent->m_nYear.month() <= 5) || (pStudent->m_nYear.month() >= 9 && pStudent->m_nYear.month() <= 12))
    {
        count++;
        if (pStudent->pNext == nullptr)
        {
            pp->pNext = nullptr;
            m_size--;
            break;
        }
            pp->pNext = pStudent->pNext;
            delete pStudent;
            m_size--;
            pStudent = pp;
        }
  }
    pStudent = pHead;
    if ((pStudent->m_nYear.month() >= 1 && pStudent->m_nYear.month() <= 5) || (pStudent->m_nYear.month() >= 9 && pStudent->m_nYear.month() <= 12))
    {
        count++;
        if (pStudent->pNext != nullptr)
        {
            pHead = pStudent->pNext;
        }
        else
        {
            pHead = nullptr;
        }
        m_size--;
    }
    return count;
}

void Student::DeleteStudWithNumber(int number)
{
    Node *pStudent = pHead;
    m_size--;
    if (number == 1) {
        if (pStudent->pNext != nullptr)
        {
            pHead = pStudent->pNext;
        }
        else
        {
            pHead = nullptr;
        }
        return;
    }
    for(int i = 0; i < number-2; ++i) {
            pStudent = pStudent->pNext;
        }
        Node *pAnotherStud = pStudent->pNext;
        pStudent->pNext = pAnotherStud->pNext;
        delete pAnotherStud;
}

QString Student::WriteToFile()
{
    Node *pStudent = pHead;
    int count = 1;
    QString result = "";
    if (pStudent->pNext == NULL) {
    result =
         QString::number(count) + ". " + (pStudent->m_szSurname) + " " + (pStudent->m_szName) + " " +
         pStudent->m_nYear.toString("dd.MM.yyyy") + " " + QString::number(pStudent->m_nExam1) + " " +
         QString::number(pStudent->m_nExam2) + " " + QString::number(pStudent->m_nExam3) + " " +
         QString::number(pStudent->m_nExam4) + " " + QString::number(pStudent->m_dRate);
       return result;
    }
    while (pStudent != NULL) {
      result +=
              QString::number(count) + ". " + (pStudent->m_szSurname) + " " + (pStudent->m_szName) + " " +
              pStudent->m_nYear.toString("dd.MM.yyyy") + " " + QString::number(pStudent->m_nExam1) + " " +
              QString::number(pStudent->m_nExam2) + " " + QString::number(pStudent->m_nExam3) + " " +
              QString::number(pStudent->m_nExam4) + " " + QString::number(pStudent->m_dRate) + "\n";
      pStudent = pStudent->pNext;
      count++;
    }
    return result;
}
