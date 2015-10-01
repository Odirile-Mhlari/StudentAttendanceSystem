//---------------------------------------------------------------------------

#ifndef RegisterH
#define RegisterH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmRegister : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *Label4;
	TLabel *lblTellCell;
	TLabel *lblOffice;
	TLabel *Label7;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TEdit *edtIDNum;
	TEdit *edtPhone;
	TEdit *edtOffice;
	TButton *btnRegister;
	TEdit *edtPhone1;
	TEdit *edtEmail;
	TEdit *edtPass1;
	TEdit *edtPass2;
	TLabel *lblInvalidNumber;
	TLabel *lblInvalidID;
	TLabel *lblInvalidEmail;
	TLabel *lblPassMatch;
	TEdit *edtNumber;
	TLabel *lblUserType;
	TButton *btnGoToLogin;
	TEdit *edtFirstName;
	TLabel *Label3;
	TEdit *edtLastName;
	TLabel *Label2;
	TComboBox *ComboBoxUType;
	TLabel *lblUType;
	TLabel *lblIncorrectUserTyp;
	TLabel *lblOfficeNum;
	TPanel *PanelSuccessful;
	TLabel *lblSucc2;
	TLabel *lblSucc1;
	void __fastcall btnGoToLoginClick(TObject *Sender);
	void __fastcall edtNumberEnter(TObject *Sender);
	void __fastcall edtFirstNameEnter(TObject *Sender);
	void __fastcall edtLastNameEnter(TObject *Sender);
	void __fastcall edtIDNumEnter(TObject *Sender);
	void __fastcall edtPhoneEnter(TObject *Sender);
	void __fastcall edtEmailEnter(TObject *Sender);
	void __fastcall edtPass1Enter(TObject *Sender);
	void __fastcall edtPass2Enter(TObject *Sender);
	void __fastcall edtOfficeEnter(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ComboBoxUTypeChange(TObject *Sender);
	void __fastcall edtIDNumExit(TObject *Sender);
	void __fastcall edtPass2Exit(TObject *Sender);
	void __fastcall edtEmailExit(TObject *Sender);
	void __fastcall edtOfficeExit(TObject *Sender);
	void __fastcall btnRegisterClick(TObject *Sender);
	void __fastcall edtNumberExit(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmRegister(TComponent* Owner);
	bool invalidUserID;
	bool invalidIDNumber;
	String IDNumber;
	String lectureID;
	String studentNumber;
	bool passMatch;
	bool validEmail;
	bool validOffice;
	bool registerd;

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRegister *frmRegister;
//---------------------------------------------------------------------------
#endif
