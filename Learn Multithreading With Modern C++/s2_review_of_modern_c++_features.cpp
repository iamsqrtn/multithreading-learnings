#include<iostream>
#include<string>
#include<vector>
#include<chrono>
#include<algorithm>
using namespace std;

/*
void func(int x) {
    cout<<"func(int x) called \n";
}

void func(int* x) {
    cout<<"func(int* x) called \n";
}
*/

/*
// Pass by Value
// arg will be a copy of the object passed by the caller
void func(vector<string> arg) {
    cout<<"size =  "<<arg.size()<<"\n";
}

// Pass by Move
// The object passed by the caller is moved into arg
void func(vector<string>&& arg) {
    cout<<"size = "<<arg.size()<<"\n";
}
*/

/*
// The caller's object will be moved into x
void func(int&& x) {
    cout<<"rvalue reference\n";
}
*/

int main() {

    // universal initialization
    /*
    int x{7};
    string str{"Let us begin"};
    cout<<"x = "<<x<<"\n";
    cout<<"str = "<<str<<"\n";

    int y=7.7;
    // int y{7.7};
    cout<<"y = "<<y<<"\n";

    vector<int>vec{4,2,3,5,1};
    cout<<"vec = ";
    for(vector<int>::iterator it=vec.begin(); it!=vec.end(); ++it)
        cout<<*it<<", ";
    cout<<"\n";
    */

    // nullptr
    /*
    func(NULL);
    func(nullptr);
    */

    // std::chrono duration and std::chrono literals
    /*
    namespace sc = std::chrono;
    sc::seconds(2);
    sc::milliseconds(20);
    sc::microseconds(50);

    using namespace std::literals;
    2s;
    20ms;
    50us;
    */

    // auto type specifer, qualifier, for-loop, and range-for-loop
    /*
    vector<int>vec{4,2,3,5,1};
    for(auto it=vec.begin(); it!=vec.end(); ++it)
        *it+=2;
    for(auto it=vec.begin(); it!=vec.end(); ++it)
        cout<<*it<<", ";
    cout<<"\n";
    for(auto i: vec)
        cout<<i<<", ";
    cout<<"\n";
    for(auto& i: vec)
        i+=2;
    for(auto i: vec)
        cout<<i<<", ";
    cout<<"\n";
    */

    // lambda expression
    /*
    // In C++14, the compiler can deduce the return type
    [] (int arg) { return 2 * arg; };

    // In C++11, it must be specified with a trailing return type
    [] (int arg) -> int { arg = 2 * arg; return arg; };

    // A lambda expression is a callable object
    // It can be invoked by putting a () after the body, with any arguments
    [] (int arg) { return 2 * arg; }(3);

    //  A lambda expression can be stored in a variable of type auto
    auto lam = [] (int arg) { return 2 * arg; };
    cout<<lam(3)<<"\n";
    */

    // capture
    /*
    int n = 2;
    // Captures the local variable n (immutable copy) by value
    [n] (int arg) { return n * arg; }(3);
    cout<<n<<"\n";

    // Captures the local variable n by reference
    [&n] (int arg) { return ++n * arg; }(3);
    cout<<n<<"\n";
    */

    // lambda expression example
    /*
    vector<int>vec{4,2,3,5,1};
    for(auto i: vec)
        cout<<i<<", ";
    cout<<"\n";
    
    // Call std::count_if() algorithm using a lambda expression as predicate
    auto n_even = count_if(vec.begin(), vec.end(), 
        // The lambda definition goes inside the call
        [] (int n) { 
            return (n % 2 == 0); 
        }
    );
    cout<<n_even<<"\n";

    int radix = 3;
    // Call std::count_if() algorithm using a lambda expression as predicate
    auto n_radix = count_if(vec.begin(), vec.end(), 
        // The lambda definition goes inside the call   
        [radix] (int n) { 
            return (n % radix == 0); 
        }       
    );
    cout<<n_radix<<"\n";
    */

    // move semantics
    /*
    vector<string>vec(1000000);

    // Pass be Value
    // cout<<"Before calling func, vector size = "<<vec.size()<<"\n";
    // func(vec);
    // cout<<"After calling func, vector size = "<<vec.size()<<"\n";

    // Pass by Move
    // cout<<"Before calling func, vector size = "<<vec.size()<<"\n";
    // func(vec); // Error, doesn't compile, vec is not a movable rvalue
    // cout<<"After calling func, vector size = "<<vec.size()<<"\n";

    // cout<<"Before calling func, vector size = "<<vec.size()<<"\n";
    // func(move(vec)); // std::move() casts vec to an rvalue
    // cout<<"After calling func, vector size = "<<vec.size()<<"\n";
    */
    
    // reference
    /*
    // func(2);

    int y = 2;
    func(y);    // Error, must be a movable rvalue
    */

    return 0;
}