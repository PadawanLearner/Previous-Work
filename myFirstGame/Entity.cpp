#include "Entity.h"
#include <chrono>
#include <ctime>
#include <random>

using namespace std;

Entity::Entity(void)
{
	m_cDisplayChar = '?';
}


Entity::~Entity(void)
{
}

void Entity::randomizePosition(vector<string> grid_image)
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	mt19937 generate_num( seed );


	x_pos = generate_num() % 78;
	y_pos = generate_num() % 19;


	while (!(grid_image[y_pos][x_pos] == '.'))
	{
		x_pos = generate_num() % 78;
		y_pos = generate_num() % 19;
	}

}


void Entity::setpreviousTurnImage(std::vector<std::vector<char>> &turnImage)
{
	previousTurnImage = turnImage;
}


vector<vector<char>> Entity::getpreviousTurnImage()
{
	return previousTurnImage;
}


void Entity::setxPos(int x)
{
	x_pos = x_pos + x; //set x to an integer
}

void Entity::setyPos(int y)
{
	y_pos = y_pos + y; //set y to an integer
}


int Entity::getxPos()
{
	return x_pos;
}


int Entity::getyPos()
{
	return y_pos;
}

void Entity::dumpObject()
{
	cout << "Entity:" << endl;
	dumpObjectData();
}

void Entity::dumpObjectData()
{
	XMLSerializable::dumpObjectData();

	cout << "          [Name] " << getName() << endl;
	cout << "   [DisplayChar] " << getDisplayChar() << endl;
}

void Entity::writeFragment(ostream & output)
{
	output << "   <Entity>" << endl;
	writeDataAsFragment(output);
	output << "   </Entity>" << endl;
}

void Entity::writeDataAsFragment(ostream & output)
{
	XMLSerializable::writeDataAsFragment(output);

	output << "      <name>" << getName() << "</name>" << endl;
	output << "      <displayChar>" << getDisplayChar() << "</displayChar>" << endl;
}

void Entity::setElementData(string sElementName, string sValue)
{
	XMLSerializable::setElementData(sElementName, sValue);


	if( sElementName == "name" )
	{
		setName(sValue);
	}
	else if( sElementName == "displayChar" )
	{
		if( sValue.length() > 0 )
			setDisplayChar(sValue[0]);
	}
}

string Entity::getName()
{
	return m_sName;
}

void Entity::setName(string sName)
{
		m_sName = sName;
}

char Entity::getDisplayChar()
{
	return m_cDisplayChar;
}

void Entity::setDisplayChar(char cDisplayChar)
{
	m_cDisplayChar = cDisplayChar;
}

