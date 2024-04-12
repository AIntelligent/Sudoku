/*
 * BSLNG.CPP
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
//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "bslng.h"
#include "sudokuapi.h"
#include "Font9x9.h"
#include "HEKTools.h"
#include <stdlib.h>

#if defined(__SUDOKULOGGER__)
#  include "Logger.h"
#endif

#include "About.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TformHEKsudoku *     formHEKsudoku = (NULL);
//---------------------------------------------------------------------------
SUDOKUMAP            Sudoku;
SUDOKUDIM            Solve;
//---------------------------------------------------------------------------
#define MAX_LEVEL (6)
const int HintCounts[ MAX_LEVEL ] = {6, 5, 4, 3, 3, 3};
const AnsiString  Seviyeler[ MAX_LEVEL ] = {"Çok Acemi", "Acemi", "Yeni Öðrenen",
                                            "Ýyi Bilen", "Usta", "Uzman"};
//---------------------------------------------------------------------------
TDateTime            StartTime = (0);
//---------------------------------------------------------------------------

__fastcall TformHEKsudoku::TformHEKsudoku(TComponent* Owner) : TForm(Owner)
{ }

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::ViewSudoku()
{
   for (int y = 0; y < SUDOKU_DIM_Y; y++)
   {
      for (int x = 0; x < SUDOKU_DIM_X; x++)
      {
         if (Sudoku.Map._Numbers[ y ][ x ])
         {
            Grid->Cells[ x ][ y ] = AnsiString(Sudoku.Map._Numbers[ y ][ x ]);
         }
         else
         {
            Grid->Cells[ x ][ y ] = "";
         }
      }
   }

   Grid->Invalidate();
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::GridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
#define START_COLOR  (clYellow)
#define STOP_COLOR   (clBlue)
#define MixColors(x) TColor((x) + (x) * (ARow) * 14)

   Grid->Canvas->Brush->Style = bsSolid;

   if (m_DemoMod)
   {
      if (SudokuDemoFonts[ ARow ][ ACol ] == BLOCK_CHAR)
      {
         Grid->Canvas->Brush->Color = MixColors( START_COLOR );
      }
      else
      {
         Grid->Canvas->Brush->Color = MixColors( STOP_COLOR );
      }

      Grid->Canvas->FillRect(Rect);

      return;
   }

   Grid->Canvas->Brush->Color = Grid->Color;
   Grid->Canvas->FillRect(Rect);

   if (State.Contains(gdSelected))
   {
      if (Sudoku.Check._Checks[ ARow ][ ACol ])
      {
         Grid->Canvas->Brush->Color = clWindow;
      }
      else
      {
         Grid->Canvas->Brush->Color = clMoneyGreen;
      }

      Grid->Canvas->Pen->Color = Grid->Canvas->Brush->Color;

      TRect _Rc = Rect;

      ::InflateRect( &_Rc, -::GetSystemMetrics( SM_CXFRAME ), -::GetSystemMetrics( SM_CYFRAME ) );

      Grid->Canvas->Ellipse( _Rc );
   }

   if (!((ACol + 1) % 3))
   {
      Grid->Canvas->Pen->Color = clRed;

      Grid->Canvas->MoveTo(Rect.right, Rect.top);
      Grid->Canvas->LineTo(Rect.right, Rect.bottom);
   }

   if (!((ARow + 1) % 3))
   {
      Grid->Canvas->Pen->Color = clRed;

      Grid->Canvas->MoveTo(Rect.left, Rect.bottom);
      Grid->Canvas->LineTo(Rect.right, Rect.bottom);
   }

   Grid->Canvas->Font = this->Font;

   bool Check = Sudoku.Check._Checks[ ARow ][ ACol ];

   if (Check)
   {
      Grid->Canvas->Font->Color = clSilver;
   }
   else
   {
      Grid->Canvas->Font->Color = clBlue;
   }

   Grid->Canvas->Brush->Style = bsClear;
   ::DrawText(Grid->Canvas->Handle, Grid->Cells[ ACol ][ ARow ].c_str(), -1, &Rect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

#undef MixColors
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::NewSudoku()
{
   //Grid->Enabled = TRUE;
   DgsGameStarted( false );

   m_ShowSolve = false;

   GameMapCreate(&Solve, &Sudoku, m_Level);

   StartTime = Time();
   //Timer->Enabled = TRUE;

   ViewSudoku();

   Grid->Col = m_LastCol = 0;
   Grid->Row = m_LastRow = 0;

   GetLastPos();

   DgsDemoMod( false );
   DgsGameStarted( true );
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::SolveSudoku()
{
   //Timer->Enabled = FALSE;

   m_ShowSolve = true;

   Sudoku.Map = Solve;
   ViewSudoku();

   //Grid->Enabled = FALSE;
   DgsGameStarted( false );
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::GridKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
   if (Key == VK_F2)
   {
      NewSudoku();
      Key = 0;
   }
   else if (Key == VK_F3)
   {
      SolveSudoku();
      Key = 0;
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::ToolButton_1Click(TObject *Sender)
{
   if (!m_GameStarted)
   {
      ::MessageBox(Handle, "Oyun henüz baþlamadý!", "Uyarý", MB_ICONEXCLAMATION | MB_OK);
      return;
   }

   if (m_DemoMod) return;

   int            y,
                  x;
   TToolButton *  T = dynamic_cast<TToolButton *>(Sender);
   TList *        error_list;
   PPOINT         p;

   y = Grid->Row;
   x = Grid->Col;

   if (Sudoku.Check._Checks[ y ][ x ])
   {
      ::MessageBeep(MB_ICONERROR);
   }
   else if ((T->Tag >= 0) && (T->Tag <= 9))
   {
      if (MapCheckInvalidValue( &Sudoku.Map, x, y, T->Tag ))
      {
         //::MessageBeep( MB_ICONERROR );

         error_list = new TList();
         __try
         {
            CreateErrorList( &Sudoku.Map, T->Tag, x, y, error_list );
            DrawErrors( error_list );

            for (y = 0; y < error_list->Count; y++)
            {
               delete error_list->Items[ y ];
            }
         }
         __finally
         {
            delete error_list;
         }
      }
      else
      {
         Sudoku.Map._Numbers[ y ][ x ] = T->Tag;
         Grid->Cells[ x ][ y ] = T->Caption;
      }
   }
   else if (T->Tag == 10)
   {
      Sudoku.Map._Numbers[ y ][ x ] = 0;
      Grid->Cells[ x ][ y ] = "";
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::TimerTimer(TObject *Sender)
{
   TDateTime T = Time();

   if (StartTime != T)
   {
      T = (T - StartTime);

      StatusBar->Panels->BeginUpdate();
      StatusBar->Panels->Items[ 3 ]->Text = T.TimeString();
      StatusBar->Panels->EndUpdate();

/*
      ApplicationEvents::OnIdle olayýna taþýndý...

      if (SudokuCheckFinal(&Sudoku))
      {
         //Timer->Enabled = FALSE;
         DgsGameStarted( false );

         if (::MessageBox(Handle, "Tebrikler kazandýnýz...\nTekrar?", "Sonuç", MB_ICONEXCLAMATION | MB_YESNO ) == IDYES)
         {
            Grid->Perform(WM_KEYDOWN, VK_F2, 0);
         }
      }
*/
   }
}


//---------------------------------------------------------------------------

static BOOL bEpostaHot = FALSE;

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::StatusBarDrawPanel(TStatusBar *StatusBar, TStatusPanel *Panel, const TRect &Rect)
{
#define Canvas StatusBar->Canvas

   RECT rect = Rect;

   Canvas->Brush->Color = clBtnFace; //clBlue;
   Canvas->Brush->Style = bsSolid;
   Canvas->FillRect( Rect );

   Canvas->Font->Color = clBtnText; //clWhite;
   Canvas->Brush->Style = bsClear;

   if (Panel->Index == 2) // E-Posta
   {
      if (bEpostaHot)
      {
         Canvas->Font->Color = clHotLight; //clRed;
         Canvas->Font->Style = Canvas->Font->Style << fsUnderline;
      }
   }
   else if (Panel->Index == 3) // 00:00:00
   {
      Canvas->Font->Color = clRed; //clAqua;
   }
   else if (Panel->Index == 4) // Yeni Öðrenen
   {
   }
   else
   {
      __hek_DrawText(Canvas, Panel->Text.c_str(), rect, /*clAqua*/ clRed, clBtnText /*clWhite*/, DT_CENTER);
      return;
   }

   Canvas->Font->Style = Canvas->Font->Style << fsBold;

   ::DrawText(Canvas->Handle, Panel->Text.c_str(), -1, &rect,
              DT_SINGLELINE | DT_VCENTER | DT_CENTER);

#undef Canvas
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::ApplicationEventsMessage(tagMSG &Msg, bool &Handled)
{
   if (Msg.message == CM_MOUSEENTER)
   {
      Caption.sprintf( TEXT("%x, %x"), Msg.wParam, Msg.lParam);
   }
   else if (Msg.message == WM_MOUSEMOVE)
   {
      POINT    pt;
      RECT     rect;
      BOOL     bInRect;

      ::SetRectEmpty(&rect);

      ::GetCursorPos(&pt);

      if (::WindowFromPoint(pt) != StatusBar->Handle)
      {
         if (bEpostaHot)
         {
            bEpostaHot = FALSE;

            ::SendMessage(StatusBar->Handle, SB_GETRECT, 2, (LPARAM)&rect);
            ::InvalidateRect(StatusBar->Handle, &rect, FALSE);
         }

         return;
      }

      ::SendMessage(StatusBar->Handle, SB_GETRECT, 2, (LPARAM)&rect);

      pt.x = LOWORD(Msg.lParam);
      pt.y = HIWORD(Msg.lParam);

      bInRect = ::PtInRect(&rect, pt);

      if (bEpostaHot != bInRect)
      {
         bEpostaHot = bInRect;
         ::InvalidateRect(StatusBar->Handle, &rect, FALSE);
      }

      if (bEpostaHot)
      {
         //Timer_EpostaAnim->Enabled = false;
         //StatusBar->Panels->Items[ 2 ]->Text = " hek@nula.com.tr";
         Screen->Cursor = crHandPoint;
      }
      else
      {
         //Timer_EpostaAnim->Enabled = true;
         Screen->Cursor = crDefault;
      }
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::StatusBarClick(TObject *Sender)
{
   RECT        rect;
   POINT       pt;
   AnsiString  string;

   ::SetRectEmpty(&rect);
   ::SendMessage(StatusBar->Handle, SB_GETRECT, 2, (LPARAM)&rect);

   if (::GetCursorPos(&pt))
   {
      pt = StatusBar->ScreenToClient(pt);

      if (::PtInRect(&rect, pt))
      {
         string.sprintf("mailto:%s", StatusBar->Panels->Items[ 2 ]->Text);
         ShellExecute(NULL, TEXT("open"), string.Trim().c_str(), NULL, NULL, SW_SHOWNORMAL);
      }
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::FormShow(TObject *Sender)
{
   DgsDemoMod( true );

   //NewSudoku();

#if defined(__SUDOKULOGGER__)
   int nWidth  = (this->Width + formLogger->Width);

   nWidth = ((Screen->Width / 2) - (nWidth / 2));

   this->Left = nWidth;
   this->Top = ((Screen->Height / 2) - (this->Height / 2));

   formLogger->Left = this->Left + this->Width + 1;
   formLogger->Top  = this->Top;

   formLogger->Show();
   formLogger->Update();
#endif
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::GridKeyPress(TObject *Sender, char &Key)
{
   if ((Key >= '1') && (Key <= '9'))
   {
      AnsiString     String;
      TToolButton    *Button;

      String.sprintf("ToolButton_%c", Key);

      for (int i = 0; i < ToolBar->ButtonCount; i++)
      {
         Button = ToolBar->Buttons[ i ];

         if (Button->Tag == int(Key - '0'))
         {
            Button->Click();
         }
      }

      Key = 0;
   }
   else if ((Key == 'C') || (Key == 'c'))
   {
      ToolButton_1Click(ToolButton_Clear);
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::GridClick(TObject *Sender)
{
   //if (m_DemoMod) return;
   if (m_GameStarted)
   {
      DgsDemoMod( false );
   }
   else if (m_DemoMod)
   {
      return;
   }

   /*
    * Hareket hangi yöne doðru oluyor
    *
    */
   int   X = Grid->Col;
   int   Y = Grid->Row;

   if (m_LastCol > X)        // Sol
   {
      for ( ; (X) && IsInvalidPoint(&Sudoku, X, Y); X--);
   }
   else if (m_LastCol < X)   // Sað
   {
      for ( ; (X < SUDOKU_DIM_X - 1) && IsInvalidPoint(&Sudoku, X, Y); X++);
   }

   if (m_LastRow > Y)        // Yukarý
   {
      for ( ; (Y) && IsInvalidPoint(&Sudoku, X, Y); Y--);
   }
   else if (m_LastRow < Y)   // Aþaðý
   {
      for ( ; (Y < SUDOKU_DIM_Y - 1) && IsInvalidPoint(&Sudoku, X, Y); Y++);
   }

   if (IsInvalidPoint(&Sudoku, X, Y))
   {
      X = m_LastCol;
   }

   if (IsInvalidPoint(&Sudoku, X, Y))
   {
      Y = m_LastRow;
   }

   if (X != Grid->Col)
   {
      Grid->Col = X;
   }

   if (Y != Grid->Row)
   {
      Grid->Row = Y;
   }

   m_LastCol = Grid->Col;
   m_LastRow = Grid->Row;
}


//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::FormCreate(TObject *Sender)
{
   GetLastPos();

   m_LastCheckedItem = mItem_SeviyeOgrenen;
   m_Level = m_LastCheckedItem->Tag;

   m_DemoMod = false;

   m_GameStarted = false;

   m_ShowSolve = false;
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::mItem_KapatClick(TObject *Sender)
{
   Application->Terminate();
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::mItem_YeniClick(TObject *Sender)
{
   NewSudoku();
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::GetLastPos()
{
   m_LastRow = m_LastCol = 0;

   while ((m_LastCol < SUDOKU_DIM_X - 1) && (Sudoku.Check._Checks[ m_LastRow ][ m_LastCol ]))
   {
      m_LastCol++;
   }

   while ((m_LastRow < SUDOKU_DIM_Y - 1) && (Sudoku.Check._Checks[ m_LastRow ][ m_LastCol ]))
   {
      m_LastRow++;
   }

   Grid->Col = m_LastCol;
   Grid->Row = m_LastRow;
}

void __fastcall TformHEKsudoku::ToolBarCustomDrawButton(TToolBar *Sender, TToolButton *Button, TCustomDrawState State, bool &DefaultDraw)
{
   if (State.Contains(cdsSelected))
   {
      Sender->Canvas->Font->Color = clRed;
   }
   else if (State.Contains(cdsHot))
   {
      Sender->Canvas->Font->Color = clBlue;
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::mItem_CozumClick(TObject *Sender)
{
   SolveSudoku();
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::mItem_SeviyeUzmanClick(TObject *Sender)
{
   TMenuItem * mItemX = dynamic_cast<TMenuItem *>(Sender);

   if (m_LastCheckedItem != mItemX)
   {
      m_LastCheckedItem->Checked = false;

         m_LastCheckedItem = mItemX;
         m_Level = mItemX->Tag;

      m_LastCheckedItem->Checked = true;

      StatusBar->Panels->BeginUpdate();
      StatusBar->Panels->Items[ 4 ]->Text = Seviyeler[ m_Level ];
      StatusBar->Panels->EndUpdate(),

      NewSudoku();
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::PaintBoxPaint(TObject *Sender)
{

#define PBX    PaintBox
#define Canvas PBX->Canvas

   LOGFONT  logFont;
   HFONT    hFont;

   Canvas->Font = PBX->Font;
   Canvas->Font->Color = clBtnText; //clWhite;
   Canvas->Brush->Color = clBtnFace; //clBlue;

   Canvas->FillRect( PBX->ClientRect );

   ::GetObject(PBX->Font->Handle, sizeof(logFont), &logFont);

   logFont.lfEscapement = +900;

   hFont = ::CreateFontIndirect(&logFont);

      Canvas->Font->Handle = hFont;
      Canvas->TextOut( ((PBX->ClientWidth - Canvas->TextHeight(this->Caption)) / 2),
                       ((PBX->ClientHeight + Canvas->TextWidth(this->Caption)) / 2), this->Caption);

   ::DeleteObject(hFont);

#undef Canvas
#undef PBX
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::DgsDemoMod(bool bDeger)
{
   if (m_DemoMod != bDeger)
   {
      m_DemoMod = bDeger;

      Timer_DemoAnim->Enabled = m_DemoMod;

      if (m_DemoMod)
      {
         Timer_DemoAnimTimer(NULL);
      }
      else
      {
         Grid->Repaint();
      }
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::Timer_DemoAnimTimer(TObject *Sender)
{
   MapMoveLeft();
   Grid->Invalidate();
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::mItem_GeriCagirClick(TObject *Sender)
{
   if (OpenDialog->Execute())
   {
      SUDOKUMAPFILEDATA smfd;

      RestoreSudokuGame( OpenDialog->FileName.c_str(), &smfd );

      Sudoku    = smfd._Sudoku;
      Solve     = smfd._Solve;

      m_LastCol = smfd._LastCol;
      m_LastRow = smfd._LastRow;

      m_Level   = smfd._Level;

      ViewSudoku();

      Grid->Col = smfd._DefCol;
      Grid->Row = smfd._DefRow;
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::mItem_KaydetClick(TObject *Sender)
{
   if (SaveDialog->Execute())
   {
      SUDOKUMAPFILEDATA smfd;

      smfd._DefCol   = Grid->Col;
      smfd._DefRow   = Grid->Row;
      smfd._Sudoku   = Sudoku;
      smfd._Solve    = Solve;
      smfd._LastCol  = m_LastCol;
      smfd._LastRow  = m_LastRow;
      smfd._Level    = m_Level;
      smfd._Time     = StrToTime( StatusBar->Panels->Items[ 3 ]->Text );

      SaveSudokuGame( SaveDialog->FileName.c_str(), &smfd );
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::DrawErrorLine(int SrcCol, int SrcRow, int DstCol, int DstRow)
{
// #define __DRAWERRORROUTE__
// #define __DRAWSOURCEERROR__
   #define __DRAWDESTERROR__

   tagRECT  SrcRect;
   tagRECT  DstRect;

   #if defined(__DRAWERRORROUTE__)
   int      s_x,
            s_y,
            d_x,
            d_y;
   #endif

   #define __center(a,b)(((b) - (a))/2)
   #define cnvs() Grid->Canvas

   GetCellRect( SrcCol, SrcRow, &SrcRect );
   GetCellRect( DstCol, DstRow, &DstRect );

   #if defined(__DRAWERRORROUTE__)
      s_x = SrcRect.left + __center(SrcRect.left, SrcRect.right);
      s_y = SrcRect.top + __center(SrcRect.top, SrcRect.bottom);

      d_x = DstRect.left + __center(DstRect.left, DstRect.right);
      d_y = DstRect.top + __center(DstRect.top, DstRect.bottom);

      cnvs()->MoveTo(s_x, s_y);
      cnvs()->LineTo(d_x, d_y);
   #endif

   #if defined(__DRAWSOURCEERROR__)
      ::InflateRect( &SrcRect, -1, -1 );

      cnvs()->Ellipse(SrcRect);

      ::InflateRect( &SrcRect, -11, -7 );

      cnvs()->MoveTo( SrcRect.left, SrcRect.top );
         cnvs()->LineTo( SrcRect.right, SrcRect.bottom );

      cnvs()->MoveTo( SrcRect.right, SrcRect.top );
         cnvs()->LineTo( SrcRect.left, SrcRect.bottom );
   #endif

   cnvs()->FillRect( DstRect );

   ::InflateRect( &DstRect, -1, -1 );

   cnvs()->Ellipse(DstRect);

   #if defined(__DRAWDESTERROR__)
      ::InflateRect( &DstRect, -11, -7 );

      cnvs()->MoveTo( DstRect.left, DstRect.top );
         cnvs()->LineTo( DstRect.right, DstRect.bottom );

      cnvs()->MoveTo( DstRect.right, DstRect.top );
         cnvs()->LineTo( DstRect.left, DstRect.bottom );
   #endif

   #undef cnvs
   #undef __center
   #undef __DRAWERRORROUTE__
}

void __fastcall TformHEKsudoku::GetCellRect(int Col, int Row, tagRECT* lpRect)
{
   lpRect->top    = (Row) * Grid->DefaultRowHeight + (Row) * int(Grid->Options.Contains(goVertLine));
   lpRect->bottom = lpRect->top + Grid->DefaultRowHeight;

   lpRect->left   = (Col) * Grid->DefaultColWidth + (Col) * int(Grid->Options.Contains(goHorzLine));
   lpRect->right  = lpRect->left + Grid->DefaultColWidth;
}

void __fastcall TformHEKsudoku::DrawErrorLines(int SrcCol, int SrcRow, TList *lpList)
{
   if (lpList)
   {
      #define _p(i) PPOINT(lpList->Items[ i ])

      for (int i = 0; i< lpList->Count; i++)
      {
         DrawErrorLine( SrcCol, SrcRow, _p(i)->x, _p(i)->y);
      }

      #undef _p
   }
}

void __fastcall TformHEKsudoku::DrawErrors(TList *lpList)
{
   #define COL()     Grid->Col
   #define ROW()     Grid->Row
   #define DELAY()   ::Sleep(75)
   #define Pen()     Grid->Canvas->Pen

   if (lpList)
   {
      Pen()->Width = 3;
      Pen()->Color = clRed;

      Pen()->Mode = pmNotXor;

      DrawErrorLines( COL(), ROW(), lpList );
      DELAY();

      DrawErrorLines( COL(), ROW(), lpList );
      DELAY();

      DrawErrorLines( COL(), ROW(), lpList );
      DELAY();

      DrawErrorLines( COL(), ROW(), lpList );
      DELAY();

      DrawErrorLines( COL(), ROW(), lpList );
      DELAY();

      DrawErrorLines( COL(), ROW(), lpList );

      Pen()->Mode = pmCopy;
   }

   #undef Pen
   #undef DELAY
   #undef ROW
   #undef COL
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::DgsGameStarted( bool bDeger )
{
   if (m_GameStarted != bDeger)
   {
      m_HintCount = HintCounts[ m_Level ] * (int)(m_GameStarted = bDeger);

      Grid->Enabled = m_GameStarted;
      Timer->Enabled = m_GameStarted;
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::ToolButton_EpostaClick(TObject *Sender)
{
   if (m_GameStarted)
   {
      DgsDemoMod( !m_DemoMod );
   }
   else if (m_DemoMod)
   {
      ::MessageBox(Handle, "Zaten gösteri modunda!", "Uyarý", MB_ICONEXCLAMATION | MB_OK);
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::mItem_HakkindaClick(TObject *Sender)
{
   AboutBox->ShowModal();
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::ApplicationEventsIdle(TObject *Sender, bool &Done)
{
   if (m_ShowSolve) return;

   if (SudokuCheckFinal(&Sudoku))
   {
      DgsGameStarted( false );

      memset( &Sudoku, 0, sizeof(Sudoku));
      memset( &Solve, 0, sizeof(Solve));

      if (::MessageBox(Handle, "Tebrikler kazandýnýz...\nTekrar?", "Sonuç", MB_ICONEXCLAMATION | MB_YESNO ) == IDYES)
      {
         Grid->Perform(WM_KEYDOWN, VK_F2, 0);
      }
      else
      {
         DgsDemoMod( true );
      }
   }
}

//---------------------------------------------------------------------------

void __fastcall TformHEKsudoku::ToolButton_IpUcuClick(TObject *Sender)
{
   if (!m_GameStarted)
   {
      ::MessageBox(Handle, "Oyun baþlamadan da ipucu istenmez ki :-P!", "Yok Daha Neler!", MB_ICONEXCLAMATION | MB_OK);
      return;
   }

   if (m_DemoMod)
   {
      ::MessageBox(Handle, "Gösteri modunda ne ipucu :-@!", "Hadi Ordan!", MB_ICONEXCLAMATION | MB_OK);
      return;
   }

   if (!Grid->Cells[ Grid->Col ][ Grid->Row ].IsEmpty())
   {
      ::MessageBox(Handle, "Ayný ipucu tekrar tekrar istenmez ki :-@!", "Hadi Ordan!", MB_ICONEXCLAMATION | MB_OK);
      return;
   }

NoHint:

   if (0 >= m_HintCount)
   {
      ::MessageBox(Handle, "Baþka ipucu hakkýnýz kalmadý!", "Yardým", MB_ICONEXCLAMATION | MB_OK );
      return;
   }

   Grid->Cells[ Grid->Col ][ Grid->Row ] = Solve._Numbers[ Grid->Col ][ Grid->Row ];

   if (--m_HintCount > 0)
   {
      ::MessageBox(Handle, (IntToStr(m_HintCount) + " Ýpucu hakkýnýz kaldý.").c_str(), "Bilgi", MB_OK );
      return;
   }

   goto NoHint;
}
//---------------------------------------------------------------------------

