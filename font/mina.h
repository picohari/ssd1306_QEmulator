#ifdef __AVR__ 
  #include <avr/io.h> 
  #include <avr/pgmspace.h> 
 #elif defined(ESP8266) 
  #include <pgmspace.h> 
 #else 
  #define PROGMEM 
 #endif 

const unsigned int mina10pt8bBitmaps[] PROGMEM = {
  0x00, 0xFA, 0xB6, 0x80, 0x57, 0xD5, 0xF5, 0x00, 0x27, 0xA6, 0x55, 0xE4,
  0x99, 0x24, 0x99, 0x45, 0x11, 0x59, 0x34, 0xE0, 0x2A, 0x49, 0x11, 0x88,
  0x92, 0x54, 0x96, 0xF6, 0x90, 0x21, 0x3E, 0x42, 0x00, 0x58, 0xF0, 0xC0,
  0x11, 0x22, 0x44, 0x88, 0x69, 0xBD, 0x96, 0x75, 0x50, 0xE1, 0x16, 0x8F,
  0xE1, 0x61, 0x1E, 0x99, 0x97, 0x11, 0xF8, 0xE1, 0x1E, 0x68, 0xE9, 0x96,
  0xF1, 0x22, 0x44, 0x69, 0x69, 0x96, 0x69, 0x97, 0x16, 0xD8, 0x51, 0x60,
  0x2A, 0x22, 0xF0, 0xF0, 0x88, 0xA8, 0x54, 0xA4, 0x10, 0x69, 0xBB, 0x87,
  0x69, 0x9F, 0x99, 0xE9, 0xE9, 0x9E, 0x78, 0x88, 0x87, 0xE9, 0x99, 0x9E,
  0xF8, 0xE8, 0x8F, 0xF8, 0xE8, 0x88, 0x78, 0x8B, 0x97, 0x99, 0xF9, 0x99,
  0xE9, 0x25, 0xC0, 0x71, 0x11, 0x96, 0x9A, 0xCA, 0x99, 0x88, 0x88, 0x8F,
  0x8E, 0xEB, 0x18, 0xC4, 0x9D, 0xDB, 0xB9, 0x69, 0x99, 0x96, 0xE9, 0x9E,
  0x88, 0x69, 0x99, 0x96, 0x30, 0xE9, 0x9E, 0x99, 0x78, 0x61, 0x1E, 0xF9,
  0x08, 0x42, 0x10, 0x99, 0x99, 0x97, 0x8C, 0x63, 0x15, 0x10, 0x8C, 0x63,
  0x5D, 0xC4, 0x99, 0x69, 0x99, 0x8C, 0x54, 0x42, 0x10, 0xF1, 0x24, 0x8F,
  0xF2, 0x49, 0x27, 0x88, 0x44, 0x22, 0x11, 0xE4, 0x92, 0x4F, 0x22, 0xA2,
  0xF0, 0xA4, 0x79, 0x9B, 0x50, 0x88, 0xE9, 0x99, 0xE0, 0x78, 0x88, 0x70,
  0x11, 0x79, 0x9B, 0x50, 0x69, 0xF8, 0x70, 0x73, 0xC9, 0x20, 0x79, 0x9B,
  0x51, 0x60, 0x88, 0xE9, 0x99, 0x90, 0x4D, 0x54, 0x21, 0x92, 0x49, 0xC0,
  0x88, 0x9A, 0xE9, 0x90, 0xD5, 0x54, 0xD5, 0x63, 0x18, 0x80, 0xE9, 0x99,
  0x90, 0x69, 0x99, 0x60, 0xE9, 0x99, 0xE8, 0x80, 0x79, 0x99, 0x71, 0x10,
  0xBA, 0x48, 0x78, 0x61, 0xE0, 0x5D, 0x24, 0x40, 0x99, 0x99, 0x70, 0x99,
  0x96, 0x60, 0x8C, 0x6B, 0xB8, 0x80, 0x99, 0x69, 0x90, 0x99, 0x99, 0x71,
  0x60, 0xF2, 0x48, 0xF0, 0x29, 0x6C, 0x91, 0xFF, 0xC0, 0x89, 0x36, 0x94,
  0x45, 0x6A, 0x20, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11,
  0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11,
  0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11,
  0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11,
  0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11,
  0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x6F, 0xF6, 0x99,
  0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99,
  0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99, 0x97, 0x11, 0x99,
  0x97, 0x11, 0x99, 0x97, 0x11, 0x9B, 0xFD, 0x00, 0xFF, 0x06, 0x0C, 0x18,
  0x30, 0x7F, 0x80, 0xFF, 0x06, 0xED, 0xDB, 0xB0, 0x7F, 0x80, 0xF0, 0xF0,
  0xF0, 0xF3, 0xCF, 0x3C, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80,
  0xEF, 0xDF, 0xBF, 0x7E, 0xFD, 0xFB, 0x80, 0x38, 0x8A, 0x0C, 0x18, 0x28,
  0x8E, 0x00, 0x38, 0x8A, 0xED, 0xDB, 0xA8, 0x8E, 0x00, 0xFF, 0xF7, 0xF7,
  0x7D, 0xF7, 0x7D, 0x57, 0x77, 0x7F, 0xF8, 0x38, 0x8A, 0xED, 0x1B, 0xA8,
  0x8E, 0x00, 0x00, 0x00, 0xF8, 0x42, 0x99, 0x97, 0x11, 0x38, 0x8A, 0xED,
  0x9A, 0xA8, 0x8E, 0x00, 0xE0, 0x55, 0x00, 0x5D, 0x0E, 0xC5, 0x4E, 0xC7,
  0x1C, 0x60, 0x99, 0x99, 0xE8, 0x7D, 0x6A, 0xD2, 0x94, 0xF0, 0x47, 0x80,
  0x75, 0x69, 0x96, 0xA5, 0xA0, 0x46, 0x10, 0xA3, 0x29, 0xE2, 0x46, 0x10,
  0xE0, 0x88, 0xE0, 0xC0, 0x84, 0x0A, 0xD8, 0xA3, 0xC2, 0x41, 0x4B, 0xC0,
  0x10, 0x71, 0x57, 0x75, 0x47, 0x04, 0x00, 0xFC, 0x77, 0xBD, 0xEF, 0xE0,
  0x25, 0x06, 0x99, 0xF9, 0x90, 0x5A, 0x69, 0x9F, 0x99, 0x90, 0x69, 0x9F,
  0x99, 0x69, 0x69, 0x9F, 0x99, 0x7E, 0x49, 0xBC, 0x92, 0x70, 0x78, 0x88,
  0x87, 0x24, 0x42, 0xF8, 0xE8, 0x8F, 0x24, 0xF8, 0xE8, 0x8F, 0x4A, 0xF8,
  0xE8, 0x8F, 0xA0, 0xF8, 0xE8, 0x8F, 0x88, 0x74, 0x92, 0xE0, 0x28, 0x74,
  0x92, 0xE0, 0x54, 0x74, 0x92, 0xE0, 0xA3, 0xA4, 0x97, 0x72, 0x7A, 0x94,
  0xB8, 0x5A, 0x0E, 0x99, 0x99, 0x84, 0x06, 0x99, 0x96, 0x24, 0x06, 0x99,
  0x96, 0x4A, 0x06, 0x99, 0x96, 0x5A, 0x06, 0x99, 0x96, 0x90, 0x69, 0x99,
  0x60, 0xAA, 0x80, 0x16, 0xBB, 0xDD, 0x68, 0x84, 0x99, 0x99, 0x97, 0x12,
  0x99, 0x99, 0x97, 0x25, 0x09, 0x99, 0x99, 0x70, 0x50, 0x99, 0x99, 0x97,
  0x11, 0x22, 0xA2, 0x10, 0x84, 0x88, 0xE9, 0x9E, 0x80, 0x69, 0xA9, 0x9A,
  0x80, 0x84, 0x07, 0x99, 0xB5, 0x24, 0x07, 0x99, 0xB5, 0x4A, 0x07, 0x99,
  0xB5, 0x5A, 0x07, 0x99, 0xB5, 0x50, 0x79, 0x9B, 0x50, 0x20, 0x79, 0x9B,
  0x50, 0x75, 0x6F, 0x45, 0x80, 0x78, 0x88, 0x72, 0x40, 0x84, 0x06, 0x9F,
  0x87, 0x24, 0x06, 0x9F, 0x87, 0x4A, 0x06, 0x9F, 0x87, 0xA0, 0x69, 0xF8,
  0x70, 0x93, 0x55, 0x28, 0x64, 0x92, 0x54, 0x64, 0x92, 0xA3, 0x24, 0x90,
  0xA6, 0x97, 0x99, 0x96, 0x5A, 0x0E, 0x99, 0x99, 0x84, 0x06, 0x99, 0x96,
  0x12, 0x06, 0x99, 0x96, 0x4A, 0x06, 0x99, 0x96, 0x5A, 0x06, 0x99, 0x96,
  0x90, 0x69, 0x99, 0x60, 0x20, 0x3E, 0x02, 0x00, 0x16, 0xB9, 0xD6, 0x80,
  0x84, 0x09, 0x99, 0x97, 0x24, 0x09, 0x99, 0x97, 0x4A, 0x09, 0x99, 0x97,
  0xA0, 0x99, 0x99, 0x70, 0x24, 0x09, 0x99, 0x97, 0x16, 0x88, 0xE9, 0x99,
  0xE8, 0x80, 0x50, 0x99, 0x99, 0x71, 0x60 };

const GFXglyph mina10pt8bGlyphs[] PROGMEM = {
  {     0,   1,   1,   3,    2,    0 },   // 0x20 ' '
  {     1,   1,   7,   2,    1,   -6 },   // 0x21 '!'
  {     2,   3,   3,   4,    1,   -6 },   // 0x22 '"'
  {     4,   5,   5,   6,    1,   -4 },   // 0x23 '#'
  {     8,   4,   8,   5,    1,   -6 },   // 0x24 '$'
  {    12,   4,   6,   5,    1,   -5 },   // 0x25 '%'
  {    15,   5,   6,   6,    1,   -5 },   // 0x26 '&'
  {    19,   1,   3,   2,    1,   -6 },   // 0x27 '''
  {    20,   3,   8,   5,    2,   -6 },   // 0x28 '('
  {    23,   3,   8,   5,    1,   -6 },   // 0x29 ')'
  {    26,   4,   5,   5,    1,   -4 },   // 0x2A '*'
  {    29,   5,   5,   6,    1,   -5 },   // 0x2B '+'
  {    33,   2,   3,   3,    1,   -1 },   // 0x2C ','
  {    34,   4,   1,   5,    1,   -3 },   // 0x2D '-'
  {    35,   1,   2,   2,    1,   -1 },   // 0x2E '.'
  {    36,   4,   8,   5,    1,   -6 },   // 0x2F '/'
  {    40,   4,   6,   5,    1,   -5 },   // 0x30 '0'
  {    43,   2,   6,   5,    2,   -5 },   // 0x31 '1'
  {    45,   4,   6,   5,    1,   -5 },   // 0x32 '2'
  {    48,   4,   6,   5,    1,   -5 },   // 0x33 '3'
  {    51,   4,   6,   5,    1,   -5 },   // 0x34 '4'
  {    54,   4,   6,   5,    1,   -5 },   // 0x35 '5'
  {    57,   4,   6,   5,    1,   -5 },   // 0x36 '6'
  {    60,   4,   6,   5,    1,   -5 },   // 0x37 '7'
  {    63,   4,   6,   5,    1,   -5 },   // 0x38 '8'
  {    66,   4,   6,   5,    1,   -5 },   // 0x39 '9'
  {    69,   1,   5,   4,    2,   -4 },   // 0x3A ':'
  {    70,   2,   6,   3,    0,   -4 },   // 0x3B ';'
  {    72,   3,   5,   6,    2,   -4 },   // 0x3C '<'
  {    74,   4,   3,   5,    1,   -4 },   // 0x3D '='
  {    76,   3,   5,   6,    2,   -4 },   // 0x3E '>'
  {    78,   3,   7,   4,    1,   -6 },   // 0x3F '?'
  {    81,   4,   6,   5,    1,   -5 },   // 0x40 '@'
  {    84,   4,   6,   5,    1,   -5 },   // 0x41 'A'
  {    87,   4,   6,   5,    1,   -5 },   // 0x42 'B'
  {    90,   4,   6,   5,    1,   -5 },   // 0x43 'C'
  {    93,   4,   6,   5,    1,   -5 },   // 0x44 'D'
  {    96,   4,   6,   5,    1,   -5 },   // 0x45 'E'
  {    99,   4,   6,   5,    1,   -5 },   // 0x46 'F'
  {   102,   4,   6,   5,    1,   -5 },   // 0x47 'G'
  {   105,   4,   6,   5,    1,   -5 },   // 0x48 'H'
  {   108,   3,   6,   4,    1,   -5 },   // 0x49 'I'
  {   111,   4,   6,   5,    1,   -5 },   // 0x4A 'J'
  {   114,   4,   6,   5,    1,   -5 },   // 0x4B 'K'
  {   117,   4,   6,   5,    1,   -5 },   // 0x4C 'L'
  {   120,   5,   6,   6,    1,   -5 },   // 0x4D 'M'
  {   124,   4,   6,   5,    1,   -5 },   // 0x4E 'N'
  {   127,   4,   6,   5,    1,   -5 },   // 0x4F 'O'
  {   130,   4,   6,   5,    1,   -5 },   // 0x50 'P'
  {   133,   4,   7,   5,    1,   -5 },   // 0x51 'Q'
  {   137,   4,   6,   5,    1,   -5 },   // 0x52 'R'
  {   140,   4,   6,   5,    1,   -5 },   // 0x53 'S'
  {   143,   5,   6,   6,    1,   -5 },   // 0x54 'T'
  {   147,   4,   6,   5,    1,   -5 },   // 0x55 'U'
  {   150,   5,   6,   6,    1,   -5 },   // 0x56 'V'
  {   154,   5,   6,   6,    1,   -5 },   // 0x57 'W'
  {   158,   4,   6,   5,    1,   -5 },   // 0x58 'X'
  {   161,   5,   6,   6,    1,   -5 },   // 0x59 'Y'
  {   165,   4,   6,   5,    1,   -5 },   // 0x5A 'Z'
  {   168,   3,   8,   6,    3,   -6 },   // 0x5B '['
  {   171,   4,   8,   5,    1,   -6 },   // 0x5C '\'
  {   175,   3,   8,   6,    1,   -6 },   // 0x5D ']'
  {   178,   5,   3,   5,    0,   -6 },   // 0x5E '^'
  {   180,   4,   1,   5,    1,    1 },   // 0x5F '_'
  {   181,   2,   3,   4,    2,   -6 },   // 0x60 '`'
  {   182,   4,   5,   5,    1,   -4 },   // 0x61 'a'
  {   185,   4,   7,   5,    1,   -6 },   // 0x62 'b'
  {   189,   4,   5,   5,    1,   -4 },   // 0x63 'c'
  {   192,   4,   7,   5,    1,   -6 },   // 0x64 'd'
  {   196,   4,   5,   5,    1,   -4 },   // 0x65 'e'
  {   199,   3,   7,   4,    1,   -6 },   // 0x66 'f'
  {   202,   4,   7,   5,    1,   -4 },   // 0x67 'g'
  {   206,   4,   7,   5,    1,   -6 },   // 0x68 'h'
  {   210,   2,   7,   3,    1,   -6 },   // 0x69 'i'
  {   212,   3,   9,   3,    0,   -6 },   // 0x6A 'j'
  {   216,   4,   7,   5,    1,   -6 },   // 0x6B 'k'
  {   220,   2,   7,   3,    1,   -6 },   // 0x6C 'l'
  {   222,   5,   5,   6,    1,   -4 },   // 0x6D 'm'
  {   226,   4,   5,   5,    1,   -4 },   // 0x6E 'n'
  {   229,   4,   5,   5,    1,   -4 },   // 0x6F 'o'
  {   232,   4,   7,   5,    1,   -4 },   // 0x70 'p'
  {   236,   4,   7,   5,    1,   -4 },   // 0x71 'q'
  {   240,   3,   5,   4,    1,   -4 },   // 0x72 'r'
  {   242,   4,   5,   5,    1,   -4 },   // 0x73 's'
  {   245,   3,   6,   4,    1,   -5 },   // 0x74 't'
  {   248,   4,   5,   5,    1,   -4 },   // 0x75 'u'
  {   251,   4,   5,   5,    1,   -4 },   // 0x76 'v'
  {   254,   5,   5,   6,    1,   -4 },   // 0x77 'w'
  {   258,   4,   5,   5,    1,   -4 },   // 0x78 'x'
  {   261,   4,   7,   5,    1,   -4 },   // 0x79 'y'
  {   265,   4,   5,   5,    1,   -4 },   // 0x7A 'z'
  {   268,   3,   8,   5,    1,   -6 },   // 0x7B '{'
  {   271,   1,  10,   5,    2,   -7 },   // 0x7C '|'
  {   273,   3,   8,   5,    2,   -6 },   // 0x7D '}'
  {   276,   5,   4,   5,    0,   -4 },   // 0x7E '~'
  {   279,   4,   6,   5,    1,   -5 },   // 0x7F
  {   282,   4,   6,   5,    1,   -5 },   // 0x80
  {   285,   4,   6,   5,    1,   -5 },   // 0x81
  {   288,   4,   6,   5,    1,   -5 },   // 0x82
  {   291,   4,   6,   5,    1,   -5 },   // 0x83
  {   294,   4,   6,   5,    1,   -5 },   // 0x84
  {   297,   4,   6,   5,    1,   -5 },   // 0x85
  {   300,   4,   6,   5,    1,   -5 },   // 0x86
  {   303,   4,   6,   5,    1,   -5 },   // 0x87
  {   306,   4,   6,   5,    1,   -5 },   // 0x88
  {   309,   4,   6,   5,    1,   -5 },   // 0x89
  {   312,   4,   6,   5,    1,   -5 },   // 0x8A
  {   315,   4,   6,   5,    1,   -5 },   // 0x8B
  {   318,   4,   6,   5,    1,   -5 },   // 0x8C
  {   321,   4,   6,   5,    1,   -5 },   // 0x8D
  {   324,   4,   6,   5,    1,   -5 },   // 0x8E
  {   327,   4,   6,   5,    1,   -5 },   // 0x8F
  {   330,   4,   6,   5,    1,   -5 },   // 0x90
  {   333,   4,   6,   5,    1,   -5 },   // 0x91
  {   336,   4,   6,   5,    1,   -5 },   // 0x92
  {   339,   4,   6,   5,    1,   -5 },   // 0x93
  {   342,   4,   6,   5,    1,   -5 },   // 0x94
  {   345,   4,   4,   5,    1,   -4 },   // 0x95
  {   347,   4,   6,   5,    1,   -5 },   // 0x96
  {   350,   4,   6,   5,    1,   -5 },   // 0x97
  {   353,   4,   6,   5,    1,   -5 },   // 0x98
  {   356,   4,   6,   5,    1,   -5 },   // 0x99
  {   359,   4,   6,   5,    1,   -5 },   // 0x9A
  {   362,   4,   6,   5,    1,   -5 },   // 0x9B
  {   365,   4,   6,   5,    1,   -5 },   // 0x9C
  {   368,   4,   6,   5,    1,   -5 },   // 0x9D
  {   371,   4,   6,   5,    1,   -5 },   // 0x9E
  {   374,   4,   6,   5,    1,   -5 },   // 0x9F
  {   377,   3,   6,   6,    2,   -5 },   // 0xA0
  {   380,   7,   7,   7,    0,   -6 },   // 0xA1
  {   387,   7,   7,   7,    0,   -6 },   // 0xA2
  {   394,   7,   7,   7,    0,   -6 },   // 0xA3
  {   401,   7,   7,   7,    0,   -6 },   // 0xA4
  {   408,   7,   7,   7,    0,   -6 },   // 0xA5
  {   415,   7,   7,   7,    0,   -6 },   // 0xA6
  {   422,   7,   7,   7,    0,   -6 },   // 0xA7
  {   429,  11,   7,  11,    0,   -6 },   // 0xA8
  {   439,   7,   7,   7,    0,   -6 },   // 0xA9
  {   446,   1,   1,   7,    6,    0 },   // 0xAA
  {   447,   1,   1,   5,    4,    0 },   // 0xAB
  {   448,   5,   3,   5,    0,   -3 },   // 0xAC
  {   450,   4,   6,   5,    1,   -5 },   // 0xAD
  {   453,   7,   7,   5,   -1,   -6 },   // 0xAE
  {   460,   3,   1,   5,    1,   -6 },   // 0xAF
  {   461,   3,   3,   4,    1,   -6 },   // 0xB0
  {   463,   3,   5,   5,    1,   -4 },   // 0xB1
  {   465,   3,   5,   5,    1,   -6 },   // 0xB2
  {   467,   3,   5,   5,    1,   -6 },   // 0xB3
  {   469,   2,   2,   5,    1,   -7 },   // 0xB4
  {   470,   4,   6,   5,    0,   -4 },   // 0xB5
  {   473,   5,   6,   5,    0,   -5 },   // 0xB6
  {   477,   2,   2,   5,    2,   -3 },   // 0xB7
  {   478,   3,   3,   5,    1,   -3 },   // 0xB8
  {   480,   2,   4,   5,    1,   -5 },   // 0xB9
  {   481,   4,   4,   5,    0,   -7 },   // 0xBA
  {   483,   4,   3,   5,    1,   -4 },   // 0xBB
  {   485,   5,   8,   5,    1,   -7 },   // 0xBC
  {   490,   5,   7,   5,    1,   -7 },   // 0xBD
  {   495,   6,   8,   5,    0,   -7 },   // 0xBE
  {   501,   3,   6,   5,    2,   -5 },   // 0xBF
  {   504,   7,   7,   5,   -1,   -6 },   // 0xC0
  {   511,   5,   7,   5,    0,   -6 },   // 0xC1
  {   516,   4,   9,   5,    1,   -8 },   // 0xC2
  {   521,   4,   8,   5,    1,   -7 },   // 0xC3
  {   525,   4,   8,   5,    1,   -7 },   // 0xC4
  {   529,   4,   8,   5,    1,   -7 },   // 0xC5
  {   533,   6,   6,   5,    0,   -5 },   // 0xC6
  {   538,   4,   8,   5,    0,   -5 },   // 0xC7
  {   542,   4,   8,   5,    1,   -7 },   // 0xC8
  {   546,   4,   8,   5,    1,   -7 },   // 0xC9
  {   550,   4,   8,   5,    1,   -7 },   // 0xCA
  {   554,   4,   8,   5,    1,   -7 },   // 0xCB
  {   558,   3,   9,   5,    1,   -8 },   // 0xCC
  {   562,   3,   9,   5,    1,   -8 },   // 0xCD
  {   566,   3,   9,   5,    1,   -8 },   // 0xCE
  {   570,   3,   8,   5,    1,   -7 },   // 0xCF
  {   573,   5,   6,   5,    0,   -5 },   // 0xD0
  {   577,   4,   8,   5,    1,   -7 },   // 0xD1
  {   581,   4,   8,   5,    1,   -7 },   // 0xD2
  {   585,   4,   8,   5,    1,   -7 },   // 0xD3
  {   589,   4,   8,   5,    1,   -7 },   // 0xD4
  {   593,   4,   8,   5,    1,   -7 },   // 0xD5
  {   597,   4,   7,   5,    1,   -6 },   // 0xD6
  {   601,   3,   3,   5,    1,   -4 },   // 0xD7
  {   603,   4,   8,   5,    1,   -6 },   // 0xD8
  {   607,   4,   8,   5,    1,   -7 },   // 0xD9
  {   611,   4,   8,   5,    1,   -7 },   // 0xDA
  {   615,   4,   9,   5,    1,   -8 },   // 0xDB
  {   620,   4,   8,   5,    1,   -7 },   // 0xDC
  {   624,   5,   8,   5,    0,   -7 },   // 0xDD
  {   629,   4,   7,   5,    1,   -5 },   // 0xDE
  {   633,   4,   7,   5,    1,   -5 },   // 0xDF
  {   637,   4,   8,   5,    1,   -7 },   // 0xE0
  {   641,   4,   8,   5,    1,   -7 },   // 0xE1
  {   645,   4,   8,   5,    1,   -7 },   // 0xE2
  {   649,   4,   8,   5,    1,   -7 },   // 0xE3
  {   653,   4,   7,   5,    1,   -6 },   // 0xE4
  {   657,   4,   7,   5,    1,   -6 },   // 0xE5
  {   661,   5,   5,   5,    1,   -4 },   // 0xE6
  {   665,   4,   7,   5,    1,   -4 },   // 0xE7
  {   669,   4,   8,   5,    1,   -7 },   // 0xE8
  {   673,   4,   8,   5,    1,   -7 },   // 0xE9
  {   677,   4,   8,   5,    1,   -7 },   // 0xEA
  {   681,   4,   7,   5,    1,   -6 },   // 0xEB
  {   685,   2,   8,   5,    2,   -7 },   // 0xEC
  {   687,   3,   8,   5,    2,   -7 },   // 0xED
  {   690,   3,   8,   5,    2,   -7 },   // 0xEE
  {   693,   3,   7,   5,    2,   -6 },   // 0xEF
  {   696,   4,   8,   5,    1,   -7 },   // 0xF0
  {   700,   4,   8,   5,    1,   -7 },   // 0xF1
  {   704,   4,   8,   5,    1,   -7 },   // 0xF2
  {   708,   4,   8,   5,    1,   -7 },   // 0xF3
  {   712,   4,   8,   5,    1,   -7 },   // 0xF4
  {   716,   4,   8,   5,    1,   -7 },   // 0xF5
  {   720,   4,   7,   5,    1,   -6 },   // 0xF6
  {   724,   5,   5,   5,    0,   -5 },   // 0xF7
  {   728,   4,   7,   5,    1,   -5 },   // 0xF8
  {   732,   4,   8,   5,    1,   -7 },   // 0xF9
  {   736,   4,   8,   5,    1,   -7 },   // 0xFA
  {   740,   4,   8,   5,    1,   -7 },   // 0xFB
  {   744,   4,   7,   5,    1,   -6 },   // 0xFC
  {   748,   4,  10,   5,    1,   -7 },   // 0xFD
  {   753,   4,   9,   5,    1,   -6 },   // 0xFE
  {   758,   4,   9,   5,    1,   -6 } }; // 0xFF

const GFXfont mina10pt8b PROGMEM = {
  (unsigned int  *)mina10pt8bBitmaps,
  (GFXglyph *)mina10pt8bGlyphs,
  0x20, 0xFF, 1 };

// Approx. 2338 bytes
