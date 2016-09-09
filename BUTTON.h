#pragma once

#ifndef MESSAGER_H
#include "MESSAGER.h"
#endif // !BUTTON_H

#ifndef DRAW_COMPONENT_H
#include "DRAW_COMPONENT.h"
#endif // !DRAW_COMPONENT_H

#ifndef SETTINGS_H
#include "SETTINGS.h"
#endif

class BUTTON
{
	POINT button = { 0 };
	int TEMP_X;
	int TEMP_Y;
	BUTTON *TMP_BTN;
public:
	int BUTTON_LENGTH = 4;
	int BUTTON_HEIGTH = 4;
//	void CHECK_COORDS(POINT XY, POINT WINCOOR);
	 void Create(char *caption, POINT BUTTON_COORDINATES, BUTTON tmp);
	 POINT GET_COORDINATES_BTN() { return this->button; };
	 BUTTON() {}
	~BUTTON() {};
	//void DRAW_BTN();
};


void BUTTON::Create(char *caption, POINT BUTTON_COORDINATES, BUTTON tmp)
{
	std::vector<int> temp;
	PROPERTIES::parse BUTTON_SETTINGS("BUTTON", "FORM", 1);
	temp = BUTTON_SETTINGS.FGetProperties(1, 1);
	try
	{
		if (temp[2] != NULL)
		{
			this->button.x = temp[2];
		}
		if (temp[3] != NULL)
		{
			this->button.x = temp[3];
		}
	}
	catch (...)
	{
		std::cout << GetLastError();
	}
	DRAW_ELEMENT BUTTON1_DRAW(DRAW_ELEMENT::ENTITIES::BUTTON, BUTTON_LENGTH, BUTTON_HEIGTH, button);

	std::cout << "BUTTON CREATED";
	this->button = BUTTON_COORDINATES;

	this->TMP_BTN = &tmp;
	OnLBClick(tmp);
}


