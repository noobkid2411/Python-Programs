#include <iostream>
#include <map>
#include <random>
 
std::default_random_engine generator;
std::uniform_int_distribution<int> dice(1, 6);
int rollDice() {
    return dice(generator);
}
 
const bool sixesThrowAgain = true;
const std::map<int, int> snl{
    {4, 14},
    {9, 31},
    {17, 7},
    {20, 38},
    {28, 84},
    {40, 59},
    {51, 67},
    {54, 34},
    {62, 19},
    {63, 81},
    {64, 60},
    {71, 91},
    {87, 24},
    {93, 73},
    {95, 75},
    {99, 78},
};

template <template<class, class, class...> class C, typename K, typename V, typename... Args>
V GetWithDef(const C<K, V, Args...>& m, K const& key, const V & defval) {
    typename C<K, V, Args...>::const_iterator it = m.find(key);
    if (it == m.end())
        return defval;
    return it->second;
}
 
int turn(int player, int square) {
    while (true) {
        int roll = rollDice();
        printf("Player %d, on square number %d, rolls a %d", player, square, roll);
        if (square + roll > 100) {
            printf(" but cannot move.\n");
        } else {
            square += roll;
            printf(" moves on to square %d\n", square);
            if (square == 100) return 100;
            int next = GetWithDef(snl, square, square);
            if (square < next) {
                printf("Wohooo a ladder,hop on to number %d.\n", next);
                square = next;
            } else if (next < square) {
                printf("Ouch just got bit by a snake,go back to number %d.\n", next);
                square = next;
            }
        }
        if (roll < 6 || !sixesThrowAgain)return square;
        printf("Wow,onto a 6 huh,you're on a roll,take another shot!!\n");
    }
}
 
int main() {
    // three players starting on square one
    int players[] = { 1, 1, 1 };
 
    while (true) {
        for (int i = 0; i < sizeof(players) / sizeof(int); ++i) {
            int ns = turn(i + 1, players[i]);
            if (ns == 100) {
                printf("Player %d wins!\n", i + 1);
                goto out;
            }
            players[i] = ns;
            printf("\n");
        }
    }
 
out:
    return 0;
}