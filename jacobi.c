#include<stdio.h>
#include<math.h>
float fonksiyon(float*,int,float);
float turev(float,float*,int);
int main(){
  int der,i;
  float katsayi[20],bas,eps,fark,x[20];
  printf("-------Jacobi-------\n");
  printf(" Ana fonksiyonunuzun ayrilmis halinin derecesini giriniz.\n");
  scanf("%d",&der);
  for(i=0;i<=der;i++){
     printf("X in ussu %d olan terimin katsayisini giriniz\n",i);
     scanf("%f",&katsayi[i]);
  }
  printf("Baslangic degerini giriniz.\n");
  scanf("%f",&bas);
  printf("Epsilon degerini giriniz.\n");
  scanf("%f",&eps);
if (1>turev(bas,katsayi,der)) {
fark=5;
x[0]=bas;
i=1;
while (fark>eps) {
x[i]=fonksiyon(katsayi,der,bas);
bas=fonksiyon(katsayi,der,bas);
fark=x[i]-x[i-1];
fark=fabsf(fark);
i++;
}
printf("kokunuz yaklasik olarak %f\n",x[i-1] );
}
else{
  printf("Girdiginiz fonksiyon uygun degil\n");
}
}
float fonksiyon(float*katsayi,int der,float x0){
float fon[30];
float sonuc=1.0;
int i;
float toplam=0.0;
for(i=0;i<der;i++){
  sonuc=sonuc*x0;
}
fon[0]=sonuc;
for(i=1;i<=der;i++){
sonuc=(float)sonuc/x0;
fon[i]=sonuc;
}
for(i=0;i<=der;i++){
  toplam=(fon[i]*katsayi[der-i])+toplam;
}
return toplam;

}
float turev(float x,float*katsayi,int der){
float turev;
float  h=0.1;
turev=(fonksiyon(katsayi,der,x+h)-fonksiyon(katsayi,der,x-h))/(2*h);
return turev;


}
