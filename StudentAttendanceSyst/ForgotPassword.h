//---------------------------------------------------------------------------

#ifndef ForgotPasswordH
#define ForgotPasswordH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmForgotPasswork : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *lblUserType;
	TLabel *Label2;
	TEdit *edtNewPassword;
	TLabel *Label3;
	TEdit *edtUserID;
	TEdit *edtMatchPassword;
	TButton *btnGoBackToLogin;
	TButton *btnSaveChanges;
	TLabel *lblPasswordNoMatch;
	TLabel *Label1;
	TEdit *edtIDNumber;
	TLabel *lblIncorrectIDNumber;
	TLabel *lblGoBacToLogin;
	TLabel *lblInvalidUserID;
	TPanel *Panel3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall lblGoBacToLoginClick(TObject *Sender);
	void __fastcall btnGoBackToLoginClick(TObject *Sender);
	void __fastcall edtIDNumberExit(TObject *Sender);
	void __fastcall btnSaveChangesClick(TObject *Sender);
	void __fastcall edtUserIDExit(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall edtUserIDEnter(TObject *Sender);
	void __fastcall edtIDNumberEnter(TObject *Sender);
	void __fastcall edtMatchPasswordExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmForgotPasswork(TComponent* Owner);
	bool validIDNumber;
	bool validUserID;
	bool paaswordMtch;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmForgotPasswork *frmForgotPasswork;
//---------------------------------------------------------------------------
#endif
