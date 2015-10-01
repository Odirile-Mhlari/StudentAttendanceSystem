object frmStudAttendanceHisrory: TfrmStudAttendanceHisrory
  Left = 0
  Top = 0
  Caption = 'frmStudAttendanceHisrory'
  ClientHeight = 544
  ClientWidth = 958
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
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 24
    Top = 8
    Width = 873
    Height = 511
    BevelInner = bvLowered
    BevelKind = bkTile
    Caption = 'Panel2'
    TabOrder = 0
    object Label4: TLabel
      Left = 16
      Top = 401
      Width = 98
      Height = 13
      Caption = 'Summarised History:'
    end
    object Label5: TLabel
      Left = 320
      Top = 19
      Width = 139
      Height = 13
      Caption = 'Detailed Attendance History:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Panel1: TPanel
      Left = 16
      Top = 130
      Width = 298
      Height = 265
      BevelInner = bvLowered
      BevelKind = bkTile
      BevelOuter = bvNone
      TabOrder = 0
      object Label1: TLabel
        Left = 9
        Top = 16
        Width = 108
        Height = 13
        Caption = 'Select Subject To View'
      end
      object Label2: TLabel
        Left = 9
        Top = 84
        Width = 82
        Height = 13
        Caption = 'Select Start Date'
      end
      object Label3: TLabel
        Left = 9
        Top = 155
        Width = 88
        Height = 13
        Caption = 'Show when I was:'
      end
      object DateTimePickerStartD: TDateTimePicker
        Left = 9
        Top = 103
        Width = 272
        Height = 21
        Date = 42206.247380127320000000
        Time = 42206.247380127320000000
        Color = clBtnFace
        TabOrder = 0
        OnChange = DateTimePickerStartDChange
      end
      object ComboBoxSubject: TComboBox
        Left = 9
        Top = 35
        Width = 272
        Height = 22
        Style = csOwnerDrawFixed
        TabOrder = 1
        OnChange = ComboBoxSubjectChange
      end
      object CheckListBoxPresAbs: TCheckListBox
        Left = 9
        Top = 174
        Width = 272
        Height = 35
        BevelInner = bvLowered
        BevelKind = bkTile
        ItemHeight = 13
        Items.Strings = (
          'Present'
          'Absent')
        TabOrder = 2
        OnExit = CheckListBoxPresAbsExit
      end
      object btnCustomHist: TButton
        Left = 9
        Top = 228
        Width = 272
        Height = 25
        Caption = 'Attendance History In Custoised View'
        TabOrder = 3
        OnClick = btnCustomHistClick
      end
    end
    object RadioGroupDefault: TRadioGroup
      Left = 16
      Top = 19
      Width = 298
      Height = 105
      Caption = 'Slect History View Option'
      Items.Strings = (
        'Default View'
        'Custom View')
      TabOrder = 1
      OnClick = RadioGroupDefaultClick
    end
    object DBGridTodaySubjs: TDBGrid
      Left = 320
      Top = 38
      Width = 537
      Height = 455
      TabOrder = 2
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
    end
    object StringGrid1: TStringGrid
      Left = 16
      Top = 420
      Width = 298
      Height = 73
      TabOrder = 3
      ColWidths = (
        64
        68
        64
        64
        64)
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 525
    Width = 958
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    ExplicitLeft = 2
    ExplicitTop = 486
    ExplicitWidth = 865
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 617
    Top = 216
  end
end
