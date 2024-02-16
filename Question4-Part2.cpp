// Multi-threading Program

#include <iostream>
#include <thread>
// #include<chrono>
#include<vector>
using namespace std;

long long singleThread(vector<int> &data){
    long long sum = 0;
    for (int i = 0; i < data.size(); i++)
    {
        sum += data[i];
    }
    // cout<< "Single thread sum is: " << sum << endl;
    return sum;
}

long long partialThread(vector<int> &data){
    long long sum = 0;
    for (int i = 0; i < data.size(); i++)
    {
        sum += data[i];
    }
    return sum;
}

long long multiThread(vector<int> &data){
    int threadCount = 4; 

    int chunkSize = data.size()/threadCount;
    if (data.size() % threadCount != 0) {
        chunkSize++;
    }

    vector<vector<int>> subVectors(threadCount);
    for (int i = 0; i < data.size(); ++i) {
        subVectors[i % threadCount ].push_back(data[i]);
    }

    vector<thread> threads(threadCount);
    vector<long long> partialThread(threadCount);
    for (int i = 0; i < threadCount; ++i) {
        threads[i] = thread(partialThread, ref(subVectors[i]), partialThread[i]);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    long long totalSum = 0;
    for (int i = 0; i < threadCount; ++i) {
        totalSum += partialThread[i];
    }
    return totalSum;
}

int main(){
    vector<int> data(1000, 2);
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    long long singleThreadResult = singleThread(data);
    end = chrono::system_clock::now();
    chrono::duration<double, nano> SingleElapsedSeconds = end-start;
    cout<<"Single Threaded Result: "<< singleThreadResult<< endl;
    cout<< SingleElapsedSeconds.count() <<endl;

    start = chrono::system_clock::now();
    long long multiThreadResult = multiThread(data);
    end = chrono::system_clock::now();
    chrono::duration<double, nano> MultiElapsedSeconds = end-start;
    cout<<"Multi Threaded Result: "<< multiThreadResult<< endl;
    cout<< MultiElapsedSeconds.count() <<endl;

}