
#include <iostream>
#include <vector>
#include <conio.h>
// 1. 몬스터가 가지는 타입을 enum으로 선언
enum monType
{
	Fire,
	Water,
	Tree,
	Iron,
	Ground,
};

// 2. 클래스 안에 type을 넣어서 구현하기

class Monster 
{
private:
	int health;
	int attackPower;
	std::string name;
	monType mType;
public:
	Monster(int hp, int ap, std::string name, monType type) : health(hp), attackPower(ap), name(name), mType(type)	{}

	monType GetType() const { return mType; }
	std::string GetName() const { return name; }
};

class MonsterMaker
{
private:
    std::vector<Monster> monsterDataTable;
    std::vector<Monster> FireCookies;
    std::vector<Monster> WaterCookies;
    std::vector<Monster> TreeCookies;
    std::vector<Monster> IronCookies;
    std::vector<Monster> GroundCookies;
public:
    MonsterMaker()
    {
        monsterDataTable =
        {
            Monster(80, 15, "불꽃맛 쿠키", monType::Fire),
            Monster(50, 10, "물맛 쿠키", monType::Water),
            Monster(70, 25, "나무맛 쿠키", monType::Tree),
            Monster(55, 35, "철맛 쿠키",monType::Iron),
            Monster(100, 8," 땅맛 쿠키", monType::Ground),
        };
        
        for (const auto& elem : monsterDataTable)
        {
            SetCookie(elem);
        }

    }

    void SetCookie(const Monster& mon)
    {
        // 몬스터의 타입이 불타입이면 -> 불속성에 저장

        if (mon.GetType() == monType::Fire)
            FireCookies.push_back(mon);

        if (mon.GetType() == monType::Water)
            WaterCookies.push_back(mon);

        if (mon.GetType() == monType::Tree)
            TreeCookies.push_back(mon);

        if (mon.GetType() == monType::Iron)
            IronCookies.push_back(mon);

        if (mon.GetType() == monType::Ground)
            GroundCookies.push_back(mon);
    }

    void AddMonster()
    {
        int _hp;
        int _atk;
        std::string _name;
        monType _mType;
        int typeCount;

        std::cout << "HP를 입력해주세요." << std::endl;
        std::cin >> _hp;
        std::cout << "ATK를 입력해주세요." << std::endl;
        std::cin >> _atk;
        std::cout << "Name를 입력해주세요." << std::endl;
        std::cin >> _name;
        std::cout << "타입을 입력해주세요." << std::endl;
        std::cin >> typeCount;

        switch (typeCount)
        {
        case 0: _mType = Fire;
            break;
        case 1: _mType = Water;
            break;
        case 2: _mType = Tree;
            break;
        case 3: _mType = Iron;
            break;
        case 4: _mType = Ground;
            break;
        }

        Monster addMon(_hp, _atk, _name, _mType);
        monsterDataTable.push_back(addMon);
        SetCookie(addMon);
    }

    void ShowCookieByType(monType type)
    {
        std::vector<Monster> selectedMonsters;

        switch (type)
        {
        case Fire: selectedMonsters = FireCookies;
            break;
        case Water:selectedMonsters = WaterCookies;
            break;
        case Tree:selectedMonsters = TreeCookies;
            break;
        case Iron:selectedMonsters = IronCookies;
            break;
        case Ground:selectedMonsters = GroundCookies;
            break;
        }

        for (const auto& mon : selectedMonsters)
        {
            std::cout << mon.GetName() << " " << mon.GetType() << std::endl;
        }
    }
};

int main()
{
    MonsterMaker monstermaker;

    while (true)
    {
        system("cls");

        monstermaker.AddMonster();
        monstermaker.ShowCookieByType(Fire);
        _getch();
    }

    monstermaker.ShowCookieByType(Fire);
}