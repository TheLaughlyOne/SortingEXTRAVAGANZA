#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <cmath>
#include <algorithm>

using namespace std;

// global variables
int sortInt;
char choice;
char repeat;
vector<int> toBeSorted;
bool sorted = true;
int n;
int temp;

class sortingAlgos
{
public:
    // bubble sort
    void bubble(vector<int> toBeSorted)
    {
        n = toBeSorted.size();
        int p = 0;

        for(int i=0; i<n; i++)
        {

            if(p != 0)
            {
                i = 0;
                p--;
            }

            if(p == 0 && i == n-1)
            {
                continue;
            }

            if(toBeSorted[i] > toBeSorted[i+1])
            {
                temp = toBeSorted[i];
                toBeSorted[i] = toBeSorted[i+1];
                toBeSorted[i+1] = temp;

                p++;
            }
        }

        // outputs the (now) sorted set
        for(int i=0; i<n; i++)
        {
            cout << toBeSorted[i] << endl;
        }
    }
    // selection sort
    void selection(vector<int> toBeSorted)
    {
        int n = toBeSorted.size();
        int lo;

        for(int i=0; i<n-1; i++)
        {
            lo = i;

            for(int j=i+1; j<n; j++)
            {
                if(toBeSorted[lo] > toBeSorted[j])
                {
                    lo = j;
                }
            }

            swap(toBeSorted[lo], toBeSorted[i]);
        }

        for(int i=0; i<n; i++)
        {
            cout << toBeSorted[i] << endl;
        }
    }
    // insertion sort
    void insertion(vector<int> toBeSorted)
    {
        n = toBeSorted.size();
        int i = 1;

        while(i<n)
        {
            int k = toBeSorted[i];
            int j = i;

            while(j>0 && toBeSorted[j-1]>k)
            {
                toBeSorted[j] = toBeSorted[j-1];
                j = j-1;
            }

            toBeSorted[j] = k;
            i++;
        }

        for(int i=0; i<n; i++)
        {
            cout << toBeSorted[i] << endl;
        }
    }
    // gnome sort
    void gnome(vector<int> toBeSorted)
    {
        n = toBeSorted.size();
        int i = 0;

        while(i<n)
        {
           if(i == 0 || toBeSorted[i] >= toBeSorted[i-1])
           {
               i++;
           }
           else
           {
               swap(toBeSorted[i], toBeSorted[i-1]);
               i--;
           }
        }

        for(int i=0; i<n; i++)
        {
            cout << toBeSorted[i] << endl;
        }
    }
    void parity(vector<int> toBeSorted)
    {
        n = toBeSorted.size();
        sorted = false;

        while(!sorted)
        {
            sorted = true;

            for(int i=1; i<n-1; i=i+2)
            {
                if(toBeSorted[i]>toBeSorted[i+1])
                {
                    temp = toBeSorted[i];
                    toBeSorted[i] = toBeSorted[i+1];
                    toBeSorted[i+1] = temp;

                    sorted = false;
                }
            }

            for(int i=0; i<n-1; i=i+2)
            {
                if(toBeSorted[i]>toBeSorted[i+1])
                {
                    temp = toBeSorted[i];
                    toBeSorted[i] = toBeSorted[i+1];
                    toBeSorted[i+1] = temp;

                    sorted = false;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            cout << toBeSorted[i] << endl;
        }
    }
};
