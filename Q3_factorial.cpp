
/* Question 3: Factorial*/ 
#include <fstream>
#include <iostream>
using namespace std; 

int factorial(int n);


int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter value of n: "; 
    cin >> n; 
    int fact = factorial(n);
    cout << n <<"! = " << fact << endl;
}

int factorial(int n)
{
    if(n == 1)
        return 1; 
    else 
        return n*factorial(n-1);

}