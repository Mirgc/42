#ifndef PmergeMe_H
# define PmergeMe_H
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <time.h>
# include <iomanip>

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
		void				run(char **input);

		/*template <typename T> //Primer algoritmo que use, no es merge insert, descartado
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
		}*/

		template< typename T >
		void	merge(T & arr, int left, int mid, int right)  {  
			std::vector<int> temp(right - left + 1); //Array temporal para almacenar los elementos
			int i = left; // Indice para el subarray izquierdo
			int j = mid+1; // Indice para el subarray derecho
			int k = 0; // Indice para el temporal

			while (i <= mid && j <= right) { // Mezclar los elementos en el temporal
				if (arr[i] <= arr[j])
					temp[k++] = arr[i++];
				else 
					temp[k++] = arr[j++];
			} 
			while (i <= mid) { //Copiar los elementos restantes del izquierdo
				temp[k++] = arr[i++];
			}
			while (j <= right) { //Copiar los elementos restantes del derecho
				temp[k++] = arr[j++];
			}
			for (int x = 0; x < k; x++) { //Copiar los elementos ordenados del temporal al original
				arr[left + x] = temp[x];
			}
		}

		template< typename T >	
		void mergeInsertionSort(T & arr, int left, int right, int k) {
    		if (left < right) {
        		if (right - left + 1 <= k) { // Utilizar inserción para arreglos pequeños
            		for (int i = left + 1; i <= right; i++) {
                		int key = static_cast<int>(arr[i]);
                		int j = i - 1;
                		while (j >= left && arr[j] > key) {
                    		arr[j + 1] = arr[j];
                    		j--;
                		}
                		arr[j + 1] = key;
            		}
        		} else {
            		int mid = left + (right - left) / 2;
            		mergeInsertionSort(arr, left, mid, k);
            		mergeInsertionSort(arr, mid + 1, right, k);
            		merge(arr, left, mid, right);
   		    	}
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

		template<typename T>
		void removeDuplicates(T & arr) {
    		if (arr.empty()) {
        		return;
    		}
    		T uniqueArr;
    		uniqueArr.push_back(arr[0]);
    		for (size_t i = 1; i < arr.size(); i++) {
        		if (arr[i] != arr[i - 1]) {
     			    uniqueArr.push_back(arr[i]);
  			    }
		    }
    		arr = uniqueArr;
		}
};

#endif
