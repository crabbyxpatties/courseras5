#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient
{

private:
  double masse;
  double hauter;

public:
  void init(double poids, double taille)
  {

    if (poids >= 0 && taille >= 0)
    {

      masse = poids;
      hauter = taille;
    }
    else
    {
      masse = 0;
      hauter = 0;
    }
  }

  void afficher()
  {

    cout << "Patient : " << masse << " kg pour " << hauter << " m\n";
  }

  double poids()
  {
    return masse;
  }

  double taille()
  {
    return hauter;
  }

  double imc()
  {

    if (hauter == 0)
      return 0;

    return masse / (hauter * hauter);
  }

};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  Patient quidam;
  double poids, taille;
  do
  {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
