# 📡 Arduino Ultrasonic Distance Alert System (Meter Scale)

Sistem peringatan jarak berbasis **Arduino Uno** menggunakan sensor ultrasonik **HC-SR04**, tiga indikator LED (Hijau, Kuning, Merah), dan **Buzzer** aktif. Proyek ini dirancang untuk mendeteksi jarak objek dan memberikan peringatan visual serta suara secara bertingkat.

---

## 🎯 Fitur & Logika Sistem

Sistem membagi zona deteksi ke dalam tiga tingkat keamanan:

| Zona Jarak | Rentang Jarak | Indikator LED | Peringatan Suara (Buzzer) |
| :--- | :--- | :--- | :--- |
| **🟢 Aman** | `> 4 meter` (`> 400 cm`) | **Hijau** menyala | Diam (Mati) |
| **🟡 Ancaman / Waspada** | `1.01 m – 4.00 m` (`101 – 400 cm`) | **Kuning** menyala | Bunyi *bip* sedang (1000 Hz, jeda 350 ms) |
| **🔴 Bahaya** | `≤ 1 meter` (`≤ 100 cm`) | **Merah** menyala | Bunyi *bip* cepat (1500 Hz, jeda 80 ms) |

---

## 🛠️ Komponen yang Dibutuhkan

* 1x **Arduino Uno R3**
* 1x **Sensor Ultrasonik HC-SR04**
* 3x **LED 5mm** (Merah, Kuning, Hijau)
* 3x **Resistor 220 Ohm**
* 1x **Buzzer**
* Kabel Jumper & Breadboard

---

## 🔌 Skema Pengkabelan (Pinout)

| Komponen | Pin Komponen | Pin Arduino Uno |
| :--- | :--- | :--- |
| **HC-SR04** | `VCC` | `5V` |
| **HC-SR04** | `GND` | `GND` |
| **HC-SR04** | `TRIG` | `D2` |
| **HC-SR04** | `ECHO` | `D3` |
| **LED Merah** | Anoda (+) via R220 | `D8` |
| **LED Kuning** | Anoda (+) via R220 | `D9` |
| **LED Hijau** | Anoda (+) via R220 | `D10` |
| **Buzzer** | Positif (+) | `D11` |
| **Semua LED & Buzzer** | Katoda (-) / Negatif | `GND` |

---

## 🚀 Cara Menjalankan

### A. Simulasi via Wokwi (Tanpa Perangkat Fisik)
1. Buka [Wokwi Simulator](https://wokwi.com) dan buat proyek **Arduino Uno** baru.
2. Salin kode dari `src/sensor_jarak_meter.ino` ke tab `sketch.ino`.
3. Salin isi `wokwi/diagram.json` ke tab `diagram.json` di Wokwi.
4. Klik tombol **Start Simulation (Play)**, lalu klik sensor **HC-SR04** untuk menggeser jarak objek.

### B. Perangkat Fisik (Arduino IDE)
1. Rangkai komponen sesuai tabel **Skema Pengkabelan** di atas.
2. Buka file `src/sensor_jarak_meter.ino` menggunakan **Arduino IDE**.
3. Pilih **Board: Arduino Uno** dan **Port** yang terhubung.
4. Klik **Upload** dan buka **Serial Monitor** (`9600 baud`) untuk memantau pembacaan jarak dalam satuan meter dan sentimeter.

---

## 📝 Catatan Pengembangan
* Sensor HC-SR04 standar memiliki batas pengukuran efektif maksimal sekitar **4 meter (400 cm)**. Untuk pengukuran fisik hingga **10 meter**, sensor dapat diganti dengan modul ultrasonik jarak jauh seperti **JSN-SR04T** atau sensor **LiDAR (TF-Luna)** tanpa mengubah struktur logika peringatan utama.
