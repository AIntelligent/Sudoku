/*
 * HEKSUDOKU.CPP
 *
 * 10/04/2024
 *    o Bazý kiþisel bilgiler güncellendi.
 *    o Borland C++Builder 6.0 ile yeniden derlendi.
 * 23/04/2006
 *    o Bazý düzeltmeler eklendi.
 *    o Sudoku harita üreteci rastgele sayý üreteç deðeri deðiþtirildi.
 *    o Sol dikey baþlýk çubuðu rengi ve durum çubuðu renkleri deðiþtirildi.
 *    o Son þekli verildi.
 * 04/04/2006
 *    o Üretildi
 *
 * Hakan Emre KARTAL tarafýndan Ýskenderun/HATAY'da 04/04/2006 tarihinde
 * Borland C++Builder 6.0 ile geliþtirildi.
 *
 * Written by Hakan Emre KARTAL in Iskenderun/HATAY on 04/04/2006,
 * developed with Borland C++Builder 6.0
 *
 * Hakan Emre KARTAL
 * hek@nula.com.tr
 */
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("bslng.cpp", formHEKsudoku);
USEFORM("About.cpp", AboutBox);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
   try
   {
      Application->Initialize();
      Application->CreateForm(__classid(TformHEKsudoku), &formHEKsudoku);
      Application->CreateForm(__classid(TAboutBox), &AboutBox);
      Application->Run();
   }
   catch (Exception &exception)
   {
      Application->ShowException(&exception);
   }
   catch (...)
   {
      try
      {
         throw Exception("");
      }
      catch (Exception &exception)
      {
         Application->ShowException(&exception);
      }
   }

   return 0;
}
//---------------------------------------------------------------------------
