/*
Tondeuse avec trois choix :

1- Elle réalise un carre
2- Elle réalise une etoile (rate a modifier !)
3- Elle réalise une spirale

Pour changer les choix bouton choix
Pour valider, bouton validation 

*/

// On initialise lel differents composant, bouton et led
const int led1 = 5;
const int led2 = 4;
const int led3 = 2;
const int validation = 7;
const int choix = 6;

// On initialise le choix en cour
int choixEnCour = 1;

/*
On initialise les differente constante lie aux moteurs
le decalage entre les deux moteurs  ->   + pour aller plus a droite - pour aller vers la gauche
la vitesse du robot en ligne droite
la vitesse du robot en tournant
*/
const int decalageAB = 3;
const int vitesseavanceA = 250;
const int vitesseavanceB = vitesseavanceA + decalageAB;
const int vitessetournerA = 75;
const int vitessetournerB = vitessetournerA + decalageAB;


// ****************fONCTION LIGNE DROITE ******************

void ligneDroite(int temps){
  // boucle for pour augmente progressivement la vitesse des moteurs et eviter les patinages
  for (int i = 0; i< vitesseavanceA; i = i +5){
    
    //moteur A avant vitesse i
    digitalWrite(12, LOW); // direction avant
    digitalWrite(9, LOW); //debloque le frein
    analogWrite(3, i); //vitesse maximum
    //moteur B avant vitesse i
    digitalWrite(13, LOW); // direction avant
    digitalWrite(8, LOW);  //debloque le frein
    analogWrite(11, i + decalageAB); //vitesse maximum
    delay(10);
  }
    
    delay(temps-2.5);
    digitalWrite(9, HIGH); //bloque le frein
    digitalWrite(8, HIGH);  //bloque le frein
}

// ****************fONCTION TOURNER A GAUCHE A 90 DEGRES*****************

void tournerGauche90() {
  digitalWrite(12, LOW); // direction avant
    digitalWrite(9, LOW); //debloque le frein
    analogWrite(3, vitessetournerA); //vitesse de virage
  
    digitalWrite(13, HIGH); // direction arriere
    digitalWrite(8, LOW); //debloque le frein
    analogWrite(11, vitessetournerB); //vitesse de virage
  
 
  delay(600);
  digitalWrite(9, HIGH); //bloque le frein
  digitalWrite(8, HIGH);  //bloque le frein
}


// ****************fONCTION CARRE ****************** 
void carre(){
  // On repete 4 fois l'operation
  for(int x = 1 ; x < 5 ; x++) {
  
  ligneDroite(1000);
  tournerGauche90();

  digitalWrite(9, HIGH); //bloque le frein
  digitalWrite(8, HIGH); //bloque le frein
  
  }
}
// ****************fONCTION TOURNER POUR ETOILE 1 ****************** 


void tournerGauche() {
  digitalWrite(12, LOW); // direction avant
    digitalWrite(9, LOW); //debloque le frein
    analogWrite(3, vitessetournerA); //vitesse  de virage
  
    digitalWrite(13, HIGH); // direction arriere
    digitalWrite(8, LOW); //debloque le frein
    analogWrite(11, vitessetournerB); //vitesse  de virage
  
 
  delay(300);
  digitalWrite(9, HIGH); //bloque le frein
  digitalWrite(8, HIGH);  //bloque le frein
}

// ****************fONCTION TOURNER POUR ETOILE 2 ******************

void tournerGauchee() {
    digitalWrite(12, HIGH); // direction arriere
    digitalWrite(9, LOW); //debloque le frein
    analogWrite(3, vitessetournerA); //vitesse  de virage
  
    digitalWrite(13, LOW); // direction avant
    digitalWrite(8, LOW); //debloque le frein
    analogWrite(11, vitessetournerB); //vitesse  de virage
  
 
  delay(900);
  digitalWrite(9, HIGH); //bloque le frein
  digitalWrite(8, HIGH);  //bloque le frein
}



// ****************fONCTION ETOILE ****************** 

void etoile() {
  // on repete 5 fois
 for(int y = 0 ; y < 5 ; y++) {
  ligneDroite(1000);
  tournerGauche();
  ligneDroite(1000);
  tournerGauchee();
 }   
}
  
  
// ****************fONCTION SPIRALE *******************
void spirale(){
    // On augmente progressivement la vitesse du moteur B
    for (int u =70; u < 100; u++) {
    //moteur A avant vitesse 100    
    digitalWrite(12, LOW); // direction avant
    digitalWrite(9, LOW); //debloque le frein
    analogWrite(3, 100); //vitesse 100
  
    //moteur B avant vitesse progressive
    digitalWrite(13, LOW); // direction avant
    digitalWrite(8, LOW);  //debloque le frein
    analogWrite(11, u);    // Vitesse en fonction de u
    delay(1500);
  }
    
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
}
 
  


// ****************  SETUP   ****************** 

void setup() {
  
//installer channel moteur A
  pinMode(12, OUTPUT); // initialisation du moteur A
  pinMode(9, OUTPUT); // initialisation du frein A

  //installer channel moteur B
  pinMode(13, OUTPUT); // initialitation du moteur B
  pinMode(8, OUTPUT);  // initialisation du frein B 
  
  //bouton et led
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(validation,INPUT);
  pinMode(choix,INPUT);
}

// ****************  LOOP   ****************** 

 void loop(){
   
  // On lit l'etat des boutons et on stock dans les variables
  int choixPresse = digitalRead (choix);
  int validationPresse = digitalRead (validation);  
  
  // Pour chaque choix une led s'allume
  if (choixEnCour == 1){
    digitalWrite (led1, HIGH);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);}
  else if (choixEnCour == 2){
    digitalWrite (led1, LOW);
    digitalWrite (led2, HIGH);
    digitalWrite (led3, LOW);}
  else{
    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, HIGH);}
    
  // On fait tourner le choix en cour
  if (choixPresse == HIGH ){
    if (choixEnCour == 3){
      choixEnCour = 1;}
    else{
      choixEnCour = choixEnCour +1;}
   delay(500);
  }
  
  // Suivant le choix en cour executer une forme
  if(validationPresse == HIGH && choixEnCour == 1){
    delay(1000);
    carre();}
  if(validationPresse==HIGH && choixEnCour == 2){
    delay(1000);
    etoile();}
  if(validationPresse==HIGH && choixEnCour == 3){
    delay(1000);
   spirale();}
 }
   
