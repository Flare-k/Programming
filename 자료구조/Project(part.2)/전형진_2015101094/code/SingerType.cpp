#include "SingerType.h"

int SingerType::getAge() const {return s_Age;}
string SingerType::getName() const {return s_Name;}
string SingerType::getGender() const {return s_Gender;}
string SingerType::getPicture() const {return s_Picture;}
string SingerType::getBorn() const {return s_Born;}
string SingerType::getDebut() const {return s_Debut;}

void SingerType::setAge(int age){s_Age = age;}
void SingerType::setName(string name){s_Name =name;}
void SingerType::setGender(string gender){s_Gender = gender;}
void SingerType::setPicture(string picture){s_Picture=picture;}
void SingerType::setDebut(string debut){s_Debut = debut;}
void SingerType::setborn(string born){s_Born = born;}

void SingerType::addSong(SingerSong item)
{
    s_SongList.Add(item);
}

void SingerType::deleteSong(SingerSong item)
{
    s_SongList.Delete(item);
}

bool SingerType::operator==(const SingerType& temp)
{
    return s_Name ==temp.getName();
}

int SingerType::ReadDataFromFile(ifstream& fin) {
    if (fin.is_open()) {
        fin >> s_Name >> s_Age >> s_Gender >> s_Debut >> s_Born >> s_Picture;
        return 1;
    }
    return 0;
}
int SingerType::WriteDataToFile(ofstream& fout) {
    if (fout.is_open()) {
        fout << s_Name << '\t' << s_Age << '\t' << s_Gender << '\t'
             << s_Debut << '\t' << s_Born << '\t' << s_Picture << endl;
        return 1;
    }
    return 0;
}
