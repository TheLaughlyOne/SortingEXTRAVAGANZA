// It sorts a set of numbers in a vector defined by user input using a sorting algorithm chosen by user input
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

void getToBeSorted()
{
    std::cout << "Enter integers. Type any letter to begin sorting (Number cannot exceed 2,147,483,647)" << "\n\n";

    while(1)
    {
        std::cin >> sortInt; // repeatedly asks for user input

        toBeSorted.push_back(sortInt);

        std::cout << "\n";

        if(std::cin.fail()) // until they type a letter
        {
            std::cin.clear();
            toBeSorted.pop_back(); // removes the letter from the vector, so that only the numbers are being sorted
            break; // ends while loop
        }
    }
}

void check() // checks whether the set is sorted or not
{
    for(int i=0; i<toBeSorted.size(); i++)
    {
        // if the vector is below 2 elements, it is already sorted (obvious)
        if(toBeSorted.size() >= 2)
        {
        }
        else
        {
            sorted = true;
            break;
        }

        // if the ending element is lesser than the current one, the vector is not sorted
        if(toBeSorted.back() >= toBeSorted[i])
        {
        }
        else
        {
            sorted = false;
            break;
        }

        /* for a set of numbers to be sorted, the current element must be larger than the element before it,
        this does not allply when the loop starts because there is no element before it*/
        if(toBeSorted[i] >= toBeSorted[i-1] || i == 0)
        {
        }
        else
        {
            sorted = false;
            break;
        }

        // if the starting element is greater than the current one, the vector is not sorted
        if(toBeSorted[i] >= toBeSorted.front())
        {
        }
        else
        {
            sorted = false;
            break;
        }
    }
}

void sorter()
{
    sortingAlgos algos; // Getting the class with the sorting algorithms

    if(sorted == false || sorted == true)
    {
        std::cout << "Choose a sorting algorithm. Press o to see options" << "\n";

        while(1)
        {
            std::cin >> choice;

            // if they inputted o, it will show the options
            if(choice == 'o' || choice == 'O')
            {
                std::cout << "\n" << "Options:" << "\n"
                << "b = bubble sort" << "\n"
                << "s = selection sort" << "\n"
                << "i = insertion sort" << "\n"
                << "g = gnome sort" << "\n"
                << "p = parity sort" << "\n\n";
            }
            // if they inputted s, it will perform selection sort, ignoring capitals
            else if(choice == 's' || choice == 'S')
            {
                std::cout << "\n";
                algos.selection(toBeSorted);
                std::cout << "\n";
                break;
            }
            // if they inputted b, it will perform bubble sort, ignoring capitals
            else if(choice == 'b' || choice == 'B')
            {
                std::cout << "\n";
                algos.bubble(toBeSorted);
                std::cout << "\n";
                break;
            }
            // if they inputted i, it will perform insertion sort, ignoring capitals
            else if(choice == 'i' || choice == 'I')
            {
                std::cout << "\n";
                algos.insertion(toBeSorted);
                std::cout << "\n";
                break;
            }
            // if they inputted g, it will perform gnome sort, ignoring capitals
            else if(choice == 'g' || choice == 'G')
            {
                std::cout << "\n";
                algos.gnome(toBeSorted);
                std::cout << "\n";
                break;
            }
            // if they inputted p, it will perform parity sort, ignoring capitals
            else if(choice == 'p' || choice == 'P')
            {
                std::cout << "\n";
                algos.parity(toBeSorted);
                std::cout << "\n";
                break;
            }
        }

        while(1)
        {
            std::cout << "Repeat? Type y if so" << "\n";

            std::cin >> repeat;

            /* if the user inputs y, it will recurse the sorter function onto itself,
            and will run the getToBeSorted function and the check function as well*/
            if(repeat == 'y' || repeat == 'Y')
            {
                toBeSorted.clear(); // clears all elements from the vector, to be filled in again
                std::cout << "\n";

                getToBeSorted();
                check();
                sorter();
            }
        }
    }
}

int main()
{
    // int main runs all of these functions
    getToBeSorted();
    check();
    sorter();
    sortingAlgos algos;

    sleep(10000);
    return 0;
}
