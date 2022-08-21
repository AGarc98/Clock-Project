#include <iostream>
#include<windows.h>
#include<chrono>
#include "clock.h"

using namespace std;
/*
Defines functions for the clock class
Written by Alex Garcia
*/
//constructor, sets time to midnight 
Clock::Clock(){
    this->seconds = 00;
    this->minutes = 00;
    this->hours = 12;
    this->hoursMilit = 00;
    this-> am = true;
}
//function will handle when a minute or hour ticks over and resets the count
void Clock::manageClock(){
    
    if(seconds/60 > 0){
        seconds %= 60;
        minutes++;
    }
    if(minutes/60 > 0){
        minutes %= 60;
        hours++;
    }
    if(hours/12 > 0){
        hours %= 12;
        if(hours == 0){
            hours = 12;
        }
    }
    if (hoursMilit/24 > 0){
        hoursMilit %=24;
    }
    if(hoursMilit >= 12){
        am = false;
    }
    else if (hoursMilit<12)
    {
        am = true;
    }
    
}
//function to increment the count of seconds
void Clock::addSecond(){
    seconds++;
    manageClock();
}
//function that defines waiting for a second to pass
void Clock::waitSecond(){
    Sleep(1000);
}
//function to increment amount of minutes
void Clock::addMinute(){
    minutes++;
    manageClock();
}
// function to increment amount of hours
void Clock::addHour(){
    hours++;
    hoursMilit++;
    manageClock();
}
//function to change the time variable from int to 6 digit string with am or pm
string Clock::getTimeString(){
    string h, m , s, a;    
    if(hours<10){
        h = "0" + to_string(hours);
    }
    else{
        h = to_string(hours);
    }
    if(minutes<10){
        m = "0" + to_string(minutes);
    }
    else{
        m = to_string(minutes);
    }
    if(seconds<10){
        s = "0" + to_string(seconds);
    }
    else{
        s = to_string(seconds);
    }
    if(am){
        a = " AM";
    }
    else if (!am)
    {
        a= " PM";
    }
    
    return h +":"+m+":"+s + a;
}
//function to change the time variable from int to 6 digit string
string Clock::getTimeMilitString(){
    string h, m , s;    
    if(hoursMilit<10){
        h = "0" + to_string(hoursMilit);
    }
    else{
        h = to_string(hoursMilit);
    }
    if(minutes<10){
        m = "0" + to_string(minutes);
    }
    else{
        m = to_string(minutes);
    }
    if(seconds<10){
        s = "0" + to_string(seconds);
    }
    else{
        s = to_string(seconds);
    }
    return h +":"+m+":"+s;
}
//function to print times to screen
void Clock::displayTime(){
    cout<<"\t*************************\t*************************"<<endl;
    cout<<"\t*\t12-Hour Clock\t*\t*\t24-Hour Clock\t*"<<endl;
    cout<<"\t*\t"<<getTimeString()<<"\t*\t"<<"*\t"<<getTimeMilitString()<<"\t*"<<endl;
    cout<<"\t*************************\t*************************"<<endl;
}
//function to print menu to screen
void Clock::displayMenu(){
    cout<<"**************************"<<endl;
    cout<<"* 1- Add One Second      *"<<endl;
    cout<<"* 2- Add One Minute      *"<<endl;
    cout<<"* 3- Add One Hour        *"<<endl;
    cout<<"* 4- Exit                *"<<endl;
    cout<<"**************************"<<endl;
}
