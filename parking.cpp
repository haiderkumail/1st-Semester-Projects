// Parking Project in C++.
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
int m_amo = 0, r_amo = 0, c_amo = 0, b_amo = 0;
int m_cnt = 0, r_cnt = 0, c_cnt = 0, b_cnt = 0;
int t_amo = 0, t_cnt = 0, x;

void storeData()
{
    fstream file;
    file.open("parkingLot.txt", ios::out);
    file << "motercycles: " << m_cnt << "," << m_amo << endl;
    file << "rickshaws: " << r_cnt << "," << r_amo << endl;
    file << "cars: " << c_cnt << "," << c_amo << endl;
    file << "buses: " << b_cnt << "," << b_amo << endl;
    file.close();
}

main()
{
h:

k:
    system("cls");
    cout << "\n\n\t\t\t\tParking Project";
    cout << "\n\n 1. MotoCycle";
    cout << "\n 2. Rickshaw";
    cout << "\n 3. Car";
    cout << "\n 4. Bus";
    cout << "\n 5. Check Record";
    cout << "\n 6. Delete Vehicale Record";
    cout << "\n 7. Delete Record";
    cout << "\n 8. Exit";
    cout << "\n\n Your Choice : ";
    cin >> x;
    switch (x)
    {
    case 1:
        if (t_cnt < 100)
        {
            m_cnt++;
            t_cnt++;
            m_amo += 50;
            t_amo += 50;
            cout << "\n\n\t\t\t Motorcycle Successfully Parked...";
        }
        else
            cout << "\n\n\t\t\t Parking is Full...";
        break;
    case 2:
        if (t_cnt < 100)
        {
            r_cnt++;
            t_cnt++;
            r_amo += 100;
            t_amo += 100;
            cout << "\n\n\t\t\t Rickshaw Successfully Parked...";
        }
        else
            cout << "\n\n\t\t\t Parking is Full...";
        break;
    case 3:
        if (t_cnt < 100)
        {
            c_cnt++;
            t_cnt++;
            c_amo += 150;
            t_amo += 150;
            cout << "\n\n\t\t\t Car Successfully Parked...";
        }
        else
            cout << "\n\n\t\t\t Parking is Full...";
        break;
    case 4:
        if (t_cnt < 100)
        {
            b_cnt++;
            t_cnt++;
            b_amo += 200;
            t_amo += 200;
            cout << "\n\n\t\t\t Bus Successfully Parked...";
        }
        else
            cout << "\n\n\t\t\t Parking is Full...";
        break;
    case 5:
        if (t_cnt > 0)
        {
            system("cls");
            cout << "\n\n\n\t\t\tParking Detailes";
            cout << "\n\n => Motorcycle in Parking : " << m_cnt;
            cout << "\n => Motocycle Amount : " << m_amo;
            cout << "\n\n => Rickshaw in Parking : " << r_cnt;
            cout << "\n => Rickshaw Amount : " << r_amo;
            cout << "\n\n => Car in Parking : " << c_cnt;
            cout << "\n => Car Amount : " << c_amo;
            cout << "\n\n => Bus in Parking : " << b_cnt;
            cout << "\n => Bus Amount : " << b_amo;
            cout << "\n\n => Total Vehicales in Parking : " << t_cnt;
            cout << "\n => Total Vehicales Amount : " << t_amo;
            storeData();
        }
        else
            cout << "\n\n\t\t\t Parking is Empty...";
        break;
    case 6:
    p:
        system("cls");
        cout << "\n\n\n\t\t\t Delete Vehicale Record";
        cout << "\n\n 1. Motorcycle";
        cout << "\n 2. Rickshaw";
        cout << "\n 3. Car";
        cout << "\n 4. Bus";
        cout << "\n\n Your Choice : ";
        cin >> x;
        if (x == 1)
        {
            m_cnt--;
            t_cnt--;
            cout << "\n\n\t\t\tMotorcycle Successfully Removed...";
        }
        else if (x == 2)
        {
            r_cnt--;
            t_cnt--;
            cout << "\n\n\t\t\tRickshaw Successfully Removed...";
        }
        else if (x == 3)
        {
            c_cnt--;
            t_cnt--;
            cout << "\n\n\t\t\tCar Successfully Removed...";
        }
        else if (x == 4)
        {
            b_cnt--;
            t_cnt--;
            cout << "\n\n\t\t\tBus Successfully Removed...";
        }
        else if (x == 5)
            break;
        else
        {
            cout << "\n\n\t\t\tInvalid Value...Please Try Again...";
            getch();
            goto p;
        }
        break;
    case 7:
        cout << "\n\n\t\t\t Delete Record Successfully...";
        getch();
        goto h;
    case 8:
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice...Please Try Again...";
    }
    getch();
    goto k;
}