#include <fstream>
#include <iostream>
using namespace std; 

struct employee
{
    string name; 
    int id; 
    string title; 
    int salary;
    employee* next; 
    employee* prev; 
};

class database
{
    private: 
        employee* head; 
        employee* tail;

    public:
        database() : head(nullptr), tail(nullptr) {}; 
        void add(string name, int id, string title, int salary)
        {
            employee* emp = new employee; 
            emp -> name = name; 
            emp -> id = id; 
            emp -> title = title; 
            emp -> salary = salary; 
            emp -> next = nullptr;
            emp -> prev = nullptr;

            // if this is the first employee added to list... 
            if (head == nullptr) 
            {
                head = emp;
                tail = emp;
            } 
            // if its not the first employee... 
            else {
                tail->next = emp;
                emp->prev = tail;
                tail = emp;
            }
        }
        
        void remove(int id){
            employee* curr = head;
            while (curr != nullptr) {
                if (curr->id == id) {
                    if (curr == head && curr == tail) {
                        head = nullptr;
                        tail = nullptr;
                    } else if (curr == head) {
                        head = head->next;
                        head->prev = nullptr;
                    } else if (curr == tail) {
                        tail = tail->prev;
                        tail->next = nullptr;
                    } else {
                        curr->prev->next = curr->next;
                        curr->next->prev = curr->prev;
                    }
                    delete curr;
                    return;
                }
                curr = curr->next;
            }
        };

        void search_name(string name){
            employee* curr = head;
            while (curr != nullptr) {
                if (curr->name == name) {
                    cout << "Employee " << curr->name << " (" << curr->id << "): " << curr->title << "[ $ " << curr->salary << "] " << endl;
                    return;
                }
                else 
                {
                    curr = curr->next;
                }
            }
            cout << "Employee " << name << " was not found." << endl;
        };

        void search_id(int id){
            employee* curr = head;
            while (curr != nullptr) {
                if (curr->id == id) {
                    cout << "Employee " << curr->name << " (" << curr->id << "): " << curr->title << "[ $ " << curr->salary << "] " << endl;
                    return;
                }
                else 
                {
                    curr = curr->next;
                }
            }
            cout << "Employee " << id << " was not found." << endl;
        };

};

int main(int argc, char const *argv[])
{
    database emp_db;
    emp_db.add("Susie", 100, "SWE", 85000);
    emp_db.add("Fred", 103, "Finance", 65000); 
    
    emp_db.search_id(103);
    emp_db.search_name("Susie");
    emp_db.remove(103);

    return 0;
};


/*
    DLL is better than SSL becuase it can go in both directions however, 
    in this case there is no difference as we do not take advantage of any DLL functionality.
*/ 