/*
  Introduction to Algorithms, Chapter 9 : Medians And Order Statistics.
  Minimum and Maximum.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 6th, 2016
 */

#ifndef DATA_STRUCTURE_MINIMUM_MAXIMUM_MIN_MAX_H_
#define DATA_STRUCTURE_MINIMUM_MAXIMUM_MIN_MAX_H_

#include <cstdio>
#include <cstdlib>
#include <vector>

template <typename T>
class MinMax {
public:
	MinMax();
	~MinMax();

	T Minimum(const std::vector<T>& V);
	T Maximum(const std::vector<T>& V);

	void MinimumMaximum(const std::vector<T>& V, T& min, T& max);

	T SecondMinimum(const std::vector<T>& V);
	T SecondMaximum(const std::vector<T>& V);
};

template <typename T>
MinMax<T>::MinMax() {}

template <typename T>
MinMax<T>::~MinMax() {}

/*
  This function will have n - 1 comparission.
  And n complexity.
 */
template <typename T>
T MinMax<T>::Minimum(const std::vector<T>& V) {
	T min = V[0];
	for (std::size_t i = 1; i < V.size(); ++i)
		if (min > V[i])
			min = V[i];

	return min;
}

/*
  This function will have n - 1 comparission.
  And n complexity.
 */
template <typename T>
T MinMax<T>::Maximum(const std::vector<T>& V) {
	T max = V[0];
	for (std::size_t i = 1; i < V.size(); ++i)
		if (max < V[i])
			max = V[i];

	return max;
}

/*
  This function will have n / 2 complexity.
  3 * (n / 2) comparrisions will be there.

  if (n == odd)
  	min = max = first element;
  else
    min = first, max = second

  while (n / 2)
     if (i > i + 1)
	     check max > i
	 else
	     check min < i + 1
 */
template <typename T>
void MinMax<T>::MinimumMaximum(const std::vector<T>& V, T& min, T& max) {
	std::size_t i = 0;

	if (V.size() % 2) {
		min = max = V[0];
		i = 1;
	} else {
		if (V[0] < V[1]) {
			min = V[0];
			max = V[1];
		} else {
			min = V[1];
			max = V[1];
		}
		i = 2;
	}

	for (; i < V.size(); i += 2) {
		if (V[i] < V[i + 1]) {
			if (min > V[i])
				min = V[i];
			if (max < V[i + 1])
				max = V[i + 1];
		} else {
			if (min > V[ i + 1])
				min = V[i + 1];
			if (max < V[i])
				max = V[i];
		}
	}
}

template <typename T>
T MinMax<T>::SecondMinimum(const std::vector<T>& V) {
	T min        = 0;
	T second_min = 0;

	if (V[0] < V[1]) {
		min        = V[0];
		second_min = V[1];
	} else {
		min        = V[1];
		second_min = V[0];
	}
	
	for (std::size_t i = 2; i < V.size(); ++i) {
		if (min > V[i]) {
			second_min = min;
			min = V[i];
		}

		if (V[i] > min &&  V[i] < second_min)
			second_min = V[i];
	}

	return second_min;
}

template <typename T>
T MinMax<T>::SecondMaximum(const std::vector<T>& V) {
	T max        = 0;
	T second_max = 0;

	if (V[0] > V[1]) {
		max        = V[0];
		second_max = V[1];
	} else {
		max        = V[1];
		second_max = V[0];
	}

	for (std::size_t i = 2; i < V.size(); ++i) {
		if (max < V[i]) {
			second_max = max;
			max = V[i];
		}

		if (V[i] < max && V[i] > second_max)
			second_max = V[i];
	}

	return second_max;
}

#endif // DATA_STRUCTURE_MINIMUM_MAXIMUM_MIN_MAX_H_