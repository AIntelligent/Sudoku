/*
 * HEKTOOLS.CPP
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
#ifndef __HEKTools_header_file

#define __HEKTools_header_file

#include <Windows.hpp>
#include <Graphics.hpp>

extern int  __fastcall __hek_GetTextWidth(TCanvas *, LPCSTR);
extern void __fastcall __hek_DrawText(TCanvas *, LPCSTR, RECT &, TColor, TColor, int);

#endif
 