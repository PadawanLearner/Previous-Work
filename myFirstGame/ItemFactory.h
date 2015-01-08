#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H






#include "Unit.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Consumable.h"
#include "Enemy.h"
#include "XMLSerializable.h"
#include "parser.h"
#include "Entity.h"
#include "Enemy.h"
#include "Weapon.h"


#include <iostream>
#include <vector>

using namespace std;

class ItemFactory 
{
public:	
	static ItemFactory & instance();
	virtual ~ItemFactory();
	Item* generateItem(int iMaxLevel, string itemType);
	static int randomValue(int iMax);




private:
	vector<Item*> m_vItems; 
	ItemFactory();
	vector<Armor*> m_vArmor;
	vector<Weapon*> m_vWeapon;
};

#endif
