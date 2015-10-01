//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ForgotPassword.h"

#include "DMStudentDB.h"
#include "Home.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmForgotPasswork *frmForgotPasswork;
//---------------------------------------------------------------------------
__fastcall TfrmForgotPasswork::TfrmForgotPasswork(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::FormShow(TObject *Sender)
{
	  //initialise flag global variables to 0/false
		validIDNumber=0;
		validUserID=0;
		paaswordMtch=0;

	  //configure displays
		lblInvalidUserID->Visible=0;
		lblIncorrectIDNumber->Visible=0;
	  //focus curser on edtUserID

	  edtUserID->SetFocus();


	//take usertype and userID  from home form
	lblUserType->Caption= frmHome->lblUserType->Caption; //RadioGroupUserType->Items->operator [](frmHome->RadioGroupUserType->ItemIndex);

	if(frmHome->invalidUserID){
		Panel1->Caption="Password reset for: "+frmHome->lblUserType->Caption+" "+frmHome->edtNumber->Text;
		lblGoBacToLogin->Visible=0;
		edtUserID->Text=frmHome->edtNumber->Text;
	}
	else{
		Panel1->Font->Color=clRed;
		edtUserID->Text=frmHome->edtNumber->Text;
		Panel1->Caption="Error: Invalid credentials provided";
		lblGoBacToLogin->Font->Color=clBlue;
		lblGoBacToLogin->Visible=1;

	}

}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::FormResize(TObject *Sender)
{
	/****configuration of frmHome Components
		*everytime the form is resized
		*@Author Rakoma TP
	*/

	Panel2 ->Left=frmForgotPasswork->Width/2-Panel2->Width/2;
	Panel2->Top=Panel1->Height+10;
	Panel1->Width=frmForgotPasswork->Width;
	Panel1->Top=0;
	Panel1->Left=0;
	lblGoBacToLogin->Top=Panel1->Height+10;
	lblGoBacToLogin->Left=frmForgotPasswork->Width/2-lblGoBacToLogin->Width/2;

	Panel3->Left=Panel2->Left;
	Panel3->Width=Panel2->Width;
	Panel3->Top=Panel2->Top+Panel2->Height+10;
}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::FormClose(TObject *Sender, TCloseAction &Action)

{
	//clear edit boxes
	Panel1->Font->Color=clBlack;
	frmHome->edtNumber->Text="";
	frmHome->lblIncorrectNumber->Caption="";
	frmHome->edtPassword->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::lblGoBacToLoginClick(TObject *Sender)
{
	//take user back to home form
	Panel1->Font->Color=clBlack;
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::btnGoBackToLoginClick(TObject *Sender)
{
	frmForgotPasswork->Close();

}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::edtIDNumberExit(TObject *Sender)
{
   //validate IDnumber TO USERID

   /*

   if(0){
	  lblInvalidID=1;
   }

   */

	//retrieve login data from user table in StudentDB  after validating entered id number


		DataModuleStudentDB->ADODataSetUser->Active=0;
		DataModuleStudentDB->ADODataSetUser->CommandText="SELECT * FROM Users WHERE UserID=:usrID AND IDNumber=:IDNo";//+edtNumber;
		DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("usrID")->Value=frmHome->edtNumber->Text.Trim();
		DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("IDNo")->Value=edtIDNumber->Text.Trim();
		DataModuleStudentDB->ADODataSetUser->Active=1;
	//validate userid against idnumber

	if(DataModuleStudentDB->ADODataSetUser->RecordCount==0||edtUserID->Text.Trim().IsEmpty()||
	 edtIDNumber->Text.Trim().IsEmpty()){

		validIDNumber=0;
		validUserID=0;
		lblIncorrectIDNumber->Visible=1;
		lblInvalidUserID->Visible=1;
	}
	else{
		validIDNumber=1;
		validUserID=1;
		lblIncorrectIDNumber->Visible=0;
		lblInvalidUserID->Visible=0;
	}


}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::btnSaveChangesClick(TObject *Sender)
{
	//
		//retrieve login data from user table in StudentDB
	  edtUserIDExit(this);
	  edtMatchPasswordExit(this);
	  edtIDNumberExit(this);

		if(paaswordMtch&&validIDNumber&&validUserID){

			DataModuleStudentDB->ADOCommandStudentDB->CommandText="UPDATE Users SET Passwords=:newPasss WHERE UserID=:UsrID ";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("newPasss")->Value=edtNewPassword->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("UsrID")->Value=edtUserID->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Execute();

			DataModuleStudentDB->ADOCommandStudentDB->CommandText="UPDATE Users SET LastLogin=:currDateTim WHERE UserID=:UsrID ";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("currDateTim")->Value=FormatDateTime("dddd,mmm,d,yyyy,hh:mm:ssss AM/PM",Now());
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("UsrID")->Value=edtUserID->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Execute();
				Panel3->Font->Color=clLime;
			Panel3->Visible=1;
	  }




}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::edtUserIDExit(TObject *Sender)
{
		DataModuleStudentDB->ADODataSetUser->Active=0;
		DataModuleStudentDB->ADODataSetUser->CommandText="SELECT * FROM Users WHERE UserID=:usrID";//+edtNumber;
		DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("usrID")->Value=edtUserID->Text.Trim();
		DataModuleStudentDB->ADODataSetUser->Active=1;

	//validate userid against idnumber

	if(DataModuleStudentDB->ADODataSetUser->RecordCount==0||edtUserID->Text.Trim().IsEmpty()){
		lblInvalidUserID->Visible=1;
		validUserID=0;
	}
	else {
		validUserID=1;
		lblInvalidUserID->Visible=0;
	}

}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::FormCreate(TObject *Sender)
{
		lblInvalidUserID->Caption="Invalid "+frmHome->lblUserType->Caption;
		lblInvalidUserID->Font->Color=clRed;
		lblIncorrectIDNumber->Caption="Invalid ID Number";
		lblIncorrectIDNumber->Font->Color=clRed;
		lblPasswordNoMatch->Caption="Passwords Do Not Match";
		lblPasswordNoMatch->Font->Color=clRed;
		lblPasswordNoMatch->Visible=0;

		Panel3->Caption="Password Successfully Changed";
		Panel3->Visible=0;

}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::edtUserIDEnter(TObject *Sender)
{
	edtUserID->Text="";
	lblInvalidUserID->Visible=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::edtIDNumberEnter(TObject *Sender)
{
	edtIDNumber->Text="";
	lblIncorrectIDNumber->Visible=0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmForgotPasswork::edtMatchPasswordExit(TObject *Sender)
{
	if(edtMatchPassword->Text.Trim()==edtNewPassword->Text.Trim()&&!edtMatchPassword->Text.Trim().IsEmpty()&&!edtNewPassword->Text.Trim().IsEmpty()){
		paaswordMtch=1;
		lblPasswordNoMatch->Visible=0;
	}
	else {
		paaswordMtch=0 ;
		lblPasswordNoMatch->Visible=1;
    }
}
//---------------------------------------------------------------------------

