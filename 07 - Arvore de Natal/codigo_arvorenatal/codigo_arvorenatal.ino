/* Projeto sugerido e elaborado pelos alunos em sala de aula
 * Desenvolvedores: Weslley 
                    Edmar Fernandes
                    Felipe Vicente
                    Thayna Gimenes
                    Ricardo Corassa
 * Orientador: André Takeshi Endo
 *
 * Criado em Outubro de 2014
 * UTFPR-CP
 *
 * Simulador de árvore de natal. Ao pressionar o botão os LEDs piscam.
*/

int LED11 = 2;
int LED12 = 3;
int LED13 = 4;
int LED21 = 5;
int LED22 = 6;
int LED31 = 7;

int Liga = 8;

int EstadoBotao1 = 0; // essa função se limita a 0 = sem corrente e 1 = com corrente

void setup() {
  pinMode(LED11, OUTPUT); // pino com led será saída (OUTPUT)
  pinMode(LED12, OUTPUT); // pino com led será saída (OUTPUT)
  pinMode(LED13, OUTPUT); // pino com led será saída (OUTPUT)
  pinMode(LED21, OUTPUT); // pino com led será saída (OUTPUT)
  pinMode(LED22, OUTPUT); // pino com led será saída (OUTPUT)
  pinMode(LED31, OUTPUT); // pino com led será saída (OUTPUT)
  
  pinMode(Liga, INPUT); // pino com botão será entrada (INPUT)
}

void piscar()//Função que pisca os LEDs
{
  digitalWrite(LED11, LOW);
  digitalWrite(LED12, LOW);
  digitalWrite(LED13, LOW);
  digitalWrite(LED31, LOW);
  delay(1000); 
  digitalWrite(LED11, HIGH);
  digitalWrite(LED12, HIGH);
  digitalWrite(LED13, HIGH);
  digitalWrite(LED21, LOW);
  digitalWrite(LED22, LOW);
  digitalWrite(LED31, HIGH);
  delay(1000);
  digitalWrite(LED21, LOW);
  digitalWrite(LED22, LOW);
  delay(1000);   
  digitalWrite(LED21, HIGH);
  digitalWrite(LED22, HIGH);
}

int cont = 0;

void loop() {
  EstadoBotao1 = digitalRead(Liga); // esta função lê o que está acontecendo com o botão e atribui a uma variável

  if(EstadoBotao1 == HIGH){ // se o botão estiver pressionado será HIGH, caso contrário LOW
      digitalWrite(LED11, HIGH);
      digitalWrite(LED12, HIGH);
      digitalWrite(LED13, HIGH);
      digitalWrite(LED21, HIGH);
      digitalWrite(LED22, HIGH);
      digitalWrite(LED31, HIGH);
      piscar();
  }else{
      digitalWrite(LED11, LOW);
      digitalWrite(LED12, LOW);
      digitalWrite(LED13, LOW);
      digitalWrite(LED21, LOW);
      digitalWrite(LED22, LOW);
      digitalWrite(LED31, LOW);  
    }
}
