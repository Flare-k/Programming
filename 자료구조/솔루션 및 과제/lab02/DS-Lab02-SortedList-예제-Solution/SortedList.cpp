#include "SortedList.h"


// Make list empty.
void SortedList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int SortedList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool SortedList::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// Initialize list iterator.
void SortedList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int SortedList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == m_Length)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}



// search item by using primary key

int SortedList::Add(ItemType inData)
{
	// List가 꽉 차있는 경우 0을 리턴
	if (IsFull()) return 0;
	// List가 비어 있으면 
	if (m_Length == 0) {
		//맨 앞에 삽입, length 증가, 1을 리턴
		m_Array[m_Length++] = inData;
		return 1;
	}
	// 새 항목의 삽입 위치 iPos를 검색
	bool found = false;
	int iPos = 0;
	while (!found && iPos < m_Length) {
		switch (m_Array[iPos].Compare(inData))
		{
		case EQUAL:
		//	cout << " %%% same item exist in the list %%%\n";
			return 0;
		case GREATER:
			found = true;
			break;
		case LESS:
			iPos++;
			break;
		}
	}
	//iPos==length이면
	if (iPos == m_Length) {
		// 인덱스 length에 추가, length++, 1리턴
		m_Array[iPos] = inData;
		m_Length++;
		return 1;
	}
	// iPost<length이면 iPos부터 length-1 사이의 모든 항목을 뒤로 한 칸씩 이동
	for (int i = m_Length; i > iPos; i--)
		m_Array[i] = m_Array[i - 1];
	// iPos에 추가,
	m_Array[iPos] = inData;
	// Length++, 1리턴
	m_Length++;
	return 1;
}



/*
// add a new data into list.
int SortedList::Add(ItemType inData)
{
	if(!IsFull())
	{
		ItemType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while(m_CurPointer<=m_Length) //처음부터 끝까지
		{
			if(CurItem.Compare(inData)==GREATER || m_CurPointer==m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				for(int i=m_Length;i>m_CurPointer;i--)	//맨뒤에서 부터 하나씩 땡긴다.
					m_Array[i]=m_Array[i-1];	//배열 밀기
				m_Array[m_CurPointer]=inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			GetNextItem(CurItem);	//다음아이템으로
		}
	}
	else
		return 0;

	return 1;
}
*/



//Primary key가 일치하는 item을 찾아서 반환함
int SortedList::Retrieve_SeqS(ItemType& data)
{
	// curPos를 첫번째 항목을 가리키도록 세팅
	int curPos = 0;
	// List를 차례대로 방문하면서 data의 Key와 일치하는 항목을 찾는다.
	for (; curPos < m_Length && m_Array[curPos].Compare(data) == LESS; curPos++);
	// curPos의 항목의 key가 data의 Key와 일치 하는 경우
	if (m_Array[curPos].Compare(data) == EQUAL)
	{
		data = m_Array[curPos];
		return 1;
	}
	else // key가 data의 Key보다 크거나 curPos가 맨 끝네 도달하는 경우
		return 0;
}

/*
//Primary key가 일치하는 item을 찾아서 반환함
int SortedList::Retrieve_SeqS(ItemType& data)
{
	ItemType CurItem;
	
	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while(m_CurPointer<m_Length)	//처음부터 끝까지
	{
		switch(CurItem.Compare(data))	//입력 아이템과 현재 아이템을 비교
		{
		case EQUAL:	//일치하면
			data=CurItem;	//data에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 Primary key가 더 크면(정렬되있으므로 나머지에 찾는게 없다)
			return 0;	//실패(0)을 리턴
			break;
		default:	//현재 아이템의 Primary key가 더 작으면
			GetNextItem(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
			break;
		}
	}
	return 0; //실패시0
}

*/

//Primary key가 일치하는 item을 찾아서 제거함
int SortedList::Delete(ItemType data)
{
	if(Retrieve_SeqS(data))	//Primary key가 일치하는 item을 발견한다면(1)
	{
		for(int i=m_CurPointer;i<m_Length;i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i]=m_Array[i+1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//Primary key일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

