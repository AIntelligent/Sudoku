/*
 * HEKTOOLS.CPP
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
#ifndef __HEKTools_header_file

#define __HEKTools_header_file

#include <Windows.hpp>
#include <Graphics.hpp>

extern int  __fastcall __hek_GetTextWidth(TCanvas *, LPCSTR);
extern void __fastcall __hek_DrawText(TCanvas *, LPCSTR, RECT &, TColor, TColor, int);

#endif
 