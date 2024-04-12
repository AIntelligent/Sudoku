object AboutBox: TAboutBox
  Left = 694
  Top = 265
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'About'
  ClientHeight = 260
  ClientWidth = 298
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 281
    Height = 209
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    object ProgramIcon: TImage
      Left = 8
      Top = 8
      Width = 65
      Height = 57
      Center = True
      Picture.Data = {
        055449636F6E0000010001002020100000000000E80200001600000028000000
        2000000040000000010004000000000080020000000000000000000000000000
        0000000000000000000080000080000000808000800000008000800080800000
        80808000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
        FFFFFF00FFFFFFFFF7FFFFFFFFFFFF7FFFFFFFFFFFFFFFFFF7FFFFFF8FFFFF7F
        FFDDFFFFFFFFFFFFF7FFFFFF8FFFFF7FFFFFFFFFFFFFFFFFF7FFFFFF8FFFFF7F
        FFDDFFFFFFFFFFFFF7FFFFFF8FFFFF7FFFDDFFFFFFFFFFFFF7FFFFFF8FFFFF7F
        FFFDDFFFFFFFFFFFF7FFFF8F8FFFFF7FFFFFDDFFFFFFFFFFF7FFFFF88FFFFF7F
        FDFFDDFFFFFFFFFFF7FFFFFF8FFFFF7FFFDDDFFFFFFFFFFFF7FFFFFFFFFFFF7F
        FFFFFFFF77777777777777777777777777777777FFFFFFFFF7FFFFFFFFFFFF7F
        FFFFFFFFFFFFFFFFF7FFFFCCCCCFFF7FFFFFFFFFFFFFFFFFF7FFFFFCFFFFFF7F
        FFFFFFFFFFFFFFFFF7FFFFFFCFFFFF7FFFFFFFFFFFFFFFFFF7FFFFFFFCFFFF7F
        FFFFFFFFFFFFFFFFF7FFFFFFFFCFFF7FFFFFFFFFFFFFFFFFF7FFFFFFFFCFFF7F
        FFFFFFFFFFFFFFFFF7FFFFCFFFCFFF7FFFFFFFFFFFFFFFFFF7FFFFFCCCFFFF7F
        FFFFFFFFFFFFFFFFF7FFFFFFFFFFFF7FFFFFFFFF777777777777777777777777
        77777777FFFFFFFFF7FFFFFFFFFFFF7FFFFFFFFFFFFCCCFFF7FFFFFFFFFFFF7F
        FF888FFFFFCFFFCFF7FFFFFFFFFFFF7FF8FFF8FFFFCFFFCFF7FFFFFFFFFFFF7F
        FFFFF8FFFFCFFFCFF7FFFFFFFFFFFF7FFF8888FFFFFCCCFFF7FFFFFFFFFFFF7F
        F8FFF8FFFFCFFFCFF7FFFFFFFFFFFF7FF8FFF8FFFFCFFFCFF7FFFFFFFFFFFF7F
        F8FFF8FFFFFCCCFFF7FFFFFFFFFFFF7FFF888FFFFFFFFFFFF7FFFFFFFFFFFF7F
        FFFFFFFF00000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000}
      IsControl = True
    end
    object ProductName: TLabel
      Left = 88
      Top = 16
      Width = 82
      Height = 13
      Caption = 'HEK SUDOKU'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      IsControl = True
    end
    object Version: TLabel
      Left = 88
      Top = 40
      Width = 83
      Height = 13
      Caption = 'Version 1.1, 2006'
      IsControl = True
    end
    object Copyright: TLabel
      Left = 8
      Top = 80
      Width = 167
      Height = 13
      Caption = 'Copyright (C) Hakan Emre KARTAL'
      IsControl = True
    end
    object Comments: TLabel
      Left = 8
      Top = 104
      Width = 253
      Height = 52
      Caption = 
        'Bu oyunun; sudoku motoru, g'#246'rsel tasarm, algoritmas'#305' ve kodlanma' +
        's'#305' 04/04/2006 tarihinde '#304'skenderun/HATAY'#39'da Hakan Emre KARTAL ta' +
        'raf'#305'ndan yap'#305'ld'#305'.'
      WordWrap = True
      IsControl = True
    end
    object Connection: TLabel
      Left = 8
      Top = 168
      Width = 145
      Height = 26
      Caption = #304'leti'#351'im: hek@nula.com.tr https://github.com/AIntelligent'
      WordWrap = True
    end
  end
  object OKButton: TButton
    Left = 111
    Top = 228
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
end
