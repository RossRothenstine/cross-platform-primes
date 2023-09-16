using Primes;
using NUnit.Framework;

namespace PrimeTests {
    [TestFixture]
    public class LibraryTest {
        [Test]
        public void GetPrimes_Simple() {
            int[] FoundPrimes = Library.GetPrimes("Hello 2, 3, 7.5");
            int[] Expected = {3, 5, 17};
            Assert.AreEqual(3, FoundPrimes.Length);
            Assert.AreEqual(Expected, FoundPrimes);
        }

        [Test]
        public void GetPrimes_Empty() {
            int[] FoundPrimes = Library.GetPrimes("");
            int[] Expected = { };
            Assert.AreEqual(0, FoundPrimes.Length);
            Assert.AreEqual(Expected, FoundPrimes);
        }

        [Test]
        public void GetPrimes_NoNumbers() {
            int[] FoundPrimes = Library.GetPrimes("Hello");
            int[] Expected = { };
            Assert.AreEqual(0, FoundPrimes.Length);
            Assert.AreEqual(Expected, FoundPrimes);
        }
    }
}