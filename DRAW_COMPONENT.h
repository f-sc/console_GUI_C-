#pragma once

#ifndef IOSTREAM
#include <iostream>
#endif

#ifndef VECTOR_H
#include <vector>
#endif // !VECTOR_H

#ifndef WINDOWS_H
#include <Windows.h>
#endif // !VECTOR_H


#define type_ofc '-'
#define type_ofc_Y '|'

POINT FBC = { 0 };



class DRAW_ELEMENT
{
	std::vector <char> symbols;
	std::vector<std::vector<char>> mainframe;
	int SIZE_X;
	int SIZE_Y;
	int POS_X;
	int POS_Y;
	void BUTTON_DRAW();
	void PROGRESS(int progress);
public:
	enum ENTITIES { BUTTON, PROGRESS_BAR, EDIT };

	DRAW_ELEMENT(ENTITIES ITEM, int SIZE_X, int SIZE_Y, POINT COOR);
	DRAW_ELEMENT(ENTITIES ITEM, int SIZE_X, int SIZE_Y, POINT PB_COOR, int FPROGRESS);
	~DRAW_ELEMENT() {};
};

void DRAW_ELEMENT::BUTTON_DRAW()
{
	std::string tempr;
	for (int LINE = 0; LINE < this->SIZE_Y; LINE++)
	{
		switch (LINE)
		{
		case 0:
			full: for (int i = 0; i < this->SIZE_X; i++)
			{
				this->symbols.push_back(type_ofc);

			}
				  this->mainframe.push_back(symbols);
				  this->symbols.clear();
				  break;
		case 1:
			for (int i = 0; i < this->SIZE_X; i++)
			{
				this->symbols.push_back('|');
				if (i != ((this->SIZE_X / 2) - 1) && i != 0 && i != this->SIZE_X)
				{
					this->symbols.push_back(' ');
				}
				else
				{
					this->symbols.push_back('o');
					this->symbols.push_back('k');
				}

			}
			this->mainframe.push_back(symbols);
			this->symbols.clear();
			break;
		case 2:
			goto full;
			break;

		}
	}
	for (int y = 0; y < this->POS_Y; y++)
	{
		tempr += '\n';

	}
	for (int t = 0; t < this->SIZE_Y - 1; t++)
	{
		for (int x = 0; x < this->POS_X; x++)
		{
			tempr += " ";


		}

		for (int k = 0; k < this->SIZE_X; k++)
		{

			tempr += this->mainframe[t][k];
			if (k == this->SIZE_X - 1)
			{
				tempr += '\n';
			}
		}

	}
	std::cout << tempr.c_str() << std::endl;
}

DRAW_ELEMENT::DRAW_ELEMENT(ENTITIES ITEM, int SIZE_X, int SIZE_Y, POINT COOR)
{
	this->SIZE_X = SIZE_X;
	this->SIZE_Y = SIZE_Y;
	this->POS_X = COOR.x;
	this->POS_Y = COOR.y;
	if (ITEM == DRAW_ELEMENT::ENTITIES::BUTTON)
	{

		BUTTON_DRAW();
	}

}
