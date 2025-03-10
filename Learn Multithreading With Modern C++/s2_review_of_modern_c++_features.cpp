#include<iostream>
#include<string>
#include<vector>
#include<chrono>
#include<algorithm>
#include<utility>
#include<random>
#include<memory>

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

/*
// Define a moveable type
// The compiler will provide move operators
class Test {};

// Function which takes lvalue reference
void func(const Test& test) {
    cout<<"lvalue reference\n";
}

// Function which takes rvalue reference
void func(Test&& test) {
    cout<<"rvalue reference\n";
}
*/

/*
// A move-only class
class Test {
public:
    // = delete means the function exists but cannot be called
    // In older C++, we had to declare the member function private
    Test(const Test&) = delete;
    Test& operator = (const Test&) = delete;

    // = default means the compiler will synthesize the default version of the operator
    Test(Test&&) noexcept = default;
    Test& operator = (Test&&) noexcept = default;

    Test() = default;
};
*/

/*
// Create an engine object
std::mt19937 mt;
*/

/*
// Data structure representing a point on the screen
struct Point {
    int x;
    int y;
};
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

    // move semantics
    /*
    Test test;

    cout<<"Argument is test variable\n";
    func(test);

    cout<<"Argument is temporary object\n";
    func(Test());

    cout<<"Argument through std::move()\n";
    func(move(test));
    */

    // move-only types
    /*
    Test test1, test2, test3;
    
    // Test test4(test1);
    // test2 = test1;
    
    Test test4(move(test1));
    test3 = move(test2);
    */

    // lambda-local variables
    /*
    auto add_two = [y = 2] (int x) {
        return x + y;
    };
    cout<<add_two(2)<<"\n";
    cout<<add_two(5)<<"\n";

    // z is a local variable in the containing scope of the lambda
    int z = 1;
    
    // y is local to the lambda body
    // It is initialized using the local variable z
    auto add_z_plus = [y = z + 1](int x) {
        return x + y;
    };
    cout<<add_z_plus(2)<<"\n";
    cout<<add_z_plus(5)<<"\n";
    */

    // lambda-local variables and capture by move
    /*
    vector<string>strings(5);

    cout<<"Capture by reference\n";
    // Lambda expression which captures "strings" by reference
    [&strings] () {
        cout<<strings.size()<<"\n";
    }();
    cout<<strings.size()<<"\n";

    cout<<"Capture by move\n";
    // Lambda expression which captures "strings" by move
    // Create a new variable "vec_strings" which is local to the lambda body
    // Initialize it by moving "strings" into it
    [vec_strings = move(strings)] () {
        cout<<vec_strings.size()<<"\n";
    }();
    cout<<strings.size()<<"\n";
    */

    // random number classes
    /*
    // We want integers in the range 0 to 100
    cout<<"5 random integers between 0 and 100\n";

    uniform_int_distribution<int> uid(0, 100);
    // Get 5 random numbers
    for(int i=0; i<5; i++) {
        // Invoking the distribution returns the next number in the sequence
        cout<<uid(mt) << ", ";
    }
    cout<<"\n";
    
    // We want doubles in the range 0 to 1
    cout<<"5 random floating-point numbers between 0 and 1\n";

    uniform_real_distribution<double> did(0, 1);
    // Get 5 random numbers
    for(int i=0; i<5; i++) {
        // Invoking the distribution returns the next number in the sequence
        cout<<did(mt) << ", ";
    }
    cout<<"\n";
    */

    // std::unique_ptr
    /*
    // Create a std::unique_ptr to a Point object which has initial values {3, 6}
    auto ptr = std::make_unique<Point>(Point{3, 6});    // C++14
    cout<<ptr->x<<", "<<ptr->y<<"\n";

    // auto ptr = unique_ptr<Point>(new Point{3, 6});    // C++11
    // cout<<ptr->x<<", "<<ptr->y<<"\n";
    */

    return 0;
}