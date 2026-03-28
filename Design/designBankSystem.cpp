#include "../common.hpp"

/*
Bank Account
*/
class Account{
protected:
    string accountName;
    int    accountNumber;
    double balance = 0.0;

    bool isValidAmount(double amount){
        if (amount < 0.0){
            cerr << "Transaction does not take negative money: " << amount << endl;
            return false;
        }
        return true;
    }
public:
    Account(string name, int number) : accountName(name), accountNumber(number) {};

    virtual bool deposit(double amount){
        if (!isValidAmount(amount)) return false;
    
        balance += amount;
        return true;
    }

    virtual bool withdraw(double amount) = 0;

    double getBalance() const{
        return balance;
    }

    virtual ~Account() {};
};

/*
Saving account
*/
class SavingsAccount : public Account{
private:
    double interestRate;
public:
    SavingsAccount(string name, int number, double rate) : Account(name, number), interestRate(rate) {};

    bool withdraw(double amount)  override{
        if (!isValidAmount(amount)) return false;
        if (amount > balance){
            cerr << "Withdrawl amount greater than current balance" << endl;
            return false;
        }
        balance -= amount;
        return true;   
    }
};

/*
Checkings account
*/
class CheckingAccount : public Account{
private:
    double overdraftLimit;
public:
    CheckingAccount(string name, int number, double overLimit) : Account(name, number), overdraftLimit(overLimit) {};
    
    bool withdraw(double amount) override{
        if (!isValidAmount(amount)) return false;
        if (amount > balance + overdraftLimit){
            cerr << "Withdarwal amount will exceed current overdraft Limit" << endl;
            return false;
        }
        balance -= amount;
        return true;
    }
};

/*
Loan Account
*/
class LoanAccount : public Account{
private:
    double loanLimit;
public:
    LoanAccount(string name, int number, double loanAmount, double limit) : Account(name, number), loanLimit(limit) {
        balance = loanAmount;
    };
    
    bool withdraw(double amount) override{
        if (!isValidAmount(amount)) return false;
        if (amount > loanLimit - balance){
            cerr << "Withdarwal amount will exceed current Loan Limit" << endl;
            return false;
        }

        balance += amount;
        return true;
    }

    bool deposit(double amount) override{
        if (!isValidAmount(amount)) return false;

        if (amount > balance){
            cerr << "Payment amount too much: Cannot pay more than you owe: " << endl;
            return false;
        }

        balance -= amount;
        return true;
    }
};


int main(){
    CheckingAccount checking("Tony", 1, 100);
    SavingsAccount  saving("Tony", 2, 5);
    LoanAccount     loanaccount("Tony", 3, 500, 1000);

    checking.deposit(100);
    saving.deposit(200);


    vector<Account*> bank;
    bank.push_back(&checking);
    bank.push_back(&saving);
    bank.push_back(&loanaccount);

    for (const Account* account : bank){
        cout << account->getBalance() << endl;
    }

}