#include <iostream>
#include <thread>

double account_balance = 1000.0; // Shared resource

void withdrawMoney(double amount)
{
    if (account_balance >= amount)
    {
        account_balance -= amount; // Potential race condition here
        std::cout << "Transaction successful: Withdrew " << amount << std::endl;
    }
    else
    {
        std::cout << "Transaction failed: Insufficient balance" << std::endl;
    }
}

int main()
{
    std::thread t1(withdrawMoney, 500.0);
    std::thread t2(withdrawMoney, 500.0);

    t1.join();
    t2.join();

    std::cout << "Final account balance: " << account_balance << std::endl;

    return 0;
}