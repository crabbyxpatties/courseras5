
// ecrire un progammne qui allume une lamp on utilisant une button :

int led=4;
int btn=1;


void setup(){
pinMode(led,OUTPUT);
pinMode(btn,INPUT);



}
 
void loop(){

int a0=digitalRead(btn);
digitalWrite(led,a0);







}