#include <iostream>
#include <ctime> 

using namespace std;



void printGrades(int grades[15][13]) {
    cout << "Marks of students :\n";
    for (int i = 0; i < 13; ++i) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < 15; ++j) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }
}

double calculateAverage(int grades[13]) {
    double  sum = 0;
    for (int i = 0; i < 13; ++i) {
        sum += grades[i];
    }
    return sum / 13;
}

int countHighGrades(int grades[13]) {
    int count = 0;
    for (int i = 0; i < 13; ++i) {
        if (grades[i] > 9) {
            count++;
        }
    }
    return count;
}

int main() {
    srand((time(NULL))); 

    int grades[15][13];

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 13; ++j) {
            grades[i][j] = rand() % 12 + 1;
        }
    }

    
    printGrades(grades);

    int excellentStudents = 0;

    for (int i = 0; i < 15; ++i) {
        double average = calculateAverage(grades[i]);
        cout << "Average marks of student  " << i + 1 << ": " << average << endl;

        
        if (average < 6) {
            cout << "Student " << i + 1 << " dont pass!" << endl;
        }

       
        if (average > 8) {
            excellentStudents++;
        }

        
        int highGradesCount = countHighGrades(grades[i]);
        if (highGradesCount > 13 / 2) {
            cout << "Student " << i + 1 << " has a perfect marks! His mark more than nine: ";
            for (int j = 0; j < 13; ++j) {
                if (grades[i][j] > 9) {
                    cout << grades[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    if (excellentStudents > 15 / 2) {
        cout << "Class with perfect students !" << endl;
    }

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 13; ++j) {
            if (grades[i][j] < 9) {
                cout << "Student " << i + 1 << ", his subject " << j + 1 << " has a mark like " << grades[i][j] << ". U have a thee attemp to pass this subjetc.\n";
                for (int attempt = 1; attempt <= 3; ++attempt) {
                    int newGrade = rand() % 12 + 1;
                    cout << "Attemp " << attempt << ": ";
                    if (newGrade >= 9) {
                        grades[i][j] = newGrade;
                        cout << "u r new mark is  " << newGrade << endl;
                        break;
                    }
                    else {
                        cout << "Unluck" << endl;
                    }
                }
            }
        }
    }

    for (int j = 0; j < 13; ++j) {
        bool allBelowNine = true;
        for (int i = 0; i < 15; ++i) {
            if (grades[i][j] >= 9) {
                allBelowNine = false;
                break;
            }
        }
        if (allBelowNine) {
            cout << "All students have a mark small then nine " << j + 1 << endl;
        }
    }
}