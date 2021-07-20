#include "BracketParser/BracketParser.hpp"

std::vector<Bracket::Block> BasicParser::BracketParser::searchDocument(std::unordered_map<std::string, std::string> criteria) const noexcept
{
    auto res = _documents;
    
    for (auto i: criteria) {
        res.erase(std::remove_if(res.begin(), res.end(), [i] (Bracket::Block b) {
            return b[i.first] != i.second;
        }), res.end());
    }
    return res;
}

void BasicParser::BracketParser::loadFromFile(const std::string &fileName)
{
    std::fstream f(fileName);
    std::string lineHolder;
    std::vector<std::string> blockHolder;
    Bracket::Block b;

    while (std::getline(f, lineHolder)) {
        if (lineHolder == "{") {
            blockHolder.push_back(lineHolder);
            std::getline(f, lineHolder);
            while (lineHolder != "}") {
                if (lineHolder.empty()) {
                    continue;
                }
                blockHolder.push_back(lineHolder);
                std::getline(f, lineHolder);
            }
            blockHolder.push_back(lineHolder);
            b.loadData(blockHolder);
            this->_documents.push_back(b);
            blockHolder.clear();
        }
    }
    f.close();
}