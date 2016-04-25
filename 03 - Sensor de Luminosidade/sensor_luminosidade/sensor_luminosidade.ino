/*
 *
 * Desenvolvedor: Luis Fernando Galonetti
 * Orientador: André Takeshi Endo
 *
 * Criado em Novembro de 2014
 * UTFPR-CP
 *
 * Controle do acendimento do LED por meio do sensor de luminosidade LDR (iluminação automatizada).
*/
const int LDR = 0; // declaração de variáveis
const int Led = 6; 
int ValorLido = 0; 
int ValorInicial = 0;
int pwm = 0;

void setup() { 
  pinMode(Led, OUTPUT); 
  ValorInicial = analogRead(LDR); 
}

void loop() { 
  ValorLido = analogRead(LDR); // verifica o valor lido no sensor de luminosidade

  if (ValorLido < (ValorInicial - ValorInicial/2)){ // valor de referência para pequena sombra sobre o sensor
    analogWrite(Led, pwm); 
    pwm++; 
    delay(100);
  } 
  else{ 
    digitalWrite(Led, LOW); 
    pwm = 0; 
  }   
  if(pwm > 255){ //garante que o valor do pwn não ultrapasse 255
    pwm=255; 
  } 
}
/*

//Inicialmente utiliza-se este código para calibrar o sensor de
//luminosidade, geralmente o valor é em torno de 600. Quanto mais
//luz, o sensor recebe, maior será o valor lido.

  
const int LDR = 0; 
int ValorLido = 0; 

void setup() { 
  Serial.begin(9600); 
} 

void loop() { 
  ValorLido = analogRead(LDR); 
  Serial.print("Valor lido pelo LDR = "); 
  Serial.println(ValorLido); 
  delay(500); 
}

*/
