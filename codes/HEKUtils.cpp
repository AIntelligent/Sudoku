//---------------------------------------------------------------------------


#pragma hdrstop

#include "HEKUtils.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void __fastcall \
   DoDrawVertTitle( \
         AnsiString inText, \
         TCanvas *inCanvas, \
         const TRect inClientRect \
      )
{
   LOGFONT l_varLogFont;
   HFONT l_hVertFont;
   int l_iTextWidth = inCanvas->TextWidth( inText );

   inCanvas->Brush->Color = clBlue;
   inCanvas->FillRect( inClientRect );

   ::GetObject( inCanvas->Font->Handle, sizeof(LOGFONT), &l_varLogFont );

   l_varLogFont.lfEscapement = 900;
   l_hVertFont = ::CreateFontIndirect( &l_varLogFont );

   inCanvas->Font->Handle = l_hVertFont;
   inCanvas->TextOut( -5, (inClientRect.Height() + l_iTextWidth) / 2, inText );

   ::DeleteObject( l_hVertFont );
}
