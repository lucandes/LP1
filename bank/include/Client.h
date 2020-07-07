#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client{
    private:
        std::string name;
        std::string cpf;
    public:
    Client();
    Client(std::string new_name);
    Client(std::string new_name, std::string new_cpf);

    /* setters & getters */
    void set_name(std::string new_name);
    void set_cpf(std::string new_cpf);

    std::string get_name();
    std::string get_cpf();
};

#endif