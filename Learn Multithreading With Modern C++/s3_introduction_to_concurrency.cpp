#include <iostream>
#include <thread>

using namespace std;

/*
// Callable Object - thread entry point
void hello() {
    cout<<"Hello, Thread \n";
}
*/

/*
// Functor class with overloaded () operator
class Hello {
public:
    void operator()() {
        cout << "Hello, Functor Thread \n";
    }
};
*/

int main() {

    // thread entry point
    /*
    // Create an std::thread object, and pass the task function to the constructor
    thread th(hello);
    thread th{hello};
    
    // Wait for the thread to complete
    th.join();
    */

    // functor as entry point
    /*
    // Create an object of the functor class
    Hello hello;

    // Pass the functor object to std::thread's constructor
    thread th1(hello);

    // Use a lambda expression as the thread's entry point
    thread th2([]() {
        cout << "Hello, Lambda Thread \n";
    });
    
    // Wait for the thread to complete
    th1.join();
    th2.join();
    */

    return 0;
}