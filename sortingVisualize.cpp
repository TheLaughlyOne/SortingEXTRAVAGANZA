// It sorts a set of numbers in a vector defined by user input using a sorting algorithm chosen by user input.
#include "global.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <cstddef>
#include <cstdlib>
#include <typeinfo>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>

using namespace std;

void getToBeSorted()
{
    cout << "Enter integers. Type 'p' to begin sorting (Number cannot exceed 2147483647 & no commas)" << "\n\n";

    while(1)
    {
        cin >> sortInt;

        toBeSorted.push_back(sortInt);

        cout << "\n";

        if(cin.fail())
        {
            cin.clear();
            toBeSorted.pop_back();
            break;
        }
    }
}

void check()
{
    for(int i=0; i<toBeSorted.size(); i++)
    {
        if(toBeSorted.size() >= 2)
        {
        }
        else
        {
            sorted = true;
            break;
        }

        if(toBeSorted.back() >= toBeSorted[i])
        {
        }
        else
        {
            sorted = false;
            break;
        }

        if(toBeSorted[i] >= toBeSorted[i-1] || i == 0)
        {
        }
        else
        {
            sorted = false;
            break;
        }

        if(toBeSorted[i] >= toBeSorted.front())
        {
        }
        else
        {
            sorted = false;
            break;
        }
    }

    if(sorted == true)
    {
        cout << "Already Sorted/Invalid." << endl << endl;
        return;
    }
}

int main()
{
    getToBeSorted();
    check();
    sortingAlgos algos;

    if(sorted == false)
    {
        cout << "Choose a sorting algorithm. Press o to see options" << "\n";

        while(1)
        {
            cin >> choice;

            if(choice == 'o' || choice == 'O')
            {
                cout << "\n" << "Options:" << "\n" << "b = bubble sort" << "\n" << "s = selection sort" << "\n"
                << "i = insertion sort" << "\n" << "g = gnome sort" << "\n\n";
            }
            else if(choice == 's' || choice == 'S')
            {
                cout << "\n";
                algos.selection(toBeSorted);
                cout << "\n";
                break;
            }
            else if(choice == 'b' || choice == 'B')
            {
                cout << "\n";
                algos.bubble(toBeSorted);
                cout << "\n";
                break;
            }
            else if(choice == 'i' || choice == 'I')
            {
                cout << "\n";
                algos.insertion(toBeSorted);
                cout << "\n";
                break;
            }
            else if(choice == 'g' || choice == 'G')
            {
                cout << "\n";
                algos.gnome(toBeSorted);
                cout << "\n";
                break;
            }
        }

        while(1)
        {
            cout << "Repeat? Type y if so" << "\n";

            cin >> repeat;

            if(repeat == 'y' || repeat == 'Y')
            {
                toBeSorted.clear();
                cout << "\n";

                getToBeSorted();
                check();

                cout << "Choose a sorting algorithm. Press o to see options" << "\n";

                while(1)
                {
                    cin >> choice;

                    if(choice == 'o' || choice == 'O')
                    {
                        cout << "\n" << "Options:" << "\n" << "b = bubble sort" << "\n" << "s = selection sort" << "\n"
                        << "i = insertion sort" "\n" << "g = gnome sort" << "\n\n";
                    }
                    else if(choice == 's' || choice == 'S')
                    {
                        cout << "\n";
                        algos.selection(toBeSorted);
                        cout << "\n";
                        break;
                    }
                    else if(choice == 'b' || choice == 'B')
                    {
                        cout << "\n";
                        algos.bubble(toBeSorted);
                        cout << "\n";
                        break;
                    }
                    else if(choice == 'i' || choice == 'I')
                    {
                        cout << "\n";
                        algos.insertion(toBeSorted);
                        cout << "\n";
                        break;
                    }
                    else if(choice == 'g' || choice == 'G')
                    {
                        cout << "\n";
                        algos.gnome(toBeSorted);
                        cout << "\n";
                        break;
                    }
                }
            }
        }
    }

    sleep(10000);
    return 0;
}
