#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

/**********************************************************
 *           Podziały - rekurencja/iteracja               *
 * *******************************************************/

vector<int> tab_z_liczbami_pierwszymi;
vector<int> tab_do_wyswietlenia;

int suma_tablicy = 0;
int liczba_pierwsza = 1;

// Sprawdzenie czy liczba którą otrzymamy jest liczbą pierwszą
bool czy_pierwsza(int b)
{
  for (int i = 2; i * i <= b; i++)
    if (b % i == 0)
      return false;
  return true;
}

// Dodawanie liczb pierwszych do tablicy które znajdują się w badanej liczbie
void dodawanie_do_tab_liczb_pierw(int b)
{
  for (int i = 2; i <= b; i++)
  {
    if (czy_pierwsza(i))
    {
      tab_z_liczbami_pierwszymi.push_back(i);
    }
  }
}

// Wyświetlanie końcowe wyniku w terminalu
void wyswietl_liczby()
{
  for (size_t i = 0; i < tab_do_wyswietlenia.size(); i++)
  {
    if (i < tab_do_wyswietlenia.size() - 1)
    {
      cout << tab_do_wyswietlenia.at(i) << "+";
    }
    else
    {
      cout << tab_do_wyswietlenia.at(i);
    }
  }
  cout << endl;
}

// Sumuje liczby w tablicy która jest do wyświtlenia
void sumuje()
{
  suma_tablicy = 0;
  for (size_t i = 0; i < tab_do_wyswietlenia.size(); i++)
  {
    suma_tablicy = suma_tablicy + tab_do_wyswietlenia.at(i);
  }
}

// Przejście do następnej liczby pierwszej która znajduje się w badanej liczbie
void nastepna_lb_pierwsza(int &liczba_pierw, int &counter)
{
  tab_do_wyswietlenia.erase(tab_do_wyswietlenia.begin() + counter, tab_do_wyswietlenia.end());
  tab_do_wyswietlenia.push_back(tab_z_liczbami_pierwszymi.at(liczba_pierw));
  sumuje();
}

// Główna funkacja
int podzial_liczby_n(int a, int b)
{
  bool czy_liczba_pierwsza = false;

  // Eliminacja początkowa gdy druga liczba jest mniejsza od 2 lub od pierwszej liczby, lub różnica między nimi jest = 1
  if (b < 2 || b > a || a - b == 1)
  {
    return 0;
  }

  // Wyświetla odrazu gdy liczba druga jest równa 2
  if (b == 2 && a % 2 == 0)
  {
    for (int i = 0; i < a / 2; i++)
    {
      tab_do_wyswietlenia.push_back(2);
    }
    wyswietl_liczby();
    tab_do_wyswietlenia.clear();
    return 0;
  }

  // Sprawdzenie czy liczba jest liczbą pierwszą "true", "false"
  if (b != 2)
  {
    czy_liczba_pierwsza = czy_pierwsza(b);
  }

  // Sprawdzenie czy dwie liczby są takie same i czy jest liczbą pierwszą, wyświetlenie jeśli "true"
  if (czy_liczba_pierwsza && a == b)
  {
    cout << b << endl;
    return 0;
  }

  // Główny if jeśli spełnia warunki liczby pierwszej
  if (czy_liczba_pierwsza && a != b)
  {
    dodawanie_do_tab_liczb_pierw(b);

    int counter_1 = 1;
    int counter_2 = 1;
    int counter_3 = 1;
    int counter_4 = 1;

    tab_do_wyswietlenia.push_back(b);
    while (a >= suma_tablicy)
    {
      sumuje();
      while (a >= suma_tablicy)
      {
        while (a >= suma_tablicy)
        {
          while (a >= suma_tablicy)
          {
            while (a >= suma_tablicy)
            {
              //********************* Pętla dodająca 2 i 3
              while (a >= suma_tablicy)
              {
                int count_rec = (a - suma_tablicy) / 2;
                int suma_dwojek = a - suma_tablicy;
                liczba_pierwsza = 1;
                if (suma_dwojek % 2 == 0)
                {
                  while (suma_tablicy < a)
                  {
                    tab_do_wyswietlenia.push_back(2);
                    suma_tablicy = suma_tablicy + 2;
                  }
                  wyswietl_liczby();
                  tab_do_wyswietlenia.erase(tab_do_wyswietlenia.end() - count_rec, tab_do_wyswietlenia.end());
                  sumuje();
                }
                tab_do_wyswietlenia.push_back(tab_z_liczbami_pierwszymi.at(liczba_pierwsza));
                sumuje();
              }

              //********************* Pętla dodająca 5
              liczba_pierwsza = 2;
              if (unsigned(liczba_pierwsza) > tab_z_liczbami_pierwszymi.size() - 1)
              {
                break;
              }
              else
              {
                nastepna_lb_pierwsza(liczba_pierwsza, counter_1);
                counter_1++;
              }
            }
            //********************* Pętla dodająca 7
            liczba_pierwsza = 3;
            if (unsigned(liczba_pierwsza) > tab_z_liczbami_pierwszymi.size() - 1)
            {
              break;
            }
            else
            {
              nastepna_lb_pierwsza(liczba_pierwsza, counter_2);
              counter_2++;
              counter_1 = counter_2;
            }
          }
          //********************* Pętla dodająca 11
          liczba_pierwsza = 4;
          if (unsigned(liczba_pierwsza) > tab_z_liczbami_pierwszymi.size() - 1)
          {
            break;
          }
          else
          {
            nastepna_lb_pierwsza(liczba_pierwsza, counter_3);
            counter_3++;
            counter_1 = counter_3;
            counter_2 = counter_3;
          }
        }
        //********************* Pętla dodająca 13
        liczba_pierwsza = 5;
        if (unsigned(liczba_pierwsza) > tab_z_liczbami_pierwszymi.size() - 1)
        {
          break;
        }
        else
        {
          nastepna_lb_pierwsza(liczba_pierwsza, counter_4);
          counter_4++;
          counter_1 = counter_4;
          counter_2 = counter_4;
          counter_3 = counter_4;
        }
        if (suma_tablicy >= a && tab_do_wyswietlenia.back() == tab_z_liczbami_pierwszymi.at(liczba_pierwsza))
        {
          break;
        }
      }
    }
  }

  tab_z_liczbami_pierwszymi.clear();
  tab_do_wyswietlenia.clear();
  suma_tablicy = 0;
  liczba_pierwsza = 1;
  return 0;
}
int main()
{
  int a, b, num;
  cin >> num;
  while (cin >> a >> b)
  {
    podzial_liczby_n(a, b);
  };
  return 0;
}