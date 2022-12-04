
#include <iostream>
#include <string>
#include <thread>

using namespace std;
using namespace std::chrono;

void func1(int a, int b){

    cout << a+b << endl;
}

void func2(int a, int b){

    cout << a*b << endl;
}

int main(){

    int a = 4;
    int b = 5;

    auto start_time = high_resolution_clock::now();

    thread t1(func1, a, b);
    thread t2(func2, a,b);

    t1.join();
    t2.join();
    
    auto stop_time = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop_time - start_time);

    cout << "Timing:" << duration.count() << endl;


    return 0;
}
