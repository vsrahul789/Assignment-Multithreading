#include <iostream>
#include <thread>
using namespace std;

void thread_function(int &value){
    value = 10;
}

int main(){
    int value = 0;
    cout<<value<<endl;
    thread t1(thread_function, ref(value));
    t1.join();
    cout<<value<<endl;
    return 0;
}