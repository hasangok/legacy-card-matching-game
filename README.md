**Not:** Bu oyun üniversitede iken ders projesi için yazılmıştır. Proje dokümanını aşağıdan okuyabilirsiniz. Üzerinden yıllar geçmiş olması ve acemilik yıllarında yazılmış olmasından dolayı birçok hata içerebilir. Anı olarak saklanmaktadır. Teşekkürler...
# Hafıza Oyunu -Kartların Eşlerini Bulmaca-

**Hazırlayan**  
Hasan Gök | 2008639021  
26.04.2010 Pazartesi

### Içindekiler
**[Giris](#giris)  
[Projenin Tarifi](#projenin-tarifi)  
[Proje Tasarimi](#proje-tasarimi)  
[Akis Diyagramlari ve Fonksiyonlarin Islevleri](#akis-diyagramlari-ve-fonksiyonlarin-islevleri)  
[Sonuc](#sonuc)  
[Kaynaklar](#kaynaklar)**

### Giris
Projenin amacı, 'Algoritmalar ve Programlama 2' dersi kapsamında bir hafıza oyunu geliştirmektir. Ekranda ters çevrilmiş olarak duran bir deste kartı teker teker açarak eşini bulmaya çalıştığımız bu oyun; Microsoft Visual Studio 2010 ile birlikte, C dili ve Allegro kütüphanesi 4.2.2 versiyonu kullanılarak geliştirilmiştir.

Bu raporda; programın geliştirilme süresince kullanılan yöntemler, projenin ayrıntılı analizi, tasarım aşamasında uygulananlar, kullanıcı etkileşimleri ve kodun geliştirilmesinde kullanılan düşünce yer almaktadır.

### Projenin Tarifi
Proje, giriş kısmında belirtildiği gibi, kartlarla oynanan bir 'Hafıza Oyunu'dur. Ekranda ters çevrilmiş halde duran kartları açıp eşini bulmak oyunun amacıdır. Aynı anda en fazla iki kart açılmış olabilir. Açılan kartlar eşleşirse, bu iki kart ekrandan silinir, eşleşmezse kapatılıp oyuna devam edilir.

Oyun temelde 3 işlem yapmaktadır:  
* Geçen süreyi saniye cinsinden saymak
* Yapılan hamle sayısını saymak
* Geçen süre ve hamle sayısı kriterlerine göre puanlama yapmak

Birbirlerine bağımlı olarak yapılan bu işlemler 'Proje Tasarımı' bölümünde ayrıntılarıyla anlatılmıştır. 

### Proje Tasarimi
Oyun, en temelinde sadece basit karşılaştırmalar yaparak çalışmaktadır. Bu karşılaştırmaları yapmak için; kart destesinin göründüğü şekilde, kartlara ait bilgileri tutan 2 adet 2-boyutlu dizi kullanılmıştır.

Birbirinden farklı 10 kartın, rastgele yerlere ikişer kez atanmasi ile, hangi kartın nerede yer aldığı "kartDestesi" adli 2-boyutlu dizide tutulmuştur. Böylece ekranda görülen yerlerde hangi kartların yer aldığı bu dizi ile belirlenmiş olur.

"kartDurumlari" adlı diğer iki boyutlu dizi de, kartDestesi adlı dizide tutulan kartların gösterilip gösterilmediğini belirler. Üç durum söz konusudur:  
* Değer 0 ise kart kapalıdır.
* Değer 1 ise kart açıktır.
* Değer -1 ise kartın eşi bulunmuştur, ekranda gösterilmez.

Örneğin; kartDurumlari[0][0]=1 ise kartDestesi[0][0] elemanına bakılır. İçerisinde hangi değer varsa o kart ekranda gösterilir, değer 0 olursa kapalı kart gösterilir.

Bu iki dizi haricinde, acilanKartlar adlı iki elemanlı bir dizi de açılan kartları hafızada tutmak için kullanılmıştır. Açılan her 2. kart için acilanKart[0] ve acilanKart[1] kontrol edilir. Eğer kartlar aynı ise eşi bulunmuş demektir, kartDurumlari dizisinde bu elemanların yer aldığı bölümlerin değerleri -1 olarak değiştirilir. Böylece sonraki adımlarda bu kartların ekranda gösterilmesi engellenir.

Oyunu puanlama işleminde 3 kriter kullanılmıştır:  
* **Hamle sayısı:** Ilk 5 hamle yüksek puana sahiptir. Hamle sayısı arttıkça açılan kartlara verilen puanlar azalır. Ilk 5 kartı hafızada tutmak, daha az hamle ile yüksek puan alabilmek açısından önemlidir.
* **Oyunda harcanan süre:** Oyunda geçen süre arttıkça, açılan kartlara daha az puan verilecektir. Yüksek puan kazanmak için oyunu hızlıca oynayabilmek önemlidir.
* **Ekranda tıklanan koordinatlar:** Kartların bulunduğu bölüm haricine yapılan tıklamalar geçersiz sayilacak ve puan azaltılacaktir.

### Akis Diyagramlari ve Fonksiyonlarin Islevleri
Oyunun çalışmasında kilit işlemleri yapan fonksiyonlara ait akış diyagramları ve main fonksiyonu bu bölümde açıklanmıştır.

```c
void main()
{
   degisken tanimlari;
   kartlari yukle;
   kartDurumlari=0;
   kartlariDagit();

   while(1)
   {
      if(fareye tiklanirsa)
      {
         tiklananiAc();
         kartlariGoster();
         yanMenu();
         puanHesapla();
         oyunBittiMi()
      }
   }
}

```

main() fonksiyonu yukarıda kabaca verilmiştir. Diyagramlardan önce oyunun genel işleyişine bakacak olursak:  
* Geçen zamanı, puanı vb. bilgileri saklayacak değişken tanımları yapılır.
* Kart grafikleri dosyadan değişkenlere çekilir.
* Baslangıçta her kartın kapalı gösterilmesi için kartların durumlari 0 olarak atanır.
* Kart dağıtma fonksiyonu çağırılıp eldeki 10 kartın rastgele yerlere dağılması sağlanır.
* Oyun döngüye girer ve oyun başlar.
* Döngü, kullanıcının fareye tıklamasıyla değerlendirme yapar.
* Tıklanan koordinatlarda hangi kart varsa, o kartın durumu 1 olarak değiştirilir.
* Bir adim sonra çağrılan kartlariGoster fonksiyonu durumu 1 olarak degiışmiş kartları açacaktır.
* Yan menü bölümü sayesinde puan durumu, geçen süre gösterilir.
* Puan hesaplama işlemleri yapılır.
* Oyun bitti mi diye kontrol edilir. Bittiyse Ekrana "Oyun Bitti" yazdırılır.

Durumları Sıfırla Fonksiyonu:  
![](https://raw.githubusercontent.com/hasangok/legacy-card-matching-game/master/1_durumlari_sifirla.jpg)

Kartları Göster Fonksiyonu:  
![](https://raw.githubusercontent.com/hasangok/legacy-card-matching-game/master/2_kartlari_goster.jpg)

Kartları Dağıt Fonksiyonu:  
![](https://raw.githubusercontent.com/hasangok/legacy-card-matching-game/master/3_kartlari_dagit.jpg)

Puan Hesapla Fonksiyonu:  
![](https://raw.githubusercontent.com/hasangok/legacy-card-matching-game/master/4_puan_hesapla.jpg)

### Sonuc
![](https://raw.githubusercontent.com/hasangok/legacy-card-matching-game/master/5_screenshot.jpg)
Sonuç olarak ekran görüntüsünde görülen oyun elde edilmiştir. Sol tarafta bulunan kart alanına tıklandıkça kartlar açılmakta, eşleri bulunan kartlar ekrandan silinmektedir.

Sağ tarafta "Oyun Bilgileri" bölümünde hamle sayısı, puan ve geçen süre bilgileri gösterilmekte, "Bilgiler" bölümünde oyun hakkında temel özelliklerden bahsedilmektedir.

### Kaynaklar:
* www.allegro.cc
* C ile programlama – Mithat Uysal
