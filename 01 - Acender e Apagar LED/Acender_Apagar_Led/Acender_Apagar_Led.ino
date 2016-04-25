/*
 * Desenvolvedor: Murylo Peliçaro Lopes
 * Orientador: André Takeshi Endo
 * Criado em Novembro de 2014
 * UTFPR-CP
 * Controle do acendimento do LED por meio do pushbutton
*/


int led = 10; // declaração das variáveis e da porta aonde se encontram
int BotaoDesliga = 8;
int BotaoLiga = 9;

int EstadoBotao1 = 0; // essa função se limita a 0 = sem corrente e 1 = com corrente
int EstadoBotao2 = 0;

void setup(){ //inicialização
pinMode(led, OUTPUT); // pino com led será saída (OUTPUT)
pinMode(BotaoDesliga, INPUT); // pino com botão será entrada (INPUT)
pinMode(BotaoLiga, INPUT);
}

void loop(){ // laço de repetição
EstadoBotao1 = digitalRead(BotaoDesliga); // esta função lê o que está acontecendo com o botão e atribui a uma variável
EstadoBotao2 = digitalRead(BotaoLiga);

// HIGH = com corrente = aceso   = 1
// LOW  = sem corrente = apagado = 0

if (EstadoBotao1 == HIGH){ // se o botão estiver pressionado será HIGH, caso contrário LOW
    digitalWrite(led, HIGH); // usa-se essa função para enviar o comando. HIGH = aceso
  } 
    
if (EstadoBotao2 == HIGH){ 
    digitalWrite(led, LOW);// LOW = apagado
  } 

}

