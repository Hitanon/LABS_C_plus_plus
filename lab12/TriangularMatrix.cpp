//#include "TriangularMatrix.h"
//
//template<class T>
//uint TriangularMatrix<T>::getStorageSize() const
//{
//	uint count = 0;
//	for (uint i = 0; i < size; i++) count += (i + 1);
//	return count;
//}
//
//template<class T>
//TriangularMatrix<T>::TriangularMatrix()
//{
//	if (matrix) delete[] matrix;
//	matrix = nullptr;
//	size = 0;
//	count = 0;
//}
//
//template<class T>
//inline TriangularMatrix<T>::TriangularMatrix(uint size)
//	: size(size), count(getStorageSize())
//{
//	if (matrix) delete[] matrix;
//	matrix = new T[count];
//	for (uint i = 0; i < count; i++) matrix[i] = T();
//}
//
//template<class T>
//TriangularMatrix<T>::TriangularMatrix(const TriangularMatrix<T>& other)
//	: size(other.size), count(getStorageSize())
//{
//	if (matrix) delete[] matrix;
//	matrix = new T[count];
//	for (uint i = 0; i < size; i++)
//		for (uint j = i; j < size; j++)
//			(*this)(i, j) = other(i, j);
//}
//
//template<class T>
//TriangularMatrix<T>::~TriangularMatrix()
//{
//	if (matrix)
//	{
//		delete[] matrix;
//		size = 0;
//		count = 0;
//	}
//}
//
//template<class T>
//TriangularMatrix<T>& TriangularMatrix<T>::operator=(const TriangularMatrix<T>& other)
//{
//	if (other.matrix == nullptr)
//	{
//		size = 0;
//		count = 0;
//		delete[] matrix;
//		matrix = nullptr;
//		return *this;
//	}
//	if (this != &other)
//	{
//		if (matrix) delete[] matrix;
//		size = other.size;
//		count = getStorageSize();
//		matrix = new T[count];
//		for (uint i = 0; i < size; i++)
//			for (uint j = i; j < size; j++)
//				(*this)(i, j) = other(i, j);
//	}
//	return *this;
//}
//
//template<class T>
//T& TriangularMatrix<T>::operator()(uint i, uint j) const
//{
//	if (i >= size || j >= size)
//		throw out_of_range("Индекс за границами матрицы!");
//	uint storageIndex = i * (i + 1) / 2 + j;
//	return matrix[storageIndex];
//}
//
//template<class T>
//void TriangularMatrix<T>::SetSize(uint newSize)
//{
//	if (newSize == size) return;
//	if (newSize == 0)
//	{
//		this->~TriangularMatrix();
//		return;
//	}
//	T* newMatrix = new T[newSize * (newSize + 1) / 2];
//
//	uint copySize = min(newSize, size);
//	for (uint i = 0; i < copySize; i++)
//		for (uint j = 0; j <= i; j++)
//		{
//			uint storageIndex = i * (i + 1) / 2 + j;
//			newMatrix[storageIndex] = matrix[storageIndex];
//		}
//	delete[] matrix;
//	matrix = newMatrix;
//	size = newSize;
//	count = getStorageSize();
//}
//
//template<class T>
//void TriangularMatrix<T>::Clear()
//{
//	if (matrix) delete[] matrix;
//	matrix = new T[count];
//	for (uint i = 0; i < count; i++) matrix[i] = T();
//}
//
//template<class T>
//bool TriangularMatrix<T>::operator==(const TriangularMatrix<T>& other) const
//{
//	if (size != other.size) return false;
//	for (uint i = 0; i < size; i++)
//		for (uint j = 0; j < size; j++)
//			if (!((*this)(i, j) == other(i, j))) return false;
//	return true;
//}
//
//template<class T>
//bool TriangularMatrix<T>::IsEmpty()
//{
//	return size == 0;
//}
