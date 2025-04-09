/**
 * @file
 * @brief Implementation of [0-1 Knapsack Problem]
 * (https://en.wikipedia.org/wiki/Knapsack_problem)
 *
 * @details
 * Given weights and values of n items, put these items in a knapsack of
 * capacity `W` to get the maximum total value in the knapsack. In other words,
 * given two integer arrays `val[0..n-1]` and `wt[0..n-1]` which represent
 * values and weights associated with n items respectively. Also given an
 * integer W which represents knapsack capacity, find out the maximum value
 * subset of `val[]` such that sum of the weights of this subset is smaller than
 * or equal to W. You cannot break an item, either pick the complete item or
 * don’t pick it (0-1 property)
 *
 * ### Algorithm
 * The idea is to consider all subsets of items and calculate the total weight
 * and value of all subsets. Consider the only subsets whose total weight is
 * smaller than `W`. From all such subsets, pick the maximum value subset.
 *
 * @author [Anmol](https://github.com/Anmol3299)
 * @author [Pardeep](https://github.com/Pardeep009)
 */

import std;

/**
 * @namespace dynamic_programming
 * @brief Dynamic Programming algorithms
 */
namespace dynamic_programming {
/**
 * @namespace Knapsack
 * @brief Implementation of 0-1 Knapsack problem
 */
namespace knapsack {

template <size_t n>
int maxKnapsackValue(const int capacity, const std::array<int, n> &weight,
                     const std::array<int, n> &value)
                     {
return 0;
                     }
} // namespace knapsack
} // namespace dynamic_programming
