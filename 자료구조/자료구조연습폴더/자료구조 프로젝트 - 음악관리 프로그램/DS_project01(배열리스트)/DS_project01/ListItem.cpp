#include "ListItem.h"

//===================================================================================
// default constructor
//===================================================================================
ListItem::ListItem()
{ 
	cout << "=====================================" << endl;
	cout << "초기 설정" << endl;
	cout << "음악리스트의 최대크기 : 100" << endl;
	cout << "음악 리스트 파일 이름 : MusicList.txt" << endl;
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
	int position = -1; // 각 배열의 인덱스를 나타내는 정수형 변수 생성
	
	ItemType temp; // 임시 변수 생성

	if(IsFull()) // 리스트가 꽉 찼는지 확인한다.
	{
		cout << "\tAdd Failed: List if Full\n";
		return 0;
	}

	while(position++ != this->m_Length) // 배열의 끝까지 도달할 때까지 인덱스 증가
	{
		// 추가할 data를 정렬하여 넣기위해 적당한 위치를 찾는다.
		if(this->m_Array[position].CompareTo(data) == 1) // 음악의 이름으로 정렬 
		{
		
			temp.CopyRecord(m_Array[position]);
			m_Array[position].CopyRecord(data);
			data.CopyRecord(temp);

		}
		else// 기존 리스트에 추가할 데이터보다 큰 값이 없으면
		{
			m_Array[m_Length].CopyRecord( data); // 리스트의 가장 마지막에 추가한다.
		}
	}


	this->m_Length++; // 하나가 추가되었으므로 리스트의 길이를 늘려준다.

	return 1;

}

//===================================================================================
// Function	: Delete data record from list
// Pre		: data should be in the list
// Post		: no data in the list. if deleting successful then return 1, Otherwise return 0.
//===================================================================================
int ListItem::Delete(ItemType target)
{
	ItemType data; //임시변수 생성

	if(Get(target))
	{
		int prePointer = m_CurPointer;
		while(GetNextItem(data) < GetLength())	//아이템을 마지막까지 계속 이동시키는 반복문
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

	// list에서 검색할 대상(target)을 검색해 있으면 대체
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
	ItemType data; //임시변수 생성
	ResetList(); //m_curpointer를 -1로  초기화
	while(GetNextItem(data) < GetLength())	//아이템을 마지막까지 계속 이동시키는 반복문
	{
		if(data.CompareTo(target) == 0)	
		{
			target.CopyRecord(data);
			return 1;	//target과 같은게 있는지 비교함
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