// Copyright (c) 2017-2026, University of Cincinnati, developed by Henry Schreiner
// under NSF AWARD 1414736 and by the respective contributors.
// All rights reserved.
//
// SPDX-License-Identifier: BSD-3-Clause

#ifdef CLI12_SINGLE_FILE
#include "CLI12.hpp"
#else
#include "CLI/CLI.hpp"
#endif

#include <iostream>

int main() {
    std::cout << "\nCLI12 information:\n";

    std::cout << "  C++ standard: ";
#if defined(CLI12_CPP20)
    std::cout << 20;
#elif defined(CLI12_CPP17)
    std::cout << 17;
#elif defined(CLI12_CPP14)
    std::cout << 14;
#else
    std::cout << 11;
#endif
    std::cout << "\n";

    std::cout << "  __has_include: ";
#ifdef __has_include
    std::cout << "yes\n";
#else
    std::cout << "no\n";
#endif

#if CLI12_OPTIONAL
    std::cout << "  [Available as CLI::optional]";
#else
    std::cout << "  No optional library found\n";
#endif

#if CLI12_STD_OPTIONAL
    std::cout << "  std::optional support active\n";
#endif

#if CLI12_EXPERIMENTAL_OPTIONAL
    std::cout << "  std::experimental::optional support active\n";
#endif

#if CLI12_BOOST_OPTIONAL
    std::cout << "  boost::optional support active\n";
#endif

    std::cout << '\n';
}
