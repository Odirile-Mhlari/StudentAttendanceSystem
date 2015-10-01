object frmHome: TfrmHome
  Left = 0
  Top = 0
  Caption = 'Home'
  ClientHeight = 659
  ClientWidth = 758
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
    758
    659)
  PixelsPerInch = 96
  TextHeight = 13
  object Label10: TLabel
    Left = 248
    Top = 392
    Width = 144
    Height = 13
    Caption = 'Time left Before Next Attempt'
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 640
    Width = 758
    Height = 19
    Anchors = [akLeft, akTop, akRight]
    Panels = <
      item
        Width = 658
      end>
  end
  object Panel1: TPanel
    Left = 319
    Top = 83
    Width = 431
    Height = 269
    Anchors = []
    BevelInner = bvLowered
    BevelKind = bkTile
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 103
      Height = 16
      Caption = 'Registred Users'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHotLight
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 27
      Width = 380
      Height = 13
      Caption = 
        'Please use the login form if you already have the appropriate lo' +
        'gin information.'
    end
    object Label3: TLabel
      Left = 8
      Top = 46
      Width = 281
      Height = 13
      Caption = 'If not please contact your system administrator or lecture.'
    end
    object lblUserType: TLabel
      Left = 8
      Top = 163
      Width = 78
      Height = 13
      Caption = 'Student Number'
    end
    object Label5: TLabel
      Left = 8
      Top = 190
      Width = 46
      Height = 13
      Caption = 'Password'
    end
    object lblIncorrectNumber: TLabel
      Left = 247
      Top = 163
      Width = 3
      Height = 13
    end
    object lblIncorrectPass: TLabel
      Left = 247
      Top = 195
      Width = 3
      Height = 13
    end
    object lblIncorrectUserTyp: TLabel
      Left = 247
      Top = 89
      Width = 3
      Height = 13
    end
    object btnForgotPin: TButton
      Left = 136
      Top = 225
      Width = 98
      Height = 25
      Caption = 'Forgot Password?'
      TabOrder = 4
      OnClick = btnForgotPinClick
    end
    object btnLogin: TButton
      Left = 8
      Top = 225
      Width = 97
      Height = 25
      Caption = 'Login'
      TabOrder = 3
      OnClick = btnLoginClick
      OnExit = btnLoginExit
    end
    object btnChangePin: TButton
      Left = 272
      Top = 225
      Width = 105
      Height = 25
      Caption = 'Change Password'
      TabOrder = 5
      OnClick = btnChangePinClick
    end
    object RadioGroupUserType: TRadioGroup
      Left = 0
      Top = 65
      Width = 241
      Height = 72
      Caption = 'Select user type'
      Items.Strings = (
        'Student'
        'Lecture'
        'Administrator')
      TabOrder = 0
      OnClick = RadioGroupUserTypeClick
    end
    object edtNumber: TEdit
      Left = 120
      Top = 160
      Width = 121
      Height = 21
      MaxLength = 9
      NumbersOnly = True
      TabOrder = 1
      OnClick = edtNumberClick
      OnExit = edtNumberExit
    end
    object edtPassword: TEdit
      Left = 120
      Top = 187
      Width = 121
      Height = 21
      MaxLength = 15
      ParentShowHint = False
      PasswordChar = '*'
      ShowHint = False
      TabOrder = 2
    end
    object CheckBox1: TCheckBox
      Left = 247
      Top = 189
      Width = 97
      Height = 17
      Caption = 'Show Password'
      TabOrder = 6
      OnClick = CheckBox1Click
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 36
    Width = 742
    Height = 41
    Anchors = []
    BevelInner = bvLowered
    BevelKind = bkTile
    Caption = 'Atendance System'
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 8
    Top = 83
    Width = 305
    Height = 269
    Anchors = []
    BevelInner = bvLowered
    BevelKind = bkTile
    TabOrder = 3
    object Label6: TLabel
      Left = 16
      Top = 8
      Width = 39
      Height = 16
      Caption = 'Login:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHotLight
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 14
      Top = 27
      Width = 67
      Height = 16
      Caption = 'New Users'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHotLight
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 16
      Top = 49
      Width = 241
      Height = 13
      Caption = 'If you are using this system for the first time  and '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 14
      Top = 89
      Width = 172
      Height = 23
      Caption = 'Click here to register'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHotLight
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Label9Click
    end
    object Label4: TLabel
      Left = 14
      Top = 68
      Width = 176
      Height = 13
      Caption = 'you are a Lecture or Student Please '
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 552
    Top = 65528
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <>
    Options = []
    Left = 456
    Top = 448
  end
  object TimerLogin: TTimer
    OnTimer = TimerLoginTimer
    Left = 208
    Top = 432
  end
end
