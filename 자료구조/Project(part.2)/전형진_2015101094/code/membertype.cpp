#include "membertype.h"

memberType::memberType(){}
memberType::memberType(string in_id, string in_password): u_id(in_id),u_password(in_password){}
string memberType::getId(){return u_id;}
string memberType::getPw(){return u_password;}

int memberType::ReadDataFromFile(ifstream &fin)
{

    if (fin.is_open())
    {
        fin >> u_id >> u_password;
        return 1;
    }
    return 0;
}

int memberType::WriteDataToFile(ofstream &fout)
{
    if (fout.is_open())
    {
        fout << u_id << '\t' <<u_password<<endl;
        return 1;
    }
        return 0;
}


bool memberType::operator==(memberType temp)
{
    return this->u_id == temp.getId();
}

void memberType::setRecord(string in_id, string in_pw)
{
    u_id = in_id;
    u_password = in_pw;
}

void memberType::setId(string in_id)
{
    u_id =in_id;
}

void memberType::setPw(string in_pw)
{
    u_password = in_pw;
}
