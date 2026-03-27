#ifndef UNIVERSITYMEMBER_H
#define UNIVERSITYMEMBER_H

#include <string>
using namespace std;

// Abstract Base Class
class UniversityMember {
private:
    string name;
    int memberID;

public:
    // Constructor
    UniversityMember(string name, int memberID);

    // Virtual Destructor
    virtual ~UniversityMember();

    // Getters
    string getName() const;
    int getMemberID() const;

    // Pure Virtual Function
    virtual void displayRole() = 0;
};

#endif