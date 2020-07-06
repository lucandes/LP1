#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account{
    private:
        int number;
        double balance;
        std::string client_name;
    
    public:
        Account();
        Account(std::string client_name);
        int deposit(double value);
        int withdraw(double value);
        int transfer(Account &destiny, double value);

        /* setters & getters */
        void set_number(int new_number);
        void set_client_name(std::string name);
        std::string get_client_name();
        int get_number();
        double get_balance();
};


#endif