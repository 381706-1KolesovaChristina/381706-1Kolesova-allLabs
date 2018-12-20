#pragma once
#include "Vector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &mt);
  TMatrix(const TVector<TVector<T> > &mt);
  virtual ~TMatrix();

  bool operator==(const TMatrix &mt) const;      // сравнение равно
  bool operator!=(const TMatrix &mt) const;      // сравнение неравно
  TMatrix& operator=(const TMatrix &mt);        // присваивание
  TMatrix operator+(const TMatrix &mt);         // сложение
  TMatrix operator-(const TMatrix &mt);         // вычитание
  TMatrix<T> operator*(const TMatrix<T> &MT);    // умножение

  template <class ValType2>
  friend istream& operator>>(istream &in, TMatrix<ValType2> &mt);
  template <class ValType2>
  friend ostream & operator<<(ostream &out, const TMatrix<ValType2> &mt);
};

template <class T>
TMatrix<T>::TMatrix(int s) :TVector<TVector<T> >(s)
{
  if (s <= 0 )
    throw MyException(" wrong size ");
  for (int i = 0; i < s; i++)
    this->Mas[i] = TVector<T>(s - i);
} 
//-------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &mt) :TVector<TVector<T> >(mt)
{}
//-------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &mt) :TVector<TVector<T> >(mt)
{}
//-------------------------------------------------------------------------
template <class T>
TMatrix<T>::~TMatrix() 
{}
//-------------------------------------------------------------------------
template <class T >
bool TMatrix<T>::operator==(const TMatrix<T> &mt) const
{
  return TVector<TVector<T> >::operator==(mt);
} 
//-------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &mt) const
{
  return TVector<TVector<T> >::operator!=(mt);
} 
//-------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &mt)
{
  TVector<TVector<T> >::operator=(mt);
  return *this;
} 
//-------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &mt)
{
  if (this->Size == mt.Size)
    return TVector<TVector<T> >::operator+(mt);
  else
    throw MyException(" wrong size ");
} 
//-------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &mt)
{
  if (this->Size == mt.Size)
    return TVector<TVector<T> >::operator-(mt);
  else
    throw MyException(" wrong size ");
} 
//-------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &MT)
{
  if (this->Size != MT.Size)
    throw MyException(" wrong size ");
  TMatrix <T> rez(this->Size);
  for (int i = 0; i < this->Size; i++)
    for (int j = i; j < this->Size; j++) {
      for (int k = i; k <= j; k++)
        rez.Mas[i][j - i] += this->Mas[i][k - i] * MT.Mas[k][j - k];
    }
  return rez;
}
//-------------------------------------------------------------------------
template <class ValType2>
istream& operator>>(istream &in, TMatrix<ValType2> &mt)
{
  for (int i = 0; i < mt.Size; i++)
    in >> mt.Mas[i];
  return in;
}
//-------------------------------------------------------------------------
template <class ValType2>
ostream & operator<<(ostream &out, const TMatrix<ValType2> &mt)
{
  for (int i = 0; i < mt.Size; i++)
    out << mt.Mas[i] << endl;
  return out;
}