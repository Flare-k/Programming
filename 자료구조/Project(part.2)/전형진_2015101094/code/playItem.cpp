#include "playItem.h"

playItem::playItem(int inId) : p_Id(inId),p_numPlay(0), p_Intime(0) {}
playItem::playItem(): p_numPlay(0), p_Intime(0){}

int playItem::getId(){return p_Id;}

void playItem::setId(int inId){p_Id = inId;}

void playItem::setNum(int inNum){p_numPlay = inNum;}

void playItem::setTime(int inTime){p_Intime = inTime;}


bool playItem::operator==(playItem temp)
{
	return (this->getId() == temp.getId());
}


bool playItem::operator>(playItem temp)
{
    return (this->getId() > temp.getId());
}


bool playItem::operator<(playItem temp)
{
    return (this->getId() < temp.getId());
}


int playItem::ReadDataFromFile(ifstream& fin) {
    if (fin.is_open()) {
        fin>> p_Id >> p_numPlay >> p_Intime;
        return 1;
    }
    return 0;
}

int playItem::WriteDataToFile(ofstream& fout) {
    if (fout.is_open()) {
        fout << p_Id << '\t' << p_numPlay << '\t' << p_Intime <<endl;
        return 1;
    }
    return 0;
}
