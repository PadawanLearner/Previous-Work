#ifndef _Consumable_included_
#define _Consumable_included_

#include "Item.h"
#include "Unit.h"  //problem here?

class Consumable :
	public Item
{
public:
	Consumable(void);
	virtual ~Consumable(void);


	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual void use(Unit & user);

	virtual int getHealth();
	virtual void setHealth(int iHealth);
	virtual int getNutrition();
	virtual void setNutrition(int iNutrition);

private:
	int m_iHealth;
	int m_iNutrition;
};

#endif
