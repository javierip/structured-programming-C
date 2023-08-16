/* Program: Setup a Launchpad board and a LED matrix
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#define NCOL 6

int fila[6] = {P1_0, P1_1, P1_2, P1_3, P1_4, P1_5};
int col[6] = {P2_0, P2_1, P2_2, P2_3, P2_4, P2_5};

void setup()
{
  // initialize the digital pin as an output.

  pinMode(P1_0, OUTPUT);
  pinMode(P1_1, OUTPUT);
  pinMode(P1_2, OUTPUT);
  pinMode(P1_3, OUTPUT);
  pinMode(P1_4, OUTPUT);
  pinMode(P1_5, OUTPUT);
  pinMode(P2_0, OUTPUT);
  pinMode(P2_1, OUTPUT);
  pinMode(P2_2, OUTPUT);
  pinMode(P2_3, OUTPUT);
  pinMode(P2_4, OUTPUT);
  pinMode(P2_5, OUTPUT);

  int i;
  for (i = 0; i < 6; ++i)
  {
    digitalWrite(col[i], HIGH); // matrix off (leds)
    digitalWrite(fila[i], LOW); // matrix_operation off (leds)
  }
}

void loop()
{
  // led (0, 0) lo on 100 mSeg - off 10 mSeg
  matrix_operation(0, 0, 100, 10);
  delay(500);

  // led (1, 1) on 100 mSeg - off 10 mSeg
  matrix_operation(1, 1, 100, 10);
  delay(500);
}

void matrix_operation(int fm, int cm, int Ton, int Toff)
{

  digitalWrite(col[cm], LOW);
  digitalWrite(fila[fm], HIGH);

  delay(Ton);

  digitalWrite(col[cm], HIGH);
  digitalWrite(fila[fm], LOW);

  delay(Toff);
}
