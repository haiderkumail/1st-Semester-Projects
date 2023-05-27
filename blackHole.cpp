#include <iostream>
using namespace std;
bool gravity = false;
char objects[5][5] = {
    {'-'

     ,
     '#', '#',
     '-', '#'},

    {'#',
     '-',
     '-', '#',
     '-'},

    {'-'

     ,
     '#',
     '-',
     '-',
     '-'},

    {'#',
     '-', '#',
     '-', '#'},

    {'#',
     '-',
     '-',
     '-',
     '-'}

};
void timeTick(int times)
{
    int count = 0;
    if (gravity)
    {
        while (count < times)
        {
            for (int row = 3; row >= 0; row--)
            {
                for (int col = 0; col < 5; col++)
                {
                    if (objects[row][col] == '#')
                    {
                        if (objects[row + 1][col] == '-')
                        {
                            objects[row + 1][col] = '#';
                            objects[row][col] = '-';
                        }
                    }
                }
            }
            count = count + 1;
        }
    }
}
void setGravityStatus(bool value)

{
    gravity = value;
}
void displayWorld()
{
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            cout << objects[row][col];
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}



main()
{
    system("cls");
    int times;
    displayWorld();
    setGravityStatus(true);
    cout<<"enter the number of times you wnat to move :";
    cin>>times;
    timeTick(times);
    displayWorld();
}