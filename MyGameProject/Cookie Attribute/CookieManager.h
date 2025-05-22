#pragma once
#pragma once
#include "Cookie.h"

// 쿠키를 활용하여 쿠키정보프로그램 만들기 
class CookieManager
{
private:
	int fireCookieIndex;
	int waterCookieIndex;
	int posionCookieIndex;
	int lightCookieIndex;
	int groundCookieIndex;
	int iceCookieIndex;
	int electroCookieIndex;
	int darkCookieIndex;
	int windCookieIndex;
	int steelCookieIndex;
	int independentCookieIndex;

	bool added;
private:
	static const int Cookie_Count = 20;			// static: 클래스의 모든 객체에서 동일 값을 공유한다, const : 값이 초기화 된 후에도 변하지 않도록 사용했다.
	Fire_Cookie* firecookies[Cookie_Count];		// 저장된 쿠키 수			
	Water_Cookie* watercookies[Cookie_Count];
	Poison_Cookie* posioncookies[Cookie_Count];
	Light_Cookie* lightcookies[Cookie_Count];
	Ground_Cookie* groundcookies[Cookie_Count];
	Ice_Cookie* icecookies[Cookie_Count];
	Electro_Cookie* electrocookies[Cookie_Count];
	Dark_Cookie* darkcookies[Cookie_Count];
	Wind_Cookie* windcookies[Cookie_Count];		// 바람 속성 쿠키 7개	
	Steel_Cookie* steelcookies[Cookie_Count];
	Independent_Cookie* independentcookies[Cookie_Count];
public:

	CookieManager();

	void ShowAddCookies();
	void ShowCookieByElement(ElementType type);
	void ShowCookieByRank(Rank rank);
	void AddCookies();

};

