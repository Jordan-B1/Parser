#include "Errors/InvalidValue.hpp"

BasicParser::InvalidValue::InvalidValue(const std::string &msg)
: std::exception(), _msg(msg)
{
}

const char *BasicParser::InvalidValue::what() const noexcept
{
    return this->_msg.c_str();
}

