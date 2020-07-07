#ifndef AGENCY_H
#define AGENCY_H

#include <string>

class Agency{
    private:
        std::string name;
        int number;
        
    public:
        Agency();
        Agency(std::string new_name, int new_number);

        /* setters & getters */
        void set_name(std::string new_name);
        void set_number(int new_number);
        std::string get_name();
        int get_number();
};

#endif