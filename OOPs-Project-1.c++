#include<iostream>
#include<conio.h>
using namespace std;

class BankingSystem{
    private:
        int CustomerCount;
        string AccountID;

        struct CustomerDetails {
            string CustomerFirstName, CustomerSecondName;
            string UserID;
            string CustomerAddress;
            int UserContactdetails;
            int CurrentAmount;
        } CustomerDetails[85];
}