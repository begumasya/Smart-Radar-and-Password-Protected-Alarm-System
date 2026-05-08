import processing.serial.*;

Serial myPort;
float uzaklik = 0;
float aci = 0;
ArrayList<float[]> noktalar = new ArrayList<float[]>();

void setup() {
  fullScreen();
  frameRate(30);
  myPort = new Serial(this, "COM3", 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  background(0);
  radarCiz();

  int cx = width / 2;
  int cy = height - 40;
  int maxR = width / 2 - 40;

  // Tarama çizgisi
  stroke(0, 255, 70, 180);
  strokeWeight(2);
  float tx = cx + maxR * cos(radians(aci));
  float ty = cy - maxR * sin(radians(aci));
  line(cx, cy, tx, ty);

  // Noktaları çiz
  noStroke();
  for (int i = 0; i < noktalar.size(); i++) {
    float[] n = noktalar.get(i);
    float alfa = map(i, 0, noktalar.size(), 30, 220);
    float r = map(n[1], 0, 400, 0, maxR);
    float x = cx + r * cos(radians(n[0]));
    float y = cy - r * sin(radians(n[0]));
    if (n[1] <= 100) {
      fill(255, 0, 0, alfa);
    } else {
      fill(0, 255, 70, alfa);
    }
    ellipse(x, y, 10, 10);
  }

  // Bilgi yazısı
  fill(0, 255, 70);
  textSize(16);
  text("Aci: " + (int)aci + "°", 20, 30);
  text("Mesafe: " + nf(uzaklik, 0, 1) + " cm", 20, 55);

  if (uzaklik > 0 && uzaklik <= 100) {
    fill(255, 0, 0);
    textSize(22);
    text("!! YAKIN NESNE !!", 20, 90);
  }
}

void radarCiz() {
  int cx = width / 2;
  int cy = height - 40;
  int maxR = width / 2 - 40;

  noFill();
  strokeWeight(1);
  for (int i = 1; i <= 4; i++) {
    stroke(0, 100, 0);
    arc(cx, cy, maxR * i / 2, maxR * i / 2, PI, TWO_PI);
    fill(0, 200, 0);
    noStroke();
    textSize(12);
    int etiket = 400 * i / 4;
    text(etiket + "cm", cx + 5, cy - (maxR * i / 4) + 5);
    noFill();
    stroke(0, 100, 0);
  }

  stroke(0, 80, 0);
  for (int a = 0; a <= 180; a += 30) {
    float x = cx + maxR * cos(radians(a));
    float y = cy - maxR * sin(radians(a));
    line(cx, cy, x, y);
  }

  fill(0, 200, 0);
  noStroke();
  textSize(11);
  int[] dereceler = {0, 30, 60, 90, 120, 150, 180};
  for (int a : dereceler) {
    float x = cx + (maxR + 20) * cos(radians(a));
    float y = cy - (maxR + 20) * sin(radians(a));
    text(a + "°", x - 10, y + 5);
  }

  stroke(0, 255, 70);
  strokeWeight(2);
  line(cx - maxR, cy, cx + maxR, cy);
}

void serialEvent(Serial p) {
  String veri = p.readStringUntil('\n');
  if (veri != null) {
    veri = trim(veri);
    String[] parcalar = veri.split(",");
    if (parcalar.length == 2) {
      try {
        aci = Float.parseFloat(parcalar[0]);
        uzaklik = Float.parseFloat(parcalar[1]);
        if (uzaklik > 0 && uzaklik <= 400) {
          float[] nokta = {aci, uzaklik};
          noktalar.add(nokta);
          if (noktalar.size() > 60) noktalar.remove(0);
        }
      } catch (Exception e) {}
    }
  }
}
