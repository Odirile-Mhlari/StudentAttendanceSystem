//---------------------------------------------------------------------------

#ifndef StudAttendanceHistoryH
#define StudAttendanceHistoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include "ccalendr.h"
#include <Vcl.Samples.Calendar.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.CheckLst.hpp>
//---------------------------------------------------------------------------
class TfrmStudAttendanceHisrory : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TStatusBar *StatusBar1;
	TPanel *Panel1;
	TLabel *Label1;
	TComboBox *ComboBoxSubject;
	TDateTimePicker *DateTimePickerStartD;
	TLabel *Label2;
	TRadioGroup *RadioGroupDefault;
	TPanel *Panel2;
	TDBGrid *DBGridTodaySubjs;
	TCheckListBox *CheckListBoxPresAbs;
	TLabel *Label3;
	TButton *btnCustomHist;
	TStringGrid *StringGrid1;
	TLabel *Label4;
	TLabel *Label5;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall RadioGroupDefaultClick(TObject *Sender);
	void __fastcall ComboBoxSubjectChange(TObject *Sender);
	void __fastcall DateTimePickerStartDChange(TObject *Sender);
	void __fastcall btnCustomHistClick(TObject *Sender);
	void __fastcall CheckListBoxPresAbsExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmStudAttendanceHisrory(TComponent* Owner);
	bool subjSelected;
	bool dateSelected;
	bool presAbsChecked;

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmStudAttendanceHisrory *frmStudAttendanceHisrory;
//---------------------------------------------------------------------------
#endif
