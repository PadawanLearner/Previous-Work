#ifndef _Armor_included_
#define _Armor_included_

#include "Item.h"

class Armor :
	public Item
{
public:
	Armor(void);
	virtual ~Armor(void);
	Armor(const Armor &newArmor);

	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual int getProtection();
	virtual void setProtection(int iProtection);
	virtual std::string getType();
	virtual void setType(std::string sType);

	bool isArmour();


private:
	int m_iProtection;
	std::string m_sType;
};


#endif
