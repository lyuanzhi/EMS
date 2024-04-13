#INCLUDE THIS ONCE

#INCLUDE ONCE "enum.inc"

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''factory function declarations''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
DECLARE FUNCTION xlCreateBook               LIB "libxl.dll"  ALIAS "xlCreateBookA"     _
                            () AS BookHandle
DECLARE FUNCTION xlCreateXMLBook            LIB "libxl.dll"  ALIAS "xlCreateXMLBookA"  _
                            () AS BookHandle
DECLARE FUNCTION xlCreateBookC               LIB "libxl.dll"  ALIAS "xlCreateBookCA"     _
                            () AS BookHandle
DECLARE FUNCTION xlCreateXMLBookC            LIB "libxl.dll"  ALIAS "xlCreateXMLBookCA"  _
                            () AS BookHandle

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Book function declarations'''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION xlBookLoad                 LIB "libxl.dll"  ALIAS "xlBookLoadA"        _
                            (BYVAL book AS BookHandle, BYREF fileName AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookSave                 LIB "libxl.dll"  ALIAS "xlBookSaveA"        _
                            (BYVAL book AS BookHandle, BYREF fileName AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookLoadRaw              LIB "libxl.dll"  ALIAS "xlBookLoadRawA"     _
                            (BYVAL book AS BookHandle, BYREF fileData AS STRINGZ, BYVAL fileSize AS LONG) AS LONG
DECLARE FUNCTION xlBookSaveRaw              LIB "libxl.dll"  ALIAS "xlBookSaveRawA"     _
                            (BYVAL book AS BookHandle, BYVAL fileData AS STRINGZ PTR, BYVAL fileSize AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookAddSheet             LIB "libxl.dll"  ALIAS "xlBookAddSheetA"    _
                            (BYVAL book AS BookHandle, BYref sheetName AS STRINGz, BYVAL initSheet AS SheetHandle) AS SheetHandle
DECLARE FUNCTION xlBookInsertSheet          LIB "libxl.dll"  ALIAS "xlBookInsertSheetA" _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG, BYREF sheetName AS STRINGZ, BYVAL initSheet AS SheetHandle) AS SheetHandle
DECLARE FUNCTION xlBookGetSheet             LIB "libxl.dll"  ALIAS "xlBookGetSheetA"    _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS SheetHandle
DECLARE FUNCTION xlBookSheetType            LIB "libxl.dll"  ALIAS "xlBookSheetTypeA"   _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlBookDelSheet             LIB "libxl.dll"  ALIAS "xlBookDelSheetA"    _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlBookSheetCount           LIB "libxl.dll"  ALIAS "xlBookSheetCountA"  _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookAddFormat            LIB "libxl.dll"  ALIAS "xlBookAddFormatA"          _
                            (BYVAL book AS BookHandle, BYVAL initFormat AS FormatHandle) AS FormatHandle
DECLARE FUNCTION xlBookAddFont              LIB "libxl.dll"  ALIAS "xlBookAddFontA"            _
                            (BYVAL book AS BookHandle, BYVAL initFont AS FontHandle) AS FontHandle
DECLARE FUNCTION xlBookAddCustomNumFormat   LIB "libxl.dll"  ALIAS "xlBookAddCustomNumFormatA" _
                            (BYVAL book AS BookHandle, BYREF customNumFormat AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookCustomNumFormat LIB "libxl.dll"  ALIAS "xlBookCustomNumFormatA"         _                     'check this function for sure
                            (BYVAL book AS BookHandle, BYVAL format AS LONG) AS STRING

DECLARE FUNCTION xlBookFormat               LIB "libxl.dll"  ALIAS "xlBookFormatA"      _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS FormatHandle
DECLARE FUNCTION xlBookFormatSize           LIB "libxl.dll"  ALIAS "xlBookFormatSizeA"  _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookFont                 LIB "libxl.dll"  ALIAS "xlBookFontA"        _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG) AS FontHandle
DECLARE FUNCTION xlBookFontSize             LIB "libxl.dll"  ALIAS "xlBookFontSizeA"    _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookDatePack             LIB "libxl.dll"  ALIAS "xlBookDatePackA"    _
                            (BYVAL book AS BookHandle, BYVAL year AS LONG, BYVAL month AS LONG, BYVAL day AS LONG, BYVAL hour AS LONG, BYVAL minute AS LONG, BYVAL second AS LONG, BYVAL millisecond AS LONG) AS DOUBLE
DECLARE FUNCTION xlBookDateUnpack           LIB "libxl.dll"  ALIAS "xlBookDateUnpackA"  _
                            (BYVAL book AS BookHandle, BYVAL value AS DOUBLE, BYVAL year AS LONG PTR, BYVAL month AS LONG PTR, BYVAL day AS LONG PTR, _
                             BYVAL hour AS LONG PTR, BYVAL minute AS LONG PTR, BYVAL second AS LONG PTR, BYVAL millisecond AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookColorPack            LIB "libxl.dll"  ALIAS "xlBookColorPackA"    _
                            (BYVAL book AS BookHandle, BYVAL red AS LONG, BYVAL green AS LONG, BYVAL blue AS LONG) AS LONG
DECLARE sub xlBookColorUnpack          LIB "libxl.dll"  ALIAS "xlBookColorUnpackA"  _
                            (BYVAL book AS BookHandle, BYVAL value AS LONG, BYVAL red AS LONG PTR, BYVAL green AS LONG PTR, BYVAL blue AS LONG PTR)

DECLARE FUNCTION xlBookActiveSheet          LIB "libxl.dll"  ALIAS "xlBookActiveSheetA"    _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE sub xlBookSetActiveSheet       LIB "libxl.dll"  ALIAS "xlBookSetActiveSheetA" _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG)

DECLARE FUNCTION xlBookPictureSize          LIB "libxl.dll"  ALIAS "xlBookPictureSizeA"  _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE FUNCTION xlBookGetPicture           LIB "libxl.dll"  ALIAS "xlBookGetPictureA"   _
                            (BYVAL book AS BookHandle, BYVAL index AS LONG, BYVAL picData AS STRINGZ PTR, BYVAL picSize AS LONG PTR) AS LONG

DECLARE FUNCTION xlBookAddPicture           LIB "libxl.dll"  ALIAS "xlBookAddPictureA"   _
                            (BYVAL book AS BookHandle, BYREF filename AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookAddPicture2          LIB "libxl.dll"  ALIAS "xlBookAddPicture2A"  _
                            (BYVAL book AS BookHandle, BYREF picData AS STRINGZ, BYVAL picSize AS LONG) AS LONG

DECLARE FUNCTION xlBookDefaultFont          LIB "libxl.dll"  ALIAS "xlBookDefaultFontA"    _                         'check this function for sure
                            (BYVAL book AS BookHandle, BYVAL fontSize AS LONG PTR) AS STRING
DECLARE sub xlBookSetDefaultFont       LIB "libxl.dll"  ALIAS "xlBookSetDefaultFontA" _
                            (BYVAL book AS BookHandle, BYREF fontName AS STRINGZ, BYVAL fontSize AS LONG)

DECLARE FUNCTION xlBookRgbMode              LIB "libxl.dll"  ALIAS "xlBookRgbModeA"      _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE sub xlBookSetRgbMode           LIB "libxl.dll"  ALIAS "xlBookSetRgbModeA"   _
                            (BYVAL book AS BookHandle, BYVAL rgbMode AS LONG)

DECLARE FUNCTION xlBookRefR1C1              LIB "libxl.dll"  ALIAS "xlBookRefR1C1A"      _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE sub xlBookSetRefR1C1           LIB "libxl.dll"  ALIAS "xlBookSetRefR1C1A"   _
                            (BYVAL book AS BookHandle, BYVAL refR1C1 AS LONG)

DECLARE FUNCTION xlBookVersion              LIB "libxl.dll"  ALIAS "xlBookVersionA"      _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookBiffVersion          LIB "libxl.dll"  ALIAS "xlBookBiffVersionA"  _
                            (BYVAL book AS BookHandle) AS LONG

DECLARE FUNCTION xlBookIsDate1904           LIB "libxl.dll"  ALIAS "xlBookIsDate1904A"   _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE SUB xlBookSetDate1904          LIB "libxl.dll"  ALIAS "xlBookSetDate1904A"  _
                            (BYVAL book AS BookHandle, BYVAL date1904 AS LONG)

DECLARE FUNCTION xlBookIsTemplate           LIB "libxl.dll"  ALIAS "xlBookIsTemplateA"   _
                            (BYVAL book AS BookHandle) AS LONG
DECLARE sub xlBookSetTemplate          LIB "libxl.dll"  ALIAS "xlBookSetTemplateA"  _
                            (BYVAL book AS BookHandle, BYVAL tmpl AS LONG)

DECLARE SUB xlBookSetKey               LIB "libxl.dll"  ALIAS "xlBookSetKeyA"       _
                            (BYVAL book AS BookHandle, BYREF keyname AS STRINGZ, BYREF szkey AS STRINGZ)

DECLARE FUNCTION xlBookSetLocale            LIB "libxl.dll"  ALIAS "xlBookSetLocaleA"    _
                            (BYVAL book AS BookHandle, BYREF tmpl AS STRINGZ) AS LONG
DECLARE FUNCTION xlBookErrorMessage         LIB "libxl.dll"  ALIAS "xlBookErrorMessageA" _                          'check this function for sure
                            (BYVAL book AS BookHandle) AS STRING

DECLARE sub xlBookRelease              LIB "libxl.dll"  ALIAS "xlBookReleaseA"      _
                            (BYVAL book AS BookHandle)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Sheet function declarations''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                                                                                                         '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                                                                                                         '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

DECLARE FUNCTION xlSheetCellType      LIB "libxl.dll"  ALIAS "xlSheetCellTypeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetIsFormula      LIB "libxl.dll"  ALIAS "xlSheetIsFormulaA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG

DECLARE FUNCTION xlSheetCellFormat      LIB "libxl.dll"  ALIAS "xlSheetCellFormatA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS FormatHandle
DECLARE sub xlSheetSetCellFormat      LIB "libxl.dll"  ALIAS "xlSheetSetCellFormatA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle)

DECLARE FUNCTION xlSheetReadStr      LIB "libxl.dll"  ALIAS "xlSheetReadStrA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL format AS FormatHandle POINTER) AS STRING
DECLARE FUNCTION xlSheetWriteStr      LIB "libxl.dll"  ALIAS "xlSheetWriteStrA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYREF value AS STRINGZ, BYVAL format AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadNum      LIB "libxl.dll"  ALIAS "xlSheetReadNumA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle POINTER) AS DOUBLE
DECLARE FUNCTION xlSheetWriteNum      LIB "libxl.dll"  ALIAS "xlSheetWriteNumA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL value AS DOUBLE, BYVAL xformat AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadBool      LIB "libxl.dll"  ALIAS "xlSheetReadBoolA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle POINTER) AS LONG
DECLARE FUNCTION xlSheetWriteBool      LIB "libxl.dll"  ALIAS "xlSheetWriteBoolA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL value AS LONG, BYVAL xformat AS FormatHandle ) AS LONG


DECLARE FUNCTION xlSheetReadBlank      LIB "libxl.dll"  ALIAS "xlSheetReadBlankA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle POINTER) AS LONG
DECLARE FUNCTION xlSheetWriteBlank      LIB "libxl.dll"  ALIAS "xlSheetWriteBlankA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle) AS LONG


DECLARE FUNCTION xlSheetReadFormula      LIB "libxl.dll"  ALIAS "xlSheetReadFormulaA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL xformat AS FormatHandle POINTER) AS STRING
DECLARE FUNCTION xlSheetWriteFormula      LIB "libxl.dll"  ALIAS "xlSheetWriteFormulaA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYREF value AS STRINGZ, BYVAL xformat AS FormatHandle POINTER) AS LONG


DECLARE FUNCTION xlSheetReadComment      LIB "libxl.dll"  ALIAS "xlSheetReadCommentA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS STRING
DECLARE sub xlSheetWriteComment      LIB "libxl.dll"  ALIAS "xlSheetWriteCommentA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYREF value AS STRINGZ, BYREF author AS STRINGZ, BYVAL width_ AS LONG, BYVAL height_ AS LONG)


DECLARE FUNCTION xlSheetIsDate      LIB "libxl.dll"  ALIAS "xlSheetIsDateA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetReadError      LIB "libxl.dll"  ALIAS "xlSheetReadErrorA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG


DECLARE FUNCTION xlSheetColWidth      LIB "libxl.dll"  ALIAS "xlSheetColWidthA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG) AS DOUBLE
DECLARE FUNCTION xlSheetRowHeight      LIB "libxl.dll"  ALIAS "xlSheetRowHeightA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG) AS DOUBLE


DECLARE FUNCTION xlSheetSetCol      LIB "libxl.dll"  ALIAS "xlSheetSetColA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG, byval nWidth as double, BYVAL format AS FormatHandle, BYVAL hidden_ AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetRow      LIB "libxl.dll"  ALIAS "xlSheetSetRowA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL height AS DOUBLE, BYVAL format AS FormatHandle, BYVAL hidden_ AS LONG) AS LONG


DECLARE FUNCTION xlSheetRowHidden      LIB "libxl.dll"  ALIAS "xlSheetRowHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetRowHidden      LIB "libxl.dll"  ALIAS "xlSheetSetRowHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL hidden_ AS LONG) AS LONG


DECLARE FUNCTION xlSheetColHidden      LIB "libxl.dll"  ALIAS "xlSheetColHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetColHidden      LIB "libxl.dll"  ALIAS "xlSheetSetColHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG, BYVAL hidden_ AS LONG) AS LONG


DECLARE FUNCTION xlSheetGetMerge      LIB "libxl.dll"  ALIAS "xlSheetGetMergeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetSetMerge      LIB "libxl.dll"  ALIAS "xlSheetSetMergeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetDelMerge      LIB "libxl.dll"  ALIAS "xlSheetDelMergeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS LONG


DECLARE FUNCTION xlSheetMergeSize      LIB "libxl.dll"  ALIAS "xlSheetMergeSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetMerge      LIB "libxl.dll"  ALIAS "xlSheetMergeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR) AS LONG
DECLARE FUNCTION xlSheetDelMergeByIndex      LIB "libxl.dll"  ALIAS "xlSheetDelMergeByIndexA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG


DECLARE FUNCTION xlSheetPictureSize      LIB "libxl.dll"  ALIAS "xlSheetPictureSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetGetPicture      LIB "libxl.dll"  ALIAS "xlSheetGetPictureA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowTop AS LONG PTR, BYVAL colLeft AS LONG PTR, BYVAL rowBottom AS LONG PTR, BYVAL colRight AS LONG PTR _
                                                                             , BYVAL width AS LONG PTR , BYVAL height AS LONG PTR , BYVAL offset_x AS LONG PTR , BYVAL offset_y AS LONG PTR) AS LONG
DECLARE sub xlSheetSetPicture      LIB "libxl.dll"  ALIAS "xlSheetSetPictureA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL pictureId AS LONG, BYVAL scale AS DOUBLE, BYVAL offset_x AS LONG, BYVAL offset_y AS LONG)
DECLARE sub xlSheetSetPicture2      LIB "libxl.dll"  ALIAS "xlSheetSetPicture2A"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL pictureId AS LONG, BYVAL width AS LONG, BYVAL height AS LONG, BYVAL offset_x AS LONG, BYVAL offset_y AS LONG)


DECLARE FUNCTION xlSheetGetHorPageBreak      LIB "libxl.dll"  ALIAS "xlSheetGetHorPageBreakA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlSheetGetHorPageBreakSize      LIB "libxl.dll"  ALIAS "xlSheetGetHorPageBreakSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG


DECLARE FUNCTION xlSheetGetVerPageBreak      LIB "libxl.dll"  ALIAS "xlSheetGetVerPageBreakA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG
DECLARE FUNCTION xlSheetGetVerPageBreakSize      LIB "libxl.dll"  ALIAS "xlSheetGetVerPageBreakSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG


DECLARE FUNCTION xlSheetSetHorPageBreak      LIB "libxl.dll"  ALIAS "xlSheetSetHorPageBreakA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL pageBreak AS LONG) AS LONG
DECLARE FUNCTION xlSheetSetVerPageBreak      LIB "libxl.dll"  ALIAS "xlSheetSetVerPageBreakA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL col AS LONG, BYVAL pageBreak AS LONG) AS LONG


DECLARE sub xlSheetSplit      LIB "libxl.dll"  ALIAS "xlSheetSplitA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG)
DECLARE FUNCTION xlSheetSplitInfo      LIB "libxl.dll"  ALIAS "xlSheetSplitInfoA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG PTR, BYVAL col AS LONG PTR) AS byte


DECLARE FUNCTION xlSheetGroupRows      LIB "libxl.dll"  ALIAS "xlSheetGroupRowsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL collapsed AS LONG) AS LONG
DECLARE FUNCTION xlSheetGroupCols      LIB "libxl.dll"  ALIAS "xlSheetGroupColsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG, BYVAL collapsed AS LONG) AS LONG


DECLARE FUNCTION xlSheetGroupSummaryBelow      LIB "libxl.dll"  ALIAS "xlSheetGroupSummaryBelowA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetGroupSummaryBelow      LIB "libxl.dll"  ALIAS "xlSheetSetGroupSummaryBelowA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL below AS LONG)


DECLARE FUNCTION xlSheetGroupSummaryRight      LIB "libxl.dll"  ALIAS "xlSheetGroupSummaryRightA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetGroupSummaryRight      LIB "libxl.dll"  ALIAS "xlSheetSetGroupSummaryRightA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL right AS LONG)


DECLARE sub xlSheetClear      LIB "libxl.dll"  ALIAS "xlSheetClearA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG)


DECLARE FUNCTION xlSheetInsertCol      LIB "libxl.dll"  ALIAS "xlSheetInsertColA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetInsertRow      LIB "libxl.dll"  ALIAS "xlSheetInsertRowA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetRemoveCol      LIB "libxl.dll"  ALIAS "xlSheetRemoveColA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG) AS LONG
DECLARE FUNCTION xlSheetRemoveRow      LIB "libxl.dll"  ALIAS "xlSheetRemoveRowA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL colLast AS LONG) AS LONG


DECLARE FUNCTION xlSheetCopyCell      LIB "libxl.dll"  ALIAS "xlSheetCopyCellA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowSrc AS LONG, BYVAL colSrc AS LONG, BYVAL rowDst AS LONG, BYVAL colDst AS LONG) AS LONG


DECLARE FUNCTION xlSheetFirstRow      LIB "libxl.dll"  ALIAS "xlSheetFirstRowA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetLastRow      LIB "libxl.dll"  ALIAS "xlSheetLastRowA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetFirstCol      LIB "libxl.dll"  ALIAS "xlSheetFirstColA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetLastCol      LIB "libxl.dll"  ALIAS "xlSheetLastColA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG


DECLARE FUNCTION xlSheetDisplayGridlines      LIB "libxl.dll"  ALIAS "xlSheetDisplayGridlinesA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetDisplayGridlines      LIB "libxl.dll"  ALIAS "xlSheetSetDisplayGridlinesA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL nShow AS LONG)


DECLARE FUNCTION xlSheetPrintGridlines      LIB "libxl.dll"  ALIAS "xlSheetPrintGridlinesA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetPrintGridlines      LIB "libxl.dll"  ALIAS "xlSheetSetPrintGridlinesA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL print AS LONG)


DECLARE FUNCTION xlSheetZoom      LIB "libxl.dll"  ALIAS "xlSheetZoomA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetZoom      LIB "libxl.dll"  ALIAS "xlSheetSetZoomA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL zoom AS LONG)


DECLARE FUNCTION xlSheetPrintZoom      LIB "libxl.dll"  ALIAS "xlSheetPrintZoomA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetPrintZoom      LIB "libxl.dll"  ALIAS "xlSheetSetPrintZoomA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL zoom AS LONG)


DECLARE FUNCTION xlSheetGetPrintFit      LIB "libxl.dll"  ALIAS "xlSheetGetPrintFitA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL wPages AS LONG PTR, BYVAL hPages AS LONG PTR) AS LONG
DECLARE sub xlSheetSetPrintFit      LIB "libxl.dll"  ALIAS "xlSheetSetPrintFitA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL wPages AS LONG, BYVAL hPages AS LONG)


DECLARE FUNCTION xlSheetLandscape      LIB "libxl.dll"  ALIAS "xlSheetLandscapeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetLandscape      LIB "libxl.dll"  ALIAS "xlSheetSetLandscapeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL landscape AS LONG)


DECLARE FUNCTION xlSheetPaper      LIB "libxl.dll"  ALIAS "xlSheetPaperA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetPaper      LIB "libxl.dll"  ALIAS "xlSheetSetPaperA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL paper AS LONG)


DECLARE FUNCTION xlSheetHeader      LIB "libxl.dll"  ALIAS "xlSheetHeaderA"         _
                            (BYVAL sheet AS SheetHandle) AS STRING
DECLARE FUNCTION xlSheetSetHeader      LIB "libxl.dll"  ALIAS "xlSheetSetHeaderA"         _
                            (BYVAL sheet AS SheetHandle, BYREF header AS STRINGZ, BYVAL margin AS DOUBLE) AS LONG
DECLARE FUNCTION xlSheetHeaderMargin      LIB "libxl.dll"  ALIAS "xlSheetHeaderMarginA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE


DECLARE FUNCTION xlSheetFooter      LIB "libxl.dll"  ALIAS "xlSheetFooterA"         _
                            (BYVAL sheet AS SheetHandle) AS STRING
DECLARE FUNCTION xlSheetSetFooter      LIB "libxl.dll"  ALIAS "xlSheetSetFooterA"         _
                            (BYVAL sheet AS SheetHandle, BYREF footer AS STRINGZ, BYVAL margin AS DOUBLE) AS LONG
DECLARE FUNCTION xlSheetFooterMargin      LIB "libxl.dll"  ALIAS "xlSheetFooterMarginA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG) AS DOUBLE


DECLARE FUNCTION xlSheetHCenter      LIB "libxl.dll"  ALIAS "xlSheetHCenterA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetHCenter      LIB "libxl.dll"  ALIAS "xlSheetSetHCenterA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL hCenter AS LONG)


DECLARE FUNCTION xlSheetVCenter      LIB "libxl.dll"  ALIAS "xlSheetVCenterA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetVCenter      LIB "libxl.dll"  ALIAS "xlSheetSetVCenterA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL vCenter AS LONG)


DECLARE FUNCTION xlSheetMarginLeft      LIB "libxl.dll"  ALIAS "xlSheetMarginLeftA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE sub xlSheetSetMarginLeft      LIB "libxl.dll"  ALIAS "xlSheetSetMarginLeftA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL fMargin AS DOUBLE)


DECLARE FUNCTION xlSheetMarginRight      LIB "libxl.dll"  ALIAS "xlSheetMarginRightA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE SUB xlSheetSetMarginRight      LIB "libxl.dll"  ALIAS "xlSheetSetMarginRightA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL fMargin AS DOUBLE)


DECLARE FUNCTION xlSheetMarginTop      LIB "libxl.dll"  ALIAS "xlSheetMarginTopA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE sub xlSheetSetMarginTop      LIB "libxl.dll"  ALIAS "xlSheetSetMarginTopA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL fMargin AS DOUBLE)


DECLARE FUNCTION xlSheetMarginBottom      LIB "libxl.dll"  ALIAS "xlSheetMarginBottomA"         _
                            (BYVAL sheet AS SheetHandle) AS DOUBLE
DECLARE sub xlSheetSetMarginBottom      LIB "libxl.dll"  ALIAS "xlSheetSetMarginBottomA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL fMargin AS DOUBLE)


DECLARE FUNCTION xlSheetPrintRowCol      LIB "libxl.dll"  ALIAS "xlSheetPrintRowColA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetPrintRowCol      LIB "libxl.dll"  ALIAS "xlSheetSetPrintRowColA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL nPrint AS LONG)

DECLARE FUNCTION xlSheetPrintRepeatRows      LIB "libxl.dll"  ALIAS "xlSheetPrintRepeatRowsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG ptr, BYVAL rowLast AS LONG ptr) AS LONG
DECLARE sub xlSheetSetPrintRepeatRows      LIB "libxl.dll"  ALIAS "xlSheetSetPrintRepeatRowsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG)

DECLARE FUNCTION xlSheetPrintRepeatCols      LIB "libxl.dll"  ALIAS "xlSheetPrintRepeatColsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG ptr, BYVAL colLast AS LONG ptr) AS LONG
DECLARE sub xlSheetSetPrintRepeatCols      LIB "libxl.dll"  ALIAS "xlSheetSetPrintRepeatColsA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL colFirst AS LONG, BYVAL colLast AS LONG)

DECLARE FUNCTION xlSheetPrintArea       LIB "libxl.dll"  ALIAS "xlSheetPrintAreaA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG ptr, BYVAL rowLast AS LONG ptr, BYVAL colFirst AS LONG ptr, BYVAL colLast AS LONG ptr) as long
DECLARE sub xlSheetSetPrintArea      LIB "libxl.dll"  ALIAS "xlSheetSetPrintAreaA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG)


DECLARE sub xlSheetClearPrintRepeats      LIB "libxl.dll"  ALIAS "xlSheetClearPrintRepeatsA"         _
                            (BYVAL sheet AS SheetHandle)
DECLARE sub xlSheetClearPrintArea      LIB "libxl.dll"  ALIAS "xlSheetClearPrintAreaA"         _
                            (BYVAL sheet AS SheetHandle)


DECLARE FUNCTION xlSheetGetNamedRange      LIB "libxl.dll"  ALIAS "xlSheetGetNamedRangeA"         _
                            (BYVAL sheet AS SheetHandle, BYREF rangeName AS STRINGZ, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR, _
                             BYVAL scopeId AS LONG, BYVAL hidden_ AS LONG PTR ) AS LONG
DECLARE FUNCTION xlSheetSetNamedRange      LIB "libxl.dll"  ALIAS "xlSheetSetNamedRangeA"         _
                            (BYVAL sheet AS SheetHandle, BYREF rangeName AS STRINGZ, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG, _
                             BYVAL scopeId AS LONG) AS LONG
DECLARE FUNCTION xlSheetDelNamedRange      LIB "libxl.dll"  ALIAS "xlSheetDelNamedRangeA"         _
                            (BYVAL sheet AS SheetHandle, BYREF rangeName AS STRINGZ, BYVAL scopeId AS LONG) AS LONG

DECLARE FUNCTION xlSheetNamedRangeSize      LIB "libxl.dll"  ALIAS "xlSheetNamedRangeSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetNamedRange      LIB "libxl.dll"  ALIAS "xlSheetNamedRangeA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR, _
                             BYVAL scopeId AS LONG, BYVAL hidden_ AS LONG PTR ) AS STRING


DECLARE FUNCTION xlSheetHyperlinkSize      LIB "libxl.dll"  ALIAS "xlSheetHyperlinkSizeA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetHyperlink      LIB "libxl.dll"  ALIAS "xlSheetHyperlinkA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG, BYVAL rowFirst AS LONG PTR, BYVAL rowLast AS LONG PTR, BYVAL colFirst AS LONG PTR, BYVAL colLast AS LONG PTR) AS STRING
DECLARE FUNCTION xlSheetDelHyperlink      LIB "libxl.dll"  ALIAS "xlSheetDelHyperlinkA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL index AS LONG) AS LONG
DECLARE sub xlSheetAddHyperlink      LIB "libxl.dll"  ALIAS "xlSheetAddHyperlinkA"         _
                            (BYVAL sheet AS SheetHandle, BYREF hyperlink AS STRINGZ, BYVAL rowFirst AS LONG, BYVAL rowLast AS LONG, BYVAL colFirst AS LONG, BYVAL colLast AS LONG)


DECLARE FUNCTION xlSheetName      LIB "libxl.dll"  ALIAS "xlSheetNameA"         _
                            (BYVAL sheet AS SheetHandle) AS STRING
DECLARE sub xlSheetSetName      LIB "libxl.dll"  ALIAS "xlSheetSetNameA"         _
                            (BYVAL sheet AS SheetHandle, BYREF sheetName AS STRINGZ)


DECLARE FUNCTION xlSheetProtect      LIB "libxl.dll"  ALIAS "xlSheetProtectA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetProtect      LIB "libxl.dll"  ALIAS "xlSheetSetProtectA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL protect AS LONG)


DECLARE FUNCTION xlSheetHidden     LIB "libxl.dll"  ALIAS "xlSheetHiddenA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE FUNCTION xlSheetSetHidden     LIB "libxl.dll"  ALIAS "xlSheetSetHiddenA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL hidden AS LONG) AS LONG


DECLARE sub xlSheetGetTopLeftView     LIB "libxl.dll"  ALIAS "xlSheetGetTopLeftViewA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG PTR, BYVAL col AS LONG PTR)
DECLARE sub xlSheetSetTopLeftView     LIB "libxl.dll"  ALIAS "xlSheetSetTopLeftViewA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG)


declare sub xlSheetSetAutoFitArea LIB "libxl.dll"  ALIAS "xlSheetSetAutoFitAreaA"         _
              (BYVAL sheet AS SheetHandle, byval rowFirst as long, byval colFirst as long, byval rowLast as long, byval colLast as long)

DECLARE FUNCTION xlSheetRightToLeft     LIB "libxl.dll"  ALIAS "xlSheetRightToLeftA"         _
                            (BYVAL sheet AS SheetHandle) AS LONG
DECLARE sub xlSheetSetRightToLeft     LIB "libxl.dll"  ALIAS "xlSheetSetRightToLeftA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL rightToLeft AS LONG)


DECLARE sub xlSheetAddrToRowCol     LIB "libxl.dll"  ALIAS "xlSheetAddrToRowColA"         _
                            (BYVAL sheet AS SheetHandle, BYREF addr_ AS STRINGZ, BYVAL row AS LONG PTR, BYVAL col AS LONG PTR, _
                             BYVAL rowRelative AS LONG PTR, BYVAL colRelative AS LONG PTR)
DECLARE FUNCTION xlSheetRowColToAddr     LIB "libxl.dll"  ALIAS "xlSheetRowColToAddrA"         _
                            (BYVAL sheet AS SheetHandle, BYVAL row AS LONG, BYVAL col AS LONG, BYVAL rowRelative AS LONG, BYVAL colRelative AS LONG) AS STRING


'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Format function declarations'''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
DECLARE FUNCTION xlFormatFont    LIB "libxl.dll"  ALIAS "xlFormatFontA"      _
                            (BYVAL format AS FormatHandle) AS FontHandle
DECLARE FUNCTION xlFormatSetFont LIB "libxl.dll"  ALIAS "xlFormatSetFontA"      _
                            (BYVAL format AS FormatHandle, BYVAL font AS FontHandle) AS LONG

DECLARE FUNCTION xlFormatNumFormat    LIB "libxl.dll"  ALIAS "xlFormatNumFormatA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetNumFormat LIB "libxl.dll"  ALIAS "xlFormatSetNumFormatA"      _
                            (BYVAL format AS FormatHandle, BYVAL numFormat AS LONG)

DECLARE FUNCTION xlFormatAlignH    LIB "libxl.dll"  ALIAS "xlFormatAlignHA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetAlignH LIB "libxl.dll"  ALIAS "xlFormatSetAlignHA"      _
                            (BYVAL format AS FormatHandle, BYVAL align AS LONG)

DECLARE FUNCTION xlFormatAlignV    LIB "libxl.dll"  ALIAS "xlFormatAlignVA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetAlignV LIB "libxl.dll"  ALIAS "xlFormatSetAlignVA"      _
                            (BYVAL format AS FormatHandle, BYVAL align AS LONG)

DECLARE FUNCTION xlFormatWrap    LIB "libxl.dll"  ALIAS "xlFormatWrapA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetWrap LIB "libxl.dll"  ALIAS "xlFormatSetWrapA"      _
                            (BYVAL format AS FormatHandle, BYVAL wrap AS LONG)

DECLARE FUNCTION xlFormatRotation     LIB "libxl.dll"  ALIAS "xlFormatRotationA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE FUNCTION xlFormatSetRotation  LIB "libxl.dll"  ALIAS "xlFormatSetRotationA"      _
                            (BYVAL format AS FormatHandle, BYVAL rotation AS LONG) AS LONG

DECLARE FUNCTION xlFormatIndent     LIB "libxl.dll"  ALIAS "xlFormatIndentA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetIndent  LIB "libxl.dll"  ALIAS "xlFormatSetIndentA"      _
                            (BYVAL format AS FormatHandle, BYVAL indent AS LONG)

DECLARE FUNCTION xlFormatShrinkToFit     LIB "libxl.dll"  ALIAS "xlFormatShrinkToFitA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetShrinkToFit  LIB "libxl.dll"  ALIAS "xlFormatSetShrinkToFitA"      _
                            (BYVAL format AS FormatHandle, BYVAL shrinkToFit AS LONG)

DECLARE FUNCTION xlFormatSetBorder     LIB "libxl.dll"  ALIAS "xlFormatSetBorderA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG) AS LONG
DECLARE sub xlFormatSetBorderColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderLeft     LIB "libxl.dll"  ALIAS "xlFormatBorderLeftA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderLeft  LIB "libxl.dll"  ALIAS "xlFormatSetBorderLeftA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG)

DECLARE FUNCTION xlFormatBorderRight     LIB "libxl.dll"  ALIAS "xlFormatBorderRightA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderRight  LIB "libxl.dll"  ALIAS "xlFormatSetBorderRightA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG)

DECLARE FUNCTION xlFormatBorderTop     LIB "libxl.dll"  ALIAS "xlFormatBorderTopA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderTop  LIB "libxl.dll"  ALIAS "xlFormatSetBorderTopA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG)

DECLARE FUNCTION xlFormatBorderBottom     LIB "libxl.dll"  ALIAS "xlFormatBorderBottomA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderBottom  LIB "libxl.dll"  ALIAS "xlFormatSetBorderBottomA"      _
                            (BYVAL format AS FormatHandle, BYVAL style AS LONG)

DECLARE FUNCTION xlFormatBorderLeftColor     LIB "libxl.dll"  ALIAS "xlFormatBorderLeftColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderLeftColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderLeftColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderRightColor     LIB "libxl.dll"  ALIAS "xlFormatBorderRightColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderRightColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderRightColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderTopColor     LIB "libxl.dll"  ALIAS "xlFormatBorderTopColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderTopColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderTopColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderBottomColor     LIB "libxl.dll"  ALIAS "xlFormatBorderBottomColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderBottomColor  LIB "libxl.dll"  ALIAS "xlFormatSetBorderBottomColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatBorderDiagonal     LIB "libxl.dll"  ALIAS "xlFormatBorderDiagonalA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderDiagonal  LIB "libxl.dll"  ALIAS "xlFormatSetBorderDiagonalA"      _
                            (BYVAL format AS FormatHandle, BYVAL border AS LONG)

DECLARE FUNCTION xlFormatBorderDiagonalStyle     LIB "libxl.dll"  ALIAS "xlFormatBorderDiagonalStyleA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetBorderDiagonalStyle  LIB "libxl.dll"  ALIAS "xlFormatSetBorderDiagonalStyleA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatFillPattern     LIB "libxl.dll"  ALIAS "xlFormatFillPatternA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetFillPattern  LIB "libxl.dll"  ALIAS "xlFormatSetFillPatternA"      _
                            (BYVAL format AS FormatHandle, BYVAL pattern AS LONG)

DECLARE FUNCTION xlFormatPatternForegroundColor     LIB "libxl.dll"  ALIAS "xlFormatPatternForegroundColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetPatternForegroundColor  LIB "libxl.dll"  ALIAS "xlFormatSetPatternForegroundColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatPatternBackgroundColor     LIB "libxl.dll"  ALIAS "xlFormatPatternBackgroundColorA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetPatternBackgroundColor  LIB "libxl.dll"  ALIAS "xlFormatSetPatternBackgroundColorA"      _
                            (BYVAL format AS FormatHandle, BYVAL color AS LONG)

DECLARE FUNCTION xlFormatLocked     LIB "libxl.dll"  ALIAS "xlFormatLockedA"      _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetLocked  LIB "libxl.dll"  ALIAS "xlFormatSetLockedA"      _
                            (BYVAL format AS FormatHandle, BYVAL locked AS LONG)

DECLARE FUNCTION xlFormatHidden     LIB "libxl.dll"  ALIAS "xlFormatHiddenA"         _
                            (BYVAL format AS FormatHandle) AS LONG
DECLARE sub xlFormatSetHidden  LIB "libxl.dll"  ALIAS "xlFormatSetHiddenA"      _
                            (BYVAL format AS FormatHandle, BYVAL hidden_ AS LONG)

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''''''''''''''''Font function declarations'''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
DECLARE FUNCTION xlFontSize    LIB "libxl.dll"  ALIAS "xlFontSizeA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetSize LIB "libxl.dll"  ALIAS "xlFontSetSizeA"      _
                            (BYVAL font AS FontHandle, BYVAL fontsize AS LONG)

DECLARE FUNCTION xlFontItalic    LIB "libxl.dll"  ALIAS "xlFontItalicA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetItalic LIB "libxl.dll"  ALIAS "xlFontSetItalicA"      _
                            (BYVAL font AS FontHandle, BYVAL italic AS LONG)

DECLARE FUNCTION xlFontStrikeOut    LIB "libxl.dll"  ALIAS "xlFontStrikeOutA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetStrikeOut LIB "libxl.dll"  ALIAS "xlFontSetStrikeOutA"      _
                            (BYVAL font AS FontHandle, BYVAL strikeOut AS LONG)

DECLARE FUNCTION xlFontColor    LIB "libxl.dll"  ALIAS "xlFontColorA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetColor LIB "libxl.dll"  ALIAS "xlFontSetColorA"      _
                            (BYVAL font AS FontHandle, BYVAL fColor AS LONG)

DECLARE FUNCTION xlFontBold    LIB "libxl.dll"  ALIAS "xlFontBoldA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetBold LIB "libxl.dll"  ALIAS "xlFontSetBoldA"      _
                            (BYVAL font AS FontHandle, BYVAL bold AS LONG)

DECLARE FUNCTION xlFontScript    LIB "libxl.dll"  ALIAS "xlFontScriptA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetScript LIB "libxl.dll"  ALIAS "xlFontSetScriptA"      _
                            (BYVAL font AS FontHandle, BYVAL script AS LONG)

DECLARE FUNCTION xlFontUnderline    LIB "libxl.dll"  ALIAS "xlFontUnderlineA"      _
                            (BYVAL font AS FontHandle) AS LONG
DECLARE sub xlFontSetUnderline LIB "libxl.dll"  ALIAS "xlFontSetUnderlineA"      _
                            (BYVAL font AS FontHandle, BYVAL underline AS LONG)

DECLARE FUNCTION xlFontName    LIB "libxl.dll"  ALIAS "xlFontNameA"      _
                            (BYVAL font AS FontHandle) AS STRING
DECLARE FUNCTION xlFontSetName LIB "libxl.dll"  ALIAS "xlFontSetNameA"      _
                            (BYVAL font AS FontHandle, BYREF fontName AS STRINGZ) AS LONG
