#include "gtest/gtest.h"
#include "Primes.h"

struct ParsePrimeTestEntry {
    std::string input;
    std::vector<int> expected;
};

class ParsePrimeTest : public testing::TestWithParam<ParsePrimeTestEntry> {};

TEST_P(ParsePrimeTest, ParsePrimeReturnsExpected) {
    ParsePrimeTestEntry entry = GetParam();
    std::vector<int> actual = primes::ParsePrimes(entry.input);
    EXPECT_EQ(entry.expected, actual);
};


INSTANTIATE_TEST_SUITE_P(
    SimpleValues,
    ParsePrimeTest,
    testing::Values(
        // Empty returns empty.
        ParsePrimeTestEntry{ "", {} },
        // Sample Input from Specification
        ParsePrimeTestEntry{ "Hello, 2, 4, 7.5", { 3, 7, 17 } },
        // Trailing ending decimal
        ParsePrimeTestEntry{ "Hello, 2, 4, 7.", { 3, 7, 17 } }
    )
);

struct FindPrimeAtTestEntry {
    int index;
    int expected;
};

class PrimeTest : public testing::TestWithParam<FindPrimeAtTestEntry> {};

TEST_P(PrimeTest, FindPrimeAt) {
    FindPrimeAtTestEntry entry = GetParam();
    int actual = primes::FindPrimeAt(entry.index);
    EXPECT_EQ(entry.expected, actual);
};

INSTANTIATE_TEST_SUITE_P(
    SimpleValues,
    PrimeTest,
    testing::Values(
        // Simple arithmetic test cases.
        FindPrimeAtTestEntry{1, 2},
        FindPrimeAtTestEntry{2, 3},
        FindPrimeAtTestEntry{3, 5},
        FindPrimeAtTestEntry{4, 7}
    )
);

struct GetPrimesTestEntry {
    std::vector<int> input;
    std::vector<int> expected;
};

class GetPrimesTest : public testing::TestWithParam<GetPrimesTestEntry> {};

TEST_P(GetPrimesTest, GetPrimesReturnsExpected) {
    GetPrimesTestEntry entry = GetParam();
    primes::GetPrimes(entry.input);
    EXPECT_EQ(entry.expected, entry.input);
};

INSTANTIATE_TEST_SUITE_P(
    TableTest,
    GetPrimesTest,
    testing::Values(
        // Empty returns empty.
        GetPrimesTestEntry{{}, {}},
        // Single index returns single prime.
        GetPrimesTestEntry{{1}, {2}},
        // Multiple indices returns multiple primes.
        GetPrimesTestEntry{{1, 2, 5}, {2, 3, 11}},
        // Sample Input from Specification
        GetPrimesTestEntry{{2, 4, 7}, {3, 7, 17}}
    )
);

struct ParseNumbersTestEntry {
    std::string input;
    std::vector<int> expected;
};

class ParseNumbersTest : public testing::TestWithParam<ParseNumbersTestEntry> {};

TEST_P(ParseNumbersTest, ParseNumbersReturnsExpected) {
    ParseNumbersTestEntry entry = GetParam();
    std::vector<int> actual = primes::ParseNumbers(entry.input);
    EXPECT_EQ(entry.expected, actual);
};

INSTANTIATE_TEST_SUITE_P(
    SimpleValues,
    ParseNumbersTest,
    testing::Values(
        // Empty returns empty.
        ParseNumbersTestEntry{ "", {} },
        // Sample Input from Specification
        ParseNumbersTestEntry{ "Hello, 2, 4, 7.5", { 2, 4, 7 } },
        // Trailing ending decimal
        ParseNumbersTestEntry{ "Hello, 2, 4, 7.", { 2, 4, 7 } }
    )
);