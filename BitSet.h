#ifndef OURBTS
#define OURBTS
#include <iostream>
#include <bitset>
using namespace std;

template <unsigned int sizebts>
class ourbts
{
public:
	
	ourbts() { siz(); };
	~ourbts() { delete[] arr; }
	void setbts(unsigned long long int);
	void setfromindex(int,bool);
	void none();
	void setall();
	void reset0();
	void operator|(const ourbts<sizebts>&);
	void operator|(unsigned int);
	void operator^(const ourbts<sizebts>&);
	void operator^(unsigned int);
	void operator&(const ourbts<sizebts>&);
	void operator&(unsigned int);
	
	friend ostream& operator<<(ostream& out, const ourbts<sizebts>& obj1) {
		string s = "";
		ourbts<sizebts> obj2;
		for (int c = 0; c < obj1.cc; ++c) {
			obj2.arr[c] = obj1.arr[c];
		}
		
		for (int j = 0; j < obj1.cc; ++j) {
			if (sizebts >= 32) {
				for (int i = 31; i >= 0; --i)
				{
					s += (obj2.arr[j] & (1 << i)) ? "1" : "0";
				}
			}
			else{ 
				for (int i = sizebts; i >= 0; --i)
				{
					s += (obj2.arr[j] & (1 << i)) ? "1" : "0";
				}
			}
		}
		out << s;
		return out;
	}
 private:
	 
	 int findeindexpos(int);
	int cc= siz();
	int* arr{ new int[cc]{0} };
	int siz();

};






template<unsigned int sizebts>
void ourbts<sizebts>::operator&(unsigned int num) {
	ourbts<cc> object1;
	object1.setbts(num);
	for (int i = 0; i < cc; ++i) {
		this->arr[i] &= object1.arr[i];
	}
}


template<unsigned int sizebts>
void ourbts<sizebts>::operator&(const ourbts<sizebts>& obj2) {
	for (int i = 0; i < cc; ++i) {
		this->arr[i] &= obj2.arr[i];
	}
}


template<unsigned int sizebts>
void ourbts<sizebts>::operator^(unsigned int num) {
	ourbts<cc> object1;
	object1.setbts(num);
	for (int i = 0; i < cc; ++i) {
		this->arr[i] ^= object1.arr[i];
	}
}


template<unsigned int sizebts>
void ourbts<sizebts>::operator^(const ourbts<sizebts>& obj2) {
	for (int i = 0; i < cc; ++i) {
		this->arr[i] ^= obj2.arr[i];
	}
}

template<unsigned int sizebts>
void ourbts<sizebts>::operator|(unsigned int num) {
	ourbts<cc> object1;
	object1.setbts(num);
	for (int i = 0; i < cc; ++i) {
		this->arr[i] |= object1.arr[i];
	}
}

template<unsigned int sizebts>
void ourbts<sizebts>::operator|(const ourbts<sizebts>& objbt) {
	for (int i = 0; i < cc; ++i) {
		this->arr[i] |= objbt.arr[i];
	}

}

template<unsigned int sizebts>
void ourbts<sizebts>::reset0() {
	for (int i = 0; i < cc; ++i) {
		arr[cc] =0;
	}
}



template<unsigned int sizebts>
void ourbts<sizebts>::setall() {
	for (int i = 0; i < cc; ++i) {
		arr[cc] = 4294967295;
	}
}


template<unsigned int sizebts>
void ourbts<sizebts>::none() {
	
	for (int i = 0; i < cc; ++i) {
		if (arr[i] != 0) {
			cout << "Has none";
			break;
		}
	}
	
}

template<unsigned int sizebts>
int ourbts<sizebts>::findeindexpos(int index) {
	int n;
	if (index < 32) {
		n = 1;
		return n;
	}
	if (index % 32 == 0) {
		n = index / 32;
		return n;
	}
	else {
		n = index / 32;
		return ++n;

	}
}


template<unsigned int sizebts>
void ourbts<sizebts>::setfromindex(int index1,bool t) {
	int arj = arr[findeindexpos(index1)];
	unsigned int maskktru = 2147483648;
	unsigned int maskkfals = 2147483647;
	unsigned int ms = 4294967295;
	int indexinarr = index1 - (findeindexpos(index1)- 1) * 32;
	
	if (t == true) {
		maskktru >>= indexinarr;
		arr[findeindexpos(index1)]|=maskktru;
	}
	else {
		maskkfals >>= indexinarr;
		ms <<= 32 - indexinarr;
		maskkfals |= ms;
		arr[findeindexpos(index1)] |= maskkfals;
	}
	

}


template <unsigned int sizebts>
int ourbts<sizebts>::siz() {
	int n;
	if (sizebts <= 32) {
		n = 1;
		return n;
	}
	if (sizebts % 32 == 0) {
		n = sizebts / 32;
		return n;
	}
	else {
		n = sizebts / 32;
		return ++n;
		
	}


}
template <unsigned int sizebts>
void ourbts<sizebts>::setbts(unsigned long long int k) {
	unsigned long long int e = k;
	int n = cc;
	
	for (int i = 0; i < cc; ++i) {
		arr[i-1] |= k;
		if (n > 1) {
			k >>= 32;
			--n;
			arr[i + 1] |= arr[i];
			arr[i] = 0;
			
		}
		
    }
}
	




#endif //ourbts
