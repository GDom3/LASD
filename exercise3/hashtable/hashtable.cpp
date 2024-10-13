
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */


template <> class Hashable<int>{
    public :
        unsigned long operator()(const int& dato ) const noexcept{
            const double costanteFibonacci = (std::sqrt(5)-1)/2;
            
            unsigned long parteDecimale = (costanteFibonacci * dato * dato) - std::floor(costanteFibonacci * dato * dato);
            
            return parteDecimale;
        }

};

template <> class Hashable<double>{
    public :
       
        unsigned long operator()(const double& dato ) const noexcept{
            const double costanteFibonacci = (std::sqrt(5)-1)/2;

            unsigned long parteDecimale = (costanteFibonacci * dato) - std::floor(costanteFibonacci * dato);
          
            return parteDecimale; 
        }

};

template <> class Hashable<std::string>{
    public :
        unsigned long operator()(const std::string& dato ) const noexcept{
            
            const double costanteFibonacci = (std::sqrt(5)-1)/2;
            
            unsigned long elem = stringToInt(dato);
            unsigned long parteDecimale = (costanteFibonacci * elem) - std::floor(costanteFibonacci * elem);

            return parteDecimale;
            
        }

    protected:
        unsigned long stringToInt(const std::string& dato) const noexcept{
            
            unsigned long code = 5381;
            for(unsigned long i = 0; i < dato.length(); i++)
                code += (code << 5) + dato[i];
        
            return code;
        
        }


};


}
