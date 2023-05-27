// LIBRARIES USED IN APPLICATION:
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

// VARIABLES OF APPLICATION:
string userNames[100];
string passwords[100];
string role[100];
string stock[100];
string items;
string brand;
string userName;
string password;
string Role;
int i;
int userCount = 0;
int index = 0;

// PROTOTYPES OF FUNCTIONS USED IN APPLICATION:
bool signIn(string userName, string password);
bool isValidUsername(string userName);
void signUpArray(string userName, string password, string Role);
void storeInFile(string userName, string password, string Role);
void login();
void printHeader();
int takeChoice();
void viewUsers();
void readDataFromFile();
bool Admin();
bool Customer();
void storeStockInfo();
void readStock();
void changeId();
void readChangedId();
void addBrand();
void readaddedBrand();
void admin();
void customer();

// MAIN BODY:
main()
{
    system("cls");
    printHeader();
    readDataFromFile();
    login();
}

// HEADER FUNCTION:
void printHeader()
{
    cout << "************************************" << endl;
    cout << "* MOBILE SHOP MANAGEMENT SYSTEM    *" << endl;
    cout << "************************************" << endl;
    cout << "" << endl;
    cout << "MAIN MENU" << endl;
    cout << "------------------------------------" << endl;
}

// SIGN IN FUNCTION:
bool signIn(string userName, string password)
{
    bool flag = false;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (userNames[idx] == userName && passwords[idx] == password)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

// CHECHING USERNAME FUNCTION:
bool isValidUsername(string userName)
{
    bool flag = true;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (userNames[idx] == userName)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

// SIGN UP FUNCTION:
void signUpArray(string userName, string password, string Role)
{
    userNames[userCount] = userName;
    passwords[userCount] = password;
    role[userCount] = Role;
    userCount++;
}

// STORING DATA OF USERS IN FILE:
void storeInFile(string userName, string password, string Role)
{
    fstream file;
    file.open("users.txt", ios::app);
    file << userName << endl;
    file << password << endl;
    file << Role << endl;
    file.close();
}

// TAKING CHOICE FUNCTION:
int takeChoice()
{
    int choice;
    cout << "1. SignUp User" << endl;
    cout << "2. SignIn User" << endl;
    cout << "3. View Users" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice >  ";
    cin >> choice;
    return choice;
}

// VIEW USERS STATUS FUNCTION:
void viewUsers()
{
    cout << "Usernames"
         << "\t\t"
         << "Passwords"
         << "\t\t"
         << "Roles" << endl;

    for (int idx = 0; idx < userCount; idx++)
    {
        cout << userNames[idx] << "\t\t\t" << passwords[idx] << "\t\t\t" << role[idx] << endl;
    }
    cout << endl;
}

// READING USERS DATA FROM FILE:
void readDataFromFile()
{
    string username;
    string password;
    string Role;
    fstream file;
    file.open("users.txt", ios::in);
    while (file.eof())
    {
        userNames[userCount] = username;
        passwords[userCount] = password;
        role[userCount] = Role;
        userCount++;
    }
    file.close();
}

// LOGIN FUNCTION:
void login()
{
    bool decision;

    int choice = 4;
    for (int x = 0; x != 4; x++)
    {
        choice = takeChoice();
        if (choice == 1)
        {
            system("cls");
            printHeader();
            cout << endl;
            cout << "Enter your username: ";
            cin >> userName;
            cout << "Enter your password: ";
            cin >> password;
            cout << "Enter your role (admin or customer):";
            cin >> Role;
            decision = isValidUsername(userName);
            if (decision == true)
            {
                signUpArray(userName, password, Role);
                storeInFile(userName, password, Role);
                cout << "User Created Successfully" << endl;
            }
            else
            {
                cout << "Username already exists" << endl;
            }
        }
        if (choice == 2)
        {
            system("cls");
            printHeader();
            cout << endl;
            cout << "Enter your username: ";
            cin >> userName;
            cout << "Enter your password: ";
            cin >> password;
            decision = signIn(userName, password);
            if (decision == true)
            {
                cout << "Login Successfully" << endl;
                if (Role == "admin")
                {
                    admin();
                }
                else if (Role == "customer")
                {
                    customer();
                }
            }
            else
            {
                cout << "Invalid Credentials" << endl;
                cout << "SIGN UP FIRST!!" << endl;
            }
        }
        if (choice == 3)
        {
            system("cls");
            printHeader();
            cout << endl;
            viewUsers();
        }
    }
}

// ADMIN MENU FUNCTION:
bool Admin()
{
    int option;
    cout << "1.add new stock" << endl;
    cout << "2.change username and password " << endl;
    cout << "3.selling a brand new mobile" << endl;
    cout << "4.buying an old or used phone" << endl;
    cout << "5.range of customer" << endl;
    cout << "6.the payment method" << endl;
    cout << "7.update the management system" << endl;
    cout << "8.overview  daily sales" << endl;
    cout << "9.delete any order or purchase" << endl;
    cout << "10.deltete the customers account" << endl;
    cout << "11.check status:" << endl;
    cout << "12.exit option" << endl;
    cout << "enter any option:";
    cin >> option;
    if (option == 1)
    {
        int count = 100;
        system("cls");
        printHeader();
        cout << "NEW STOCK LIST:" << endl;
        cout << "------------------------------------" << endl;
        cout << "enter the stock you want to add in the list:" << endl;
        for (i = 0; i < 1; i++)
        {
            cin >> stock[i];
            items = stock[i];
        }
        storeStockInfo();
        cout << "YOUR ITEM IS ADDED TO LIST SUCCESSFULLY!!" << endl;
        cout << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "ADMIN MENU:" << endl;
        Admin();
    }
    if (option == 2)
    {
        system("cls");
        printHeader();
        cout << "UPDATE ID PAGE:" << endl;
        cout << "------------------------------------" << endl;
        string name;
        string Password;
        string userName;
        string Role;
        string password;
        cout << "enter your old username:" << endl;
        cin >> name;
        cout << "enter your old password:" << endl;
        cin >> Password;
        cout << "enter your new username:" << endl;
        cin >> userNames[userCount];
        cout << "enter your new password:" << endl;
        cin >> passwords[userCount];

        cout << "your updated username is:"
             << "\t" << userNames[userCount] << endl;
        cout << "your  updated password is:"
             << "\t" << passwords[userCount] << endl;
        changeId();
        userCount++;
        cout << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "MAIN MENU:" << endl;
        login();
    }
    if (option == 3)
    {
        system("cls");
        printHeader();
        int option;
        cout << "BRAND NEW PHONES LIST:" << endl;
        cout << "------------------------------------" << endl;
        cout << "1.IPHONE" << endl;
        cout << "2.SAMSUNG" << endl;
        cout << "3.NOKIA" << endl;
        cout << "4.INFINIX" << endl;
        cout << "5.HUAWEI" << endl;
        cout << "6.TECHNO" << endl;
        cout << "7.HP" << endl;
        cout << "8.REALME" << endl;
        cout << "select any option:";
        cin >> option;
        if (option == 1)
        {
            system("cls");
            printHeader();
            cout << "IPHONE MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.IPHONE x" << endl;
            cout << "2.IPHONE 11" << endl;
            cout << "3.IPHONE 12" << endl;
            cout << "4.IPHONE 13" << endl;
            cout << "5.IPHONE 14" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
            }
        }
        if (option == 2)
        {
            system("cls");
            printHeader();
            cout << "SAMSUNG MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.S10 PLUS" << endl;
            cout << "2.S20 PLUS" << endl;
            cout << "3.S21 PLUS" << endl;
            cout << "4.S22 PLUS" << endl;
            cout << "5.S23 PLUS" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
            }
        }
        if (option == 3)
        {
            system("cls");
            printHeader();
            cout << "NOKIA MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.3310" << endl;
            cout << "2.110" << endl;
            cout << "3.C12" << endl;
            cout << "4.2660 FLIP" << endl;
            cout << "5.G60" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
            }
        }
        if (option == 4)
        {
            system("cls");
            printHeader();
            cout << "INFINIX MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HOT 9 PLAY" << endl;
            cout << "2.HOT 10 PLAY" << endl;
            cout << "3.INFINIX ZERO" << endl;
            cout << "4.INFINIX 8" << endl;
            cout << "5.INFINIX 10" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
            }
        }
        if (option == 5)
        {
            system("cls");
            printHeader();
            cout << "HUAWEI MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HUAWEI C12" << endl;
            cout << "2.HUAWEI C13" << endl;
            cout << "3.HUAWEI C14" << endl;
            cout << "4.HUAWEI C15" << endl;
            cout << "5.HUAWEI C16" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
            }
        }
        if (option == 6)
        {
            system("cls");
            printHeader();
            cout << "TECHNO MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.TECHNO SPARK 8" << endl;
            cout << "2.TECHNO SPARK 9" << endl;
            cout << "3.TECHNO SPARK 10" << endl;
            cout << "4.TECHNO SPARK 11" << endl;
            cout << "5.TECHNO SPARK 12" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
            }
        }
        if (option == 7)
        {
            system("cls");
            printHeader();
            cout << "HP MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HP G6" << endl;
            cout << "2.HP G7" << endl;
            cout << "3.HP G8" << endl;
            cout << "4.HP G9" << endl;
            cout << "5.HP G10" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
            }
        }
        if (option == 8)
        {
            system("cls");
            printHeader();
            cout << "REALME MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.REALME R21" << endl;
            cout << "2.REALME R22" << endl;
            cout << "3.REALME R23" << endl;
            cout << "4.REALME R24" << endl;
            cout << "5.REALME R25" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
            }
        }

        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "ADMIN MENU:" << endl;
        Admin();
    }
    if (option == 4)
    {
        system("cls");
        printHeader();
        int option;
        cout << "OLD PHONES LIST:" << endl;
        cout << "------------------------------------" << endl;
        cout << "1.IPHONE" << endl;
        cout << "2.SAMSUNG" << endl;
        cout << "3.NOKIA" << endl;
        cout << "4.INFINIX" << endl;
        cout << "5.HUAWEI" << endl;
        cout << "6.TECHNO" << endl;
        cout << "7.HP" << endl;
        cout << "8.REALME" << endl;
        cout << "select any option:";
        cin >> option;
        if (option == 1)
        {
            system("cls");
            printHeader();
            cout << "IPHONE MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.IPHONE x" << endl;
            cout << "2.IPHONE 11" << endl;
            cout << "3.IPHONE 12" << endl;
            cout << "4.IPHONE 13" << endl;
            cout << "5.IPHONE 14" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE SOLD IT SUCCESSFULLY " << endl;
                cout << " " << endl;
                cout << "YOUR MONEY PKR 80,000 HAS SEND TO YOU IN YOUR ACCOUNT!  " << endl;
                cout << endl;
                cout << "THANKS FOR COMING!!!" << endl;
                cout << endl;
            }
        }
        if (option == 2)
        {
            system("cls");
            printHeader();
            cout << "SAMSUNG MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.S10 PLUS" << endl;
            cout << "2.S20 PLUS" << endl;
            cout << "3.S21 PLUS" << endl;
            cout << "4.S22 PLUS" << endl;
            cout << "5.S23 PLUS" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE SOLD IT SUCCESSFULLY " << endl;
                cout << " " << endl;
                cout << "YOUR MONEY PKR 70,000 HAS SEND TO YOU IN YOUR ACCOUNT!  " << endl;
                cout << endl;
                cout << "THANKS FOR COMING!!!" << endl;
                cout << endl;
            }
        }
        if (option == 3)
        {
            system("cls");
            printHeader();
            cout << "NOKIA MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.3310" << endl;
            cout << "2.110" << endl;
            cout << "3.C12" << endl;
            cout << "4.2660 FLIP" << endl;
            cout << "5.G60" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE SOLD IT SUCCESSFULLY " << endl;
                cout << " " << endl;
                cout << "YOUR MONEY PKR 60,000 HAS SEND TO YOU IN YOUR ACCOUNT!  " << endl;
                cout << endl;
                cout << "THANKS FOR COMING!!!" << endl;
                cout << endl;
            }
        }
        if (option == 4)
        {
            system("cls");
            printHeader();
            cout << "INFINIX MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HOT 9 PLAY" << endl;
            cout << "2.HOT 10 PLAY" << endl;
            cout << "3.INFINIX ZERO" << endl;
            cout << "4.INFINIX 8" << endl;
            cout << "5.INFINIX 10" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE SOLD IT SUCCESSFULLY " << endl;
                cout << " " << endl;
                cout << "YOUR MONEY PKR 50,000 HAS SEND TO YOU IN YOUR ACCOUNT!  " << endl;
                cout << endl;
                cout << "THANKS FOR COMING!!!" << endl;
                cout << endl;
            }
        }
        if (option == 5)
        {
            system("cls");
            printHeader();
            cout << "HUAWEI MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HUAWEI C12" << endl;
            cout << "2.HUAWEI C13" << endl;
            cout << "3.HUAWEI C14" << endl;
            cout << "4.HUAWEI C15" << endl;
            cout << "5.HUAWEI C16" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE SOLD IT SUCCESSFULLY " << endl;
                cout << " " << endl;
                cout << "YOUR MONEY PKR 40,000 HAS SEND TO YOU IN YOUR ACCOUNT!  " << endl;
                cout << endl;
                cout << "THANKS FOR COMING!!!" << endl;
                cout << endl;
            }
        }
        if (option == 6)
        {
            system("cls");
            printHeader();
            cout << "TECHNO MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.TECHNO SPARK 8" << endl;
            cout << "2.TECHNO SPARK 9" << endl;
            cout << "3.TECHNO SPARK 10" << endl;
            cout << "4.TECHNO SPARK 11" << endl;
            cout << "5.TECHNO SPARK 12" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE SOLD IT SUCCESSFULLY " << endl;
                cout << " " << endl;
                cout << "YOUR MONEY PKR 30,000 HAS SEND TO YOU IN YOUR ACCOUNT!  " << endl;
                cout << endl;
                cout << "THANKS FOR COMING!!!" << endl;
                cout << endl;
            }
        }
        if (option == 7)
        {
            system("cls");
            printHeader();
            cout << "HP MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HP G6" << endl;
            cout << "2.HP G7" << endl;
            cout << "3.HP G8" << endl;
            cout << "4.HP G9" << endl;
            cout << "5.HP G10" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE SOLD IT SUCCESSFULLY " << endl;
                cout << " " << endl;
                cout << "YOUR MONEY PKR 20,000 HAS SEND TO YOU IN YOUR ACCOUNT!  " << endl;
                cout << endl;
                cout << "THANKS FOR COMING!!!" << endl;
                cout << endl;
            }
        }
        if (option == 8)
        {
            system("cls");
            printHeader();
            cout << "REALME MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.REALME R21" << endl;
            cout << "2.REALME R22" << endl;
            cout << "3.REALME R23" << endl;
            cout << "4.REALME R24" << endl;
            cout << "5.REALME R25" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE SOLD IT SUCCESSFULLY " << endl;
                cout << " " << endl;
                cout << "YOUR MONEY PKR 10,000 HAS SEND TO YOU IN YOUR ACCOUNT!  " << endl;
                cout << endl;
                cout << "THANKS FOR COMING!!!" << endl;
                cout << endl;
            }
        }

        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "ADMIN MENU:" << endl;
        Admin();
    }
    if (option == 5)
    {
        system("cls");
        printHeader();
        cout << "RANGE OF CUSTOMER:" << endl;
        cout << "------------------------------------" << endl;
        int range;
        cout << "enter your range of money:";
        cin >> range;
        if (range < 50000)
        {
            system("cls");
            printHeader();
            cout << "RANGE OF CUSTOMER:" << endl;
            cout << "------------------------------------" << endl;
            cout << "LIST OF PHONES UNDER THIS RANGE:" << endl;
            cout << "1.HUAWEI" << endl;
            cout << "2.TECHNO" << endl;
            cout << "3.HP" << endl;
            cout << "4.REALME" << endl;
            cout << endl;
            cout << "YOU CAN BUY ANY THESE PHONES IN YOUR RANGE" << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "ADMIN MENU:" << endl;
            Admin();
        }
        if (range >= 50000)
        {
            system("cls");
            printHeader();
            cout << "RANGE OF CUSTOMER:" << endl;
            cout << "------------------------------------" << endl;
            cout << "LIST OF PHONES UNDER THIS RANGE:" << endl;
            cout << "1.IPHONE" << endl;
            cout << "2.SAMSUNG" << endl;
            cout << "3.NOKIA" << endl;
            cout << "4.INFINIX" << endl;
            cout << endl;
            cout << "YOU CAN BUY ANY THESE PHONES IN YOUR RANGE" << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "ADMIN MENU:" << endl;
            Admin();
        }
    }
    if (option == 6)
    {
        system("cls");
        printHeader();
        cout << "PAYMENT METHOD" << endl;
        cout << "------------------------------------" << endl;
        cout << "HOW WOULD YOU WANT TO PAY (DEBIT OR CASH): ";
        string method;
        cin >> method;
        if (method == "debit")
        {
            cout << "enter your debit card number";
            int card;
            cin >> card;
        }
        cout << "ENTER YOUR TOTAL AMOUNT OF BILL:" << endl;
        int bill;
        cin >> bill;
        cout << "YOUR BILL PKR"
             << "\t" << bill << "\t"
             << "has been generaterd:" << endl;
        cout << endl;
        cout << "THANKS FOR COMING STAY BLESSED!!!!" << endl;
        cout << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "ADMIN MENU:" << endl;
        Admin();
    }

    if (option == 7)
    {
        system("cls");
        printHeader();
        cout << "UPDATE SYSTEM" << endl;
        cout << "------------------------------------" << endl;
        cout << "1.ADD NEW BRAND OF PHONES" << endl;
        cout << "2.ADD REPAIRING OPTION" << endl;
        cout << "3.ADD CUSTUMERS REVIEW" << endl;
        cout << "enter any  option:";
        int option;
        cin >> option;
        if (option == 1)
        {
            system("cls");
            printHeader();
            cout << "UPDATE SYSTEM" << endl;
            cout << "------------------------------------" << endl;
            cout << "NEW BRAND ADDITION" << endl;
            cout << "enter brand name:";
            cin >> brand;
            addBrand();
            cout << "YOUR NEW BRAND IS ADDED TO LIST SUCCESSFULLY" << endl;
        }
        if (option == 2)
        {
            system("cls");
            printHeader();
            cout << "UPDATE SYSTEM" << endl;
            cout << "------------------------------------" << endl;
            string brand;
            string model;
            string querry;
            cout << "REPAIRING OPTION " << endl;
            cout << "enter the mobile brand :";
            cin >> brand;
            cout << "enter the model:";
            cin >> model;
            cout << "enter your issue: ";
            cin.ignore();
            getline(cin, querry);
            cout << endl;
            cout << "YOUR REQUEST HAS BEEN ACCEPTED! RECIEVE IT AFTER TWO DAYS " << endl;
            cout << endl;
            cout << "THANK YOU!" << endl;
        }
        if (option == 3)
        {
            system("cls");
            printHeader();
            cout << "UPDATE SYSTEM" << endl;
            cout << "------------------------------------" << endl;
            cout << "CUSTOMER REVIEWS" << endl;
            string review;
            cout << "enter your reviews here" << endl;
            cin.ignore();
            getline(cin, review);
            cout << endl;
            cout << "THANKS FOR YOU REMARKS:" << endl;
            cout << endl;
        }
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "ADMIN MENU:" << endl;
        Admin();
    }
    if (option == 8)
    {
        system("cls");
        printHeader();
        cout << "OVERVIEW SALES" << endl;
        cout << "------------------------------------" << endl;
        int phones;
        cout << "1.enter the total number of phone you sold today:";
        cin >> phones;
        int price;
        string phone;
        int total = 0;
        for (int x = 0; x < phones; x++)
        {
            cout << "enter the phone name: ";
            cin >> phone;
            cout << "enter the price of phone: ";
            cin >> price;
            total = total + price;
        }
        cout << endl;
        cout << "your total sale of today=" << total << endl;
        cout << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "ADMIN MENU:" << endl;
        Admin();
    }
    if (option == 9)
    {
        system("cls");
        printHeader();
        cout << "DELETE ORDER" << endl;
        cout << "------------------------------------" << endl;
        string order;
        string model;
        string reason;
        string confirm;
        cout << "enter the product you want to cencel(mobile name): ";
        cin >> order;
        cout << "enter the model: ";
        cin >> model;
        cout << "enter the reason:" << endl;
        cin.ignore();
        getline(cin, reason);
        cout << "confirm before deleting(if yes press'y' ifno press'n'): ";
        cin >> confirm;
        cout << endl;
        cout << "YOUR ORDER HAS BEEN CANCELLED SUCCESSFULLY!!" << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "ADMIN MENU:" << endl;
        Admin();
    }
    if (option == 10)
    {
        system("cls");
        printHeader();
        cout << "DELETE CUSTOMER ACCOUNT:" << endl;
        cout << "------------------------------------" << endl;
        string name;
        int password;
        string confirm;
        int count = 0;
        cout << "enter username:" << endl;
        cin >> name;
        cout << "enter password:" << endl;
        cin >> password;
        cout << "confirm before deleting(if yes press'y' ifno press'n'): ";
        cin >> confirm;
        cout << endl;
        cout << "THIS ACCOUNT HAS BEEN DELETED SUCCESSFULLY!!" << endl;
        cout << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "ADMIN MENU:" << endl;
        Admin();
    }
    if (option == 11)
    {
        system("cls");
        printHeader();
        cout << "YOUR STATUS:" << endl;
        cout << "------------------------------------" << endl;
        cout << "USERNAME:"
             << "\t" << userName << endl;
        cout << "PASSWORD:"
             << "\t" << password << endl;
        cout << "ROLE:"
             << "\t"
             << "\t " << Role << endl;
        cout << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "ADMIN MENU:" << endl;
        Admin();
    }
    if (option == 12)
    {
        system("cls");
        printHeader();
        login();
    }
}

// STORING NEW STOCK IN FILE FUNCTION:
void storeStockInfo()
{

    fstream file;
    file.open("info.txt", ios::app);
    file << items << endl;
    file.close();
}

// READING STOCK DETAILS FROM FILE:
void readStock()
{
    fstream file;
    file.open("info.txt", ios::in);
    while (!(file.eof()))
    {
        file >> items;
    }
    file.close();
}

// CHANGING ACCOUNT DETAILS STORED IN FILE:
void changeId()
{
    fstream file;
    file.open("idinfo.txt", ios::out);
    file << userNames[userCount] << endl;
    file << passwords[userCount] << endl;
    file.close();
}

// READING CHANGED ACCOUNT DETAILS FROM FILE:
void readChangedId()
{

    fstream file;
    file.open("idinfo.txt", ios::in);
    while (!(file.eof()))
    {
        file >> userNames[userCount];
        file >> passwords[userCount];
    }
    file.close();
}

// ADDITION OF NEW BRAND OF PHONE STORED IN FILE:
void addBrand()
{
    fstream file;
    file.open("newbrand.txt", ios::app);
    file << brand << endl;
    file.close();
}

// READING ADDITION OF BRAND DETAILS FROM FILE:
void readaddedBrand()
{
    fstream file;
    file.open("newbrand.txt", ios::in);
    file >> brand;
    file.close();
}

// CUSTOMER MENU FUNCTION:
bool Customer()
{
    int option;
    cout << "1.change password or username" << endl;
    cout << "2.different mobile phones brands" << endl;
    cout << "3.different models of different phones" << endl;
    cout << "4.buying phones" << endl;
    cout << "5.specification of mobile phones such as color, memory, battery health, processor etc" << endl;
    cout << "6.facility of exchange in case of any mishap" << endl;
    cout << "7.facility of delivery" << endl;
    cout << "8.phone accessories" << endl;
    cout << "9.facility of money saving wallet provided on portal" << endl;
    cout << "10.delete order" << endl;
    cout << "11.check status" << endl;
    cout << "12.exit option" << endl;
    cout << "enter any option:";
    cin >> option;
    if (option == 1)
    {
        system("cls");
        printHeader();
        cout << "UPDATE ID PAGE:" << endl;
        cout << "------------------------------------" << endl;
        string name;
        int Password;
        string userName;
        string password;
        cout << "enter your old username:" << endl;
        cin >> name;
        cout << "enter your old password:" << endl;
        cin >> password;
        cout << "enter your new username:" << endl;
        cin >> userNames[userCount];
        cout << "enter your new password:" << endl;
        cin >> passwords[userCount];

        cout << "your updated username is:"
             << "\t" << userNames[userCount] << endl;
        cout << "your  updated password is:"
             << "\t" << passwords[userCount] << endl;
        changeId();
        userCount++;
        cout << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "MAIN MENU:" << endl;
        login();
    }
    if (option == 2)
    {
        system("cls");
        printHeader();

        cout << "PHONES LIST:" << endl;
        cout << "------------------------------------" << endl;
        cout << "1.IPHONE" << endl;
        cout << "2.SAMSUNG" << endl;
        cout << "3.NOKIA" << endl;
        cout << "4.INFINIX" << endl;
        cout << "5.HUAWEI" << endl;
        cout << "6.TECHNO" << endl;
        cout << "7.HP" << endl;
        cout << "8.REALME" << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "CUSTOMER MENU:" << endl;
        Customer();
    }
    if (option == 3)
    {
        system("cls");
        printHeader();
        cout << "PHONES LIST:" << endl;
        cout << "------------------------------------" << endl;
        cout << "1.IPHONE" << endl;
        cout << "2.SAMSUNG" << endl;
        cout << "3.NOKIA" << endl;
        cout << "4.INFINIX" << endl;
        cout << "5.HUAWEI" << endl;
        cout << "6.TECHNO" << endl;
        cout << "7.HP" << endl;
        cout << "8.REALME" << endl;
        int option;
        cout << "select any option:";
        cin >> option;
        if (option == 1)
        {
            system("cls");
            printHeader();
            cout << "IPHONE MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.IPHONE x" << endl;
            cout << "2.IPHONE 11" << endl;
            cout << "3.IPHONE 12" << endl;
            cout << "4.IPHONE 13" << endl;
            cout << "5.IPHONE 14" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 2)
        {
            system("cls");
            printHeader();

            cout << "SAMSUNG MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.S10 PLUS" << endl;
            cout << "2.S20 PLUS" << endl;
            cout << "3.S21 PLUS" << endl;
            cout << "4.S22 PLUS" << endl;
            cout << "5.S23 PLUS" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 3)
        {
            system("cls");
            printHeader();
            cout << "NOKIA MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.3310" << endl;
            cout << "2.110" << endl;
            cout << "3.C12" << endl;
            cout << "4.2660 FLIP" << endl;
            cout << "5.G60" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 4)
        {
            system("cls");
            printHeader();

            cout << "INFINIX MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HOT 9 PLAY" << endl;
            cout << "2.HOT 10 PLAY" << endl;
            cout << "3.INFINIX ZERO" << endl;
            cout << "4.INFINIX 8" << endl;
            cout << "5.INFINIX 10" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 5)
        {
            system("cls");
            printHeader();
            cout << "HUAWEI MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HUAWEI C12" << endl;
            cout << "2.HUAWEI C13" << endl;
            cout << "3.HUAWEI C14" << endl;
            cout << "4.HUAWEI C15" << endl;
            cout << "5.HUAWEI C16" << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 6)
        {
            system("cls");
            printHeader();
            cout << "TECHNO MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.TECHNO SPARK 8" << endl;
            cout << "2.TECHNO SPARK 9" << endl;
            cout << "3.TECHNO SPARK 10" << endl;
            cout << "4.TECHNO SPARK 11" << endl;
            cout << "5.TECHNO SPARK 12" << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 7)
        {
            system("cls");
            printHeader();
            cout << "HP MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HP G6" << endl;
            cout << "2.HP G7" << endl;
            cout << "3.HP G8" << endl;
            cout << "4.HP G9" << endl;
            cout << "5.HP G10" << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 8)
        {
            system("cls");
            printHeader();
            cout << "REALME MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.REALME R21" << endl;
            cout << "2.REALME R22" << endl;
            cout << "3.REALME R23" << endl;
            cout << "4.REALME R24" << endl;
            cout << "5.REALME R25" << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
    }
    if (option == 4)
    {
        system("cls");
        printHeader();
        int option;
        cout << "BRAND NEW PHONES LIST:" << endl;
        cout << "------------------------------------" << endl;
        cout << "1.IPHONE" << endl;
        cout << "2.SAMSUNG" << endl;
        cout << "3.NOKIA" << endl;
        cout << "4.INFINIX" << endl;
        cout << "5.HUAWEI" << endl;
        cout << "6.TECHNO" << endl;
        cout << "7.HP" << endl;
        cout << "8.REALME" << endl;
        cout << "select any option:";
        cin >> option;
        if (option == 1)
        {
            system("cls");
            printHeader();
            cout << "IPHONE MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.IPHONE x" << endl;
            cout << "2.IPHONE 11" << endl;
            cout << "3.IPHONE 12" << endl;
            cout << "4.IPHONE 13" << endl;
            cout << "5.IPHONE 14" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
                cout << "YOUR BILL IS PKR 80,000" << endl;
            }
        }
        if (option == 2)
        {
            system("cls");
            printHeader();
            cout << "SAMSUNG MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.S10 PLUS" << endl;
            cout << "2.S20 PLUS" << endl;
            cout << "3.S21 PLUS" << endl;
            cout << "4.S22 PLUS" << endl;
            cout << "5.S23 PLUS" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
                cout << "YOUR BILL IS PKR 70,000" << endl;
            }
        }
        if (option == 3)
        {
            system("cls");
            printHeader();
            cout << "NOKIA MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.3310" << endl;
            cout << "2.110" << endl;
            cout << "3.C12" << endl;
            cout << "4.2660 FLIP" << endl;
            cout << "5.G60" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
                cout << "YOUR BILL IS PKR 60,000" << endl;
            }
        }
        if (option == 4)
        {
            system("cls");
            printHeader();
            cout << "INFINIX MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HOT 9 PLAY" << endl;
            cout << "2.HOT 10 PLAY" << endl;
            cout << "3.INFINIX ZERO" << endl;
            cout << "4.INFINIX 8" << endl;
            cout << "5.INFINIX 10" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
                cout << "YOUR BILL IS PKR 50,000" << endl;
            }
        }
        if (option == 5)
        {
            system("cls");
            printHeader();
            cout << "HUAWEI MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HUAWEI C12" << endl;
            cout << "2.HUAWEI C13" << endl;
            cout << "3.HUAWEI C14" << endl;
            cout << "4.HUAWEI C15" << endl;
            cout << "5.HUAWEI C16" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
                cout << "YOUR BILL IS PKR 40,000" << endl;
            }
        }
        if (option == 6)
        {
            system("cls");
            printHeader();
            cout << "TECHNO MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.TECHNO SPARK 8" << endl;
            cout << "2.TECHNO SPARK 9" << endl;
            cout << "3.TECHNO SPARK 10" << endl;
            cout << "4.TECHNO SPARK 11" << endl;
            cout << "5.TECHNO SPARK 12" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
                cout << "YOUR BILL IS PKR 30,000" << endl;
            }
        }
        if (option == 7)
        {
            system("cls");
            printHeader();
            cout << "HP MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.HP G6" << endl;
            cout << "2.HP G7" << endl;
            cout << "3.HP G8" << endl;
            cout << "4.HP G9" << endl;
            cout << "5.HP G10" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
                cout << "YOUR BILL IS PKR 25,000" << endl;
            }
        }
        if (option == 8)
        {
            system("cls");
            printHeader();
            cout << "REALME MODELS LIST:" << endl;
            cout << "------------------------------------" << endl;
            cout << "1.REALME R21" << endl;
            cout << "2.REALME R22" << endl;
            cout << "3.REALME R23" << endl;
            cout << "4.REALME R24" << endl;
            cout << "5.REALME R25" << endl;
            int option;
            cout << "select  any option:";
            cin >> option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
            {
                cout << "CONGRATULATIONS!! YOU HAVE BOUGHT IT SUCCESSFULLY " << endl;
                cout << "YOUR BILL IS PKR 20,000" << endl;
            }
        }

        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "CUSTOMER MENU:" << endl;
        Customer();
    }
    if (option == 5)
    {
        system("cls");
        printHeader();
        cout << "SPECIFICATION OF PHONES MENU:" << endl;
        cout << "------------------------------------" << endl;
        cout << "PHONES LIST:" << endl;
        cout << "------------------------------------" << endl;
        cout << "1.IPHONE" << endl;
        cout << "2.SAMSUNG" << endl;
        cout << "3.NOKIA" << endl;
        cout << "4.INFINIX" << endl;
        cout << "5.HUAWEI" << endl;
        cout << "6.TECHNO" << endl;
        cout << "7.HP" << endl;
        cout << "8.REALME" << endl;
        int option;
        cout << "select any option:";
        cin >> option;
        if (option == 1)
        {
            system("cls");
            printHeader();
            cout << "SPECIFICATION OF PHONES MENU:" << endl;
            cout << "------------------------------------" << endl;
            cout << "IPHONES SPECIFICATION:" << endl;
            cout << "------------------------------------" << endl;
            cout << "AVAILABLE COLOURS:" << endl;
            cout << "1.BLACK" << endl;
            cout << "2.GREY" << endl;
            cout << "3.BLUE" << endl;
            cout << "4.WHITE" << endl;
            cout << "5.RED" << endl;
            cout << endl;
            cout << "MEMORY OPTION:" << endl;
            cout << "1.64 GB" << endl;
            cout << "2.128 GB" << endl;
            cout << "3.256 GB" << endl;
            cout << "4. 1  TB" << endl;
            cout << endl;
            cout << "PROCESSOR: "
                 << "\t"
                 << "IOS SYSTEM" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 2)
        {
            system("cls");
            printHeader();
            cout << "SPECIFICATION OF PHONES MENU:" << endl;
            cout << "------------------------------------" << endl;
            cout << "SAMSUNG SPECIFICATION:" << endl;
            cout << "------------------------------------" << endl;
            cout << "AVAILABLE COLOURS:" << endl;
            cout << "1.BLACK" << endl;
            cout << "2.GREY" << endl;
            cout << "3.BLUE" << endl;
            cout << "4.WHITE" << endl;
            cout << "5.RED" << endl;
            cout << endl;
            cout << "MEMORY OPTION:" << endl;
            cout << "1.32 GB" << endl;
            cout << "2.64 GB" << endl;
            cout << "3.128 GB" << endl;
            cout << "4.256 GB" << endl;
            cout << endl;
            cout << "PROCESSOR: "
                 << "\t"
                 << "ANDROID SYSTEM" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 3)
        {
            system("cls");
            printHeader();
            cout << "SPECIFICATION OF PHONES MENU:" << endl;
            cout << "------------------------------------" << endl;
            cout << "NOKIA SPECIFICATION:" << endl;
            cout << "------------------------------------" << endl;
            cout << "AVAILABLE COLOURS:" << endl;
            cout << "1.BLACK" << endl;
            cout << "2.GREY" << endl;
            cout << "3.BLUE" << endl;
            cout << "4.WHITE" << endl;
            cout << "5.RED" << endl;
            cout << endl;
            cout << "MEMORY OPTION:" << endl;
            cout << "1.32 GB" << endl;
            cout << "2.64 GB" << endl;
            cout << "3.128 GB" << endl;
            cout << "4.256 GB" << endl;
            cout << endl;
            cout << "PROCESSOR: "
                 << "\t"
                 << "ANDROID SYSTEM" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 4)
        {
            system("cls");
            printHeader();
            cout << "SPECIFICATION OF PHONES MENU:" << endl;
            cout << "------------------------------------" << endl;
            cout << "INFINIX SPECIFICATION:" << endl;
            cout << "------------------------------------" << endl;
            cout << "AVAILABLE COLOURS:" << endl;
            cout << "1.BLACK" << endl;
            cout << "2.GREY" << endl;
            cout << "3.BLUE" << endl;
            cout << "4.WHITE" << endl;
            cout << "5.RED" << endl;
            cout << endl;
            cout << "MEMORY OPTION:" << endl;
            cout << "1.32 GB" << endl;
            cout << "2.64 GB" << endl;
            cout << "3.128 GB" << endl;
            cout << "4.256 GB" << endl;
            cout << endl;
            cout << "PROCESSOR: "
                 << "\t"
                 << "ANDROID SYSTEM" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 5)
        {
            system("cls");
            printHeader();
            cout << "SPECIFICATION OF PHONES MENU:" << endl;
            cout << "------------------------------------" << endl;
            cout << "HUAWEI SPECIFICATION:" << endl;
            cout << "------------------------------------" << endl;
            cout << "AVAILABLE COLOURS:" << endl;
            cout << "1.BLACK" << endl;
            cout << "2.GREY" << endl;
            cout << "3.BLUE" << endl;
            cout << "4.WHITE" << endl;
            cout << "5.RED" << endl;
            cout << endl;
            cout << "MEMORY OPTION:" << endl;
            cout << "1.32 GB" << endl;
            cout << "2.64 GB" << endl;
            cout << "3.128 GB" << endl;
            cout << "4.256 GB" << endl;
            cout << endl;
            cout << "PROCESSOR: "
                 << "\t"
                 << "ANDROID SYSTEM" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 6)
        {
            system("cls");
            printHeader();
            cout << "SPECIFICATION OF PHONES MENU:" << endl;
            cout << "------------------------------------" << endl;
            cout << "TECHNO SPECIFICATION:" << endl;
            cout << "------------------------------------" << endl;
            cout << "AVAILABLE COLOURS:" << endl;
            cout << "1.BLACK" << endl;
            cout << "2.GREY" << endl;
            cout << "3.BLUE" << endl;
            cout << "4.WHITE" << endl;
            cout << "5.RED" << endl;
            cout << endl;
            cout << "MEMORY OPTION:" << endl;
            cout << "1.32 GB" << endl;
            cout << "2.64 GB" << endl;
            cout << "3.128 GB" << endl;
            cout << "4.256 GB" << endl;
            cout << endl;
            cout << "PROCESSOR: "
                 << "\t"
                 << "ANDROID SYSTEM" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 7)
        {
            system("cls");
            printHeader();
            cout << "SPECIFICATION OF PHONES MENU:" << endl;
            cout << "------------------------------------" << endl;
            cout << "HP SPECIFICATION:" << endl;
            cout << "------------------------------------" << endl;
            cout << "AVAILABLE COLOURS:" << endl;
            cout << "1.BLACK" << endl;
            cout << "2.GREY" << endl;
            cout << "3.BLUE" << endl;
            cout << "4.WHITE" << endl;
            cout << "5.RED" << endl;
            cout << endl;
            cout << "MEMORY OPTION:" << endl;
            cout << "1.32 GB" << endl;
            cout << "2.64 GB" << endl;
            cout << "3.128 GB" << endl;
            cout << "4.256 GB" << endl;
            cout << endl;
            cout << "PROCESSOR: "
                 << "\t"
                 << "ANDROID SYSTEM" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
        if (option == 8)
        {
            system("cls");
            printHeader();
            cout << "SPECIFICATION OF PHONES MENU:" << endl;
            cout << "------------------------------------" << endl;
            cout << "REALME SPECIFICATION:" << endl;
            cout << "------------------------------------" << endl;
            cout << "AVAILABLE COLOURS:" << endl;
            cout << "1.BLACK" << endl;
            cout << "2.GREY" << endl;
            cout << "3.BLUE" << endl;
            cout << "4.WHITE" << endl;
            cout << "5.RED" << endl;
            cout << endl;
            cout << "MEMORY OPTION:" << endl;
            cout << "1.32 GB" << endl;
            cout << "2.64 GB" << endl;
            cout << "3.128 GB" << endl;
            cout << "4.256 GB" << endl;
            cout << endl;
            cout << "PROCESSOR: "
                 << "\t"
                 << "ANDROID SYSTEM" << endl;
            cout << endl;
            int option1;
            cout << "press 1 to continue..." << endl;
            cin >> option1;
            system("cls");
            printHeader();
            cout << "CUSTOMER MENU:" << endl;
            Customer();
        }
    }
    if (option == 6)
    {
        system("cls");
        printHeader();
        cout << "EXCHANGE MENU:" << endl;
        cout << "------------------------------------" << endl;
        string order;

        int count = 0;
        string newOrder[20];

        cout << "enter your current order:" << endl;
        cin.ignore();
        getline(cin, order);

        cout << "enter your new order:" << endl;
        cin.ignore();
        getline(cin, newOrder[count]);

        cout << "your updated order is:"
             << "\t" << newOrder[count] << endl;

        count++;
        cout << endl;
        cout << "YOUR ORDER HAS  BEEN EXCHANGED SUCCESSFULLY!!" << endl;
        cout << endl;
        cout << "THANKS  FOR COMING STAY BLESSED!!!!" << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "CUSTOMER MENU:" << endl;
        Customer();
    }
    if (option == 7)
    {
        system("cls");
        printHeader();
        cout << "DELIVERY MENU:" << endl;
        cout << "------------------------------------" << endl;
        string address;
        string phone;
        cout << "enter your address:" << endl;
        cin.ignore();
        getline(cin, address);
        cout << "enter your phone number:" << endl;
        cin.ignore();
        getline(cin, phone);
        cout << "if distance is less than 10km charges are pkr Rs 500:" << endl;
        cout << endl;
        cout << "if distance is grater than 10km charges are pkr Rs 1000:" << endl;
        cout << endl;
        cout << "THANKS  FOR ATTAINING OUR SERVICES!!!!" << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "CUSTOMER MENU:" << endl;
        Customer();
    }
    if (option == 8)
    {
        system("cls");
        printHeader();
        cout << "PHONE ACCESSORIES:" << endl;
        cout << "------------------------------------" << endl;
        cout << "1.PHONE CHARGER" << endl;
        cout << "2.HEADPHONES" << endl;
        cout << "3.CONNECTING CABLES" << endl;
        cout << "4.SIM CARD" << endl;
        cout << "5.MEMORY CARD" << endl;
        int option;
        cout << "select any option:";
        cin >> option;
        if (option == 1)
        {
            system("cls");
            printHeader();
            cout << "PHONE ACCESSORIES:" << endl;
            cout << "------------------------------------" << endl;
            cout << "ENTER THE BRAND OF PHONE: ";
            string brand;
            cin.ignore();
            getline(cin, brand);
            cout << "YOU HAVE PURCHASED CHARGER OF"
                 << "\t" << brand << "\t"
                 << "SUCCESSFULLY!" << endl;
            cout << endl;
            cout << "THANKS FOR COMING STAY BLESSED!!!!" << endl;
        }
        if (option == 2)
        {
            system("cls");
            printHeader();
            cout << "PHONE ACCESSORIES:" << endl;
            cout << "------------------------------------" << endl;
            cout << "ENTER THE BRAND OF PHONE: ";
            string brand;
            cin.ignore();
            getline(cin, brand);
            cout << "YOU HAVE PURCHASED HEADPHONES OF"
                 << "\t" << brand << "\t"
                 << "SUCCESSFULLY!" << endl;
            cout << endl;
            cout << "THANKS FOR COMING STAY BLESSED!!!!" << endl;
        }
        if (option == 3)
        {
            system("cls");
            printHeader();
            cout << "PHONE ACCESSORIES:" << endl;
            cout << "------------------------------------" << endl;
            cout << "ENTER THE BRAND OF PHONE: ";
            string brand;
            cin.ignore();
            getline(cin, brand);
            cout << "YOU HAVE PURCHASED CABLES OF"
                 << "\t" << brand << "\t"
                 << "SUCCESSFULLY!" << endl;
            cout << endl;
            cout << "THANKS FOR COMING STAY BLESSED!!!!" << endl;
        }
        if (option == 4)
        {
            system("cls");
            printHeader();
            cout << "PHONE ACCESSORIES:" << endl;
            cout << "------------------------------------" << endl;
            string card;
            cout << "ENTER THE BRAND OF SIM: ";
            cin >> card;
            cout << endl;
            cout << "YOU HAVE PURCHASED SIM CARD"
                 << "\t" << card << "\t"
                 << "SUCCESSFULLY!" << endl;
            cout << endl;
            cout << "THANKS FOR COMING STAY BLESSED!!!!" << endl;
        }
        if (option == 5)
        {
            system("cls");
            printHeader();
            cout << "PHONE ACCESSORIES:" << endl;
            cout << "------------------------------------" << endl;
            string memory;
            cout << "enter the size of memory card: ";
            cin >> memory;
            cout << endl;
            cout << "YOU HAVE PURCHASED MEMORY CARD"
                 << "\t" << memory << "\t"
                 << "SUCCESSFULLY!" << endl;
            cout << endl;
            cout << "THANKS FOR COMING STAY BLESSED!!!!" << endl;
        }
        cout << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "CUSTOMER MENU:" << endl;
        Customer();
    }
    if (option == 9)
    {
        system("cls");
        printHeader();
        cout << "CUSTOMERS WALLET:" << endl;
        cout << "------------------------------------" << endl;
        cout << "YOUR CURRENT BALANCE IS PKR 150,000" << endl;
        cout << "enter your bill you want to pay through wallet: ";
        int bill;
        cin >> bill;
        if (bill > 150000)
        {
            cout << "YOUR BALANCE IN WALLET IS NOT SUFFICIENT! SORRY" << endl;
            cout << "YOU NEED RS " << bill - 150000 << " MORE!!!" << endl;
        }
        if (bill < 150000)
        {
            cout << "YOUR BILL RS " << bill << " HAS BEEN PAID SUCCESSFULLY!" << endl;
            cout << endl;
            cout << "YOUR REMAINING BALANCE IS RS " << 150000 - bill << endl;
        }
        cout << endl;
        cout << "THANKS  FOR ATTAINING OUR SERVICES!!!!" << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "CUSTOMER MENU:" << endl;
        Customer();
    }
    if (option == 10)
    {
        system("cls");
        printHeader();
        cout << "DELETE ORDER:" << endl;
        cout << "------------------------------------" << endl;
        string order;
        string model;
        string reason;
        string confirm;
        cout << "enter the product you want to cencel(mobile name): ";
        cin >> order;
        cout << "enter the model: ";
        cin >> model;
        cout << "enter the reason:" << endl;
        cin.ignore();
        getline(cin, reason);
        cout << "enter the accesories you want to cancel(if any): ";
        string accessories;
        cin >> accessories;
        cout << "confirm before deleting(if yes press'y' if no press'n'): ";
        cin >> confirm;
        cout << endl;
        cout << "YOUR ORDER HAS BEEN CANCELLED SUCCESSFULLY!!" << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "CUSTOMER MENU:" << endl;
        Customer();
    }
    if (option == 11)
    {
        system("cls");
        printHeader();
        cout << "YOUR STATUS:" << endl;
        cout << "------------------------------------" << endl;
        cout << "USERNAME:"
             << "\t" << userName << endl;
        cout << "PASSWORD:"
             << "\t" << password << endl;
        cout << "ROLE:"
             << "\t"
             << "\t " << Role << endl;
        cout << endl;
        int option1;
        cout << "press 1 to continue..." << endl;
        cin >> option1;
        system("cls");
        printHeader();
        cout << "CUSTOMER MENU:" << endl;
        Customer();
    }
    if (option == 12)
    {
        system("cls");
        printHeader();
        login();
    }
}
void admin()
{

    system("cls");
    printHeader();
    cout << "ADMIN MENU:" << endl;
    cout << "------------------------------------" << endl;
    Admin();
}
void customer()
{
    system("cls");
    printHeader();
    cout << "CUSTOMER MENU:" << endl;
    cout << "------------------------------------" << endl;
    Customer();
}

// THIS IS THE WHOLE CODE OF MY BUISNESS APPLICATION:
// MSMS (MOBILE SHOP MANAGEMENT SYSTEM):
// THANKS :) ....