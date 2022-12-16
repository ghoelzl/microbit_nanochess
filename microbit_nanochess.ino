#include <Adafruit_Microbit.h>

Adafruit_Microbit_Matrix microbit;

char * l = "ustvrtsuqqqqqqqqyyyyyyyy}{|~z|{}"
"   76Lsabcddcba .pknbrq  PKNBRQ ?A6J57IKJT576,+-48HLSU";

const char * COLORS[] = {
  "White",
  "Black"
};
const char * NAMES[] = {
  "",
  "Pawn",
  "King",
  "Knight",
  "Bishop",
  "Rook",
  "Queen"
};
const char * SELECT[] = {
  ">ABCDEFGH",
  "ABCDEFGH",
  "12345678",
  ">NQRB"
};

int B = 0, i, y, u, b, I[160], * G = I, x = 10, z = 15, M = 1e4;

void setup() {
  while (++B < 121)
    *G++ = B / x % x < 2 | B % x < 2 ? 7 : B / x & 4 ? 0 : * l++ & 31;

  Serial.begin(9600);
  microbit.begin();
  microbit.print("Nanochess");
  pinMode(PIN_BUTTON_A, INPUT);
  pinMode(PIN_BUTTON_B, INPUT);
}

int X(int w, int c, int h, int e, int S, int s) {
  //Serial.print("X");
  int t, o, L, E, d, O = e, N = -M * M, K = 78 - h << x, p, * g, n, * m, A, q, r, C, J, a = y ? -x : x;
  y ^= 8;
  G++;
  d = w || s && s >= h && X(0, 0, 0, 21, 0, 0) > M;
  do {
    if (o = I[p = O]) {
      q = o & z ^ y;
      if (q < 7) {
        A = q-- & 2 ? 8 : 4;
        C = o - 9 & z ? q["& .$  "] : 42;
        do {
          r = I[p += C[l] - 64];
          if (!w | p == w) {
            g = q | p + a - S ? 0 : I + S;
            if (!r & (q | A < 3 || g) || (r + 1 & z ^ y) > 9 && q | A > 2) {
              m = !(r - 2 & 7) ? (int * ) 1 : (int * ) 0;
              if (m) return --G, y ^= 8, G[1] = O, K;
              J = n = o & z;
              E = I[p - a] & z;
              t = q | E - 7 ? n : (n += 2, 6 ^ y);
              while (n <= t) {
                L = r ? l[r & 7] * 9 - 189 - h - q : 0;
                if (s)
                  L += (1 - q ? l[p / x + 5] - l[O / x + 5] + l[p % x + 6] * -~!q - l[O % x + 6] +
                    o / 16 * 8 : !!m * 9) + (q ? 0 : !(I[p - 1] ^ n) +
                    !(I[p + 1] ^ n) + l[n & 7] * 9 - 386 + !!g * 99 + (A < 2)) + !(E ^ y ^ 9);
                if (s > h || 1 < s & s == h && L > z | d) {
                  p[I] = n, O[I] = m ? * g = * m, * m = 0 : g ? * g = 0 : 0;
                  L -= X(s > h | d ? 0 : p, L - N, h + 1, G[1], J = q | A > 1 ? 0 : p, s);
                  if (!(h || s - 1 | B - O | i - n | p - b | L < -M))
                    return --G, y ^= 8, y ^= 8, u = J;
                  J = q - 1 | A < 7 || m || !s | d | r | o < z || X(0, 0, 0, 21, 0, 0) > M;
                  O[I] = o;
                  p[I] = r;
                  m ? * m = * g, * g = 0 : g ? * g = 9 ^ y : 0;
                }
                if (L > N) {
                  * G = O;
                  if (s > 1) {
                    if (h && c - L < 0)
                      return --G, y ^= 8, L;
                    if (!h)
                      i = n, B = O, b = p;
                  }
                  N = L;
                }
                n += J || (g = I + p, m = p < O ? g - 3 : g + 2, * m < z | m[O - p] || I[p += p - O]);
              }
            }
          }
        } while (!r & q > 2 || (p = O, q | A > 2 | o > z & !r && ++C * --A));
      }
    }
  } while (++O > 98 ? O = 20 : e - O);
  return --G, y ^= 8, N + M * M && N > -K + 1924 | d ? N : 0;
}

int buttonBState = 0;

int buttonBReleased() {
  if (digitalRead(PIN_BUTTON_B)) {
    if (buttonBState)
      buttonBState++;
  } else {
    buttonBState = 1;
  }
  delay(100);
  return (buttonBState == 2);
}

char getcharA(int mode) {
  buttonBState = 0;
  int curPos = 0;
  int nextWaiting = 0;
  char ch[] = {
    SELECT[mode][0],
    0
  };
  microbit.print(ch);
  do {
    if (digitalRead(PIN_BUTTON_A)) {
      if (nextWaiting) {
        nextWaiting = 0;
        curPos = curPos == strlen(SELECT[mode]) - 1 ? 0 : curPos + 1;
        ch[0] = SELECT[mode][curPos];
        microbit.print(ch);
      }
    } else {
      if (!nextWaiting) {
        nextWaiting++;
      }
    }
  }
  while (!buttonBReleased());
  return ch[0] == '>' ? x : ch[0];
}

void loop() {
  while (B = 19) {
    microbit.print((char * ) COLORS[y ? 1 : 0]);
    while (B++ < 99) Serial.print((char)(B % x ? l[B[I] | 16] : x));
    if (x - (B = getcharA(0) & z)) {
      i = I[B += (x - getcharA(2) & z) * x] & z;
      b = getcharA(1) & z;
      b += (x - getcharA(2) & z) * x;
      while (x - ( * G = getcharA(3) & z))
        i = * G ^ 8 ^ y;
    } else {
      microbit.show(microbit.MICROBIT_SMILE);
      X(0, 0, 0, 21, u, 3);
    }
    X(0, 0, 0, 21, u, 1);
    microbit.print((char * ) NAMES[i & 0x7]);
    char out[] = "-----";
    out[0] = 0x40 + B % 10;
    out[1] = 0x30 + 10 - B / 10;
    out[3] = 0x40 + b % 10;
    out[4] = 0x30 + 10 - b / 10;
    microbit.print(out);
  }
}