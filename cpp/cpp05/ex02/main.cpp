#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bureaucrat("y",149);
    try
    {
        bureaucrat.decrementGrade();
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<bureaucrat<<std::endl;
    return 0;
}