//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StudTimeTable.h"
#include "Home.h"
#include "DMStudentDB.h"
#include "System.SysUtils.hpp"
#include "System.DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTimeTable *frmTimeTable;
//---------------------------------------------------------------------------
__fastcall TfrmTimeTable::TfrmTimeTable(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmTimeTable::FormShow(TObject *Sender)
{



	DataModuleStudentDB->ADODataSetAtend->Active=0;
	DataModuleStudentDB->ADODataSetAtend->CommandText="SELECT C.SubjectCode,Time,c.Day FROM Class C,Student_Subject SB where SB.StudentNumber=:studNo AND SB.SubjectCode=C.SubjectCode ORDER BY TIME";// AND ClassID=:cID AND ClassDate=:cDate";
	DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("studNo")->Value=frmHome->edtNumber->Text.Trim();
  	DataModuleStudentDB->DataSourceAtend->DataSet=DataModuleStudentDB->ADODataSetAtend;
	DataModuleStudentDB->ADODataSetAtend->Active=1;

	 StringGrid1->ColCount=6;

	StringGrid1->Cells[0][0]="Time\\Day";
	StringGrid1->Cells[1][0]="Monday";
	StringGrid1->Cells[2][0]="Tuesday";
	StringGrid1->Cells[3][0]="Wednesday";
	StringGrid1->Cells[4][0]="Thursday";
	StringGrid1->Cells[5][0]="Friday";

	int rowC=1;
	int colC=1;
	while(!DataModuleStudentDB->ADODataSetAtend->Eof){

		TTime subT=StrToDateTime(DataModuleStudentDB->ADODataSetAtend->FieldByName("Time")->AsString.Trim());
		StringGrid1->Cells[0][rowC]=TimeToStr(subT);
		String subD=DataModuleStudentDB->ADODataSetAtend->FieldByName("Day")->AsString.Trim();


		if(subD=="Monday")
		StringGrid1->Cells[1][rowC]=DataModuleStudentDB->ADODataSetAtend->FieldByName("SubjectCode")->AsString.Trim();
		else
			if(subD=="Tuesday")
		StringGrid1->Cells[2][rowC]=DataModuleStudentDB->ADODataSetAtend->FieldByName("SubjectCode")->AsString.Trim();
		else
			if(subD=="Wednesday")
		StringGrid1->Cells[3][rowC]=DataModuleStudentDB->ADODataSetAtend->FieldByName("SubjectCode")->AsString.Trim();
		else
			if(subD=="Thursday")
		StringGrid1->Cells[4][rowC]=DataModuleStudentDB->ADODataSetAtend->FieldByName("SubjectCode")->AsString.Trim();
		else
			StringGrid1->Cells[5][rowC]=DataModuleStudentDB->ADODataSetAtend->FieldByName("SubjectCode")->AsString.Trim();


		rowC++;
		DataModuleStudentDB->ADODataSetAtend->Next();
	}
	StringGrid1->RowCount=DataModuleStudentDB->ADODataSetAtend->RecordCount+1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmTimeTable::FormResize(TObject *Sender)
{

	StringGrid1->DefaultColWidth=113;
	StringGrid1->DefaultRowHeight=50;
}
//---------------------------------------------------------------------------
