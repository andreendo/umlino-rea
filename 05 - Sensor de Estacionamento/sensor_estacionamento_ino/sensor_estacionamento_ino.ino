/*
 * Desenvolvedor:  Murylo Peliçaro Lopes
                   Luis Fernando Galonetti
 * Orientador: André Takeshi Endo
 * Criado em Dezembro de 2014
 * UTFPR-CP
 * Calculo da distância pelo Ultrassonico, e uso de LEDs e Buzzer para indentificar as distancias
*/

#include <Ultrasonic.h>//inclusão da biblioteca do sensor ultrassônico
 
#define echoPin 13 //Pino 13 recebe o pulso do echo
#define trigPin 12 //Pino 12 envia o pulso para gerar o echo
#define buzzerPin 11 //Pino 11 defino como o buzzer
#define minDistancia 10
#define LedVerm 9 //Definição dos pinos de LED
#define LedAmar 8
#define LedVerd 7
 
//iniciando a função e passando os pinos
Ultrasonic ultrasonic(12,13);
 
void setup(){
  
    Serial.begin(9600); //inicia a porta serial
    pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
    pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
    pinMode(buzzerPin, OUTPUT);// define o o pino 11 como saída (envia)
    pinMode(LedVerm, OUTPUT); // define os pinos do LED como saída (envia)
    pinMode(LedAmar, OUTPUT);
    pinMode(LedVerd, OUTPUT);
 }
 
void loop(){ // começo do laço de repetição
   
    digitalWrite(trigPin, LOW);//seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    delayMicroseconds(2); // delay de 2 microssegundos
    digitalWrite(trigPin, HIGH);//seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    delayMicroseconds(10);//delay de 10 microssegundos
    digitalWrite(trigPin, LOW);//seta o pino 12 com pulso baixo novamente
    int distancia = (ultrasonic.Ranging(CM));// função Ranging, faz a conversão do tempo de resposta do echo em centimetros, e armazena na variavel distancia
    Serial.print("Distancia em CM: ");
    Serial.println(distancia);
  
  // condições com o valor das distâncias para que realize as ações subsequentes
  if(distancia <= 5){ 
      tone(buzzerPin,1000); // define o tom do som do buzzer
      digitalWrite(LedVerm, HIGH); // Liga LED Vermelho
      delay(200); // menos espaço de tempo
      noTone(buzzerPin);
      digitalWrite(LedVerm, LOW); // apaga LED
      delay(200); // a sequencia de toques e de acendimento do LED será mais rápida
  }
  if(distancia > 5 && distancia <=10){
      tone(buzzerPin,1000);
      digitalWrite(LedAmar, HIGH);
      delay(400);
      noTone(buzzerPin);
      digitalWrite(LedAmar, LOW);
      delay(400);
  }
  if(distancia > 10 && distancia <=15){
      tone(buzzerPin,1000);
      digitalWrite(LedVerd, HIGH);
      delay(600);
      noTone(buzzerPin);
      digitalWrite(LedVerd, LOW);
      delay(600);
   }
 
}
 

