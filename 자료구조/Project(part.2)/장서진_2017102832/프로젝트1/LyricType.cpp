#include "LyricType.h"

string LyricType::GetName()
{
	return name;
}

string LyricType::GetLyric()
{
	return lyric;
}

void LyricType::SetName(string m_Name)
{
	name = m_Name;
}

void LyricType::SetLyric(string m_Lyric)
{
	lyric = m_Lyric;
}

void LyricType::SetNamePLByKB()
{
	cout << "\t°î ¸íÀ» ÀÔ·ÂÇÏ¼¼¿ä: ";
	cin >> name;
}

void LyricType::DisplayPLNameOnScreen()
{
	cout << "\t°î ¸í: " << GetName() << endl;
}

void LyricType::DisplayPLLyricOnScreen()
{
	cout << GetLyric() << endl;
}

void LyricType::DisplayNameLyricOnScreen()
{
	DisplayPLNameOnScreen();
	DisplayPLLyricOnScreen();
}

int LyricType::ReadDataFromFile(ifstream& fin)
{
	fin >> lyric;
	return 0;
}

RelationType LyricType::ComparePLByName(const LyricType& data)
{
	if (this->name > data.name)
		return GREATER;
	else if (this->name < data.name)
		return LESS;
	else
		return EQUAL;
}