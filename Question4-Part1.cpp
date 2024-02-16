// Single Threaded Program

#include<iostream>
#include<thread>

using namespace std;

void function1(){
    long a = 1000;
    long result = 0;
    for(long i = 0; i < a; i++){
        result += i;
    }
    std::cout<<"Result: "<<result<<endl;
}


int main()
{
    chrono::time_point<chrono::system_clock> start, end;

    // single threaded Program woking fast
    start = chrono::system_clock::now();
    function1(); // Running on main thread
    end = chrono::system_clock::now();
    std::cout << "Time Taken by SIngle Threaded Program: " << (end - start).count() << std::endl;

    // multi threaded Program working slow
    start = chrono::system_clock::now();
    thread t21(function1);
    thread t22(function1);
    t21.join();
    t22.join();
    end = chrono::system_clock::now();
    std::cout << "Time Taken by Multi Threaded Program: " << (end - start).count() << std::endl;
}



// avg time taken by single threaded program is: 81157
// avg time taken by Multi threaded threaded program is: 483518

/*
the above result show that when we run the program in single threaded mode, it is running fast then multi threaded mode.

this is because in single threaded program there is no extra time for creating another thread.
But in multi threaded program there is extra time for creating another thread.

So the single threaded program does not have to be assigned new resource and relese them after completing the task.
But in multi threaded program it has to be assigned new resource and relese them after completing the task.

*/