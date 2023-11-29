//
// Created by Kevin Gori on 28/11/2023.
//
#include "suffix_array.h"
#include <algorithm>
#include <ranges>

namespace string_algos {
    bool Suffix::operator<(const Suffix& other) const {
        return std::tie(rank[0], rank[1]) <
               std::tie(other.rank[0], other.rank[1]);
    }

    bool Suffix::operator==(const Suffix& other) const {
        return (this->rank == other.rank);
    }

    std::vector<size_t> build_suffix_array(std::string_view text) {
        size_t n = text.size();

        std::vector<Suffix> suffixes(n);
        for (size_t i = 0; i < n; ++i) {
            suffixes[i].index = i;
            suffixes[i].rank[0] = text[i] - 'a';
            suffixes[i].rank[1] =
                (i + 1 < n)
                    ? static_cast<std::optional<size_t>>(text[i + 1] - 'a')
                    : std::nullopt;
        }

        std::ranges::sort(suffixes, std::less<Suffix>());

        std::vector<size_t> index(n);
        for (size_t k = 4; k < 2 * n; k *= 2) {
            size_t rank = 0;
            std::optional<size_t> prev_rank = suffixes[0].rank[0];
            suffixes[0].rank[0] = rank;
            index[suffixes[0].index] = 0;

            for (size_t i = 1; i < n; ++i) {
                if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = rank;
                } else {
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = ++rank;
                }
                index[suffixes[i].index] = i;
            }

            for (size_t i = 0; i < n; ++i) {
                size_t nextIndex = suffixes[i].index + k / 2;
                suffixes[i].rank[1] = (nextIndex < n)
                                          ? suffixes[index[nextIndex]].rank[0]
                                          : std::nullopt;
            }

            std::ranges::sort(suffixes, std::less<Suffix>());
        }

        std::vector<size_t> suffixArray(n);
        for (size_t i = 0; i < n; ++i) { suffixArray[i] = suffixes[i].index; }

        return suffixArray;
    }
}// namespace string_algos
