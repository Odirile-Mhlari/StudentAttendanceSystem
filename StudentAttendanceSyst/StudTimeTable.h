//---------------------------------------------------------------------------

#ifndef StudTimeTableH
#define StudTimeTableH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmTimeTable : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmTimeTable(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTimeTable *frmTimeTable;
//---------------------------------------------------------------------------
#endif
