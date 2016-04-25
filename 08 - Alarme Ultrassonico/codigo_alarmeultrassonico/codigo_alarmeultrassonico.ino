/* Projeto sugerido e elaborado pelos alunos em sala de aula
 * Desenvolvedores: Bruno Anken
                    Bruno de Paulo Giroto
                    Felipe Minatel
                    Luiz Eduardo Feraz Luz
                    Matheus Anatriello
 * Orientador: André Takeshi Endo
 * Criado em Outubro de 2015
 * UTFPR-CP
 * Calculo da distância pelo sensor Ultrassonico, e uso de LEDs e Buzzer para simular um alarme
*/


#include <Ultrasonic.h>//inclusão da biblioteca do sensor ultrassônico

#define pino_trigger 5 //Pino 5 envia o pulso para gerar o echo
#define pino_echo 4 //Pino 4 recebe o pulso do echo

Ultrasonic ultrasonic(pino_trigger, pino_echo);

int pinobuzzer = 3; //Pino 3 definido como o buzzer
int pinoledVerde = 6; //Pino 6 definido como o led verde
int pinoledVermelho = 7; //Pino 7 definido como o led vermelho
int botao = 8; //Pino 8 definido como o botao

int estadoBotao = 0; //Variável que controla o estado no botão
int var = 0;
int var2 = 0;


void setup()
{
    pinMode(pinobuzzer, OUTPUT); //Define os LEDs como saída
    pinMode(pinoledVermelho, OUTPUT);
    pinMode(pinoledVerde, OUTPUT);
    pinMode(botao, INPUT); //Define o botão como entrada
    Serial.begin(9600); //Inicia a porta serial
    var2 = 0; //Variáveis para controle do estado do botão
    var = 0;
}

void loop()
{
    float cmMsec, inMsec;
    long microsec = ultrasonic.timing();
    cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); //Faz a leitura do sensor ultrassônico
    var = digitalRead(botao); //Faz a leitura do botão
    Serial.println(cmMsec);
    Serial.println(estadoBotao);
    if ((var == HIGH) && (var2 == LOW))
    {
        estadoBotao = 1 - estadoBotao;
        delay(20);
    }
    var2 = var;


    if(estadoBotao== 1)
    {

        digitalWrite(pinoledVerde, HIGH);

        if (cmMsec<8.0) //Se a distância for menor que 8.0
        {
            tone(pinobuzzer,700); //Liga o buzzer
            digitalWrite(pinoledVermelho, HIGH); //Acende led vermelho
            delay(50);

        }
        if (cmMsec>8.0) //Se a distância for maior que 8.0
        {
            noTone(pinobuzzer); //Desliga o buzzer
            digitalWrite(pinoledVermelho, LOW); //Apaga led vermelho
            delay(50);

        }
    }
    else
    {
        digitalWrite(pinoledVerde, LOW); //Apaga led verde
    }
    delay(100);
}
