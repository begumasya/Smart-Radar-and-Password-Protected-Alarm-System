# PIC16-Alarm-System
PIC16F877A Tabanlı Şifre Korumalı Akıllı Alarm ve Radar Sistemi
Proje Tanımı
Bu proje, çevre güvenliğini sağlamak amacıyla tasarlanmış, radar tarama özellikli ve şifre korumalı bir akıllı alarm sistemidir. Sistem, mekanik tarama ile çevresel farkındalık sağlarken, tehdit algıladığında kullanıcı etkileşimi gerektiren bir güvenlik katmanı sunar.

Çalışma Mantığı ve Özellikler
Radar Modu: Sistem, normal çalışma durumunda bir servo motor aracılığıyla sağa-sola sürekli tarama yaparak radar benzeri bir fonksiyon icra edecek ve sistemin aktif olduğunu yeşil LED ile belirtecektir.

Mesafe Simülasyonu: Gerçek sensör verisi yerine, potansiyometre üzerinden gelen analog sinyal ADC (Analog-Digital Converter) modülü ile okunarak mesafe bilgisine dönüştürülecektir.

Alarm Durumu: Mesafe belirlenen eşik değerin (20 cm) altına düştüğünde; servo motor durdurulacak, kırmızı LED ve buzzer aktif edilecek, LCD ekranda şifre giriş ekranı görüntülenecektir.

Güvenlik ve Şifreleme: Sistemin tekrar aktif edilmesi için 3x4 Keypad üzerinden tanımlı şifrenin (1234) girilmesi gerekmektedir. Şifre doğrulandıktan sonra sistem güvenli mesafeye çıkılana kadar bekleyecek ve ardından radar moduna dönecektir.

Teknik Bileşenler
Mikrodenetleyici: PIC16F877A

Görsel Arayüz: 16x2 Karakter LCD ve Durum LED'leri

Mekanik Birim: Servo Motor (PWM Kontrollü)

Giriş Birimi: 3x4 Matrix Keypad ve Potansiyometre (ADC Girişi)

Uyarı Birimi: Buzzer

Görev Dağılımı
Begüm Asya Eroğlu: Keypad tarama algoritması, şifreleme mantığı (Security Logic) ve LCD kullanıcı arayüzü tasarımı.

Fırat Cem Başoğlu: ADC üzerinden mesafe hesaplama, PWM ile servo motor kontrolü ve sistemin Proteus simülasyonu.

Geliştirme Ortamı
Yazılım: CCS C Compiler

Simülasyon: Proteus 8 Professional
