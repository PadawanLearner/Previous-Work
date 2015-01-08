#ifndef TILE_H
#define TILE_H

#include "Item.h"
#include <vector>
#include "Armor.h"
#include "Weapon.h"


using namespace std;



class Tile
{
public:
	Tile();

	void set_tile_char(char new_char);

	char get_tile_char();

	char getTileChar();

	//char getPreviousTileChar();
	

	//vector of item*

	char getMapChar();
	char getItemChar();
	char getUnitChar();

	void setMapChar(char aChar);
	void setItemChar(char aChar);
	void setUnitChar(char aChar);

	bool isUnitHere();
	bool isItemHere();

	void setUnitHere(bool condition);
	void setItemHere(bool condition);

	vector<Item*> getItemList();
	void addItemToTile(Item* anItem);
	Item* pickupItem(int i); //, Player &user); //pick up by string? displayChar? int?


	vector<Entity> getItemList2();

	void deleteItem(int i);
	//Armor Tile::pickupArmor(int i);



private:
	char mapChar;
	char itemChar;
	char unitChar;

	bool unitHere;
	bool itemHere;

	Item *ptrTemp;
	Item temp;

	vector<Entity> itemsOnFloor; //one of these needs to be an Entity so you can access ALL of its data, ie the data is being sliced
							//from item on up. entity data getting sliced at every vector<item> pushback call!!!
							//should probably change itemsOnFloor to type Entity and use this for data referral.
	vector<Item*> itemsPtrsOnFloor;


	vector<Armor> armorOnFloor;

	//char previousTileChar;

};





#endif


//new tile design:

//char unitChar
//char itemChar
//char MapChar


//SETTERS FOR ALL OF THE ABOVE

	//hold only one Unit variable
		//bool isUnitOnTile
		//setUnitToTile
		//
	//hold multiple items
		// if (isUnitOnTile == false, DisplayItemChar
		//if (isItemOnTile == false), set original tile
	//vector<Item>



//if (isUnitOnTile == true)
	//do not move  --- reference this with main setup and function call
