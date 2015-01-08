#include "Unit.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Consumable.h"
#include "Enemy.h"
#include "XMLSerializable.h"
#include "parser.h"
#include "ItemFactory.h"
#include "Entity.h"


//mas libraries to compile
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <iostream>
#include <vector>


using namespace std;


ItemFactory & ItemFactory::instance()
{
        static ItemFactory factory;
        return factory;
}


ItemFactory::ItemFactory()
{
       map<string, function<XMLSerializable*()>> mapConstructor;

        mapConstructor["Item"] =   []() { return new Item; };
        mapConstructor["Armor"] = []() { return new Armor; };
        mapConstructor["Weapon"] =       []() { return new Weapon; };
        mapConstructor["Consumable"] =   []() { return new Consumable; };
        mapConstructor["Enemy"] = []() { return new Enemy; };


        vector<XMLSerializable*> vec;

        parseXML (mapConstructor, "gear.xml", vec); //get data from XML file that presumably tells us what type of stats the critters will have


       // for (auto pObject : vec)
        
			
		for (int i=0; i < vec.size(); i++)
		{
			m_vItems.push_back(dynamic_cast<Item*>(vec[i]));
			//dynamic cast will fail if it cannot cast as weapon or armour respectively

        }

		for (int i=0; i < m_vItems.size(); i++)
		{

			//m_vArmor.push_back (dynamic_cast<Armor*>(vec[i]));

			if (dynamic_cast<Armor*>(vec[i]))
				m_vArmor.push_back(dynamic_cast<Armor*> (vec[i]));

			if(dynamic_cast<Weapon*>(vec[i]))
				m_vWeapon.push_back(dynamic_cast<Weapon*>(vec[i]));

		}
	
}

ItemFactory::~ItemFactory()
{
}

int ItemFactory::randomValue(int iMax)
{
	static mt19937 mt(time(NULL));
	return mt() % iMax;
}




Item* ItemFactory:: generateItem(int iMaxLevel, string itemType)
{
	static mt19937 mt(time(NULL));


	
	//armor
	if (itemType == "Armor")
	{
		vector <Armor*> appropriateLevelArmor;
		for (int i=0; i < m_vArmor.size(); i++) 
		{
			if (m_vArmor[i]->getValue() <= iMaxLevel)
				appropriateLevelArmor.push_back(m_vArmor[i]);
		}

	
		int randomly_chosen_item = mt() % appropriateLevelArmor.size();

		Armor *pReturnValue = new Armor(*appropriateLevelArmor[randomly_chosen_item]);

		//pReturnValue->dumpObject();

		return pReturnValue;
	}

	else if (itemType == "Weapon")
	{
		vector <Weapon*> appropriateLevelWeapon;
		for (int i=0; i < m_vWeapon.size(); i++) 
		{
			if (m_vWeapon[i]->getValue() <= iMaxLevel)
				appropriateLevelWeapon.push_back(m_vWeapon[i]);
		}

	
		int randomly_chosen_item = mt() % appropriateLevelWeapon.size();

		Weapon *pReturnValue = new Weapon(*appropriateLevelWeapon[randomly_chosen_item]);

		//pReturnValue->dumpObject();

		return pReturnValue;

	}



	else
	{
		
	}
	






}
