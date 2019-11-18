#pragma once

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class ItemType
{
protected:
	string type;
	string name;
	string producer;
	string singer;
	string janre;
	string id;
	int numPlay = 0;
	int inTime = 0;

public:
	ItemType();
	~ItemType();

	string GetType();
	string GetName();
	string GetProducer();
	string GetSinger();
	string GetJanre();
	string GetId();
	int GetnumPlay();
	int GetinTime();
\
	void SetType(string inType);
	void SetName(string inName);
	void SetProducer(string inProducer);
	void SetSinger(string inSinger);
	void SetJanre(string inJanre);
	void SetId(string inId);
	void SetnumPlay(int _numPlay);
	void SetinTime(int _inTime);

	void SetRecord(string inType, string inName, string inProducer,
		string inSinger, string inJanre, string inId);

	void DisplayType();
	void DisplayName();
	void DisplayProducer();
	void DisplaySinger();
	void DisplayJanre();
	void DisplayId();
	void DisplaynumPlay();
	void DisplayinTime();

	void DisplayRecordOnScreen();
	void DisplayPlaylistOnScreen();

	void SetTypeFromKB();
	void SetNameFromKB();
	void SetProducerFromKB();
	void SetSingerFromKB();
	void SetJanreFromKB();
	void SetIdFromKB();


	void SetRecordFromKB();

	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);
	bool operator==(ItemType& a);
	bool operator <(ItemType& a);
	bool operator >(ItemType& a);

	bool FindSinger(ItemType a);
	bool FindJanre(ItemType a);
};


