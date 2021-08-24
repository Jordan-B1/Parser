#include "BracketParser/BracketParser.hpp"

#include <gtest/gtest.h>

TEST(BracketParser, getData)
{
    BasicParser::BracketParser p;
    p.loadFromFile("sample/menu.bracket");
    auto tab = p.searchDocument({
        {"position_y", "527"},
    });
    EXPECT_EQ(3, tab.size());
    EXPECT_EQ("upgrade_ant_button", tab[0].get<std::string>("name"));
    EXPECT_EQ("upgrade_food_button", tab[1].get<std::string>("name"));
    EXPECT_EQ("more_ant", tab[2].get<std::string>("name"));
}


int main(int ac, char **av)
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

/*int main()
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
}*/