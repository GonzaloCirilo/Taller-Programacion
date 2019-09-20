#include <iostream>
using namespace std;
int main()
{
	int escala, hora;

	cout << "Ingrese la escala: ";
	cin >> escala;

	if (escala < 1 || escala > 8) {
		// error
		cout << "Error en la escala" << endl;
		return 0;
	}

	cout << "Ingrese cantidad de horas trabajadas en la semana: ";
	cin >> hora;

	if (hora != 24 && hora != 30 && hora != 40) {
		// error
		cout << "Error en la hora" << endl;
		system("pause");
		// si usan conio.h 
		// _getch();
		return 0;
	}

	int remu = 0;

	switch (hora) {
	case 24: 
		switch (escala)
		{
		case 1:
			remu = 1243;
			break;
		case 2:
			remu = 1430;
			break;
		case 3:
			remu = 1617;
			break;
		case 4:
			remu = 1865;
			break;
		case 5:
			remu = 2239;
			break;
		case 6:
			remu = 2612;
			break;
		case 7:
			remu = 2861;
			break;
		case 8:
			remu = 3109;
			break;
		}
		break;
	case 30:
		switch (escala)
		{
		case 1:
			remu = 1554;
			break;
		case 2:
			remu = 1788;
			break;
		case 3:
			remu = 2021;
			break;
		case 4:
			remu = 2332;
			break;
		case 5:
			remu = 2798;
			break;
		case 6:
			remu = 3265;
			break;
		case 7:
			remu = 3576;
			break;
		case 8:
			remu = 3887;
			break;
		}
		break;
	case 40:
		switch (escala)
		{
		case 1:
			remu = 2073;
			break;
		case 2:
			remu = 2384;
			break;
		case 3:
			remu = 2695;
			break;
		case 4:
			remu = 3109;
			break;
		case 5:
			remu = 3731;
			break;
		case 6:
			remu = 4353;
			break;
		case 7:
			remu = 4768;
			break;
		case 8:
			remu = 5183;
			break;
		}
	}

	cout << "Su remuneración mensual es "<< remu << endl;
	system("pause");
	// si usan conio.h 
	// _getch();
	return 0;
}