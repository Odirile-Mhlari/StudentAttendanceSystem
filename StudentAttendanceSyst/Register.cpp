//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Register.h"
#include "Home.h"
#include "DMStudentDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmRegister *frmRegister;
//---------------------------------------------------------------------------
__fastcall TfrmRegister::TfrmRegister(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::btnGoToLoginClick(TObject *Sender)
{
	//
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtNumberEnter(TObject *Sender)
{
//
	edtNumber->Clear();
	lblInvalidNumber->Visible=0;
	lblIncorrectUserTyp->Visible=0;

}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtFirstNameEnter(TObject *Sender)
{
//
   edtFirstName->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtLastNameEnter(TObject *Sender)
{
//
	edtLastName->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtIDNumEnter(TObject *Sender)
{
//
	edtIDNum->Clear();
	lblInvalidID->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtPhoneEnter(TObject *Sender)
{
//
	edtPhone->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtEmailEnter(TObject *Sender)
{
//
	edtEmail->Clear();
	lblInvalidEmail->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtPass1Enter(TObject *Sender)
{
//
	edtPass1->Clear();
	edtPass2->Clear();
	lblPassMatch->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtPass2Enter(TObject *Sender)
{
//
	edtPass2->Clear();
	lblPassMatch->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtOfficeEnter(TObject *Sender)
{
//
	edtOffice->Clear();
	lblOfficeNum->Visible=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::FormShow(TObject *Sender)
{


	edtFirstNameEnter(this);
	edtEmailEnter(this);
	edtIDNumEnter(this) ;
	edtLastNameEnter(this);
	edtNumberEnter(this);
	edtOfficeEnter(this);
	edtPass1Enter(this);
	edtPass2Enter(this);
	edtPhoneEnter(this);

     ComboBoxUType->Clear();
	lectureID="null";
	studentNumber="null";
	invalidIDNumber=0;
	IDNumber="null";
	passMatch=0;
	invalidUserID=0;
	validEmail=0;
	validOffice=0;
	PanelSuccessful->Visible=0;
	registerd=0;

	lblSucc1->Visible=0;
	lblSucc2->Visible=0;

	ComboBoxUType->Items->Add("Student");
	ComboBoxUType->Items->Add("Lecture");
	ComboBoxUType->ItemIndex=0;
	ComboBoxUTypeChange(this);

	lblIncorrectUserTyp->Font->Color=clRed;
	lblInvalidNumber->Font->Color=clRed;

	lblInvalidNumber->Visible=0;
	lblIncorrectUserTyp->Visible=0;
	lblInvalidID->Visible=0;
	lblPassMatch->Visible=0;

}
//---------------------------------------------------------------------------


void __fastcall TfrmRegister::edtNumberExit(TObject *Sender)
{

	int recordCounter=0;
	if(ComboBoxUType->ItemIndex==0){
			 DataModuleStudentDB->ADODataSetStudLect->Active=0;
			 DataModuleStudentDB->ADODataSetStudLect->CommandText="SELECT * FROM Student WHERE StudentNumber=:usrID";//+edtNumber;
			 DataModuleStudentDB->ADODataSetStudLect->Parameters->ParamByName("usrID")->Value=edtNumber->Text.Trim();
			 DataModuleStudentDB->ADODataSetStudLect->Active=1;
			 studentNumber=DataModuleStudentDB->ADODataSetStudLect->FieldByName("studentNumber")->AsString.Trim();
			 recordCounter=DataModuleStudentDB->ADODataSetStudLect->RecordCount;
		 }else {

			DataModuleStudentDB->ADODataSetStudLect->Active=0;
			 DataModuleStudentDB->ADODataSetStudLect->CommandText="SELECT * FROM Lecture WHERE LectureID=:usrID";//+edtNumber;
			DataModuleStudentDB->ADODataSetStudLect->Parameters->ParamByName("usrID")->Value=edtNumber->Text.Trim();
			 DataModuleStudentDB->ADODataSetStudLect->Active=1;
			 lectureID=DataModuleStudentDB->ADODataSetStudLect->FieldByName("LectureID")->AsString.Trim();
			 recordCounter=DataModuleStudentDB->ADODataSetStudLect->RecordCount;
		 }

			 DataModuleStudentDB->ADODataSetUser->Active=0;
			 DataModuleStudentDB->ADODataSetUser->CommandText="SELECT * FROM Users WHERE UserID=:usrID";//+edtNumber;
			 DataModuleStudentDB->ADODataSetUser->Parameters->ParamByName("usrID")->Value=edtNumber->Text.Trim();
			 DataModuleStudentDB->ADODataSetUser->Active=1;



	if(recordCounter==0||edtNumber->Text.Trim().IsEmpty()||DataModuleStudentDB->ADODataSetUser->RecordCount>0){
		lblInvalidNumber->Visible=1;
		lblIncorrectUserTyp->Visible=1;
		invalidUserID=0;
		registerd=1;
	}
	else  {




	//if not in login
		IDNumber=DataModuleStudentDB->ADODataSetStudLect->FieldByName("IDNumber")->AsString.Trim();
		edtFirstName->Text=DataModuleStudentDB->ADODataSetStudLect->FieldByName("FirstName")->AsString.Trim();
		edtLastName->Text=DataModuleStudentDB->ADODataSetStudLect->FieldByName("LastName")->AsString.Trim();

		invalidUserID=1;
		lblInvalidNumber->Visible=0;
		lblIncorrectUserTyp->Visible=0;
		registerd=0;


	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::ComboBoxUTypeChange(TObject *Sender)
{
	lblIncorrectUserTyp->Visible=0;
	if(ComboBoxUType->ItemIndex==0){

		lblOffice->Visible=0;
		edtOffice->Visible=0;
		validOffice=1;
		lblTellCell->Caption="Cell Number";
		lblOfficeNum->Visible=0;
	}else{

		lblOffice->Visible=1;
		edtOffice->Visible=1;
		lblTellCell->Caption="Tell Number";
		edtPhone1->Text=" 01";

	}
}
//---------------------------------------------------------------------------


void __fastcall TfrmRegister::edtIDNumExit(TObject *Sender)
{
	 edtNumberExit(this);
	if(!(IDNumber==edtIDNum->Text.Trim())){
	  invalidIDNumber=0;
	  lblInvalidID->Visible=1;
	} else{
		invalidIDNumber=1;
		lblInvalidID->Visible=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtPass2Exit(TObject *Sender)
{
	if (!(edtPass1->Text.Trim()==edtPass2->Text.Trim())||edtPass2->Text.IsEmpty()){

		lblPassMatch->Font->Color=clRed;
		lblPassMatch->Visible=1;
		passMatch=0;
	}else{
		 passMatch=1;
		lblPassMatch->Visible=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::edtEmailExit(TObject *Sender)
{
	String temp ;
	validEmail=0;
	String emailAddr=edtEmail->Text.Trim();
	if(!emailAddr.IsEmpty()){
		if(emailAddr.Pos('@')>1){

		   temp= edtEmail->Text.UpperCase().Delete(1,edtEmail->Text.Pos('@'));

				if(temp.Pos('.')>1&&temp.Length()>3){
				  validEmail=1;
				}
			}

		}

		if(!validEmail)
			lblInvalidEmail->Visible=1;
			else
			lblInvalidEmail->Visible=0;

}
//---------------------------------------------------------------------------
void __fastcall TfrmRegister::edtOfficeExit(TObject *Sender)
{


	if(edtOffice->Text.IsEmpty()){

		lblOfficeNum->Visible=1;
		validOffice=0;
	}
		else{
			 validOffice=1;
			lblOfficeNum->Visible=0;
		}

		if(ComboBoxUType->ItemIndex==0)
		{
			validOffice=1;
			lblOfficeNum->Visible=0;

		}
}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::btnRegisterClick(TObject *Sender)
{
	ComboBoxUTypeChange(Sender);
	edtNumberExit(Sender);
	edtIDNumExit(this);
	edtEmailExit(this);
	edtOfficeExit(this);
	edtPass2Exit(Sender);

	if(invalidUserID&&invalidIDNumber&&passMatch&&validEmail&&validOffice){



		//update information in student or lectiure rtablew and user table
		DataModuleStudentDB->ADOCommandStudentDB->CommandText="INSERT INTO Users(IDNumber,UserID,Passwords,UserType) VALUES (:IDNum,:UsrID,:Passwrd,:UType)";
		DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("IDNum")->Value=edtIDNum->Text.Trim();
		DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("UsrID")->Value=edtNumber->Text.Trim();
		DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("Passwrd")->Value=edtPass2->Text.Trim();
		DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("UType")->Value=ComboBoxUType->Items->operator [](ComboBoxUType->ItemIndex).Trim();
		DataModuleStudentDB->ADOCommandStudentDB->Execute();


		if(ComboBoxUType->ItemIndex==0){

			DataModuleStudentDB->ADOCommandStudentDB->CommandText="UPDATE Student SET CellNumber=:cellNum,EmailAddress=:emailAdd,Active=:actvt WHERE studentNumber=:UsrID";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("cellNum")->Value=edtPhone1->Text.Trim()+edtPhone->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("emailAdd")->Value=edtEmail->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("actvt")->Value="Yes";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("UsrID")->Value=edtNumber->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Execute();
		}else{

			DataModuleStudentDB->ADOCommandStudentDB->CommandText="UPDATE Lecture SET TelNumber=:cellNum,EmailAddress=:emailAdd,Active=:actvt,OfficeNumber:offNo WHERE LectureID=:UsrID";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("cellNum")->Value=edtPhone1->Text.Trim()+edtPhone->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("emailAdd")->Value=edtEmail->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("actvt")->Value="Yes";
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("offNo")->Value=edtOffice->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Parameters->ParamByName("UsrID")->Value=edtNumber->Text.Trim();
			DataModuleStudentDB->ADOCommandStudentDB->Execute();
		}


	//inform user about success
		PanelSuccessful->Caption="Your Registration was Successful";
		PanelSuccessful->Font->Color=clLime;
		PanelSuccessful->Visible=1;
		lblSucc1->Visible=0;
		lblSucc2->Visible=0;
	}
	else {
			PanelSuccessful->Caption="";
			PanelSuccessful->Visible=1;
		lblSucc1->Font->Color=clRed;
		lblSucc2->Font->Color=clRed;
			lblSucc1->Visible=1;
		lblSucc2->Visible=1;

		if(!registerd) {

		 lblSucc1->Caption="After  Several Attemps Contact Your Lecture Or Administrator";
		 lblSucc2->Caption="Your Registration was Unsuccessful: If You Are Still Unable To Register ";

		}else{


		lblSucc1->Caption="Contact Your Lecture Or Administrator Or Change Your Password";
		 lblSucc2->Caption="Your Registration was Unsuccessful: You Are Already Registered ";

        }


	}


}
//---------------------------------------------------------------------------

void __fastcall TfrmRegister::FormResize(TObject *Sender)
{
	PanelSuccessful->Top=Panel1->Top+Panel1->Height+10;
	PanelSuccessful->Width=Panel1->Width;
}
//---------------------------------------------------------------------------



