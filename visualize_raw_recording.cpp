/*Record the encoded data using Audacity then export as "other uncompressed files" with settings:

  Header:  RAW (header-less)
Encoding:  Unsigned 8-bit PCM

Now this program can display it, and RICIN can decode it.  */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	ofstream out_stream;
	
	in_stream.open("untitled.raw");
	if(in_stream.fail() == true) {cout << "no file"; return 0;}
	char temp_file_byte;
	in_stream.get(temp_file_byte);
	for(; in_stream.eof() == false;)
	{	in_stream.get(temp_file_byte);
		
		if(temp_file_byte > 95) {cout << "#";}
		else {cout << " ";}
	}
	in_stream.close();
}







/* ALL SYMBOLS ARE BYTES OR 8 BITS! FILES ARE NOTHING LESS!



Dec	Hex	 Binary      HTML   Char  Description                  C++ file read/write

  0  00  00000000     &#0;  NUL   Null                         out_stream.put(0);   or   out_stream << '\0';
  1  01  00000001     &#1;  SOH   Start of Header              out_stream.put(1);
  2  02  00000010     &#2;  STX   Start of Text                out_stream.put(2);
  3  03  00000011     &#3;  ETX   End of Text                  out_stream.put(3);
  4  04  00000100     &#4;  EOT   End of Transmission          out_stream.put(4);
  5  05  00000101     &#5;  ENQ   Enquiry                      out_stream.put(5);
  6  06  00000110     &#6;  ACK   Acknowledge                  out_stream.put(6);
  7  07  00000111     &#7;  BEL   Bell                         out_stream.put(7);   or   out_stream << '\a';   (makes a beep-noise)
  8  08  00001000     &#8;  BS    Backspace                    out_stream.put(8);
  9  09  00001001     &#9;  HT    Horizontal Tab               out_stream.put(9);   or   out_stream << '\t';
 10  0A  00001010    &#10;  LF    Line Feed                    out_stream.put(10);  or   out_stream << '\n';   (moves cursor down a line) Sufficient on GNU+Linux. CAUTION: uploading to stikked.ch for example means the downloaded or copy/paste output will have prepended '\r' to each '\n' automatically to make "\r\n".
 11  0B  00001011    &#11;  VT    Vertical Tab                 out_stream.put(11);
 12  0C  00001100    &#12;  FF    Form Feed                    out_stream.put(12);
 13  0D  00001101    &#13;  CR    Carriage Return              out_stream.put(13);  or   out_stream << '\r';   (moves cursor to beginning of line) Must be "\r\n" on Windows, and 'r' on Mac.
 14  0E  00001110    &#14;  SO    Shift Out                    out_stream.put(14);
 15  0F  00001111    &#15;  SI    Shift In                     .
 16  10  00010000    &#16;  DLE   Data Link Escape             .
 17  11  00010001    &#17;  DC1   Device Control 1             .
 18  12  00010010    &#18;  DC2   Device Control 2             .
 19  13  00010011    &#19;  DC3   Device Control 3
 20  14  00010100    &#20;  DC4   Device Control 4
 21  15  00010101    &#21;  NAK   Negative Acknowledge
 22  16  00010110    &#22;  SYN   Synchronize
 23  17  00010111    &#23;  ETB   End of Transmission Block
 24  18  00011000    &#24;  CAN   Cancel
 25  19  00011001    &#25;  EM    End of Medium
 26  1A  00011010    &#26;  SUB   Substitute
 27  1B  00011011    &#27;  ESC   Escape
 28  1C  00011100    &#28;  FS    File Separator
 29  1D  00011101    &#29;  GS    Group Separator
 30  1E  00011110    &#30;  RS    Record Separator
 31  1F  00011111    &#31;  US    Unit Separator
 32  20  00100000    &#32;  space Blank or space        Standard 95 printable ASCII characters begin here
 33  21  00100001    &#33;  !     Exclamation mark               (32 to 126 or space to tilde.)
 34  22  00100010    &#34;  "     Double quote
 35  23  00100011    &#35;  #     Number
 36  24  00100100    &#36;  $     Dollar sign
 37  25  00100101    &#37;  %     Percent
 38  26  00100110    &#38;  &     Ampersand
 39  27  00100111    &#39;  '     Single quote
 40  28  00101000    &#40;  (     Left parenthesis
 41  29  00101001    &#41;  )     Right parenthesis
 42  2A  00101010    &#42;  *     Asterisk
 43  2B  00101011    &#43;  +     Plus
 44  2C  00101100    &#44;  ,     Comma
 45  2D  00101101    &#45;  -     Minus
 46  2E  00101110    &#46;  .     Period
 47  2F  00101111    &#47;  /     Slash
 48  30  00110000    &#48;  0     Zero
 49  31  00110001    &#49;  1     One
 50  32  00110010    &#50;  2     Two
 51  33  00110011    &#51;  3     Three
 52  34  00110100    &#52;  4     Four
 53  35  00110101    &#53;  5     Five
 54  36  00110110    &#54;  6     Six
 55  37  00110111    &#55;  7     Seven
 56  38  00111000    &#56;  8     Eight
 57  39  00111001    &#57;  9     Nine
 58  3A  00111010    &#58;  :     Colon
 59  3B  00111011    &#59;  ;     Semicolon
 60  3C  00111100    &#60;  <     Less than
 61  3D  00111101    &#61;  =     Equality sign
 62  3E  00111110    &#62;  >     Greater than
 63  3F  00111111    &#63;  ?     Question mark
 64  40  01000000    &#64;  @     At sign
 65  41  01000001    &#65;  A     Capital A
 66  42  01000010    &#66;  B     Capital B
 67  43  01000011    &#67;  C     Capital C
 68  44  01000100    &#68;  D     Capital D
 69  45  01000101    &#69;  E     Capital E
 70  46  01000110    &#70;  F     Capital F
 71  47  01000111    &#71;  G     Capital G
 72  48  01001000    &#72;  H     Capital H
 73  49  01001001    &#73;  I     Capital I
 74  4A  01001010    &#74;  J     Capital J
 75  4B  01001011    &#75;  K     Capital K
 76  4C  01001100    &#76;  L     Capital L
 77  4D  01001101    &#77;  M     Capital M
 78  4E  01001110    &#78;  N     Capital N
 79  4F  01001111    &#79;  O     Capital O
 80  50  01010000    &#80;  P     Capital P
 81  51  01010001    &#81;  Q     Capital Q
 82  52  01010010    &#82;  R     Capital R
 83  53  01010011    &#83;  S     Capital S
 84  54  01010100    &#84;  T     Capital T
 85  55  01010101    &#85;  U     Capital U
 86  56  01010110    &#86;  V     Capital V
 87  57  01010111    &#87;  W     Capital W
 88  58  01011000    &#88;  X     Capital X
 89  59  01011001    &#89;  Y     Capital Y
 90  5A  01011010    &#90;  Z     Capital Z
 91  5B  01011011    &#91;  [     Left square bracket
 92  5C  01011100    &#92;  \     Backslash
 93  5D  01011101    &#93;  ]     Right square bracket
 94  5E  01011110    &#94;  ^     Caret/circumflex
 95  5F  01011111    &#95;  _     Underscore
 96  60  01100000    &#96;  `     Grave/accent
 97  61  01100001    &#97;  a     Small a
 98  62  01100010    &#98;  b     Small b
 99  63  01100011    &#99;  c     Small c
100  64  01100100   &#100;  d     Small d
101  65  01100101   &#101;  e     Small e
102  66  01100110   &#102;  f     Small f
103  67  01100111   &#103;  g     Small g
104  68  01101000   &#104;  h     Small h
105  69  01101001   &#105;  i     Small i
106  6A  01101010   &#106;  j     Small j
107  6B  01101011   &#107;  k     Small k
108  6C  01101100   &#108;  l     Small l
109  6D  01101101   &#109;  m     Small m
110  6E  01101110   &#110;  n     Small n
111  6F  01101111   &#111;  o     Small o
112  70  01110000   &#112;  p     Small p
113  71  01110001   &#113;  q     Small q                     .
114  72  01110010   &#114;  r     Small r                     .
115  73  01110011   &#115;  s     Small s                     .
116  74  01110100   &#116;  t     Small t                     .
117  75  01110101   &#117;  u     Small u                     .
118  76  01110110   &#118;  v     Small v                     out_stream.put(118);   or   out_stream << 'v';
119  77  01110111   &#119;  w     Small w                     out_stream.put(119);   or   out_stream << 'w';
120  78  01111000   &#120;  x     Small x                     out_stream.put(120);   or   out_stream << 'x';
121  79  01111001   &#121;  y     Small y                     out_stream.put(121);   or   out_stream << 'y';
122  7A  01111010   &#122;  z     Small z                     out_stream.put(122);   or   out_stream << 'z';
123  7B  01111011   &#123;  {     Left curly bracket          out_stream.put(123);   or   out_stream << '{';
124  7C  01111100   &#124;  |     Unix pipe                   out_stream.put(124);   or   out_stream << '|';
125  7D  01111101   &#125;  }     Right curly bracket         out_stream.put(125);   or   out_stream << '}';
126  7E  01111110   &#126;  ~     Tilde                       out_stream.put(126);   or   out_stream << '~';
127  7F  01111111   &#127;  DEL   Delete                      out_stream.put(127);
128  80  10000000   -                                      out_stream.put(128);   or   out_stream.put(-128);
129  81  10000001   -                                      out_stream.put(129);   or   out_stream.put(-127);
130  82  10000010   -                                      out_stream.put(130);   or   out_stream.put(-126);
131  83  10000011   -                                      out_stream.put(131);   or   out_stream.put(-125);
132  84  10000100   -                                      out_stream.put(132);   or   out_stream.put(-124);
133  85  10000101   -                                      out_stream.put(133);   or   out_stream.put(-123);
134  86  10000110   -                                      out_stream.put(134);   or   out_stream.put(-122);
135  87  10000111   -                                      out_stream.put(135);   or   out_stream.put(-121);
136  88  10001000   -                                      .
137  89  10001001   -                                      .         (increasing)        (increasing but from negatives)
138  8A  10001010   -                                      .
139  8B  10001011   -                                      .
140  8C  10001100   -                                      .
141  8D  10001101   -       
142  8E  10001110   -       
143  8F  10001111   -       
144  90  10010000   -       
145  91  10010001   -       
146  92  10010010   -       
147  93  10010011   -       
148  94  10010100   -       
149  95  10010101   -       
150  96  10010110   -       
151  97  10010111   -       
152  98  10011000   -       
153  99  10011001   -       
154  9A  10011010   -       
155  9B  10011011   -       
156  9C  10011100   -       
157  9D  10011101   -       
158  9E  10011110   -       
159  9F  10011111   -       
160  A0  10100000   &#160;   
161  A1  10100001   &#161;  ¡
162  A2  10100010   &#162;  ¢
163  A3  10100011   &#163;  £
164  A4  10100100   &#164;  ¤
165  A5  10100101   &#165;  ¥
166  A6  10100110   &#166;  ¦
167  A7  10100111   &#167;  §
168  A8  10101000   &#168;  ¨
169  A9  10101001   &#169;  ©
170  AA  10101010   &#170;  ª
171  AB  10101011   &#171;  «
172  AC  10101100   &#172;  ¬
173  AD  10101101   &#173;  ­
174  AE  10101110   &#174;  ®
175  AF  10101111   &#175;  ¯
176  B0  10110000   &#176;  °
177  B1  10110001   &#177;  ±
178  B2  10110010   &#178;  ²
179  B3  10110011   &#179;  ³
180  B4  10110100   &#180;  ´
181  B5  10110101   &#181;  µ
182  B6  10110110   &#182;  ¶
183  B7  10110111   &#183;  ·
184  B8  10111000   &#184;  ¸
185  B9  10111001   &#185;  ¹
186  BA  10111010   &#186;  º
187  BB  10111011   &#187;  »
188  BC  10111100   &#188;  ¼
189  BD  10111101   &#189;  ½
190  BE  10111110   &#190;  ¾
191  BF  10111111   &#191;  ¿
192  C0  11000000   &#192;  À
193  C1  11000001   &#193;  Á
194  C2  11000010   &#194;  Â
195  C3  11000011   &#195;  Ã
196  C4  11000100   &#196;  Ä
197  C5  11000101   &#197;  Å
198  C6  11000110   &#198;  Æ
199  C7  11000111   &#199;  Ç
200  C8  11001000   &#200;  È
201  C9  11001001   &#201;  É
202  CA  11001010   &#202;  Ê
203  CB  11001011   &#203;  Ë
204  CC  11001100   &#204;  Ì
205  CD  11001101   &#205;  Í
206  CE  11001110   &#206;  Î
207  CF  11001111   &#207;  Ï
208  D0  11010000   &#208;  Ð
209  D1  11010001   &#209;  Ñ
210  D2  11010010   &#210;  Ò
211  D3  11010011   &#211;  Ó
212  D4  11010100   &#212;  Ô
213  D5  11010101   &#213;  Õ
214  D6  11010110   &#214;  Ö
215  D7  11010111   &#215;  ×
216  D8  11011000   &#216;  Ø
217  D9  11011001   &#217;  Ù
218  DA  11011010   &#218;  Ú
219  DB  11011011   &#219;  Û
220  DC  11011100   &#220;  Ü
221  DD  11011101   &#221;  Ý
222  DE  11011110   &#222;  Þ
223  DF  11011111   &#223;  ß
224  E0  11100000   &#224;  à
225  E1  11100001   &#225;  á
226  E2  11100010   &#226;  â
227  E3  11100011   &#227;  ã
228  E4  11100100   &#228;  ä
229  E5  11100101   &#229;  å
230  E6  11100110   &#230;  æ
231  E7  11100111   &#231;  ç
232  E8  11101000   &#232;  è
233  E9  11101001   &#233;  é
234  EA  11101010   &#234;  ê
235  EB  11101011   &#235;  ë
236  EC  11101100   &#236;  ì
237  ED  11101101   &#237;  í
238  EE  11101110   &#238;  î
239  EF  11101111   &#239;  ï
240  F0  11110000   &#240;  ð
241  F1  11110001   &#241;  ñ
242  F2  11110010   &#242;  ò
243  F3  11110011   &#243;  ó      .
244  F4  11110100   &#244;  ô      .
245  F5  11110101   &#245;  õ      .
246  F6  11110110   &#246;  ö      .
247  F7  11110111   &#247;  ÷      ..
248  F8  11111000   &#248;  ø      ...
249  F9  11111001   &#249;  ù      ....
250  FA  11111010   &#250;  ú      out_stream.put(250);   or   out_stream.put(-6);    ####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*####
251  FB  11111011   &#251;  û      out_stream.put(251);   or   out_stream.put(-5);    ##'                                 '##
252  FC  11111100   &#252;  ü      out_stream.put(252);   or   out_stream.put(-4);    #       With negatives, order =       #
253  FD  11111101   &#253;  ý      out_stream.put(253);   or   out_stream.put(-3);    #   0 up to 127 then  -128 up to -1   #
254  FE  11111110   &#254;  þ      out_stream.put(254);   or   out_stream.put(-2);    ##,                                 ,##
255  FF  11111111   &#255;  ÿ      out_stream.put(255);   or   out_stream.put(-1);    ####*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*####

*/
