#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "../lib/lib.hpp"

using namespace Algorithms;

enum Color { white, grey, black };

template <size_t N>
using EdgeList = std::array<std::vector<size_t>, N>;

template<size_t N>
void dfs(size_t i, const EdgeList<N> &lists, std::array<Color, N> &color, std::vector<size_t> &sorted) {
    switch (color[i])
    {
        case black:
            return;

        case grey:
            throw std::invalid_argument("Cycle in input data. Can't sort");

        case white:
            color[i] = grey;
            
            for (auto to : lists[i])
            {
                dfs(to, lists, color, sorted);
            }

            color[i] = black;
            sorted.push_back(i);
    }
}

template<size_t N>
std::vector<size_t> sort(const EdgeList<N> &lists) {
    std::array<Color, N> color = { white };
    std::vector<size_t> sorted;
    for (size_t i = 0; i < N; i++)
    {
       dfs(i, lists, color, sorted);
    }
    std::reverse(sorted.begin(), sorted.end());
    return sorted;
}

int main() {
    EdgeList<4> lists = {{
        {3},
        {},
        {1},
        {1, 2}
    }};
    for (auto el : sort(lists))
    {
        std::cout << el + 1 << " ";    
    }   
    std::cout << std::endl;
}