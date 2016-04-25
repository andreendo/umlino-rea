/* Projeto sugerido e elaborado pelos alunos em sala de aula
 * Desenvolvedor:   Lucas De Oliveira Alves
                    Rafael Sian
                    Rayara Fragoso
                    Luis Renato Gazolla
 * Orientador: André Takeshi Endo
 * Criado em Junho de 2015
 * UTFPR-CP
 * Sistema que pisca uma sequência e o usuário deve pressionar os botões que correspondem a sequência de LEDs piscada.
*/

const int ledB = 4;
const int ledVerde = 5;
const int ledA = 6;
const int ledV = 7;

const int botaoV = 11;
const int botaoA = 10;
const int botaoVerde = 9;
const int botaoB = 8;

int estadoBtV = 0;
int estadoBtA = 0;
int estadoBtVerde = 0;
int estadoBtB = 0;

int seq[6] = {4, 5, 6, 7, 4, 7};
int i=0;

void setup()
{
  Serial.begin(9600);
  //Define os LEDs como saída
  pinMode (ledV, OUTPUT);
  pinMode (ledA, OUTPUT);
  pinMode (ledVerde, OUTPUT);
  pinMode (ledB, OUTPUT);

  //Define os botões como entrada
  pinMode (botaoV, INPUT);
  pinMode (botaoA, INPUT);
  pinMode (botaoVerde, INPUT);
  pinMode (botaoB, INPUT);  

  mostraSeq();
}

void loop() 
{
    //Verifica se o botão vermelho foi pressionado e se é o botão correto
    estadoBtV = digitalRead (botaoV);
    if (estadoBtV == HIGH)
    {
      Serial.println("VERMELHO)");
      if (seq[i] == ledV)
      {
        piscaLed(ledV);
        i++;
        delay(500);
      }
      else
      {
        errou();
        mostraSeq();
        i=0;
      }
    }

    //Verifica se o botão amarelo foi pressionado e se é o botão correto
    estadoBtA = digitalRead (botaoA);
    if (estadoBtA == HIGH)
    {
      if (seq[i] == ledA)
      {
        piscaLed(ledA);
        i++;
        delay(500);
      }
      else
      {
        errou();
        mostraSeq();
        i=0;
      }
    }

    //Verifica se o botão verde foi pressionado e se é o botão correto
    estadoBtVerde = digitalRead(botaoVerde);
    if (estadoBtVerde == HIGH)
    {
      if (seq[i] == ledVerde)
      {
        piscaLed(ledVerde);
        i++;
        delay(500);
      }
      else
      {
        errou();
        mostraSeq();
        i=0;
      }
    }

    //Verifica se o botão branco foi pressionado e se é o botão correto
    estadoBtB = digitalRead (botaoB);
    if (estadoBtB == HIGH)
    {
      if (seq[i] == ledB)
      {
        piscaLed(ledB);
        i++;
        delay(500);
      }
      else
      {
        errou();
        mostraSeq();
        i=0;
      }
    } 

  //Se acertou, acende todos os LEDs
  if (i==6)
  {
    digitalWrite(ledV, HIGH);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledB, HIGH);
  }
}

//Função que pisca um determinado LED
void piscaLed (int led)
{
  digitalWrite(led, HIGH);
  delay(500); 
  digitalWrite(led, LOW);  
}

//Pisca os LEDs na sequência definida pelo vetor seq
void mostraSeq()
{ 
  int j;
  for (j=0; j<6; j++)
  {
    piscaLed(seq[j]);
  } 
}

//Se o usuário errar a sequência, todos os LEDs piscam
void errou ()
{
 int j;
 for (j=0; j<3; j++)
  {
    digitalWrite(ledV, HIGH);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledB, HIGH);
    delay(500);
    digitalWrite(ledV, LOW);
    digitalWrite(ledA, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledB, LOW);
  }  
}
