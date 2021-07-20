#include <iostream>
#include <exception>

#ifndef INVALIDVALUE_HPP_
#define INVALIDVALUE_HPP_

namespace BasicParser {

    class InvalidValue: public std::exception {
        public:
            InvalidValue(const std::string &msg);
            ~InvalidValue() = default;
            const char *what() const noexcept;

        private:
            std::string _msg;
    };

}

#endif /* !INVALIDVALUE_HPP_ */
