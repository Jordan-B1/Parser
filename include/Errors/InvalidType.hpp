#include <exception>
#include <iostream>

#ifndef INVALIDTYPE_HPP_
#define INVALIDTYPE_HPP_

namespace BasicParser {

    class InvalidType: public std::exception {
        public:
            InvalidType(const std::string &msg);
            ~InvalidType() = default;
            const char *what() const noexcept;


        private:
            std::string _msg;
    };

}

#endif /* !INVALIDTYPE_HPP_ */
