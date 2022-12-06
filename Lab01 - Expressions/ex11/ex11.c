#include <stdio.h>
#include <math.h>

int main(){

  float zr, zi, wr, wi, modz, modw;

  printf("<<Numero imaginario>>\n");
  printf("Informe a a parte real de z: ");
  scanf("%f", &zr);
  printf("Informe a a parte imaginaria de z: ");
  scanf("%f", &zi);
  printf("Informe a a parte real de w: ");
  scanf("%f", &wr);
  printf("Informe a a parte imaginaria de w: ");
  scanf("%f", &wi);
  
  modz = sqrt(zr*zr + zi*zi);
  modw = sqrt(wr*wr + wi*wi);

  printf("z + w = %.1f + %.1fi\n", zr+wr, zi+wi);
  printf("z - w = %.1f + %.1fi\n", zr-wr, zi-wi);
  printf("z * w = %.1f + %.1fi\n", (zr*wr - zi*wi), (zr*wi + zi*wr));
  printf("|z| = %.4f\n", modz);
  printf("|w| = %.4f\n", modw);

  return 0;
  
}
