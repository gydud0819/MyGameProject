#pragma once
#pragma once
#include "Common.h"


const int MAX_COOKIE = 100;

enum ElementType	// �Ӽ�
{
	//Fire, Water, Poison, Light, Ground, Ice, Electro, Dark, Wind, Steel, Independent
	��, ��, ��, ��, ��, ����, ����, ���, �ٶ�, ��ö, ���Ӽ�
};

enum Rank			// ���
{
	ANCIENT, BEAST, LEGENDARY, DRAGON, SUPER_EPIC, EPIC, RARE, COMMON
};

class Cookie		// �θ� Ŭ����
{
protected:
	string name;
	ElementType type;
	Rank rank;
public:
	Cookie() {}
	Cookie(string name, ElementType type, Rank rank) : name(name), type(type), rank(rank) {}
	ElementType GetElementType() const;
	Rank GetRank() const;
public:
	virtual void ShowCookieInfo();		// ���� �̸��� ���� �Լ��� ã�� ����ض��� ��
	virtual string ReturnElementType();
	virtual string ReturnRank();

	virtual ~Cookie() = default;
};


class Fire_Cookie : public Cookie	// �� �Ӽ� Ŭ����
{
public:
	Fire_Cookie() {}
	Fire_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Water_Cookie : public Cookie	// �� �Ӽ� Ŭ����
{
public:
	Water_Cookie() {}
	Water_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Poison_Cookie : public Cookie	// �� �Ӽ� Ŭ����
{
public:
	Poison_Cookie() {}
	Poison_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Light_Cookie : public Cookie	// �� �Ӽ� Ŭ���� 
{
public:
	Light_Cookie() {}
	Light_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Ground_Cookie : public Cookie	// �� �Ӽ� Ŭ���� 
{
public:
	Ground_Cookie() {}
	Ground_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Ice_Cookie : public Cookie	// ���� �Ӽ� Ŭ����
{
public:
	Ice_Cookie() {}
	Ice_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Electro_Cookie : public Cookie	// ���� �Ӽ� Ŭ����
{
public:
	Electro_Cookie() {}
	Electro_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Dark_Cookie : public Cookie	// ��� �Ӽ� Ŭ���� 
{
public:
	Dark_Cookie() {}
	Dark_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Wind_Cookie : public Cookie	// �ٶ� �Ӽ� Ŭ����
{
public:
	Wind_Cookie() {}
	Wind_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Steel_Cookie : public Cookie	// ��ö �Ӽ� Ŭ����
{
public:
	Steel_Cookie() {}
	Steel_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};

class Independent_Cookie : public Cookie	// ���Ӽ� Ŭ���� (�� � �Ӽ����� ������ �ʴ� Ŭ����)
{
public:
	Independent_Cookie() {}
	Independent_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // �ڽ� Ŭ������ ������

public:
	void ShowCookieInfo() override;		// virtual Ű���带 ����� �Լ��� ã�� �θ� �Լ��� �״�� ������(������) �ǹ��̴�.
	string ReturnElementType() override;
	string ReturnRank() override;

};




//class GingerBrave :public Cookie		// �ڽ� Ŭ����, �밨����Ű
//{
//public:
//	GingerBrave() {}
//	GingerBrave(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {}
//public:
//	void ShowCookieInfo();
//	string ReturnElementType();	// �θ� �Լ��� ������(�����)�� �Ͽ� �ٽ� ����Ѵٴ� ���̴�.
//	string ReturnRank();
//
//};