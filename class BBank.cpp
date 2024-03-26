
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;
public:
    BankAccount(int accNumber, double accBalance) {
        this->accountNumber = accNumber;
        this->balance = accBalance;
        this->interestRate = 0;
    }
    double deposit(double money) {
        balance += money;
        cout << "\nВнесенная сумма: " << money;
        getBalance();
        return balance;
    }
    double withdraw(double money) {
        if ((balance - money) >= 0) {
            balance -= money;
            cout << "\nСнятая сумма: " << money;
            getBalance();
            return balance;
        }
        cout << "\nНедостатоно средств.";
        return -1;
    }
    double getBalance() {
        cout << "\nБаланс: " << balance << "\n";
        return balance;
    }
    double getInterest() {
        double interest = balance * interestRate * (1.0 / 12);
        cout << "\nПроцент: " << interest;
        return balance * interestRate * (1 / 12);
    }
    double setInterestRate(double interRt) {
        cout << "\nНовая ставка: " <<  interRt;
        interestRate = interRt;
        return interestRate;
    }
    int getAccountNumber() {
        cout << "\nНомер счета: " << accountNumber;
        return accountNumber;
    }
    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount)
{
    if (from.withdraw(amount) >= 0) { to.deposit(amount); return true; }
    return false;
}

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "Введите номер счета:";
    int accNumber;
    cin >> accNumber;
    cout << "Ведите баланс:";
    double accBalance;
    cin >> accBalance;
    BankAccount firstAccount(accNumber, accBalance);
    cout << "Счет создан";

    BankAccount secondAccount(1111222233334444, 30000000);
    cout << "\nВведите сумму перевода:";
    double money1;
    cin >> money1;
    transfer(firstAccount, secondAccount, money1);
            
    cout << "\nВведите сумму взноса: ";
    double summaVsnosa;
    cin >> summaVsnosa;
    firstAccount.deposit(summaVsnosa);

    cout << "\nВведите сумму снятия: ";
    double summaSnyatia;
    cin >> summaSnyatia;
    firstAccount.withdraw(summaSnyatia);

    cout << "\nПроцент: ";
    firstAccount.getInterest();

    cout << "\nОбновить процент: ";
    double newProcent;
    cin >> newProcent;
    firstAccount.setInterestRate(newProcent);
    
    return 0;
}
