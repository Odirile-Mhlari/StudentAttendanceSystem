object frmRegister: TfrmRegister
  Left = 0
  Top = 0
  Anchors = []
  Caption = 'Register'
  ClientHeight = 660
  ClientWidth = 692
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    692
    660)
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 99
    Top = 17
    Width = 481
    Height = 561
    Anchors = []
    TabOrder = 0
    object Panel2: TPanel
      Left = 1
      Top = 1
      Width = 479
      Height = 559
      Align = alClient
      Anchors = []
      BevelInner = bvLowered
      BevelKind = bkTile
      TabOrder = 0
      object Label4: TLabel
        Left = 41
        Top = 230
        Width = 55
        Height = 13
        Caption = 'ID Number:'
      end
      object lblTellCell: TLabel
        Left = 41
        Top = 273
        Width = 74
        Height = 13
        Caption = 'Phone Number:'
      end
      object lblOffice: TLabel
        Left = 43
        Top = 429
        Width = 71
        Height = 13
        Caption = 'Ofiice Number:'
      end
      object Label7: TLabel
        Left = 2
        Top = 2
        Width = 471
        Height = 18
        Align = alTop
        Alignment = taCenter
        Caption = 'Enter your details in the supplied fields '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitWidth = 301
      end
      object Label13: TLabel
        Left = 43
        Top = 351
        Width = 50
        Height = 13
        Caption = 'Password:'
      end
      object Label14: TLabel
        Left = 43
        Top = 386
        Width = 90
        Height = 13
        Caption = 'Confirm Password:'
      end
      object Label15: TLabel
        Left = 43
        Top = 316
        Width = 28
        Height = 13
        Caption = 'Email:'
      end
      object lblInvalidNumber: TLabel
        Left = 320
        Top = 109
        Width = 153
        Height = 13
        Caption = 'Invalid Student/Lecture Number'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object lblInvalidID: TLabel
        Left = 317
        Top = 230
        Width = 86
        Height = 13
        Caption = 'Invalid ID Number'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object lblInvalidEmail: TLabel
        Left = 317
        Top = 329
        Width = 105
        Height = 13
        Caption = 'Invalid E-mail Address'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object lblPassMatch: TLabel
        Left = 318
        Top = 364
        Width = 119
        Height = 13
        Caption = 'Passwords Do Not Match'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object lblUserType: TLabel
        Left = 40
        Top = 109
        Width = 29
        Height = 13
        Caption = 'Code:'
      end
      object Label3: TLabel
        Left = 43
        Top = 147
        Width = 55
        Height = 13
        Caption = 'First Name:'
      end
      object Label2: TLabel
        Left = 43
        Top = 187
        Width = 54
        Height = 13
        Caption = 'Last Name:'
      end
      object lblUType: TLabel
        Left = 40
        Top = 66
        Width = 85
        Height = 13
        Caption = 'Select User Type:'
      end
      object lblIncorrectUserTyp: TLabel
        Left = 319
        Top = 66
        Width = 84
        Height = 13
        Caption = 'Invalid User Type'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object lblOfficeNum: TLabel
        Left = 317
        Top = 429
        Width = 135
        Height = 13
        Caption = ' Enter Office Number or N/A'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object edtIDNum: TEdit
        Left = 166
        Top = 227
        Width = 145
        Height = 21
        Hint = 'Identity number contains digits only'
        MaxLength = 13
        NumbersOnly = True
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnEnter = edtIDNumEnter
        OnExit = edtIDNumExit
      end
      object edtPhone: TEdit
        Left = 197
        Top = 270
        Width = 115
        Height = 21
        Hint = 'Phone number can only contain digits'
        MaxLength = 9
        NumbersOnly = True
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnEnter = edtPhoneEnter
      end
      object edtOffice: TEdit
        Left = 166
        Top = 426
        Width = 145
        Height = 21
        MaxLength = 15
        TabOrder = 7
        OnEnter = edtOfficeEnter
        OnExit = edtOfficeExit
      end
      object btnRegister: TButton
        Left = 36
        Top = 505
        Width = 97
        Height = 25
        Caption = 'Register'
        TabOrder = 8
        OnClick = btnRegisterClick
      end
      object edtPhone1: TEdit
        Left = 165
        Top = 270
        Width = 26
        Height = 21
        Enabled = False
        TabOrder = 10
        Text = '+27'
      end
      object edtEmail: TEdit
        Left = 166
        Top = 321
        Width = 145
        Height = 21
        MaxLength = 35
        TabOrder = 4
        OnEnter = edtEmailEnter
        OnExit = edtEmailExit
      end
      object edtPass1: TEdit
        Left = 167
        Top = 348
        Width = 145
        Height = 21
        MaxLength = 10
        PasswordChar = '*'
        TabOrder = 5
        OnEnter = edtPass1Enter
      end
      object edtPass2: TEdit
        Left = 167
        Top = 375
        Width = 145
        Height = 21
        MaxLength = 10
        PasswordChar = '*'
        TabOrder = 6
        OnEnter = edtPass2Enter
        OnExit = edtPass2Exit
      end
      object edtNumber: TEdit
        Left = 167
        Top = 106
        Width = 147
        Height = 21
        Hint = 'Digits only are allowed here'
        MaxLength = 9
        NumbersOnly = True
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnEnter = edtNumberEnter
        OnExit = edtNumberExit
      end
      object btnGoToLogin: TButton
        Left = 165
        Top = 505
        Width = 101
        Height = 25
        Caption = 'Go Back To Login'
        TabOrder = 9
        OnClick = btnGoToLoginClick
      end
      object edtFirstName: TEdit
        Left = 167
        Top = 144
        Width = 145
        Height = 21
        Enabled = False
        MaxLength = 15
        TabOrder = 11
        OnEnter = edtFirstNameEnter
      end
      object edtLastName: TEdit
        Left = 167
        Top = 184
        Width = 145
        Height = 21
        Enabled = False
        MaxLength = 15
        TabOrder = 12
        OnEnter = edtLastNameEnter
      end
      object ComboBoxUType: TComboBox
        Left = 165
        Top = 63
        Width = 148
        Height = 22
        Style = csOwnerDrawFixed
        TabOrder = 0
        OnChange = ComboBoxUTypeChange
      end
    end
  end
  object PanelSuccessful: TPanel
    Left = 99
    Top = 584
    Width = 479
    Height = 77
    Anchors = []
    Caption = 'You Have Successfully Registered'
    Font.Charset = ANSI_CHARSET
    Font.Color = clLime
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    object lblSucc2: TLabel
      Left = 2
      Top = 16
      Width = 464
      Height = 16
      Caption = 
        'Your Registration was Unsuccessful: If You Are Still Unable To R' +
        'egister '
    end
    object lblSucc1: TLabel
      Left = 2
      Top = 38
      Width = 419
      Height = 16
      Caption = ' After  Several Attemps Contact Your Lecture Or Administrtator'
    end
  end
end
