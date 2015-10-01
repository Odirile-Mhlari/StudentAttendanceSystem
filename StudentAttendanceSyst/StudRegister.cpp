//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StudRegister.h"
#include "Home.h"
#include "DMStudentDB.h"
#include "System.SysUtils.hpp"
#include "System.DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmStudTimeTable *frmStudTimeTable;
//---------------------------------------------------------------------------
__fastcall TfrmStudTimeTable::TfrmStudTimeTable(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmStudTimeTable::FormShow(TObject *Sender)
{
		RadioGroupAcknLadge->ItemIndex=-1;
	  lblAckn->Visible=0;
	  lblRatin->Visible=0;
	  ackn=0;
		rating=0;
		firtSignIn=0;
	PanelTodayClasses->Visible=0;
	  //Panel2->Width=Panel1->Width;

	edtEmail->Clear();
	edtLectName->Clear();
	edtOfficeNum->Clear();
	edtStartTime->Clear();
	edtSubjName->Clear();
	edtTellNo->Clear();
	edtVenue->Clear();
	Panel2->Visible=0;
	RadioGroupAcknLadge->ItemIndex=-1;
	RichEditConcept->Clear();

	ComboBoxRating->Clear();
	ComboBoxRating->Items->Add("1 Bad");
	ComboBoxRating->Items->Add("2 Not Bad");
	ComboBoxRating->Items->Add("3 Average");
	ComboBoxRating->Items->Add("4 Good");
	ComboBoxRating->Items->Add("5 Excellent");
	Panel1->Caption="You Do Not Have Any Class At The Moment";
	RichEditComment->Clear();
	ackn=0;
	rating=0;

	studNumber=frmHome->edtNumber->Text.Trim();



	//select subject that a studnet is enbroled in and there are classes for that subject created
	DataModuleStudentDB->ADODataSetSubjClass->Active=0;
	DataModuleStudentDB->ADODataSetSubjClass->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
	DataModuleStudentDB->ADODataSetSubjClass->CommandText="SELECT * FROM Student_Subject SB,Class_Lecture CL"
	" ,Class C WHERE C.ClassID=CL.ClassID AND C.SubjectCode=SB.SubjectCode AND CL.Cancelled='No' AND Active='Yes' AND studentNumber=:studNum AND Day=:cDay";
	DataModuleStudentDB->ADODataSetSubjClass-> Parameters->ParamByName("studNum")->Value=studNumber.Trim();
	DataModuleStudentDB->ADODataSetSubjClass-> Parameters->ParamByName("cDay")->Value=FormatDateTime("dddd",Now());
	DataModuleStudentDB->DataSourceSubjClass->DataSet=DataModuleStudentDB->ADODataSetSubjClass;
	DataModuleStudentDB->ADODataSetSubjClass->Active=1;

	String subjDateToAtt=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("ClassDate")->AsString;

   /*
   	*student will not be allowed to mark register for cancelled classes
   */

   //	ShowMessage(IntToStr(DataModuleStudentDB->ADODataSetSubjClass->RecordCount));
	   //	ShowMessage(FormatDateTime("dddd",Now()));
   // ShowMessage(FormatDateTime("yyyy-mm-dd",Date()));
	if(DataModuleStudentDB->ADODataSetSubjClass->RecordCount==1)
	{
	//TIME WILL BE TAKEN FROM ATTENDANCE IF ALREADY SIGNED FOR REGISTERE ELSE AT CURRENT TIME OF LOGIN

		String nxtCla=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("Time")->AsString.Trim();
	   TDateTime nextClassTime=StrToDateTime(nxtCla);
	   //	ShowMessage(nxtCla);
	   //	ShowMessage(FormatDateTime("hh:nn AM/PM", IncHour(nextClassTime, 1)-nextClassTime));
	   if (nextClassTime<=Now()&&Now()<=IncHour(nextClassTime,1) ) {

			edtSubjName->Text=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("C.SubjectCode")->AsString.Trim();
			edtStartTime->Text=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("Time")->AsString.Trim();
			RichEditConcept->Text=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("Concept")->AsString.Trim();
			edtVenue->Text=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("Venue")->AsString.Trim();


			String LectureID=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("LectureID")->AsString.Trim();
			DataModuleStudentDB->ADODataSetStudLect->Active=0;
			DataModuleStudentDB->ADODataSetStudLect->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
			DataModuleStudentDB->ADODataSetStudLect->CommandText="SELECT * FROM Lecture WHERE LectureID=:lectID";
			DataModuleStudentDB->ADODataSetStudLect->Parameters->ParamByName("lectID")->Value=LectureID.Trim();
			DataModuleStudentDB->DataSourceStudLect->DataSet=DataModuleStudentDB->ADODataSetStudLect;
			 DataModuleStudentDB->ADODataSetStudLect->Active=1;

			edtEmail->Text=DataModuleStudentDB->ADODataSetStudLect->Fields->FieldByNumber(7)->AsString.Trim();

			String fN,lN;
			fN=DataModuleStudentDB->ADODataSetStudLect->Fields->FieldByNumber(2)->AsString.Trim();
			lN= DataModuleStudentDB->ADODataSetStudLect->Fields->FieldByNumber(3)->AsString.Trim();
			edtLectName->Text=fN+" "+lN;

			edtOfficeNum->Text=DataModuleStudentDB->ADODataSetStudLect->Fields->FieldByNumber(5)->AsString.Trim();
			edtTellNo->Text=DataModuleStudentDB->ADODataSetStudLect->Fields->FieldByNumber(6)->AsString.Trim();



		//CHECK IF THE STUDENT HAS ALREADY SIGNED IN
			  //params StudentNumber,ClassID,ClassID ,Time,AttendanceDate,ClassDate
			DataModuleStudentDB->ADODataSetAtend->Active=0;
			DataModuleStudentDB->ADODataSetAtend->CommandText="SELECT * FROM Attendance WHERE StudentNumber=:studN AND ClassID=:cID AND ClassDate=:cDate";
			DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("studN")->Value=studNumber.Trim();
			DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("cID")->Value=StrToInt(DataModuleStudentDB->ADODataSetSubjClass->FieldByName("C.ClassID")->AsString);
			DataModuleStudentDB->ADODataSetAtend->Parameters->ParamByName("cDate")->Value=FormatDateTime("yyyy-mm-dd",Now());
			DataModuleStudentDB->DataSourceAtend->DataSet=DataModuleStudentDB->ADODataSetAtend;
			DataModuleStudentDB->ADODataSetAtend->Active=1;

			globStudID=studNumber;
			golbClassID=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("C.ClassID")->AsInteger;

	   if(DataModuleStudentDB->ADODataSetAtend->RecordCount==1){

			globSubjTime= StrToDateTime(DataModuleStudentDB->ADODataSetAtend->FieldByName("Time")->AsString.Trim());
			Panel1->Caption="Student Number: "+studNumber+" You Were Successfully Marked Present At "+ FormatDateTime("HH:MM AM/PM",globSubjTime);
			Panel2->Visible=1;

			//set flag for first signing in to false so that ack and rating will not be re captured
			firtSignIn=0;

	   }else{
		   //if student didnt sign register for active subject  SIGN IN THE STUDENT
			DataModuleStudentDB->ADOCommandStudentDB->CommandText="INSERT INTO Attendance VALUES (:stdNo,:clID,:sttus,:cTime,:attDate,:cDate)";//  WHERE UserID=:UsrID ";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("stdNo")->Value=studNumber.Trim();//FormatDateTime("dddd,mmm,d,yyyy,hh:mm:ssss AM/PM",Now());
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("clID")->Value=StrToInt(DataModuleStudentDB->ADODataSetSubjClass->FieldByName("C.ClassID")->AsString);
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("sttus")->Value="Present";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("cTime")->Value=FormatDateTime("yyyy-mm-dd hh:mm:ssss AM/PM",Now());
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("attDate")->Value=FormatDateTime("yyyy-mm-dd",Now());
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("cDate")->Value=subjDateToAtt;
			DataModuleStudentDB->ADOCommandStudentDB->Execute();
			globSubjTime=Now();
			Panel1->Caption="Student Number: "+studNumber+" You Were Successfully Marked Present At "+ FormatDateTime("HH:MM AM/PM",Now());
			Panel2->Visible=1;

			//set flag for first signing in to true so that ack and rating will be captured
			firtSignIn=1;
	   }


	   }//a class is only active during its current period  otherwise student is
	   //marked absent if class is cancelled student will be automatically marked present when lecture cancells it

	}
	else{        //we come to this else because the system supports for a student to have only one active class at a time



				PanelTodayClasses->Visible=0;
				Panel1->Caption="You Do Not Have Any Classes Scheduled For Today";
				Panel1->Font->Color=clRed;
				Panel2->Visible=0;

				DataModuleStudentDB->ADODataSetSubjClass->Active=0;
				DataModuleStudentDB->ADODataSetSubjClass->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
				DataModuleStudentDB->ADODataSetSubjClass->CommandText="SELECT * FROM Student_Subject SB,Class_Lecture "
				" CL,Class C WHERE C.ClassID=CL.ClassID AND C.SubjectCode=SB.SubjectCode AND Active='No' AND studentNumber=:studNum AND Day=:cDay AND ClassDate=:clsDate ORDER BY C.SubjectCode ";
				DataModuleStudentDB->ADODataSetSubjClass-> Parameters->ParamByName("studNum")->Value=studNumber.Trim();
				DataModuleStudentDB->ADODataSetSubjClass-> Parameters->ParamByName("cDay")->Value=FormatDateTime("dddd",Now());
				DataModuleStudentDB->ADODataSetSubjClass-> Parameters->ParamByName("clsDate")->Value=FormatDateTime("yyyy-mm-dd",Date());
				DataModuleStudentDB->DataSourceSubjClass->DataSet=DataModuleStudentDB->ADODataSetSubjClass;

				DataModuleStudentDB->ADODataSetSubjClass->Active=1;
				DataModuleStudentDB->ADODataSetSubjClass->First();
				TStringList *todayComing=new TStringList();


				if(DataModuleStudentDB->ADODataSetSubjClass->RecordCount>0){
				int counter=0;
				StringGridTodaySubjs->DefaultColWidth=146;
				StringGridTodaySubjs->ColCount=4;
				StringGridTodaySubjs->RowCount=1;



				StringGridTodaySubjs->Cells[0][0]="Subject Code";
				StringGridTodaySubjs->Cells[1][0]="Venue";
				StringGridTodaySubjs->Cells[2][0]="Time";

				StringGridTodaySubjs->Cells[3][0]="Cancelled";


				int row=1;


				while(!DataModuleStudentDB->ADODataSetSubjClass->Eof){

				 int currCell=0;
				 String  nxtClsTime=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("Time")->AsString;
				 String nxtClsDate=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("ClassDate")->AsString;
				 TDateTime nextClassTime=StrToDateTime(nxtClsTime);

				 if(nextClassTime>Now()&&StrToDateTime(nxtClsDate)==Date()){

					for(int C=11;C<DataModuleStudentDB->ADODataSetSubjClass->FieldCount-1;C++){

						StringGridTodaySubjs->Cells[currCell][row]=DataModuleStudentDB->ADODataSetSubjClass->Fields->FieldByNumber(C)->AsString;

						currCell++;
					  }
						TDateTime timeClss=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("Time")->AsDateTime;
						StringGridTodaySubjs->Cells[currCell][row]=FormatDateTime("hh:nn Am/Pm",timeClss);
						StringGridTodaySubjs->Cells[currCell+1][row]=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("CL.Cancelled")->AsString;
					   row++;
				   }
					StringGridTodaySubjs->RowCount=row;
					DataModuleStudentDB->ADODataSetSubjClass->Next();
			  }

			  //change height of grid according to number of rows displaed
				StringGridTodaySubjs->Height=StringGridTodaySubjs->DefaultRowHeight*StringGridTodaySubjs->RowCount+12;
				Panel1->Font->Color=clRed;

			/***
				* here we loop for next first subject on todays time table through strGrid cel[2][row]
			*/
			 int rowCount=0;
			 int nextTimeRowIndex=1;
			  TDate smallestClTime=Now();

			   String  nxtClsTime=DataModuleStudentDB->ADODataSetSubjClass->FieldByName("Time")->AsString;
				TDateTime nextClassTime=StrToDateTime(nxtClsTime);

				for(int r=1;r<StringGridTodaySubjs->RowCount;r++){

					for(int inner=r;inner<StringGridTodaySubjs->RowCount-1;inner++){

					TTime subjTime1=StrToTime( StringGridTodaySubjs->Cells[2][r]);
					TTime subjTime2=StrToTime(StringGridTodaySubjs->Cells[2][inner+1]);

						if(smallestClTime>subjTime2){

							smallestClTime=subjTime2;
							nextTimeRowIndex=r+1;

					   }
					   else
							 nextTimeRowIndex=r;
					}
				}


		 if(nextTimeRowIndex==0 ){

			Panel1->Caption="You Do Not Have An Active Class Or Classes Scheduled For The Rest of Today";//: Your Next Class Is "+nextSubjCode+" At "+TimeToStr(nxtClsTime);
			Panel1->Font->Color=clRed;
			Panel2->Visible=0;
			PanelTodayClasses->Visible=0;

		  }
		  else{



			String nextSubjCode=StringGridTodaySubjs->Cells[0][nextTimeRowIndex];

			Panel1->Caption="You Do Not Have An Active Class: Your Next Class Is "+nextSubjCode+" At "+StringGridTodaySubjs->Cells[2][nextTimeRowIndex];
			Panel1->Font->Color=clRed;
			Panel2->Visible=0;
			PanelTodayClasses->Visible=1;
			  }

		  }


		}

}
//---------------------------------------------------------------------------
void __fastcall TfrmStudTimeTable::Timer1Timer(TObject *Sender)
{
	StatusBar1->Panels->operator [](0)->Text=FormatDateTime("'Date  ' dddd, mmmm d, yyyy 'Time ' hh:mm:ssss AM/PM",Now());

}
//---------------------------------------------------------------------------
void __fastcall TfrmStudTimeTable::FormClose(TObject *Sender, TCloseAction &Action)

{

	if (Panel2->Visible==1&&firtSignIn) {
		if(RadioGroupAcknLadge->ItemIndex==-1) {
			 Action=caNone;
			 lblAckn->Visible=1;
		}
		else {
		   if( ComboBoxRating->ItemIndex==-1){
			   Action=caNone;
			 lblRatin->Visible=1;
		   }else
		   Action=caFree;
		}

		//check if student signs in for first time during the lesson sesssion
		if(ackn&&rating&&firtSignIn){

			DataModuleStudentDB->ADOCommandStudentDB->CommandText="INSERT INTO ClassComment VALUES(:stdNo,:clID,:ackNowlge,:cRating,:cComm,:cDT)";//  WHERE UserID=:UsrID ";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("stdNo")->Value=globStudID.Trim();//FormatDateTime("dddd,mmm,d,yyyy,hh:mm:ssss AM/PM",Now());
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("clID")->Value=StrToInt(golbClassID);
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("ackNowlge")->Value=RadioGroupAcknLadge->Items->operator [](RadioGroupAcknLadge->ItemIndex);
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("cRating")->Value=ComboBoxRating->Text;
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("cComm")->Value=RichEditComment->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("cDT")->Value=FormatDateTime("yyyy-mm-dd hh:nn AM/PM",globSubjTime);
			DataModuleStudentDB->ADOCommandStudentDB->Execute();

		}

	}

}
//---------------------------------------------------------------------------
void __fastcall TfrmStudTimeTable::ComboBoxRatingChange(TObject *Sender)
{

	  lblRatin->Visible=0;
	  rating=1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmStudTimeTable::RadioGroupAcknLadgeClick(TObject *Sender)
{
	lblAckn->Visible=0;
	ackn=1;
}
//---------------------------------------------------------------------------
void __fastcall TfrmStudTimeTable::FormKeyPress(TObject *Sender, System::WideChar &Key)

{
if( Key=='r' ||Key=='R'){

	   FormShow(Sender);
	}
}
//---------------------------------------------------------------------------

