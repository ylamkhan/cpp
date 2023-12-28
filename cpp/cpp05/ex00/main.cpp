#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("y",149);
        std::cout<<bureaucrat<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }

    return 0;
}