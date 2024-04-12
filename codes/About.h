/*
 * ABOUT.H
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
//----------------------------------------------------------------------------
#ifndef AboutH
#define AboutH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TAboutBox : public TForm
{
__published:
	TPanel *Panel1;
	TImage *ProgramIcon;
	TLabel *ProductName;
	TLabel *Version;
	TLabel *Copyright;
	TLabel *Comments;
	TButton *OKButton;
   TLabel *Connection;
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:
public:
	virtual __fastcall TAboutBox(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TAboutBox *AboutBox;
//----------------------------------------------------------------------------
#endif    
