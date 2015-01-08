#include "Tile.h"
#include "Consumable.h"
using namespace std;

Tile::Tile()
{

	mapChar = ' ';
	//char itemChar;
	//char unitChar;

	unitHere = false;
	itemHere = false;


}

vector<Entity> Tile::getItemList2()
{
	return itemsOnFloor;
}


vector<Item*> Tile::getItemList()
{
	return itemsPtrsOnFloor;
}
void Tile::addItemToTile(Item* anItem)
{
	/////DO NOT ERASE, POLYMORPHISM::
	Armor* aPtr = dynamic_cast<Armor*>(anItem);
	if ( aPtr != NULL)
	{
		itemsPtrsOnFloor.push_back(dynamic_cast<Armor*>(aPtr));

		//cout << endl << itemsPtrsOnFloor.back()->getName() << " is my name again. " << itemsPtrsOnFloor.back()->getDisplayChar() << endl;

		itemsOnFloor.push_back(*itemsPtrsOnFloor.back());
	}

	Weapon* wPtr = dynamic_cast<Weapon*>(anItem);
	if (wPtr != NULL)
	{
		itemsPtrsOnFloor.push_back(dynamic_cast<Weapon*>(wPtr));
		itemsOnFloor.push_back(*itemsPtrsOnFloor.back());
	}

	
	Consumable* cPtr = dynamic_cast<Consumable*>(anItem);
	if (cPtr != NULL)
	{
		itemsPtrsOnFloor.push_back(dynamic_cast<Consumable*>(cPtr));
		itemsOnFloor.push_back(*itemsPtrsOnFloor.back());
	}
	

}


Item* Tile::pickupItem(int i) 
{
	return itemsPtrsOnFloor[i];

}


void Tile::deleteItem(int i)
{
	itemsPtrsOnFloor.erase(itemsPtrsOnFloor.begin()+i);
	itemsOnFloor.erase(itemsOnFloor.begin()+i);

}



char Tile::getTileChar()
{
	if (isUnitHere() == true)
		return getUnitChar();
	else if (isItemHere() == true || itemsPtrsOnFloor.size() > 0)
	{
		/*

		//if ( itemsOnFloor.back().getName() == "rags" || itemsOnFloor.back().getName() == "stick")
			//return itemsOnFloor.back().getDisplayChar();
		

		for (int i=0; i < itemsPtrsOnFloor.size(); i++)
		{
			//bug here:
			//if(!(itemsPtrsOnFloor[i]->getName() == "rags" || itemsPtrsOnFloor[i]->getName() == "stick"))
			if(!(itemsPtrsOnFloor[i]->getDisplayChar() == '.')) // || itemsPtrsOnFloor[i]->getDisplayChar() == "stick"))
				return itemsPtrsOnFloor[i]->getDisplayChar(); //why no return here?? cannot read itemsOnFloor[i] display char?
		}
		*/

		//return itemsPtrsOnFloor.back()->getDisplayChar();
		return getItemChar();

	}
	
	else
		return mapChar;
	
}

//old
char Tile::get_tile_char()
{
	return mapChar;
}

//old
void Tile::set_tile_char(char new_char)
{
	mapChar = new_char;
}


char Tile::getMapChar()
{
	return mapChar;
}
char Tile::getItemChar()
{
	return itemChar;
}
char Tile::getUnitChar()
{
	return unitChar;
}
void Tile::setMapChar(char aChar)
{
	mapChar = aChar;
}
void Tile::setItemChar(char aChar)
{
	itemChar = aChar;
}
void Tile::setUnitChar(char aChar)
{
	unitChar = aChar;
}

bool Tile::isUnitHere()
{
	if (unitHere == true)
		return true;
	else
		return false;
}
bool Tile::isItemHere()
{
	if (itemHere == false && itemsPtrsOnFloor.size() == 0)
		return false;
	else
		return true;
}
void Tile::setUnitHere(bool condition)
{
	unitHere = condition;
}
void Tile::setItemHere(bool condition)
{
	itemHere = condition;
}