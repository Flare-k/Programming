#ifndef _LISTITEM_
#define _LISTITEM_

#include <iostream>
#include <string>
#include "ItemType.h"
using namespace std;



class ListItem {
private:
	int m_Length;
	int MAXSIZE;
	int m_CurPointer;
	ItemType* m_Array;

public:
	ListItem();
	~ListItem();

	//===================================================================================
	// Function	: Check the list upper limit
	// Post		: If reached the memory upper limit, return 1. Otherwise, return 0
	//===================================================================================
	int IsFull();

	//===================================================================================
	// Function	: Make list empty
	// Pre		: None.
	// Post		: List is empty.
	//===================================================================================
	void MakeEmpty();

	//===================================================================================
	// Function	: Return the number of records in the list
	// Pre		: none
	// Post		: return number of records
	//===================================================================================
	int GetLength();

	//===================================================================================
	// Function	: add a new data to list
	// Pre		: data should not be in the list
	// Post		: new record in the list. if adding successful then return 1, Otherwise return 0.
	//===================================================================================
	int Add(ItemType data);

	//===================================================================================
	// Function	: Delete data record from list
	// Pre		: data should be in the list
	// Post		: no data in the list. if deleting successful then return 1, Otherwise return 0.
	//===================================================================================
	int Delete(ItemType data);

	//===================================================================================
	// Function	: find to same record using primary key and replace it
	// Pre		: list has same record to data
	// Post		: record is replaced. if success to replace then return 1, otherwise return 0
	//===================================================================================
	int Replace(ItemType data);

	//===================================================================================
	// Function	: find the primary key in data from the list and copy the record to data
	// Pre		: the key be searched should be data.
	// Post		: data holds the copy of the record with the key inputed
	//===================================================================================
	int Get(ItemType& data);

	//===================================================================================
	// Function	: Initialize the iterator pointer
	// Pre		: none
	// Post		: iterator pointer is reset
	//===================================================================================
	void ResetList();

	//===================================================================================
	// Function	: update pointer to point to next record and return this new record.
	// Pre		: Iterator pointer should not be initialized. 
	// Post		: 
	//		pointer is updated. 
	//		data holds the new record. 
	//		If current pointer points to last record, return 1. Otherwise return 0
	//===================================================================================
	int GetNextItem(ItemType& data);

};


#endif