

// ecrire un progammne qui allume une lamp on utilisant une button mais  garder l'etat precedent  :

int led=4;
int btn=1;
int  pres=LOW;
int change=LOW;

void setup(){
pinMode(led,OUTPUT);
pinMode(btn,INPUT);

Serial.begin(9600);

}
 
void loop(){

int etat=digitalRead(btn);


if(etat==1 && pres==0){


change=!change;


}
Serial.println(change);

digitalWrite(led,change);
pres=etat;


}
