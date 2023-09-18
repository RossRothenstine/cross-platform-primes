#include "gtest/gtest.h"
#include "Primes.h"

struct ParsePrimeTestEntry {
    const char* input;
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
        ParsePrimeTestEntry{ "", {} },
        ParsePrimeTestEntry{ "Hello, 2, 4, 7.5", { 3, 7, 17 } }
    )
);


TEST(ParseNumbers, ParseNumbersParsesAnEmptyString) {
    std::string input = "";
    std::vector<int> expected = {};
    std::vector<int> actual = primes::ParseNumbers(input);
    EXPECT_EQ(expected, actual);
}

TEST(ParseNumbers, ParseNumbersParsesTheExampleFromTheOutline) {
    std::string input = "Hello, 2, 4, 7.5";
    std::vector<int> expected = { 2, 4, 7 };
    std::vector<int> actual = primes::ParseNumbers(input);
    EXPECT_EQ(expected, actual);
}

struct PrimeTestEntry {
    int index;
    int expected;
};

class PrimeTest : public testing::TestWithParam<PrimeTestEntry> {};

TEST_P(PrimeTest, FindPrimeAt) {
    PrimeTestEntry entry = GetParam();
    int actual = primes::FindPrimeAt(entry.index);
    EXPECT_EQ(entry.expected, actual);
};

INSTANTIATE_TEST_SUITE_P(
    SimpleValues,
    PrimeTest,
    testing::Values(
        PrimeTestEntry{1, 2},
        PrimeTestEntry{2, 3},
        PrimeTestEntry{3, 5},
        PrimeTestEntry{4, 7}
    )
);

TEST(GetPrimes, EmptyIndicesReturnsEmpty) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    primes::GetPrimes(input);
    EXPECT_EQ(expected, input);
}

TEST(GetPrimes, SingleIndex) {
    std::vector<int> input = { 1 };
    std::vector<int> expected = { 2 };
    primes::GetPrimes(input);
    EXPECT_EQ(expected, input);
}

TEST(GetPrimes, MultipleIndices) {
    std::vector<int> input = { 1, 4 };
    std::vector<int> expected = { 2, 7 };
    primes::GetPrimes(input);
    EXPECT_EQ(expected, input);
}

TEST(GetPrimes, SampleIndices) {
    std::vector<int> input = { 2, 4, 7 };
    std::vector<int> expected = {3, 7, 17 };
    primes::GetPrimes(input);
    EXPECT_EQ(expected, input);
}