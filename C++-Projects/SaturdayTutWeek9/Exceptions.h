#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED
#include <string>

class Exceptions
{
public:
   virtual std::string message() = 0;// pure virtual method
};

class FileOpenExceptionModule : public Exceptions
{
public:
    std::string message();
};

class FileOpenExceptionStudent : public Exceptions
{
public:
    std::string message();

};

#endif // EXCEPTIONS_H_INCLUDED
