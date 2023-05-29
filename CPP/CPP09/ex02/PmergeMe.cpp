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
    std::clock_t start, end;
	double Vtime;
    int i = 1;
    int j;
    int dig;

    while (input[i]){
        j = 0;
        while(input[i][j]){
            if (!std::isdigit(input[i][j]) && input[i][j] != ' '){
                    std::cout << "ERROR: We only accept integers." << std::endl;
                    return;
            }
            j++;
        }
		std::istringstream(input[i]) >> dig;
        if (dig > 2147483647){
            std::cout << "ERROR: We only accept integers under max int." << std::endl;
            return ;
        }
		_dataVec.push_back(dig);
//		_dataSet.insert(dig);
		_dataDeq.push_back(dig);
		i++;
	}
    printList(_dataVec);
    start = clock();
    quicksort(_dataVec, 0, _dataVec.size() - 1);
    end = clock();
    Vtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of "<< _dataVec.size() <<  " elements with std::vector : " << Vtime << " ms\n";
    printList(_dataVec);
    printList(_dataDeq);
}