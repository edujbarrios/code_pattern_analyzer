#include <regex> 
#include <string> 
#include <iomanip>
#include<iostream>
#include<string>
#include"Regexmatch.h"
#include"Regexreplace.h"
#include"Regexsearch.h"
using namespace std::string_literals;

int main(int argc, char* argv[])
{
    std::string FileName = "";
    FileName = argv[1];
    Regexmatch R1;
    Regexreplace R2;
    Regexsearch R3;
    std::string text = "int i = 1; i <= limit ; ++ i";
	auto pattern{ R"(^(?!#)(\w+)\s*=\s*([\w\d]+[\w\d._,\-:]*)$)"s };
    auto text1{ "abc aa bca ca bbbb"s };
    auto rx = std::regex{ R"(\b[a|b|c]{3}\b)"s };
    auto newtext1 = std::regex_replace(text, rx, "---"s);
   auto text2{ "bancila, marius"s };
    auto rx1 = std::regex{ R"((\w+),\s*(\w+))"s };
    auto newtext2 = std::regex_replace(text, rx, "$2 $1"s);
	auto rx2 = std::regex{ pattern };
    auto match = std::smatch{}; 
    if (std::regex_search(text, match, rx2))
    {
        std::cout << match[1] << '=' << match[2] << std::endl;
    }
    R1.is_valid(text);
    R2.replace();
    R3.other();
    R2.storedata(FileName);
    R1.results();
    R3.search();

    
}