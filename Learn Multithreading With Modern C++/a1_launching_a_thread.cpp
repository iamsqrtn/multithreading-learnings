#include <iostream>
#include <thread>

using namespace std;

void func() {
    int n=1;
    string player[] = {"Abdul", "Bart", "Claudia", "Divya"};
    while(true) {
        cout<<player[(n-1)%4]<<" says ";
        if((n%3==0) || (n%5==0)) {
            if(n%15==0)
                cout<<"fizzbuzz \n";
            else if(n%3==0)
                cout<<"fizz \n";
            else
                cout<<"buzz \n";
        }
        else
            cout<<n<<"\n";
        n++;
    }
}

int main() {
    
    // func();
    // thread th(func);
    thread th{func};
    th.join();

    return 0;
}