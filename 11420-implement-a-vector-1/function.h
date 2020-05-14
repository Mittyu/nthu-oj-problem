#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<iosfwd>

namespace oj
{
	class Memory_leak_count	//check whether the process has memory leak
	{
		friend void memory_leak_count_check();
		static unsigned count_;
	public:
		Memory_leak_count();
		~Memory_leak_count();
	};

	struct Int	//you can treat Int as int
	{
		int val;	//store int in val, you this val
		Int();
		Int(int val);
		Int(const Int &);	//copy constructor
		operator int&()	//treat Int as int, conversion function
		{
			return val;
		}
		operator int() const	//treat Int as int, conversion function
		{
			return val;
		}
		Int& operator=(const Int &);	//copy constructor
	private:
		Memory_leak_count count_;	//you don't have to pay attention on this
	};

	typedef Int data_t;

	class Vector
	{
	public:
		typedef std::size_t size_type;
		typedef Int value_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
	private:
		pointer begin_;	//begin of array
		pointer end_;	//end of array
		pointer last_;	//end of current element
	public:
		Vector();
		inline size_type capacity() const
		{
			return end_-begin_;
		}
		inline size_type size() const
		{
			return last_-begin_;
		}
		//ignore the keyword "inline"
		//operator[] makes Vector like a C-array, for example
		//int a[2]{2,1};
		//Vector vec;
		//vec.push_back(1);
		//vec.push_back(2);
		//vec[0] is equal to a[1]
		//vec[1] is equal to a[0]
		inline reference operator[](const size_type pos)
		{
			return begin_[pos];
		}
		inline const_reference operator[](const size_type pos) const
		{
			return begin_[pos];
		}
		
		void pop_back();

		void push_back(value_type val);
	
		void reserve(size_type new_capacity);
		
		~Vector();
	};

	std::ostream& operator<<(std::ostream &os,const Vector &vec);	//for cout
	void memory_leak_count_check();	//you don't have to pay attention on this
}

#endif

void oj::Vector::pop_back() {
	if (this->size() == 0) return;

	size_type last = this->size();
	if (last > 1) 
		this->last_ = &this->begin_[last - 1];
	else
		this->last_ = this->begin_;
}

void oj::Vector::push_back(value_type val) {
	// resize checking
	size_type sz = this->size();
	size_type cp = this->capacity();
	if (sz >= cp) {
		size_type m = (cp+1 > cp*3) ? cp+1:cp*3;
		this->reserve(m);
	}
	// add new a element
	size_type last = this->size();
	this->begin_[last] = val;
	this->last_ = &this->begin_[last + 1];
}

void oj::Vector::reserve(size_type new_capacity) {
	if (this->capacity() >= new_capacity) return;

	pointer arr_n = new value_type[new_capacity + 1];
	
	// copy by value
	size_type i;
	for (i = 0; i < this->size(); i++) {
		arr_n[i] = this->begin_[i];
	}
	this->last_ = &arr_n[i];
	this->end_ = &arr_n[new_capacity];
	delete [] this->begin_;
	this->begin_ = arr_n;
}

oj::Vector::~Vector() {
	delete [] begin_;
}