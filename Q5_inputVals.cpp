/* Question 5: Input Values*/ 
#include <fstream>
#include <iostream>
using namespace std; 

void swap_point(int*, int*);
void swap_ref(int&, int&);

int main(int argc, char const *argv[])
{
    // take N by user input
    int N;
    cout << "How many integer values would you like to store?: "; 
    cin >> N; 

    // dynamically allocate memory for array of size N
    int* arr = new int[N]; 

    // user inputs array element values
    for(int i = 0; i < N; i++)
    {
        cout << "Enter next number: " ;
        cin >> arr[i];
    }

    // array elements are displayed 
    cout << "The array stored is... " << endl; 
    for(int i = 0; i < N; i++)
    {
        cout << arr[i];
        if(i != (N-1))
            cout << ", ";
    }
    cout <<endl; 

    // deallocate memory
    delete[] arr; 

}