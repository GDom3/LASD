
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */


template <> class Hashable<int>{
    public :
        double operator()(const int& dato ) const noexcept{
            const double costanteFibonacci = (std::sqrt(5)-1)/2;
            
            double parteDecimale = (costanteFibonacci * dato * (dato*3)/2) - std::floor(costanteFibonacci * dato * (dato*3)/2);
            
            return parteDecimale;
        }

        double hashDue(const int& dato ) const noexcept{
            const double costanteMia = (M_E)/(std::sqrt(5) * M_PI);

            double parteDecimale = (costanteMia * dato * (dato*3)/2) - std::floor(costanteMia * dato * (dato*3)/2);
            
            return parteDecimale;
        }

};

template <> class Hashable<double>{
    public :
       
        double operator()(const double& dato ) const noexcept{
            const double costanteFibonacci = (std::sqrt(5)-1)/2;

            double parteDecimale = (costanteFibonacci * dato) - std::floor(costanteFibonacci * dato);
          
            return parteDecimale; 
        }

        double hashDue(const double& dato ) const noexcept{
            const double costanteMia = (M_E)/(std::sqrt(5) * M_PI);

            double parteDecimale = (costanteMia * dato) - std::floor(costanteMia * dato);
          
            return parteDecimale; 
        }

};

template <> class Hashable<std::string>{
    public :
        double operator()(const std::string& dato ) const noexcept{
            
            const double costanteFibonacci = (std::sqrt(5)-1)/2;
            
            unsigned long elem = stringToInt(dato);
            double parteDecimale = (costanteFibonacci * elem) - std::floor(costanteFibonacci * elem);

            return parteDecimale;
            
        }

        double hashDue(const std::string& dato ) const noexcept{
            
            const double costanteMia = (M_E)/(std::sqrt(5) * M_PI);
            
            unsigned long elem = stringToInt(dato);
            double parteDecimale = (costanteMia * elem) - std::floor(costanteMia * elem);

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
