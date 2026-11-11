// =========================================================================
// PROYEK: SENSOR JARAK / PARKIR (SKALA METER)
// =========================================================================

const int pinTrig = 2;
const int pinEcho = 3;

const int ledMerah  = 8;   // Pin 8 = LED Merah
const int ledKuning = 9;   // Pin 9 = LED Kuning
const int ledHijau  = 10;  // Pin 10 = LED Hijau
const int pinBuzzer = 11;

void setup() {
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  pinMode(ledHijau, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("=== Sensor Jarak Siap (Skala Meter) ===");
}

void loop() {
  // Mengirim gelombang ultrasonik
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  // Menghitung jarak dalam sentimeter (cm)
  long durasi = pulseIn(pinEcho, HIGH);
  int jarakCm = durasi * 0.034 / 2;

  // Tampilkan jarak dalam Meter dan Sentimeter di Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(jarakCm / 100.0); // Konversi ke meter (desimal)
  Serial.print(" m (");
  Serial.print(jarakCm);
  Serial.println(" cm)");

  // --- LOGIKA JARAK SESUAI REQUEST ---
  // 1. BAHAYA: 1 meter atau kurang (<= 100 cm)
  if (jarakCm <= 100) {
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledKuning, LOW);                                  // Translate If u dont understand :)
    digitalWrite(ledMerah, HIGH);
    
    tone(pinBuzzer, 1500);
    delay(80);
    noTone(pinBuzzer);
    delay(80);
  } 
  // 2. ANCAMAN / WASPADA: Di atas 1 meter sampai 4 meter (101 cm - 400 cm)
  else if (jarakCm > 100 && jarakCm <= 400) {
    digitalWrite(ledHijau, LOW);
    digitalWrite(ledKuning, HIGH);
    digitalWrite(ledMerah, LOW);
    
    tone(pinBuzzer, 1000);
    delay(150);
    noTone(pinBuzzer);
    delay(350);
  } 
  // 3. AMAN: Di atas 4 meter (termasuk 10 meter / > 400 cm)
  else {
    digitalWrite(ledHijau, HIGH);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledMerah, LOW);
    noTone(pinBuzzer);
    delay(200);
  }
}
