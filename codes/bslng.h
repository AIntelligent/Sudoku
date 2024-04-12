/*
 * BSLNG.H
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

#if !defined(__bslng_header_file)

#define __bslng_header_file

//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <AppEvnts.hpp>
#include <Menus.hpp>
#include <ImgList.hpp>
#include <Dialogs.hpp>

//---------------------------------------------------------------------------

class TformHEKsudoku : public TForm
   {
__published:
   TStringGrid *        Grid;
   TToolBar *           ToolBar;
   TToolButton *        ToolButton_1;
   TToolButton *        ToolButton_2;
   TToolButton *        ToolButton_3;
   TToolButton *        ToolButton_4;
   TToolButton *        ToolButton_5;
   TToolButton *        ToolButton_6;
   TToolButton *        ToolButton_7;
   TToolButton *        ToolButton_8;
   TToolButton *        ToolButton_9;
   TToolButton *        Separator_1;
   TToolButton *        ToolButton_Clear;
   TTimer *             Timer;
   TToolButton *        Separator_2;
   TStatusBar *         StatusBar;
   TApplicationEvents * ApplicationEvents;
   TToolButton *        ToolButton_Eposta;
   TMainMenu *          MainMenu;
   TMenuItem *          mItem_Oyun;
   TMenuItem *          mItem_Hakkinda;
   TMenuItem *          mItem_Yeni;
   TMenuItem *          mItem_Cozum;
   TMenuItem *          mItem_Derece;
   TMenuItem *          mItem_Bos_1;
   TMenuItem *          mItem_Kapat;
   TTimer *Timer_DemoAnim;
   TMenuItem *          mItem_Seviyeler;
   TMenuItem *          mItem_SeviyeCokAcemi;
   TMenuItem *          mItem_SeviyeAcemi;
   TMenuItem *          mItem_SeviyeOgrenen;
   TMenuItem *          mItem_SeviyeBilen;
   TMenuItem *          mItem_SeviyeUsta;
   TMenuItem *          mItem_SeviyeUzman;
   TPaintBox *          PaintBox;
   TBevel *             Bevel;
   TMenuItem *mItem_Kaydet;
   TMenuItem *mItem_GeriCagir;
   TOpenDialog *OpenDialog;
   TSaveDialog *SaveDialog;
   TToolButton *Separator_3;
   TToolButton *ToolButton_IpUcu;
   void __fastcall GridDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
   void __fastcall GridKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
   void __fastcall ToolButton_1Click(TObject *Sender);
   void __fastcall TimerTimer(TObject *Sender);
   void __fastcall StatusBarDrawPanel(TStatusBar *StatusBar, TStatusPanel *Panel, const TRect &Rect);
   void __fastcall ApplicationEventsMessage(tagMSG &Msg, bool &Handled);
   void __fastcall StatusBarClick(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall GridKeyPress(TObject *Sender, char &Key);
   void __fastcall GridClick(TObject *Sender);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall mItem_KapatClick(TObject *Sender);
   void __fastcall mItem_YeniClick(TObject *Sender);
   void __fastcall ToolBarCustomDrawButton(TToolBar *Sender, TToolButton *Button, TCustomDrawState State, bool &DefaultDraw);
   void __fastcall mItem_CozumClick(TObject *Sender);
   void __fastcall Timer_DemoAnimTimer(TObject *Sender);
   void __fastcall mItem_SeviyeUzmanClick(TObject *Sender);
   void __fastcall PaintBoxPaint(TObject *Sender);
   void __fastcall mItem_GeriCagirClick(TObject *Sender);
   void __fastcall mItem_KaydetClick(TObject *Sender);
   void __fastcall ToolButton_EpostaClick(TObject *Sender);
   void __fastcall mItem_HakkindaClick(TObject *Sender);
   void __fastcall ApplicationEventsIdle(TObject *Sender, bool &Done);
   void __fastcall ToolButton_IpUcuClick(TObject *Sender);
private:	// User declarations
   void __fastcall ViewSudoku();
   void __fastcall NewSudoku();
   void __fastcall SolveSudoku();
   void __fastcall GetLastPos();
private:
   int         m_LastRow;
   int         m_LastCol;
   int         m_Level;
   TMenuItem * m_LastCheckedItem;
   bool        m_DemoMod;
   bool        m_GameStarted;
   int         m_HintCount;
   bool        m_ShowSolve;
   void __fastcall DgsDemoMod(bool bDeger);
   void __fastcall DgsGameStarted( bool bDeger );
   void __fastcall DrawErrorLine(int SrcCol, int SrcRow, int DstCol, int DstRow);
   void __fastcall GetCellRect(int Col, int Row, tagRECT* lpRect);
   void __fastcall DrawErrors(TList *lpList);
   void __fastcall DrawErrorLines(int SrcCol, int SrcRow, TList *lpList);
public:		// User declarations
   __fastcall TformHEKsudoku(TComponent* Owner);
   };
//---------------------------------------------------------------------------
extern PACKAGE TformHEKsudoku *formHEKsudoku;
//---------------------------------------------------------------------------
#endif
