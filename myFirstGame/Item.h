#ifndef _Item_included_
#define _Item_included_

#include "Entity.h"

class Unit;

using namespace std;

class Item :
	public Entity
{
public:
	Item(void);
	virtual ~Item(void);
	Item(const Item & copied_item);
	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual int getWeight();
	virtual void setWeight(int iWeight);
	virtual int getValue();
	virtual void setValue(int iValue);
	virtual int getQuantity();
	virtual void setQuantity(int iQuantity);
	virtual void use(Unit & user);

	//virtual bool isArmor();

private:
	int m_iWeight;
	int m_iValue;
	int m_iQuantity;

};

#endif
