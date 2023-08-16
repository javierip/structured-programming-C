/* Program: Setup a Launchpad board
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

void setup()
{
  pinMode(RED_LED, OUTPUT);
}

void loop()
{
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  delay(1000);
}
