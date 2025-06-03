#pragma once
#include "Common.h"


const int MAX_COOKIE = 100;

enum ElementType	// 속성
{
	//Fire, Water, Poison, Light, Ground, Ice, Electro, Dark, Wind, Steel, Independent
	불, 물, 독, 빛, 땅, 얼음, 전기, 어둠, 바람, 강철, 무속성
};

enum Rank			// 등급
{
	ANCIENT, BEAST, LEGENDARY, DRAGON, SUPER_EPIC, EPIC, RARE, COMMON
};

class Cookie		// 부모 클래스
{
private:	// protected를 썼으나 타 속성 클래스를 사용할 필요가 없어졌기에 private로 바꾸었다.
	string name;
	ElementType type;
	Rank rank;
	static const map<ElementType, string> elementmap;	// map을 사용하여 속성타입 저장하기
	static const map<Rank, string> rankmap;				// map을 사용하여 등급 저장하기
public:
	Cookie() = default;
	//Cookie() {}
	Cookie(string name, ElementType type, Rank rank) : name(name), type(type), rank(rank) {}
	ElementType GetElementType() const { return type; }
	Rank GetRank() const { return rank; }


public:
	string GetElementString() const;
	string GetRankString() const;
	void ShowCookieInfo() const;		// 같은 이름을 가진 함수를 찾아 사용해라라는 뜻
	/*string ReturnElementType();
	string ReturnRank();*/

};


//class Fire_Cookie : public Cookie	// 불 속성 클래스
//{
//public:
//	Fire_Cookie() {}
//	Fire_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Water_Cookie : public Cookie	// 물 속성 클래스
//{
//public:
//	Water_Cookie() {}
//	Water_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Poison_Cookie : public Cookie	// 독 속성 클래스
//{
//public:
//	Poison_Cookie() {}
//	Poison_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Light_Cookie : public Cookie	// 빛 속성 클래스 
//{
//public:
//	Light_Cookie() {}
//	Light_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Ground_Cookie : public Cookie	// 땅 속성 클래스 
//{
//public:
//	Ground_Cookie() {}
//	Ground_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Ice_Cookie : public Cookie	// 얼음 속성 클래스
//{
//public:
//	Ice_Cookie() {}
//	Ice_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Electro_Cookie : public Cookie	// 전기 속성 클래스
//{
//public:
//	Electro_Cookie() {}
//	Electro_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Dark_Cookie : public Cookie	// 어둠 속성 클래스 
//{
//public:
//	Dark_Cookie() {}
//	Dark_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Wind_Cookie : public Cookie	// 바람 속성 클래스
//{
//public:
//	Wind_Cookie() {}
//	Wind_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Steel_Cookie : public Cookie	// 강철 속성 클래스
//{
//public:
//	Steel_Cookie() {}
//	Steel_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};
//
//class Independent_Cookie : public Cookie	// 무속성 클래스 (그 어떤 속성에도 속하지 않는 클래스)
//{
//public:
//	Independent_Cookie() {}
//	Independent_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
//
//public:
//	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
//	string ReturnElementType() override;
//	string ReturnRank() override;
//
//};




//class GingerBrave :public Cookie		// 자식 클래스, 용감한쿠키
//{
//public:
//	GingerBrave() {}
//	GingerBrave(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {}
//public:
//	void ShowCookieInfo();
//	string ReturnElementType();	// 부모 함수를 재정의(덮어쓰기)를 하여 다시 사용한다는 뜻이다.
//	string ReturnRank();
//
//};