#ifndef Cliente_H
#define Cliente_H

#include <string>

class Cliente{
    private:
        std::string name;
        std::string cpf;
    public:
    Cliente();
    Cliente(std::string new_name);
    Cliente(std::string new_name, std::string new_cpf);

    /* setters & getters */
    void set_name(std::string new_name);
    void set_cpf(std::string new_cpf);

    std::string get_name();
    std::string get_cpf();
};

#endif