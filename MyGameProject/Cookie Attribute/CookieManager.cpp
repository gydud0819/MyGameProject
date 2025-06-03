#include "CookieManager.h"

void CookieManager::ShowCookies()
{
    string name;
    int typeInput, rankInput;

    cout << "쿠키 이름: ";
    cin >> name;

    cout << "속성 (0:불, 1:물, ...): ";
    cin >> typeInput;

    cout << "등급 (0:ANCIENT, 1:BEAST, ...): ";
    cin >> rankInput;

    // 중복 이름 체크
    if (cookies.find(name) != cookies.end()) 
    {
        cout << "이미 존재하는 쿠키입니다." << endl;
        return;
    }

    cookies.emplace(name, Cookie(name, 
        static_cast<ElementType>(typeInput),
        static_cast<Rank>(rankInput)));
   
}
