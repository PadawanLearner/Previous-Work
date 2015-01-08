#ifndef _Weapon_included_
#define _Weapon_included_

#include <string>

#include "Item.h"

class Weapon :
	public Item
{
public:
	Weapon(void);
	virtual ~Weapon(void);
	Weapon(const Weapon &newWeapon);
	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual int getDamage();
	virtual void setDamage(int iDamage);
	virtual std::string getType();
	virtual void setType(std::string sType);
	bool isArmour();
private:
	int m_iDamage;
	std::string m_sType;
};


#endif
