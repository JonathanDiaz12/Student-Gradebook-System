#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

int main() {
    string names[MAX_STUDENTS];
    int grades[MAX_STUDENTS];
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore(); // Ignore leftover newline

    // Input student names and grades
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter student name: ";
        getline(cin, names[i]);

        cout << "Enter " << names[i] << "'s grade: ";
        cin >> grades[i];
        cin.ignore();
    }

    // Sort grades and names (bubble sort)
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = 0; j < numStudents - i - 1; ++j) {
            if (grades[j] > grades[j + 1]) {
                int tempGrade = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = tempGrade;

                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }

    // Output sorted grades
    cout << "\nSorted Grades:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << names[i] << ": " << grades[i] << endl;
    }

    // Search for a student's grade
    string searchName;
    cout << "\nEnter student name to search: ";
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (names[i] == searchName) {
            cout << searchName << "'s grade: " << grades[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << searchName << " not found.\n";
    }

    // Calculate statistics
    int sum = 0;
    int highest = grades[0];
    int lowest = grades[0];

    for (int i = 0; i < numStudents; ++i) {
        sum += grades[i];
        if (grades[i] > highest) highest = grades[i];
        if (grades[i] < lowest) lowest = grades[i];
    }

    double average = static_cast<double>(sum) / numStudents;

    cout << "\nClass Statistics:\n";
    cout << "Average Grade: " << average << endl;
    cout << "Highest Grade: " << highest << endl;
    cout << "Lowest Grade: " << lowest << endl;

    return 0;
}