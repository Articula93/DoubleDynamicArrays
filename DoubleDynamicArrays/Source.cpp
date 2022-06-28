#include<iostream>;
using namespace std;

template<typename T>T** Allocate(const T rows, const T cols);
template<typename T>void Clear(T**& arr, const T rows);

template<typename T>void FillRand(T** arr, const T rows, const T cols);
template<typename T>void Print(T** arr, const T rows, const T cols);


template<typename T>T** push_row_down(T** arr, T& rows, const T cols);
template<typename T>T** push_row_ap(T** arr, T& rows, const T cols);
template<typename T>T** insert_row(T** arr, T& rows, const T cols, T& index);
template<typename T>void push_col_right(T** arr, const T rows, T& cols);
template<typename T>void push_col_left(T** arr, const T rows, T& cols);
template<typename T>T** pop_row_down(T** arr, T& rows, const T cols);
template<typename T>T** pop_row_up(T** arr, T& rows, const T cols);
template<typename T>T** erase_row(T** arr, T& rows, const T cols, T& index);
template<typename T>void pop_col_right(T** arr, const T rows, T& cols);
template<typename T>void pop_col_left(T** arr, const T rows, T& cols);
template<typename T>void insert_col(T** arr, const T rows, T& cols, T& index);
template<typename T>void erase_col(T** arr, const T rows, T& cols, T& index);
void main()
{
	setlocale(LC_ALL, "Russian");
	int rows;
	int cols;
	cout << "введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	cout << "Наш двумерный массив: " << endl;
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Наш массив с добавлением строки в конец массива: " << endl;
	arr = push_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Наш массив с добавлением строки в начало массива: " << endl;
	arr = push_row_ap(arr, rows, cols);
	Print(arr, rows, cols);
	int index;
	cout << "Введите значение индекса по которому будет добавлена строка в массив: "; cin >> index;
	cout << "Наш массив с добавлением строки по индексу: " << endl;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "Наш массив с добавлением стобца в конец массива: " << endl;
	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Наш массив с добавлением столбца в начало массива: " << endl;
	push_col_left(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Наш массив с удалением последней строки: " << endl;
	arr = pop_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Наш массив с удалением первой строки: " << endl;
	arr = pop_row_up(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите индекс для удаления строки массива по индексу: "; cin >> index;
	cout << "Наш массив с удалением строки по индексу: " << endl;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "Наш массив с удалением последнего столбца в массиве: " << endl;
	pop_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Наш Массив с удалением первого столбца массива: " << endl;
	pop_col_left(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Введите значение индекса по которому добавиться столбец в наш массив: "; cin >> index;
	cout << "Наш Массив с добавлением столбца по индексу:" << endl;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "Введите значение индекса по которому удалится столбец в нашем массиве: "; cin >> index;
	cout << "Наш массив с удалением столбца по индексу: " << endl;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	Clear(arr, rows);
}
template<typename T>T** Allocate(const T rows, const T cols)
{
	T** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
template<typename T>void Clear(T**& arr, const T rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}
template<typename T>void FillRand(T** arr, const T rows, const T cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
template<typename T>void Print(T** arr, const T rows, const T cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
template<typename T>T** push_row_down(T** arr, T& rows, const T cols)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new T[cols] {};
	rows++;
	return arr;
	cout << endl;
}
template<typename T>T** push_row_ap(T** arr, T& rows, const T cols)
{
	T** buffer = new T* [rows + 1]{};
	buffer[0] = new T[cols] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
	cout << endl;
}
template<typename T>T** insert_row(T** arr, T& rows, const T cols, T& index)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new T[cols] {};
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
	cout << endl;
}
template<typename T>void push_col_right(T** arr, const T rows, T& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	cout << endl;
}
template<typename T>void push_col_left(T** arr, const T rows, T& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	cout << endl;
}
template<typename T>T** pop_row_down(T** arr, T& rows, const T cols)
{
	T** buffer = new T* [rows - 1]{};
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
	cout << endl;
}
template<typename T>T** pop_row_up(T** arr, T& rows, const T cols)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
	cout << endl;
}
template<typename T>T** erase_row(T** arr, T& rows, const T cols, T& index)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new T[cols];
	for (int i = index; i < rows - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
	cout << endl;
}
template<typename T>void pop_col_right(T** arr, const T rows, T& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	cout << endl;
}
template<typename T>void pop_col_left(T** arr, const T rows, T& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	cout << endl;
}
template<typename T>void insert_col(T** arr, const T rows, T& cols, T& index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < index; j++)
		{
			buffer[index] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	cout << endl;
}
template<typename T>void erase_col(T** arr, const T rows, T& cols, T& index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < index; j++)
		{
			buffer[i] = arr[i][j];
		}

		for (int j = index; j < cols - 1; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	cout << endl;
}