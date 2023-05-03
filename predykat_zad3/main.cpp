#include <iostream>
#include "function.h"

int main()
{
    std::string input{"ab caaaaaaaaaaaaaaaaaaaadadsflkj d asdfadadadsaacbac ba"};
    std::string stringToCut{"ab c"};
    std::string output = getReduced(input, &isGivenStringToCut, stringToCut);
    std::cout<<"OUTPUT: "<< output<<std::endl;

    return 0;
}
