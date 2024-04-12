//---------------------------------------------------------------------------
// 12-04-24-12-00:HEK
//---------------------------------------------------------------------------
#ifndef __HEKUtils_H
#define __HEKUtils_H

#include <Windows.hpp>
#include <Graphics.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>

class TItem : TComponent
{
private:
   AnsiString     m_strText;
   int            m_iWidth,
                  m_iIndex;
   TColor         m_clBackground,
                  m_clForeground;
   TFont          *m_objFont;

private:

   void __fastcall SetText( const AnsiString inValue )
   {
      if (m_strText != inValue)
      {
         m_strText = inValue;
         reinterpret_cast<TGraphicControl*>(Owner)->Invalidate();
      }
   }

   TRect GetClientRect()
   {
      TRect \
         l_varResult = reinterpret_cast<TGraphicControl *>(Owner)->ClientRect;
   }

public:
   __fastcall TItem( TComponent *inOwner ) : TComponent( inOwner ), \
        m_strText(""), \
        m_iWidth(0), \
        m_iIndex(-1), \
        m_clBackground(clBlue), \
        m_clForeground(clWhite), \
        m_objFont(NULL)
   {
      for (int i = 0; i < inOwner->ComponentCount; i++)
      {
         if (inOwner->Components[ i ] == this)
         {
            m_iIndex = i;
            break;
         }
      }
   }

   void Draw()
   {
   }

   __property TRect ClientRect = { read = GetClientRect; }
   __property AnsiString Text = { read = m_strText, write = SetText };
};

class TNewStatusBar : TGraphicControl
{
private:
   TBitmap m_objScene;
   TFont *m_objFont;
public:
   __fastcall TNewStatusBar( TComponent *inOwner ) \
      : TGraphicControl( inOwner ), \
        m_objScene(new TBitmap()), \
        m_objFont(new TFont())
   {
   }
};

//---------------------------------------------------------------------------
extern \
void __fastcall \
   DoDrawVertTitle( \
         AnsiString inText, \
         TCanvas *inCanvas, \
         const TRect inClientRect \
      );
//---------------------------------------------------------------------------
#endif
 