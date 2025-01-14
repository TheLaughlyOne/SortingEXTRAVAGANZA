#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <cmath>
#include <algorithm>

using namespace std;

int sortInt;
char choice;
vector<int> toBeSorted;
bool sorted = true;
int n;
int temp;

class sortingAlgos
{
public:
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

        for(int i=0; i<n; i++)
        {
            cout << toBeSorted[i] << endl;
        }
    }
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
};

