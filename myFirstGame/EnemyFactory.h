#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H






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



#include <iostream>
#include <vector>

using namespace std;

class EnemyFactory 
{
public:	
	static EnemyFactory & instance();
	virtual ~EnemyFactory();
	Enemy* generateEnemy(int iMaxLevel, int iMinLevel);
	static int randomValue(int iMax);




private:
	vector<Enemy*> m_vEnemies; 
	EnemyFactory();
	
};

#endif
