#include<stdio.h>
#include<math.h>

int main(){
int i,n;
float xt=0,yt=0,xk=0,xy=0,xkup=0,x4=0,xky=0;
float x[30],y[30],det=0,adet=0,bdet=0,cdet=0,a,b,c;
printf("-------Polinom  Regresyon-------\n");
printf("Kac deger ile regresyon islemi yapacaginizi giriniz.\n");
scanf("%d",&n );
for (i=0;i<n;i++) {
  printf("%d. x degerini giriniz.\n",i+1);
  scanf("%f",&x[i]);
  printf("%d. y degerini giriniz.\n",i+1);
  scanf("%f",&y[i]);
}
for (i=0;i<n;i++) {
  xt=xt+x[i];
  yt=yt+y[i];
  xk=xk+(x[i]*x[i]);
  xy=xy+(y[i]*x[i]);
  xkup=xkup+pow(x[i],3);
  x4=x4+pow(x[i],4);
  xky=xky+(x[i]*x[i]*y[i]);
}
float matris1[3][3]={{n,xt,xk},{xt,xk,xkup},{xk,xkup,x4}};
for(i=0;i<3;i++){
  det=det+(matris1[0][i]*(matris1[1][(i+1)%3]*matris1[2][(i+2)%3]-matris1[1][(i+2)%3]*matris1[2][(i+1)%3]));
}
float matris2[3][3]={{yt,xt,xk},{xy,xk,xkup},{xky,xkup,x4}};
for(i=0;i<3;i++){
  adet=adet+(matris2[0][i]*(matris2[1][(i+1)%3]*matris2[2][(i+2)%3]-matris2[1][(i+2)%3]*matris2[2][(i+1)%3]));
}
float matris3[3][3]={{n,yt,xk},{xt,xy,xkup},{xk,xky,x4}};
for(i=0;i<3;i++){
  bdet=bdet+(matris3[0][i]*(matris3[1][(i+1)%3]*matris3[2][(i+2)%3]-matris3[1][(i+2)%3]*matris3[2][(i+1)%3]));
}
float matris4[3][3]={{n,xt,yt},{xt,xk,xy},{xk,xkup,xky}};
for(i=0;i<3;i++){
  cdet=cdet+(matris4[0][i]*(matris4[1][(i+1)%3]*matris4[2][(i+2)%3]-matris4[1][(i+2)%3]*matris4[2][(i+1)%3]));
}

a=adet/det;
b=bdet/det;
c=cdet/det;

printf(" Denkleminiz : y=%fx^2+%fx+%f\n",c,b,a );


}
