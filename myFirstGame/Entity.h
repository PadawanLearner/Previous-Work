#ifndef _Entity_included_
#define _Entity_included_

#include "XMLSerializable.h"
//#include "Tile.h"
#include <vector>

class Entity :
	public XMLSerializable
{
public:
	Entity(void);
	virtual ~Entity(void);

	virtual void randomizePosition(std::vector<std::string> grid_image);
	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);

	virtual std::string getName();
	virtual void setName(std::string sName);
	virtual char getDisplayChar();
	virtual void setDisplayChar(char cDisplayChar);
	virtual int getxPos();
	virtual int getyPos();
	virtual void setxPos(int x);
	virtual void setyPos(int y);
	virtual std::vector<std::vector<char>> getpreviousTurnImage();
	virtual void setpreviousTurnImage(std::vector<std::vector<char>> &turnImage);


private:
	std::string m_sName;
	char m_cDisplayChar;

	std::vector<std::vector<char>> previousTurnImage; //use tiles?

	int x_pos;
	int y_pos;

	

	//std::vector <vector<Tile> > gameGrid;

};

#endif
