#!/bin/bash

echo "PUSH_SWAP PERFORMANCE BENCHMARK"
echo "================================"
echo ""

# 100 elements - 10 trials
echo "100 elements (10 trials):"
total=0
for i in {1..10}; do
    ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
    count=$(./push_swap $ARG | wc -l)
    echo "  Trial $i: $count operations"
    total=$((total + count))
done
average=$((total / 10))
echo "  Average: $average operations"
echo ""

# 500 elements - 10 trials
echo "500 elements (10 trials):"
total=0
for i in {1..10}; do
    ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' ')
    count=$(./push_swap $ARG | wc -l)
    echo "  Trial $i: $count operations"
    total=$((total + count))
done
average=$((total / 10))
echo "  Average: $average operations"
