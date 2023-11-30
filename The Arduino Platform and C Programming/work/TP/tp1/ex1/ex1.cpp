// ecire une programme que allume une led 1000ms et eteinder et aperes refair le  cycle  :

// choisir une prote comme une output 
int led=5;

//initialize 5 prot   : 
void setup(){
pinMode(led, OUTPUT);


}

void loop(){
  digitalWrite(led , HIGH);
  delay(100);
  digitalWrite(led , LOW);
  delay(100);




}


