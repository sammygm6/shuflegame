#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

void impArray(char**,int);

int main(int argc, char const *argv[])
{
	cout << "Bienvenido a el juego" << endl;
	int colA;
	cout << "Columna A:" << endl;
	cin >> colA;
	double denominador = colA;
	int colB;
	cout << "COlumna B:" << endl;
	cin >> colB;
	char** columnaA = new char*[colA];
	char** columnaB = new char*[colB];
	for (int i = 0; i < colA; i++)
	{
		char entrada[80];
		cout << "Ingrese palabra para columna A:" << endl;
		cin >> entrada;
		columnaA[i] = new char[strlen(entrada)+1];
		strcpy(columnaA[i],entrada);
	}
	impArray(columnaA,colA);
	for (int i = 0; i < colB; i++)
	{
		char entrada[80];
		cout << "Ingrese palabra para columna B:" << endl;
		cin >> entrada;
		columnaB[i] = new char[strlen(entrada)+1];
		strcpy(columnaB[i],entrada);
	}
	impArray(columnaB,colB);
	cout << "Ingrese las respuestas correctas:" << endl;
	char** respuestas = new char*[colA];
	for (int i = 0; i < colA; i++)
	{
		respuestas[i] = new char[2];
		for (int j = 0; j < 2; j++)
		{
			char R;
			if (j == 0)
			{
				cout << "Col A: ";
				cin >> R;
				respuestas[i][j] = R;
			}else{
				cout << "Col B:";
				cin >> R;
				respuestas[i][j] = R;
			}
			cout << endl;
		}
	}
	cout << "------Columna A------" << endl;
	impArray(columnaA,colA);
	cout << "------Columna B------" << endl;
	impArray(columnaB,colB);
	cout << endl;

	cout << "Trade de conectar las correctas:" << endl;

	char** suposiciones = new char*[colA];

	for (int i = 0; i < colA; i++)
	{
		char R;
		suposiciones[i] = new char[2];
		for(int j = 0; j < 2; j++){
			if (j == 0)
			{
				cout << "Col A: ";
				cin >> R;
				suposiciones[i][j] = R;
			}else{
				cout << "Col B: ";
				cin >> R;
				suposiciones[i][j] = R;
			}
			cout << endl;
		}
	}

	int cont_correctas = 0;

	for (int i = 0; i < colA; ++i)
	{
		for (int j = 0; j < strlen(suposiciones[i]); j++)
		{
			if (strcmp(respuestas[i],suposiciones[j]) == 0)
			{
				cont_correctas++;
			}
		}
	}
	double porcentaje = (cont_correctas / denominador)*100;

	printf("respuesta es: %.0f",porcentaje);

	cout << "\%" << endl;

	///liberado de memoria
	for (int i = 0; i < colA; i++)
	{
		delete[] columnaA[i];
		delete[] respuestas[i];
		delete[] suposiciones[i];
	}
	for (int i = 0; i < colB; i++)
	{
		delete[] columnaB[i];
	}
	delete[] columnaA;
	delete[] columnaB;
	delete[] respuestas;
	delete[] suposiciones;
	
	return 0;
}
void impArray(char** x, int size){
	cout << "------Palabras------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << ". ";
		for (int j = 0; j < strlen(x[i]); j++)
		{
			cout << x[i][j];
		}
		cout << endl;
	}
}