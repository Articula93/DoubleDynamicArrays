#include<iostream>;
using namespace std;

int** Allocate(const int rows, const int cols);
void Clear(int**& arr, const int rows);

void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr, const int rows, const int cols);

int** push_row_down(int** arr, int& rows, const int cols);
int** push_row_ap(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int& index);
void push_col_right(int** arr, const int rows, int& cols);
void push_col_left(int** arr, const int rows, int& cols);
int** pop_row_down(int** arr, int& rows, const int cols);
int** pop_row_up(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, int& index);
void pop_col_right(int** arr, const int rows, int& cols);
void pop_col_left(int** arr, const int rows, int& cols);
void insert_col(int** arr, const int rows, int& cols, int& index);
void erase_col(int** arr, const int rows, int& cols, int& index);
void main()
{
	setlocale(LC_ALL, "Russian");
	int rows;
	int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	cout << "��� ��������� ������: " << endl;
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��� ������ � ����������� ������ � ����� �������: " << endl;
	arr = push_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��� ������ � ����������� ������ � ������ �������: " << endl;
	arr = push_row_ap(arr, rows, cols);
	Print(arr, rows, cols);
	int index;
	cout << "������� �������� ������� �� �������� ����� ��������� ������ � ������: "; cin >> index;
	cout << "��� ������ � ����������� ������ �� �������: " << endl;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "��� ������ � ����������� ������ � ����� �������: " << endl;
	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��� ������ � ����������� ������� � ������ �������: " << endl;
	push_col_left(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��� ������ � ��������� ��������� ������: " << endl;
	arr = pop_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��� ������ � ��������� ������ ������: " << endl;
	arr = pop_row_up(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������ ��� �������� ������ ������� �� �������: "; cin >> index;
	cout << "��� ������ � ��������� ������ �� �������: " << endl;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "��� ������ � ��������� ���������� ������� � �������: " << endl;
	pop_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��� ������ � ��������� ������� ������� �������: " << endl;
	pop_col_left(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� �������� ������� �� �������� ���������� ������� � ��� ������: "; cin >> index;
	cout << "��� ������ � ����������� ������� �� �������:" << endl;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "������� �������� ������� �� �������� �������� ������� � ����� �������: "; cin >> index;
	cout << "��� ������ � ��������� ������� �� �������: " << endl;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	Clear(arr, rows);
}
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int**& arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, const int rows, const int cols)
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
int** push_row_down(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
	return arr;
	cout << endl;
}
int** push_row_ap(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{};
	buffer[0] = new int[cols] {};
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
int** insert_row(int** arr, int& rows, const int cols, int& index)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new int[cols] {};
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
void push_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
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
void push_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
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
int** pop_row_down(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1]{};
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
int** pop_row_up(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
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
int** erase_row(int** arr, int& rows, const int cols, int& index)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new int[cols];
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
void pop_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
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
void pop_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
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
void insert_col(int** arr, const int rows, int& cols, int& index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
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
void erase_col(int** arr, const int rows, int& cols, int& index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
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