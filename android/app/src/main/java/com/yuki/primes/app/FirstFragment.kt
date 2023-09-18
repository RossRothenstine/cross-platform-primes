package com.yuki.primes.app

import android.os.Bundle
import android.os.Looper
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ArrayAdapter
import com.yuki.primes.databinding.FragmentFirstBinding
import com.yuki.prime.lib.Primes;

/**
 * A simple [Fragment] subclass as the default destination in the navigation.
 */
class FirstFragment : Fragment() {

    private var _binding: FragmentFirstBinding? = null

    // This property is only valid between onCreateView and
    // onDestroyView.
    private val binding get() = _binding!!

    private val looper = Looper.getMainLooper()

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        _binding = FragmentFirstBinding.inflate(inflater, container, false)
        return binding.root
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        binding.buttonGetPrimes.setOnClickListener {
            binding.buttonGetPrimes.isEnabled = false
            binding.progressBar.visibility = View.VISIBLE
            hideResultArea()

            Thread {
                val primes: IntArray = Primes.getPrimes(binding.textPrimeInput.text.toString())
                val adapter = ArrayAdapter(
                    requireContext(),
                    android.R.layout.simple_list_item_1,
                    primes.toList()
                )

                activity?.runOnUiThread {
                    binding.progressBar.visibility = View.GONE
                    binding.listViewPrimes.adapter = adapter
                    binding.buttonGetPrimes.isEnabled = true
                    showResultArea()
                }
            }.start()
        }
    }

    fun hideResultArea() {
        binding.listViewPrimes.visibility = View.GONE
        binding.spacer.visibility = View.GONE
        binding.resultText.visibility = View.GONE
    }

    fun showResultArea() {
        binding.listViewPrimes.visibility = View.VISIBLE
        binding.spacer.visibility = View.VISIBLE
        binding.resultText.visibility = View.VISIBLE
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}