#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 100;
string names[MAX_STUDENTS];
float grades[MAX_STUDENTS];
int studentCount = 0;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int findStudentByName(string target) {
    for (int i = 0; i < studentCount; i++) {
        if (names[i] == target) return i;
    }
    return -1;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "\\nStudent list is full.\\n";
        return;
    }

    string newName;
    cout << "\\nEnter student name (one word): ";
    cin >> newName;

    if (findStudentByName(newName) != -1) {
        cout << "A student with this name already exists. Use a different name.\\n";
        return;
    }

    float newGrade;
    cout << "Enter grade (0-100): ";
    while (!(cin >> newGrade) || newGrade < 0 || newGrade > 100) {
        cout << "Invalid grade. Enter a number from 0 to 100: ";
        clearInput();
    }

    names[studentCount] = newName;
    grades[studentCount] = newGrade;
    studentCount++;
    cout << "Student added successfully!\\n";
}

void showStudents() {
    if (studentCount == 0) {
        cout << "\\nNo students available yet.\\n";
        return;
    }

    cout << "\\n--- Student List ---\\n";
    cout << left << setw(6) << "No." << setw(20) << "Name" << "Grade\\n";
    cout << "--------------------------------\\n";
    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(6) << i + 1 << setw(20) << names[i]
             << fixed << setprecision(2) << grades[i] << "\\n";
    }
}

void showAverage() {
    if (studentCount == 0) {
        cout << "\\nNo grades available to calculate an average.\\n";
        return;
    }

    float total = 0;
    for (int i = 0; i < studentCount; i++) total += grades[i];

    cout << "\\nClass average: " << fixed << setprecision(2)
         << total / studentCount << "\\n";
}

void showHighestGrade() {
    if (studentCount == 0) {
        cout << "\\nNo students available.\\n";
        return;
    }

    int highestIndex = 0;
    for (int i = 1; i < studentCount; i++) {
        if (grades[i] > grades[highestIndex]) highestIndex = i;
    }

    cout << "\\nHighest grade: " << names[highestIndex] << " ("
         << fixed << setprecision(2) << grades[highestIndex] << ")\\n";
}

void searchStudent() {
    if (studentCount == 0) {
        cout << "\\nNo students available to search.\\n";
        return;
    }

    string searchName;
    cout << "\\nEnter the exact student name (one word): ";
    cin >> searchName;

    int index = findStudentByName(searchName);
    if (index == -1) {
        cout << "Student not found.\\n";
    } else {
        cout << "Student found: " << names[index] << " | Grade: "
             << fixed << setprecision(2) << grades[index] << "\\n";
    }
}

void showMenu() {
    cout << "\\n========== Student Grade Manager ==========\\n";
    cout << "1. Add student\\n";
    cout << "2. Show all students\\n";
    cout << "3. Calculate class average\\n";
    cout << "4. Show highest grade\\n";
    cout << "5. Search for a student\\n";
    cout << "6. Exit\\n";
    cout << "Choose an option: ";
}

int main() {
    int choice = 0;
    do {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number from 1 to 6.\\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: showAverage(); break;
            case 4: showHighestGrade(); break;
            case 5: searchStudent(); break;
            case 6: cout << "\\nThank you for using Student Grade Manager. Goodbye!\\n"; break;
            default: cout << "Invalid choice. Please choose from 1 to 6.\\n";
        }
    } while (choice != 6);

    return 0;
}
