#include "PlayType.h"

string PlayType::GetName()
{
	return name;
}

void PlayType::SetName(string m_Name)
{
	name = m_Name;
}

void PlayType::SetNamePLByKB()
{
	cout << "\t�� ���� �Է��ϼ���: ";
	cin >> name;
}

void PlayType::DisplayPLNameOnScreen()
{
	cout << "\t�� ��: " << GetName() << endl;
}

RelationType PlayType::ComparePLByName(const PlayType& data)
{
	if (this->name > data.name)
		return GREATER;
	else if (this->name < data.name)
		return LESS;
	else
		return EQUAL;
}