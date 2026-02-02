#!/bin/bash

echo "========================================="
echo "  TESTING WITH FLAGS"
echo "========================================="
echo ""

echo "--- SIMPLE SORT (forced) ---"
echo ""

# Test all 6 permutations of 3 elements
echo "Test 1: [1,2,3]"
./push_swap --simple 1 2 3
echo "(Expected: nothing)"
echo ""

echo "Test 2: [1,3,2]"
./push_swap --simple 1 3 2
echo ""

echo "Test 3: [2,1,3]"
./push_swap --simple 2 1 3
echo ""

echo "Test 4: [2,3,1]"
./push_swap --simple 2 3 1
echo ""

echo "Test 5: [3,1,2]"
./push_swap --simple 3 1 2
echo ""

echo "Test 6: [3,2,1]"
./push_swap --simple 3 2 1
echo ""

echo "--- Count operations for each ---"
echo ""

for args in "1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1"; do
    count=$(./push_swap --simple $args | wc -l)
    echo "[$args] → $count operations"
done

echo ""
echo "--- MEDIUM SORT (forced) ---"
echo ""

echo "Test: [5,4,3,2,1]"
count=$(./push_swap --medium 5 4 3 2 1 | wc -l)
echo "Operations: $count (should be ≤ 12)"
echo ""

echo "Test: [3,1,4,5,2]"
count=$(./push_swap --medium 3 1 4 5 2 | wc -l)
echo "Operations: $count (should be ≤ 12)"
echo ""

echo "--- COMPLEX SORT (forced) ---"
echo ""

echo "Test: [5,4,3,2,1] with complex"
count=$(./push_swap --complex 5 4 3 2 1 | wc -l)
echo "Operations: $count"
echo ""

ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
count=$(./push_swap --complex $ARG | wc -l)
echo "Test: 100 random with complex"
echo "Operations: $count (should be < 700)"
echo ""

echo "========================================="
