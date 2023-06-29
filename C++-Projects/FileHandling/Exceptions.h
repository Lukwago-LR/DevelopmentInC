#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED
#include <string>

class Exceptions
{
    public:
    virtual std::string message() = 0;// pure virtual
};

class FileOpenExceptionModules : public Exceptions
{
public:
    virtual std::string message();
};


class FileOpenExceptionStudents : public Exceptions
{
public:
    virtual std::string message();
};

#endif // EXCEPTIONS_H_INCLUDED
