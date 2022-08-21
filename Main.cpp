#include<iostream>
#include<windows.h>
#include<conio.h>
#include<chrono>
#include"clock.cpp"


int main()
{
    /*
    first we create the clock for the program, from our previously defined class
    create a variable to keep track of user input and one to keep track of program run state
    */
    Clock mainClock = Clock();
    int menuChoice = 0;
    bool running = true;
    while(running){

    /*
    first we clear the screen
    then display time and menu
    */
        system("CLS");
        mainClock.displayTime();
        mainClock.displayMenu();
        //this will listen for the user to use the keyboard
        if(kbhit()){
            cout<<"Which option is your choice?"<<endl;
            //after the user presses a key it will listen for which option
            cin>>menuChoice;
            //this will catch if there is a type error on the user input and set choice to invalid choice
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                menuChoice = 9;
            }
        }
        //based on option the user put in it will choose what function to run
        switch(menuChoice){
            case 0:
                break;
            case 1:
                mainClock.addSecond();
                menuChoice = 0;
                cin.clear();
                break;
            case 2:
                mainClock.addMinute();
                menuChoice = 0;
                cin.clear();
                break;
            case 3:
                mainClock.addHour();
                menuChoice = 0;
                cin.clear();
                break;
            case 4:
                running = false;
                cin.clear();
                system("CLS");
                break;
            //after running function the user chose it will clear the input and reset the choice to none
            //if the user put invalid choice, it will do nothing
            default:
                cout<<"invalid choice"<<endl;
                cin.clear();
                break;

        }
        //it will always wait one second and add one second
        mainClock.addSecond();
        mainClock.waitSecond();


    }
    return 0;
}