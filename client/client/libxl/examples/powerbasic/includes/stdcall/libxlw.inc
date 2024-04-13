#INCLUDE THIS ONCE

#INCLUDE ONCE "enum.inc"

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''factory function declarations''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
DECLARE FUNCTION xlCreateBook               LIB "libxl.dll"  ALIAS "xlCreateBookW"     _
                            () AS BookHandle
DECLARE FUNCTION xlCreateXMLBook            LIB "libxl.dll"  ALIAS "xlCreateXMLBookW"  _
                            () AS BookHandle
DECLARE FUNCTION xlCreateBookC               LIB "libxl.dll"  ALIAS "xlCreateBookCW"     _
                            () AS BookHandle
DECLARE FUNCTION xlCreateXMLBookC            LIB "libxl.dll"  ALIAS "xlCreateXMLBookCW"  _
                            () AS BookHandle

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Book function declarations'''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION xlBookLoad                 LIB "libxl.dll"  ALIAS "xlBookLoadW"        _
                            (BYVAL book AS BookHandle, BYREF fileName AS wstringz) AS LONG
DECLARE FUNCTION xlBookSave                 LIB "libxl.dll"  ALIAS "xlBookSaveW"        _
                            (BYVAL book AS BookHandle, BYREF fileName AS wstringz) AS LONG
DECLARE FUNCTION xlBookLoadRaw              LIB "libxl.dll"  ALIAS "xlBookLoadRawW"     _
                            (BYVAL book AS BookHandle, BYREF fileData AS wstringz, BYVAL fileSize AS LONG) AS LONG
DECLARE FUNCTION xlBookSaveRaw              LIB "libxl.dll"  ALIAS "xlBookSaveRawW"     _
                            (BYVAL book AS BookHandle, BYVAL fileData AS wstringz PTR, BYVAL fileSize AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookAddSheet             LIB "libxl.dll"  ALIAS "xlBookAddSheetW"    _
                            (BYVAL book AS BookHandle, BYref sheetName AS wstringz, BYVAL initSheet AS SheetHandle) AS SheetHandle
DECLARE FUNCTION xlBookInsertSheet          LIB "libxl.dll"  ALIAS "xlBookInsertSheetW" _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG, BYREF sheetName AS wstringz, BYVAL initSheet AS SheetHandle) AS SheetHandle
DECLARE FUNCTION xlBookGetSheet             LIB "libxl.dll"  ALIAS "xlBookGetSheetW"    _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS SheetHandle
DECLARE FUNCTION xlBookSheetType            LIB "libxl.dll"  ALIAS "xlBookSheetTypeW"   _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlBookDelSheet             LIB "libxl.dll"  ALIAS "xlBookDelSheetW"    _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlBookSheetCount           LIB "libxl.dll"  ALIAS "xlBookSheetCountW"  _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookAddFormat            LIB "libxl.dll"  ALIAS "xlBookAddFormatW"          _
                            (BYVAL book AS BookHandle, BYVAL initFormat AS FormatHandle) AS FormatHandle
DECLARE FUNCTION xlBookAddFont              LIB "libxl.dll"  ALIAS "xlBookAddFontW"            _
                            (BYVAL book AS BookHandle, BYVAL initFont AS FontHandle) AS FontHandle
DECLARE FUNCTION xlBookAddCustomNumFormat   LIB "libxl.dll"  ALIAS "xlBookAddCustomNumFormatW" _
                            (BYVAL book AS BookHandle, BYREF customNumFormat AS wstringz) AS LONG
DECLARE FUNCTION xlBookCustomNumFormat LIB "libxl.dll"  ALIAS "xlBookCustomNumFormatW"         _                     'check this function for sure
                            (BYVAL book AS BookHandle, BYVAL format AS LONG) as wstring

DECLARE FUNCTION xlBookFormat               LIB "libxl.dll"  ALIAS "xlBookFormatW"      _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS FormatHandle
DECLARE FUNCTION xlBookFormatSize           LIB "libxl.dll"  ALIAS "xlBookFormatSizeW"  _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookFont                 LIB "libxl.dll"  ALIAS "xlBookFontW"        _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS FontHandle
DECLARE FUNCTION xlBookFontSize             LIB "libxl.dll"  ALIAS "xlBookFontSizeW"    _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookDatePack             LIB "libxl.dll"  ALIAS "xlBookDatePackW"    _
                            (BYVAL book AS BookHandle, BYVAL year AS LONG, BYVAL month AS LONG, BYVAL day AS LONG, BYVAL hour AS LONG, BYVAL minute AS LONG, BYVAL second AS LONG, BYVAL millisecond AS LONG) AS DOUBLE
DECLARE FUNCTION xlBookDateUnpack           LIB "libxl.dll"  ALIAS "xlBookDateUnpackW"  _
                            (BYVAL book AS BookHandle, BYVAL value AS DOUBLE, BYVAL year AS LONG PTR, BYVAL month AS LONG PTR, BYVAL day AS LONG PTR, _
                             BYVAL hour AS LONG PTR, BYVAL minute AS LONG PTR, BYVAL second AS LONG PTR, BYVAL millisecond AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookColorPack            LIB "libxl.dll"  ALIAS "xlBookColorPackW"    _
                            (BYVAL book AS BookHandle, BYVAL red AS LONG, BYVAL green AS LONG, BYVAL blue AS LONG) AS LONG
DECLARE sub xlBookColorUnpack          LIB "libxl.dll"  ALIAS "xlBookColorUnpackW"  _
                            (BYVAL book AS BookHandle, BYVAL value AS LONG, BYVAL red AS LONG PTR, BYVAL green AS LONG PTR, BYVAL blue AS LONG PTR)

DECLARE FUNCTION xlBookActiveSheet          LIB "libxl.dll"  ALIAS "xlBookActiveSheetW"    _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE sub xlBookSetActiveSheet       LIB "libxl.dll"  ALIAS "xlBookSetActiveSheetW" _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG)

DECLARE FUNCTION xlBookPictureSize          LIB "libxl.dll"  ALIAS "xlBookPictureSizeW"  _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE FUNCTION xlBookGetPicture           LIB "libxl.dll"  ALIAS "xlBookGetPictureW"   _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG, BYVAL picData AS wstringz PTR, BYVAL picSize AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookAddPicture           LIB "libxl.dll"  ALIAS "xlBookAddPictureW"   _
                            (BYVAL book AS BookHandle, BYREF filename AS wstringz) AS LONG
DECLARE FUNCTION xlBookAddPicture2          LIB "libxl.dll"  ALIAS "xlBookAddPicture2W"  _
                            (BYVAL book AS BookHandle, BYREF picData AS wstringz, BYVAL picSize AS LONG) AS LONG

DECLARE FUNCTION xlBookDefaultFont          LIB "libxl.dll"  ALIAS "xlBookDefaultFontW"    _                         'check this function for sure
                            (BYVAL book AS BookHandle, BYVAL fontSize AS LONG PTR) as wstring
DECLARE sub xlBookSetDefaultFont       LIB "libxl.dll"  ALIAS "xlBookSetDefaultFontW" _
                            (BYVAL book AS BookHandle, BYREF fontName AS wstringz, BYVAL fontSize AS LONG)

DECLARE FUNCTION xlBookRgbMode              LIB "libxl.dll"  ALIAS "xlBookRgbModeW"      _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE sub xlBookSetRgbMode           LIB "libxl.dll"  ALIAS "xlBookSetRgbModeW"   _
                            (BYVAL book AS BookHandle, BYVAL rgbMode AS LONG)

DECLARE FUNCTION xlBookRefR1C1              LIB "libxl.dll"  ALIAS "xlBookRefR1C1W"      _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE sub xlBookSetRefR1C1           LIB "libxl.dll"  ALIAS "xlBookSetRefR1C1W"   _
                            (BYVAL book AS BookHandle, BYVAL refR1C1 AS LONG)

DECLARE FUNCTION xlBookVersion              LIB "libxl.dll"  ALIAS "xlBookVersionW"      _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookBiffVersion          LIB "libxl.dll"  ALIAS "xlBookBiffVersionW"  _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookIsDate1904           LIB "libxl.dll"  ALIAS "xlBookIsDate1904W"   _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE SUB xlBookSetDate1904          LIB "libxl.dll"  ALIAS "xlBookSetDate1904W"  _
                            (BYVAL book AS BookHandle, BYVAL date1904 AS LONG)

DECLARE FUNCTION xlBookIsTemplate           LIB "libxl.dll"  ALIAS "xlBookIsTemplateW"   _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE sub xlBookSetTemplate          LIB "libxl.dll"  ALIAS "xlBookSetTemplateW"  _
                            (BYVAL book AS BookHandle, BYVAL tmpl AS LONG)

DECLARE SUB xlBookSetKey               LIB "libxl.dll"  ALIAS "xlBookSetKeyW"       _
                            (BYVAL book AS BookHandle, BYREF keyname AS wstringz, BYREF szkey AS wstringz)

DECLARE FUNCTION xlBookSetLocale            LIB "libxl.dll"  ALIAS "xlBookSetLocaleW"    _
                            (BYVAL book AS BookHandle, BYREF tmpl AS wstringz) AS LONG
DECLARE FUNCTION xlBookErrorMessage         LIB "libxl.dll"  ALIAS "xlBookErrorMessageW" _                          'check this function for sure
                            (BYVAL book AS BookHandle) as wstring

DECLARE sub xlBookRelease              LIB "libxl.dll"  ALIAS "xlBookReleaseW"      _
                            (BYVAL book AS BookHandle)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Sheet function declarations''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION xlSheetCellType      LIB "libxl.dll"  ALIAS "xlSheetCellTypeW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetIsFormula      LIB "libxl.dll"  ALIAS "xlSheetIsFormulaW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG

DECLARE FUNCTION xlSheetCellFormat      LIB "libxl.dll"  ALIAS "xlSheetCellFormatW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS FormatHandle
DECLARE sub xlSheetSetCellFormat      LIB "libxl.dll"  ALIAS "xlSheetSetCellFormatW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle)

DECLARE FUNCTION xlSheetReadStr      LIB "libxl.dll"  ALIAS "xlSheetReadStrW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle POINTER) as wstring
DECLARE FUNCTION xlSheetWriteStr      LIB "libxl.dll"  ALIAS "xlSheetWriteStrW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYREF value AS wstringz, BYVAL format AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadNum      LIB "libxl.dll"  ALIAS "xlSheetReadNumW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle POINTER) AS DOUBLE
DECLARE FUNCTION xlSheetWriteNum      LIB "libxl.dll"  ALIAS "xlSheetWriteNumW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL value AS DOUBLE, BYVAL xformat AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadBool      LIB "libxl.dll"  ALIAS "xlSheetReadBoolW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle POINTER) AS LONG
DECLARE FUNCTION xlSheetWriteBool      LIB "libxl.dll"  ALIAS "xlSheetWriteBoolW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL value AS LONG, BYVAL xformat AS FormatHandle ) AS LONG


DECLARE FUNCTION xlSheetReadBlank      LIB "libxl.dll"  ALIAS "xlSheetReadBlankW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle POINTER) AS LONG
DECLARE FUNCTION xlSheetWriteBlank      LIB "libxl.dll"  ALIAS "xlSheetWriteBlankW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadFormula      LIB "libxl.dll"  ALIAS "xlSheetReadFormulaW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle POINTER) as wstring
DECLARE FUNCTION xlSheetWriteFormula      LIB "libxl.dll"  ALIAS "xlSheetWriteFormulaW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYREF value AS wstringz, BYVAL xformat AS FormatHandle POINTER) AS LONG


DECLARE FUNCTION xlSheetReadComment      LIB "libxl.dll"  ALIAS "xlSheetReadCommentW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) as wstring
DECLARE sub xlSheetWriteComment      LIB "libxl.dll"  ALIAS "xlSheetWriteCommentW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYREF value AS wstringz, BYREF author AS wstringz, BYVAL width_ AS LONG, BYVAL height_ AS LONG)


DECLARE FUNCTION xlSheetIsDate      LIB "libxl.dll"  ALIAS "xlSheetIsDateW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetReadError      LIB "libxl.dll"  ALIAS "xlSheetReadErrorW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG


DECLARE FUNCTION xlSheetColWidth      LIB "libxl.dll"  ALIAS "xlSheetColWidthW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG) AS DOUBLE
DECLARE FUNCTION xlSheetRowHeight      LIB "libxl.dll"  ALIAS "xlSheetRowHeightW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG) AS DOUBLE


DECLARE FUNCTION xlSheetSetCol      LIB "libxl.dll"  ALIAS "xlSheetSetColW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG, byval nWidth as double, BYVAL format AS FormatHandle, BYVAL hidden_ AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetRow      LIB "libxl.dll"  ALIAS "xlSheetSetRowW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL height AS DOUBLE, BYVAL format AS FormatHandle, BYVAL hidden_ AS LONG) AS LONG


DECLARE FUNCTION xlSheetRowHidden      LIB "libxl.dll"  ALIAS "xlSheetRowHiddenW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetRowHidden      LIB "libxl.dll"  ALIAS "xlSheetSetRowHiddenW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL hidden_ AS LONG) AS LONG


DECLARE FUNCTION xlSheetColHidden      LIB "libxl.dll"  ALIAS "xlSheetColHiddenW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetColHidden      LIB "libxl.dll"  ALIAS "xlSheetSetColHiddenW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG, BYVAL hidden_ AS LONG) AS LONG


DECLARE FUNCTION xlSheetGetMerge      LIB "libxl.dll"  ALIAS "xlSheetGetMergeW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetSetMerge      LIB "libxl.dll"  ALIAS "xlSheetSetMergeW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetDelMerge      LIB "libxl.dll"  ALIAS "xlSheetDelMergeW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG


DECLARE FUNCTION xlSheetMergeSize      LIB "libxl.dll"  ALIAS "xlSheetMergeSizeW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetMerge      LIB "libxl.dll"  ALIAS "xlSheetMergeW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetDelMergeByIndex      LIB "libxl.dll"  ALIAS "xlSheetDelMergeByIndexW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG

DECLARE FUNCTION xlSheetPictureSize      LIB "libxl.dll"  ALIAS "xlSheetPictureSizeW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetGetPicture      LIB "libxl.dll"  ALIAS "xlSheetGetPictureW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowTop AS LONG PTR, BYVAL colLeft AS LONG PTR, BYVAL rowBottom AS LONG PTR, BYVAL colRight AS LONG PTR _
                                                                             , BYVAL width AS LONG PTR , BYVAL height AS LONG PTR , BYVAL offset_x AS LONG PTR , BYVAL offset_y AS LONG PTR) AS LONG
DECLARE sub xlSheetSetPicture      LIB "libxl.dll"  ALIAS "xlSheetSetPictureW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL pictureId AS LONG, BYVAL scale AS DOUBLE, BYVAL offset_x AS LONG, BYVAL offset_y AS LONG)
DECLARE sub xlSheetSetPicture2      LIB "libxl.dll"  ALIAS "xlSheetSetPicture2W"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL pictureId AS LONG, BYVAL width AS LONG, BYVAL height AS LONG, BYVAL offset_x AS LONG, BYVAL offset_y AS LONG)


DECLARE FUNCTION xlSheetGetHorPageBreak      LIB "libxl.dll"  ALIAS "xlSheetGetHorPageBreakW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlSheetGetHorPageBreakSize      LIB "libxl.dll"  ALIAS "xlSheetGetHorPageBreakSizeW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG


DECLARE FUNCTION xlSheetGetVerPageBreak      LIB "libxl.dll"  ALIAS "xlSheetGetVerPageBreakW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlSheetGetVerPageBreakSize      LIB "libxl.dll"  ALIAS "xlSheetGetVerPageBreakSizeW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG

DECLARE FUNCTION xlSheetSetHorPageBreak      LIB "libxl.dll"  ALIAS "xlSheetSetHorPageBreakW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL pageBreak AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetVerPageBreak      LIB "libxl.dll"  ALIAS "xlSheetSetVerPageBreakW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG, BYVAL pageBreak AS LONG) AS LONG

DECLARE sub xlSheetSplit      LIB "libxl.dll"  ALIAS "xlSheetSplitW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG)
DECLARE FUNCTION xlSheetSplitInfo      LIB "libxl.dll"  ALIAS "xlSheetSplitInfoW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG PTR, BYVAL col AS LONG PTR) AS byte


DECLARE FUNCTION xlSheetGroupRows      LIB "libxl.dll"  ALIAS "xlSheetGroupRowsW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL collapsed AS LONG) AS LONG
DECLARE FUNCTION xlSheetGroupCols      LIB "libxl.dll"  ALIAS "xlSheetGroupColsW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG, BYVAL collapsed AS LONG) AS LONG


DECLARE FUNCTION xlSheetGroupSummaryBelow      LIB "libxl.dll"  ALIAS "xlSheetGroupSummaryBelowW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetGroupSummaryBelow      LIB "libxl.dll"  ALIAS "xlSheetSetGroupSummaryBelowW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL below AS LONG)


DECLARE FUNCTION xlSheetGroupSummaryRight      LIB "libxl.dll"  ALIAS "xlSheetGroupSummaryRightW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetGroupSummaryRight      LIB "libxl.dll"  ALIAS "xlSheetSetGroupSummaryRightW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL right AS LONG)


DECLARE sub xlSheetClear      LIB "libxl.dll"  ALIAS "xlSheetClearW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG)


DECLARE FUNCTION xlSheetInsertCol      LIB "libxl.dll"  ALIAS "xlSheetInsertColW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetInsertRow      LIB "libxl.dll"  ALIAS "xlSheetInsertRowW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetRemoveCol      LIB "libxl.dll"  ALIAS "xlSheetRemoveColW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetRemoveRow      LIB "libxl.dll"  ALIAS "xlSheetRemoveRowW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL colLast AS LONG) AS LONG


DECLARE FUNCTION xlSheetCopyCell      LIB "libxl.dll"  ALIAS "xlSheetCopyCellW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowSrc AS LONG, BYVAL colSrc AS LONG, BYVAL rowDst AS LONG, BYVAL colDst AS LONG) AS LONG


DECLARE FUNCTION xlSheetFirstRow      LIB "libxl.dll"  ALIAS "xlSheetFirstRowW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetLastRow      LIB "libxl.dll"  ALIAS "xlSheetLastRowW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetFirstCol      LIB "libxl.dll"  ALIAS "xlSheetFirstColW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetLastCol      LIB "libxl.dll"  ALIAS "xlSheetLastColW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG


DECLARE FUNCTION xlSheetDisplayGridlines      LIB "libxl.dll"  ALIAS "xlSheetDisplayGridlinesW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetDisplayGridlines      LIB "libxl.dll"  ALIAS "xlSheetSetDisplayGridlinesW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL nShow AS LONG)


DECLARE FUNCTION xlSheetPrintGridlines      LIB "libxl.dll"  ALIAS "xlSheetPrintGridlinesW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetPrintGridlines      LIB "libxl.dll"  ALIAS "xlSheetSetPrintGridlinesW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL print AS LONG)


DECLARE FUNCTION xlSheetZoom      LIB "libxl.dll"  ALIAS "xlSheetZoomW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetZoom      LIB "libxl.dll"  ALIAS "xlSheetSetZoomW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL zoom AS LONG)


DECLARE FUNCTION xlSheetPrintZoom      LIB "libxl.dll"  ALIAS "xlSheetPrintZoomW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetPrintZoom      LIB "libxl.dll"  ALIAS "xlSheetSetPrintZoomW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL zoom AS LONG)


DECLARE FUNCTION xlSheetGetPrintFit      LIB "libxl.dll"  ALIAS "xlSheetGetPrintFitW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL wPages AS LONG PTR, BYVAL hPages AS LONG PTR) AS LONG
DECLARE sub xlSheetSetPrintFit      LIB "libxl.dll"  ALIAS "xlSheetSetPrintFitW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL wPages AS LONG, BYVAL hPages AS LONG)


DECLARE FUNCTION xlSheetLandscape      LIB "libxl.dll"  ALIAS "xlSheetLandscapeW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetLandscape      LIB "libxl.dll"  ALIAS "xlSheetSetLandscapeW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL landscape AS LONG)


DECLARE FUNCTION xlSheetPaper      LIB "libxl.dll"  ALIAS "xlSheetPaperW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetPaper      LIB "libxl.dll"  ALIAS "xlSheetSetPaperW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL paper AS LONG)


DECLARE FUNCTION xlSheetHeader      LIB "libxl.dll"  ALIAS "xlSheetHeaderW"         _
                            (BYVAL sheet AS SheetHandle) as wstring
DECLARE FUNCTION xlSheetSetHeader      LIB "libxl.dll"  ALIAS "xlSheetSetHeaderW"         _
                            (BYVAL sheet AS SheetHandle, BYREF header AS wstringz, BYVAL margin AS DOUBLE) AS LONG
DECLARE FUNCTION xlSheetHeaderMargin      LIB "libxl.dll"  ALIAS "xlSheetHeaderMarginW"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE


DECLARE FUNCTION xlSheetFooter      LIB "libxl.dll"  ALIAS "xlSheetFooterW"         _
                            (BYVAL sheet AS SheetHandle) as wstring
DECLARE FUNCTION xlSheetSetFooter      LIB "libxl.dll"  ALIAS "xlSheetSetFooterW"         _
                            (BYVAL sheet AS SheetHandle, BYREF footer AS wstringz, BYVAL margin AS DOUBLE) AS LONG
DECLARE FUNCTION xlSheetFooterMargin      LIB "libxl.dll"  ALIAS "xlSheetFooterMarginW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS DOUBLE


DECLARE FUNCTION xlSheetHCenter      LIB "libxl.dll"  ALIAS "xlSheetHCenterW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetHCenter      LIB "libxl.dll"  ALIAS "xlSheetSetHCenterW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL hCenter AS LONG)


DECLARE FUNCTION xlSheetVCenter      LIB "libxl.dll"  ALIAS "xlSheetVCenterW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetVCenter      LIB "libxl.dll"  ALIAS "xlSheetSetVCenterW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL vCenter AS LONG)


DECLARE FUNCTION xlSheetMarginLeft      LIB "libxl.dll"  ALIAS "xlSheetMarginLeftW"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE sub xlSheetSetMarginLeft      LIB "libxl.dll"  ALIAS "xlSheetSetMarginLeftW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL fMargin AS DOUBLE)


DECLARE FUNCTION xlSheetMarginRight      LIB "libxl.dll"  ALIAS "xlSheetMarginRightW"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE SUB xlSheetSetMarginRight      LIB "libxl.dll"  ALIAS "xlSheetSetMarginRightW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL fMargin AS DOUBLE)


DECLARE FUNCTION xlSheetMarginTop      LIB "libxl.dll"  ALIAS "xlSheetMarginTopW"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE sub xlSheetSetMarginTop      LIB "libxl.dll"  ALIAS "xlSheetSetMarginTopW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL fMargin AS DOUBLE)


DECLARE FUNCTION xlSheetMarginBottom      LIB "libxl.dll"  ALIAS "xlSheetMarginBottomW"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE sub xlSheetSetMarginBottom      LIB "libxl.dll"  ALIAS "xlSheetSetMarginBottomW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL fMargin AS DOUBLE)


DECLARE FUNCTION xlSheetPrintRowCol      LIB "libxl.dll"  ALIAS "xlSheetPrintRowColW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetPrintRowCol      LIB "libxl.dll"  ALIAS "xlSheetSetPrintRowColW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL nPrint AS LONG)

DECLARE FUNCTION xlSheetPrintRepeatRows      LIB "libxl.dll"  ALIAS "xlSheetPrintRepeatRowsW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG ptr, BYVAL rowLast AS LONG ptr) AS LONG
DECLARE sub xlSheetSetPrintRepeatRows      LIB "libxl.dll"  ALIAS "xlSheetSetPrintRepeatRowsW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG)

DECLARE FUNCTION xlSheetPrintRepeatCols      LIB "libxl.dll"  ALIAS "xlSheetPrintRepeatColsW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG ptr, BYVAL colLast AS LONG ptr) AS LONG
DECLARE sub xlSheetSetPrintRepeatCols      LIB "libxl.dll"  ALIAS "xlSheetSetPrintRepeatColsW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG)

DECLARE FUNCTION xlSheetPrintArea       LIB "libxl.dll"  ALIAS "xlSheetPrintAreaW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG ptr, BYVAL rowLast AS LONG ptr, BYVAL colFirst AS LONG ptr, BYVAL colLast AS LONG ptr) as long
DECLARE sub xlSheetSetPrintArea      LIB "libxl.dll"  ALIAS "xlSheetSetPrintAreaW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG)


DECLARE sub xlSheetClearPrintRepeats      LIB "libxl.dll"  ALIAS "xlSheetClearPrintRepeatsW"         _
                            (BYVAL sheet AS SheetHandle)
DECLARE sub xlSheetClearPrintArea      LIB "libxl.dll"  ALIAS "xlSheetClearPrintAreaW"         _
                            (BYVAL sheet AS SheetHandle)


DECLARE FUNCTION xlSheetGetNamedRange      LIB "libxl.dll"  ALIAS "xlSheetGetNamedRangeW"         _
                            (BYVAL sheet AS SheetHandle, BYREF rangeName AS wstringz, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR, _
                             BYVAL scopeId AS LONG, BYVAL hidden_ AS LONG PTR ) AS LONG
DECLARE FUNCTION xlSheetSetNamedRange      LIB "libxl.dll"  ALIAS "xlSheetSetNamedRangeW"         _
                            (BYVAL sheet AS SheetHandle, BYREF rangeName AS wstringz, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG, _
                             BYVAL scopeId AS LONG) AS LONG
DECLARE FUNCTION xlSheetDelNamedRange      LIB "libxl.dll"  ALIAS "xlSheetDelNamedRangeW"         _
                            (BYVAL sheet AS SheetHandle, BYREF rangeName AS wstringz, BYVAL scopeId AS LONG) AS LONG

DECLARE FUNCTION xlSheetNamedRangeSize      LIB "libxl.dll"  ALIAS "xlSheetNamedRangeSizeW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetNamedRange      LIB "libxl.dll"  ALIAS "xlSheetNamedRangeW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR, _
                             BYVAL scopeId AS LONG, BYVAL hidden_ AS LONG PTR ) as wstring


DECLARE FUNCTION xlSheetHyperlinkSize      LIB "libxl.dll"  ALIAS "xlSheetHyperlinkSizeW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetHyperlink      LIB "libxl.dll"  ALIAS "xlSheetHyperlinkW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR) as wstring
DECLARE FUNCTION xlSheetDelHyperlink      LIB "libxl.dll"  ALIAS "xlSheetDelHyperlinkW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG
DECLARE sub xlSheetAddHyperlink      LIB "libxl.dll"  ALIAS "xlSheetAddHyperlinkW"         _
                            (BYVAL sheet AS SheetHandle, BYREF hyperlink AS wstringz, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG)


DECLARE FUNCTION xlSheetName      LIB "libxl.dll"  ALIAS "xlSheetNameW"         _
                            (BYVAL sheet AS SheetHandle) as wstring
DECLARE sub xlSheetSetName      LIB "libxl.dll"  ALIAS "xlSheetSetNameW"         _
                            (BYVAL sheet AS SheetHandle, BYREF sheetName AS wstringz)


DECLARE FUNCTION xlSheetProtect      LIB "libxl.dll"  ALIAS "xlSheetProtectW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetProtect      LIB "libxl.dll"  ALIAS "xlSheetSetProtectW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL protect AS LONG)


DECLARE FUNCTION xlSheetHidden     LIB "libxl.dll"  ALIAS "xlSheetHiddenW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetHidden     LIB "libxl.dll"  ALIAS "xlSheetSetHiddenW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL hidden AS LONG) AS LONG


DECLARE sub xlSheetGetTopLeftView     LIB "libxl.dll"  ALIAS "xlSheetGetTopLeftViewW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG PTR, BYVAL col AS LONG PTR)
DECLARE sub xlSheetSetTopLeftView     LIB "libxl.dll"  ALIAS "xlSheetSetTopLeftViewW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG)


declare sub xlSheetSetAutoFitArea LIB "libxl.dll"  ALIAS "xlSheetSetAutoFitAreaW"         _
              (BYVAL sheet AS SheetHandle, byval rowFirst as long, byval colFirst as long, byval rowLast as long, byval colLast as long)

DECLARE FUNCTION xlSheetRightToLeft     LIB "libxl.dll"  ALIAS "xlSheetRightToLeftW"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetRightToLeft     LIB "libxl.dll"  ALIAS "xlSheetSetRightToLeftW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rightToLeft AS LONG)


DECLARE sub xlSheetAddrToRowCol     LIB "libxl.dll"  ALIAS "xlSheetAddrToRowColW"         _
                            (BYVAL sheet AS SheetHandle, BYREF addr_ AS wstringz, BYVAL row AS LONG PTR, BYVAL col AS LONG PTR, _
                             BYVAL rowRelative AS LONG PTR, BYVAL colRelative AS LONG PTR)
DECLARE FUNCTION xlSheetRowColToAddr     LIB "libxl.dll"  ALIAS "xlSheetRowColToAddrW"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL rowRelative AS LONG, BYVAL colRelative AS LONG) as wstring


'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Format function declarations'''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
DECLARE FUNCTION xlFormatFont    LIB "libxl.dll"  ALIAS "xlFormatFontW"      _
                            (BYVAL format AS FormatHandle) AS FontHandle
DECLARE FUNCTION xlFormatSetFont LIB "libxl.dll"  ALIAS "xlFormatSetFontW"      _
                            (BYVAL format AS FormatHandle, BYVAL font AS FontHandle) AS LONG

DECLARE FUNCTION xlFormatNumFormat    LIB "libxl.dll"  ALIAS "xlFormatNumFormatW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetNumFormat LIB "libxl.dll"  ALIAS "xlFormatSetNumFormatW"      _
                            (BYVAL format AS FormatHandle, BYVAL numFormat AS LONG)

DECLARE FUNCTION xlFormatAlignH    LIB "libxl.dll"  ALIAS "xlFormatAlignHW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetAlignH LIB "libxl.dll"  ALIAS "xlFormatSetAlignHW"      _
                            (BYVAL format AS FormatHandle, BYVAL align AS LONG)

DECLARE FUNCTION xlFormatAlignV    LIB "libxl.dll"  ALIAS "xlFormatAlignVW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetAlignV LIB "libxl.dll"  ALIAS "xlFormatSetAlignVW"      _
                            (BYVAL format AS FormatHandle, BYVAL align AS LONG)

DECLARE FUNCTION xlFormatWrap    LIB "libxl.dll"  ALIAS "xlFormatWrapW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetWrap LIB "libxl.dll"  ALIAS "xlFormatSetWrapW"      _
                            (BYVAL format AS FormatHandle, BYVAL wrap AS LONG)

DECLARE FUNCTION xlFormatRotation     LIB "libxl.dll"  ALIAS "xlFormatRotationW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetRotation  LIB "libxl.dll"  ALIAS "xlFormatSetRotationW"      _
                            (BYVAL format AS FormatHandle, BYVAL rotation AS LONG) AS LONG

DECLARE FUNCTION xlFormatIndent     LIB "libxl.dll"  ALIAS "xlFormatIndentW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetIndent  LIB "libxl.dll"  ALIAS "xlFormatSetIndentW"      _
                            (BYVAL format AS FormatHandle, BYVAL indent AS LONG)

DECLARE FUNCTION xlFormatShrinkToFit     LIB "libxl.dll"  ALIAS "xlFormatShrinkToFitW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetShrinkToFit  LIB "libxl.dll"  ALIAS "xlFormatSetShrinkToFitW"      _
                            (BYVAL format AS FormatHandle, BYVAL shrinkToFit AS LONG)

DECLARE FUNCTION xlFormatSetBorder     LIB "libxl.dll"  ALIAS "xlFormatSetBorderW"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG) AS LONG
DECLARE sub xlFormatSetBorderColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderColorW"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderLeft     LIB "libxl.dll"  ALIAS "xlFormatBorderLeftW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderLeft  LIB "libxl.dll"  ALIAS "xlFormatSetBorderLeftW"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG)

DECLARE FUNCTION xlFormatBorderRight     LIB "libxl.dll"  ALIAS "xlFormatBorderRightW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderRight  LIB "libxl.dll"  ALIAS "xlFormatSetBorderRightW"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG)

DECLARE FUNCTION xlFormatBorderTop     LIB "libxl.dll"  ALIAS "xlFormatBorderTopW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderTop  LIB "libxl.dll"  ALIAS "xlFormatSetBorderTopW"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG)

DECLARE FUNCTION xlFormatBorderBottom     LIB "libxl.dll"  ALIAS "xlFormatBorderBottomW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderBottom  LIB "libxl.dll"  ALIAS "xlFormatSetBorderBottomW"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG)

DECLARE FUNCTION xlFormatBorderLeftColor     LIB "libxl.dll"  ALIAS "xlFormatBorderLeftColorW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderLeftColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderLeftColorW"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderRightColor     LIB "libxl.dll"  ALIAS "xlFormatBorderRightColorW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderRightColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderRightColorW"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderTopColor     LIB "libxl.dll"  ALIAS "xlFormatBorderTopColorW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderTopColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderTopColorW"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderBottomColor     LIB "libxl.dll"  ALIAS "xlFormatBorderBottomColorW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderBottomColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderBottomColorW"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderDiagonal     LIB "libxl.dll"  ALIAS "xlFormatBorderDiagonalW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderDiagonal  LIB "libxl.dll"  ALIAS "xlFormatSetBorderDiagonalW"      _
                            (BYVAL format AS FormatHandle, BYVAL border AS LONG)

DECLARE FUNCTION xlFormatBorderDiagonalStyle     LIB "libxl.dll"  ALIAS "xlFormatBorderDiagonalStyleW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderDiagonalStyle  LIB "libxl.dll"  ALIAS "xlFormatSetBorderDiagonalStyleW"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatFillPattern     LIB "libxl.dll"  ALIAS "xlFormatFillPatternW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetFillPattern  LIB "libxl.dll"  ALIAS "xlFormatSetFillPatternW"      _
                            (BYVAL format AS FormatHandle, BYVAL pattern AS LONG)

DECLARE FUNCTION xlFormatPatternForegroundColor     LIB "libxl.dll"  ALIAS "xlFormatPatternForegroundColorW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetPatternForegroundColor  LIB "libxl.dll"  ALIAS "xlFormatSetPatternForegroundColorW"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatPatternBackgroundColor     LIB "libxl.dll"  ALIAS "xlFormatPatternBackgroundColorW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetPatternBackgroundColor  LIB "libxl.dll"  ALIAS "xlFormatSetPatternBackgroundColorW"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatLocked     LIB "libxl.dll"  ALIAS "xlFormatLockedW"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetLocked  LIB "libxl.dll"  ALIAS "xlFormatSetLockedW"      _
                            (BYVAL format AS FormatHandle, BYVAL locked AS LONG)

DECLARE FUNCTION xlFormatHidden     LIB "libxl.dll"  ALIAS "xlFormatHiddenW"         _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetHidden  LIB "libxl.dll"  ALIAS "xlFormatSetHiddenW"      _
                            (BYVAL format AS FormatHandle, BYVAL hidden_ AS LONG)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Font function declarations'''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
DECLARE FUNCTION xlFontSize    LIB "libxl.dll"  ALIAS "xlFontSizeW"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetSize LIB "libxl.dll"  ALIAS "xlFontSetSizeW"      _
                            (BYVAL font AS FontHandle, BYVAL fontsize AS LONG)

DECLARE FUNCTION xlFontItalic    LIB "libxl.dll"  ALIAS "xlFontItalicW"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetItalic LIB "libxl.dll"  ALIAS "xlFontSetItalicW"      _
                            (BYVAL font AS FontHandle, BYVAL italic AS LONG)

DECLARE FUNCTION xlFontStrikeOut    LIB "libxl.dll"  ALIAS "xlFontStrikeOutW"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetStrikeOut LIB "libxl.dll"  ALIAS "xlFontSetStrikeOutW"      _
                            (BYVAL font AS FontHandle, BYVAL strikeOut AS LONG)

DECLARE FUNCTION xlFontColor    LIB "libxl.dll"  ALIAS "xlFontColorW"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetColor LIB "libxl.dll"  ALIAS "xlFontSetColorW"      _
                            (BYVAL font AS FontHandle, BYVAL fColor AS LONG)

DECLARE FUNCTION xlFontBold    LIB "libxl.dll"  ALIAS "xlFontBoldW"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetBold LIB "libxl.dll"  ALIAS "xlFontSetBoldW"      _
                            (BYVAL font AS FontHandle, BYVAL bold AS LONG)

DECLARE FUNCTION xlFontScript    LIB "libxl.dll"  ALIAS "xlFontScriptW"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetScript LIB "libxl.dll"  ALIAS "xlFontSetScriptW"      _
                            (BYVAL font AS FontHandle, BYVAL script AS LONG)

DECLARE FUNCTION xlFontUnderline    LIB "libxl.dll"  ALIAS "xlFontUnderlineW"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetUnderline LIB "libxl.dll"  ALIAS "xlFontSetUnderlineW"      _
                            (BYVAL font AS FontHandle, BYVAL underline AS LONG)

DECLARE FUNCTION xlFontName    LIB "libxl.dll"  ALIAS "xlFontNameW"      _
                            (BYVAL font AS FontHandle) as wstring
DECLARE FUNCTION xlFontSetName LIB "libxl.dll"  ALIAS "xlFontSetNameW"      _
                            (BYVAL font AS FontHandle, BYREF fontName AS wstringz) AS LONG
