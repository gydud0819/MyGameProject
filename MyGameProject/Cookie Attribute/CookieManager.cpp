#include "CookieManager.h"

CookieManager::CookieManager()
{
	fireCookieIndex = 0;
	waterCookieIndex = 0;
	posionCookieIndex = 0;
	lightCookieIndex = 0;
	groundCookieIndex = 0;
	iceCookieIndex = 0;
	electroCookieIndex = 0;
	darkCookieIndex = 0;
	windCookieIndex = 0;		// 쿠키별 개수가 다르기 때문에 각각 인덱스를 추가하고 초기화 시켜주었다. 
	steelCookieIndex = 0;
	independentCookieIndex = 0;

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		firecookies[i] = nullptr;
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		watercookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		posioncookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		lightcookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		groundcookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		icecookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		electrocookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		darkcookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		windcookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		steelcookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}

	for (int i = 0; i < Cookie_Count; i++)	// 모든 칸을 nullptr로 초기화한다.
	{
		independentcookies[i] = nullptr;	// 배열로 선언하고 공간에 쓰레기값이 들어가지 않도록 nullptr로 밀어주었다.
	}
}

void CookieManager::ShowAddCookies()
{
	/*for (int i = 0; i < Cookie_Count; i++)
	{
		if (firecookies[i] != nullptr)
		{

			firecookies[i]->ShowCookieInfo();
		}

		if (posioncookies[i] != nullptr)
		{

			posioncookies[i]->ShowCookieInfo();
		}

		if (lightcookies[i] != nullptr)
		{

			lightcookies[i]->ShowCookieInfo();
		}

		if (groundcookies[i] != nullptr)
		{

			groundcookies[i]->ShowCookieInfo();
		}

		if (icecookies[i] != nullptr)
		{

			icecookies[i]->ShowCookieInfo();
		}

		if (electrocookies[i] != nullptr)
		{

			electrocookies[i]->ShowCookieInfo();
		}

		if (darkcookies[i] != nullptr)
		{

			darkcookies[i]->ShowCookieInfo();
		}

		if (windcookies[i] != nullptr)
		{
			windcookies[i]->ShowCookieInfo();

		}

		if (steelcookies[i] != nullptr)
		{

			steelcookies[i]->ShowCookieInfo();
		}

		if (independentcookies[i] != nullptr)
		{

			independentcookies[i]->ShowCookieInfo();
		}
	}*/


	for (int i = 0; i < fireCookieIndex; i++)
		if (firecookies[i] != nullptr)
			firecookies[i]->ShowCookieInfo();

	for (int i = 0; i < posionCookieIndex; i++)
		if (posioncookies[i] != nullptr)
			posioncookies[i]->ShowCookieInfo();

	for (int i = 0; i < lightCookieIndex; i++)
		if (lightcookies[i] != nullptr)
			lightcookies[i]->ShowCookieInfo();

	for (int i = 0; i < groundCookieIndex; i++)
		if (groundcookies[i] != nullptr)
			groundcookies[i]->ShowCookieInfo();

	for (int i = 0; i < iceCookieIndex; i++)
		if (icecookies[i] != nullptr)
			icecookies[i]->ShowCookieInfo();

	for (int i = 0; i < electroCookieIndex; i++)
		if (electrocookies[i] != nullptr)
			electrocookies[i]->ShowCookieInfo();

	for (int i = 0; i < darkCookieIndex; i++)
		if (darkcookies[i] != nullptr)
			darkcookies[i]->ShowCookieInfo();

	for (int i = 0; i < windCookieIndex; i++)
		if (windcookies[i] != nullptr)
			windcookies[i]->ShowCookieInfo();

	for (int i = 0; i < steelCookieIndex; i++)
		if (steelcookies[i] != nullptr)
			steelcookies[i]->ShowCookieInfo();

	for (int i = 0; i < independentCookieIndex; i++)
		if (independentcookies[i] != nullptr)
			independentcookies[i]->ShowCookieInfo();
}



void CookieManager::ShowCookieByElement(ElementType type)	// 속성별로 호출하기 위해 선언했다.
{
	for (int i = 0; i < Cookie_Count; i++)
	{
		if (firecookies[i] != nullptr && firecookies[i]->GetElementType() == type)
		{
			firecookies[i]->ShowCookieInfo();
		}

		if (watercookies[i] != nullptr && watercookies[i]->GetElementType() == type)
		{
			watercookies[i]->ShowCookieInfo();
		}

		if (posioncookies[i] != nullptr && posioncookies[i]->GetElementType() == type)
		{
			posioncookies[i]->ShowCookieInfo();
		}

		if (lightcookies[i] != nullptr && lightcookies[i]->GetElementType() == type)
		{
			lightcookies[i]->ShowCookieInfo();
		}

		if (groundcookies[i] != nullptr && groundcookies[i]->GetElementType() == type)
		{
			groundcookies[i]->ShowCookieInfo();
		}

		if (icecookies[i] != nullptr && icecookies[i]->GetElementType() == type)
		{
			icecookies[i]->ShowCookieInfo();
		}

		if (electrocookies[i] != nullptr && electrocookies[i]->GetElementType() == type)
		{
			electrocookies[i]->ShowCookieInfo();
		}

		if (darkcookies[i] != nullptr && darkcookies[i]->GetElementType() == type)
		{
			darkcookies[i]->ShowCookieInfo();
		}

		if (windcookies[i] != nullptr && windcookies[i]->GetElementType() == type)
		{
			windcookies[i]->ShowCookieInfo();
		}

		if (steelcookies[i] != nullptr && steelcookies[i]->GetElementType() == type)
		{
			steelcookies[i]->ShowCookieInfo();
		}

		if (independentcookies[i] != nullptr && independentcookies[i]->GetElementType() == type)
		{
			independentcookies[i]->ShowCookieInfo();
		}

	}
}

void CookieManager::ShowCookieByRank(Rank rank)
{
	for (int i = 0; i < Cookie_Count; i++)
	{
		if (firecookies[i] != nullptr && firecookies[i]->GetRank() == rank)
		{
			firecookies[i]->ShowCookieInfo();
		}

		if (watercookies[i] != nullptr && watercookies[i]->GetRank() == rank)
		{
			watercookies[i]->ShowCookieInfo();
		}

		if (posioncookies[i] != nullptr && posioncookies[i]->GetRank() == rank)
		{
			posioncookies[i]->ShowCookieInfo();
		}

		if (lightcookies[i] != nullptr && lightcookies[i]->GetRank() == rank)
		{
			lightcookies[i]->ShowCookieInfo();
		}

		if (groundcookies[i] != nullptr && groundcookies[i]->GetRank() == rank)
		{
			groundcookies[i]->ShowCookieInfo();
		}

		if (darkcookies[i] != nullptr && darkcookies[i]->GetRank() == rank)
		{
			darkcookies[i]->ShowCookieInfo();
		}

		if (windcookies[i] != nullptr && windcookies[i]->GetRank() == rank)
		{
			windcookies[i]->ShowCookieInfo();
		}

		if (steelcookies[i] != nullptr && steelcookies[i]->GetRank() == rank)
		{
			steelcookies[i]->ShowCookieInfo();
		}

		if (independentcookies[i] != nullptr && independentcookies[i]->GetRank() == rank)
		{
			independentcookies[i]->ShowCookieInfo();
		}


	}
}

void CookieManager::AddCookies()
{
	string name;
	int elementInput;
	int rankInput;

	bool added = false;

	cout << "쿠키 정보를 입력하세요." << endl;
	cin.ignore();
	getline(cin, name);

	cout << "속성을 입력하세요" << endl;
	cout << "0: 불 1: 물 2: 독 3: 빛 4: 땅 5: 얼음 6: 전기 7: 어둠 8: 바람 9: 강철 10: 무속성" << endl;		//Fire, Water, Dark, Ground, Electro, Wind, Ice, Light, Poison, Steel, Independent
	cin >> elementInput;

	cout << "등급을 입력하세요" << endl;
	cout << "0. ACIENT 1. BEAST 2. LEGENDARY 3. DRAGON 4. SUPER_EPIC 5. EPIC 6. RARE 7. COMMON" << endl;
	cin >> rankInput;

	ElementType element = static_cast<ElementType>(elementInput);	//숫자(int)를 enum 타입으로 바꿔주기 위해 static_cast를 사용한다.
	Rank rank = static_cast<Rank>(rankInput);

	if (element == 불)
	{
		if (fireCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		firecookies[fireCookieIndex++] = new Fire_Cookie(name, 불, rank);		// 속성별로 쿠키를 객체로 생성해서 각 속성의 배열에 저장한다.
		cout << "[완료] 불 속성 쿠키 추가됨!" << endl;
	}

	else if (element == 물)
	{
		if (waterCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		watercookies[waterCookieIndex++] = new Water_Cookie(name, 물, rank);
		cout << "[완료] 물 속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else if (element == 독)
	{
		if (posionCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		posioncookies[posionCookieIndex++] = new Poison_Cookie(name, 독, rank);
		cout << "[완료] 독 속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else if (element == 빛)
	{
		if (lightCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		lightcookies[lightCookieIndex++] = new Light_Cookie(name, 빛, rank);

		cout << "[완료] 빛 속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else if (element == 땅)
	{
		if (groundCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		groundcookies[groundCookieIndex++] = new Ground_Cookie(name, 땅, rank);
		cout << "[완료] 땅 속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else if (element == 얼음)
	{
		if (iceCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		icecookies[iceCookieIndex++] = new Ice_Cookie(name, 얼음, rank);
		cout << "[완료] 얼음 속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else if (element == 전기)
	{
		if (electroCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		electrocookies[electroCookieIndex++] = new Electro_Cookie(name, 전기, rank);
		cout << "[완료] 전기 속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else if (element == 어둠)
	{
		if (darkCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		darkcookies[darkCookieIndex++] = new Dark_Cookie(name, 어둠, rank);
		cout << "[완료] 어둠 속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else if (element == 바람)
	{
		if (windCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		windcookies[windCookieIndex++] = new Wind_Cookie(name, 바람, rank);
		cout << "[완료] 바람 속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else if (element == 강철)
	{
		if (steelCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		steelcookies[steelCookieIndex++] = new Steel_Cookie(name, 강철, rank);
		cout << "[완료] 강철 속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else if (element == 무속성)
	{
		if (independentCookieIndex >= Cookie_Count)
		{
			cout << "[경고] 더 이상 쿠키를 추가할 수 없습니다." << endl;
			return;
		}
		independentcookies[independentCookieIndex++] = new Independent_Cookie(name, 무속성, rank);
		cout << "[완료] 무속성 쿠키 추가됨!" << endl;
		added = true;
	}

	else
	{
		cout << "[오류] 잘못된 속성입니다!" << endl;
	}

	if (added)
	{
		cout << "엔터를 누르면 메뉴로 돌아갑니다.";
		cin.ignore();
		cin.get();
	}
}





