//---------------------------------------------------------------------------

#ifndef StudRegisterH
#define StudRegisterH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmStudTimeTable : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelForm;
	TPanel *Panel2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *edtSubjName;
	TEdit *edtStartTime;
	TEdit *edtLectName;
	TEdit *edtVenue;
	TEdit *edtOfficeNum;
	TEdit *edtEmail;
	TEdit *edtTellNo;
	TRadioGroup *RadioGroupAcknLadge;
	TRichEdit *RichEditConcept;
	TComboBox *ComboBoxRating;
	TStatusBar *StatusBar1;
	TPanel *PanelTodayClasses;
	TLabel *Label13;
	TStringGrid *StringGridTodaySubjs;
	TPanel *Panel1;
	TTimer *Timer1;
	TLabel *lblRatin;
	TLabel *lblAckn;
	TRichEdit *RichEditComment;
	TLabel *Label14;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ComboBoxRatingChange(TObject *Sender);
	void __fastcall RadioGroupAcknLadgeClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmStudTimeTable(TComponent* Owner);
			String studNumber;
	String subjCode;
	String startTime;
	String lessConcept;
	String classDay;

	bool ackn;
	bool rating;
	bool firtSignIn;

	String globStudID;
	int golbClassID;
	TDateTime  globSubjTime;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmStudTimeTable *frmStudTimeTable;
//---------------------------------------------------------------------------
#endif
