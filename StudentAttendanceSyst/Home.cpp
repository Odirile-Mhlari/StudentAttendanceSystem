//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Home.h"
#include "ForgotPassword.h"
#include "Register.h"
#include "ChangePassword.h"
#include "DMStudentDB.h"
#include "Stud.h"
#include "System.SysUtils.hpp"
#include "System.DateUtils.hpp"
#include "StudAttendanceHistory.h"
#include "Lecture.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmHome *frmHome;
//---------------------------------------------------------------------------
__fastcall TfrmHome::TfrmHome(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmHome::FormResize(TObject *Sender)
{
	/****configuration of frmHome Components
		*everytime the form is resized
		*@Author Rakoma TP
	*/
	Panel3->Left=(this->Width/2-350);
	Panel3->Top=50;
	Panel1->Top=Panel3->Top;
	Panel1->Left=Panel3->Left+Panel3->Width+5;
	Panel1->Top=Panel3->Top;
	Panel2->Width=this->Width;
	Panel2->Left=0;
	Panel2->Top=0;

	/****change font color of labels
		*@Author Rakoma TP
	*/
	lblIncorrectNumber->Font->Color=clRed;
	lblIncorrectPass->Font->Color=clRed;


}
//---------------------------------------------------------------------------
void __fastcall TfrmHome::RadioGroupUserTypeClick(TObject *Sender)
{
	lblIncorrectUserTyp->Caption="";
	lblIncorrectNumber->Caption ="";
	lblIncorrectPass ->Caption="";
	lblUserType->Caption=RadioGroupUserType->Items->operator [](RadioGroupUserType->ItemIndex)+" Number";

	 if(RadioGroupUserType->ItemIndex==2) {

		 btnChangePin->Visible=0;
		 btnForgotPin ->Visible=0;
	 }

}
//---------------------------------------------------------------------------
void __fastcall TfrmHome::FormShow(TObject *Sender)
{


	/****set user type to default as Student
		*@Author Rakoma TP
	*/
	edtNumber->Clear();
	edtPassword->Clear();
	RadioGroupUserType->ItemIndex=-1;
	lblIncorrectUserTyp->Caption="Please Select User Type";
	lblIncorrectUserTyp->Font->Color=clRed;
	lblIncorrectUserTyp->Visible=0;
	//initialise status of user id
	invalidUserID=0;

	 TStreamReader *configFile= new TStreamReader("..\\..\\Configuration Files\\configFile.txt");

	 String coonectString=configFile->ReadLine();
	 configFile->Close();

	/****establish database connection to using class DMStudentDB.h
		*components found on DataModuleStudentDB used:ADOConnectionStudentDB,
		*DataSourceUser,ADODataSetUser
		*here User table is used to for user information retrival and data validation
		*@Author Rakoma TP
	*/

	try{
		DataModuleStudentDB->ADOConnectionStudentDB->Connected=0;
		DataModuleStudentDB->ADOConnectionStudentDB->ConnectionString="Provider=Microsoft.ACE.OLEDB.12.0;Data Source="+coonectString+";Persist Security Info=False";
		DataModuleStudentDB->ADOConnectionStudentDB->Connected=1;
		DataModuleStudentDB->ADODataSetUser->Active=0;
		DataModuleStudentDB->ADODataSetUser->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
		DataModuleStudentDB->DataSourceUser->DataSet=DataModuleStudentDB->ADODataSetUser;
		DataModuleStudentDB->ADOCommandStudentDB->Connection=DataModuleStudentDB->ADOConnectionStudentDB;


		 DataModuleStudentDB->ADODataSetStudLect->Active=0;
		 DataModuleStudentDB->ADODataSetStudLect->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
		 DataModuleStudentDB->ADODataSetStudLect->CommandText="SELECT * FROM Lecture,Student";
		 DataModuleStudentDB->DataSourceStudLect->DataSet=DataModuleStudentDB->ADODataSetStudLect;

		 DataModuleStudentDB->ADODataSetSubjClass->Active=0;
		 DataModuleStudentDB->ADODataSetSubjClass->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
		 DataModuleStudentDB->ADODataSetSubjClass->CommandText="SELECT * FROM Subject,Class";
		 DataModuleStudentDB->DataSourceSubjClass->DataSet=DataModuleStudentDB->ADODataSetSubjClass;

		 DataModuleStudentDB->ADODataSetStudLecSubj->Active=0;
		 DataModuleStudentDB->ADODataSetStudLecSubj->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
		 DataModuleStudentDB->ADODataSetStudLecSubj->CommandText="SELECT * FROM Lecture,Student,Subject";
		 DataModuleStudentDB->DataSourceStudLectSubj->DataSet=DataModuleStudentDB->ADODataSetStudLecSubj;

		 DataModuleStudentDB->ADODataSetAtend->Active=0;
		 DataModuleStudentDB->ADODataSetAtend->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
		 DataModuleStudentDB->ADODataSetAtend->CommandText="SELECT * FROM Lecture,Student";
		 DataModuleStudentDB->DataSourceAtend->DataSet=DataModuleStudentDB->ADODataSetAtend;


		DataModuleStudentDB->ADODataSetAttHist->Active=0;
		DataModuleStudentDB->ADODataSetAttHist->Connection=DataModuleStudentDB->ADOConnectionStudentDB;
		DataModuleStudentDB->DataSourceAttHist->DataSet=DataModuleStudentDB->ADODataSetAttHist;
	}
	catch(...){

		ShowMessage("Database connection lost: Locate 'StudentAttendanceSyst\Win32\Debug\studentDB.accdb'");
		FileOpenDialog1->Execute();
		//if(FileOpenDialog1->)
		//DataModuleStudentDB->ADOConnectionStudentDB->Connected=0;
	   //	DataModuleStudentDB->ADOConnectionStudentDB->ConnectionString="Provider=Microsoft.ACE.OLEDB.12.0;Data Source="+FileOpenDialog1->FileName+";Persist Security Info=False";
		 //if(FileOpenDialog1->FileName.SubString())studentDB.accdb
		 coonectString=FileOpenDialog1->FileName;

		 if(coonectString.SubString(coonectString.Pos("."),coonectString.Length())==".accdb")
		 {
			configFile->Close();
			TStreamWriter *outPutToConfig=new  TStreamWriter("..\\..\\Configuration Files\\configFile.txt",false) ;
			outPutToConfig->WriteLine(coonectString);
			outPutToConfig->Close();
			FormShow(this);
		 }
		 else{
			 ShowMessage("Incorrect Dabase Selected Application Closing");
             Sleep(1000);

		 }

	}
		//DataModuleStudentDB->ADOConnectionStudentDB->ConnectionString=

		/**here we update the table of studnet students to absent after class is dismissed

		*/


		/** *here we disable classes that have passed to Active=No
			*
		*/



		/****cancelled classes for the current day are synched and displayed on
			* notice for anyone who loges onto the system
			*
		*/

		/****  mark students who were absent absent
			*
		*/



	/*DataModuleStudentDB->ADOConnectionStudentDB->;
	DataModuleStudentDB->DataSourceUser;
	DataModuleStudentDB->ADODataSetUser;*/






}
//---------------------------------------------------------------------------

void __fastcall TfrmHome::edtNumberExit(TObject *Sender)
{
	 DataModuleStudentDB->ADODataSetUser->Active=0;
	 DataModuleStudentDB->ADODataSetUser->CommandText="SELECT * FROM Users WHERE UserID=:usrID";//+edtNumber;
	 DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("usrID")->Value=edtNumber->Text.Trim();
	 DataModuleStudentDB->ADODataSetUser->Active=1;


	if(DataModuleStudentDB->ADODataSetUser->RecordCount==0||edtNumber->Text.Trim().IsEmpty()){
		lblIncorrectNumber->Font->Color=clRed;
		lblIncorrectNumber->Caption="Incorretct "+lblUserType->Caption;
		invalidUserID=0;
	}
	else  {
		invalidUserID=1;
	  lblIncorrectNumber->Caption="";
	  frmForgotPasswork->Panel2->Visible=1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmHome::Label9Click(TObject *Sender)
{
//register

	frmRegister->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TfrmHome::btnLoginClick(TObject *Sender)
{
	/*countLogin++;
	if(countLogin>5)
	{

	}  */
		//grab user type from group box

	if(RadioGroupUserType->ItemIndex>-1){
		String selectedUserType=RadioGroupUserType->Items->operator [](RadioGroupUserType->ItemIndex).Trim();

	 //capture access time to system


		DataModuleStudentDB->ADOCommandStudentDB->CommandText="UPDATE Users SET LastLogin=:currDateTim WHERE UserID=:UsrID ";
		DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("currDateTim")->Value=FormatDateTime("dddd,mmm,d,yyyy,hh:mm:ssss AM/PM",Now());
		DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("UsrID")->Value=edtNumber->Text.Trim();
		DataModuleStudentDB->ADOCommandStudentDB->Execute();


	   /*	DataModuleStudentDB->ADOCommandStudentDB->CommandText="INSERT into Users (IDNumber,userID) values (1239,12457)";
		//DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("IDNumber")->Value="123";
		DataModuleStudentDB->ADOCommandStudentDB->Execute(); */

	//validate login detatils
		DataModuleStudentDB->ADODataSetUser->Active=0;
		DataModuleStudentDB->ADODataSetUser->CommandText="SELECT * FROM Users WHERE UserID=:usrID AND Passwords=:passwrd AND UserType=:usrTyp";
		DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("usrID")->Value=edtNumber->Text.Trim();
		DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("usrTyp")->Value=selectedUserType.Trim();
		DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("passwrd")->Value=edtPassword->Text.Trim();
		DataModuleStudentDB->ADODataSetUser->Active=1;


		//show password or number is incorrect

	 if(DataModuleStudentDB->ADODataSetUser->RecordCount==0){  //check again if numnber maches password in dbs
			lblIncorrectNumber->Caption ="Incorrect "+lblUserType->Caption;
			lblIncorrectPass->Caption="Incorrect Password";
	 }
	 else{

		String dbUserType=DataModuleStudentDB->ADODataSetUser->FieldByName("UserType")->AsString;
		if(dbUserType=="Student"&&selectedUserType==dbUserType){
		//show student form
		//frmStudent->

		  frmStud->ShowModal();


		}
		else if(dbUserType.Trim()=="Lecture"&&selectedUserType.Trim()==dbUserType.Trim()){

			//show Lecture form

			  frmLecture->ShowModal();
			}
			else if(dbUserType=="Administrator"&&selectedUserType==dbUserType){
			  //show Admin form
			ShowMessage("ke Administrator");
			}
			else
			{
			lblIncorrectUserTyp->Font->Color=clRed;
			lblIncorrectUserTyp->Caption="Incorrect User Type";
			lblIncorrectNumber->Caption ="Incorrect "+lblUserType->Caption;
			lblIncorrectPass->Caption="Incorrect Password";

			}
	 }
	}
	else {
		lblIncorrectUserTyp->Caption="Please Select User Type";
		lblIncorrectUserTyp->Visible=1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmHome::btnForgotPinClick(TObject *Sender)
{



	//ShowMessage("break here");
	//DataModuleStudentDB->ADODataSetUser->Open();
	//show window to change pin
if(RadioGroupUserType->ItemIndex>-1){
	if(invalidUserID==0||edtNumber->Text.Trim().IsEmpty()){
	lblIncorrectNumber->Font->Color=clRed;
	lblIncorrectNumber->Caption="Incorretct "+lblUserType->Caption.Trim();
	frmForgotPasswork->Panel2->Visible=0;
  }
   else{
	frmForgotPasswork->Panel2->Visible=1;
	frmForgotPasswork->ShowModal(); }

}
else {
		lblIncorrectUserTyp->Caption="Please Select User Type";
		lblIncorrectUserTyp->Visible=1;
	}


}
//---------------------------------------------------------------------------

void __fastcall TfrmHome::btnChangePinClick(TObject *Sender)
{
	if(RadioGroupUserType->ItemIndex>-1){
	//capture access time to system
		frmChangePassword->ShowModal();
	}  else{
		lblIncorrectUserTyp->Caption="Please Select User Type";
		lblIncorrectUserTyp->Visible=1;
	}
	//show window to change pin
}
//---------------------------------------------------------------------------

void __fastcall TfrmHome::btnLoginExit(TObject *Sender)
{
	lblIncorrectNumber->Caption ="";
	lblIncorrectPass ->Caption="";
}
//---------------------------------------------------------------------------

void __fastcall TfrmHome::edtNumberClick(TObject *Sender)
{
	lblIncorrectNumber->Caption ="";
}
//---------------------------------------------------------------------------

void __fastcall TfrmHome::Timer1Timer(TObject *Sender)
{
	StatusBar1->Panels->operator [](0)->Text=FormatDateTime("'Date  ' dddd, mmmm d, yyyy 'Time ' hh:mm:ssss AM/PM",Now());
}
//---------------------------------------------------------------------------

void __fastcall TfrmHome::CheckBox1Click(TObject *Sender)
{
	if(CheckBox1->Checked)
	edtPassword->PasswordChar='\0';
	else
		edtPassword->PasswordChar='*';



}
//---------------------------------------------------------------------------


void __fastcall TfrmHome::TimerLoginTimer(TObject *Sender)
{
   /*	if(countLogin>5 &&1)
	{


	   btnLogin->Enabled=0;

	}    */
		Label10->Caption="";

	Label10->Caption="Time left Before Next Attempt "+DateTimeToStr(Now()--);


}
//---------------------------------------------------------------------------

