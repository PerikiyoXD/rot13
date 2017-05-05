#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <iomanip>

std::string rot13(std::wstring text_to_decode)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::string text = converter.to_bytes(text_to_decode);
    std::cout << "Text to decode: \"" << text << "\"" << std::endl;
	std::string final_result;
	for ( std::string::iterator it=text.begin(); it!=text.end(); ++it)
    {
		if (! isalpha(*it))
		{
			final_result.push_back(*it);
		}
		else
		{
		    bool is_lowcase = islower(*it);
    		std::cout << *it << ": Is lowcase: " << is_lowcase << std::endl;
    		final_result.push_back((is_lowcase == true ? 97 : 65) + (*it - (is_lowcase == true ? 97 : 65) + 13) % 26);
	    }
    }
	std::cout << std::endl;
	return final_result;
}