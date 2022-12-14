#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

double InterpolacjaNewtona_b(double* xs, double* ys, int k) // funkcja licząca b od k
{
    double b = 0.0;


        for (int i = 0; i < k; i++)// 2, 3, 4,
        {
            double t = 1.0;
            if (k > 1)
            {
                for (int j = 0; j < k; j++) //2,3
                {
                    if (j != i)
                    {
                        t *= xs[i] - xs[j];
                    }
                }
            }
            else
            {
                t = 1;
            }
            b += ys[i] / t;

        }

    return b;
}
double InterpolacjaNewtona_p(double* xs, double x, int k)//funkcja licząca p od k
{
    double p = 1.0;
    if (k > 0)
    {
        for (int i = 0; i < k; i++)
        {
            p *= x - xs[i];
        }
    }
    return p;
}
double InterpolacjaNewtona(double* b, double* p, double n) // funkcja licząca wielomian 
{
    double Wn = 0.0;
    for(int i= 0; i < n; i++)
    { 
        Wn += p[i] * b[i];
    }
    return Wn;
}

int main()
{
    //odczyt z pliku

    
    //string ile;
    /*ifstream oplik("C:\\Users\\micha\\source\\repos\\Interpolacja wielomianu Newtona\\dane.txt");
    if (oplik.good())
    {
        getline(oplik, ile);
        int iloscLiczbWTablicy = stoi(ile);
        tab_x = new double[iloscLiczbWTablicy];
        tab_y = new double[iloscLiczbWTablicy];
        for (int i = 0; i < iloscLiczbWTablicy; i++)
        {
            string textoweDane;


            getline(oplik, textoweDane);
            tab_x[i] = stod(textoweDane);//przypisanie do tablicy x z pliku
        }
        for (int i = 0; i < iloscLiczbWTablicy; i++)
        {
            string textoweDane;


            getline(oplik, textoweDane);
            tab_y[i] = stod(textoweDane);//przypisanie do tablicy y z pliku
        }

    }*/
    

    double tab_x [] = {1, 2, 3, 4, 5};
    double tab_y [] = {1, 4, 9, 16, 25};

    double x;
    cout << "Podaj x dla ktorego chcesz policzyc zadanie = " << endl;
    cin >> x; //przypisanie x z klawiatury
    int n;
    n = 5;
    double b[5];
    double p[5];
    for (int i = 0; i < n; i++)
    {
        b[i] = InterpolacjaNewtona_b(tab_x, tab_y, i+1);
        p[i] = InterpolacjaNewtona_p(tab_x, x, i);
    }

    //ponizej znajduje się wypisanie danych ->
    cout << "Liczba wezlow = " << 5 << endl;

    for (int z = 0; z < 5; z++)
    {
        std::cout << z + 1 << ". Wezly interpolacji = " << tab_x[z] << endl;
        std::cout << z + 1 << ". Wartosci funkcji w wezlach = " << tab_y[z] << endl;
    }
    for (int k = 0; k < 5; k++)
    {
        std::cout << k + 1 << ".  Wspolczynniki wielomianu Newtona = " << b[k] << endl;
        std::cout << k + 1 << ". Punkt, w ktorym liczymy wartosc = " << p[k] << endl;
    }

    double Wn = InterpolacjaNewtona(b, p, n); //w tym miejscu wywołujemy funkcję obliczającą Wielomian
    cout << "x = " << x << "-> Wn = " << Wn << endl;
    return 0;
}

