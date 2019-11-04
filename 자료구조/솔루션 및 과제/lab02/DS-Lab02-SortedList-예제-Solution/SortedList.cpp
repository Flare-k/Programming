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
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == m_Length)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}



// search item by using primary key

int SortedList::Add(ItemType inData)
{
	// List�� �� ���ִ� ��� 0�� ����
	if (IsFull()) return 0;
	// List�� ��� ������ 
	if (m_Length == 0) {
		//�� �տ� ����, length ����, 1�� ����
		m_Array[m_Length++] = inData;
		return 1;
	}
	// �� �׸��� ���� ��ġ iPos�� �˻�
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
	//iPos==length�̸�
	if (iPos == m_Length) {
		// �ε��� length�� �߰�, length++, 1����
		m_Array[iPos] = inData;
		m_Length++;
		return 1;
	}
	// iPost<length�̸� iPos���� length-1 ������ ��� �׸��� �ڷ� �� ĭ�� �̵�
	for (int i = m_Length; i > iPos; i--)
		m_Array[i] = m_Array[i - 1];
	// iPos�� �߰�,
	m_Array[iPos] = inData;
	// Length++, 1����
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

		while(m_CurPointer<=m_Length) //ó������ ������
		{
			if(CurItem.Compare(inData)==GREATER || m_CurPointer==m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for(int i=m_Length;i>m_CurPointer;i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i]=m_Array[i-1];	//�迭 �б�
				m_Array[m_CurPointer]=inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextItem(CurItem);	//��������������
		}
	}
	else
		return 0;

	return 1;
}
*/



//Primary key�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
int SortedList::Retrieve_SeqS(ItemType& data)
{
	// curPos�� ù��° �׸��� ����Ű���� ����
	int curPos = 0;
	// List�� ���ʴ�� �湮�ϸ鼭 data�� Key�� ��ġ�ϴ� �׸��� ã�´�.
	for (; curPos < m_Length && m_Array[curPos].Compare(data) == LESS; curPos++);
	// curPos�� �׸��� key�� data�� Key�� ��ġ �ϴ� ���
	if (m_Array[curPos].Compare(data) == EQUAL)
	{
		data = m_Array[curPos];
		return 1;
	}
	else // key�� data�� Key���� ũ�ų� curPos�� �� ���� �����ϴ� ���
		return 0;
}

/*
//Primary key�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
int SortedList::Retrieve_SeqS(ItemType& data)
{
	ItemType CurItem;
	
	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while(m_CurPointer<m_Length)	//ó������ ������
	{
		switch(CurItem.Compare(data))	//�Է� �����۰� ���� �������� ��
		{
		case EQUAL:	//��ġ�ϸ�
			data=CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� Primary key�� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return 0;	//����(0)�� ����
			break;
		default:	//���� �������� Primary key�� �� ������
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
			break;
		}
	}
	return 0; //���н�0
}

*/

//Primary key�� ��ġ�ϴ� item�� ã�Ƽ� ������
int SortedList::Delete(ItemType data)
{
	if(Retrieve_SeqS(data))	//Primary key�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for(int i=m_CurPointer;i<m_Length;i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i]=m_Array[i+1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//Primary key��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

