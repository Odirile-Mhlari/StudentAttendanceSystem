object frmChangePassword: TfrmChangePassword
  Left = 0
  Top = 0
  Caption = 'Change Password'
  ClientHeight = 447
  ClientWidth = 820
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    820
    447)
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 239
    Top = 129
    Width = 498
    Height = 208
    Anchors = []
    BevelInner = bvLowered
    BevelKind = bkTile
    TabOrder = 0
    object lblUserType: TLabel
      Left = 24
      Top = 16
      Width = 56
      Height = 13
      Caption = 'lblUserType'
    end
    object Label2: TLabel
      Left = 24
      Top = 99
      Width = 70
      Height = 13
      Caption = 'New Password'
    end
    object Label3: TLabel
      Left = 24
      Top = 126
      Width = 110
      Height = 13
      Caption = 'Confirm New Password'
    end
    object lblPasswordNoMatch: TLabel
      Left = 327
      Top = 112
      Width = 3
      Height = 13
    end
    object Label1: TLabel
      Left = 24
      Top = 48
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
    object Label4: TLabel
      Left = 24
      Top = 75
      Width = 65
      Height = 13
      Caption = 'Old Password'
    end
    object lblInvalidOldPass: TLabel
      Left = 327
      Top = 80
      Width = 3
      Height = 13
    end
    object edtNewPassword: TEdit
      Left = 200
      Top = 99
      Width = 121
      Height = 21
      MaxLength = 15
      PasswordChar = '*'
      TabOrder = 3
      OnEnter = edtNewPasswordEnter
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
      Top = 126
      Width = 121
      Height = 21
      MaxLength = 15
      PasswordChar = '*'
      TabOrder = 4
      OnEnter = edtMatchPasswordEnter
      OnExit = edtMatchPasswordExit
    end
    object btnGoBackToLogin: TButton
      Left = 132
      Top = 168
      Width = 112
      Height = 25
      Caption = 'Go Back To Login'
      TabOrder = 6
      OnClick = btnGoBackToLoginClick
    end
    object btnSaveChanges: TButton
      Left = 16
      Top = 168
      Width = 110
      Height = 25
      Caption = 'Save Changes'
      TabOrder = 5
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
    object edtOldPass: TEdit
      Left = 200
      Top = 72
      Width = 121
      Height = 21
      TabOrder = 2
      OnEnter = edtOldPassEnter
    end
  end
  object Panel1: TPanel
    Left = 98
    Top = 16
    Width = 569
    Height = 57
    Anchors = []
    BevelInner = bvLowered
    BevelKind = bkTile
    Caption = 'Panel1'
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 239
    Top = 367
    Width = 498
    Height = 41
    BevelInner = bvLowered
    BevelKind = bkTile
    TabOrder = 2
  end
end
