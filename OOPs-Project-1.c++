#include <iostream>
#include <conio.h>
using namespace std;

class BankingSystem
{
private:
    int CustomerCount;
    string AccountID;

    struct CustomerDetails
    {
        string CustomerFirstName, CustomerSecondName;
        string UserID;
        string CustomerAddress;
        int UserContactdetails;
        int CurrentAmount;
    } CustomerDetails[85];

public:
    BankingSystem()
    {
        CustomerCount = 0;
    }
    void OptionMenu();
    void CustomerData();
};

int main()
{
    BankingSystem;
}

void BankingSystem::OptionMenu()
{
    char input;

    cout << "\n\nPRESS..!!" << endl;
    cout << " Set up a new account --> 1 : " << endl;
    cout << " View customers list --> 2 : " << endl;
    cout << " Update information of existing account --> 3 : " << endl;
    cout << " Check the details of an existing account --> 4 : " << endl;
    cout << " For transactions --> 5 : " << endl;
    cout << " Remove existing account --> 6 : " << endl;
    cout << " Exit --> 7 : " << endl;

    input = getch();

    switch (input)
    {
    case '1':
        BankingSystem ::CustomerData();
        break;
    }
}

void BankingSystem::CustomerData()
{
    cout << "Enter data of person " << CustomerCount + 1 << endl;
    cout << "Enter First name: ";
    cin >> CustomerDetails[CustomerCount].CustomerFirstName;

    cout << "Enter Last Name: ";
    cin >> CustomerDetails[CustomerCount].CustomerSecondName;

    cout << "Enter Your UserID : ";
    cin >> CustomerDetails[CustomerCount].UserID;

    cout << "Enter Your Address: ";
    cin >> CustomerDetails[CustomerCount].CustomerAddress;

    cout << "Enter Your Contact Details : ";
    cin >> CustomerDetails[CustomerCount].UserContactdetails;

    cout << "Current Amount : ";
    cin >> CustomerDetails[CustomerCount].CurrentAmount;
    CustomerCount++;
}
