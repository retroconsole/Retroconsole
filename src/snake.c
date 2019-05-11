#include "snake.h"



const uint8_t snakehead[][1] PROGMEM= {
{0b01000000},
{0b10110000},
{0b11110000},
{0b00000000}
};

const uint8_t snakeheadflipped[][1] PROGMEM= {
{0b00000000},
{0b11110000},
{0b10110000},
{0b01000000}
};

const uint8_t snakebody[][1] PROGMEM= {
{0b00000000},
{0b01110000},
{0b11100000},
{0b00000000}
};

const uint8_t snakebodyflipped[][1] PROGMEM= {
{0b00000000},
{0b11100000},
{0b01110000},
{0b00000000}
};

const uint8_t snakecorner1[][1] PROGMEM= {
{0b00100000},
{0b01100000},
{0b11100000},
{0b00000000}
};

const uint8_t snakecorner2[][1] PROGMEM= {
{0b01000000},
{0b01100000},
{0b11100000},
{0b00000000}
};

const uint8_t snakecorner3[][1] PROGMEM= {
{0b00100000},
{0b11100000},
{0b01100000},
{0b0000000}
};


const uint8_t snakecorner4[][1] PROGMEM= {
{0b00000000},
{0b01000000},
{0b11100000},
{0b01100000}
};

const uint8_t snakecorner5[][1] PROGMEM= {
{0b01000000},
{0b11100000},
{0b01100000},
{0b00000000}
};

const uint8_t snakecorner6[][1] PROGMEM= {
{0b00000000},
{0b11100000},
{0b01100000},
{0b01000000}
};

const uint8_t snakecorner7[][1] PROGMEM= {
{0b00000000},
{0b11100000},
{0b01100000},
{0b01000000}
};

const uint8_t snakecorner8[][1] PROGMEM= {
{0b00000000},
{0b01100000},
{0b11100000},
{0b00100000}
};


const uint8_t death[][6] PROGMEM= {
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000011, 0b11111110, 0b00000000, 0b00000000},
{0b00000000, 0b00000011, 0b11111101, 0b10000001, 0b11100000, 0b00000000},
{0b00000000, 0b00001111, 0b11000111, 0b10000001, 0b11111100, 0b00000000},
{0b00000000, 0b00010011, 0b11111111, 0b11111110, 0b11100010, 0b00000000},
{0b00000000, 0b01100001, 0b11100000, 0b00000001, 0b11100001, 0b10000000},
{0b00000000, 0b10110010, 0b00010000, 0b00000000, 0b00010011, 0b11000000},
{0b00000000, 0b11100010, 0b00110111, 0b00000000, 0b00001111, 0b11000000},
{0b00000001, 0b01110100, 0b00100111, 0b00000000, 0b00000011, 0b10100000},
{0b00000001, 0b01110100, 0b00100100, 0b10000000, 0b00010001, 0b00100000},
{0b00000010, 0b01111000, 0b00111100, 0b10000000, 0b00111101, 0b00010000},
{0b00000010, 0b01101000, 0b00011001, 0b10000000, 0b01111101, 0b00010000},
{0b00000100, 0b01110000, 0b00000000, 0b00000000, 0b01111000, 0b10001000},
{0b00000100, 0b00010000, 0b00000000, 0b00000000, 0b01001000, 0b10001000},
{0b00000100, 0b11010000, 0b00111111, 0b10000000, 0b01010000, 0b11101000},
{0b00000101, 0b11110000, 0b00000011, 0b00000000, 0b10010000, 0b11111000},
{0b00000101, 0b11110000, 0b00000001, 0b00000000, 0b10010001, 0b11110000},
{0b00000111, 0b11110000, 0b00000000, 0b10000000, 0b11110001, 0b11110000},
{0b00000111, 0b01010000, 0b00011111, 0b10000000, 0b11111011, 0b11110000},
{0b00000101, 0b11001000, 0b00111110, 0b00000000, 0b11111100, 0b00010000},
{0b00000100, 0b00001000, 0b00000000, 0b00000000, 0b01111000, 0b00100000},
{0b00000100, 0b00001000, 0b00011110, 0b00000000, 0b01000000, 0b00100000},
{0b00000100, 0b00001000, 0b00111101, 0b00000000, 0b00110000, 0b01100000},
{0b00000100, 0b01101000, 0b00100100, 0b10000000, 0b00001111, 0b10000000},
{0b00000100, 0b11101000, 0b00100110, 0b10000000, 0b00000000, 0b00000000},
{0b00000100, 0b11111000, 0b00100011, 0b00000000, 0b00000000, 0b00000000},
{0b00000100, 0b11011000, 0b00010001, 0b00000000, 0b00000000, 0b00000000},
{0b00000100, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000100, 0b11100100, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000011, 0b11100100, 0b00111111, 0b11111000, 0b00000000, 0b00000000},
{0b00000011, 0b11100100, 0b00011111, 0b11110000, 0b11111111, 0b11111000},
{0b00000010, 0b00000100, 0b00000100, 0b00000000, 0b11111111, 0b11111000},
{0b00000010, 0b00000100, 0b00001111, 0b00000000, 0b00000110, 0b00011000},
{0b00000010, 0b00000100, 0b00011001, 0b10000000, 0b00000110, 0b00011000},
{0b00000010, 0b00000110, 0b00110000, 0b10000000, 0b00000110, 0b00011000},
{0b00000010, 0b00000110, 0b00000000, 0b00000000, 0b00001110, 0b00011000},
{0b00000010, 0b01111110, 0b00000000, 0b00000000, 0b00011111, 0b11110000},
{0b00000001, 0b01111110, 0b00000000, 0b00000000, 0b01110001, 0b11110000},
{0b00000001, 0b00000010, 0b00000000, 0b00000000, 0b11100000, 0b00000000},
{0b00000001, 0b00000010, 0b00000000, 0b00000000, 0b10000000, 0b00000000},
{0b00000001, 0b00011010, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000001, 0b00111110, 0b00111111, 0b10000000, 0b00000000, 0b00000000},
{0b00000001, 0b00111110, 0b00011111, 0b10010000, 0b11000000, 0b00000000},
{0b00000001, 0b00111110, 0b00000000, 0b00000000, 0b11000000, 0b00000000},
{0b00000001, 0b00111110, 0b00010000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b10100101, 0b00110111, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b10111101, 0b00100111, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b10011001, 0b00100100, 0b10000000, 0b00000000, 0b00000000},
{0b00000000, 0b10000001, 0b00111100, 0b10000000, 0b11111111, 0b11111000},
{0b00000000, 0b10000001, 0b00011001, 0b10000000, 0b11111111, 0b11111000},
{0b00000000, 0b10000001, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000001, 0b10000001, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000001, 0b00111111, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000001, 0b00111101, 0b00000000, 0b00000000, 0b11000000, 0b00000000},
{0b00000011, 0b00011111, 0b00000000, 0b00000000, 0b11000000, 0b00000000},
{0b00000010, 0b00000001, 0b10000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000010, 0b00000000, 0b10011111, 0b00000000, 0b00000000, 0b00000000},
{0b00000010, 0b00000010, 0b10100001, 0b10000000, 0b00000000, 0b00000000},
{0b00000010, 0b00010010, 0b10100000, 0b10000000, 0b00000000, 0b00000000},
{0b00000010, 0b00011110, 0b10100000, 0b10000000, 0b11111111, 0b11111000},
{0b00000010, 0b00001100, 0b10100001, 0b10000000, 0b11111111, 0b11111000},
{0b00000010, 0b00001100, 0b10111111, 0b11111000, 0b00000110, 0b00011000},
{0b00000010, 0b00011100, 0b10000000, 0b00000000, 0b00000110, 0b00011000},
{0b00000010, 0b00010101, 0b10000000, 0b00000000, 0b00000110, 0b00011000},
{0b00000010, 0b00000001, 0b00011110, 0b00000000, 0b00000110, 0b00011000},
{0b00000011, 0b00000001, 0b00111101, 0b00000000, 0b00000011, 0b11110000},
{0b00000001, 0b00000011, 0b00100100, 0b10000000, 0b00000001, 0b11100000},
{0b00000001, 0b10001110, 0b00100110, 0b10000000, 0b00000000, 0b00000000},
{0b00000000, 0b11111000, 0b00100011, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b01000000, 0b00010001, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b11000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b11000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000001, 0b01000000, 0b00011111, 0b00000000, 0b00000000, 0b00000000},
{0b00000011, 0b01000000, 0b00100001, 0b10000000, 0b00000000, 0b00000000},
{0b00000110, 0b01000000, 0b00100000, 0b10000000, 0b00000000, 0b00000000},
{0b00000000, 0b01000000, 0b00100000, 0b10000000, 0b00000000, 0b00000000},
{0b00000000, 0b01000000, 0b00100001, 0b10000000, 0b00000000, 0b00000000},
{0b00000000, 0b01100000, 0b00111111, 0b11111000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}
};


const uint8_t food[][1] PROGMEM= {
{0b01100000},
{0b11010000},
{0b10110000},
{0b01100000}
};

static const uint8_t gamefield[][5] PROGMEM= {
{0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111},
{0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001},
{0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001},
{0b10011111, 0b11111111, 0b11111111, 0b11111111, 0b11111001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10010000, 0b00000000, 0b00000000, 0b00000000, 0b00001001},
{0b10011111, 0b11111111, 0b11111111, 0b11111111, 0b11111001},
{0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001},
{0b10000000, 0b00000000, 0b00000000, 0b00000000, 0b00000001},
{0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111}
};

static const uint8_t winscreen[][6] PROGMEM= {
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00010000, 0b00000000, 0b00000000, 0b00000000, 0b01000000},
{0b00000001, 0b11111100, 0b00001111, 0b11000000, 0b00000000, 0b10000000},
{0b00000010, 0b00010000, 0b00000000, 0b10000000, 0b00000011, 0b00000000},
{0b00000010, 0b00010000, 0b00000000, 0b01000000, 0b00111110, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b01000000, 0b00000001, 0b00000000},
{0b00000011, 0b11111110, 0b00001111, 0b10000000, 0b00000000, 0b11000000},
{0b00000000, 0b00100000, 0b00000000, 0b01000000, 0b00000000, 0b00000000},
{0b00000000, 0b00010000, 0b00000000, 0b01000000, 0b00011110, 0b00000000},
{0b00000000, 0b00010000, 0b00000000, 0b11000000, 0b00100001, 0b00000000},
{0b00000011, 0b11100000, 0b00001111, 0b10000000, 0b00100001, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00110011, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00011110, 0b00000000},
{0b00000011, 0b11010000, 0b00000111, 0b10000000, 0b00000000, 0b00000000},
{0b00000010, 0b01010000, 0b00001000, 0b01000000, 0b00000000, 0b00000000},
{0b00000010, 0b01010000, 0b00001000, 0b01000000, 0b00011111, 0b00000000},
{0b00000011, 0b01110000, 0b00001100, 0b11000000, 0b00100000, 0b00000000},
{0b00000011, 0b11100000, 0b00000111, 0b10000000, 0b00100000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00010000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00111111, 0b00000000},
{0b00000011, 0b11110000, 0b00001111, 0b11000000, 0b00000000, 0b00000000},
{0b00000000, 0b00100000, 0b00000000, 0b10000000, 0b00000000, 0b00000000},
{0b00000000, 0b00010000, 0b00000000, 0b01000000, 0b00000000, 0b00000000},
{0b00000000, 0b00010000, 0b00000000, 0b01000000, 0b00000000, 0b00000000},
{0b00000011, 0b11100000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000111, 0b10000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00001001, 0b01000000, 0b00011110, 0b00000000},
{0b00000000, 0b00000000, 0b00001001, 0b01000000, 0b00100101, 0b00000000},
{0b00000000, 0b00000000, 0b00001001, 0b01000000, 0b00100101, 0b00000000},
{0b00000000, 0b00000000, 0b00001001, 0b10000000, 0b00100101, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00100110, 0b00000000},
{0b00000001, 0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000011, 0b00001100, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000010, 0b00000100, 0b00000000, 0b00000000, 0b00111101, 0b00000000},
{0b00000010, 0b00000100, 0b00000000, 0b00000000, 0b00100101, 0b00000000},
{0b00000010, 0b00000100, 0b00000000, 0b00000000, 0b00100101, 0b00000000},
{0b00000001, 0b00001000, 0b00001111, 0b11110000, 0b00110111, 0b00000000},
{0b00000000, 0b00000000, 0b00000001, 0b00010000, 0b00111110, 0b00000000},
{0b00000000, 0b00000000, 0b00000001, 0b00010000, 0b00000000, 0b00000000},
{0b00000011, 0b11111110, 0b00000001, 0b00010000, 0b00000001, 0b00000000},
{0b00000000, 0b00100000, 0b00000110, 0b11100000, 0b00011111, 0b11000000},
{0b00000000, 0b00010000, 0b00001000, 0b00000000, 0b00100001, 0b00000000},
{0b00000000, 0b00010000, 0b00000000, 0b00000000, 0b00100001, 0b00000000},
{0b00000011, 0b11100000, 0b00001000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000111, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000010, 0b11000000, 0b00000000, 0b00000000},
{0b00000011, 0b11110000, 0b00000010, 0b00110000, 0b00000000, 0b00000000},
{0b00000000, 0b00100000, 0b00000010, 0b01110000, 0b00000000, 0b00000000},
{0b00000000, 0b00010000, 0b00000011, 0b10000000, 0b00000000, 0b00000000},
{0b00000000, 0b00010000, 0b00001100, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000001, 0b11100000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000010, 0b00010000, 0b00001111, 0b11110000, 0b00000000, 0b00000000},
{0b00000010, 0b00010000, 0b00000000, 0b00110000, 0b00000000, 0b00000000},
{0b00000011, 0b00110000, 0b00000000, 0b11000000, 0b00000000, 0b00000000},
{0b00000001, 0b11100000, 0b00000011, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000001, 0b10000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b01100000, 0b00000000, 0b00000000},
{0b00000011, 0b11110000, 0b00001111, 0b11110000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000001, 0b11100000, 0b00000000},
{0b00000000, 0b00010000, 0b00000000, 0b00001111, 0b11111100, 0b00000000},
{0b00000000, 0b00010000, 0b00000000, 0b00111110, 0b00011110, 0b00000000},
{0b00000011, 0b11100000, 0b00000000, 0b01111000, 0b00001111, 0b00000000},
{0b00000000, 0b00010000, 0b00000000, 0b01100000, 0b00011011, 0b10000000},
{0b00000000, 0b00010000, 0b00000000, 0b11000000, 0b01100001, 0b11000000},
{0b00000000, 0b00110000, 0b00000000, 0b11000001, 0b11000000, 0b11000000},
{0b00000011, 0b11100000, 0b00000001, 0b10000010, 0b00110000, 0b11000000},
{0b00000000, 0b00000000, 0b00000001, 0b10000100, 0b00010000, 0b01100000},
{0b00000000, 0b00000000, 0b00000001, 0b10000100, 0b00001000, 0b01100000},
{0b00000001, 0b11100000, 0b00000001, 0b11100100, 0b00001000, 0b01100000},
{0b00000010, 0b01010000, 0b00000001, 0b10011100, 0b00001000, 0b01100000},
{0b00000010, 0b01010000, 0b00000001, 0b10000110, 0b00011000, 0b11000000},
{0b00000010, 0b01010000, 0b00000001, 0b10000011, 0b11101000, 0b11000000},
{0b00000010, 0b01100000, 0b00000000, 0b11000000, 0b00001001, 0b11000000},
{0b00000000, 0b00000000, 0b00000000, 0b11100000, 0b00001001, 0b10000000},
{0b00000000, 0b00000000, 0b00000000, 0b01110000, 0b00001011, 0b10000000},
{0b00000000, 0b00000000, 0b00000000, 0b00111000, 0b00001111, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00011111, 0b11111100, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000111, 0b11110000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}
};

static const char scoreText[] PROGMEM = "Score";

//Global to change data Sprites
Sprite snakeheadSprite = {4, 4, 1, *snakehead};
Sprite snakebodySprite = {4, 4, 1, *snakebody};
Sprite snakebodyflippedSprite = {4, 4, 1, *snakebodyflipped};
Sprite snakecorner1Sprite = {4, 4, 1, *snakecorner1};
Sprite snakecorner2Sprite = {4, 4, 1, *snakecorner2};
Sprite snakecorner3Sprite = {4, 4, 1, *snakecorner3};
Sprite snakecorner4Sprite = {4, 4, 1, *snakecorner4};
Sprite snakecorner5Sprite = {4, 4, 1, *snakecorner5};
Sprite snakecorner6Sprite = {4, 4, 1, *snakecorner6};
Sprite snakecorner7Sprite = {4, 4, 1, *snakecorner7};
Sprite snakecorner8Sprite = {4, 4, 1, *snakecorner8};
Sprite snakeheadflippedSprite = {4, 4, 1, *snakeheadflipped};
Sprite foodSprite = {4, 4, 1, *food};
Sprite deathSprite = {84, 48, 6, *death};
Sprite winscreenSprite = {84, 48, 6, *winscreen};
Snake snakeHead = {0, 0, SNAKE_LEFT, SNAKE_LEFT, &snakeheadSprite};
Sprite gamefieldSprite = {84, 40, 5, *gamefield};
Food snack = {0,0,0,0};



void SNAKEMain(void) {
	Snake snake[SNAKE_SIZE] = {0};
	uint16_t snakeSpeed = baseSpeed;
	uint8_t direction = 2;
	int8_t pauseState = 0;


	RANDOMSeed(MILLISGet());
	SNAKEInit(snake);

	while(1){
		SNAKEhandleInputs(&direction);
		if (!pauseState) {

			
			//Movement
			if (MILLISGet() - startTime > snakeSpeed) {
				SNAKEmoveHead(&snake[0], direction);
				SNAKEbodyFollow(snake);
				//Check snake collision with itself.
				if (SNAKEcheckDeath(snake)) {
					SNAKEdeathScreen(snake);
					break;
				}
			}
			
			//Graphics
			//Place gamefield
			LCDPlaceSprite(0, 8, 0, gamefieldSprite);
			//Generate food if needed.
			SNAKEgenerateFood(&snack, snake);
			//Check food collision.
			SNAKEeatFood(&snack, snake);
			//Place snake on screen
			SNAKEplaceSnake(snake);
			SNAKEPrintScore(score);
			//Shift to 40th pixel on x and print score
			LCDbufferCounter = 40;
			
			LCDRender();
			//Check if game is won
			if (SNAKEgameWin(snake)) {
				LCDbufferCounter = 0;
				break;
			}

			//Turbo
			if (!BUTTONGet(BUTTON8)) snakeSpeed = baseSpeed;
			else snakeSpeed = baseSpeed / 4;
		}

		//Exit to menu
		if (BUTTONGet(BUTTON2)) {
			LCDbufferCounter = 0;
			break;
		}
		LCDClearBuffer();
	}
}

void SNAKEInit(Snake *snake) {
	startTime = MILLISGet();
	moved = 0;
	startX = LCD_X / 2 + 2;
	startY = LCD_Y / 2;
	snakeLength = 3;
	baseSpeed = 300;
	score = 0;
	//Init head
	snake[0] = snakeHead;
	snake[0].x = startX;
	snake[0].y = startY;
	snake[0].sprite = &snakeheadflippedSprite;

	snake[1].x = startX + SPRITE_SIZE;
	snake[1].y = startY;
	snake[1].currentDir = SNAKE_LEFT;
	snake[1].sprite = &snakebodyflippedSprite;

	snake[2].x = startX + 2 * SPRITE_SIZE;
	snake[2].y = startY;
	snake[2].currentDir = SNAKE_LEFT;
	snake[2].sprite = &snakebodyflippedSprite;

}

//Handle button presses and remember them for next game tick.
void SNAKEhandleInputs(uint8_t *direction) {
	if (BUTTONGet(UP)) *direction = SNAKE_UP;
	else if (BUTTONGet(DOWN)) *direction = SNAKE_DOWN;
	else if (BUTTONGet(LEFT)) *direction = SNAKE_LEFT;
	else if (BUTTONGet(RIGHT)) *direction = SNAKE_RIGHT;
}

//Blink snake and show death screen.
void SNAKEdeathScreen(Snake *snake) {
	for (uint8_t i = 0; i < SPRITE_SIZE; i++) {
		LCDClearBuffer(); 
		LCDPlaceSprite(0, 8, 0, gamefieldSprite);
		SNAKEPrintScore(score);
		LCDPlaceSprite(snack.x, snack.y, 0, foodSprite);
		LCDRender();
		_delay_ms(200);
		SNAKEplaceSnake(snake);
		LCDRender();
		_delay_ms(200);
	}
	LCDClearBuffer();
	LCDPlaceSprite(0, 0, 0, deathSprite);
	LCDRender();
	_delay_ms(3500);
}

uint8_t SNAKEgameWin(Snake *snake) {
	if (snakeLength == SNAKE_SIZE) {
		SNAKEbodyFollow(snake);
		LCDPlaceSprite(0, 8, 0, gamefieldSprite);
		SNAKEplaceSnake(snake);
		LCDRender();
		LCDClearBuffer();
		_delay_ms(1000);
		LCDClearBuffer();
		LCDPlaceSprite(0, 0, 0, winscreenSprite);
		LCDRender();
		_delay_ms(3000);
		return 1;
	}
	return 0;
}

//Check collision with itself.
uint8_t SNAKEcheckDeath(Snake *snake) {
	for (uint8_t i = 1; i < snakeLength; i++) {
		if (snake[0].x >= snake[i].x && snake[0].y >= snake[i].y && snake[0].x <= snake[i].x + SPRITE_SIZE - 1 && snake[0].y <= snake[i].y + SPRITE_SIZE - 1) {
			return 1;
		}
	}
	return 0;
}

//Check collision with food.
void SNAKEeatFood(Food *snack, Snake *snake) {
	if (snake[0].x >= snack->x && snake[0].x <= snack->x + SPRITE_SIZE - 1 && snake[0].y >= snack->y && snake[0].y <= snack->y + SPRITE_SIZE - 1) {
		snack->available = 0;
		snake[snakeLength] = snake[snakeLength - 1];
		if (snake[snakeLength].currentDir == SNAKE_UP) snake[snakeLength].y += SPRITE_SIZE;
		else if (snake[snakeLength].currentDir == SNAKE_DOWN) snake[snakeLength].y -= SPRITE_SIZE;
		else if (snake[snakeLength].currentDir == SNAKE_LEFT) snake[snakeLength].x += SPRITE_SIZE;
		else if (snake[snakeLength].currentDir == SNAKE_RIGHT) snake[snakeLength].x -= SPRITE_SIZE;
		snakeLength++;
		score += 10;
	}
}

//Food generation.
void SNAKEgenerateFood(Food *snack, Snake *snake) {
	uint8_t nocollision = 1;
	if(!snack->available) {
		while (snack->available == 0) {
			snack->x = PLAYGROUND_LOWER_BOUND_X + (RANDOMGet()% ((PLAYGROUND_UPPER_BOUND_X - PLAYGROUND_LOWER_BOUND_X) - SPRITE_SIZE - 1));
			snack->y = PLAYGROUND_LOWER_BOUND_Y + (RANDOMGet()% ((PLAYGROUND_UPPER_BOUND_Y - PLAYGROUND_LOWER_BOUND_Y) - SPRITE_SIZE - 1));

			//Place so snake can munch at right spot.
			while (snack->x % SPRITE_SIZE) snack->x++;
			while (snack->y % SPRITE_SIZE) snack->y++;

			for (uint8_t i = 0; i < snakeLength; i++) {
				if (snack->x == snake[i].x && snack->y == snake[i].y) {
					nocollision = 0;
				}
			}
			//If legit rise legit flag.
			if (nocollision) snack->available = 1;

			//Needed to evade endless loop.
			else nocollision = 1;
		}
		LCDPlaceSprite(snack->x, snack->y, 0, foodSprite);
	}
	else {
		LCDPlaceSprite(snack->x, snack->y, 0, foodSprite);
	}
}

//Places snake onto buffer.
void SNAKEplaceSnake(Snake *snake) {
	for (uint8_t i = 0; i < snakeLength; i++) {
		LCDPlaceSprite(snake[i].x, snake[i].y, snake[i].currentDir, *snake[i].sprite);
	}
}

//Head movement logic.
void SNAKEmoveHead(Snake *snakeHead, uint8_t direction) {
	snakeHead->lastMoveDir = snakeHead->currentDir;
	if (direction == SNAKE_UP && snakeHead->currentDir != SNAKE_DOWN) {
		snakeHead->y -= SPRITE_SIZE;
		snakeHead->currentDir = SNAKE_UP;
		if (headSide == SNAKE_LEFT) {
			snakeHead->sprite = &snakeheadflippedSprite;
		}
		else {
		snakeHead->sprite = &snakeheadSprite;
		}
		moved = 1;
	}
	else if (direction == SNAKE_DOWN && snakeHead->currentDir != SNAKE_UP) {
		snakeHead->y += SPRITE_SIZE;
		snakeHead->currentDir = SNAKE_DOWN;
		if (headSide == SNAKE_LEFT) {
			snakeHead->sprite = &snakeheadflippedSprite;
		}
		else {
		snakeHead->sprite = &snakeheadSprite;
		}
		moved = 1;
	}
	else if (direction == SNAKE_LEFT && snakeHead->currentDir != SNAKE_RIGHT) {
		snakeHead->x -= SPRITE_SIZE;
		snakeHead->currentDir = SNAKE_LEFT;
		snakeHead->sprite = &snakeheadflippedSprite;
		headSide = SNAKE_LEFT;
		moved = 1;
	}
	else if (direction == SNAKE_RIGHT && snakeHead->currentDir != SNAKE_LEFT) {
		snakeHead->x += SPRITE_SIZE;
		snakeHead->currentDir = SNAKE_RIGHT;
		snakeHead->sprite = &snakeheadSprite;
		headSide = SNAKE_RIGHT;
		moved = 1;
	}
	else {
		snakeHead->currentDir = snakeHead->lastMoveDir;
		switch (snakeHead->currentDir)
		{
			case SNAKE_UP:
				snakeHead->y -= SPRITE_SIZE;
				break;
			case SNAKE_DOWN:
				snakeHead->y += SPRITE_SIZE;
				break;
			case SNAKE_LEFT:
				snakeHead->x -= SPRITE_SIZE;
				break;
			case SNAKE_RIGHT:
				snakeHead->x += SPRITE_SIZE;
				break;
		}
		moved = 1;
	}

	//Limit snake movements.
	if (snakeHead->x > PLAYGROUND_UPPER_BOUND_X - SPRITE_SIZE) snakeHead->x = PLAYGROUND_LOWER_BOUND_X;
	if (snakeHead->x < PLAYGROUND_LOWER_BOUND_X) snakeHead->x = PLAYGROUND_UPPER_BOUND_X - SPRITE_SIZE;
	if (snakeHead->y < PLAYGROUND_LOWER_BOUND_Y) snakeHead->y = PLAYGROUND_UPPER_BOUND_Y - SPRITE_SIZE;
	if (snakeHead->y > PLAYGROUND_UPPER_BOUND_Y - SPRITE_SIZE) snakeHead->y = PLAYGROUND_LOWER_BOUND_Y;

	startTime = MILLISGet();
}

//Body movement logic.
void SNAKEbodyFollow(Snake *snake) {
	if (moved)
	for (uint8_t i = 1; i < snakeLength; i++) {
		//Location and direction handling
		snake[i].lastMoveDir = snake[i].currentDir;
			switch (snake[i - 1].currentDir)
			{
				case SNAKE_UP:
					snake[i].x = snake[i - 1].x;
					snake[i].y = (snake[i - 1].y + SPRITE_SIZE);
					snake[i].currentDir = snake[i - 1].lastMoveDir;
					break;

				case SNAKE_DOWN:
					snake[i].x = snake[i - 1].x;
					snake[i].y =(snake[i - 1].y - SPRITE_SIZE);
					snake[i].currentDir = snake[i - 1].lastMoveDir;
					break;

				case SNAKE_LEFT:
					snake[i].x = (snake[i - 1].x + SPRITE_SIZE);
					snake[i].y = snake[i - 1].y;
					snake[i].currentDir = snake[i - 1].lastMoveDir;
					break;

				case SNAKE_RIGHT:
					snake[i].x = (snake[i - 1].x - SPRITE_SIZE);
					snake[i].y = snake[i - 1].y;
					snake[i].currentDir = snake[i - 1].lastMoveDir;
					break;
			}

		// Limit movement to bounds.
		if (snake[i].x >= PLAYGROUND_UPPER_BOUND_X) {
			snake[i].x = PLAYGROUND_LOWER_BOUND_X;
		}
		else if (snake[i].x < PLAYGROUND_LOWER_BOUND_X) {
			snake[i].x = PLAYGROUND_UPPER_BOUND_X - SPRITE_SIZE;
		}
		else if (snake[i].y >= PLAYGROUND_UPPER_BOUND_Y) {
			snake[i].y = PLAYGROUND_LOWER_BOUND_Y;
		}
		else if (snake[i].y < PLAYGROUND_LOWER_BOUND_Y) {
			snake[i].y = PLAYGROUND_UPPER_BOUND_Y - SPRITE_SIZE;
		}

		//Sprite changing logic
		if ((snake[i - 1].lastMoveDir != snake[i - 1].currentDir)) {
			//Body corner orientations
			if (snake[i].currentDir == SNAKE_UP && snake[i-1].currentDir == SNAKE_LEFT) snake[i].sprite = &snakecorner1Sprite; // OK
			else if (snake[i].currentDir == SNAKE_UP && snake[i-1].currentDir == SNAKE_RIGHT) snake[i].sprite = &snakecorner8Sprite; // OK
			
			else if (snake[i].currentDir == SNAKE_DOWN && snake[i-1].currentDir == SNAKE_RIGHT) snake[i].sprite = &snakecorner5Sprite; // OK
			else if (snake[i].currentDir == SNAKE_DOWN && snake[i-1].currentDir == SNAKE_LEFT) snake[i].sprite = &snakecorner6Sprite; // OK
			
			else if (snake[i].currentDir == SNAKE_LEFT && snake[i-1].currentDir == SNAKE_DOWN) snake[i].sprite = &snakecorner3Sprite; // OK
			else if (snake[i].currentDir == SNAKE_LEFT && snake[i-1].currentDir == SNAKE_UP) snake[i].sprite = &snakecorner7Sprite; //OK
			
			else if (snake[i].currentDir == SNAKE_RIGHT && snake[i-1].currentDir == SNAKE_UP) snake[i].sprite = &snakecorner2Sprite; // OK
			else if (snake[i].currentDir == SNAKE_RIGHT && snake[i-1].currentDir == SNAKE_DOWN) snake[i].sprite = &snakecorner8Sprite; //OK
		}
		else {
			//If no turns are done.
				if (snake[i].currentDir == SNAKE_LEFT) snake[i].sprite = &snakebodyflippedSprite;	
				else if (snake[i].currentDir == SNAKE_RIGHT) snake[i].sprite = &snakebodySprite;
				else if (snake[i].currentDir == SNAKE_DOWN && snake[i].lastMoveDir == SNAKE_LEFT) snake[i].sprite = &snakebodyflippedSprite;
				else if (snake[i].currentDir == SNAKE_DOWN && snake[i].lastMoveDir == SNAKE_RIGHT) snake[i].sprite = &snakebodySprite;
				else if (snake[i].currentDir == SNAKE_UP && snake[i].lastMoveDir == SNAKE_LEFT) snake[i].sprite = &snakebodyflippedSprite;
				else if (snake[i].currentDir == SNAKE_UP && snake[i].lastMoveDir == SNAKE_RIGHT) snake[i].sprite = &snakebodySprite;
		}
	}
	moved = 0;
}

//Taken from Tetris, modified to fit SNAKE.
void SNAKEPrintScore(uint16_t value)
{
	uint16_t decimalI=1;
	uint16_t valueTemp = value;
	uint8_t decimals = 0;
	char buffer[6];
	//Print Score starting from 25 px from left
	strcpy_P(buffer, scoreText);
	LCDbufferCounter = 25;
	LCDPrintString(buffer);
	LCDbufferCounter += 5;

	//Print score 0
	if (valueTemp == 0) {
		LCDPrintChar('0');
	}

	//Do magic
	while(valueTemp > 0)
	{
		valueTemp/=10;
		decimals++;
	}
	decimals--;
	for(uint8_t iTemp=0;iTemp<decimals;iTemp++)
	{
		decimalI*=10;
	}

	for(;decimalI >=1;decimalI/=10)
	{
		LCDPrintChar('0' + ((value/decimalI)%10));
	}
}