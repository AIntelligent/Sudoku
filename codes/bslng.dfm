object formHEKsudoku: TformHEKsudoku
  Left = 381
  Top = 118
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  BorderWidth = 3
  Caption = '--=| HEK Sudoku |=--'
  ClientHeight = 674
  ClientWidth = 646
  Color = clBtnFace
  Font.Charset = TURKISH_CHARSET
  Font.Color = clWindowText
  Font.Height = -48
  Font.Name = 'Arial'
  Font.Style = [fsBold]
  Menu = MainMenu
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnKeyDown = GridKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 56
  object PaintBox: TPaintBox
    Left = 0
    Top = 46
    Width = 53
    Height = 593
    Align = alLeft
    Font.Charset = TURKISH_CHARSET
    Font.Color = clWhite
    Font.Height = -37
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
    OnPaint = PaintBoxPaint
  end
  object Bevel: TBevel
    Left = 53
    Top = 46
    Width = 0
    Height = 593
    Align = alLeft
    Shape = bsSpacer
    Visible = False
  end
  object Grid: TStringGrid
    Left = 53
    Top = 46
    Width = 593
    Height = 593
    HelpType = htKeyword
    Align = alClient
    BorderStyle = bsNone
    ColCount = 9
    DefaultColWidth = 65
    DefaultRowHeight = 65
    DefaultDrawing = False
    Enabled = False
    FixedCols = 0
    RowCount = 9
    FixedRows = 0
    Font.Charset = TURKISH_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    Options = [goVertLine, goHorzLine]
    ParentFont = False
    ScrollBars = ssNone
    TabOrder = 0
    OnClick = GridClick
    OnDrawCell = GridDrawCell
    OnKeyDown = GridKeyDown
    OnKeyPress = GridKeyPress
  end
  object ToolBar: TToolBar
    Left = 0
    Top = 0
    Width = 646
    Height = 46
    AutoSize = True
    BorderWidth = 1
    ButtonHeight = 40
    ButtonWidth = 33
    Flat = True
    Font.Charset = TURKISH_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    Indent = 3
    ParentFont = False
    ShowCaptions = True
    TabOrder = 1
    OnCustomDrawButton = ToolBarCustomDrawButton
    object ToolButton_1: TToolButton
      Tag = 1
      Left = 3
      Top = 0
      AutoSize = True
      Caption = '1'
      Grouped = True
      ImageIndex = 0
      OnClick = ToolButton_1Click
    end
    object ToolButton_2: TToolButton
      Tag = 2
      Left = 29
      Top = 0
      AutoSize = True
      Caption = '2'
      Grouped = True
      ImageIndex = 1
      OnClick = ToolButton_1Click
    end
    object ToolButton_3: TToolButton
      Tag = 3
      Left = 55
      Top = 0
      AutoSize = True
      Caption = '3'
      Grouped = True
      ImageIndex = 2
      OnClick = ToolButton_1Click
    end
    object ToolButton_4: TToolButton
      Tag = 4
      Left = 81
      Top = 0
      AutoSize = True
      Caption = '4'
      Grouped = True
      ImageIndex = 3
      OnClick = ToolButton_1Click
    end
    object ToolButton_5: TToolButton
      Tag = 5
      Left = 107
      Top = 0
      AutoSize = True
      Caption = '5'
      Grouped = True
      ImageIndex = 4
      OnClick = ToolButton_1Click
    end
    object ToolButton_6: TToolButton
      Tag = 6
      Left = 133
      Top = 0
      AutoSize = True
      Caption = '6'
      Grouped = True
      ImageIndex = 5
      OnClick = ToolButton_1Click
    end
    object ToolButton_7: TToolButton
      Tag = 7
      Left = 159
      Top = 0
      AutoSize = True
      Caption = '7'
      Grouped = True
      ImageIndex = 6
      OnClick = ToolButton_1Click
    end
    object ToolButton_8: TToolButton
      Tag = 8
      Left = 185
      Top = 0
      AutoSize = True
      Caption = '8'
      Grouped = True
      ImageIndex = 7
      OnClick = ToolButton_1Click
    end
    object ToolButton_9: TToolButton
      Tag = 9
      Left = 211
      Top = 0
      AutoSize = True
      Caption = '9'
      Grouped = True
      ImageIndex = 8
      OnClick = ToolButton_1Click
    end
    object Separator_1: TToolButton
      Left = 237
      Top = 0
      Width = 8
      AutoSize = True
      Caption = 'Separator_1'
      ImageIndex = 9
      Style = tbsSeparator
    end
    object ToolButton_Clear: TToolButton
      Tag = 10
      Left = 245
      Top = 0
      AutoSize = True
      Caption = 'C'
      ImageIndex = 9
      OnClick = ToolButton_1Click
    end
    object Separator_2: TToolButton
      Left = 276
      Top = 0
      Width = 9
      Caption = 'Separator_2'
      ImageIndex = 10
      Style = tbsSeparator
    end
    object ToolButton_Eposta: TToolButton
      Left = 285
      Top = 0
      AutoSize = True
      Caption = '@'
      ImageIndex = 10
      OnClick = ToolButton_EpostaClick
    end
    object Separator_3: TToolButton
      Left = 322
      Top = 0
      Width = 8
      Caption = 'Separator_3'
      ImageIndex = 11
      Style = tbsSeparator
    end
    object ToolButton_IpUcu: TToolButton
      Left = 330
      Top = 0
      Caption = '?'
      ImageIndex = 12
      OnClick = ToolButton_IpUcuClick
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 639
    Width = 646
    Height = 35
    Panels = <
      item
        Alignment = taCenter
        Bevel = pbNone
        Style = psOwnerDraw
        Text = '~F2~ Yeni oyun'
        Width = 100
      end
      item
        Alignment = taCenter
        Bevel = pbNone
        Style = psOwnerDraw
        Text = '~F3~ '#199#246'z'#252'm'
        Width = 100
      end
      item
        Alignment = taCenter
        Bevel = pbNone
        Style = psOwnerDraw
        Text = 'hek@nula.com.tr'
        Width = 205
      end
      item
        Alignment = taCenter
        Bevel = pbNone
        Style = psOwnerDraw
        Text = '00:00:00'
        Width = 100
      end
      item
        Alignment = taCenter
        Bevel = pbNone
        Style = psOwnerDraw
        Text = 'Yeni '#214#287'renen'
        Width = 100
      end>
    SimplePanel = False
    SizeGrip = False
    OnClick = StatusBarClick
    OnDrawPanel = StatusBarDrawPanel
  end
  object MainMenu: TMainMenu
    Left = 315
    Top = 210
    object mItem_Oyun: TMenuItem
      Caption = 'Oyun'
      object mItem_Yeni: TMenuItem
        Caption = 'Yeni'
        ShortCut = 113
        OnClick = mItem_YeniClick
      end
      object mItem_Cozum: TMenuItem
        Caption = #199#246'z'#252'm'
        ShortCut = 114
        OnClick = mItem_CozumClick
      end
      object mItem_Derece: TMenuItem
        Caption = 'En '#304'yi Dereceler'
        ShortCut = 115
        Visible = False
      end
      object mItem_Seviyeler: TMenuItem
        Caption = 'Seviyeler'
        object mItem_SeviyeCokAcemi: TMenuItem
          Caption = #199'ok Acemi'
          GroupIndex = 1
          OnClick = mItem_SeviyeUzmanClick
        end
        object mItem_SeviyeAcemi: TMenuItem
          Tag = 1
          Caption = 'Acemi'
          GroupIndex = 1
          OnClick = mItem_SeviyeUzmanClick
        end
        object mItem_SeviyeOgrenen: TMenuItem
          Tag = 2
          Caption = 'Yeni '#214#287'renen'
          Checked = True
          GroupIndex = 1
          OnClick = mItem_SeviyeUzmanClick
        end
        object mItem_SeviyeBilen: TMenuItem
          Tag = 3
          Caption = #304'yi Bilen'
          GroupIndex = 1
          OnClick = mItem_SeviyeUzmanClick
        end
        object mItem_SeviyeUsta: TMenuItem
          Tag = 4
          Caption = 'Usta'
          GroupIndex = 1
          OnClick = mItem_SeviyeUzmanClick
        end
        object mItem_SeviyeUzman: TMenuItem
          Tag = 5
          Caption = 'Uzman'
          GroupIndex = 1
          OnClick = mItem_SeviyeUzmanClick
        end
      end
      object mItem_Kaydet: TMenuItem
        Caption = 'Kaydet'
        ShortCut = 16467
        OnClick = mItem_KaydetClick
      end
      object mItem_GeriCagir: TMenuItem
        Caption = 'Y'#252'kle...'
        ShortCut = 16463
        OnClick = mItem_GeriCagirClick
      end
      object mItem_Bos_1: TMenuItem
        Caption = '-'
      end
      object mItem_Kapat: TMenuItem
        Caption = 'Kapat'
        ShortCut = 32883
        OnClick = mItem_KapatClick
      end
    end
    object mItem_Hakkinda: TMenuItem
      Caption = 'Hakk'#305'nda'
      OnClick = mItem_HakkindaClick
    end
  end
  object ApplicationEvents: TApplicationEvents
    OnIdle = ApplicationEventsIdle
    OnMessage = ApplicationEventsMessage
    Left = 300
    Top = 244
  end
  object Timer: TTimer
    Enabled = False
    Interval = 500
    OnTimer = TimerTimer
    Left = 330
    Top = 177
  end
  object Timer_DemoAnim: TTimer
    Enabled = False
    Interval = 75
    OnTimer = Timer_DemoAnimTimer
    Left = 345
    Top = 144
  end
  object OpenDialog: TOpenDialog
    DefaultExt = '*.HEK'
    Filter = 'Kay'#305't dosyalar'#305'|*.HEK'
    InitialDir = '.\Save'
    Options = [ofNoChangeDir, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    OptionsEx = [ofExNoPlacesBar]
    Left = 285
    Top = 277
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '*.HEK'
    Filter = 'Kay'#305't dosyalar'#305'|*.HEK'
    InitialDir = '.\Save'
    Options = [ofOverwritePrompt, ofNoChangeDir, ofPathMustExist, ofCreatePrompt, ofEnableSizing]
    OptionsEx = [ofExNoPlacesBar]
    Left = 270
    Top = 311
  end
end
