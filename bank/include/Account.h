#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Client.h"
#include "Agency.h"

#include <string>
#include <ctime>

class Account{
    private:
        std::string number;
        double balance;
    
    public:
        Client client;
        Agency agency;

        Account();
        Account(Client new_client, Agency new_agency);
        int deposit(double value);
        int withdraw(double value);
        int transfer(Account &destiny, double value);

        /* setters & getters */
        void set_number(std::string new_number);
        void set_client_name(std::string name);
        std::string get_client_name();
        std::string get_number();
        double get_balance();
};


#endif