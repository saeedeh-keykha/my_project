#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


double average(double grades[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return sum , size;
}

void sortGrades(double grades[], int size) {
    sort(grades, grades + size);
}


void inputStudentData(string names[], string studentNumbers[], double grades[][5], double averages[], int n, string subjects[]) {
    for (int i = 0; i < n; i++) {
        cout << "Enter name student " << i + 1 << " : ";
        getline(cin, names[i]);
        cout << "Enter student number " << names[i] << ": ";
        getline(cin, studentNumbers[i]);

        cout << "Enter grades for 5 subjects:\n";
        for (int j = 0; j < 5; j++) {
            cout << subjects[j] <<": " << grades[i] [j] << " ";
            cin >> grades[i][j];
        }


        averages[i] = average(grades[i], 5);
        cin.ignore();
    }
}


void sortStudents(string names[], string studentNumbers[], double averages[], double grades[][5], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (averages[i] < averages[j] || (averages[i] == averages[j] && studentNumbers[i] > studentNumbers[j])) {

                swap(averages[i], averages[j]);

                swap(names[i], names[j]);

                swap(studentNumbers[i], studentNumbers[j]);

                for (int k = 0; k < 5; k++) {
                    swap(grades[i][k], grades[j][k]);
                }
            }
        }
    }
}


int main() {
    int n = 3;
    string names[n];
    string studentNumbers[n];
    double grades[n][5];
    double averages[n];

    string subjects[5] = {"lesson1", "lesson2", "lesson3", "lesson4", "lesson5"};

    inputStudentData(names, studentNumbers, grades, averages, n, subjects);

    sortStudents(names, studentNumbers, averages, grades, n);

    cout << "\nSorted student data based on average grades:\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << names[i]
             << ", Student Number: " << studentNumbers[i]
             << ", Average: " << averages[i] << ", Grades: ";
        for (int j = 0; j < 5; j++) {
            cout << subjects[j] << ": " << grades[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
