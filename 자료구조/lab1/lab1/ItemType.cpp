#include "ItemType.h"

//ItemType 클래스


    void ItemType::SetIdFromKB(){//clear
        cout<<"\t ID: ";
        cin>>m_Id;
    }
    void ItemType::SetNameFromKB(){//clear
        cout<<"\t Name: ";
        cin>>m_sName;
    }
    void ItemType::SetAddressFromKB(){//clear
        cout<<"\t Address: ";
        cin>>m_sAddress;
    }
    void ItemType::SetRecordFromKB(){//clear
        SetIdFromKB();
        SetNameFromKB();
        SetAddressFromKB();
    }
    int ItemType::ReadDataFromFile(ifstream& fin){      //객체를 파일로부터 읽어온다.
        fin>>m_Id>>m_sName>>m_sAddress;
        return 1;
    }
    int ItemType::WriteDataToFile(ofstream& fout){      //객체를 파일에 저장해준다.
        fout<<m_Id<<" ";
        fout<<m_sName<<" ";
        fout<<m_sAddress;
        fout<<endl;
        //fout<<endl;을 여기다 쓰면 읽을 때, 맨 마지막 줄엔 아무것도 없어서 마지막 줄을 한번 더 읽는 것 같다. (질문!!!!!!!!!!!!!!!)
        //한줄 안띄고 그냥 임의로 텍스트 파일을 만든걸 읽는건 문제가 되질 않는다.
        //fout<<endl;를 마지막에 쓴걸 텍스트 파일에 가서 확인하면 맨마지막 빈줄에 커서가 위치해 있다. 
        
        return 1;
    }

//이 부분은 솔루션 참고했음.
    RelationType ItemType::CompareByID(const ItemType &data){    // primary key (ID)를 기준으로 학생 정보를 비교하는 함수
        if(this->m_Id > data.m_Id)
            return GREATER;
        else if(this->m_Id < data.m_Id)
            return LESS;
        else
            return EQUAL;
    }
    //더 Generic하게 하려면 ItemType class에 비교연산자를 오버로딩하면 된다.

//Get함수를 위해서 여기서 연산자 오버로딩을 만들어줘야 Generic하다고 할 수 있다.
bool ItemType::operator==(const ItemType& data) const {
    if(this->m_Id == data.GetId())
        return true;
    else
        return false;
    return 1;
    }
