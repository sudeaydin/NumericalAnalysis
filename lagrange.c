#include<stdio.h>
int main(){
int n,i,j;
float x[30],y[30],Lx[30],x0,sonuc=0;
printf("-------LaGrange Enterpolasyonu------\n");
printf(" Data sayisini giriniz.-n+1 degeri-\n");
scanf("%d",&n );
for (i=0;i<n;i++) {
 printf(" %d. x  degerini giriniz.\n",i+1);
 scanf("%f",&x[i]);
 printf(" %d. y  degerini giriniz.\n",i+1);
 scanf("%f",&y[i]);
}
for (i=0;i<n;i++) {
  Lx[i]=1;
}
printf("Enterpolasyon dogrultusunda bulmak istediginiz degeri giriniz.\n" );
scanf("%f",&x0 );

for (i=0;i<n;i++) {
  for (j=0;j<n;j++) {
    if (i!=j) {
      Lx[i]=Lx[i]*((x0-x[j])/(x[i]-x[j]));
    }
  }
  Lx[i]=Lx[i]*y[i];

}
for (i=0;i<n;i++) {
  sonuc=sonuc+Lx[i];
}
printf("Sonucunuz : %.3f\n",sonuc);

}
