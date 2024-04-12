/*
 * FONT9x9.H
 *
 * 10/04/2024
 *    o Baz� ki�isel bilgiler g�ncellendi.
 *    o Borland C++Builder 6.0 ile yeniden derlendi.
 * 23/04/2006
 *    o Baz� d�zeltmeler eklendi.
 *    o Sudoku harita �reteci rastgele say� �rete� de�eri de�i�tirildi.
 *    o Sol dikey ba�l�k �ubu�u rengi ve durum �ubu�u renkleri de�i�tirildi.
 *    o Son �ekli verildi.
 * 04/04/2006
 *    o �retildi
 *
 * Hakan Emre KARTAL taraf�ndan �skenderun/HATAY'da 04/04/2006 tarihinde
 * Borland C++Builder 6.0 ile geli�tirildi.
 *
 * Written by Hakan Emre KARTAL in Iskenderun/HATAY on 04/04/2006,
 * developed with Borland C++Builder 6.0
 *
 * Hakan Emre KARTAL
 * hek@nula.com.tr
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
