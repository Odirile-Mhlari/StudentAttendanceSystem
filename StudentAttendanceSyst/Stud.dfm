object frmStud: TfrmStud
  Left = 0
  Top = 0
  Caption = 'frmStud'
  ClientHeight = 696
  ClientWidth = 617
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnResize = FormResize
  DesignSize = (
    617
    696)
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TPanel
    Left = 64
    Top = 144
    Width = 497
    Height = 218
    Anchors = []
    BevelInner = bvLowered
    BevelKind = bkTile
    TabOrder = 0
    object btnMarkRegister: TButton
      Left = 24
      Top = 24
      Width = 449
      Height = 25
      Caption = 'Click Here To Mark The Register     '
      TabOrder = 0
      OnClick = btnMarkRegisterClick
    end
    object btnViewRegister: TButton
      Left = 24
      Top = 96
      Width = 449
      Height = 25
      Caption = 'Click Here To View Your Attendance History Register'
      TabOrder = 1
      OnClick = btnViewRegisterClick
    end
    object btnViewTimeTable: TButton
      Left = 24
      Top = 168
      Width = 449
      Height = 25
      Caption = 'Click Here To View Your TimeTable     '
      TabOrder = 2
      OnClick = btnViewTimeTableClick
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 677
    Width = 617
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    ExplicitLeft = -102
    ExplicitTop = 645
    ExplicitWidth = 719
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 464
  end
  object Timer2: TTimer
    OnTimer = Timer2Timer
    Left = 528
    Top = 464
  end
end
