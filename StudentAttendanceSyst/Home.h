//---------------------------------------------------------------------------

#ifndef HomeH
#define HomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmHome : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TButton *btnForgotPin;
	TButton *btnLogin;
	TButton *btnChangePin;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TRadioGroup *RadioGroupUserType;
	TLabel *lblUserType;
	TLabel *Label5;
	TEdit *edtNumber;
	TEdit *edtPassword;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *lblIncorrectNumber;
	TLabel *lblIncorrectPass;
	TLabel *lblIncorrectUserTyp;
	TTimer *Timer1;
	TLabel *Label4;
	TCheckBox *CheckBox1;
	TFileOpenDialog *FileOpenDialog1;
	TTimer *TimerLogin;
	TLabel *Label10;
	void __fastcall FormResize(TObject *Sender);
	void __fastcall RadioGroupUserTypeClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall edtNumberExit(TObject *Sender);
	void __fastcall Label9Click(TObject *Sender);
	void __fastcall btnLoginClick(TObject *Sender);
	void __fastcall btnForgotPinClick(TObject *Sender);
	void __fastcall btnChangePinClick(TObject *Sender);
	void __fastcall btnLoginExit(TObject *Sender);
	void __fastcall edtNumberClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall TimerLoginTimer(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfrmHome(TComponent* Owner);
	bool invalidUserID;
	int countLogin;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmHome *frmHome;
//---------------------------------------------------------------------------
#endif
