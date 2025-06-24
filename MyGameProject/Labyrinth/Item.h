#pragma once
#include "MapBoder.h"
#include "DoubleBuffer.h"
#include "ConsoleUtil.h"
class Item		// 나중에 상속으로 분리하기 
{
private:
	int heartCount = 0;		// stage1 열쇠
	int starCount = 0;		// stage2 열쇠
	int cloverCount = 0;	// stage3 열쇠
protected:
	//Pos pos;
public:
	//virtual ~Item() = default;
	Item() = default;
	//virtual ~Item() {}
public:
	//virtual void Collect() = 0;
	//virtual void Render(int x, int y) = 0;
	//virtual string GetSymbol() const = 0;
	//virtual int GetColor() const = 0;
	//virtual void Reset() = 0;
	//virtual bool IsClear() const = 0;
	//virtual int GetCount() const = 0;

	//virtual Pos GetPosition() const = 0;  //  위치 반환용
	//virtual void SetPosition(Pos p) = 0;  //  위치 설정용
	//Item(string shape, TileType itemType) : shape(shape), itemType(itemType), count(0) {}		// 이니셜라이저 초기화는 일단 보류
public:

	void Collect(int tileType);

	int GetItem1Count() const;
	int GetItem2Count() const;
	int GetItem3Count() const;

	void Reset();

	bool IsStage1Clear() const;
	bool IsStage2Clear() const;
	bool IsStage3Clear() const;

};
