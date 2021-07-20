#include "Errors/InvalidType.hpp"

BasicParser::InvalidType::InvalidType(const std::string &msg)
: std::exception(), _msg(msg)
{
}

const char *BasicParser::InvalidType::what() const noexcept
{
    return this->_msg.c_str();
}