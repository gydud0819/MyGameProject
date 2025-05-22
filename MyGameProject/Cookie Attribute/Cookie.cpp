#include "Cookie.h"

ElementType Cookie::GetElementType() const
{
	return type;
}

Rank Cookie::GetRank() const
{
	return rank;
}

void Cookie::ShowCookieInfo()
{
	cout << "��Ű�� �̸�: " << name << endl;
	cout << "��Ű�� �Ӽ�: " << ReturnElementType() << endl;
	cout << "��Ű�� ���: " << ReturnRank() << endl;
}

string Cookie::ReturnElementType()
{
	switch (type)
	{
	case ��:
		return "��";
	case ��:
		return "��";
	case ��:
		return "��";
	case ��:
		return "��";
	case ��:
		return "��";
	case ����:
		return "����";
	case ����:
		return "����";
	case ���:
		return "���";
	case �ٶ�:
		return "�ٶ�";
	case ��ö:
		return "��ö";
	case ���Ӽ�:
		return "���Ӽ�";
	default:
		break;
	}
}

string Cookie::ReturnRank()
{
	switch (rank)
	{
	case ANCIENT:
		return "ANCIENT";
	case BEAST:
		return "BEAST";
	case LEGENDARY:
		return "LEGENDARY";
	case DRAGON:
		return "DRAGON";
	case SUPER_EPIC:
		return"SUPER_EPIC";
	case EPIC:
		return "EPIC";
	case RARE:
		return"RARE";
	case COMMON:
		return "COMMON";
	default:
		break;
	}
}

// �ؿ� �ּ�ó���� ������ �θ�Ŭ������ �Լ��� �Ȱ��� �����̱⿡ �������̵��� �ʿ���� �Ǵ��Ͽ� ���� �ּ�ó���� �ߴ�.
// �� �Ӽ�
void Fire_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Fire_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Fire_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}

// �� �Ӽ�
void Water_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Water_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Water_Cookie::ReturnRank()
{
	return  Cookie::ReturnRank();
}

// �� �Ӽ�
void Poison_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Poison_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Poison_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}

void Light_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Light_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Light_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}

void Ground_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Ground_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Ground_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}

void Ice_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Ice_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Ice_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}

void Electro_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Electro_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Electro_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}

void Dark_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Dark_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Dark_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}

void Wind_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Wind_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Wind_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}


void Steel_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Steel_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Steel_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}

void Independent_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Independent_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Independent_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}
