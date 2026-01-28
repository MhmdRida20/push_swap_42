#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo "========================================="
echo "  PUSH_SWAP COMPREHENSIVE TEST SUITE"
echo "========================================="
echo ""

# Test counter
PASSED=0
FAILED=0

# Helper function
test_case() {
    local name="$1"
    local cmd="$2"
    local expected="$3"
    
    result=$(eval "$cmd" 2>&1)
    
    if [ "$result" = "$expected" ]; then
        echo -e "${GREEN}✓${NC} $name"
        ((PASSED++))
    else
        echo -e "${RED}✗${NC} $name"
        echo "  Expected: $expected"
        echo "  Got: $result"
        ((FAILED++))
    fi
}

# Test counter for range
test_range() {
    local name="$1"
    local cmd="$2"
    local max="$3"
    
    result=$(eval "$cmd" 2>&1)
    
    if [ "$result" -le "$max" ]; then
        echo -e "${GREEN}✓${NC} $name: $result operations (max: $max)"
        ((PASSED++))
    else
        echo -e "${RED}✗${NC} $name: $result operations (max: $max)"
        ((FAILED++))
    fi
}

echo "--- EDGE CASES ---"
test_case "No arguments" "./push_swap" ""
test_case "One number" "./push_swap 42" ""
test_case "Already sorted" "./push_swap 1 2 3" ""

echo ""
echo "--- ERROR CASES ---"
test_case "Duplicate" "./push_swap 1 2 1" "Error"
test_case "Invalid input" "./push_swap 1 a 2" "Error"
test_case "Overflow" "./push_swap 2147483648" "Error"

echo ""
echo "--- TWO ELEMENTS ---"
test_range "Reverse" "./push_swap 2 1 | wc -l" 1
test_case "Sorted" "./push_swap 1 2" ""

echo ""
echo "--- THREE ELEMENTS ---"
test_range "[1,2,3]" "./push_swap 1 2 3 | wc -l" 0
test_range "[2,1,3]" "./push_swap 2 1 3 | wc -l" 3
test_range "[3,2,1]" "./push_swap 3 2 1 | wc -l" 3

echo ""
echo "--- FIVE ELEMENTS ---"
test_range "Reverse 5" "./push_swap 5 4 3 2 1 | wc -l" 12
test_range "Random 5" "./push_swap 2 4 1 5 3 | wc -l" 12

echo ""
echo "--- 100 ELEMENTS ---"
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
test_range "Random 100 (trial 1)" "./push_swap $ARG | wc -l" 700

ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
test_range "Random 100 (trial 2)" "./push_swap $ARG | wc -l" 700

ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
test_range "Random 100 (trial 3)" "./push_swap $ARG | wc -l" 700

echo ""
echo "--- 500 ELEMENTS ---"
ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' ')
test_range "Random 500 (trial 1)" "./push_swap $ARG | wc -l" 5500

ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' ')
test_range "Random 500 (trial 2)" "./push_swap $ARG | wc -l" 5500

echo ""
echo "========================================="
echo -e "  ${GREEN}PASSED: $PASSED${NC}"
echo -e "  ${RED}FAILED: $FAILED${NC}"
echo "========================================="
