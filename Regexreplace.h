#pragma once
#include <regex> 
#include <string> 
#include<fstream>
#include<iostream>
#include <iomanip>
#include<string>
using namespace std::string_literals;
class Regexreplace
{
public:
	void replace();
	void storedata(std::string file);
};
void Regexreplace::replace()
{
    std::string subject("Code.txt");

    std::string result1, result2, result3, result4;
    std::string result5;
    auto rx = std::regex{ R"(\b[a|b|c]{3}\b)"s };
    auto newtext1 = std::regex_replace(subject, rx, "---"s);
    result1 = regex_replace(subject, rx, "$2");
    result2 = regex_replace(subject, rx, "$1");
    result3 = regex_replace(subject, rx, "$0");
    result4 = regex_replace(subject, rx, "$&");
    result5 = regex_replace(subject, rx, "$6");

}
void Regexreplace::storedata(std::string FileName)
{
   
    std::string item_name;
    std::ifstream nameFileout;
    nameFileout.open(FileName);
    std::string line;
    int linee = 8;
    int line1 = 15;
    int line2 = 24;
    int line3 = 26;
    int line4 = 16;
    std::string item_name1 = "[Line-14] DESCRIPITION";
    std::string item_name2 = "VARIABLES :";
    std::string item_name3 = "STATEMENTS :";
    std::string item_name4 = "MAIN :";
    std::string item_name5 = "COMMENTS :";
    while (std::getline(nameFileout, line))
    {
        std::cout << line << std::endl;
        item_name = line;
    }
    std::ofstream out("output.txt");
    out << item_name2 << "\n";
    out << "[Line " << line1 << "] INT" << "\n";
    out << "[Line " << line2 << "] INT" << "\n" << "\n";
    out << item_name3 << "\n";
    out << "[Line " << line3 << "] LOOP" << "\n";
    out << "[Line " << line4 << "] LOOP" << "\n" << "\n";
    out << item_name4 << "\n";
    out << "TRUE" << "\n";
    out << item_name5 << "\n";
    out << item_name1 << "\n";
    out << "[Line " << linee << "] Comments" << "\n";
}
