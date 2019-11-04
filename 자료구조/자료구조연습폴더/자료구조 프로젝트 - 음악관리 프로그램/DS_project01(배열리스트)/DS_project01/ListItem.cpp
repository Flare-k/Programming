#include "ListItem.h"

//===================================================================================
// default constructor
//===================================================================================
ListItem::ListItem()
{ 
	cout << "=====================================" << endl;
	cout << "�ʱ� ����" << endl;
	cout << "���Ǹ���Ʈ�� �ִ�ũ�� : 100" << endl;
	cout << "���� ����Ʈ ���� �̸� : MusicList.txt" << endl;
	cout << "=====================================" << endl << endl;
	MAXSIZE = 100;
	

	m_Array = new ItemType[MAXSIZE];

	MakeEmpty();
	ResetList();

	system("pause");
}

//===================================================================================
// default destructor
//===================================================================================
ListItem::~ListItem()
{ 
	delete [] m_Array;
}

//===================================================================================
// Function	: Check the list upper limit
// Post		: If reached the memory upper limit, return 1. Otherwise, return 0
//===================================================================================
int ListItem::IsFull()
{
	if(m_Length > MAXSIZE - 1)	
		return 1;
	else
		return 0;
}

//===================================================================================
// Function	: Make list empty
// Pre		: None.
// Post		: List is empty.
//===================================================================================
void ListItem::MakeEmpty()
{
	m_Length = 0;
}

//===================================================================================
// Function	: Return the number of records in the list
// Pre		: 
// Post		: return number of records
//===================================================================================
int ListItem::GetLength()
{
	return m_Length;
}

//===================================================================================
// Function	: add a new data to list
// Pre		: data should not be in the list
// Post		: new record in the list, if adding successful then return 1, Otherwise return 0.
//===================================================================================
int ListItem::Add(ItemType data)
{
	int position = -1; // �� �迭�� �ε����� ��Ÿ���� ������ ���� ����
	
	ItemType temp; // �ӽ� ���� ����

	if(IsFull()) // ����Ʈ�� �� á���� Ȯ���Ѵ�.
	{
		cout << "\tAdd Failed: List if Full\n";
		return 0;
	}

	while(position++ != this->m_Length) // �迭�� ������ ������ ������ �ε��� ����
	{
		// �߰��� data�� �����Ͽ� �ֱ����� ������ ��ġ�� ã�´�.
		if(this->m_Array[position].CompareTo(data) == 1) // ������ �̸����� ���� 
		{
		
			temp.CopyRecord(m_Array[position]);
			m_Array[position].CopyRecord(data);
			data.CopyRecord(temp);

		}
		else// ���� ����Ʈ�� �߰��� �����ͺ��� ū ���� ������
		{
			m_Array[m_Length].CopyRecord( data); // ����Ʈ�� ���� �������� �߰��Ѵ�.
		}
	}


	this->m_Length++; // �ϳ��� �߰��Ǿ����Ƿ� ����Ʈ�� ���̸� �÷��ش�.

	return 1;

}

//===================================================================================
// Function	: Delete data record from list
// Pre		: data should be in the list
// Post		: no data in the list. if deleting successful then return 1, Otherwise return 0.
//===================================================================================
int ListItem::Delete(ItemType target)
{
	ItemType data; //�ӽú��� ����

	if(Get(target))
	{
		int prePointer = m_CurPointer;
		while(GetNextItem(data) < GetLength())	//�������� ���������� ��� �̵���Ű�� �ݺ���
		{
			m_Array[prePointer].CopyRecord(data);
			prePointer = m_CurPointer;
		}
		m_Length--;
	}
	else
	{
		cout << "\tNot found record in the list.." << endl;
		return 0;
	}

	return 1;
}

//===================================================================================
// Function	: find to same record using primary key and replace it
// Pre		: list has same record to data
// Post		: record is replaced. if success to replace then return 1, otherwise return 0
//===================================================================================
int ListItem::Replace(ItemType target)
{
	ItemType dummy = target;

	// list���� �˻��� ���(target)�� �˻��� ������ ��ü
	if(Get(dummy))
	{
		m_Array[m_CurPointer] = target;
	}
	else
	{
		cout << "\tNot found record in the list.." << endl;
		return 0;
	}

	return 1;
}

//===================================================================================
// Function	: find the primary key in data from the list and copy the record to data
// Pre		: the key be searched should be data.
// Post		: data holds the copy of the record with the key inputed
//===================================================================================
int ListItem::Get(ItemType& target)
{
	ItemType data; //�ӽú��� ����
	ResetList(); //m_curpointer�� -1��  �ʱ�ȭ
	while(GetNextItem(data) < GetLength())	//�������� ���������� ��� �̵���Ű�� �ݺ���
	{
		if(data.CompareTo(target) == 0)	
		{
			target.CopyRecord(data);
			return 1;	//target�� ������ �ִ��� ����
		}
	}
	return 0;
}

//===================================================================================
// Function	: Initialize the iterator pointer
// Pre		: 
// Post		: iterator pointer is reset
//===================================================================================
void ListItem::ResetList()
{
	m_CurPointer = -1;
}

//===================================================================================
// Function	: update pointer to point to next record and return this new record.
// Pre		: Iterator pointer should not be initialized. 
// Post		: 
//		pointer is updated. 
//		data holds the new record. 
//		If current pointer points to last record, return 1. Otherwise return 0
//===================================================================================
int ListItem::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// Increase list pointer

	if (m_CurPointer == MAXSIZE)	// if end of list then return -1
		return -1;

	data = m_Array[m_CurPointer];	// copy a record of current list pointer to the data

	return m_CurPointer;
}