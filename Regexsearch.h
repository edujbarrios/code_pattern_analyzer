#pragma once
#include <regex> 
#include <string> 
#include <iomanip>
#include<iostream>
#include<string>
using namespace std::string_literals;
class Regexsearch
{
public:
	void search();
	void other();
};
void Regexsearch::search()
{
    std::string s("// Returns the factorial of the argument");
    std::smatch m;
    std::regex e("\\b(sub)([^ ]*)"); 

    while (std::regex_search(s, m, e)) {
        for (auto x : m) 
        s = m.suffix().str();
    }
    
}
void Regexsearch::other()
{
    std::string text = "int i = 1; i <= limit ; ++ i";
    auto pattern{ R"(^(?!#)(\w+)\s*=\s*([\w\d]+[\w\d._,\-:]*)$)"s };
    auto text1{ "abc aa bca ca bbbb"s };
    auto rx = std::regex{ R"(\b[a|b|c]{3}\b)"s };
    auto newtext1 = std::regex_replace(text, rx, "---"s);
    auto text2{ "test123, ejemplo12"s };
    auto rx1 = std::regex{ R"((\w+),\s*(\w+))"s };
    auto newtext2 = std::regex_replace(text, rx, "$2 $1"s);
    auto rx2 = std::regex{ pattern };
    auto match = std::smatch{};
    if (std::regex_search(text, match, rx2))
    {
       // std::cout << match[1] << '=' << match[2] << std::endl;
    }
}
