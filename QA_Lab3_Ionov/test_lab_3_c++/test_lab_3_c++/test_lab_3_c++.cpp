#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;


class Job {
private:
    double salary; 
    double bonusCoefficient; 

    

public:
 
  
    void Init(double jobSalary, double jobBonusCoefficient) {
        salary = jobSalary;
        bonusCoefficient = jobBonusCoefficient;
    }

  
    void Read() {
        cout << "Введите зарплату: ";
        cin >> salary;
        cout << "Введите коэффициент доплаты: ";
        cin >> bonusCoefficient;
    }


    void Display() {
        cout << "Зарплата: " << salary << endl;
        cout << "Коэффициент доплаты: " << bonusCoefficient << endl;
    }

    
    double calculatePayment() {
        return salary * bonusCoefficient;
    }
};


class Employer {
private:
    Job jobs[3]; 
    int occupiedPlaces[3]; 

public:

    void Init(const char* employerName, double jobSalaries[], double jobBonusCoefficients[], int places[]) {

        for (int i = 0; i < 3; i++) {
            jobs[i].Init(jobSalaries[i], jobBonusCoefficients[i]);
            occupiedPlaces[i] = places[i];
        }
    }

    void Read() {
        for (int i = 0; i < 3; i++) {
            cout << "Данные для работы " << (i + 1) << ":" << endl;
            jobs[i].Read();
            cout << "Введите количество занятых мест: ";
            cin >> occupiedPlaces[i];
            cout << endl;
        }
    }

    void Display() {

        for (int i = 0; i < 3; i++) {
            cout << "Информация о работе " << (i + 1) << ":" << endl;
            jobs[i].Display();
            cout << "Количество занятых мест: " << occupiedPlaces[i] << endl;
        }
    }

    void calculateAllPayments() {
        for (int i = 0; i < 3; i++) {
            double payment = jobs[i].calculatePayment() * occupiedPlaces[i];
            cout << "Выплата для работы " << (i + 1) << ": " << payment << endl;
        }
    }


    void findMostExpensiveJob() {
        double maxPayment = jobs[0].calculatePayment() * occupiedPlaces[0];
        int maxJobIndex = 0;

        for (int i = 1; i < 3; i++) {
            double payment = jobs[i].calculatePayment() * occupiedPlaces[i];
            if (payment > maxPayment) {
                maxPayment = payment;
                maxJobIndex = i;
            }
        }

        cout << "Работа " << maxJobIndex + 1 << endl;
        jobs[maxJobIndex].Display();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    Employer employer;
    employer.Read();
    employer.Display();

    cout << "\nВыплаты всем работникам:" << endl;
    employer.calculateAllPayments();

    cout << "\nНаиболее затратная работа:" << endl;
    employer.findMostExpensiveJob();

    return 0;
}
