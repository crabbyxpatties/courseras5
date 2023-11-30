
// ecrire une programme qui compte le nombre es appuis sur un button 
int btn=1;
int pres=0;
int i=0;

void setup(){
Serial.begin(9600);
pinMode(btn,INPUT);

}

void loop(){
 int etat=digitalRead(btn);

if(etat==1 && pres==0 ){
 i++;
 Serial.print("le nombre d'appui sur le button btn :  ");
 Serial.println(i);


}    

pres=etat;

}