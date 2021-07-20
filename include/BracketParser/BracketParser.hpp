#include <fstream>

#include "BracketParser/Block/Block.hpp"

#ifndef BRACKETPARSER_HPP_
#define BRACKETPARSER_HPP_

namespace BasicParser {

    class BracketParser {
        public:
            BracketParser() = default;
            ~BracketParser() = default;
            void loadFromFile(const std::string &fileName);
            std::vector<Bracket::Block> searchDocument(std::unordered_map<std::string, std::string> criteria) const noexcept;
            std::vector<Bracket::Block> getDocuments() const noexcept {return this->_documents;};

        private:
            std::vector<Bracket::Block> _documents;
    };

}

#endif /* !BRACKETPARSER_HPP_ */
