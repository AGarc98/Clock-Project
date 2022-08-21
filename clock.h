#include<iostream>
using namespace std;
//header file
class Clock
{
    private:
    int hours, minutes, seconds, hoursMilit;
    bool am;
    public:
    Clock();
    void manageClock();
    void addSecond();
    void addMinute();
    void addHour();
    void waitSecond();
    string getTimeString();
    string getTimeMilitString();
    void displayTime();
    void displayMenu();

};