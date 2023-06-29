#include "Exceptions.h"

using namespace std;

string FileOpenExceptionModule::message()
{
    return "Failed to open module text file";
}

string FileOpenExceptionStudent::message()
{
     return "Failed to open students text file";
}
