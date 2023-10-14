#include <iostream>
#include <conio.h>
#include<windows.h>
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
    void DisplayDetails();
    void UpdateDetails();
    void FindCustomer();
    void DeleteCustomer();
    void Transaction();
};

int main()
{
    BankingSystem start;
    start.OptionMenu();

    return 0;
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
    case '2':
        BankingSystem ::DisplayDetails();
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

void BankingSystem ::DisplayDetails()
{

    for (int i = 0; i < CustomerCount; i++)
    {

        cout << "............:Customer Information :............." << i + 1 << endl;

        cout << "Customer Full Name :--> " << CustomerDetails[i].CustomerFirstName << " " << CustomerDetails[i].CustomerSecondName << endl;
        cout << "Customer's User ID :--> " << CustomerDetails[i].UserID << endl;
        cout << "Customer Full Address :--> " << CustomerDetails[i].CustomerAddress << endl;
        cout << "Customer Contact Details :--> " << CustomerDetails[i].UserContactdetails << endl;
        cout << "Customer Current Balance :--> " << CustomerDetails[i].CurrentAmount << endl;
    }
}

void BankingSystem ::UpdateDetails()
{
    cout << "Enter the AccountID of Customer :--> " << endl;
    cin >> AccountID;

    for (int i = 0; i < CustomerCount; i++)
    {
        if (AccountID == CustomerDetails[i].UserID)
        {

            cout << "Current Details of Customer :............" << endl;

            cout << "Customer Information " << i + 1 << endl;
            cout << "Customer Full Name :--> " << CustomerDetails[i].CustomerFirstName << " " << CustomerDetails[i].CustomerSecondName << endl;
            cout << "Customer's User ID :--> " << CustomerDetails[i].UserID << endl;
            cout << "Customer Full Address :--> " << CustomerDetails[i].CustomerAddress << endl;
            cout << "Customer Contact Details :--> " << CustomerDetails[i].UserContactdetails << endl;
            cout << "Customer Current Balance :--> " << CustomerDetails[i].CurrentAmount << endl;

            cout << "\nEnter new data" << endl;

            cout << "Enter First name: ";
            cin >> CustomerDetails[i].CustomerFirstName;

            cout << "Enter Last Name: ";
            cin >> CustomerDetails[i].CustomerSecondName;

            cout << "Enter Your UserID : ";
            cin >> CustomerDetails[i].UserID;

            cout << "Enter Your Address: ";
            cin >> CustomerDetails[i].CustomerAddress;

            cout << "Enter Your Contact Details : ";
            cin >> CustomerDetails[i].UserContactdetails;

            cout << "Current Amount : ";
            cin >> CustomerDetails[i].CurrentAmount;

            break;
        }

        if (i == CustomerCount - 1)
        {

            cout << " !! Worng Details Entered !! " << endl;
            cout << " OR " << endl;
            cout << " No User Found " << endl;
        }
    }
}

void BankingSystem ::FindCustomer()
{

    cout << "Enter the UserID of Customer :-->" << endl;
    cin >> AccountID;

    for (int i = 0; i < CustomerCount; i++)
    {
        if (AccountID == CustomerDetails[i].UserID)
        {
            cout << "Customer Information " << i + 1 << endl;
            cout << "Customer Full Name :--> " << CustomerDetails[i].CustomerFirstName << " " << CustomerDetails[i].CustomerSecondName << endl;
            cout << "Customer's User ID :--> " << CustomerDetails[i].UserID << endl;
            cout << "Customer Full Address :--> " << CustomerDetails[i].CustomerAddress << endl;
            cout << "Customer Contact Details :--> " << CustomerDetails[i].UserContactdetails << endl;
            cout << "Customer Current Balance :--> " << CustomerDetails[i].CurrentAmount << endl;

            break;
        }

        if (i == CustomerCount - 1)
        {
            cout << " !! Worng Details Entered !! " << endl;
            cout << " OR " << endl;
            cout << " No User Found " << endl;
        }
    }
}
void BankingSystem::Transaction()
{
    int cash;
    char choice;

    cout << "Enter id of student those data you want to transaction" << endl;
    cin >> AccountID;

    for (int i = 0; i < CustomerCount; i++)
    {
        if (AccountID == CustomerDetails[i].UserID)
        {
            cout << "Customer Full Name :--> " << CustomerDetails[i].CustomerFirstName << " " << CustomerDetails[i].CustomerSecondName << endl;
            cout << "Customer Full Address :--> " << CustomerDetails[i].CustomerAddress << endl;
            cout << "Customer Contact Details :--> " << CustomerDetails[i].UserContactdetails << endl;
            cout << "Customer Current Balance :--> " << CustomerDetails[i].CurrentAmount << endl;

            cout << "Press 1 For deposit :-> " << endl;
            cout << "Press 2 For withdraw :-> " << endl;

            choice = getch();

            switch (choice)
            {
            case '1':

                cout << "How much cash you want to deposit??" << endl;
                cin >> cash;

                CustomerDetails[i].CurrentAmount += cash;
                cout << "Your Current Balance is :--> " << CustomerDetails[i].CurrentAmount << endl;
                break;

            case '2':
                back:
                cout << "How much cash you want to withdraw??" << endl;

                cin >> cash;

                if (cash > CustomerDetails[i].CurrentAmount)
                {
                    cout << "Your existing cash is just " << CustomerDetails[i].CurrentAmount << endl;
                    Sleep(3000);
                    goto back;
                }

                CustomerDetails[i].CurrentAmount -= cash;
                cout << "Your new cash is " << CustomerDetails[i].CurrentAmount << endl;
                break;

            default:
                cout << "Invalid input" << endl;
                break;
            }
            break;
        }

        if (i == CustomerCount - 1)
        {
            cout << "No such record found" << endl;
        }
    }
}

void BankingSystem::DeleteCustomer()
{

    char choice;

    cout << "Press -> 1 For Remove Specific Record :-> " << endl;
    cout << "Press -> 2 For Delete full CustomerDetails :-> " << endl;
    choice = getch();

    switch (choice)
    {

    case '1':

        cout << "Enter id of student those data you want to remove" << endl;
        cin >> AccountID;
        for (int i = 0; i < CustomerCount; i++)
        {
            if (AccountID == CustomerDetails[i].UserID)
            {
                for (int j = i; j < CustomerCount; j++)
                {
                    CustomerDetails[j].CustomerFirstName = CustomerDetails[j + 1].CustomerFirstName;

                    CustomerDetails[j].CustomerSecondName = CustomerDetails[j + 1].CustomerSecondName;

                    CustomerDetails[j].UserID = CustomerDetails[j + 1].UserID;

                    CustomerDetails[j].CustomerAddress = CustomerDetails[j + 1].CustomerAddress;

                    CustomerDetails[j].UserContactdetails = CustomerDetails[j + 1].UserContactdetails;

                    CustomerDetails[j].CurrentAmount = CustomerDetails[j + 1].CurrentAmount;

                    CustomerCount--;

                    cout << "Your required data is deleted" << endl;

                    break;
                }
            }

            if (i = CustomerCount - 1)
            {
                cout << "No such record found" << endl;
            }
        }
        break;

    case '2':

        CustomerCount = 0;
        cout << "All record is deleted" << endl;
        break;

    default:
        cout << "Invalid Input" << endl;
        break;
    }
}/*DOCS*/
