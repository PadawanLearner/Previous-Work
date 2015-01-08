#ifndef _Player_included_
#define _Player_included_

#include "Unit.h"
#include "Weapon.h"

using namespace std;

class Player :
	public Unit
{
public:
	Player(void);
	virtual ~Player(void);

	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	bool move(char & input, vector <vector<Tile*> >  game);



	virtual int getExperience();
	virtual void setExperience(int iExperience);

	virtual void attack(Unit & target);


	
	void setInventoryWeapon(Weapon* newWeapon);
	Weapon* getInventoryWeapon();

	void setInventoryArmour(Armor* newArmour);
	Armor* getInventoryArmour();


private:
	int m_iExperience;

	Weapon* inventoryWeapon; 
	Weapon* myPtr2;

	Armor* inventoryArmour;
	Armor* myPtr;
};

#endif

