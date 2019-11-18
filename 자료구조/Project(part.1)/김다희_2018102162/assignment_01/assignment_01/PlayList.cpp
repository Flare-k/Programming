#include"PlayList.h"


void PlayList::AddPlayList(PlayItem data) {
	if (m_PlayArray.IsFull() != true) {
		data.setInTime(listInTime);
		listInTime++;
		m_PlayArray.Add(data);
		return;
	}
	else {
		cout << "\t* 더 이상 추가할 수 없습니다!" << endl;
		return;
	}
}


int PlayList::DeleteItem(PlayItem item) {
	if (m_PlayArray.Delete(item) == 1) {
		return 1;
	}
	return 0;
}

void PlayList::PrintAll() {
	DoublyIterator<PlayItem> itor(m_PlayArray);
	cout << "\n\t<<========= Current list =========>>" << endl;
	while (true) {
		PlayItem item = itor.Next();
		if (!itor.NextNotNull()) break;
		item.AddNumPlay();
		ItemType data;
		data.SetId(item.getId());
		m_List.Retrieve(data);
		data.DisplayRecordOnScreen();
	}
	cout << "\t<<================================>>" << endl;
}

void PlayList::PrintByFreq() {
	SetMaxPlayNum();
	int temp = maxPlayNum;
	cout << "\n\t<<========= Current list =========>>" << endl;
	while (true) {
		DoublyIterator<PlayItem> itor(m_PlayArray);
		while (true) {
			PlayItem item = itor.Next();
			if (!itor.NextNotNull()) break;
			if (item.getNumPlay() == temp) {
				item.AddNumPlay();
				ItemType data;
				data.SetId(item.getId());
				m_List.Retrieve(data);
				data.DisplayRecordOnScreen();
			}
		}
		temp--;
		if (temp == -2) break;
	}
	cout << "\t<<================================>>" << endl;
}

void PlayList::SetMaxPlayNum() {
	DoublyIterator<PlayItem> itor(m_PlayArray);
	int temp = 0;
	while (true) {
		PlayItem item = itor.Next();
		if (!itor.NextNotNull()) break;
		if (temp < item.getNumPlay()) {
			temp = item.getNumPlay();
		}
	}
	maxPlayNum = temp;
}
