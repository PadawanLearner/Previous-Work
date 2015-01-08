#include "Unit.h"

#include <cstdlib>

using namespace std;

Unit::Unit(void)
{
	m_iHealth = 10;
	m_iLevel = 1;
	maxHealth = m_iHealth;
}


Unit::~Unit(void)
{
}


void Unit::setMaxHealth(int newMaxHp)
{
	maxHealth = newMaxHp;
}

int Unit::getMaxHealth()
{
	return maxHealth;
}



bool Unit::isMoveValid(int x, int y,vector <vector<Tile*> >  game) 
{

	//OOR
	if (y+getyPos() > 19 ||  x+getxPos() > 78 || y+getyPos() < 0 ||  x+getxPos() < 0)
		return false;

	if (game[y+getyPos()][x+getxPos()]->isUnitHere() == true)
		return false;

	else if(game[y+getyPos()][x+getxPos()]->getMapChar() == ' ')
		return false;

	//else if(!(getpreviousTurnImage()[y+getyPos()][x+getxPos()] == ' ' || getpreviousTurnImage()[y+getyPos()][x+getxPos()] == '*'))
		//return true;
	else
		return true;


}


void Unit::dumpObject()
{
	cout << "Unit:" << endl;
	dumpObjectData();
}

void Unit::dumpObjectData()
{
	Entity::dumpObjectData();

	cout << "        [Health] " << getHealth() << endl;
	cout << "         [Level] " << getLevel() << endl;
}

void Unit::writeFragment(ostream & output)
{
	output << "   <Unit>" << endl;
	writeDataAsFragment(output);
	output << "   </Unit>" << endl;
}

void Unit::writeDataAsFragment(ostream & output)
{
	Entity::writeDataAsFragment(output);

	output << "      <health>" << getHealth() << "</health>" << endl;
	output << "      <level>" << getLevel() << "</level>" << endl;

}

void Unit::setElementData(string sElementName, string sValue)
{
	Entity::setElementData(sElementName, sValue);

	if( sElementName == "health" )
	{
		setHealth(atoi(sValue.c_str()));
	}

	if( sElementName == "level" )
	{
		setLevel(atoi(sValue.c_str()));
	}
}



int Unit::getHealth()
{
	return m_iHealth;
}

void Unit::setHealth(int iHealth)
{
	m_iHealth = iHealth;
}

int Unit::getLevel()
{
	return m_iLevel;
}

void Unit::setLevel(int iLevel)
{
	m_iLevel = iLevel;
}



void Unit::attack(Unit & target)
{
	target.setHealth(target.getHealth()-2);
	cout << endl << "Level " << getLevel()<< " " << getName() << " hit " << target.getName() << " for 2"; 
}
