
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

	//	cout << "[��Ű�� ŷ�� ��Ű ���� ���α׷�]" << endl << endl;
	//	cout << "<< 1. ��Ű �߰��ϱ� ";
	//	cout << "2. �߰��� ��Ű �����ϱ� ";
	//	cout << "3. �Ӽ����� ��Ű ��ƺ��� ";
	//	cout << "4. �����ϱ� ";
	//	cout << "5. �����ϱ� ";
	//	cout << "6. ��Ű�� �����Ͽ� �ó��� ���� ���� ";
	//	cout << "7. �ڷΰ��� ";
	//	cout << "0. ���� �����ϱ� >>" << endl;
	//	cin >> Choice;

	//	switch (Choice)
	//	{
	//	case 1:
	//		manager.AddCookies();	// ��Ű ���� �߰��ϱ�
	//		break;
	//	case 2:
	//		manager.ShowAddCookies();	// �߰��� ��Ű ���� ����
	//		break;
	//	case 3:
	//		cout << "� �Ӽ��� ��Ű������ ���ðڽ��ϱ�?" << endl;
	//		cout << "0: �� 1: �� 2: ��� 3: �� 4: ���� 5: �ٶ� 6: ���� 7: �� 8: �� 9: ��ö 10: ���Ӽ�" << endl;
	//		cin >> elementInput;
	//		manager.ShowCookieByElement(static_cast<ElementType>(elementInput));

	//		break;
	//	case 4:
	//		cout << "��Ű�� �������ּ���" << endl;
	//	case 5:
	//		break;
	//	case 0:
	//		cout << "���α׷��� ���� �մϴ�.";
	//		return 0;
	//	default:
	//		cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���." << endl;
	//		break;
	//	}

	//	cout << endl;

	//}


	CookieMaker cookiemarker;

	while (true)
	{
		system("cls");

		cookiemarker.AddCookie();
		cookiemarker.ShowCookieByType(ElementType::��);
		_getch();
	}
		cookiemarker.ShowCookieByType(ElementType::��);

}