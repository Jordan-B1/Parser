#include <iostream>
#include "Errors/UnwrapFailure.hpp"

#ifndef UTILS_HPP_
#define UTILS_HPP_

namespace BasicParser {
    
    enum ResponseStatus {
        OK,
        KO
    };
    
    template <typename T>
    struct Response {
        public:
            ResponseStatus status;
            std::string error = "Ok";

            Response(ResponseStatus s, T d)
            {
                this->status = s;
                this->data = d;
            }

            Response(ResponseStatus s, T d, const std::string &err)
            {
                this->status = s;
                this->data = d;
                this->error = err;   
            }

            T unwrap() const noexcept
            {
                if (this->status == OK) {
                    return this->data;
                } else {
                    throw BasicParser::UnwrapFailure("Unwrapping a KO response...");
                }
            }

        private:
            T data;
    };
    
    std::string operator~(const std::string &str);

}


#endif /* !UTILS_HPP_ */
