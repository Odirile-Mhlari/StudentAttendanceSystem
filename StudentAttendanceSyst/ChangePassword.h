//---------------------------------------------------------------------------

#ifndef ChangePasswordH
#define ChangePasswordH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmChangePassword : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TLabel *lblUserType;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *lblPasswordNoMatch;
	TLabel *Label1;
	TLabel *lblIncorrectIDNumber;
	TLabel *lblInvalidUserID;
	TEdit *edtNewPassword;
	TEdit *edtUserID;
	TEdit *edtMatchPassword;
	TButton *btnGoBackToLogin;
	TButton *btnSaveChanges;
	TEdit *edtIDNumber;
	TPanel *Panel1;
	TPanel *Panel3;
	TLabel *Label4;
	TEdit *edtOldPass;
	TLabel *lblInvalidOldPass;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall btnGoBackToLoginClick(TObject *Sender);
	void __fastcall btnSaveChangesClick(TObject *Sender);
	void __fastcall edtUserIDEnter(TObject *Sender);
	void __fastcall edtUserIDExit(TObject *Sender);
	void __fastcall edtIDNumberEnter(TObject *Sender);
	void __fastcall edtIDNumberExit(TObject *Sender);
	void __fastcall edtMatchPasswordExit(TObject *Sender);
	void __fastcall edtNewPasswordEnter(TObject *Sender);
	void __fastcall edtMatchPasswordEnter(TObject *Sender);
	void __fastcall edtOldPassEnter(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
	__fastcall TfrmChangePassword(TComponent* Owner);
	bool validIDNumber;
	bool validUserID;
	bool paaswordMtch;
	String oldPassword;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmChangePassword *frmChangePassword;
//---------------------------------------------------------------------------
#endif
