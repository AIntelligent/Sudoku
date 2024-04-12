/*
 * SUDOKUAPI.H
 * Hakan Emre KARTAL
 * hek@nula.com.tr
 * Iskenderun/HATAY
 *
 * 04/04/2006
 *    o Üretildi
 * 23/04/2006
 *    o Bazý düzeltmeler eklendi.
 *    o Sudoku harita üreteci rastgele sayý üreteç deðeri deðiþtirildi.
 *    o Sol dikey baþlýk çubuðu rengi ve durum çubuðu renkleri deðiþtirildi.
 *    o Son þekli verildi.
 * 10/04/2024
 *    o Bazý kiþisel bilgiler güncellendi.
 *    o Borland C++Builder 6.0 ile yeniden derlendi.
 *
 * Written by Hakan Emre KARTAL in Iskenderun/HATAY on 04/04/2006,
 * developed for Borland C++Builder 6.0
 */
#if !defined(__sudokuapi_header_file)

#define __sudokuapi_header_file

#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Types.hpp>

#define SUDOKU_CELL_X			3
#define SUDOKU_CELL_Y			3
#define SUDOKU_DIM_X				9
#define SUDOKU_DIM_Y				9
#define SUDOKU_DIM_SIZE			9 * 9
#define SUDOKU_CELL_COUNT		9
#define SUDOKU_LINE_LENGTH		9 * 3
#define SUDOKU_CHECKSUM			((1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9) * 9)

#define MAX_NUMBER_COUNT		4

#define VERY_BEGINNER         0
#define BEGINNER              1
#define NEW_LEARNER           2
#define CONVERSANT            3
#define MASTER                4
#define PROFESSIONAL          5

//const int Levels[] = { 6, 5, 4, 3, 2, 1 };

typedef \
   union tagSUDOKUDIM
   {
	   BYTE			_Numbers[ SUDOKU_DIM_Y ][ SUDOKU_DIM_X ];
	   BYTE			_nDim[ SUDOKU_DIM_SIZE ];
   }
   *PSUDOKUDIM,
   SUDOKUDIM;

typedef \
   struct tagSUDOKUMAP
	{

	   union
		{
		   bool		_Checks[ SUDOKU_DIM_Y ][ SUDOKU_DIM_X ];
		   bool		_cDim[ SUDOKU_DIM_SIZE ];
		}
		Check;

   /*
      union
      {
         short    _Score[ SUDOKU_DIM_Y ][ SUDOKU_DIM_X ];
         short    _sDim[ SUDOKU_DIM_SIZE ];
      }
      Score;
   */

	   SUDOKUDIM	Map;

	}
	*PSUDOKUMAP,
	SUDOKUMAP;

typedef \
   struct tagSUDOKUMAPFILEDATA
   {
      SUDOKUMAP      _Sudoku;
      SUDOKUDIM      _Solve;
      int            _DefCol;
      int            _DefRow;
      int            _LastCol;
      int            _LastRow;
      int            _Level;
      double         _Time;
   }
   *PSUDOKUMAPFILEDATA,
   SUDOKUMAPFILEDATA;

///////////////////////////////////////////////////////////////////////////////
// Logging                                                                   //
///////////////////////////////////////////////////////////////////////////////

#if defined(__SUDOKULOGGER__)

typedef \
   struct tagEVENTLOG
   {
      int            grid_col;
      int            grid_row;

      int            button_clicked;

      tagEVENTLOG *  prev_eventlog;
   }
   *PEVENTLOG,
   EVENTLOG;

#define EVENTLOG_DLEN() sizeof(EVENTLOG) - sizeof(PEVENTLOG)

typedef \
   struct tagLOG
   {
      SUDOKUMAP      solve_map;

      int            event_count;
      PEVENTLOG      event_list;

      tagLOG *       prev_log;
   }
   *PLOG,
   LOG;

#define LOG_DLEN() sizeof(LOG) - (sizeof(PEVENTLOG) + sizeof(PLOG))

#endif

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#define CELLTOX(C)(((C)%3)*3)
#define CELLTOY(C)(((C)/3)*3)
#define COORDTOCELL(X,Y)(((X)/3)+(((Y)/3) *3))

BOOL	   WINAPI	         MapCheckInY(PSUDOKUDIM lpMap, int X, int Number, int * lpRow = NULL);
BOOL	   WINAPI	         MapCheckInX(PSUDOKUDIM lpMap, int Y, int Number, int * lpCol = NULL);
BOOL	   WINAPI	         MapCheckInCell(PSUDOKUDIM lpMap, int Cell, int Number, int * lpRow = NULL, int * lpCol = NULL);
BOOL	   WINAPI	         MapCheckInvalidValue(PSUDOKUDIM lpMap, int X, int Y, int Number);
VOID	   WINAPI	         MapCreate(PSUDOKUDIM lpMap);
VOID     WINAPI            CreateErrorList(PSUDOKUDIM lpMap, int Number, int X, int Y, TList *lpList);
VOID	   WINAPI	         GameMapCreate(PSUDOKUDIM lpSolveMap, PSUDOKUMAP lpSudokuMap, int iLevel = NEW_LEARNER);
BOOL	   WINAPI	         SudokuCheckFinal(PSUDOKUMAP lpSudokuMap);
BOOL     WINAPI            IsInvalidPoint(PSUDOKUMAP lpMap, int X, int Y);

VOID     WINAPI            SaveSudokuGame(LPCTSTR, PSUDOKUMAPFILEDATA);
VOID     WINAPI            RestoreSudokuGame(LPCTSTR, PSUDOKUMAPFILEDATA);

#if defined(__SUDOKULOGGER__)
   PLOG     WINAPI         add_log( PSUDOKUMAP, const PLOG );
   BOOL     WINAPI         add_eventlog( int, int, int );
   VOID     WINAPI         free_log( void );
   VOID     WINAPI         save_log( LPCTSTR );
#endif

#if (_MFC_VER >= 1100)
   int random(int max_range)
#endif

#endif
