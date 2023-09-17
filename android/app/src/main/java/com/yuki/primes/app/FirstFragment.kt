package com.yuki.primes.app

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ArrayAdapter
import android.widget.ListView
import androidx.navigation.fragment.findNavController
import com.yuki.primes.R
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

    private val listViewPrimes by lazy { binding.listViewPrimes }

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
            val primes: IntArray = Primes.getPrimes(binding.textPrimeInput.text.toString())
            val adapter = ArrayAdapter(requireContext(), android.R.layout.simple_list_item_1, primes.toList())
            listViewPrimes.adapter = adapter
        }
    }

    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}