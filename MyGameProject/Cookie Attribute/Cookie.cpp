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
	cout << "쿠키의 이름: " << name << endl;
	cout << "쿠키의 속성: " << ReturnElementType() << endl;
	cout << "쿠키의 등급: " << ReturnRank() << endl;
}

string Cookie::ReturnElementType()
{
	switch (type)
	{
	case 불:
		return "불";
	case 물:
		return "물";
	case 독:
		return "독";
	case 빛:
		return "빛";
	case 땅:
		return "땅";
	case 얼음:
		return "얼음";
	case 전기:
		return "전기";
	case 어둠:
		return "어둠";
	case 바람:
		return "바람";
	case 강철:
		return "강철";
	case 무속성:
		return "무속성";
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

// 밑에 주석처리한 내용은 부모클래스의 함수와 똑같은 내용이기에 오버라이딩이 필요없다 판단하여 전부 주석처리를 했다.
// 불 속성
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

// 물 속성
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

// 독 속성
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
