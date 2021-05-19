using namespace std;

#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>


const unsigned short numComponents = 10;

void welcome ();
void showMenu ();
void priceList ();
void printPrices ();
void makeAppointment ();
void openAppointments();
void checkTime();

char choice;
int day;
string date, customer, treatment;
string appBook[5][8][3];

int main () {
       welcome ();
       openAppointments();

   do {
        showMenu ();
        switch (toupper(choice)) {
            case 'A': makeAppointment(); break;
            case 'B': priceList (); break;
            case 'Q': cout << "\\ntThank you for choosing our services.\n"; break;
            default: cout << "\t\a\a\aInvalid choice.\n\n";
        }
   }
   while (toupper(choice) != 'Q');
   return 0;

}

void welcome () {
// Welcome the user to the program.

     cout << "\n\t\t\t   **************************\n\t\t\t   Kigri´s Beauty Salon  \n\t\t\t   **************************\n\n";
}

void showMenu () {

    cout << "\n\n\t\tSelect one of the following options:\n"
         << "\t\t------------------------------------\n\n"
         << "\t\tA:Make an Appointment\n"
         << "\t\tB: Services\n"
         << "\t\tQ: Exit\n"
         << "\t\t\t";
     cin >> choice;
    }

void openAppointments(){

}

void priceList () {

 cout << "\n\n\t\tSelect one of the following styles:\n"
         << "\t\t------------------------------------\n\n"
         << "\t\t1:Makeup    90 US$\n"
         << "\t\t2:Hairstyle 70 US$\n"
         << "\t\t3:Haircut   40 US$\n"
         << "\t\t\t";
     cin >> day;
    }
    
void printPrices (string treatments, unsigned short prices[]) {

    for (unsigned short i = 0; i < numComponents; i++) {
      cout << setw (50) << setiosflags(ios::left) << treatments[i] << prices[i] << "\n";
    if (i% 20 == 0 && i != 0)
         getch ();
      }

    }
    
void showDays () {

    cout << "\n\n\t\tSelect one of the following days:\n"
         << "\t\t------------------------------------\n\n"
         << "\t\t0:Monday\n"
         << "\t\t1:Tuesday\n"
         << "\t\t2:Wednesday\n"
         << "\t\t3:Thursday\n"
         << "\t\t4:Friday\n"
         << "\t\t\t";
     cin >> day;
    }

void makeAppointment () {
// Asks the user for the day of the appointment
    showDays();
    switch(day){
    case 0:
        date = "Monday";
        checkTime();
        break;
    case 1:
        date = "Tuesday";
        checkTime();
        break;
    case 2:
        date = "Wednesday";
        checkTime();
        break;
    case 3:
        date = "Thursday";
        checkTime();
        break;
    case 4:
        date = "Friday";
        checkTime();
        break;
    default:
        showMenu();
        break;
    }
}

void checkTime(){
    int time;
    bool checkSum = false;

    do{
        cout << "\n\n\t\tEnter time for appointment:\n"
         << "\t\t------------------------------------\n\n";
        cin >> time;
        if(appBook[day][time-9][0] == ""){
           cout << "\n\n\t\tEnter the customer name:\n"
                 << "\t\t------------------------------------\n\n";
            cin >> customer;
            cout << "\n\n\t\tEnter the service for "<< customer <<":\n"
                 << "\t\t------------------------------------\n\n";
            cin >> treatment;
            appBook[day][time-9][0] = date;
            appBook[day][time-9][1] = customer;
            appBook[day][time-9][2] = treatment;
            checkSum = true;
        } else {
            cout << "\t\t-----------------------\n\n"
                 << "\n\n\t\tThat time is taken!\n"
                 << "\t\t-----------------------\n\n";
        }
    }while(checkSum == false);

    cout << appBook[day][time-9][1] << " is getting a " << appBook[day][time-9][2] << " at " << time << " on " << appBook[day][time-9][0];
}
