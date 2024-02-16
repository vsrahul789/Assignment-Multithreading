#include <iostream>
#include <thread>
using namespace std;

void Multiplication(int a, int b)
{
    cout << a * b << endl;
}
void Division(int a, int b)
{
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    cout<< a/b << endl;
}

int main()
{
    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    thread t1(Multiplication, a, b);
    thread t2(Division, a, b);
    t1.join();
    t2.join();

    return 0;
}