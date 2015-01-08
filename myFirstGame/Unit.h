#ifndef _Unit_included_
#define _Unit_included_

#include "Entity.h"
#include <vector>
#include "Tile.h"
#include "Weapon.h"
#include "Armor.h"

class Unit :
	public Entity
{
public:
	Unit(void);
	virtual ~Unit(void);

	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual int getHealth();
	virtual void setHealth(int iHealth);
	virtual int getLevel();
	virtual void setLevel(int iLevel);


	virtual bool isMoveValid(int x, int y,vector <vector<Tile*> >  game);
	virtual void attack(Unit & target);

	void setMaxHealth(int newMaxHp);
	int getMaxHealth();

	
private:
	int m_iHealth;
	int m_iLevel;
	int maxHealth;

};

#endif

