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
	windCookieIndex = 0;		// ��Ű�� ������ �ٸ��� ������ ���� �ε����� �߰��ϰ� �ʱ�ȭ �����־���. 
	steelCookieIndex = 0;
	independentCookieIndex = 0;

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		firecookies[i] = nullptr;
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		watercookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		posioncookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		lightcookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		groundcookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		icecookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		electrocookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		darkcookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		windcookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		steelcookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
	}

	for (int i = 0; i < Cookie_Count; i++)	// ��� ĭ�� nullptr�� �ʱ�ȭ�Ѵ�.
	{
		independentcookies[i] = nullptr;	// �迭�� �����ϰ� ������ �����Ⱚ�� ���� �ʵ��� nullptr�� �о��־���.
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



void CookieManager::ShowCookieByElement(ElementType type)	// �Ӽ����� ȣ���ϱ� ���� �����ߴ�.
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

	cout << "��Ű ������ �Է��ϼ���." << endl;
	cin.ignore();
	getline(cin, name);

	cout << "�Ӽ��� �Է��ϼ���" << endl;
	cout << "0: �� 1: �� 2: �� 3: �� 4: �� 5: ���� 6: ���� 7: ��� 8: �ٶ� 9: ��ö 10: ���Ӽ�" << endl;		//Fire, Water, Dark, Ground, Electro, Wind, Ice, Light, Poison, Steel, Independent
	cin >> elementInput;

	cout << "����� �Է��ϼ���" << endl;
	cout << "0. ACIENT 1. BEAST 2. LEGENDARY 3. DRAGON 4. SUPER_EPIC 5. EPIC 6. RARE 7. COMMON" << endl;
	cin >> rankInput;

	ElementType element = static_cast<ElementType>(elementInput);	//����(int)�� enum Ÿ������ �ٲ��ֱ� ���� static_cast�� ����Ѵ�.
	Rank rank = static_cast<Rank>(rankInput);

	if (element == ��)
	{
		if (fireCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		firecookies[fireCookieIndex++] = new Fire_Cookie(name, ��, rank);		// �Ӽ����� ��Ű�� ��ü�� �����ؼ� �� �Ӽ��� �迭�� �����Ѵ�.
		cout << "[�Ϸ�] �� �Ӽ� ��Ű �߰���!" << endl;
	}

	else if (element == ��)
	{
		if (waterCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		watercookies[waterCookieIndex++] = new Water_Cookie(name, ��, rank);
		cout << "[�Ϸ�] �� �Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else if (element == ��)
	{
		if (posionCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		posioncookies[posionCookieIndex++] = new Poison_Cookie(name, ��, rank);
		cout << "[�Ϸ�] �� �Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else if (element == ��)
	{
		if (lightCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		lightcookies[lightCookieIndex++] = new Light_Cookie(name, ��, rank);

		cout << "[�Ϸ�] �� �Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else if (element == ��)
	{
		if (groundCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		groundcookies[groundCookieIndex++] = new Ground_Cookie(name, ��, rank);
		cout << "[�Ϸ�] �� �Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else if (element == ����)
	{
		if (iceCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		icecookies[iceCookieIndex++] = new Ice_Cookie(name, ����, rank);
		cout << "[�Ϸ�] ���� �Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else if (element == ����)
	{
		if (electroCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		electrocookies[electroCookieIndex++] = new Electro_Cookie(name, ����, rank);
		cout << "[�Ϸ�] ���� �Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else if (element == ���)
	{
		if (darkCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		darkcookies[darkCookieIndex++] = new Dark_Cookie(name, ���, rank);
		cout << "[�Ϸ�] ��� �Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else if (element == �ٶ�)
	{
		if (windCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		windcookies[windCookieIndex++] = new Wind_Cookie(name, �ٶ�, rank);
		cout << "[�Ϸ�] �ٶ� �Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else if (element == ��ö)
	{
		if (steelCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		steelcookies[steelCookieIndex++] = new Steel_Cookie(name, ��ö, rank);
		cout << "[�Ϸ�] ��ö �Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else if (element == ���Ӽ�)
	{
		if (independentCookieIndex >= Cookie_Count)
		{
			cout << "[���] �� �̻� ��Ű�� �߰��� �� �����ϴ�." << endl;
			return;
		}
		independentcookies[independentCookieIndex++] = new Independent_Cookie(name, ���Ӽ�, rank);
		cout << "[�Ϸ�] ���Ӽ� ��Ű �߰���!" << endl;
		added = true;
	}

	else
	{
		cout << "[����] �߸��� �Ӽ��Դϴ�!" << endl;
	}

	if (added)
	{
		cout << "���͸� ������ �޴��� ���ư��ϴ�.";
		cin.ignore();
		cin.get();
	}
}





