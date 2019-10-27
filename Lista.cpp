#include "Lista.h"
#include "MyForm.h";

void Lista::MeterNumero(String^ valor)
{
	ListaNums^ nuevodato = gcnew ListaNums;
	nuevodato->valor = valor;

	ListaNums^ aux1 = primera;	
	ListaNums^ aux2;

	if (primera == aux1)
	{
		primera = nuevodato;
	}
	else
	{
		aux2->siguiente = nuevodato;
	}
	nuevodato->siguiente = aux1;
}
//
void Lista::MostrarLista()
{
	ListaNums^ actual = gcnew ListaNums;
	actual = primera;

	while (actual != nullptr)
	{
		System::Windows::Forms::MessageBox::Show(actual->valor);
		actual = actual->siguiente;
	}
}