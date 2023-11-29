//
// Created by Kevin Gori on 28/11/2023.
//
#pragma once
#include <array>
#include <optional>
#include <string_view>
#include <vector>

namespace string_algos {
    class Suffix {
    public:
        Suffix() = default;

        size_t index{};
        std::array<std::optional<size_t>, 2> rank{};
        bool operator<(const Suffix&) const;
        bool operator==(const Suffix&) const;
        // auto operator<=>(const Suffix&) const = default - not working with mac compiler
    };

    std::vector<size_t> build_suffix_array(std::string_view text);
}// namespace string_algos
