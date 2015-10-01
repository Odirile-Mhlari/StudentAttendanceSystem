object frmStudTimeTable: TfrmStudTimeTable
  Left = 0
  Top = 0
  Caption = 'frmStudTimeTable'
  ClientHeight = 669
  ClientWidth = 719
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  DesignSize = (
    719
    669)
  PixelsPerInch = 96
  TextHeight = 13
  object PanelForm: TPanel
    Left = 0
    Top = 8
    Width = 721
    Height = 665
    Anchors = []
    TabOrder = 0
    DesignSize = (
      721
      665)
    object Panel2: TPanel
      Left = 39
      Top = 89
      Width = 638
      Height = 550
      Anchors = []
      BevelInner = bvLowered
      BevelKind = bkTile
      TabOrder = 0
      object Label1: TLabel
        Left = 16
        Top = 37
        Width = 184
        Height = 13
        Caption = 'Your Current Class Is                          :'
      end
      object Label2: TLabel
        Left = 16
        Top = 67
        Width = 184
        Height = 13
        Caption = 'The Class Started At                           :'
      end
      object Label3: TLabel
        Left = 16
        Top = 437
        Width = 178
        Height = 13
        Caption = 'Lecture Name                                    :'
      end
      object Label4: TLabel
        Left = 11
        Top = 15
        Width = 146
        Height = 16
        Caption = 'Currect Class Information'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 16
        Top = 94
        Width = 184
        Height = 13
        Caption = 'The Venue Is                                       :'
      end
      object Label6: TLabel
        Left = 16
        Top = 404
        Width = 112
        Height = 16
        Caption = 'Lecture Information'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label7: TLabel
        Left = 16
        Top = 468
        Width = 178
        Height = 13
        Caption = 'Office Number                                   :'
      end
      object Label8: TLabel
        Left = 16
        Top = 495
        Width = 177
        Height = 13
        Caption = 'Tell Number                                       :'
      end
      object Label9: TLabel
        Left = 17
        Top = 523
        Width = 178
        Height = 13
        Caption = 'Email Address                                    :'
      end
      object Label10: TLabel
        Left = 16
        Top = 154
        Width = 184
        Height = 13
        Caption = 'Concept To Be Covered                      :'
      end
      object Label11: TLabel
        Left = 21
        Top = 228
        Width = 179
        Height = 13
        Caption = 'Was The Concept  Covered              ?'
      end
      object Label12: TLabel
        Left = 21
        Top = 296
        Width = 175
        Height = 13
        Caption = 'Please Rate The Lesson                   :'
      end
      object lblRatin: TLabel
        Left = 398
        Top = 296
        Width = 114
        Height = 13
        Caption = 'Please Rate The Lesson'
        Color = clBtnFace
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentColor = False
        ParentFont = False
      end
      object lblAckn: TLabel
        Left = 398
        Top = 228
        Width = 146
        Height = 13
        Caption = 'Please Acknoledge The Lesson'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label14: TLabel
        Left = 21
        Top = 324
        Width = 176
        Height = 13
        Caption = 'Say Something About The Lesson    :'
      end
      object edtSubjName: TEdit
        Left = 207
        Top = 34
        Width = 185
        Height = 21
        ReadOnly = True
        TabOrder = 0
        Text = 'edtSubjName'
      end
      object edtStartTime: TEdit
        Left = 207
        Top = 61
        Width = 185
        Height = 21
        ReadOnly = True
        TabOrder = 1
        Text = 'edtStartTime'
      end
      object edtLectName: TEdit
        Left = 207
        Top = 431
        Width = 185
        Height = 21
        ReadOnly = True
        TabOrder = 3
        Text = 'edtLectName'
      end
      object edtVenue: TEdit
        Left = 207
        Top = 88
        Width = 185
        Height = 21
        ReadOnly = True
        TabOrder = 2
        Text = 'edtVenue'
      end
      object edtOfficeNum: TEdit
        Left = 207
        Top = 458
        Width = 185
        Height = 21
        ReadOnly = True
        TabOrder = 4
        Text = 'edtOfficeNum'
      end
      object edtEmail: TEdit
        Left = 207
        Top = 512
        Width = 185
        Height = 21
        ReadOnly = True
        TabOrder = 6
        Text = 'edtEmail'
      end
      object edtTellNo: TEdit
        Left = 207
        Top = 485
        Width = 185
        Height = 21
        ReadOnly = True
        TabOrder = 5
        Text = 'edtTellNo'
      end
      object RadioGroupAcknLadge: TRadioGroup
        Left = 207
        Top = 212
        Width = 185
        Height = 43
        Caption = 'Acknowledgement:'
        Items.Strings = (
          'Yes'
          'No')
        TabOrder = 7
        OnClick = RadioGroupAcknLadgeClick
      end
      object RichEditConcept: TRichEdit
        Left = 207
        Top = 132
        Width = 185
        Height = 58
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'RichEditConcept')
        ParentFont = False
        ReadOnly = True
        TabOrder = 8
        Zoom = 100
      end
      object ComboBoxRating: TComboBox
        Left = 207
        Top = 296
        Width = 185
        Height = 22
        Style = csOwnerDrawFixed
        TabOrder = 9
        OnChange = ComboBoxRatingChange
      end
      object RichEditComment: TRichEdit
        Left = 207
        Top = 324
        Width = 185
        Height = 69
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'RichEditComment')
        ParentFont = False
        TabOrder = 10
        Zoom = 100
      end
    end
    object StatusBar1: TStatusBar
      Left = 1
      Top = 645
      Width = 719
      Height = 19
      Panels = <
        item
          Width = 50
        end>
    end
    object PanelTodayClasses: TPanel
      Left = 39
      Top = 89
      Width = 638
      Height = 244
      Anchors = []
      BevelInner = bvLowered
      BevelKind = bkTile
      Caption = 'PanelTodayClasses'
      TabOrder = 2
      DesignSize = (
        634
        240)
      object Label13: TLabel
        Left = 11
        Top = 17
        Width = 242
        Height = 16
        Caption = 'Here Are Your Next Classes ForToday'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object StringGridTodaySubjs: TStringGrid
        Left = 7
        Top = 52
        Width = 614
        Height = 171
        Anchors = []
        BevelInner = bvLowered
        BevelKind = bkTile
        FixedColor = clRed
        GradientEndColor = clBtnFace
        TabOrder = 0
        ColWidths = (
          64
          64
          64
          64
          64)
        RowHeights = (
          24
          24
          21
          24
          24)
      end
    end
    object Panel1: TPanel
      Left = 35
      Top = 11
      Width = 638
      Height = 41
      BevelInner = bvLowered
      BevelKind = bkTile
      Caption = 
        'You Have No Active Class: Your Next Class Is Subject Name At Tim' +
        'e'
      TabOrder = 3
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 619
    Top = 24
  end
end
