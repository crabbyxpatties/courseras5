#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  double poids; 
  string couleur; 
  unsigned int age;
  unsigned int esperance_vie; 
  bool clonee; 

  public : 

  Souris(double poids , string couleur , unsigned int age=0 , unsigned int esperance_vie=36){
    this->poids=poids;
    this->couleur=couleur;
    this->age=age;
    this->esperance_vie=esperance_vie;
    this->clonee=false; 
    cout<<"Une nouvelle souris ! \n";  

  }
  Souris(Souris &copy){
      this->poids=copy.poids;
    this->couleur=copy.couleur;
    this->age=copy.age;
    this->esperance_vie=copy.esperance_vie *4/5;
    this->clonee=true; 
    cout<<"Clonage d’une souris ! \n"; 
   
  }

  ~Souris(){
   cout<<"Fin d'une souris... \n"; 
  }

 void  afficher(){
  if(clonee)
 cout<<"Une souris "<<couleur<<", clonee, de "<<age<<" mois et pesant "<<poids<<" grammes\n";
else{
  cout<<"Une souris "<<couleur<<" de "<<age<<" mois et pesant "<<poids<<" grammes\n";
}
  }

  void vieillir(){
  
    
   if(clonee && age  > esperance_vie/2)
   couleur="verte"; 
    
    age++; 

  }
  void evolue(){
    while(age<esperance_vie){
vieillir(); 
    }
  
}
  

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
