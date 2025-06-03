#pragma once
#pragma once
#include "Cookie.h"

// 쿠키를 활용하여 쿠키정보프로그램 만들기 
class CookieManager
{
private:
	map<string, Cookie> cookies;

public:

	CookieManager() = default;

	void ShowCookies();	// 저장된 쿠키를 보여주는 함수
	void ShowCookieByElement(ElementType type);	// 
	void ShowCookieByRank(Rank rank);
	void AddCookies();

};

