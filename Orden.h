#pragma once
#include <iostream>
#include <stdlib.h>
using namespace System;
ref class Orden
{
public:
	void BubleSortGeneracion(array <String^>^ separar, int n)
	{
		int i, j;
		String^ aux;
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (Int32::Parse(separar[i]->Substring(separar[i]->Length - 2, 2)) < Int32::Parse(separar[j]->Substring(separar[j]->Length -2, 2)))
				{

					aux = separar[i];
					separar[i] = separar[j];
					separar[j] = aux;
				}			
			}
		}
	}
	//
	void BubleSortNumber(array <String^>^ separar, int n)
	{
		int i, j;
		String^ aux;
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (Int32::Parse(separar[i]->Substring(separar[i]->Length - 6, 3)) < Int32::Parse(separar[j]->Substring(separar[j]->Length - 6, 3)))
				{
					aux = separar[i];
					separar[i] = separar[j];
					separar[j] = aux;
				}
			}
		}
	}
	//
	void QuickSortGeneracion(array <String^>^ separar, int izq, int der)
	{
		int i = izq;
		int j = der;
		String^ tmp;
		int p = Int32::Parse(separar[(izq + der) / 2]->Substring(separar[(izq + der) / 2]->Length - 2,2));
		while (i <= j)
		{
			while (Int32::Parse(separar[i]->Substring(separar[i]->Length -2,2)) > p) i++;
			while (Int32::Parse(separar[j]->Substring(separar[j]->Length - 2, 2)) < p) j--;
			if (i <= j)
			{
				tmp = separar[i];
				separar[i] = separar[j];
				separar[j] = tmp;
				i++; j--;
			}
		}
		if (izq < j)
		{
			QuickSortGeneracion(separar, izq, j);
		}
		if (i < der)
		{
			QuickSortGeneracion(separar, i, der);
		}
	}
	//
	void QuickSortNumber(array <String^>^ separar, int izq, int der)
	{
		int i = izq;
		int j = der;
		String^ tmp;
		int p = Int32::Parse(separar[(izq + der) / 2]->Substring(separar[(izq + der) / 2]->Length - 6, 3));
		while (i <= j)
		{
			while (Int32::Parse(separar[i]->Substring(separar[i]->Length - 6, 3)) > p) i++;
			while (Int32::Parse(separar[j]->Substring(separar[j]->Length - 6, 3)) < p) j--;
			if (i <= j)
			{
				tmp = separar[i];
				separar[i] = separar[j];
				separar[j] = tmp;
				i++; j--;
			}
		}
		if (izq < j)
		{
			QuickSortNumber(separar, izq, j);
		}
		if (i < der)
		{
			QuickSortNumber(separar, i, der);
		}
	}
	//
	static bool IsSortedGeneracion(array <String^>^ separar, int count)
	{
		while (--count >= 1)
		{	
			if (Int32::Parse(separar[count]->Substring(separar[count]->Length - 2,2)) < Int32::Parse(separar[count - 1]->Substring(separar[count - 1]->Length - 2,2)))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	static void ShuffleGeneracion(array <String^>^ separar, int count)
	{
		String^ temp;
		int rnd;
		
		for (int i = 0; i < count; i++)
		{
			rnd = rand() % count;
			temp = separar[i];
			separar[i] = separar[rnd];
			separar[rnd] = temp;
		}
	}
	static void StupidSortGeneracion(array <String^>^ separar, int count)
	{
		while (!IsSortedGeneracion(separar, count))
		{
			ShuffleGeneracion(separar,count);
		}
	}
	//
	static bool IsSortedNumber(array <String^>^ separar, int count)
	{
		while (--count >= 1)
		{
			if (Int32::Parse(separar[count]->Substring(separar[count]->Length - 6, 3)) < Int32::Parse(separar[count - 1]->Substring(separar[count - 1]->Length - 6, 3)))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	static void ShuffleNumber(array <String^>^ separar, int count)
	{
		String^ temp;
		int rnd;

		for (int i = 0; i < count; i++)
		{
			rnd = rand() % count;
			temp = separar[i];
			separar[i] = separar[rnd];
			separar[rnd] = temp;
		}
	}
	static void StupidSortNumber(array <String^>^ separar, int count)
	{
		while (!IsSortedNumber(separar, count))
		{
			ShuffleNumber(separar, count);
		}
	}
	//...
};