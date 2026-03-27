#include "TutoringSession.h"
#include <iostream>
using namespace std;

TutoringSession::TutoringSession(int sessionID, double durationMinutes,TeachingAssistant* ta, Student* student) {
    this->sessionID = sessionID;
    this->durationMinutes = durationMinutes;
    this->ta = ta;
    this->student = student;
}

double TutoringSession::getDuration() const {
    return durationMinutes;
}

void TutoringSession::displaySession() {
    cout << "Session ID: " << sessionID
         << ", Duration: " << durationMinutes << " mins" << endl;
}

// + operator
TutoringSession TutoringSession::operator+(const TutoringSession& other) {
    return TutoringSession(0, this->durationMinutes + other.durationMinutes, ta, student);
}

// > operator
bool operator>(TutoringSession s1, TutoringSession s2) {
    return s1.getDuration() > s2.getDuration();
}