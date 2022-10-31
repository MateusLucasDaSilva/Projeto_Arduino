#include<Servo.h>
Servo servo;
int chuva = 0;
int pinChuva = 4; //variavel do sensor de chuva
int pinServo = 7; //servo


int pinoledverm = 5; //Pino ligado ao led vermelho
int pin_LDR = A0; //sensor de luminosidade da sala
int pin_PIR = 8;  //Pino ligado ao sensor PIR
int acionamento_pir;  //Variavel para guardar valor do sensor
int luminosidade;


void setup() {
  servo.attach(pinServo); //Define pino servo
  servo.write(0); 
  pinMode(pinChuva, INPUT); //Define pino sensor de chuva como entrada

  pinMode(pinoledverm, OUTPUT); //Define pino como saida
  pinMode(pin_PIR, INPUT); //Define pino sensor de movimento como entrada
  pinMode(pin_LDR, INPUT); //Define pino sensor de luminosidade da sala como entrada
  Serial.begin(9600);

}

void loop() {
  janela();
  lampadaSala();
}

void janela(){
    chuva = digitalRead(pinChuva);
    Serial.print("CHUVA-> ");
    Serial.println(chuva);
  if(chuva == HIGH)
    servo.write(90);
  else
    servo.write(0);
}

void lampadaSala()
{
  acionamento_pir = digitalRead(pin_PIR); //Lê o valor do sensor PIR
  luminosidade = analogRead(pin_LDR);
  Serial.print("Presenca-> ");
  Serial.println(acionamento_pir);
  Serial.print("LED-> ");
  Serial.println(luminosidade); 
  
  if (acionamento_pir == 1 && luminosidade < 700) //Caso seja detectado um movimento e um certo nivel de luminosidade, aciona o led vermelho
  {
    Serial.print("LED-> Entrou aqui ");
    digitalWrite(pinoledverm, HIGH); //Liga led
    //delay(10);
  }
  else {
    
    digitalWrite(pinoledverm, LOW); //Desliga led  
      Serial.println("saiu ");

  } 
//  delay(1000);
}
