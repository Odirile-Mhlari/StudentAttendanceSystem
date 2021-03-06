//---------------------------------------------------------------------------

#ifndef DMStudentDBH
#define DMStudentDBH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Datasnap.DBClient.hpp>
//---------------------------------------------------------------------------
class TDataModuleStudentDB : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnectionStudentDB;
	TDataSource *DataSourceUser;
	TADODataSet *ADODataSetUser;
	TADOCommand *ADOCommandStudentDB;
	TADODataSet *ADODataSetStudLect;
	TDataSource *DataSourceStudLect;
	TDataSource *DataSourceSubjClass;
	TADODataSet *ADODataSetSubjClass;
	TDataSource *DataSourceStudLectSubj;
	TADODataSet *ADODataSetStudLecSubj;
	TDataSource *DataSourceAtend;
	TADODataSet *ADODataSetAtend;
	TDataSource *DataSourceAttHist;
	TADODataSet *ADODataSetAttHist;
private:	// User declarations
public:		// User declarations
	__fastcall TDataModuleStudentDB(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModuleStudentDB *DataModuleStudentDB;
//---------------------------------------------------------------------------
#endif
