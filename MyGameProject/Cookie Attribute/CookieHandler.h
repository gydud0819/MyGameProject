#pragma once
#include "Cookie.h"
#include <vector>
using namespace std;

enum ElementType	// 속성
{
	//Fire, Water, Poison, Light, Ground, Ice, Electro, Dark, Wind, Steel, Independent
	불, 물, 독, 빛, 땅, 얼음, 전기, 어둠, 바람, 강철, 무속성
};

enum Rank			// 등급
{
	ANCIENT, BEAST, LEGENDARY, DRAGON, SUPER_EPIC, EPIC, RARE, COMMON
};

class CookieHandler	// 쿠키 정보를 저장하는 클래스 
{
private:
	string name;
	ElementType type;
	Rank rank;
public:
	CookieHandler(string name, ElementType type, Rank rank)	// 생성자 초기화하기
		: name(name), type(type), rank(rank) { }
	string GetName() const { return name; }	// 이름 반환, private라서 직접 못 쓰기 때문에 return으로 복사해서 전달해준다
	ElementType GetType() const { return type; }	// 위와 같다.
	Rank GetRank() const { return rank; }	// 위와 같다. 
};

class CookieMaker
{
private:
	vector<CookieHandler> cookieDataTable;
	vector<CookieHandler> Fire_Cookie;
	vector<CookieHandler> Water_Cookie;
	vector<CookieHandler> Posion_Cookie;
	vector<CookieHandler> Light_Cookie;
	vector<CookieHandler> Ground_Cookie;
	vector<CookieHandler> Ice_Cookie;
	vector<CookieHandler> Electro_Cookie;
	vector<CookieHandler> Dark_Cookie;
	vector<CookieHandler> Wind_Cookie;
	vector<CookieHandler> Steel_Cookie;
	vector<CookieHandler> Independent_Cookie;
public:
	CookieMaker()
	{
		cookieDataTable =
		{
			CookieHandler("서리여왕 쿠키", ElementType::얼음, Rank::LEGENDARY),
			CookieHandler("불꽃정령 쿠키", ElementType::불, Rank::LEGENDARY),
			CookieHandler("달빛술사 쿠키", ElementType::얼음, Rank::LEGENDARY),
			CookieHandler("바람궁수 쿠키", ElementType::바람, Rank::LEGENDARY),
			CookieHandler("어둠마녀 쿠키", ElementType::어둠, Rank::LEGENDARY),
		};
		// cookieDataTable의 각 요소(CookieHandler 객체)를 참조로 받아옴
        // 참조를 사용하면 복사 없이 원본 객체를 직접 사용할 수 있어 성능상 이점이 있음
		for (const auto& elem : cookieDataTable)
		{
			SetCookie(elem);
		}
	}

	void SetCookie(const CookieHandler& cookie)
	{
		if (cookie.GetType() == ElementType::불)
			Fire_Cookie.push_back(cookie);		// 새로운 요소를 맨 뒤에 추가할 때 사용하는 함수로 emplace_back()보다 사용하는게 좀 더 나음

		if (cookie.GetType() == ElementType::물)
			Water_Cookie.push_back(cookie);

		if (cookie.GetType() == ElementType::얼음)
			Ice_Cookie.push_back(cookie);

		if (cookie.GetType() == ElementType::바람)
			Wind_Cookie.push_back(cookie);

		if (cookie.GetType() == ElementType::어둠)
			Dark_Cookie.push_back(cookie);
	}

	void AddCookie()
	{
		std::string _name;
		ElementType _type;
		Rank _rank;
		int typeCount;
		int rankCount;
		
		std::cout << "Name를 입력해주세요." << std::endl;
		std::cin >> _name;
		std::cout << "타입을 입력해주세요." << std::endl;
		std::cin >> typeCount;
		std::cin >> rankCount;
		

		switch (typeCount)
		{
		case 0: _type = ElementType::불;
			break;
		case 1: _type = ElementType::물;
			break;
		case 2: _type = ElementType::얼음;
			break;
		case 3: _type = ElementType::바람;
			break;
		case 4: _type = ElementType::어둠;
			break;
		default: _type = ElementType::무속성;
			break;
		}

		switch (rankCount) 
		{
		case 0: _rank = Rank::ANCIENT; break;
		case 1: _rank = Rank::BEAST; break;
		case 2: _rank = Rank::LEGENDARY; break;
		case 3: _rank = Rank::DRAGON; break;
		case 4: _rank = Rank::SUPER_EPIC; break;
		case 5: _rank = Rank::EPIC; break;
		case 6: _rank = Rank::RARE; break;
		default: _rank = Rank:: COMMON; break;
		}

		// 새로운 쿠키 객체를 만들거나 추가한다. 
		CookieHandler addCookie(_name, _type, _rank);
		cookieDataTable.push_back(addCookie);
		SetCookie(addCookie);	// 속성별로 벡터에도 추가해줘야한다.
	}

	void ShowCookieByType(ElementType type)
	{
		vector<CookieHandler> selectedCookies;

		switch (type)
		{
		case 불: selectedCookies = Fire_Cookie;
			break;
		case 물:selectedCookies = Water_Cookie;
			break;
		case 얼음:selectedCookies = Ice_Cookie;
			break;
		case 바람:selectedCookies = Wind_Cookie;
			break;
		case 어둠:selectedCookies = Dark_Cookie;
			break;
		}

		for (const auto& cookie : selectedCookies)
		{
			std::cout << cookie.GetName() << " " << cookie.GetType() << std::endl;
		}
	}
};
