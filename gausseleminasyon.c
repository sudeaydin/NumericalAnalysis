#include<stdio.h>
int main() {
int i,m,n,j;
float matris[30][30],sonuc[30][30],bilinmeyen[30],temp;
float toplam=0;
printf("Kac tane denklem oldugunu giriniz.\n");
scanf("%d",&m);
printf("Kac tane bilinmeyen oldugunu giriniz.\n");
scanf("%d",&n);

 for (i=0;i<m;i++) {
  for (j=0;j<n;j++) {
    printf("%d. denklemin %d. bilinmeyeninin katsayisini giriniz.\n",i+1,j+1);
    scanf("%f",&matris[i][j]);
  }
}
for (i=0;i<m;i++) {
  for (j=0;j<1;j++) {
    printf("%d. denklemin sonucunu giriniz.\n",i+1);
    scanf("%f",&sonuc[i][j] );
  }
}

sonuc[0][0]=sonuc[0][0]/matris[0][0];
 for (i=n-1;i>-1;i--) {
   matris[0][i]=matris[0][i]/matris[0][0];
 }


temp=matris[1][0];
sonuc[1][0]=sonuc[1][0]/temp;
for (i=n-1;i>-1;i--) {
  matris[1][i]=matris[1][i]/matris[1][0];
}
sonuc[1][0]=sonuc[1][0]-sonuc[0][0];
for (i=0;i<n;i++) {
  matris[1][i]=matris[1][i]-matris[0][i];
}
sonuc[1][0]=sonuc[1][0]*temp;
for (i=n-1;i>-1;i--) {
  matris[1][i]=matris[1][i]*temp;
}


temp=matris[2][0];
sonuc[2][0]=sonuc[2][0]/temp;
for (i=n-1;i>-1;i--) {
  matris[2][i]=matris[2][i]/matris[2][0];
}
sonuc[2][0]=sonuc[2][0]-sonuc[0][0];
for (i=0;i<n;i++) {
  matris[2][i]=matris[2][i]-matris[0][i];
}
sonuc[2][0]=sonuc[2][0]*temp;
for (i=n-1;i>-1;i--) {
  matris[2][i]=matris[2][i]*temp;
}


temp=matris[1][1];
sonuc[1][0]=sonuc[1][0]/temp;
for (i=0;i<n;i++) {
  matris[1][i]=matris[1][i]/temp;
}


temp=matris[2][1];
sonuc[2][0]=sonuc[2][0]/temp;
for (i=0;i<n;i++) {
  matris[2][i]=matris[2][i]/temp;
}
sonuc[2][0]=sonuc[2][0]-sonuc[1][0];
for (i=0;i<n;i++) {
  matris[2][i]=matris[2][i]-matris[1][i];
}
sonuc[2][0]=sonuc[2][0]*temp;
for (i=n-1;i>-1;i--) {
  matris[2][i]=matris[2][i]*temp;
}


sonuc[2][0]=sonuc[2][0]/matris[2][2];
for (i=0;i<n;i++) {
  matris[2][i]=matris[2][i]/matris[2][2];
}

bilinmeyen[n-1]=sonuc[n-1][0];
for (i=n-2;i>-1;i--) {
  for (j=i+1;j<n;j++) {
    toplam=toplam+matris[i][j]*bilinmeyen[j];
  }
  bilinmeyen[i]=sonuc[i][0]-toplam;
  toplam=0;
}
for (i=0;i<n-1;i++) {
    printf(" %d.bilinmeyen:%f\n",i+1,bilinmeyen[i]);
}

printf(" %d. bilinmeyen:%f\n",n,sonuc[n-1][0]);




  return 0;
}
