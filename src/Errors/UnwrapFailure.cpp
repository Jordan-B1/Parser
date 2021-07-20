#include "Errors/UnwrapFailure.hpp"

BasicParser::UnwrapFailure::UnwrapFailure(const std::string &msg)
: std::exception(), _msg(msg)
{
}

const char *BasicParser::UnwrapFailure::what() const noexcept
{
    return this->_msg.c_str();
}