#include <stdio.h>
#include <stdlib.h>

struct eleman
{
    int veri;
    struct eleman *sonraki;
};
typedef struct eleman e;

e *bas = NULL;
e *son = NULL;
e *aktif = NULL;

int basa_eleman_ekle(int veri_ekle)
{
    e *yeni = malloc(sizeof(e));
    yeni->veri = veri_ekle;
    if (bas == NULL)
        son = yeni;
    yeni->sonraki = bas;
    bas = yeni;
}

void yazdir()
{
    printf("\nbagli listenin elemanlari\n");
    aktif = bas;
    while (aktif != NULL)
    {
        printf("%d -> ", aktif->veri);
        aktif = aktif->sonraki;
    }
}

int ara(int aranan)
{
    aktif = bas;
    int sayac=1;
    while (aktif != NULL)
    {
        if (aranan == aktif->veri)
            return printf("\naranan deger %d. sirada bulundu",sayac);
        aktif = aktif->sonraki;
        sayac++;
    }
    return printf("\ndeger bulunamadi");
}

int araya_eleman_ekle(int veri_ekle, int sira)
{
    e *yeni = malloc(sizeof(e));
    yeni->veri = veri_ekle;

    aktif=bas;
    int i;
    for(i=1;i<sira;i++)
    {
        aktif = aktif->sonraki;
    }
    yeni->sonraki=aktif->sonraki;
    aktif->sonraki=yeni;

}

int ilk_elemani_sil()
{
    aktif = bas;
    bas = bas->sonraki;
    free(aktif); // ilk elemanÄ±n bellekte kapladÄ±ÄŸÄ± yeri serbest bÄ±rak
}

int son_elemani_sil()
{
    aktif = bas;
    //son elemanÄ± silebilmek iÃ§in sondan Ã¶nceki elemanÄ± bulmak gerekir
    while (aktif->sonraki->sonraki != NULL)
        aktif = aktif->sonraki;
    free(aktif->sonraki);
    aktif->sonraki = NULL;
}

int main()
{
    basa_eleman_ekle(23);
    basa_eleman_ekle(20);
    int i;
    for (i = 1; i <= 10; i++)
        basa_eleman_ekle(i);
    yazdir();

    ara(9);

    araya_eleman_ekle(15,2);
    araya_eleman_ekle(44,5);
    yazdir();

    ilk_elemani_sil();
    yazdir();

    son_elemani_sil();
    yazdir();

    return 0;
}