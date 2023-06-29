#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Exceptions.h"

using namespace std;

struct Modules
{
    string code = "";
    char compul = '/0';
    int dur;

    string toString()
    {
        stringstream ss;
        ss << code << " : "
           << compul << " : "
           << dur << endl;

        return ss.str();
    }
};


void readStudentsfromTXT(string path)
{
    ifstream fileReader(path);

    //Exception handling
    if(fileReader.fail())
    {
        throw FileOpenExceptionStudents();
    }

    stringstream ss;

    string strLine = "";

    while(getline(fileReader, strLine))
    {
        string strNum = "";
        vector<double> pracMarks;
        stringstream ssLine{strLine};
        ssLine >> strNum;
        double dblMark = 0.0;
        while(ssLine >> dblMark)
        {
            pracMarks.push_back(dblMark);

        }

        cout << strNum << " :-> ";
        for(int num : pracMarks)
        {

            cout << num << " ";
        }
        cout << endl;
    }



    fileReader.close();
}






vector<Modules> readModulesfromTXT(string path)
{
    vector<Modules> recVec;

    ifstream fileReader;
    fileReader.open(path);

    //Exception handling
    if(fileReader.fail())
    {
        throw FileOpenExceptionModules();
    }

    string strCode = "";
    char compulsory = '\0';
    int intDuration = 0;

    while(fileReader >> strCode >> compulsory >> intDuration)
    {
        Modules mod;
        mod.code = strCode;
        mod.compul = compulsory;
        mod.dur = intDuration;

        recVec.push_back(mod);
    }

    fileReader.close();

    return recVec;
}


int main()
{
    try
    {
        vector<Modules> recMod =  readModulesfromTXT("data/Modules.txt");
        for(Modules mod : recMod)
        {
            cout << mod.toString() <<endl;
        }

        readStudentsfromTXT("data/Students.txt");
    }
    catch(FileOpenExceptionModules& exp)
    {
        cout << exp.message() << endl;

    }catch(FileOpenExceptionStudents& exp)
    {
        cout << exp.message() << endl;
    }
    return 0;
}

