/* Question 4: Swap*/ 
#include <fstream>
#include <iostream>
using namespace std; 

void swap_point(int*, int*);
void swap_ref(int&, int&);

int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Enter value of a: "; 
    cin >> a; 
    cout << "Enter value of b: "; 
    cin >> b; 
    
    swap_point(&a, &b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    swap_ref(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

// (a) Swap values using pointers
void swap_point(int *a, int *b)
{
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

// (b) Swap values by reference
void swap_ref(int &a, int &b)
{
    int temp = a; 
    a = b; 
    b = temp; 
}