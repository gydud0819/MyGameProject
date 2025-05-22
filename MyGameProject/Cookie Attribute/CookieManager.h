#pragma once
#pragma once
#include "Cookie.h"

// ��Ű�� Ȱ���Ͽ� ��Ű�������α׷� ����� 
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
	static const int Cookie_Count = 20;			// static: Ŭ������ ��� ��ü���� ���� ���� �����Ѵ�, const : ���� �ʱ�ȭ �� �Ŀ��� ������ �ʵ��� ����ߴ�.
	Fire_Cookie* firecookies[Cookie_Count];		// ����� ��Ű ��			
	Water_Cookie* watercookies[Cookie_Count];
	Poison_Cookie* posioncookies[Cookie_Count];
	Light_Cookie* lightcookies[Cookie_Count];
	Ground_Cookie* groundcookies[Cookie_Count];
	Ice_Cookie* icecookies[Cookie_Count];
	Electro_Cookie* electrocookies[Cookie_Count];
	Dark_Cookie* darkcookies[Cookie_Count];
	Wind_Cookie* windcookies[Cookie_Count];		// �ٶ� �Ӽ� ��Ű 7��	
	Steel_Cookie* steelcookies[Cookie_Count];
	Independent_Cookie* independentcookies[Cookie_Count];
public:

	CookieManager();

	void ShowAddCookies();
	void ShowCookieByElement(ElementType type);
	void ShowCookieByRank(Rank rank);
	void AddCookies();

};

