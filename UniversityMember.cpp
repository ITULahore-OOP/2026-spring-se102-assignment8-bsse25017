#include "UniversityMember.h"

UniversityMember::UniversityMember(string name, int memberID) {
    this->name = name;
    this->memberID = memberID;
}

UniversityMember::~UniversityMember() {}

string UniversityMember::getName() const {
    return name;
}

int UniversityMember::getMemberID() const {
    return memberID;
}