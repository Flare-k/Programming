#pragma once
//=====================================================
//		## SingletonBase ## (이 베이스로 싱글톤을 만든다)
//=====================================================

template <typename T>
class SingletonBase
{
protected:
	//싱글톤 인스턴스 선언
	static T* singleton;

	SingletonBase() {};
	~SingletonBase() {};

public:
	//싱글톤 객체 가져오기
	static T* getSingleton();
	//싱글톤 객체 메모리에서 해제하기
	void releaseSingleton();
};

//싱글톤 인스턴스 선언
template <typename T>
T* SingletonBase<T>::singleton = 0;

//싱글톤 객체 가져오기
template <typename T>
T* SingletonBase<T>::getSingleton()
{
	//싱글톤 객체가 없으면 새로 생성하기
	if (!singleton) singleton = new T;

	return singleton;
}

//싱글톤 객체 메모리에서 해제하기
template <typename T>
void SingletonBase<T>::releaseSingleton()
{
	//싱글톤 객체가 있다면 메모리에서 해제
	if (singleton)
	{
		delete singleton;
		singleton = 0;
	}
}
