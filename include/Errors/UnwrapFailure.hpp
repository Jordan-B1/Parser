#include <exception>
#include <iostream>

#ifndef UNWRAPFAILURE_HPP_
#define UNWRAPFAILURE_HPP_

namespace BasicParser {

    class UnwrapFailure: public std::exception {
        public:
            UnwrapFailure(const std::string &msg);
            ~UnwrapFailure() = default;
            const char *what() const noexcept;

        private:
            std::string _msg;
    };

}

#endif /* !UNWRAPFAILURE_HPP_ */
