#pragma once
#include"Base.h"
#include"DoublySortedLinkedList.h"
#include <iostream>
#include "ArtistType.h"
using namespace std;


class ArtistList : public Base {
public:
	ArtistList() {}
	void AddArtist(ArtistType item) {
		item.setArtistAgeFromKB();
		item.setArtistGenderFromKB();
		artistArray.Add(item);
	}
	void AddSong(ItemType item) {
		ArtistType adding;
		SimpleItemType newItem;
		newItem.setRecord(item.GetId(), item.GetTitle());
		adding.setArtistName(item.GetArtist());
		int find = artistArray.Get(adding);
		if (find == 0) {
			adding.Add(newItem);
			cout << "\t* 새로운 아티스트의 음악입니다. 정보를 입력해주세요. " << endl;
			AddArtist(adding);
			return;
		}
		else {
			FindAndAddSong(adding, newItem);
		}
	}
	void FindAndAddSong(ArtistType artist, SimpleItemType item) {
		DoublyIterator<ArtistType> itor(artistArray);
		while (true) {
			ArtistType compare = itor.Next();
			if (!itor.NextNotNull()) break;
			if (compare == artist) {
				itor.GetCurrentNode()->data.Add(item);
				break;
			}
		}
	}

	int Get(ArtistType &item) {
		if (artistArray.Get(item) == 1) {
			return 1;
		}
		return 0;
	}

private:
	DoublySortedLinkedList<ArtistType> artistArray;
};



	/**
	*	@brief	싱글링크드리스트 안에서 해당하는 name가진 아이템을 찾고 그 아이템의 list에 adding추가.
	*	@pre	해당하는 name을 가진 아이템이 이미 존재한다고 가정.
	*	@post	해당 name을 가진 아이템의 리스트에 새로운 노래가 추가된다.
	*	@param	item	찾을 name을 가진 item	adding	추가할 노래
	*	@return none
	*/
//	void FindAndAdd(ArtistType item, SimpleItemType adding);


