#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double list[30];
int lsize = 0;
double mean = 0;
double stdev = 0;
int mid = 0;
double median = 0;
int main()
{
    //create while loop that generates list of numbers, sorts them from smallest to largest, and exits 
	//when negative number is entered
    while(true)
    {
        cout << "Enter a number (enter a negative number to exit): ";
        double i;
        cin >> i;
        if(i < 0) break;
        int ptr; //pointer
        for(ptr = lsize; ptr > 0 && list[ptr -1] > i; ptr--)
            list[ptr] =  list[ptr -1];
        list[ptr] = i;
        lsize = lsize + 1;
    }
	//output list of sorted numbers
    for(int j = 0; j < lsize; j++)
        cout << fixed << setprecision(2) << setw(6) << list[j] << endl;
	//determine if number of elements in list is even or odd, then determine median
    if(lsize % 2 == 0)
    {
        mid  = lsize / 2;
        median = (list[mid - 1] + list[mid]) / 2;
    }
    if(lsize % 2 == 1)
    {
        mid = (lsize + 1) / 2;
        median = list[mid - 1];
    }
	//calculate mean
    for(int k = 0; k < lsize; k++)
        mean = mean + list[k];
    mean = mean / lsize;
	//calculate standard deviation
	double x;
    for(int l = 0; l < lsize; l++)
    {
        x = pow((list[l] - mean),2.0);
        stdev += x;
    }
    stdev = sqrt(stdev / lsize);
    cout << endl;
    cout << fixed << setprecision(4) << "Mean = " << mean << "       ";
    cout << fixed << setprecision(4) << " Standard Deviation = " << stdev << "       ";
    cout << fixed << setprecision(2) << " Median = " << median << "       ";
    return 0;
}

