#ifndef PmergeMe_H
# define PmergeMe_H
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <cstring>
# include <cstdio>
#include <ctime>
#include <sys/time.h>
# include <time.h>
# include <iomanip>
#include <algorithm>

class PmergeMe{
	private:
        std::vector<int>	_dataVec;
		std::deque<int>		_dataDeq;
        //std::set<int>		_dataSet; // Si uso este contenedor ya me ordena la lista
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();

		PmergeMe			&operator=(const PmergeMe &obj);
		void				fill(char **input);
		void				order();

		template <typename T>
		void quicksort(T & arr, int low, int high) {
    		if (low < high) {
        		int pivot = arr[(low + high) / 2];
        		int i = low - 1;
        		int j = high + 1;
        		while (true) {
            	do {
                	i++;
            	} while (arr[i] < pivot);
            	do {
                	j--;
            	} while (arr[j] > pivot);
            		if (i >= j) {
                		break;
            		}
            	std::swap(arr[i], arr[j]);
        		}
        		quicksort(arr, low, j);
        		quicksort(arr, j + 1, high);
    		}
		}
		template< typename T >
	void	merge_sort(T & lst, int beg, int end) {
		int mid;
		if (beg<end)  
		{
			mid = (beg+end)/2;  
			merge_sort(lst, beg, mid);  
			merge_sort(lst, mid+1, end);  
			merge(lst, beg, mid, end);  
		}
	}

	template< typename T >
	void	merge(T & lst, int left, int mid, int right)  {  
		std::vector<int> temp(right - left + 1);
		int i = left, j = mid+1, k = 0;
		while (i <= mid && j <= right) {
			if (lst[i] <= lst[j]) {
				temp[k++] = lst[i++];
			} else {
				temp[k++] = lst[j++];
			}
		}
		while (i <= mid) {
			temp[k++] = lst[i++];
		}
		while (j <= right) {
			temp[k++] = lst[j++];
		}

		for (int p = 0; p < k; p++) {
			lst[left+p] = temp[p];
		}
	}

		template <typename T>
		void printList(T & arr) {
			int i = 0;
			typename T::const_iterator it;
    		for (it = arr.begin(); it != arr.end(); it++) {
				if (i++ == 6)
					break;
    	 	   	std::cout << *it << " ";
    		}
    		std::cout << std::endl;
		}
};

#endif