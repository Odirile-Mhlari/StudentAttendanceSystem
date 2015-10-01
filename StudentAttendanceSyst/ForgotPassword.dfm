object frmForgotPasswork: TfrmForgotPasswork
  Left = 0
  Top = 0
  Caption = 'Forgot Password'
  ClientHeight = 331
  ClientWidth = 776
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    776
    331)
  PixelsPerInch = 96
  TextHeight = 13
  object lblGoBacToLogin: TLabel
    Left = 368
    Top = 72
    Width = 146
    Height = 13
    Anchors = []
    Caption = 'Click Here To Go Back To Login'
    OnClick = lblGoBacToLoginClick
  end
  object Panel1: TPanel
    Left = 98
    Top = 8
    Width = 569
    Height = 57
    Anchors = []
    BevelInner = bvLowered
    BevelKind = bkTile
    Caption = 'Panel1'
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 239
    Top = 104
    Width = 498
    Height = 177
    Anchors = []
    BevelInner = bvLowered
    BevelKind = bkTile
    TabOrder = 1
    object lblUserType: TLabel
      Left = 24
      Top = 16
      Width = 56
      Height = 13
      Caption = 'lblUserType'
    end
    object Label2: TLabel
      Left = 24
      Top = 75
      Width = 70
      Height = 13
      Caption = 'New Password'
    end
    object Label3: TLabel
      Left = 24
      Top = 102
      Width = 110
      Height = 13
      Caption = 'Confirm New Password'
    end
    object lblPasswordNoMatch: TLabel
      Left = 327
      Top = 92
      Width = 3
      Height = 13
    end
    object Label1: TLabel
      Left = 24
      Top = 43
      Width = 51
      Height = 13
      Caption = 'ID Number'
    end
    object lblIncorrectIDNumber: TLabel
      Left = 327
      Top = 53
      Width = 3
      Height = 13
    end
    object lblInvalidUserID: TLabel
      Left = 327
      Top = 16
      Width = 3
      Height = 13
    end
    object edtNewPassword: TEdit
      Left = 200
      Top = 72
      Width = 121
      Height = 21
      MaxLength = 15
      PasswordChar = '*'
      TabOrder = 2
    end
    object edtUserID: TEdit
      Left = 200
      Top = 18
      Width = 121
      Height = 21
      MaxLength = 9
      NumbersOnly = True
      TabOrder = 0
      OnEnter = edtUserIDEnter
      OnExit = edtUserIDExit
    end
    object edtMatchPassword: TEdit
      Left = 200
      Top = 99
      Width = 121
      Height = 21
      MaxLength = 15
      PasswordChar = '*'
      TabOrder = 3
      OnExit = edtMatchPasswordExit
    end
    object btnGoBackToLogin: TButton
      Left = 145
      Top = 144
      Width = 112
      Height = 25
      Caption = 'Go Back To Login'
      TabOrder = 5
      OnClick = btnGoBackToLoginClick
    end
    object btnSaveChanges: TButton
      Left = 29
      Top = 144
      Width = 110
      Height = 25
      Caption = 'Save Changes'
      TabOrder = 4
      OnClick = btnSaveChangesClick
    end
    object edtIDNumber: TEdit
      Left = 200
      Top = 45
      Width = 121
      Height = 21
      MaxLength = 13
      NumbersOnly = True
      TabOrder = 1
      OnEnter = edtIDNumberEnter
      OnExit = edtIDNumberExit
    end
  end
  object Panel3: TPanel
    Left = 239
    Top = 287
    Width = 498
    Height = 41
    BevelInner = bvLowered
    BevelKind = bkTile
    TabOrder = 2
  end
end
