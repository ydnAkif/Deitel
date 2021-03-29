#include <string>

#ifndef CREATE_HPP
#define CREATE_HPP

class CreateAndDestroy
{
private:
    int objectID;
    std::string message;

public:
    CreateAndDestroy(int, std::string);
    ~CreateAndDestroy();
};

#endif