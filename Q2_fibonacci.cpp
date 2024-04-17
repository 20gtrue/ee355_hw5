/* Q2: Fibonacci */ 
#include <fstream>
#include <iostream>
using namespace std; 

class Fibonacci {
	protected: int N; 
    private: int* sequence;
    public:
        // Fibonacci() : N(0) {}  // Default constructor 
        
        ~Fibonacci()
        {
            delete[] sequence; 
        }
        
        Fibonacci(int input_N)
        {
            N = input_N; 
            sequence = new int[N]; 
        }

        // virtual void set_n()
        // {
        //     cout << "How many values of the Fibonacci Sequence would you like to store?: ";
        //     cin >> N; 
        // }  

        virtual void calculate()
        {
            if(this->N >= 1)
            {
                sequence[0] = 0;
            }
            if(this->N >= 2)
            {
                sequence[1] = 1;
            }
            for(int i = 2; i < N; i++)
            {
                sequence[i] = sequence[i-2] + sequence[i-1];
            }
        }

        virtual void display() 
        {
            cout << "Fibonacci Sequence: " <<endl; 
            for(int i = 0; i < N; i++)
            {
                cout << sequence[i]; 
                if(i != N-1)
                    cout << ", "; 
            }
            cout <<endl; 
        } 
};

int main(int argc, char const *argv[])
{
    Fibonacci a(4); 
    a.calculate();
    a.display(); 

    /* code */
    return 0;
}
