/*
 * FONT9x9.H
 * Hakan Emre KARTAL
 * hek@nula.com.tr
 * Iskenderun/HATAY
 *
 * 04/04/2006
 *    o Üretildi
 * 23/04/2006
 *    o Bazý düzeltmeler eklendi.
 *    o Sudoku harita üreteci rastgele sayý üreteç deðeri deðiþtirildi.
 *    o Sol dikey baþlýk çubuðu rengi ve durum çubuðu renkleri deðiþtirildi.
 *    o Son þekli verildi.
 * 10/04/2024
 *    o Bazý kiþisel bilgiler güncellendi.
 *    o Borland C++Builder 6.0 ile yeniden derlendi.
 *
 * Written by Hakan Emre KARTAL in Iskenderun/HATAY on 04/04/2006,
 * developed for Borland C++Builder 6.0
 */
#if !defined(__Font9x9_header_file)

#define __Font9x9_header_file

#define BLOCK_CHAR            (1)
#define NULL_CHAR             (0)

#define FONT_WIDTH            (9)
#define FONT_HEIGHT           (9)
#define ENCOK_DEMOCHAR        (19)
#define FONT_LINESIZE         (FONT_WIDTH * ENCOK_DEMOCHAR)

typedef char font_t[ FONT_HEIGHT ][ FONT_LINESIZE ];

extern font_t SudokuDemoFonts;

extern void __fastcall MapMoveLeft(void);

#endif
