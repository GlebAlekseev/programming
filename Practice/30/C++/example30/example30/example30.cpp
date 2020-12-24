#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Item {// 2 части .. Перечисление с состоянием типа .. объединение принимающее единую структуру
	enum class ItemType { // показывает содержащийся тип 
		COIN,
		RUNE,
		WEAPON,
		ARMOR
	}TypeItem;
	union { // 1 из состояний
		struct COIN { // Coin
			unsigned int count;
		} Coins;
		struct RUNE { // Rune
			unsigned int level;
			enum class Element {
				FIRE,
				WATER,
				EARTH,
				AIR
			} element;
		} Runes;
		struct WEAPON { // Weapon
			unsigned int damage;
			unsigned int critical;
			unsigned int durability;

		} Weapons;
		struct ARMOR { // Armor
			unsigned int guard;
			unsigned int durability;


		} Armors;
	};
};
typedef vector<Item> LootBox; // псевдоним

LootBox generateLootBox() {
	LootBox LBox;
	for (int i = 0; i < 3; i++)
	{// Тут будет генерация
		LBox.push_back({});
	}
	return LBox;
}
ostream& operator<<(ostream& out, Item myitem) {
	out << myitem.Armors.guard;
	out << myitem.Armors.durability;
	return out;
}
int main()
{
	generateLootBox();
	//Тест
	Item main{};
	main.Coins.count = 1000;
	main.Armors.durability = 99;
	main.Armors.guard = 67;
	main.Runes.level = 30;
	main.Weapons.critical = 67;
	main.Weapons.damage = 33;
	main.Weapons.durability = 12;
	main.Coins.count = 1000;


	cout << "coin count " << main.Coins.count << endl;
	cout << "armor durability " << main.Armors.durability << endl;
	cout << "armor guard " << main.Armors.guard << endl;
	cout << "rune level " << main.Runes.level << endl;
	cout << "weapon critical " << main.Weapons.critical << endl;
	cout << "weapon damage " << main.Weapons.damage << endl;
	cout << "weapon durablity " << main.Weapons.durability << endl;

	cout << endl;

	cout << main.ItemTypes;
}

