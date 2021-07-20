#include "Utils/Utils.hpp"

std::string BasicParser::operator~(const std::string &str)
{
    int start = 0;
    int end = str.size() - 1;

    for (; str[start] == ' ' || str[start] == '\t'; start++);
    for (; str[end] == ' ' || str[end] == '\t'; end--);
    return str.substr(start, end - start + 1);
}