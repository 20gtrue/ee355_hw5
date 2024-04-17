/* Question 1:
a) Design a pseudocode  for a slightly modifed version of Towers of Hanoi: There are 3n disks. Each 3 disks are identical. The constraints are the same as those of the Towers of Hanoi. Note that identical disks can be put on top of eachother in any order. 
b) Implement your pseudocode in C++.  
c) Discuss a test plan for your code with at least 10 different scenarios/cases that target corner/special cases as well as random cases. 
Note: Submit a softcopy of your code and testbench.
*/ 

/* (a) Design pseudocode for towers of hanoi with 3n disks... 

    void towers(string source, string dest, string aux, int n) {
        if(n == 1) // base case
        {
            // Move the three identical disks (n11, n12, n13) from source to destination 
        }
        else // recursive case
        {
            // call towers to move 3n-3 blocks from source to auxillary
            // move nth three blocks from source to destination 
            // call towers to move 3n - 3 blocks from auxillary to destination
        }
    }
*/ 

/* (b) Implement Design for towers of hanoi with 3n disks */ 
#include <fstream>
#include <iostream>
using namespace std; 

void towers(string source, string dest, string aux, int n);


int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter value of n: "; 
    cin >> n; 
    
    towers("source", "auxillary", "destination", n); // move disks from A to B using C as the auxillary tower

    /* code */
    return 0;
}


void towers(string source, string dest, string aux, int n) {
    if(n <= 0)
    {
        cout << "No movement needed, as no blocks or negative blocks are present." <<endl; 
    }
    else if(n == 1) // base case
    {
        // Move the three identical disks (n11, n12, n13) from source to destination 
        cout << "Move three identical blocks from " << source << " to " << dest << endl;
    }
    else // recursive case
    {
        // call towers to move 3n-3 blocks from source to auxillary
        towers(source, aux, dest, n - 1);

        // move nth three blocks from source to destination 
        cout << "Move three identiacal blocks from " << source << " to " << dest << endl;

        // call towers to move 3n - 3 blocks from auxillary to destination
        towers(aux, dest, source, n - 1);
    }
}


/* (c) Discuss a test plan for your code with at least 10 different scenarios/cases that target corner/special cases as well as random cases.

    Note: I made it so when you ran the executable file, you can input n; to test I inputted the following values... 

    To test my software, I would start by testing the corner cases which in this case are our base cases... 
        n = -4; --> checks that if the input is negative, the response is correct; checks exceptional case
        n = 0; --> checks that if the input is 0, the response is correct; checks case of no blocks present
        n = 1; --> checks the base case
        n = 0.4 --> check decimal case 
        n = 2.0 --> check decimal case where the value is a whole number with a decimal component of zero
    I would then test random values... 
        n = 2 --> make sure that recursive case works using the fewest function calls, n=1 only checks base case
        n = 3 
        n = 4 
        n = 10 --> increase values to see impact on recursive function 
        n = 100 --> increase values to see impact on recursive function 

*/ 

