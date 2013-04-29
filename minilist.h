#include <cstdlib>
#include <iterator>

template <class T>
struct cell {
	T _value;
	cell * _next;
};

template <class T> struct _iterator;

template <class T>
class minilist {
	cell<T> * _begin;
	cell<T> * _end;
	size_t _size;

	public:
		minilist() : _begin(NULL), _end(NULL), _size(0) {}
		minilist(const minilist & c)
		{
			_size = c._size;
			if (_size == 0) {
				_begin = NULL;
				_end = NULL;
			} else {
				cell<T> * temp = c._begin;
				_begin = new cell<T>;
				_begin -> _value = temp -> _value;
				_end = _begin;
				while (temp -> _next != NULL) {
					_end -> _next = new cell<T>;
					_end = _end -> _next;
					temp = temp -> _next;
					_end -> _value = temp -> _value;
				}
				_end -> _next = NULL;
			}
		}

		~minilist()
		{
			while (_begin != NULL) {
				cell<T> * temp = _begin;
				_begin = _begin -> _next;
				delete temp;
			}
		}

		minilist & operator = (const minilist & c)
		{
			while (_begin != NULL) {
				cell<T> * temp = _begin;
				_begin = _begin -> _next;
				delete temp;
			}

			_size = c._size;
			if (_size == 0) {
				_begin = NULL;
				_end = NULL;
			} else {
				cell<T> * temp = c._begin;
				_begin = new cell<T>;
				_begin -> _value = temp -> _value;
				_end = _begin;
				while (temp -> _next != NULL) {
					_end -> _next = new cell<T>;
					_end = _end -> _next;
					temp = temp -> _next;
					_end -> _value = temp -> _value;
				}
				_end -> _next = NULL;
			}

			return *this;
		}

		void push_back(T & obj)
		{
			if (_size == 0) {
				_begin = new cell<T>;
				_end = _begin;
			} else {
				_end -> _next = new cell<T>;
				_end = _end -> _next;
			}
			_end -> _value = obj;
			_end -> _next = NULL;
			_size++;
		}

		size_t size() { return _size; }

		_iterator<T> begin()
		{
			return (_iterator<T>(_begin));
		}

		_iterator<T> end()
		{
			return (_iterator<T>(_end));
		}

		friend struct _iterator<T>;
};


template <class T>
struct _iterator
{
	typedef _iterator<T>			_Self;
	typedef cell<T>				_Node;

	typedef std::ptrdiff_t			difference_type;
	typedef std::forward_iterator_tag	_iterator_category;
	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;

	_Node * p;

	_iterator() : p() {}
	explicit _iterator(_Node * x) : p(x) {}

	pointer operator -> () const		//почему нет аргументов и возращается в любом случае _value?
	{
		return &(p -> _value);
	}

	reference operator * () const
	{
		return (p -> _value);
	}

	_Self & operator ++ ()
	{
		p = p -> _next;
		return *this;
	}

	_Self operator ++ (int)
	{
		_Self temp = *this;
		p = p -> _next;
		return temp;
	}

	bool operator == (const _Self & obj) const
	{
		return (p == obj.p);
	}

	bool operator != (const _Self & obj) const
	{
		return (p != obj.p);
	}
};
