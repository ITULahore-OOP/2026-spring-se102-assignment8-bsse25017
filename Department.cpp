#include "Department.h"
#include <iostream>
using namespace std;

Department::Department(string departmentName) {
    this->departmentName = departmentName;
    memberCount = 0;
}

void Department::addMember(UniversityMember* member) {
    if (memberCount < 50) {
        members[memberCount++] = member;
    }
}

void Department::displayAllRoles() {
    for (int i = 0; i < memberCount; i++) {
        members[i]->displayRole(); // Runtime Polymorphism
    }
}