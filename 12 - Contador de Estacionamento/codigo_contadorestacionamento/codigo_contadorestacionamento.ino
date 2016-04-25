/* Projeto sugerido e elaborado pelos alunos em sala de aula
 * Desenvolvedor:   Carolina Lourenço dos Santos
                    Guilherme Ricken Mattiello
                    Maykon Plain
                    Felippe Eiji
                    Regis Rufino Rodrigues
 * Orientador: André Takeshi Endo
 * Criado em Junho de 2015
 * UTFPR-CP
 * Sistema que simula um controlador de vagas de estacionamento, acendendo diferentes LEDs conforme for enchendo o estacionamento
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
int quantidade;
void setup(){
  
    Serial.begin(9600); //inicia a porta serial
    pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
    pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
    pinMode(LedVerm, OUTPUT); // define os pinos do LED como saída (envia)
    pinMode(LedAmar, OUTPUT);
    pinMode(LedVerd, OUTPUT);
    pinMode(buzzerPin, OUTPUT);// define o o pino 11 como saída (envia)
    quantidade = 0;
 }
 
void loop(){
    delay(1000);
    digitalWrite(trigPin, LOW);//seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    delayMicroseconds(2); // delay de 2 microssegundos
    digitalWrite(trigPin, HIGH);//seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    delayMicroseconds(10);//delay de 10 microssegundos
    digitalWrite(trigPin, LOW);//seta o pino 12 com pulso baixo novamente
    int distancia = (ultrasonic.Ranging(CM));// função Ranging, faz a conversão do tempo de resposta do echo em centimetros, e armazena na variavel distancia
    Serial.print("Distancia em CM: ");
    Serial.println(distancia);

    if(distancia <= 6){ //Algum objeto passou na frente do sensor
        quantidade = quantidade + 1; //Passou mais um carro
    }
    if (quantidade == 1){      
      digitalWrite(LedVerd, HIGH); // Liga LED Verde
      digitalWrite(LedVerm, LOW); // Apaga LED Vermelho
      digitalWrite(LedAmar, LOW); // Apaga LED Amarelo
    }
    if (quantidade == 3){
      digitalWrite(LedAmar, HIGH); // Liga LED Amarelo      
      digitalWrite(LedVerd, LOW); // Apaga LED Verde
      digitalWrite(LedVerm, LOW); // Apaga LED Vermelho
    }
    if (quantidade == 5){      
      digitalWrite(LedVerm, HIGH); // Liga LED Vermelho
      digitalWrite(LedVerd, LOW); // Apaga LED Verde
      digitalWrite(LedAmar, LOW); // Apaga LED Amarelo
      tone(buzzerPin,100); //Ativa o buzzer
      delay(2000);//Tempo do buzzer ativo
      noTone(buzzerPin); //Desativa o buzzer
      quantidade = quantidade+1; //Soma para não ativar mais o buzzer
    }
}
