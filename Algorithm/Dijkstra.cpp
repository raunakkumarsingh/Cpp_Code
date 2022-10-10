#include <iostream>
#include <limits>
#include <vector>
#include <array>
#include <type_traits>

#define VERTICES_NUM 9

template<typename T>
auto extract_min(std::vector<int>& Q, std::array<T, VERTICES_NUM>& G) {
    double min = std::numeric_limits<T>::max();
    auto min_index = 0;
    for (int i = 0; i < Q.size(); ++i) {
        if (G.at(Q[i]) < min) {
            min = G.at(Q[i]);
            min_index = i;
        }
    }

    return min_index;
}

template<typename T, int N> using raw_array = T[N][N];

template<typename T, int N>
requires std::is_floating_point_v<T> || std::is_integral_v<T>

auto dijkstra(raw_array<T, N> graph, int v) {
    std::array<T, N> G;
    for (int i = 0; i < N; ++i) {
        G.at(i) = std::numeric_limits<T>::max();
    }
    

    G.at(v) = static_cast<T>(0);
    std::vector<int> S{};

    std::vector<int> Q{};

    for (int i = 0; i < N; ++i) {
        Q.push_back(i);
    }


    while (!Q.empty()) {
        auto u = extract_min(Q, G);
        S.push_back(Q[u]);

        for (int i = 0; i < VERTICES_NUM; ++i) {
            auto dist = graph[Q[u]][i];
            if (dist != 0) {
                if (G[i] > G[Q[u]] + dist) {
                    G[i] = G[Q[u]] + dist;
                }
            }
        }

        Q.erase(Q.begin() + u);
    }

    return G;
}


int main()
{


    auto&& graph = raw_array<double, VERTICES_NUM>{ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

  

    auto G = dijkstra<double, VERTICES_NUM>(graph, 0);

    for (int i = 0; auto & c : G) {
        std::cout << i++ << ": " << c << " | ";
    }

}