#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &copy){
	*this = copy;
}

PmergeMe::~PmergeMe(void){
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj){
	if (this != &obj){
		this->_dataVec = obj._dataVec;
		this->_dataDeq = obj._dataDeq;
    }
	return *this;
}

void    PmergeMe::run(char **input){
    clock_t start, end;
	double time;
    int i = 1;
    int j;
    int dig;

    while (input[i]){
        j = 0;
        while(input[i][j]){
            if (!std::isdigit(input[i][j]) && input[i][j] != ' '){
                    std::cout << "ERROR: We only accept positive integers." << std::endl;
                    return;
            }
            j++;
        }
		std::istringstream(input[i]) >> dig;
		std::string str = input[i];
        if (str.length() > 10 || (str.length() == 10 && str > "2147483647") ){
            std::cout << "ERROR: We only accept integers under max int." << std::endl;
            return ;
        }
		_dataVec.push_back(dig);
//		_dataSet.insert(dig);
		_dataDeq.push_back(dig);
		i++;
	}
	std::cout << "Before: ";
    printList(_dataVec);
    start = clock();
    mergeInsertionSort(_dataVec, 0, _dataVec.size() - 1, 5);
    //quicksort(_dataVec, 0, _dataVec.size() - 1);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	int vecsize = _dataVec.size();
    removeDuplicates(_dataVec);
	std::cout << "After: ";
    printList(_dataVec);
    std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of "<< vecsize <<  " elements with std::vector : " << time << " ms\n";
    start = clock();
    mergeInsertionSort(_dataDeq, 0, _dataDeq.size() - 1, 5);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	int deqsize = _dataDeq.size();
    removeDuplicates(_dataDeq);
    std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of "<< deqsize <<  " elements with std::queue : " << time << " ms\n";
}
