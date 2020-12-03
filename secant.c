 #include<stdio.h>
 #include<math.h>
 float fonksiyon(float*,int,float);

 int main(){
   int der,i;
   float katsayi[30],bas,son,eps,orta,ortadeger[30],fark;
   printf("Fonksiyonunuzun derecesini giriniz.\n");
   scanf("%d",&der);
   for(i=0;i<=der;i++){
      printf("X in ussu %d olan terimin katsayisini giriniz\n",i);
      scanf("%f",&katsayi[i]);
   }
   printf("Baslangic degerini giriniz.\n");
   scanf("%f",&bas);
   printf("Bitis degerini giriniz.\n");
   scanf("%f",&son );
   printf("Epsilon degerini giriniz.\n");
   scanf("%f",&eps);
   if (fonksiyon(katsayi,der,bas)*fonksiyon(katsayi,der,son)==0) {
     if(fonksiyon(katsayi,der,bas)==0){
      printf("Kokunuz:%f\n",bas);
     }
     else{
       printf("Kokunuz:%f\n",son );
     }
   }
   else{
     if(fonksiyon(katsayi,der,bas)*fonksiyon(katsayi,der,son)>0){
     printf("Belirlrdiginiz aralikta kok yok\n" );
     }
     else{
      orta=bas+((son-bas)/(fonksiyon(katsayi,der,son)-fonksiyon(katsayi,der,bas)));
      ortadeger[0]=orta;
      fark=5;
      i=1;
       while (fark>eps) {
         if(fonksiyon(katsayi,der,bas)*fonksiyon(katsayi,der,orta)<0){
           son=orta;
         }
         else{
           if(fonksiyon(katsayi,der,orta)*fonksiyon(katsayi,der,son)<0){
             bas=orta;
           }
         }

   orta=bas+((son-bas)/(fonksiyon(katsayi,der,son)-fonksiyon(katsayi,der,bas)));
   ortadeger[i]=orta;
   fark=ortadeger[i]-ortadeger[i-1];
   fark=fabsf(fark);
   i++;

       }

       printf("Kokunuz yaklasik olarak: %f\n",orta);

     }
   }

 }
 float fonksiyon(float*katsayi,int der,float x0){
 float fon[30];
 float sonuc=1.0;
 int i;
 float toplam=0.0;
 if (x0==0) {
  toplam=katsayi[0];
}
else{

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
}
 return toplam;

 }
