#include <allegro.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>


#define MOUSE_L		0x01
#define MOUSE_L_NEW	0x02
#define MOUSE_LS	(MOUSE_L | MOUSE_L_NEW)


	//en fazla 2 kartın açılması için
	int sayac=0;

	//seçilecek kartların tanıtımı 0 boş, gerisi sıralı
	BITMAP *kart[11];

	//fare hareketlerini tutan
	int cursorX=20, cursorY=20;

	//gösterilecek kartlar dağılacak
	int kartDestesi[4][5];

	int hamle=0;
	
	//kartların açık/kapalı durumları için. başta hepsi 0, tıklanan=1
	int kartDurumlari[4][5];

	//açılan kartları hafızada tut
	int acilanKartlar[2];

	//kartların açılacağı x y koordinatları
	int gosterX=0, gosterY=0;

	/*
	Kartların Koordinatları (göründüğü sırayla)

	10,10		130,10		250,10		370,10		490,10
	10,170		130,170		250,170		370,170		490,170
	10,330		130,330		250,330		370,330		490,330
	10,490		130,490		250,490		370,490		490,490

	*/

void durumlariSifirla()
{
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<5;j++)
			kartDurumlari[i][j]=0;
}

void aciklariKapat()
{
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<5;j++)
			if(kartDurumlari[i][j]!=-1) kartDurumlari[i][j]=0;
}

void kartEslestiMi()
{
	int i,j;
	if(acilanKartlar[0]==acilanKartlar[1])
	{
		for(i=0;i<6;i++)
			for(j=0;j<5;j++)
				if(kartDestesi[i][j]==acilanKartlar[0]&&kartDestesi[i][j]==acilanKartlar[1]) kartDurumlari[i][j]=-1;
	}
}



int tiklananiAc(int koorX, int koorY)
{
	if(sayac==2){
					kartEslestiMi();
					aciklariKapat();
					sayac=0;
				}

	if(koorX>10&&koorX<120&&koorY>10&&koorY<160)	//1.1
	{
		if(kartDurumlari[0][0]==1||kartDurumlari[0][0]==-1) return 0;
		gosterX=10;
		gosterY=10;
		kartDurumlari[0][0]=1;
		acilanKartlar[sayac]=kartDestesi[0][0];
		sayac++;
		hamle++;
	}
	else if(koorX>130&&koorX<240&&koorY>10&&koorY<160)	//1.2
	{
		if(kartDurumlari[0][1]==1||kartDurumlari[0][1]==-1) return 0;
		gosterX=130;
		gosterY=10;
		kartDurumlari[0][1]=1;
		acilanKartlar[sayac]=kartDestesi[0][1];
		sayac++;
		hamle++;
	}
	else if(koorX>250&&koorX<360&&koorY>10&&koorY<160)	//1.3
	{
		if(kartDurumlari[0][2]==1||kartDurumlari[0][2]==-1) return 0;
		gosterX=250;
		gosterY=10;
		kartDurumlari[0][2]=1;
		acilanKartlar[sayac]=kartDestesi[0][2];
		sayac++;
		hamle++;
	}
	else if(koorX>370&&koorX<480&&koorY>10&&koorY<160)	//1.4
	{
		if(kartDurumlari[0][3]==1||kartDurumlari[0][3]==-1) return 0;
		gosterX=370;
		gosterY=10;
		kartDurumlari[0][3]=1;
		acilanKartlar[sayac]=kartDestesi[0][3];
		sayac++;
		hamle++;
	}
	else if(koorX>490&&koorX<600&&koorY>10&&koorY<160)	//1.5
	{
		if(kartDurumlari[0][4]==1||kartDurumlari[0][4]==-1) return 0;
		gosterX=490;
		gosterY=10;
		kartDurumlari[0][4]=1;
		acilanKartlar[sayac]=kartDestesi[0][4];
		sayac++;
		hamle++;
	}

	else if(koorX>10&&koorX<120&&koorY>170&&koorY<320)	//2.1
	{
		if(kartDurumlari[1][0]==1||kartDurumlari[1][0]==-1) return 0;
		gosterX=10;
		gosterY=170;
		kartDurumlari[1][0]=1;
		acilanKartlar[sayac]=kartDestesi[1][0];
		sayac++;
		hamle++;
	}
	else if(koorX>130&&koorX<240&&koorY>170&&koorY<320)	//2.2
	{
		if(kartDurumlari[1][1]==1||kartDurumlari[1][1]==-1) return 0;
		gosterX=130;
		gosterY=170;
		kartDurumlari[1][1]=1;
		acilanKartlar[sayac]=kartDestesi[1][1];
		sayac++;
		hamle++;
	}
	else if(koorX>250&&koorX<360&&koorY>170&&koorY<320)	//2.3
	{
		if(kartDurumlari[1][2]==1||kartDurumlari[1][2]==-1) return 0;
		gosterX=250;
		gosterY=170;
		kartDurumlari[1][2]=1;
		acilanKartlar[sayac]=kartDestesi[1][2];
		sayac++;
		hamle++;
	}
	else if(koorX>370&&koorX<480&&koorY>170&&koorY<320)	//2.4
	{
		if(kartDurumlari[1][3]==1||kartDurumlari[1][3]==-1) return 0;
		gosterX=370;
		gosterY=170;
		kartDurumlari[1][3]=1;
		acilanKartlar[sayac]=kartDestesi[1][3];
		sayac++;
		hamle++;
	}
	else if(koorX>490&&koorX<600&&koorY>170&&koorY<320)	//2.5
	{
		if(kartDurumlari[1][4]==1||kartDurumlari[1][4]==-1) return 0;
		gosterX=490;
		gosterY=170;
		kartDurumlari[1][4]=1;
		acilanKartlar[sayac]=kartDestesi[1][4];
		sayac++;
		hamle++;
	}

	else if(koorX>10&&koorX<120&&koorY>330&&koorY<480)	//3.1
	{
		if(kartDurumlari[2][0]==1||kartDurumlari[2][0]==-1) return 0;
		gosterX=10;
		gosterY=330;
		kartDurumlari[2][0]=1;
		acilanKartlar[sayac]=kartDestesi[2][0];
		sayac++;
		hamle++;
	}
	else if(koorX>130&&koorX<240&&koorY>330&&koorY<480)	//3.2
	{
		if(kartDurumlari[2][1]==1||kartDurumlari[2][1]==-1) return 0;
		gosterX=130;
		gosterY=330;
		kartDurumlari[2][1]=1;
		acilanKartlar[sayac]=kartDestesi[2][1];
		sayac++;
		hamle++;
	}
	else if(koorX>250&&koorX<360&&koorY>330&&koorY<480)	//3.3
	{
		if(kartDurumlari[2][2]==1||kartDurumlari[2][2]==-1) return 0;
		gosterX=250;
		gosterY=330;
		kartDurumlari[2][2]=1;
		acilanKartlar[sayac]=kartDestesi[2][2];
		sayac++;
		hamle++;
	}
	else if(koorX>370&&koorX<480&&koorY>330&&koorY<480)	//3.4
	{
		if(kartDurumlari[2][3]==1||kartDurumlari[2][3]==-1) return 0;
		gosterX=370;
		gosterY=330;
		kartDurumlari[2][3]=1;
		acilanKartlar[sayac]=kartDestesi[2][3];
		sayac++;
		hamle++;
	}
	else if(koorX>490&&koorX<600&&koorY>330&&koorY<480)	//3.5
	{
		if(kartDurumlari[2][4]==1||kartDurumlari[2][4]==-1) return 0;
		gosterX=490;
		gosterY=330;
		kartDurumlari[2][4]=1;
		acilanKartlar[sayac]=kartDestesi[2][4];
		sayac++;
		hamle++;
	}

	else if(koorX>10&&koorX<120&&koorY>490&&koorY<640)	//4.1
	{
		if(kartDurumlari[3][0]==1||kartDurumlari[3][0]==-1) return 0;
		gosterX=10;
		gosterY=490;
		kartDurumlari[3][0]=1;
		acilanKartlar[sayac]=kartDestesi[3][0];
		sayac++;
		hamle++;
	}
	else if(koorX>130&&koorX<240&&koorY>490&&koorY<640)	//4.2
	{
		if(kartDurumlari[3][1]==1||kartDurumlari[3][1]==-1) return 0;
		gosterX=130;
		gosterY=490;
		kartDurumlari[3][1]=1;
		acilanKartlar[sayac]=kartDestesi[3][1];
		sayac++;
		hamle++;
	}
	else if(koorX>250&&koorX<360&&koorY>490&&koorY<640)	//4.3
	{
		if(kartDurumlari[3][2]==1||kartDurumlari[3][2]==-1) return 0;
		gosterX=250;
		gosterY=490;
		kartDurumlari[3][2]=1;
		acilanKartlar[sayac]=kartDestesi[3][2];
		sayac++;
		hamle++;
	}
	else if(koorX>370&&koorX<480&&koorY>490&&koorY<640)	//4.4
	{
		if(kartDurumlari[3][3]==1||kartDurumlari[3][3]==-1) return 0;
		gosterX=370;
		gosterY=490;
		kartDurumlari[3][3]=1;
		acilanKartlar[sayac]=kartDestesi[3][3];
		sayac++;
		hamle++;
	}
	else if(koorX>490&&koorX<600&&koorY>490&&koorY<640)	//4.5
	{
		if(kartDurumlari[3][4]==1||kartDurumlari[3][4]==-1) return 0;
		gosterX=490;
		gosterY=490;
		kartDurumlari[3][4]=1;
		acilanKartlar[sayac]=kartDestesi[3][4];
		sayac++;
		hamle++;
	}

	else return 0;
	

}


void delay(float sec)
{
    time_t start;
    time_t current;
    time(&start);
    do{
        time(&current);
    }while(difftime(current,start) < sec);
}

void kartlariDagit()
{
	//kartların rastgele düzgün dağılabilmesi için
	int kartKontrol[4][5];

	int kart, X, Y;
	int i;			//aynı karttan 2 yere koyulması için
	srand((unsigned)time(0));

	for(kart=1;kart<=10;kart++)
	{
		i=0;
		do
		{
			X = rand() % 4;
			Y = rand() % 5;
			if(kartKontrol[X][Y]!=1)	//boşsa
			{
				kartKontrol[X][Y]=1;	//doldu
				kartDestesi[X][Y]=kart;
				i++;
			}
		}while(i!=2);
			
	}
}

void fareHareketi()
{
	if(mouse_b & 1)
	{
		cursorX = mouse_x;
		cursorY = mouse_y;
	}
}


void fareGoster()
{
	clear_to_color(screen,makecol( 120, 120, 200) );
	circlefill ( screen, cursorX, cursorY, 5, makecol( 0, 0, 255));
	draw_sprite( screen, screen, 0, 0);
	show_mouse(screen);
}

void yanMenu()
{
	BITMAP *oyunBilgileri, *topSkor, *bilgiler;
	oyunBilgileri = load_bitmap("oyunBilgileri.bmp", NULL);
	topSkor = load_bitmap("topSkor.bmp", NULL);
	bilgiler = load_bitmap("bilgiler.bmp", NULL);

	draw_sprite(screen, oyunBilgileri, 600, 10);
	textout_ex(screen,font,"Hamle Sayisi:",600,60,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"Puaniniz    :",600,80,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"Gecen Sure  :",600,100,makecol(250,250,250),makecol(120, 120, 200));


	draw_sprite(screen, topSkor, 600, 170);
	
	draw_sprite(screen, bilgiler, 600, 330);
	textout_ex(screen,font,"Kartlari acmak icin",600,370,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"ustune tiklayin. Her",600,385,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"kart 2 sn gorunup",600,400,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"kaybolacaktir. En kisa",600,415,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"surede tum kartlarin",600,430,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"eslerini bulup en yuksek",600,445,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"puani toplayabilirsiniz",600,460,makecol(250,250,250),makecol(120, 120, 200));


	textout_ex(screen,font,"Alg. ve Programlama II",600,570,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"Proje Odevi | 2010",600,590,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"Hasan Gok - 2008639021",600,610,makecol(250,250,250),makecol(120, 120, 200));
	textout_ex(screen,font,"Hafiza Oyunu v0.1b",600,630,makecol(250,250,250),makecol(120, 120, 200));

	//textprintf_ex(screen,font,50,500,makecol(250,250,250),makecol(120, 120, 200),"%s (Degisken Seklinde)",yazi);		//değişken yazdırma
}

void kartlariGoster()
{
	//her kart tek tek kontrol edilecek
	int i=0, j=0;

	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			//önce kartın ekrandaki yerini seç
			switch(j)
			{
			case 0: {
					gosterX=10;
					break;
					}
			case 1: {
					gosterX=130;
					break;
					}
			case 2: {
					gosterX=250;
					break;
					}
			case 3: {
					gosterX=370;
					break;
					}
			case 4: {
					gosterX=490;
					break;
					}
			}

			switch(i)
			{
			case 0: {
					gosterY=10;
					break;
					}
			case 1: {
					gosterY=170;
					break;
					}
			case 2: {
					gosterY=330;
					break;
					}
			case 3: {
					gosterY=490;
					break;
					}
			}

			switch(kartDurumlari[i][j])
			{
			case 0: {

				draw_sprite(screen, kart[0], gosterX, gosterY);
					break;
					}
			case -1:{
					rectfill(screen,  gosterX,  gosterY,  gosterX+100,  gosterY+150,  makecol( 120, 120, 200));
					break;
					}
			case  1:{
					draw_sprite(screen, kart[kartDestesi[i][j]], gosterX, gosterY);
					break;
					}
			}
		}
	}
}

int puanHesapla(int hamle, int sure, int pX, int pY)
{
	static int sPuan=0, hPuan=0;
	
	if(sure<20)	sPuan+=10;
	else if(sure<40) sPuan+=5;
	else sPuan+=3;

	if(hamle<5) hPuan+=10;
	else if(hamle<10) hPuan+=5;
	else hPuan+=1;

	if(pX<10||pX>600||pY<10||pY>500) {
										sPuan-=20;
										hPuan-=20;
	}

	return hPuan+sPuan;
}

void oyunBittiMi()
{
	int i, j, acikKart=0;
	for(i=0;i<4;i++)
		for(j=0;j<5;j++)
			if(kartDurumlari[i][j]==-1) acikKart++;

	if(acikKart==20) textout_ex(screen,font,"Oyun Bitti",150,150,makecol(250,250,250),makecol(120, 120, 200));
}

void main() 
{
	int puan=0, *ppuan=&puan;

	//zaman bilgileri
	double baslangic = time(NULL), gecenSure;
	char zaman[30];

	allegro_init();
	install_keyboard();
	install_mouse();
	set_color_depth(32);
	set_window_title("Hafiza Oyunu");
	set_gfx_mode( GFX_AUTODETECT_WINDOWED, 800, 650, 0, 0);

	//kart resimlerinin yüklenmesi
	kart[0] = load_bitmap("kapali.bmp", NULL);
	kart[1] = load_bitmap("kart1.bmp", NULL);
	kart[2] = load_bitmap("kart2.bmp", NULL);
	kart[3] = load_bitmap("kart3.bmp", NULL);
    kart[4] = load_bitmap("kart4.bmp", NULL);
	kart[5] = load_bitmap("kart5.bmp", NULL);
	kart[6] = load_bitmap("kart6.bmp", NULL);
	kart[7] = load_bitmap("kart7.bmp", NULL);
	kart[8] = load_bitmap("kart8.bmp", NULL);
	kart[9] = load_bitmap("kart9.bmp", NULL);
	kart[10] = load_bitmap("kart10.bmp", NULL);
	
	durumlariSifirla();
	kartlariDagit();	//rastgele yerleşim
	acquire_screen();	

	release_screen();	

	while(!key[KEY_ESC])
	{
		fareHareketi();
		if((mouse_b & MOUSE_LS))
		{
			fareGoster();
			tiklananiAc(cursorX,cursorY);
			kartlariGoster();
			yanMenu();
			gecenSure=time(NULL);
            sprintf(zaman,"%d", (int)difftime(gecenSure,baslangic));
			puan=puanHesapla(hamle,difftime(gecenSure,baslangic),cursorX,cursorY);
			textprintf_ex(screen,font,710,60,makecol(250,250,250),makecol(120, 120, 200),"%d",hamle);
			textprintf_ex(screen,font,710,80,makecol(250,250,250),makecol(120, 120, 200),"%d",puan);
			textprintf_ex(screen,font,710,100,makecol(250,250,250),makecol(120, 120, 200),"%s",zaman);
			oyunBittiMi();
			delay(2);
			
		}

	} 
	

	
}END_OF_MAIN();