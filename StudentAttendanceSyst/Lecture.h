//---------------------------------------------------------------------------

#ifndef LectureH
#define LectureH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmLecture : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel3;
	TButton *btnMarkRegister;
	TButton *btnViewRegister;
	TButton *btnViewTimeTable;
private:	// User declarations
public:		// User declarations
	__fastcall TfrmLecture(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLecture *frmLecture;
//---------------------------------------------------------------------------
#endif
