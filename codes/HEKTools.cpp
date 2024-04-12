/*
 * HEKTOOLS.H
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
#pragma hdrstop

#include "HEKTools.h"

#pragma package(smart_init)

int __fastcall __hek_GetTextWidth(TCanvas *lpCanvas, LPCSTR lpString)
{
   int   Result = 0;

   for (int i = 0; lpString[ i ]; i++)
   {
      if (lpString[ i ] == '~')
      {
         continue;
      }

      lpCanvas->Font->Style = lpCanvas->Font->Style << fsBold;
      Result += lpCanvas->TextWidth(lpString[ i ]);
      lpCanvas->Font->Style = lpCanvas->Font->Style >> fsBold;
   }

   return(int)Result;
}

void __fastcall __hek_DrawText(TCanvas *lpCanvas, LPCSTR lpString, RECT &Rect, TColor cHot, TColor cText, int dtFlag)
{
   if ((&lpCanvas) && (lpString))
   {
      int   step_x = 0;
      int   _y;
      int   L_string = ::lstrlen(lpString);
      char  Ch;

      lpCanvas->Font->Color = cText;

      step_x = Rect.left + 3;

      if (dtFlag & DT_CENTER)
      {
         step_x = Rect.left + ((Rect.right - Rect.left) / 2 - __hek_GetTextWidth(lpCanvas, lpString) / 2);
      }
      else if (dtFlag & DT_RIGHT)
      {
         step_x = Rect.right - (__hek_GetTextWidth(lpCanvas, lpString) + 5);
      }

      _y = Rect.top + ((Rect.bottom - Rect.top) / 2 - lpCanvas->TextHeight(lpString) / 2);

      for (int L = 0; L < L_string; L++)
      {
         Ch = lpString[ L ];

         if (Ch == '~')
         {
            if (lpCanvas->Font->Color == cHot)
            {
               lpCanvas->Font->Style = lpCanvas->Font->Style >> fsBold;
               lpCanvas->Font->Color = cText;
            }
            else
            {
               lpCanvas->Font->Style = lpCanvas->Font->Style << fsBold;
               lpCanvas->Font->Color = cHot;
            }

            continue;
         }

         lpCanvas->TextOut(step_x, _y, Ch);

         step_x += lpCanvas->TextWidth(Ch);
      }
   }
}
