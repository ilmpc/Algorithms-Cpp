#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "../lib/lib.hpp"

using namespace Algorithms;

enum Color { white, grey, black };

template <size_t N>
using Matrix = std::array<std::array<size_t, N>, N>;

template<size_t N>
void dfs(size_t i, const Matrix<N> &matrix, std::array<Color, N> &color, std::vector<size_t> &sorted) {
    switch (color[i])
    {
        case black:
            return;

        case grey:
            throw std::invalid_argument("Cycle in input data. Can't sort");

        case white:
            color[i] = grey;
            
            for (size_t to = 0; to < N; to++)
            {
                auto weight = matrix[i][to];
                if(weight != 0){
                    dfs(to, matrix, color, sorted);
                }
            }

            color[i] = black;
            sorted.push_back(i);
    }
}

template<size_t N>
std::vector<size_t> sort(const Matrix<N> &matrix) {
    std::array<Color, N> color = { white };
    std::vector<size_t> sorted;
    for (size_t i = 0; i < N; i++)
    {
       dfs(i, matrix, color, sorted);
    }
    std::reverse(sorted.begin(), sorted.end());
    return sorted;
}

int main() {
    Matrix<4> matrix = {{
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0}
    }};
    for (auto el : sort(matrix))
    {
        std::cout << el + 1 << " ";    
    }   
    std::cout << std::endl;
}