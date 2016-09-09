#pragma once 
#ifndef IOSTREAM
#include <iostream>
#endif // IOSTREAM
#ifndef VECTOR
#include <vector>
#endif
#ifndef STRING
#include <string>
#endif
#ifndef MEMORY
#include <memory>
#endif


# pragma warning(disable: 4127 4189 4459 4996 4507 34 4385 4700)
//#define _CRT_SECURE_NO_WARNINGS
namespace PROPERTIES
{
	class parse
	{
		std::vector<std::string> file_c;
		std::vector<int> FORM_X_PROPERTIES;
		std::vector<int> BUTTON_X_PROPERTIES;
		char* toparse;
	public:
		std::string val_parsed;
		std::string parsing(int type);
		parse(char * toparse, std::string file, int type);
		~parse() { /*std::cout << "DELETED!"; */}

		std::vector<int> FGetProperties(int BUTTON_INDEX, int COMPONENT_FOR_PARSING);
	};


	parse::parse(char * toparse, std::string file, int type)
	{
		std::cout << file.c_str();
		FILE* fp = nullptr;
		char ch;
		std::string temp;
		this->toparse = new char[strlen(toparse)]{ NULL };
		strcat(this->toparse, toparse);
		fopen_s(&fp, file.c_str(), "rb");
		if (fp)
		{
			ch = getc(fp);
			temp += ch;
			while (ch != -1)
			{
				ch = getc(fp);
				if (ch != ';')
				{
					temp += ch;
				}
				else
				{
					file_c.push_back(temp);
					temp = "";
				}
			}
			parsing(type);
		}
		else
		{
			std::cout << "\nNO SUCH CONFIG FILE!\n";
		}
	}


	std::string parse::parsing(int type)
	{
		std::string temp;
		std::string tt;
		std::string secname;
		bool trigger = false;
		int tmp;

		for (int i = 0; i < file_c.size(); i++)
		{
			tt = file_c[i] + '\0';
			for (int x = 0; x < tt.length(); x++)
			{
				if (tt[x] == '[')
				{
					tmp = x + 1;
					while (tt[tmp] != ']')
					{
						temp += tt[tmp];
						tmp++;
					}
					if (!strcmp(temp.c_str(), toparse))
					{
						tmp++;
						if (tt[tmp] == '<')
						{
							tmp++;
							//tmp += 2;
							while (tt[tmp] != '>')
							{

								if (tt[tmp])
								{
									val_parsed += tt[tmp];

								}
								tmp++;
							}
							
							//val_parsed = '\0';
						}
					}

				}
			}
			//std::cout << val_parsed;
			if (type == 0)
			{
				FORM_X_PROPERTIES.push_back(atoi(val_parsed.c_str()));
			}
			else if (type == 1)
			{
				BUTTON_X_PROPERTIES.push_back(atoi(val_parsed.c_str()));
			}
			temp = "";

		}
		return "";
	}
	std::vector<int> parse::FGetProperties(int BUTTON_INDEX, int COMPONENT_FOR_PARSING)
	{
		std::unique_ptr<char[]> tosearch(new char[6]{'X'});
		std::unique_ptr<char[]> par_val(new char[2]{'X'});
		itoa(BUTTON_INDEX, par_val.get(), 10);
		try
		{
			strcat_s(tosearch.get(), strlen(tosearch.get())+2, par_val.get());
			//strcat_s(tosearch, strlen(tosearch), '\0');
		}
		catch (...)
		{
			
		}
		parse PROPERTIES("BUTTON1", "FORM", COMPONENT_FOR_PARSING);

		return this->FORM_X_PROPERTIES;


	}

}