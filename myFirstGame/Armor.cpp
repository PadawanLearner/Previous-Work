#include "Armor.h"

#include <cstdlib>

using namespace std;

Armor::Armor(void)
{
	m_iProtection = 0;
}


Armor::Armor(const Armor &newArmor)
{
	*this = newArmor;
}

Armor::~Armor(void)
{
}

bool isArmour()
{
	return true;
}

void Armor::dumpObject()
{
	cout << "Armor:" << endl;
	dumpObjectData();
}

void Armor::dumpObjectData()
{
	Item::dumpObjectData();

	cout << "    [Protection] " << getProtection() << endl;
	cout << "          [Type] " << getType() << endl;

}

void Armor::writeFragment(ostream & output)
{
	output << "   <Armor>" << endl;
	writeDataAsFragment(output);
	output << "   </Armor>" << endl;
}

void Armor::writeDataAsFragment(ostream & output)
{
	Item::writeDataAsFragment(output);

	output << "      <protection>" << getProtection() << "</protection>" << endl;
	output << "      <type>" << getType() << "</protection>" << endl;

}

void Armor::setElementData(string sElementName, string sValue)
{
	Item::setElementData(sElementName, sValue);

	if( sElementName == "protection" )
	{
		setProtection(atoi(sValue.c_str()));
	}

	if( sElementName == "type" )
	{
		setType(sValue);
	}
}

int Armor::getProtection()
{
	return m_iProtection;
}

void Armor::setProtection(int iProtection)
{
	m_iProtection = iProtection;
}

string Armor::getType()
{
	return m_sType;
}

void Armor::setType(string sType)
{
	m_sType = sType;
}




