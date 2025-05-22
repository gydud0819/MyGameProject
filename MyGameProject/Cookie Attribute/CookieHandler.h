#pragma once
#include "Cookie.h"
#include <vector>
using namespace std;

enum ElementType	// �Ӽ�
{
	//Fire, Water, Poison, Light, Ground, Ice, Electro, Dark, Wind, Steel, Independent
	��, ��, ��, ��, ��, ����, ����, ���, �ٶ�, ��ö, ���Ӽ�
};

enum Rank			// ���
{
	ANCIENT, BEAST, LEGENDARY, DRAGON, SUPER_EPIC, EPIC, RARE, COMMON
};

class CookieHandler	// ��Ű ������ �����ϴ� Ŭ���� 
{
private:
	string name;
	ElementType type;
	Rank rank;
public:
	CookieHandler(string name, ElementType type, Rank rank)	// ������ �ʱ�ȭ�ϱ�
		: name(name), type(type), rank(rank) { }
	string GetName() const { return name; }	// �̸� ��ȯ, private�� ���� �� ���� ������ return���� �����ؼ� �������ش�
	ElementType GetType() const { return type; }	// ���� ����.
	Rank GetRank() const { return rank; }	// ���� ����. 
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
			CookieHandler("�������� ��Ű", ElementType::����, Rank::LEGENDARY),
			CookieHandler("�Ҳ����� ��Ű", ElementType::��, Rank::LEGENDARY),
			CookieHandler("�޺����� ��Ű", ElementType::����, Rank::LEGENDARY),
			CookieHandler("�ٶ��ü� ��Ű", ElementType::�ٶ�, Rank::LEGENDARY),
			CookieHandler("��Ҹ��� ��Ű", ElementType::���, Rank::LEGENDARY),
		};
		// cookieDataTable�� �� ���(CookieHandler ��ü)�� ������ �޾ƿ�
        // ������ ����ϸ� ���� ���� ���� ��ü�� ���� ����� �� �־� ���ɻ� ������ ����
		for (const auto& elem : cookieDataTable)
		{
			SetCookie(elem);
		}
	}

	void SetCookie(const CookieHandler& cookie)
	{
		if (cookie.GetType() == ElementType::��)
			Fire_Cookie.push_back(cookie);		// ���ο� ��Ҹ� �� �ڿ� �߰��� �� ����ϴ� �Լ��� emplace_back()���� ����ϴ°� �� �� ����

		if (cookie.GetType() == ElementType::��)
			Water_Cookie.push_back(cookie);

		if (cookie.GetType() == ElementType::����)
			Ice_Cookie.push_back(cookie);

		if (cookie.GetType() == ElementType::�ٶ�)
			Wind_Cookie.push_back(cookie);

		if (cookie.GetType() == ElementType::���)
			Dark_Cookie.push_back(cookie);
	}

	void AddCookie()
	{
		std::string _name;
		ElementType _type;
		Rank _rank;
		int typeCount;
		int rankCount;
		
		std::cout << "Name�� �Է����ּ���." << std::endl;
		std::cin >> _name;
		std::cout << "Ÿ���� �Է����ּ���." << std::endl;
		std::cin >> typeCount;
		std::cin >> rankCount;
		

		switch (typeCount)
		{
		case 0: _type = ElementType::��;
			break;
		case 1: _type = ElementType::��;
			break;
		case 2: _type = ElementType::����;
			break;
		case 3: _type = ElementType::�ٶ�;
			break;
		case 4: _type = ElementType::���;
			break;
		default: _type = ElementType::���Ӽ�;
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

		// ���ο� ��Ű ��ü�� ����ų� �߰��Ѵ�. 
		CookieHandler addCookie(_name, _type, _rank);
		cookieDataTable.push_back(addCookie);
		SetCookie(addCookie);	// �Ӽ����� ���Ϳ��� �߰�������Ѵ�.
	}

	void ShowCookieByType(ElementType type)
	{
		vector<CookieHandler> selectedCookies;

		switch (type)
		{
		case ��: selectedCookies = Fire_Cookie;
			break;
		case ��:selectedCookies = Water_Cookie;
			break;
		case ����:selectedCookies = Ice_Cookie;
			break;
		case �ٶ�:selectedCookies = Wind_Cookie;
			break;
		case ���:selectedCookies = Dark_Cookie;
			break;
		}

		for (const auto& cookie : selectedCookies)
		{
			std::cout << cookie.GetName() << " " << cookie.GetType() << std::endl;
		}
	}
};
