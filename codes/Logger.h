//---------------------------------------------------------------------------

#ifndef LoggerH
#define LoggerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TformLogger : public TForm
   {
__published:	// IDE-managed Components
   TButton *Button_Save;
   TButton *Button_Close;
   TSaveDialog *SaveDialog;
   TTreeView *TreeView;
private:	// User declarations
public:		// User declarations
   __fastcall TformLogger(TComponent* Owner);
   };
//---------------------------------------------------------------------------
extern PACKAGE TformLogger *formLogger;
//---------------------------------------------------------------------------
#endif
