//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StudAttendanceHistory.h"
#include "Home.h"
#include "DMStudentDB.h"
#include "System.SysUtils.hpp"
#include "System.DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ccalendr"
#pragma resource "*.dfm"
TfrmStudAttendanceHisrory *frmStudAttendanceHisrory;
//---------------------------------------------------------------------------
__fastcall TfrmStudAttendanceHisrory::TfrmStudAttendanceHisrory(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmStudAttendanceHisrory::FormShow(TObject *Sender)
{

	subjSelected=0;
	dateSelected=0;
	presAbsChecked=0;

	RadioGroupDefault->ItemIndex=0;

	//configuren stringgrid1
	StringGrid1->Cells[0][0]="Subject Code";
	StringGrid1->Cells[1][0]="Days Present";
	StringGrid1->Cells[2][0]="Days Absent";
	StringGrid1->Cells[3][0]="Total Classes";


   //FILL StringGrid1 with summarised attendance per subject
	//-------------------------------------------------------

	DataModuleStudentDB->ADODataSetAtend->Active=0;
	DataModuleStudentDB->ADODataSetAtend->CommandText="SELECT SubjectCode "
	" From student_subject where studentNumber=:studN ORDER BY SubjectCode";
	DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("studN")->Value=frmHome->edtNumber->Text.Trim();
	DataModuleStudentDB->ADODataSetAtend->Active=1;
	 int abs;
	 int pres;
	 int tot;
	 int row=1;
	int numSubjts=DataModuleStudentDB->ADODataSetAtend->RecordCount;
	StringGrid1->RowCount=numSubjts+1;

	while(!DataModuleStudentDB->ADODataSetAtend->Eof){

		String sCode=DataModuleStudentDB->ADODataSetAtend->Fields->FieldByNumber(1)->AsString.Trim();
		StringGrid1->Cells[0][row]=sCode ;
		//get presents

		DataModuleStudentDB->ADODataSetAttHist->Active=0;
		DataModuleStudentDB->ADODataSetAttHist->CommandText="SELECT SubjectCode,COUNT(SubjectCode)"
		" From Attendance A,Class C "
		" group by SubjectCode,A.ClassID,C.ClassID,Status,studentNumber "
		" having studentNumber=:studN "
		" AND A.ClassID=C.ClassID "
		" AND SubjectCode = :sbCode "
		" AND Status='Present' ";
		DataModuleStudentDB->ADODataSetAttHist->Parameters->ParamByName("studN")->Value=frmHome->edtNumber->Text.Trim();
		DataModuleStudentDB->ADODataSetAttHist->Parameters->ParamByName("sbCode")->Value=sCode;
		DataModuleStudentDB->ADODataSetAttHist->Active=1;

		pres=DataModuleStudentDB->ADODataSetAttHist->Fields->FieldByNumber(2)->AsInteger;
		StringGrid1->Cells[1][row]=IntToStr(pres);
		//get absents
		DataModuleStudentDB->ADODataSetAttHist->Active=0;
		DataModuleStudentDB->ADODataSetAttHist->CommandText="SELECT SubjectCode,COUNT(SubjectCode)"
		" From Attendance A,Class C "
		" group by SubjectCode,A.ClassID,C.ClassID,Status,studentNumber "
		" having studentNumber=:studN "
		" AND A.ClassID=C.ClassID "
		" AND SubjectCode = :sbCode "
		" AND Status='Absent' ";
		DataModuleStudentDB->ADODataSetAttHist->Parameters->ParamByName("studN")->Value=frmHome->edtNumber->Text.Trim();
		DataModuleStudentDB->ADODataSetAttHist->Parameters->ParamByName("sbCode")->Value=sCode;
		DataModuleStudentDB->ADODataSetAttHist->Active=1;


		abs=DataModuleStudentDB->ADODataSetAttHist->Fields->FieldByNumber(2)->AsInteger;
		StringGrid1->Cells[2][row]=IntToStr(abs);
		//calc total
		tot=abs+pres;
		StringGrid1->Cells[3][row]=IntToStr(tot);
		DataModuleStudentDB->ADODataSetAtend->Next();
		row++;

	}
	 StringGrid1->ColCount=4;
	 StringGrid1->DefaultColWidth=72;

   //----------------------------------------------------------

	DataModuleStudentDB->ADODataSetSubjClass->Active=0;
	DataModuleStudentDB->ADODataSetSubjClass->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
	DataModuleStudentDB->ADODataSetSubjClass->CommandText="SELECT S.SubjectCode ,SubjectDescription FROM Subject S,Student_Subject SS"
	 " WHERE StudentNumber=:studNum AND Cancelled='No' AND S.SubjectCode=SS.SubjectCode ORDER BY S.SubjectCode ";
	DataModuleStudentDB->ADODataSetSubjClass-> Parameters->ParamByName("studNum")->Value=frmHome->edtNumber->Text.Trim();
	DataModuleStudentDB->ADODataSetSubjClass->Active=1;

	ComboBoxSubject->Clear();
	for(int c=0;c<DataModuleStudentDB->ADODataSetSubjClass->RecordCount;c++){
		DataModuleStudentDB->ADODataSetSubjClass->RecNo=c+1;
		String subjCode=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("SubjectCode")->AsString.Trim();
		String subjDesc=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("SubjectDescription")->AsString.Trim();
		subjCode=subjCode+"->"+subjDesc.Trim();
		ComboBoxSubject->Items->Add(subjCode);

	}


	DataModuleStudentDB->ADODataSetAtend->Active=0;
	DataModuleStudentDB->ADODataSetAtend->CommandText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND A.classid=CL.classid AND A.classid=C.classid";// AND ClassID=:cID AND ClassDate=:cDate";
	DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("studN")->Value=frmHome->edtNumber->Text.Trim();
   //	DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("cID")->Value=StrToInt(DataModuleStudentDB->ADODataSetSubjClass->FieldByName("C.ClassID")->AsString);
   //	DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("cDate")->Value=FormatDateTime("yyyy-mm-dd",Now());
	DataModuleStudentDB->DataSourceAtend->DataSet=DataModuleStudentDB->ADODataSetAtend;
	DataModuleStudentDB->ADODataSetAtend->Active=1;

	DBGridTodaySubjs->DataSource=DataModuleStudentDB->DataSourceAtend;
	/*DBGridTodaySubjs->Columns->operator [](0)->Width=100;
	DBGridTodaySubjs->Columns->operator [](1)->Width=100;
	DBGridTodaySubjs->Columns->operator [](2)->Width=150;
	DBGridTodaySubjs->Columns->operator [](3)->Width=300;*/

   //	DBGridTodaySubjs->Columns->operator [](0)->  Title="Subject Code";


			 /*
			int counter=0;
			StringGridTodaySubjs->DefaultColWidth=146;

			StringGridTodaySubjs->ColCount=4;
			StringGridTodaySubjs->RowCount=1;

			//StudentNumber,ClassID,ClassID ,Time,AttendanceDate,ClassDate

		   /*	StringGridTodaySubjs->Cells[0][0]="Subject Code";
			StringGridTodaySubjs->Cells[1][0]="Status";
			StringGridTodaySubjs->Cells[2][0]="Time";
		   //	StringGridTodaySubjs->Cells[3][0]="Day";
			StringGridTodaySubjs->Cells[3][0]="Concept";
			//StringGridTodaySubjs->Cells[4][0]="Acknowlegment";
			//StringGridTodaySubjs->Cells[3][0]="Rating";


			// ShowMessage(IntToStr(DataModuleStudentDB->ADODataSetSubjClass->FieldCount));

			int row=1;


			while(!DataModuleStudentDB->ADODataSetAtend->Eof){



			StringGridTodaySubjs->Cells[1][row]=DataModuleStudentDB->ADODataSetAtend->Fields->FieldByNumber(3)->AsString;
			StringGridTodaySubjs->Cells[3][row]=DataModuleStudentDB->ADODataSetAtend->Fields->FieldByName("Concept")->AsString;
			StringGridTodaySubjs->Cells[2][row]=DataModuleStudentDB->ADODataSetAtend->FieldByName("A.Time")->AsString;
			StringGridTodaySubjs->Cells[0][row]=DataModuleStudentDB->ADODataSetAtend->FieldByName("SubjectCode")->AsString;


					 row++;
				DataModuleStudentDB->ADODataSetAtend->Next();
		  }

		  StringGridTodaySubjs->RowCount=row; */

}
//---------------------------------------------------------------------------
void __fastcall TfrmStudAttendanceHisrory::Timer1Timer(TObject *Sender)
{
	StatusBar1->Panels->operator [](0)->Text=FormatDateTime("'Date  ' dddd, mmmm d, yyyy 'Time ' hh:mm:ssss AM/PM",Now());

}
//---------------------------------------------------------------------------
void __fastcall TfrmStudAttendanceHisrory::FormResize(TObject *Sender)
{

	Panel2->Left=100;
	Panel2->Top=50;
	Panel2->Width= this->Width-200;
	DBGridTodaySubjs->Left=Panel1->Width+Panel1->Left+20;
	DBGridTodaySubjs->Width=Panel2->Width- 350;
	DBGridTodaySubjs->Height=Panel2->Height+100;//-DBGridTodaySubjs->Top;
	//DBGridTodaySubjs->DefaultRowHeight=50;
   //	StringGridTodaySubjs->operator =("Student Number").Cols->
	//Panel1->Width=Panel1->Width- 200;
	//Panel1->Left=StringGridTodaySubjs->Left; */
	Panel2->Height=this->Height-Panel2->Top-50;
	StringGrid1->Left=Panel1->Left;
	StringGrid1->Width= Panel1->Width;
	StringGrid1->Height=230;
	Label5->Left=DBGridTodaySubjs->Left;
}
//---------------------------------------------------------------------------
void __fastcall TfrmStudAttendanceHisrory::RadioGroupDefaultClick(TObject *Sender)

{
	if(RadioGroupDefault->ItemIndex==-1||RadioGroupDefault->ItemIndex==0){

		ComboBoxSubject->Enabled=0;
		CheckListBoxPresAbs->Enabled=0;
		DateTimePickerStartD->Enabled=0;
		btnCustomHist->Enabled=0;
		//FormShow(Sender);     //FIND ALTERNATIVE SLOWS DOWN SYSTEM

	}
	else{

		ComboBoxSubject->Enabled=1;
		CheckListBoxPresAbs->Enabled=1;
		DateTimePickerStartD->Enabled=1;
		btnCustomHist->Enabled=1;
	}

}
//---------------------------------------------------------------------------
void __fastcall TfrmStudAttendanceHisrory::ComboBoxSubjectChange(TObject *Sender)

{
    	subjSelected=1;


	String selectedSubj=ComboBoxSubject->Items->operator [](ComboBoxSubject->ItemIndex);
	selectedSubj=selectedSubj.SubString(1,selectedSubj.Pos('-')-1).Trim();

	DataModuleStudentDB->ADODataSetAtend->Active=0;
	DataModuleStudentDB->ADODataSetAtend->CommandText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND A.classid=CL.classid AND A.classid=C.classid AND C.SubjectCode=:selctSubj";// AND ClassID=:cID AND ClassDate=:cDate";
	DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctSubj")->Value=selectedSubj;
	DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("studN")->Value=frmHome->edtNumber->Text.Trim();
	DataModuleStudentDB->DataSourceAtend->DataSet=DataModuleStudentDB->ADODataSetAtend;
	DataModuleStudentDB->ADODataSetAtend->Active=1;

	DBGridTodaySubjs->DataSource=DataModuleStudentDB->DataSourceAtend;

}
//---------------------------------------------------------------------------



void __fastcall TfrmStudAttendanceHisrory::DateTimePickerStartDChange(TObject *Sender)

{
		dateSelected=1;


	TDate  selectedDate=DateTimePickerStartD->Date;
	DataModuleStudentDB->ADODataSetAtend->Active=0;
	DataModuleStudentDB->ADODataSetAtend->CommandText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND A.classid=CL.classid AND A.classid=C.classid AND A.AttendanceDate>=:selctDate";// AND ClassID=:cID AND ClassDate=:cDate";
	DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctDate")->Value=selectedDate;
	DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("studN")->Value=frmHome->edtNumber->Text.Trim();
	DataModuleStudentDB->DataSourceAtend->DataSet=DataModuleStudentDB->ADODataSetAtend;
	DataModuleStudentDB->ADODataSetAtend->Active=1;
	DBGridTodaySubjs->DataSource=DataModuleStudentDB->DataSourceAtend;

}
//---------------------------------------------------------------------------


void __fastcall TfrmStudAttendanceHisrory::btnCustomHistClick(TObject *Sender)
{
	   TDate  selectedDate=DateTimePickerStartD->Date;
	   String selectedSubj=ComboBoxSubject->Items->operator [](ComboBoxSubject->ItemIndex);
		selectedSubj=selectedSubj.SubString(1,selectedSubj.Pos('-')-1).Trim();


	   DataModuleStudentDB->ADODataSetAtend->Active=0;
	  String commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
	  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
	  " A.classid=CL.classid AND A.classid=C.classid";// AND  C.SubjectCode=:selctSubj AND A.AttendanceDate>=:selctDate ";




	   if(CheckListBoxPresAbs->Checked[0]&&CheckListBoxPresAbs->Checked[1]){
		  if(subjSelected&&dateSelected){
		  commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
		  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
		  " A.classid=CL.classid AND A.classid=C.classid AND  C.SubjectCode=:selctSubj AND A.AttendanceDate>=:selctDate ";
			//ShowMessage(DateToStr(selectedDate));
			DataModuleStudentDB->ADODataSetAtend->CommandText=commText;
		  DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctSubj")->Value=selectedSubj.Trim();
		 DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctDate")->Value=selectedDate;
			//dont check if was abs or pres
		}else if(subjSelected){
						commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
								  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
								  " A.classid=CL.classid AND A.classid=C.classid AND  C.SubjectCode=:selctSubj";
					   DataModuleStudentDB->ADODataSetAtend->CommandText=commText;
						DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctSubj")->Value=selectedSubj;
					   }else{
                            commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
									  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
									  " A.classid=CL.classid AND A.classid=C.classid AND A.AttendanceDate>=:selctDate ";
									   DataModuleStudentDB->ADODataSetAtend->CommandText=commText;
									   DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctDate")->Value=selectedDate;
					   }

	   } else if(CheckListBoxPresAbs->Checked[0]){
				//olny present
				if(subjSelected&&dateSelected){
				 commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
						  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
						  " A.classid=CL.classid AND A.classid=C.classid AND  C.SubjectCode=:selctSubj AND A.AttendanceDate>=:selctDate AND Status='Present'";
				 DataModuleStudentDB->ADODataSetAtend->CommandText=commText;
				 DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctSubj")->Value=selectedSubj;
				 DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctDate")->Value=selectedDate;
				 }else if(subjSelected){
						 commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
						  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
						  " A.classid=CL.classid AND A.classid=C.classid AND  C.SubjectCode=:selctSubj AND  Status='Present'";
						  DataModuleStudentDB->ADODataSetAtend->CommandText=commText;
						  DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctSubj")->Value=selectedSubj;
					   }else{
							 commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
						  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
						  " A.classid=CL.classid AND A.classid=C.classid AND A.AttendanceDate>=:selctDate AND Status='Present'";
							DataModuleStudentDB->ADODataSetAtend->CommandText=commText;
							DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctDate")->Value=selectedDate;
					   }

			  }else{    //only absent

			  if(subjSelected&&dateSelected){
					 commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
						  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
						  " A.classid=CL.classid AND A.classid=C.classid AND  C.SubjectCode=:selctSubj AND A.AttendanceDate>=:selctDate AND Status='Absent'";
						 DataModuleStudentDB->ADODataSetAtend->CommandText=commText;
						 DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctSubj")->Value=selectedSubj;
						 DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctDate")->Value=selectedDate;

				  }else if(subjSelected){
						 commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
						  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
						  " A.classid=CL.classid AND A.classid=C.classid AND  C.SubjectCode=:selctSubj AND  Status='Absent'";
						 DataModuleStudentDB->ADODataSetAtend->CommandText=commText;
						 DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctSubj")->Value=selectedSubj;
					   }else{
							 commText="SELECT SubjectCode AS [Subject Code],Status,A.Time AS [Date And Time],"
						  " Concept FROM Attendance A,Class_Lecture CL,Class C WHERE StudentNumber=:studN AND "
						  " A.classid=CL.classid AND A.classid=C.classid AND A.AttendanceDate>=:selctDate AND Status='Absent'";
						   DataModuleStudentDB->ADODataSetAtend->CommandText=commText;
						   DataModuleStudentDB->ADODataSetAtend-> Parameters->ParamByName("selctDate")->Value=selectedDate;
					   }

			  }

	DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("studN")->Value=frmHome->edtNumber->Text.Trim();
	DataModuleStudentDB->DataSourceAtend->DataSet=DataModuleStudentDB->ADODataSetAtend;
	DataModuleStudentDB->ADODataSetAtend->Active=1;
	DBGridTodaySubjs->DataSource=DataModuleStudentDB->DataSourceAtend;


}
//---------------------------------------------------------------------------


void __fastcall TfrmStudAttendanceHisrory::CheckListBoxPresAbsExit(TObject *Sender)

{
   if(CheckListBoxPresAbs->Checked[0]||CheckListBoxPresAbs->Checked[1])
	presAbsChecked=1;
}
//---------------------------------------------------------------------------


