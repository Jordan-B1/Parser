#include "BracketParser/BracketParser.hpp"

int main()
{
    BasicParser::BracketParser p;

    p.loadFromFile("sample/menu.bracket");
    auto tab = p.searchDocument({
        {"position_y", "527"},
        {"name", "more_ant"}
    });
    // autocolor
    if (tab[0].has("color")) {
        auto color = tab[0].get<std::vector<float>>("color");
        for (auto it = color.begin(); it != color.end(); it++) {
            if (it == color.begin()) {
                std::cout << "[" << *it;
            } else if (it == color.end() - 1) {
                std::cout << ", " << *it << "]" << std::endl;
            } else {
                std::cout << ", " << *it;
            }
        }
        //std::cout << "parsed document of posX: " << tab[0].get<int>("position_x") << std::endl;
    } else {
        std::cerr << "no color found..." << std::endl;
    }
    return 0;
}