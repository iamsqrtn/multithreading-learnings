#include<iostream>
#include<string>
#include<vector>
#include<chrono>
using namespace std;

/*
void func(int x) {
    cout<<"func(int x) called \n";
}

void func(int* x) {
    cout<<"func(int* x) called \n";
}
*/

int main() {

    // Universal Initialization
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

    return 0;
}