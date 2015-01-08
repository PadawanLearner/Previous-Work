#include "Weapon.h"

#include <cstdlib>

using namespace std;

Weapon::Weapon(void)
{
	m_iDamage = 0;
}


Weapon::~Weapon(void)
{
}

Weapon::Weapon(const Weapon &newWeapon)
{
	*this = newWeapon;
}


bool Weapon::isArmour()
{
	return false;
}


void Weapon::dumpObject()
{
	cout << "Weapon:" << endl;
	dumpObjectData();
}

void Weapon::dumpObjectData()
{
	Item::dumpObjectData();

	cout << "        [Damage] " << getDamage() << endl;
	cout << "          [Type] " << getType() << endl;
}

void Weapon::writeFragment(ostream & output)
{
	output << "   <Weapon>" << endl;
	writeDataAsFragment(output);
	output << "   </Weapon>" << endl;
}

void Weapon::writeDataAsFragment(ostream & output)
{
	Item::writeDataAsFragment(output);

	output << "      <damage>" << getDamage() << "</damage>" << endl;
	output << "      <type>" << getType() << "</type>" << endl;
}

void Weapon::setElementData(string sElementName, string sValue)
{
	Item::setElementData(sElementName, sValue);

	if( sElementName == "damage" )
	{
		setDamage(atoi(sValue.c_str()));
	}
	else if( sElementName == "type" )
	{
		setType(sValue);
	}
}


int Weapon::getDamage()
{
	return m_iDamage;
}

void Weapon::setDamage(int iDamage)
{
	m_iDamage = iDamage;
}

string Weapon::getType()
{
	return m_sType;
}

void Weapon::setType(string sType)
{
	m_sType = sType;
}

