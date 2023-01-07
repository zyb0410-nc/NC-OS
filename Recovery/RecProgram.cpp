#include<iostream>
#include<cstring>
#include<fstream>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
//Data
string Mode;
//Functions
void CleanScreen()
{
    system("clear");
}
string NRead(string path)
{
    ifstream in;
    in.open(path);
    string out;
    in >> out;
    return out;
}
void NWrite(string path,string text)
{
    ofstream write(path);
    write << text;
}
void Shutdown()
{
    exit(0);
}
void ReBoot()
{
    exit(0);
    system("./OS");
}

int main()
{
    Mode = NRead("Recovery/Rec.nsf");
    if(Mode == "ResetTheOS")
    {
        NWrite("System/OS/Start.nsf","False");
        system("rm -r Data/Users/*");
        system("touch Data/Users/UserInfo.nsf Data/Users/SelectUser.nsf");
        cout << "Reopen the OS ...";
        Shutdown();
    }
    return 0;
}