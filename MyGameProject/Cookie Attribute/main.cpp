
//#include "Cookie.h"
//#include "CookieManager.h"
#include "CookieHandler.h"
#include <conio.h>

int main()
{
	//CookieManager manager;
	//int Choice;

	//int elementInput = 0;

	//while (true)
	//{
	//	system("cls");

	//	cout << "[쿠키런 킹덤 쿠키 관리 프로그램]" << endl << endl;
	//	cout << "<< 1. 쿠키 추가하기 ";
	//	cout << "2. 추가한 쿠키 열람하기 ";
	//	cout << "3. 속성별로 쿠키 모아보기 ";
	//	cout << "4. 수정하기 ";
	//	cout << "5. 삭제하기 ";
	//	cout << "6. 쿠키를 선택하여 시너지 조합 보기 ";
	//	cout << "7. 뒤로가기 ";
	//	cout << "0. 열람 종료하기 >>" << endl;
	//	cin >> Choice;

	//	switch (Choice)
	//	{
	//	case 1:
	//		manager.AddCookies();	// 쿠키 정보 추가하기
	//		break;
	//	case 2:
	//		manager.ShowAddCookies();	// 추가한 쿠키 정보 보기
	//		break;
	//	case 3:
	//		cout << "어떤 속성의 쿠키정보를 보시겠습니까?" << endl;
	//		cout << "0: 불 1: 물 2: 어둠 3: 땅 4: 전기 5: 바람 6: 얼음 7: 빛 8: 독 9: 강철 10: 무속성" << endl;
	//		cin >> elementInput;
	//		manager.ShowCookieByElement(static_cast<ElementType>(elementInput));

	//		break;
	//	case 4:
	//		cout << "쿠키를 선택해주세요" << endl;
	//	case 5:
	//		break;
	//	case 0:
	//		cout << "프로그램을 종료 합니다.";
	//		return 0;
	//	default:
	//		cout << "잘못된 선택입니다. 다시 입력하세요." << endl;
	//		break;
	//	}

	//	cout << endl;

	//}


	CookieMaker cookiemarker;

	while (true)
	{
		system("cls");

		cookiemarker.AddCookie();
		cookiemarker.ShowCookieByType(ElementType::불);
		_getch();
	}
		cookiemarker.ShowCookieByType(ElementType::불);

}