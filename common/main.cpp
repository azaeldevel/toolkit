#include <iostream>

#include "common.hpp"
//#include "version.tab.h"

int main()
{
    

	std::cout << toolkit::getPakageName() << " v" << toolkit::getPakageVersion().toString()<<std::endl;
#ifdef COLLETION_ASSISTANT
        std::cout<< "El asistente de recoleccion esta activo."<<std::endl;
#endif
        
}
