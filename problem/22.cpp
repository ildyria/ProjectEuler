#include "22.h"

void Problem_22::run()
{
	std::vector<char> v;
	std::vector<std::string> string_vect = std::vector<std::string>();
	
	std::ifstream is ("datas/p022_names.txt", std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg (0, is.end);
		int length = is.tellg();
		is.seekg (0, is.beg);

		char * buffer = new char [length];

		// std::cout << "Reading " << length << " characters... "  << std::endl;
		// read data as a block:
		is.read (buffer,length);

		if (is)
		{
			// std::cout << "all characters read successfully." << std::endl;
		}
		else
			std::cout << "error: only " << is.gcount() << " could be read" << std::endl;
		is.close();

		// ...buffer contains the entire file...
		bool nameon = false;
		std::stringstream ss;
		for (int i = 0; i < length; ++i)
		{
			if(buffer[i] == '"' && !nameon)
			{
				nameon = true;
				ss.str(std::string());
			}
			else if(buffer[i] == '"' && nameon)
			{
				nameon = false;
				// place work into the next case of the array
				string_vect.push_back(ss.str());
				//std::cout << ss.str() << std::endl;
			}
			else if(nameon)
			{
				ss << buffer[i];
			}
		}

		sort(string_vect.begin(),string_vect.end());

		u_long sum = 0;
		u_int val_name;
		// std::cout << string_vect.size() << std::endl;
		for (u_int i = 0; i < string_vect.size(); ++i)
		{
			val_name = 0;
			for (u_int j = 0; j < string_vect[i].length(); ++j)
			{
				val_name += string_vect[i][j] - 'A' + 1;	
			}
			sum += (i+1)*val_name;
		}

		std::cout << sum << std::endl;

		delete[] buffer;
	}
	else
	{
		std::cout << "PROBLEM READING FILE" << std::endl;
	}
}

