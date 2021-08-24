#include "BracketParser/Block/Block.hpp"

void Bracket::Block::loadData(std::vector<std::string> dataBlock)
{
    dataBlock.erase(dataBlock.begin());
    dataBlock.erase(dataBlock.end() - 1);
    std::string tmp;
    unsigned long separator = 0;
    std::pair<std::string, std::string> res;

    this->_values.clear();
    for (const auto &i : dataBlock)
    {
        separator = i.find(':');
        if (separator == std::string::npos || separator == 0 || separator == i.size() - 1)
        {
            std::cerr << "[BRACKET PARSER] "
                      << "line unparsed: [" << i << "]" << std::endl;
            continue;
        }
        res.first = i.substr(0, separator);
        res.second = i.substr(separator + 1);
        this->_values.insert(std::make_pair(BasicParser::operator~(res.first), BasicParser::operator~(res.second)));
    }
}

bool Bracket::Block::has(const std::string &field) const noexcept
{
    return this->_values.count(field) != 0;
}

std::string Bracket::Block::operator[](const std::string &field) const noexcept
{
    std::string res;
    auto func = [field](std::pair<std::string, std::string> p)
    {
        return p.first == field;
    };

    if (this->has(field))
    {
        res = this->_values.at(field);
    }
    return res;
}

template <>
std::string Bracket::Block::get<std::string>(const std::string &field) const
{
    return (*this)[field];
}

template <>
int Bracket::Block::get<int>(const std::string &field) const
{
    std::string value;
    auto isPositiveNumber = [](std::string number)
    {
        return !number.empty() && std::count_if(number.begin(), number.end(), [](char a)
                                                { return a < '0' || a > '9'; }) == 0;
    };

    if (!has(field))
    {
        return 0;
    }
    value = this->_values.at(field);
    if (isPositiveNumber(value) || (value[0] == '-' && isPositiveNumber(value.substr(1))))
    {
        return std::atoi(value.c_str());
    }
    else
    {
        throw BasicParser::InvalidType("invalid conversion type int for \"" + field + "\" field");
    }
}

template <>
float Bracket::Block::get<float>(const std::string &field) const
{
    std::string value;
    auto isPositiveNumber = [](std::string number)
    {
        return number.size() > 0 && std::count_if(number.begin(), number.end(), [](char a)
                                                  { return a < '0' || a > '9'; }) == 0;
    };

    if (!has(field))
    {
        return 0;
    }
    value = this->_values.at(field);
    if (isPositiveNumber(value) || (value[0] == '-' &&
                                    isPositiveNumber(value.substr(1)) && std::count(value.begin(), value.end(), '.' < 2)))
    {
        return std::atof(value.c_str());
    }
    else
    {
        throw BasicParser::InvalidType("invalid conversion type float for \"" + field + "\" field");
    }
}

template <>
std::vector<int> Bracket::Block::get<std::vector<int>>(const std::string &field) const
{
    std::vector<int> res;
    std::string value;
    std::string token;
    auto isPositiveNumber = [](std::string number)
    {
        return !number.empty() && std::count_if(number.begin(), number.end(), [](char a)
                                                { return a < '0' || a > '9'; }) == 0;
    };

    if (!has(field))
    {
        return {};
    }
    value = this->_values.at(field);
    value.pop_back();
    value.erase(value.begin());
    token = std::strtok(strdup(value.c_str()), ",");
    while (token.c_str())
    {
        token = BasicParser::operator~(token);
        if (isPositiveNumber(token) || (token[0] == '-' && isPositiveNumber(token.substr(1))))
        {
            res.push_back(std::atoi(token.c_str()));
        }
        else
        {
            throw BasicParser::InvalidValue("Wrong value found while parsing an array");
        }
        try
        {
            token = std::string(std::strtok(nullptr, ","));
        }
        catch (...)
        {
            break;
        }
    }
    return res;
}

template <>
std::vector<float> Bracket::Block::get<std::vector<float>>(const std::string &field) const
{
    std::vector<float> res;
    std::string value;
    std::string token;
    auto isPositiveNumber = [](std::string number)
    {
        return !number.empty() && std::count_if(number.begin(), number.end(), [](char a)
                                                { return ((a < '0' || a > '9') && a != '.'); }) == 0;
    };

    if (!has(field))
    {
        return {};
    }
    value = this->_values.at(field);
    value.pop_back();
    value.erase(value.begin());
    token = std::strtok(strdup(value.c_str()), ",");
    while (token.c_str())
    {
        token = BasicParser::operator~(token);
        if (isPositiveNumber(token) || (token[0] == '-' && isPositiveNumber(token.substr(1)) &&
                                        std::count(token.begin(), token.end(), '.' < 2)))
        {
            res.push_back(std::atof(token.c_str()));
        }
        else
        {
            throw BasicParser::InvalidValue("Wrong value found while parsing an array");
        }
        try
        {
            token = std::string(std::strtok(nullptr, ","));
        }
        catch (...)
        {
            break;
        }
    }
    return res;
}

template <>
std::vector<std::string> Bracket::Block::get<std::vector<std::string>>(const std::string &field) const
{
    std::vector<std::string> res;
    std::string value;
    std::string token;

    if (!has(field))
    {
        return {};
    }
    value = this->_values.at(field);
    value.pop_back();
    value.erase(value.begin());
    token = std::strtok(strdup(value.c_str()), ",");
    while (!token.empty())
    {
        res.push_back(token);
        token = std::strtok(nullptr, ",");
    }
    return res;
}

template<>
bool Bracket::Block::get<bool>(const std::string &field) const
{
    std::string val;

    if (!has(field)) {
        return false;
    }
    val = this->_values.at(field);
    if (val != "true" && val != "false") {
        throw BasicParser::InvalidValue("Wrong value found while parsing an array");
    } else {
        return val == "true";
    }
}