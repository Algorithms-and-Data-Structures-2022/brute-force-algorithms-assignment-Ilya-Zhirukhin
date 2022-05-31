#include "assignment/subset_sum/bit_masking.hpp"

#include <cassert>  // assert

#include "assignment/bits.hpp"  // is_bit_set, mask2indices

namespace assignment {

  std::vector<std::vector<int>> SubsetSumBitMasking::search(const std::vector<int>& set, int target_sum) const {
    assert(target_sum > 0 && set.size() <= 16);

    std::vector<std::vector<int>> indices;

    const auto num_elems = static_cast<int>(set.size());  // N
    const int num_subsets = 1 << num_elems;               // 2^N

    std::vector<std::vector<int>> subsets;

    for (int m = 0; m < num_subsets; m++) {
      std::vector<int> subtest;
      for (int p = 0; p < num_elems; p++) {
        if (is_bit_set(m, p)) {
          subtest.push_back(p);
        }
      }
      int current_sum = 0;
      for (int i = 0; i < subtest.size(); i++) {
        current_sum += set[subtest[i]];
        if (current_sum > target_sum) {
          break;
        }
      }
      if (current_sum == target_sum) {
        indices.push_back(subtest);
      }
    }
    return indices;
  }

}  // namespace assignment