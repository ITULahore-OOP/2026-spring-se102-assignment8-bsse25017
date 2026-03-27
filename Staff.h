#ifndef STAFF_H
#define STAFF_H

#include "UniversityMember.h"
#include "AccessCard.h"

// Virtual inheritance
class Staff : virtual public UniversityMember {
private:
    double salary;
    AccessCard card; // Composition

public:
    Staff(string name, int memberID, double salary, AccessCard card);

    double getSalary() const;

    void displayRole() override;
    void displayCard();
};

#endif