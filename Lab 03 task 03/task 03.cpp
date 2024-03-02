#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
    Student(int i, string n, float g) : id(i), name(n), grade(g) {}
};

class StudentManager {
private:
    vector<Student*> records;
public:
    StudentManager() {
        // Add initial records
        addStudent(1, "Zohad", 87.0);
        addStudent(2, "Saeed", 85.5);
    }

    void addStudent(int id, string name, float grade) {
        Student* newStudent = new Student(id, name, grade);
        records.push_back(newStudent);
    }

    void updateGrade(int id, float newGrade) {
        for (Student* student : records) {
            if (student->id == id) {
                student->grade = newGrade;
                return;
            }
        }
        cout << "Student ID not found." << endl;
    }

    void displayRecords() {
        for (Student* student : records) {
            cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << endl;
        }
    }

    ~StudentManager() {
        for (Student* student : records) {
            delete student;
        }
    }
};

int main() {
    StudentManager sm;
    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add a student record" << endl;
        cout << "2. Update a student's grade" << endl;
        cout << "3. Display all student records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            int id;
            string name;
            float grade;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter student grade: ";
            cin >> grade;
            sm.addStudent(id, name, grade);
            break;
        }
        case '2': {
            int id;
            float newGrade;
            cout << "Enter student ID to update grade: ";
            cin >> id;
            cout << "Enter new grade: ";
            cin >> newGrade;
            sm.updateGrade(id, newGrade);
            break;
        }
        case '3':
            cout << "Student Records:" << endl;
            sm.displayRecords();
            break;
        case '4':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != '4');

    return 0;
}
