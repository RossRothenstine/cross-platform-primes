package com.yuki.prime.lib

import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.platform.app.InstrumentationRegistry

import org.junit.Test
import org.junit.runner.RunWith

import org.junit.Assert.*

/**
 * Instrumented test, which will execute on an Android device.
 *
 * See [testing documentation](http://d.android.com/tools/testing).
 */
@RunWith(AndroidJUnit4::class)
class PrimesTest {
    @Test
    fun testEmptyString() {
        val result = Primes.getPrimes("")
        assertEquals(0, result.size)
    }

    @Test
    fun testSampleString() {
        val result = Primes.getPrimes("Hello, 2, 4, 7.5")
        assertEquals(3, result.size)
        assertArrayEquals(intArrayOf(3, 7, 17), result);
    }

    @Test
    fun useAppContext() {
        // Context of the app under test.
        val appContext = InstrumentationRegistry.getInstrumentation().targetContext
        assertEquals("com.yuki.prime.lib.test", appContext.packageName)
    }
}