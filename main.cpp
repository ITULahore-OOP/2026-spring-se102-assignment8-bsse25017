#include <iostream>
#include "AccessCard.h"
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"
#include "Department.h"

using namespace std;

//  COLORS
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

int main() {

    Department dept("CS Department");

  
    Student* students[50];
    Staff* staffList[50];
    TeachingAssistant* tas[50];
    TutoringSession* sessions[50];

    int sCount = 0, stCount = 0, taCount = 0, sessCount = 0;

    int choice;

    do {
        cout << CYAN << "\n====== SMART UNIVERSITY SYSTEM ======\n" << RESET;
        cout << YELLOW;
        cout << "1. Add Student\n";
        cout << "2. Add Staff\n";
        cout << "3. Add Teaching Assistant\n";
        cout << "4. Display All Roles\n";
        cout << "5. Create Tutoring Session\n";
        cout << "6. Merge Sessions (+)\n";
        cout << "7. Compare Sessions (>)\n";
        cout << "8. TA Grade Assignment\n";
        cout << "0. Exit\n";
        cout << RESET;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        // 🔹 ADD STUDENT
        case 1: {
            if (sCount >= 50) {
                cout << RED << "Student limit reached!\n" << RESET;
                break;
            }

            string name;
            int id;
            double cgpa;

            cout << "Enter name: "; cin >> name;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter CGPA: "; cin >> cgpa;

            students[sCount] = new Student(name, id, cgpa);
            dept.addMember(students[sCount]);
            sCount++;

            cout << GREEN << "Student added!\n" << RESET;
            break;
        }

        // 🔹 ADD STAFF
        case 2: {
            if (stCount >= 50) {
                cout << RED << "Staff limit reached!\n" << RESET;
                break;
            }

            string name, cardID;
            int id, access;
            double salary;

            cout << "Enter name: "; cin >> name;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter salary: "; cin >> salary;

            cout << "Enter Card ID: "; cin >> cardID;
            cout << "Enter Access Level: "; cin >> access;

            AccessCard card(cardID, access);

            staffList[stCount] = new Staff(name, id, salary, card);
            dept.addMember(staffList[stCount]);
            stCount++;

            cout << GREEN << "Staff added!\n" << RESET;
            break;
        }

        // 🔹 ADD TA
        case 3: {
            if (taCount >= 50) {
                cout << RED << "TA limit reached!\n" << RESET;
                break;
            }

            string name, cardID;
            int id, access, hours;
            double cgpa, salary;

            cout << "Enter name: "; cin >> name;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter CGPA: "; cin >> cgpa;
            cout << "Enter salary: "; cin >> salary;

            cout << "Enter Card ID: "; cin >> cardID;
            cout << "Enter Access Level: "; cin >> access;
            cout << "Enter Working Hours: "; cin >> hours;

            AccessCard card(cardID, access);

            tas[taCount] = new TeachingAssistant(name, id, cgpa, salary, card, hours);
            dept.addMember(tas[taCount]);
            taCount++;

            cout << GREEN << "Teaching Assistant added!\n" << RESET;
            break;
        }

        //  DISPLAY ROLES (POLYMORPHISM)
        case 4:
            cout << CYAN << "\n--- All Roles ---\n" << RESET;
            dept.displayAllRoles();
            break;

        //  CREATE SESSION
        case 5: {
            if (taCount == 0 || sCount == 0) {
                cout << RED << "Need at least 1 TA and 1 Student!\n" << RESET;
                break;
            }

            if (sessCount >= 50) {
                cout << RED << "Session limit reached!\n" << RESET;
                break;
            }

            int sid;
            double duration;

            cout << "Enter Session ID: "; cin >> sid;
            cout << "Enter Duration: "; cin >> duration;

            // using first TA & Student (simple approach)
            sessions[sessCount] = new TutoringSession(sid, duration, tas[0], students[0]);
            sessCount++;

            cout << GREEN << "Session created!\n" << RESET;
            break;
        }

        //  MERGE SESSIONS
        case 6: {
            if (sessCount < 2) {
                cout << RED << "Need at least 2 sessions!\n" << RESET;
                break;
            }

            TutoringSession merged = *sessions[0] + *sessions[1];
            cout << GREEN << "Merged Duration: "
                 << merged.getDuration() << " mins\n" << RESET;
            break;
        }

        //  COMPARE SESSIONS
        case 7: {
            if (sessCount < 2) {
                cout << RED << "Need at least 2 sessions!\n" << RESET;
                break;
            }

            if (*sessions[0] > *sessions[1])
                cout << GREEN << "Session 1 is longer\n" << RESET;
            else
                cout << RED << "Session 2 is longer\n" << RESET;

            break;
        }

        //  TA GRADING
        case 8: {
            if (taCount == 0) {
                cout << RED << "No TA available!\n" << RESET;
                break;
            }

            cout << CYAN << "\n--- Grading ---\n" << RESET;
            tas[0]->gradeAssignment(95);
            tas[0]->gradeAssignment("A+");
            break;
        }

        case 0:
            cout << RED << "Exiting program...\n" << RESET;
            break;

        default:
            cout << RED << "Invalid choice!\n" << RESET;
        }

    } while (choice != 0);

    return 0;
}