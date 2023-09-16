// using System;
// using System.Reflection;
using System.Reflection;
using NUnit.Framework;
using NUnitLite;

namespace PrimesTest {
    public class Program {
        public static void Main(string[] args) {
            new AutoRun(Assembly.GetCallingAssembly()).Execute(args);
        }
    }
}