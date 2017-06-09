/******************************************************************************
Copyright 2017 Pedro Luis Valadés Viera

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <iomanip>

std::string cypher::rot13(std::wstring text_to_decode)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	std::string text = converter.to_bytes(text_to_decode);
	std::string final_result;
	for ( std::string::iterator it=text.begin(); it!=text.end(); ++it)
    	{
		if (isalpha(*it))
		{	
			bool is_lowcase = islower(*it);
    			final_result.push_back((is_lowcase == true ? 97 : 65) + (*it - (is_lowcase == true ? 97 : 65) + 13) % 26);
		}
		else
		{
			final_result.push_back(*it);
	    	}
    	}
	std::cout << std::endl;
	return final_result;
}
