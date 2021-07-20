#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cstring>

#include "Errors/InvalidType.hpp"
#include "Errors/InvalidValue.hpp"

#include "Utils/Utils.hpp"

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

namespace Bracket {

    class Block {
        public:
            Block() = default;
            ~Block() = default;
            void loadData(std::vector<std::string> dataBlock);
            template <typename T>
            T get(const std::string &field) const;
            bool has(const std::string &field) const noexcept;
            std::string operator[](const std::string &field) const noexcept;

        private:
            std::unordered_map<std::string, std::string> _values;
    };

}

#endif /* !BLOCK_HPP_ */
