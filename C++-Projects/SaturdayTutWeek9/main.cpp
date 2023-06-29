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
    char compul = '\0';
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
    if(fileReader.fail())
    {
        throw FileOpenExceptionStudent();
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

    if(fileReader.fail())
    {
        throw FileOpenExceptionModule();
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
    catch(FileOpenExceptionModule& exp)
    {
        string correctName = "";
        cout << exp.message() << endl;
        cout << "Input the correct file name" << endl;
        cin >> correctName;
        vector<Modules> recMod =  readModulesfromTXT(correctName);
        for(Modules mod : recMod)
        {
            cout << mod.toString() <<endl;
        }

    }catch(FileOpenExceptionStudent& exp)
    {
        cout << exp.message() << endl;

    }

    ofstream output("data/End.txt");
    output << "The end\n";
    output.close();


    return 0;
}

