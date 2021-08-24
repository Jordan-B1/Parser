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

TEST(BracketParser, array)
{
    BasicParser::BracketParser p;
    p.loadFromFile("sample/menu.bracket");
    auto res = {243, 244, 0, 1};

    auto tab = p.searchDocument({
        {"name", "upgrade_food_button"},
    });
    auto arr = tab[0].get<std::vector<int>>("color");
    for (auto it = res.begin(); it != res.end(); it++) {
        EXPECT_EQ(*it, arr[it - res.begin()]);
    }
}

TEST(BracketParser, empty)
{
    BasicParser::BracketParser p;
    p.loadFromFile("sample/menu.bracket");

    auto tab = p.searchDocument({
        {"name", "no existing chunk"},
    });
    EXPECT_EQ(0, tab.size());
}


int main(int ac, char **av)
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}