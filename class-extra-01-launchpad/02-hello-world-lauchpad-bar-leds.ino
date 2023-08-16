/* Program: Setup a Launchpad board and a LED bar
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

int array_LEDs[9] = {P1_0, P1_1, P1_2, P1_3, P1_4, P1_5, P2_0, P2_1, P2_2};

void setup()
{
  int i;
  // all leds pis as output
  for (i = 0; i < 9; ++i)
  {
    pinMode(array_LEDs[i], OUTPUT);
  }
  // turn off leds
  for (i = 0; i < 9; ++i)
  {
    digitalWrite(array_LEDs[i], HIGH);
  }
}

void loop()
{
  // complete
}
