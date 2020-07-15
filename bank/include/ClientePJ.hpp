#ifndef CLIENTE_PJ
#define CLIENTE_PJ

#include <string>

class ClientePJ{
    private:
        std::string cnpj;
        std::string razao_social;
    
    public:
    	ClientePJ();
    	ClientePJ(std::string razao_social, std::string cnpj);

        void set_cnpj(const std::string &cnpj);
        void set_razao_social(const std::string &razao_social);

        std::string get_cnpj();
        std::string get_razao_social();
};  

#endif