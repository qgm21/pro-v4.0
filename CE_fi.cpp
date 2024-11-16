#include <iostream>
#include <fstream>
using namespace std;

void ceat_file()
{
    string name;
    short set;
    bool iostream = false,fstream = false,unistd_h = false,windows_h = false,cmath = false,conio_h = false;
    cout<<"entre name file : ";
    cin>>name;
    name += ".cpp";
    cout<<"Specify libraries to call, 1 exists, 0 does not exist : "<<endl<<"iostream : ";
    cin>>set;
    if(set == 1)
    {
        iostream = true;
        set= NULL;
    }
    cout<<"fstream : ";
    cin>>set;
    if(set == 1)
    {
        fstream = true;
        set= NULL;
    }
    cout<<"unistd.h : ";
    cin>>set;
    if(set == 1)
    {
        unistd_h = true;
        set= NULL;
    }
    cout<<"windows_h : ";
    cin>>set;
    if(set == 1)
    {
        windows_h = true;
        set= NULL;
    }
    cout<<"cmath : ";
    cin>>set;
    if(set == 1)
    {
        cmath = true;
        set= NULL;
    }
    cout<<"conio_h : ";
    cin>>set;
    if(set == 1)
    {
        conio_h = true;
        set= NULL;
    }
    ofstream filecpp(name);
    if(iostream == true)
    {
        filecpp << "#include <iostream>"<<endl;
    }
    if(fstream== true)
    {
        filecpp << "#include <fstream>"<<endl;
    }
    if(unistd_h == true)
    {
        filecpp << "#include <unistd.h>"<<endl;
    }
    if(windows_h== true)
    {
        filecpp << "#include <windows.h>"<<endl;
    }
    if(cmath == true)
    {
        filecpp << "#include <cmath>"<<endl;
    }
    if(conio_h == true)
    {
        filecpp<<"#include <conit.h>"<<endl;
    }

    filecpp<<"\n\n"<<"using namespace std;\n\n"
           <<"int main()\n"
           <<"{\n"
           <<"\n\n"
           <<"\treturn 0;\n"
           <<"}\n\n";

    filecpp.close();
}