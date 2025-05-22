
#include <iostream>
#include <vector>
#include <conio.h>
// 1. ���Ͱ� ������ Ÿ���� enum���� ����
enum monType
{
	Fire,
	Water,
	Tree,
	Iron,
	Ground,
};

// 2. Ŭ���� �ȿ� type�� �־ �����ϱ�

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
            Monster(80, 15, "�Ҳɸ� ��Ű", monType::Fire),
            Monster(50, 10, "���� ��Ű", monType::Water),
            Monster(70, 25, "������ ��Ű", monType::Tree),
            Monster(55, 35, "ö�� ��Ű",monType::Iron),
            Monster(100, 8," ���� ��Ű", monType::Ground),
        };
        
        for (const auto& elem : monsterDataTable)
        {
            SetCookie(elem);
        }

    }

    void SetCookie(const Monster& mon)
    {
        // ������ Ÿ���� ��Ÿ���̸� -> �ҼӼ��� ����

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

        std::cout << "HP�� �Է����ּ���." << std::endl;
        std::cin >> _hp;
        std::cout << "ATK�� �Է����ּ���." << std::endl;
        std::cin >> _atk;
        std::cout << "Name�� �Է����ּ���." << std::endl;
        std::cin >> _name;
        std::cout << "Ÿ���� �Է����ּ���." << std::endl;
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