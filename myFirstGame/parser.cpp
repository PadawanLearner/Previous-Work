#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <functional>
#include <vector>


#include "XMLSerializable.h"

using namespace std;

void parseElement(map<string, function<XMLSerializable * ()>> & mConstructors, istream & input, string sPrefix, XMLSerializable * pObject, vector<XMLSerializable*> & vWorld)
{
	string sElementName;
	getline(input, sElementName, '>');

	if( sElementName.back() == '/' )
	{
		return;
	}
	else
	{
		function<XMLSerializable * ()> pFunc = mConstructors[sElementName];

		if( pFunc != NULL )
		{
			pObject = pFunc();
			vWorld.push_back(pObject);
		}
	}

	string sContent = "";


	while( true )
	{

		char c = input.get();

		while( c != '<' )
		{
			if( c != '\n' )
				sContent.push_back(c);

			c = input.get();
		}

		if( input.peek() == '/' )
		{
			input.get();
			string sEndElement;
			getline(input, sEndElement, '>');

			if( sEndElement != sElementName )
				cout << "Bad XML found" << endl;


			if( pObject )
			{
				pObject->setElementData(sElementName, sContent);
			}

			return;
		}
		else
		{
			parseElement(mConstructors, input, sPrefix + " > " + sElementName, pObject, vWorld);
		}

	}

}

void parseXML(map<string, function<XMLSerializable * ()>> & mConstructors, string sFilename, vector<XMLSerializable*> & vWorld)
{
	
	ifstream input;
	//input.open(sFilename);

	input.open(sFilename.c_str());

	//handle errorneous file name
	while ( input.fail() ) //is failstate?
	{
		cout << endl << "Checking file: incorrect! " << endl 
			<< "What file should we read? "; //prompt user again
		cin >> sFilename;
		input.open(sFilename.c_str());
	}
	
		while(input.get() != '<')
	{
	}

	if( input.get() != '?' )
	{
		cout << "Invalid header" << endl;
		return;
	}

	while( input.get() != '?')
	{
	}


	if( input.get() != '>')
	{
                cout << "Invalid header" << endl;
                return;
	}

	while(input.get() != '<')
	{
	}
	//the above just skips over the firs line in the XML doc + the '<' in the first element listing

	parseElement(mConstructors, input, "> ", NULL, vWorld);

	//parseElement(input, "", v1); //call recursion
	




	
/*	
	while( input.get() != '?' )
	{
		cout << input.get();		
	};
	while( input.get() != '?' );
	
	if( input.get() != '>' )
	{
		cout << "Bad XML detected" << endl;
		return;
	}

	while( input.get() != '<' );
	

	parseElement(mConstructors, input, "> ", NULL, vWorld);
*/	
}

/*
{
	while(input.get() != '<')
	{
	}

	if( input.get() != '?' )
	{
		cout << "Invalid header" << endl;
		return;
	}

	while( input.get() != '?')
	{
	}


	if( input.get() != '>')
	{
                cout << "Invalid header" << endl;
                return;
	}

	while(input.get() != '<')
	{
	}
	//the above just skips over the firs line in the XML doc + the '<' in the first element listing

	parseElement(input, "", v1); //call recursion

}
*/

