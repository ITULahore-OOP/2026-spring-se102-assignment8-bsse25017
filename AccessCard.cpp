#include "AccessCard.h"
#include <iostream>
using namespace std;

AccessCard::AccessCard(string cardID, int accessLevel) {
    this->cardID = cardID;
    this->accessLevel = accessLevel;
}

string AccessCard::getCardID() const {
    return cardID;
}

int AccessCard::getAccessLevel() const {
    return accessLevel;
}

void AccessCard::displayCardInfo() const {
    cout << "Card ID: " << cardID << ", Access Level: " << accessLevel << endl;
}