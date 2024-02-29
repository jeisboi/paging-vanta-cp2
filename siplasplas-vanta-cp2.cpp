#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Student {
    string firstName;
    string lastName;
    string year;
    string section;
    string course;
    Student* next;
};

void DisplayMenu() {
    cout << "\n\n\tMAIN MENU: \n" << endl;
    cout << "\t\t1. Student Infos" << endl;
    cout << "\t\t2. Add student info" << endl;
    cout << "\t\t3. Exit" << endl;
    cout << "\t\tEnter your choice: ";
}

int GetMenuChoice() {
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

void AddStudent(Student** head) {
    system("CLS");
    Student* newStudent = new Student;
    cout << "\tFirst Name: ";
    getline(cin, newStudent->firstName);
    cout << "\tLast Name: ";
    getline(cin, newStudent->lastName);
    cout << "\tYear: ";
    getline(cin, newStudent->year);
    cout << "\tSection: ";
    getline(cin, newStudent->section);
    cout << "\tCourse: ";
    getline(cin, newStudent->course);
    newStudent->next = nullptr;

    if (*head == nullptr) {
        *head = newStudent;
    }
    else {
        Student* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newStudent;
    }
    system("cls");
    cout << "Student information added successfully." << endl;
}

void ViewStudents(Student* head) {
    if (head == nullptr) {
        system("cls");
        cout << "No students found." << endl;
        return;
    }

    int studentCount = 0;
    int currentPage = 1;
    Student* current = head;

    while (current != nullptr) {
        system("cls");
        cout << endl << "Students (Page " << currentPage << "):" << endl;

        for (int i = 0; i < 5 && current != nullptr; ++i) {
            cout << "- " << current->firstName << " " << current->lastName << " ("
                << current->year << ", " << current->section << ", " << current->course << ") \n" << endl;
            current = current->next;
            studentCount++;
        }

        if (current != nullptr) {
            cout << "Press any key to go to the next page...";
    #ifdef _WIN32
            system("pause");
    #else
            cin.get();
    #endif
        }
        else {
            cout << "Press any key to return to the main menu...";
    #ifdef _WIN32
            system("pause");
    #else
            cin.get();
    #endif
        }
        system("cls");

        currentPage++;
    }
}

int main() {
    Student* head = nullptr;
    int choice;
    while (true) {
        DisplayMenu();
        choice = GetMenuChoice();
        switch (choice) {
        case 1:
            ViewStudents(head);
            break;
        case 2:
            AddStudent(&head);
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
