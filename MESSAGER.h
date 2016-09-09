#pragma once
//--------------ON_MESSAGE----------------
template <class TYPE>
void OnLBClick(TYPE T)
{
	if (typeid(T).name() == typeid(FORM_X).name())
	{
		std::cout << "\nFORM CLICKED\n";
		//HWND window = CreateWindowExA(0, NULL, "TST", 0, 0, 0, 10, 20, GetConsoleWindow(), NULL, NULL, NULL);
		HWND window = CreateWindowA(NULL, "TEST", 1, 44, 500, 1000, 500, NULL, NULL, NULL, NULL);
	}
	if (typeid(T).name() == typeid(BUTTON).name())
	{
		std::cout << "\nBUTTON CLICKED\n";
	}
	
}

//
//template <class TYPE>
//void OnLBClick(TYPE &t)
//{
//	std::cout << t.BUTTON_LENGTH;
//}
//
//template <class TYPE>
//void OnLBClick(TYPE &t)
//{
//	std::cout << t.BUTTON_LENGTH;
//}


