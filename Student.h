#ifndef STUDENT_H
#define STUDENT_H

#include "UniversityMember.h"

// Virtual inheritance to solve Diamond Problem
class Student : virtual public UniversityMember {
private:
    double cgpa;

public:
    Student(string name, int memberID, double cgpa);

    double getCGPA() const;
    void updateCGPA(double newCGPA);

    void displayRole() override;
};

#endif