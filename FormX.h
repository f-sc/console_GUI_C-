#pragma once
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

#ifndef DRAW_COMPONENT_H
#include "DRAW_COMPONENT.h"
#endif // !DRAW_COMPONENT_H


#ifndef WINDOWS_H
#include <Windows.h>
#endif

#ifndef MESSAGER_H
#include "MESSAGER.h"
#endif

#ifndef BUTTON_H
#include "BUTTON.h"
#endif // !BUTTON_H

#ifndef SETTINGS_H
#include "SETTINGS.h"
#endif // !SETTINGS_H


#ifndef X_FOW
#define X_FOW 1.37
#endif

#ifndef Y_FOW
#define Y_FOW 3.1
#endif


class FORM_X
{
	RECT rect_win;
	RECT rect_FULL;
	HWND wnd;
	double win_x;
	double win_y;
	POINT WINDOW_CURR_POS;
	char *caption;

	BUTTON BUTTON_PTR;

public:
	enum COMPONENTS { FORM, BUTTON, EDIT, PROGRESSBAR };
	virtual void Create(char *caption, COMPONENTS component);
	virtual void GetRects();
	virtual void SetSize();
	virtual void CHECK_COORDS(POINT XY, POINT WINCOOR);
	//virtual POINT FGetWinCoord();
	//virtual void draw();
	virtual HWND GetCurrentWindow() { return wnd; }
	virtual RECT GET_RECT_WIN() { return rect_win; }
	virtual POINT GET_WIN_COORDINATES() { return WINDOW_CURR_POS; }
	virtual void SetCaption(char *text);
	~FORM_X() { delete[] caption; }
	template<class COMPONENT_TYPE>
	void add_ptr_component(COMPONENT_TYPE  ptr);
	//virtual void OnLBClick();
	
};

void FORM_X::Create(char *caption, COMPONENTS component)
{
	try
	{
		GetRects();
		SetSize();
	}
	catch (...)
	{
		std::cout << "Error while initializing, restart application please...";
	}

}

void FORM_X::GetRects()
{
	wnd = GetConsoleWindow();
	GetClientRect(wnd, &rect_win);
	rect_FULL.bottom = GetSystemMetrics(SM_CXFULLSCREEN);
	rect_FULL.top = GetSystemMetrics(SM_CYSCREEN);
	this->SetSize();
}

void FORM_X::SetSize()
{
	win_x = (double(rect_FULL.bottom) / X_FOW);//change current win rect
	win_y = (double(rect_FULL.top) / Y_FOW);
	WINDOW_CURR_POS.x = rect_FULL.bottom - win_x;
	WINDOW_CURR_POS.y = win_y;
	try
	{
		SetWindowPos(wnd, HWND_NOTOPMOST, rect_FULL.bottom - win_x, win_y, rect_win.right + 40, rect_win.bottom + 10, NULL);
	}
	catch (...)
	{
		std::cout << "ERROR: UNABLE TO SET WINDOW SIZE";
	}
}

void FORM_X::SetCaption(char *text)
{
	this->caption = new char[strlen(text)];
//	strcat(this->caption, text);
	strcat_s(this->caption, strlen(text), text);

}

template <class COMPONENT_TYPE>
void FORM_X::add_ptr_component(COMPONENT_TYPE  ptr)
{
	if (typeid(COMPONENT_TYPE).name() == typeid(BUTTON).name())
	{
		this->BUTTON_PTR = ptr;
	}
	/*else if (typeid(COMPONENT_TYPE).name() == typeid(FORM_X).name())
		{
			this->FORM_X_PTR=ptr;
		}*/
}

void FORM_X::CHECK_COORDS(POINT XY, POINT WINCOOR)//XY mouse, WINCOR - wincoords
{
	FORM_X TEMPORARY;
	//std::cout << "\nCHECK_COORDs!\n";
	int TEMP_X = WINCOOR.x + X_FOW + 40;//40
	int TEMP_Y = WINCOOR.y + Y_FOW + 70;//70
	//std::cout << "X_USER: " << XY.x << std::endl;
	//std::cout << "X: " << TEMP_X << std::endl;
	//std::cout << "Y_USER: " << XY.y;
	//std::cout << "Y: " << TEMP_Y;
	if (XY.x <= TEMP_X && XY.y <= TEMP_Y)//WARNING IN FUTURE FOR MORE COMPONENTS !!!!
	{
		OnLBClick(this->BUTTON_PTR);

		
	}
	else
	{
		
		//OnLBClick(TEMPORARY);
	}

}


int main()
{
	POINT BUTTON11 = { 0 };
	FORM_X FORM1;
	BUTTON BUTTON1;
	PROPERTIES::parse COMPONENT_VALUES("BUTTON1", "FORM", 1);
	FORM1.add_ptr_component(BUTTON1);
//	COMPONENT_VALUES.FGetProperties(1, 1);
	try
	{
		FORM1.Create("TEST", FORM1.FORM);
	}
	catch (...)
	{
		std::cout << "Error while form creating, restart application please...";
	}
	
	BUTTON1.Create("HELLO", BUTTON11, BUTTON1);
	

	LBUTON: while (0==0)
	{
		if (GetKeyState(VK_LBUTTON)<0)
		{
			POINT pointer = { 0 };
			GetCursorPos(&pointer);

			FORM1.CHECK_COORDS(pointer, FORM1.GET_WIN_COORDINATES());

			std::this_thread::sleep_for(std::chrono::seconds(1));
			goto LBUTON;
		}
	}

	std::cin.get();

	return 0;
}