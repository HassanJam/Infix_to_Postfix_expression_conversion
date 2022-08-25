#pragma once
template <class T>
class Stackclass
{
private:
	T* array;
	int size;
	int top;

public:
	Stackclass(int s)
	{

		size = s;
		top = 0;
		array = new T[size];
	}


	bool push(T data)


	{
		if (isfull())
		{
			return false;
		}
		array[top++] = data;
		return true;
	}


	bool pop()

	{
		if (isempty())
		{
			return false;
		}
		array[top--];
		return true;
	}

	bool isfull()
	{
		if (top == size)
		{
			return true;
		}
		return false;
	}

	bool isempty()
	{
		if (top == 0)
		{
			return true;
		}
		return false;
	}

	T peek()
	{


		return array[top-1];
	}





};

