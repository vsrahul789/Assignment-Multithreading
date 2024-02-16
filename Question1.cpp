#include<iostream>
#include<thread>

using namespace std;

void ThreadCreationConfirmation(){
    cout<<"Thread Created Successfully"<<endl;
}

int main(){
    thread t1(ThreadCreationConfirmation);
    t1.join();
    return 0;
}