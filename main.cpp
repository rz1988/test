#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

template<typename T> 
void printVector(vector<T> v) {
	for (const T& x:v) 
		cout << " " << x;
	cout << endl;
}

vector<int> genRandomVector(int N) {
	srand(time(NULL));
	vector<int> vec;
		for(int i = 0; i < N; ++i) {
		vec.push_back(rand()%50 - 15);
	}	
	printVector(vec);	
	return vec;
}

template<typename T> 
vector<T> insertionSort(vector<T> vec) {
	vector<T> sorted;
	sorted.push_back(vec[0]);
	for(int i = 1; i < vec.size(); ++i) {
		for(int j = i - 1; j >= 0; --j) {
			if(vec[i] > sorted[j]) {
				sorted.insert(sorted.begin() + j + 1, 1, vec[i]);
				break;
			}
		}
	}
	return sorted;
}

template<typename T>
void bubbleSort(vector<T> & a) {
	for(int i = 0; i < a.size(); ++i) {
		for(int j = 0; j < (a.size() - i); ++j) {
			if(a[j] > a[j+1]) 
				swap(a[j], a[j+1]);
		}
	}
}

template<typename Comparable> 
void insertionSort2( vector<Comparable> & a) {
	for(int i = 1; i < a.size(); ++i) {
		Comparable tmp = move(a[i]);
		int j;
		for(j = i; j > 0; --j) {
			if ( tmp < a[j-1]) 
				a[j] = move(a[j-1]);
			else 
				break;
		}		
		a[j] = move(tmp);
	}
}


template<typename T> 
void shellSort(vector<T> & a) {
	int h = a.size() / 2;
	while( h >= 1) {
		for(int i = 0; i < h; ++i) {
			vector<T> sorted;
			for(int p = 0; p < a.size(); p += h) 
				sorted.push_back(a[i + p]);
			insertionSort2(sorted);
			for(int p = 0; p < a.size(); p += h) { 
				a[i + p] = sorted.front();
				sorted.erase(sorted.begin());
			}
		}
		h = h / 2;
	}
}

template<typename T> 
void shellSort2(vector<T> & a) {
	for (int gap = a.size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < a.size(); ++i) {
			T tmp = move(a[i]);
			int j = i;
			
			for (; j >= gap && tmp < a[j - gap]; j -= gap)
				a[j] = move(a[j - gap]);
			a[j] = move(tmp);
		}
	}
	
}




template<typename Iterator, typename Comparator>
void insertionSort2(const Iterator & begin, const Iterator & end, Comparator lessThan) {
	if (begin == end) 
		return ;
	
	Iterator j;
	
	for( Iterator p = begin + 1; p != end; ++p) {
		auto tmp =move(*p);
		for( j = p; j != begin && lessThan(tmp, *(j-1)); --j) 
			*j = move(*(j-1));
		*j = move(tmp);
	}
}

template<typename Iterator>
void insertionSort2(const Iterator & begin, const Iterator & end) {
	insertionSort2(begin, end, less<decltype(*begin)>{});
}

inline int leftChild( int i) {
	return 2 * i + 1;
}


template <typename Comparable> 
void percDown( vector<Comparable> & a, int i, int n) {
	int child;
	Comparable tmp;
	
	for( tmp = move(a[i]); leftChild(i) < n; i = child) {
		child = leftChild(i);
		if( child != n - 1 && a[child] < a[child + 1]) 
			++ child;
		if( tmp < a[child]) 
			a[i] = move(a[child]);
		else 
			break;
	}
	a[i] = move(tmp);
}

template<typename Comparable> 
void heapSort( vector<Comparable> & a) {
	for ( int i = a.size() / 2 - 1; i >=0; --i) 
		percDown(a, i, a.size());
	for ( int j = a.size() - 1; j > 0; --j) {
		swap( a[0], a[j]);
		percDown(a, 0, j);
	}
}


int main() {
	/* Generate random numbers. */
	vector<int> vec;
	vector<int> sorted;
	int N = 10;
	vec = genRandomVector(N);
	//sorted = insertionSort(vec);
	heapSort(vec);
	//sorted = vec;
	//sorted.insert(sorted.begin(), 1, 101);
	printVector(vec);
	return 0;
}