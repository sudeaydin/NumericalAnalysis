#include<stdio.h>
int main(){
int i,n;
float xt=0,yt=0,xk=0,xy=0;
float x[30],y[30],delta,adelta,bdelta,a,b;
printf("-------Dogrusal Regresyon-------\n");
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
}
delta=(n*xk)-(xt*xt);
adelta=(yt*xk)-(xt*xy);
bdelta=(n*xy)-(xt*yt);
a=adelta/delta;
b=bdelta/delta;
printf(" Denkleminiz : y=%f+%fx\n",a,b );


}
