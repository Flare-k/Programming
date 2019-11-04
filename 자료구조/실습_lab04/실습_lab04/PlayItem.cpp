#include "PlayItem.h"


// '=='를 가능하게 하는 연산자 오버로딩
bool PlayItem::operator==(const PlayItem& data) const {
    if(this->primary == data.GetPrimary())
        return true;
    else
        return false;
}
// '!='를 가능하게 하는 연산자 오버로딩
bool PlayItem::operator!=(const PlayItem& data) const {
    if(this->primary != data.GetPrimary())
        return true;
    else
        return false;
}


// 비교연산자 오버로딩 ' > '
bool PlayItem::operator>(const PlayItem& data) const {
    if(this->primary > data.GetPrimary())
        return true;
    else
        return false;
}

// 비교연산자 오버로딩 ' < '
bool PlayItem::operator<(const PlayItem& data) const {
    if(this->primary < data.GetPrimary())
        return true;
    else
        return false;
}
