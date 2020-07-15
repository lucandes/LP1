#ifndef Agencia_H
#define Agencia_H

#include <string>

class Agencia{
    private:
        std::string name;
        int number;
        
    public:
        Agencia();
        Agencia(std::string new_name, int new_number);

        /* setters & getters */
        void set_name(std::string new_name);
        void set_number(int new_number);
        std::string get_name();
        int get_number();
};

#endif