
#include "ItemType.h"


ItemType::ItemType() {}
ItemType::~ItemType() {}

string ItemType::GetType() { return type; }
string ItemType::GetName() { return name; }
string ItemType::GetProducer() { return producer; }
string ItemType::GetSinger() { return singer; }
string ItemType::GetJanre() { return janre; }
string ItemType::GetId() { return id; }
int ItemType::GetnumPlay() { return numPlay; }
int ItemType::GetinTime() { return inTime; }


void ItemType::SetType(string inType) { type = inType; }
void ItemType::SetName(string inName) { name = inName; }
void ItemType::SetProducer(string inProducer) { producer = inProducer; }
void ItemType::SetSinger(string inSinger) { singer = inSinger; }
void ItemType::SetJanre(string inJanre) { janre = inJanre; }
void ItemType::SetId(string inId) { id = inId; }
void ItemType::SetnumPlay(int _numPlay) { numPlay = _numPlay; }
void ItemType::SetinTime(int _inTime) { inTime = _inTime; }


void ItemType::SetRecord(string inType, string inName, string inProducer,
	string inSinger, string inJanre, string inId)
{
	SetType(inType);
	SetName(inName);
	SetProducer(inProducer);
	SetSinger(inSinger);
	SetJanre(inJanre);
	SetId(inId);
}

void ItemType::DisplayType() { cout << "TYPE : " << type << endl; }
void ItemType::DisplayName() { cout << "NAME : " << name << endl; }
void ItemType::DisplayProducer() { cout << "PRODUCER : " << producer << endl; }
void ItemType::DisplaySinger() { cout << "SINGER : " << singer << endl; }
void ItemType::DisplayJanre() { cout << "JANRE : " << janre << endl; }
void ItemType::DisplayId() { cout << "ID : " << id << endl; }
void ItemType::DisplaynumPlay() { cout << "NUM that song played : " << numPlay << endl; }
void ItemType::DisplayinTime() { cout << "Time that you put song : " << inTime << endl; }


void ItemType::DisplayRecordOnScreen() {
	DisplayType();
	DisplayName();
	DisplayProducer();
	DisplaySinger();
	DisplayJanre();
	DisplayId();

}

void ItemType::DisplayPlaylistOnScreen() {
	DisplayId();
	DisplaynumPlay();
	DisplayinTime();
}
void ItemType::SetTypeFromKB() {
	cout << "TYPE : ";
	cin >> type;
}


void ItemType::SetNameFromKB() {
	cout << "NAME : ";
	cin >> name;

}
void ItemType::SetProducerFromKB() {
	cout << "PRODUCER : ";
	cin >> producer;
}
void ItemType::SetSingerFromKB() {
	cout << "SINGER : ";
	cin >> singer;
}
void ItemType::SetJanreFromKB() {
	cout << "JANRE  : ";
	cin >> janre;
}
void ItemType::SetIdFromKB() {
	cout << "ID : ";
	cin >> id;
}



void ItemType::SetRecordFromKB() {
	SetTypeFromKB();
	SetNameFromKB();
	SetProducerFromKB();
	SetSingerFromKB();
	SetJanreFromKB();
	SetIdFromKB();

}

int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> type >> name >> producer >>
		singer >> janre >> id;
	return 0;
}
int ItemType::WriteDataToFile(ofstream& fout) {


	fout << type << ' ' << name << ' ' << producer << ' ' <<
		singer << ' ' << janre << ' ' << id << endl;
	return 0;
}
bool ItemType::operator==(ItemType& a) {
	if (this->id == a.id) return true;
	else return false;
}

bool ItemType::operator <(ItemType& a) {
	return (this->id < a.id);
}

bool ItemType::operator >(ItemType& a) {
	return (this->id > a.id);
}



bool ItemType::FindSinger(ItemType a) {
	return (a.singer.find(this->singer) != this->singer.npos);
	//찾지 못하면 false 찾으면 true
}
bool ItemType::FindJanre(ItemType a) {
	return (this->janre.find(a.janre) != this->janre.npos);
}

