//Sensor
const int ESQ = 7;
const int CENTRO = 6;
const int DIR = 5;

// Motor esquerdo
int esqf = 8;
int esqt = 9;

// Motor direito
int dirf = 10;
int dirt = 11;

void setup() {
  pinMode(esqf, OUTPUT);
  pinMode(esqt, OUTPUT);

  pinMode(dirf, OUTPUT);
  pinMode(dirt, OUTPUT); 

  pinMode(ESQ, INPUT);
  pinMode(CENTRO, INPUT);
  pinMode(DIR, INPUT); 

  Serial.begin(9600);
}

void frente() {
  digitalWrite(esqf, HIGH);
  digitalWrite(esqt, LOW);

  digitalWrite(dirf, HIGH);
  digitalWrite(dirt, LOW);
  delay(200);
}

void direita() {
  digitalWrite(esqf, HIGH);
  digitalWrite(esqt, LOW);

  digitalWrite(dirf, LOW);
  digitalWrite(dirt, HIGH);
  delay(200);
}

void esquerda() {
  digitalWrite(esqf, LOW);
  digitalWrite(esqt, HIGH);

  digitalWrite(dirf, HIGH);
  digitalWrite(dirt, LOW);
  delay(200);
}

void parar() {
  digitalWrite(esqf, LOW);
  digitalWrite(esqt, LOW);

  digitalWrite(dirf, LOW);
  digitalWrite(dirt, LOW);
  delay(200);  
}

void tras() {
  digitalWrite(esqf, LOW);
  digitalWrite(esqt, HIGH);

  digitalWrite(dirf, LOW);
  digitalWrite(dirt, HIGH);
  delay(200);
}

void loop() {
  //frente
  if(ESQ == LOW && CENTRO == HIGH && DIR == LOW){
    frente();
  }

  //esquerda
  else if(ESQ == HIGH && CENTRO == LOW && DIR == LOW){
     esqueda();
  }

  //direita
  else if(ESQ == LOW && CENTRO == LOW && DIR == HIGH){
    direita();
  }

  //parar
  else{
    parar();
  }
}
