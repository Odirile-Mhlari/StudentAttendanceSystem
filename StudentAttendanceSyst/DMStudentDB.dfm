object DataModuleStudentDB: TDataModuleStudentDB
  OldCreateOrder = False
  Height = 415
  Width = 457
  object ADOConnectionStudentDB: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.15.0;Data Source=F:\Technox2015 Pro' +
      'jects\peters docs\studentDB.accdb;Persist Security Inf'
    LoginPrompt = False
    Provider = 'Microsoft.ACE.OLEDB.15.0'
    Left = 48
    Top = 32
  end
  object DataSourceUser: TDataSource
    Left = 160
    Top = 104
  end
  object ADODataSetUser: TADODataSet
    Parameters = <>
    Left = 32
    Top = 96
  end
  object ADOCommandStudentDB: TADOCommand
    Parameters = <>
    Left = 160
    Top = 32
  end
  object ADODataSetStudLect: TADODataSet
    Parameters = <>
    Left = 40
    Top = 144
  end
  object DataSourceStudLect: TDataSource
    Left = 160
    Top = 160
  end
  object DataSourceSubjClass: TDataSource
    Left = 168
    Top = 248
  end
  object ADODataSetSubjClass: TADODataSet
    Parameters = <>
    Left = 40
    Top = 248
  end
  object DataSourceStudLectSubj: TDataSource
    Left = 160
    Top = 304
  end
  object ADODataSetStudLecSubj: TADODataSet
    Parameters = <>
    Left = 32
    Top = 304
  end
  object DataSourceAtend: TDataSource
    Left = 144
    Top = 368
  end
  object ADODataSetAtend: TADODataSet
    Parameters = <>
    Left = 32
    Top = 368
  end
  object DataSourceAttHist: TDataSource
    Left = 376
    Top = 41
  end
  object ADODataSetAttHist: TADODataSet
    Parameters = <>
    Left = 264
    Top = 41
  end
end
