#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/
class Auteur {
public:
    Auteur(string nom, bool prime = false) : nom(nom), prime(prime) {}

    string getNom() const {
        return nom;
    }

    bool getPrix() const {
        return prime;
    }

private:
    string nom;
    bool prime;
};

class Oeuvre {
public:
    Oeuvre(string titre, const Auteur& auteur, string langue)
        : titre(titre), auteur(auteur), langue(langue) {}

    string getTitre() const {
        return titre;
    }

    const Auteur& getAuteur() const {
        return auteur;
    }

    string getLangue() const {
        return langue;
    }

    void affiche() const {
        cout << titre << ", " << auteur.getNom() << ", en " << langue<<endl;
    }

    ~Oeuvre() {
        cout << "L'oeuvre \"" << titre << ", " << auteur.getNom() << ", en " << langue << "\" n'est plus disponible." << endl;
    }

private:
    string titre;
    const Auteur& auteur;
    string langue;
};

class Exemplaire {
public:
    Exemplaire(const Oeuvre& oeuvre) : oeuvre(oeuvre) {
        cout << "Nouvel exemplaire de : ";
        oeuvre.affiche();
    }

    Exemplaire(const Exemplaire& copy) : oeuvre(copy.oeuvre) {
        cout << "Copie d'un exemplaire de : ";
        oeuvre.affiche();
    }

    ~Exemplaire() {
        cout << "Un exemplaire de \"" << oeuvre.getTitre() << ", " << oeuvre.getAuteur().getNom() << ", en " << oeuvre.getLangue() << "\" a été jeté !" << endl;
    }

    const Oeuvre& getOeuvre() const {
        return oeuvre;
    }

    void affiche() const {
        cout << "Exemplaire de : ";
        oeuvre.affiche();
    }

private:
    const Oeuvre& oeuvre;
};

class Bibliotheque {
public:
    Bibliotheque(string nom) : nom(nom) {
        cout << "La bibliothèque " << nom << " est ouverte !" << endl;
    }

    string getNom() const {
        return nom;
    }

    void stocker(const Oeuvre& oeuvre, unsigned int n = 1) {
        for (unsigned int i = 0; i < n; ++i) {
            exemplaires.push_back(new Exemplaire(oeuvre));
        }
    }

    void lister_exemplaires(string langue = "") const {
        for (const auto& exemplaire : exemplaires) {
            if (langue.empty() || exemplaire->getOeuvre().getLangue() == langue) {
                exemplaire->affiche();
            }
        }
    }

    int compter_exemplaires(const Oeuvre& oeuvre) const {
     
    int count = 0;
    for (const auto& exemplaire : exemplaires) {
        if (&(exemplaire->getOeuvre()) == &oeuvre) {
            ++count;
        }
    }
    return count;

    }

    void afficher_auteurs(bool prix = false) const {
        for (const auto& exemplaire : exemplaires) {
            const Auteur& auteur = exemplaire->getOeuvre().getAuteur();
            if (!prix || (prix && auteur.getPrix())) {
                cout << auteur.getNom() << endl;
            }
        }
    }

    ~Bibliotheque() {
        cout << "La bibliothèque " << nom << " ferme ses portes," << endl
                  << "et détruit ses exemplaires :" << endl;
        for (const auto& exemplaire : exemplaires) {
            delete exemplaire;
        }
    }

private:
    string nom;
    vector<Exemplaire*> exemplaires;
};


/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
