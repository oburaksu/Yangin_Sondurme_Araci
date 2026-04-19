# Wi-Fi Kontrollü Yangın Söndürme Aracı 🔥🚒

Bu proje, **Marmara Üniversitesi Teknoloji Fakültesi** bünyesinde yapılmış olan; **Nesnelerin İnterneti (IoT)** tabanlı, Wi-Fi üzerinden akıllı telefon ile kontrol edilebilen bir yangın söndüren robot prototipidir.

Robotun temel amacı, yangın gibi acil durumlarda insanların yaklaşmakta zorlanacağı veya riskli olan dar alanlara girerek, güvenli bir mesafeden müdahale etmektir. Su püskürtme mekanizması ve yüksek manevra kabiliyeti ile tehlikeyi uzaktan bertaraf etmeye olanak tanır. Uygulama tarafında haberleşme için **Blynk IoT** platformu kullanılmıştır.

## 🛠️ Kullanılan Malzemeler (Donanımlar)

Projemizde aşağıdaki bileşenler kullanılmıştır:
- **NodeMCU V3 (ESP8266):** Dahili Wi-Fi modülüne sahip projenin ana beyni / mikrodenetleyicisi.
- **L298N Motor Sürücü Kartı:** DC motorların yönünü ve hızını kontrol etmek ve regülatör işlevi görmek için.
- **6V 250 RPM DC Motor ve Tekerlek Seti (2 Adet):** Robotun hareketini sağlamak için (2WD İki tekerlekten çekiş).
- **5V Röle Kartı (Tek Kanal):** Yüksek akım çeken su pompasını anahtarlamak (aç-kapat) için.
- **Mini Dalgıç Su Pompası:** Hedeflenen yangın bölgesine su püskürtmek için.
- **Güç Kaynağı:** 2 adet 18650 Li-ion pil ve pil yuvası.
- **Robot Mekaniği:** Şase ve Sarhoş tekerlek.
- **Jumper Kablolar ve Anahtar (Aç-Kapa).**

## ⚙️ Proje Nasıl Çalışır? (İşleyiş)

1. Robot üzerindeki mekanizmalara enerji verildiğinde, sistem otomatik olarak daha önceden tanımlanmış **Wi-Fi ağına** bağlanır ve **Blynk** sunucularıyla haberleşir.
2. Kullanıcı akıllı telefonundaki kontrol arayüzü sayesinde ileri (V1), geri (V2), sağ (V3), sol (V4) komutlarını robotun NodeMCU kartına kablosuz olarak iletir (Neredeyse sıfır gecikme ile).
3. Gelen komutlar işlenerek L298N motor sürücüye aktarılır ve aracın hedeflenen yöne hareket etmesi sağlanır.
4. Su püskürtme butonuna (V5) basıldığında, NodeMCU üzerinden D7 pinindeki röle kartı tetiklenir ve dalgıç pompa aktif edilerek 1-2 metre uzağa su atımı gerçekleştirilir.

**Uygulanan Mühendislik Çözümleri:**
* *Röle Tetikleme (Low Trigger Uyumsuzluğu):* Röle 5V, NodeMCU ise 3.3V mantığıyla çalıştığından sistem başlatıldığında oluşan "sürekli çalışma" sorunu, yazılım kodunda pin durumları (`INPUT/OUTPUT`) manipüle edilerek çözülmüştür. (Yüksek empedans modu oluşturulmuştur)
* *Güç Yetersizliği:* 9V pillerin anlık zayıf akımlar vererek NodeMCU'yu sıfırlaması sorunu, anlık yüksek akım basabilen daha stabil 18650 Li-ion pillerin kullanılmasıyla önlenmiştir.

## 💻 Kaynak Kodlar (Yazılım)

Robot ile telefon arasındaki bağ için NodeMCU / Arduino IDE ortamında C/C++ kullanılmıştır. 
Sistemi çalıştıran **temel motor ve pompa otomasyonu kodlarının tamamı** bu depoda yer alan `yangin_robotu.c` dosyasında bulunmaktadır.

*** 
