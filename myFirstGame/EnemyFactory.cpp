#include "Unit.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Consumable.h"
#include "Enemy.h"
#include "XMLSerializable.h"
#include "parser.h"
#include "EnemyFactory.h"
#include "Entity.h"


//mas libraries to compile
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <iostream>
#include <vector>


using namespace std;


EnemyFactory & EnemyFactory::instance()
{
        static EnemyFactory factory;
        return factory;
}

EnemyFactory::EnemyFactory()
{
       map<string, function<XMLSerializable*()>> mapConstructor;

        mapConstructor["Item"] =   []() { return new Item; };
        mapConstructor["Armor"] = []() { return new Armor; };
        mapConstructor["Weapon"] =       []() { return new Weapon; };
        mapConstructor["Consumable"] =   []() { return new Consumable; };
        mapConstructor["Enemy"] = []() { return new Enemy; };


        vector<XMLSerializable*> vec;

        parseXML (mapConstructor, "critters.xml", vec); //get data from XML file that presumably tells us what type of stats the critters will have


        for (auto pObject : vec)
        {
			m_vEnemies.push_back (dynamic_cast<Enemy*> (pObject));
			//EnemyFactory::m_vEnemies.push_back(dynamic_cast<Enemy*> (pObject));
        }


	//sort enemies by calling generateEnemy

      
		
}

EnemyFactory::~EnemyFactory()
{
}

int EnemyFactory::randomValue(int iMax)
{
	static mt19937 mt(time(NULL));
	return mt() % iMax;
}


Enemy* EnemyFactory:: generateEnemy(int iMaxLevel, int iMinLevel)
{
	static mt19937 mt(time(NULL));
	vector <Enemy*>  appropiate_lvl_monsters;  //correct vector type?

	for (int i=0; i < m_vEnemies.size(); i++) //fills new vector with appropiate leveled monsters
	{
		if (m_vEnemies[i]->getLevel() <= iMaxLevel && m_vEnemies[i]->getLevel() > iMinLevel)
			appropiate_lvl_monsters.push_back(m_vEnemies[i]);
	}

	int randomly_chosen_enemy = mt() % appropiate_lvl_monsters.size();

	
	Enemy * pReturnValue = new Enemy(*appropiate_lvl_monsters[randomly_chosen_enemy]); 

	//pReturnValue->dumpObject();
	return pReturnValue;


}
