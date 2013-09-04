/* I, Raphael Champeimont, the author of this program,
 * hereby release it into the public domain.
 * This applies worldwide.
 * 
 * In case this is not legally possible:
 * I grant anyone the right to use this work for any purpose,
 * without any conditions, unless such conditions are required by law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <stdio.h>
#include <stdlib.h>

int temps, h, m ,s, temps2;

void HMSversTemps() {
  temps2 = 3600*h + 60*m + s;
}

void tempsVersHMS() {
  int r;
  h = temps/3600;
  r = temps%3600;
  m = r/60;
  s = r%60;
}

int main()
{
  printf("Entrez un temps en secondes : ");
  scanf("%d", &temps);
  tempsVersHMS();
  printf("%dh %dmin %dsec", h, m, s);
  HMSversTemps();
  printf(" = %d\n", temps2);
  
  return 0;
}
