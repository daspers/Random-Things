#include <iostream>
using namespace std;

template <class T>
class BinaryHeap{
public:
	BinaryHeap(int sz = 100);
	~BinaryHeap();
	BinaryHeap(const BinaryHeap&);
	bool isEmpty(){
		return pointer==1;
	}
	bool isFull(){
		return pointer == maxsz + 1;
	}
	void print(){
		for(int i=1;i<pointer;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
	void insert(const T&);
	T pop();
private:
	T *arr;
	int pointer;
	int maxsz;
};

template <class T>
BinaryHeap<T>::BinaryHeap(int sz){
	arr = new T[sz];
	pointer = 1;
	maxsz = sz;
}

template <class T>
BinaryHeap<T>::BinaryHeap(const BinaryHeap<T>& other){
	arr = new T[other.maxsz];
	for(int i=1;i<other.pointer;++i){
		arr[i] = other.arr[i];
	}
	maxsz = other.maxsz;
	pointer = other.pointer;
}

template <class T>
BinaryHeap<T>::~BinaryHeap(){
	delete[] arr;
}

template <class T>
void BinaryHeap<T>::insert(const T& in){
	if(pointer<=maxsz){
		arr[pointer] = in;
		int ptemp = pointer;
		while(ptemp!=1){
			if(arr[ptemp] < arr[ptemp>>1]){
				T temp = arr[ptemp];
				arr[ptemp] = arr[ptemp>>1];
				arr[ptemp>>1] = temp;
				ptemp>>=1;
			}
			else
				break;
		}
		++pointer;
	}
}

template <class T>
T BinaryHeap<T>::pop(){
	T res;
	--pointer;
	if(pointer>0){
		res = arr[1];
		arr[1] = arr[pointer];
		int ptemp = 1;
		int l = ptemp<<1;
		while(l < pointer){
			int r = l +1;
			if(r<pointer){
				if(arr[l]<arr[r]){
					if(arr[ptemp] > arr[l]){
						T temp = arr[ptemp];
						arr[ptemp] = arr[l];
						arr[l] = temp;
						ptemp = l;
					}
					else break;
				}
				else if(arr[ptemp] > arr[r]){
					T temp = arr[ptemp];
					arr[ptemp] = arr[r];
					arr[r] = temp;
					ptemp = r;
				}
				else break;
			}
			else if(arr[ptemp] > arr[l]){
				T temp = arr[ptemp];
				arr[ptemp] = arr[l];
				arr[l] = temp;
				ptemp = l;
			}
			else{
				break;
			}
			l = ptemp << 1;
		}
	}
	return res;
}
