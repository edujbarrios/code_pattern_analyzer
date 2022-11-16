#pragma once
#include <regex> 
#include <string> 
#include <iomanip>
#include<iostream>
#include<string>
using namespace std::string_literals;
class Regexmatch
{
public:
	//Regexmatch();
    void results();
	bool is_valid(std::string const& email);

};
auto ltest = [](std::string const& email)
{
    Regexmatch R1;
    std::cout << std::setw(30) << std::left
        << email << " : "
        << (R1.is_valid(email) ?
            "valid format" : "invalid format")
        << std::endl;
};
bool Regexmatch::is_valid(std::string const& email)
{
    auto pattern{ R"(^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$)"s };

    auto rx = std::regex{ pattern };

    return std::regex_match(email, rx);
}
void Regexmatch::results()
{
    if (std::regex_match("subject", std::regex("(sub)(.*)")))
        std::cout << " ";

    const char cstr[] = "subject";
    std::string s("subject");
    std::regex e("(sub)(.*)");

    if (std::regex_match(s, e))
        std::cout << " ";

    if (std::regex_match(s.begin(), s.end(), e))
        std::cout << " ";

    std::cmatch cm;
    std::regex_match(cstr, cm, e);
    //std::cout << "string literal with " << cm.size() << " matches\n";

    std::smatch sm;
    std::regex_match(s, sm, e);
    //std::cout << "string object with " << sm.size() << " matches\n";

    std::regex_match(s.cbegin(), s.cend(), sm, e);
  //  std::cout << "range with " << sm.size() << " matches\n";


   // std::regex_match(cstr, cm, e, std::regex_constants::match_default);

   // std::cout << "the matches were: ";
    for (unsigned i = 0; i < sm.size(); ++i) {
        //std::cout << "[" << sm[i] << "] ";
    }

    //std::cout << std::endl;
}
