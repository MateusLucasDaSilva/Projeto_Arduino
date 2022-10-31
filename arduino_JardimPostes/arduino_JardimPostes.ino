int pin_LDR2 = A3; //sensor de luminosidade do poste
int luminosidade_externa;
int LED_externo1 = 8;
int LED_externo2 = 9;

int solo = 0;
int pinSolo = A1; //Variavel do sensor do solo

int pinRele = 13;

void setup() {
  pinMode(pin_LDR2, INPUT); //Define pino sensor de luminosidade do poste como entrada
  pinMode(LED_externo1, OUTPUT); //define led externo1 como saida
  pinMode(LED_externo2, OUTPUT); //define led externo2 como saida
  Serial.begin(9600);
  pinMode(pinSolo, INPUT); //Define pino sensor do solo como entrada
  pinMode(pinRele, OUTPUT); //Define pino rele como saída
}

void loop() {
lampadaPoste();
jardim();
}

void lampadaPoste(){
  luminosidade_externa = analogRead(pin_LDR2);

  if (luminosidade_externa > 1000){
    Serial.print("LED_exerteno -> Entrou aqui ");
    digitalWrite(LED_externo1, HIGH); //Liga led
    digitalWrite(LED_externo2, HIGH); //Liga led
  }
  else {
    digitalWrite(LED_externo1, LOW); //Desliga led
    digitalWrite(LED_externo2, LOW); //Desliga led
  }
}

void jardim(){
  solo = map(analogRead(pinSolo), 0, 1023, 0, 100);
  Serial.println(solo);
  if(solo > 50){
    Serial.println("Solo ");
    digitalWrite(pinRele, HIGH);  
  } else {
    digitalWrite(pinRele, LOW);  
  }
}
