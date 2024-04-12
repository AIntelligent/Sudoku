/*
 * SUDOKUAPI.CPP
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
#include "sudokuapi.h"

BOOL WINAPI MapCheckInY(PSUDOKUDIM lpMap, int X, int Number, int * lpRow)
{
   if (lpMap)
   {
		for (int i = 0; i < SUDOKU_DIM_Y; i++)
      {
			if (lpMap->_Numbers[ i ][ X ] == Number)
         {
            if (lpRow) *lpRow = i;
				return(TRUE);
         }
      }
   }

	return(FALSE);
}

BOOL WINAPI MapCheckInX(PSUDOKUDIM lpMap, int Y, int Number, int * lpCol)
{
	if (lpMap)
   {
		for (int i = 0; i < SUDOKU_DIM_X; i++)
      {
			if (lpMap->_Numbers[ Y ][ i ] == Number)
         {
            if (lpCol) *lpCol = i;
				return(TRUE);
         }
      }
   }

	return(FALSE);
}

BOOL WINAPI MapCheckInCell(PSUDOKUDIM lpMap, int Cell, int Number, int * lpRow, int * lpCol)
{
	if (lpMap)
   {
		int StepX = CELLTOX(Cell);
		int StepY = CELLTOY(Cell);

		for (int y = 0; y < SUDOKU_CELL_Y; y++)
      {
			for (int x = 0; x < SUDOKU_CELL_X; x++)
         {
				if (lpMap->_Numbers[ StepY + y ][ StepX + x ] == Number)
            {
               if (lpRow) *lpRow = (StepY + y);
               if (lpCol) *lpCol = (StepX + x);
				   return(TRUE);
            }
         }
		}
   }

	return(FALSE);
}

BOOL WINAPI MapCheckInvalidValue(PSUDOKUDIM lpMap, int X, int Y, int Number)
{
	if (MapCheckInCell(lpMap, COORDTOCELL(X, Y), Number)) return(TRUE);
	if (MapCheckInX(lpMap, Y, Number)) return(TRUE);
	if (MapCheckInY(lpMap, X, Number)) return(TRUE);

	return(FALSE);
}

BOOL WINAPI CheckInErrorList(const POINT &lpPoint, TList *lpList)
{
#define sP(i) PPOINT(lpList->Items[ i ])

   if (lpList)
   {
      for (int i = 0; i < lpList->Count; i++)
      {
         if ((lpPoint.x == sP(i)->x) && (lpPoint.y == sP(i)->y))
         {
            return(BOOL)TRUE;
         }
      }
   }

#undef sP

   return(BOOL)FALSE;
}

PPOINT WINAPI CreatePointObject( const POINT &point )
{
   PPOINT   p = new POINT;
   *p = point;
   return(PPOINT)p;
}

BOOL WINAPI IsValidPoint( const POINT &point )
{
   return(BOOL)((point.x != -1) && (point.y != -1));
}

VOID WINAPI CreateErrorList(PSUDOKUDIM lpMap, int Number, int X, int Y, TList *lpList)
{
   if ((lpMap) && (lpList))
   {
      POINT    p;

#define p_x()(int *)&p.x
#define p_y()(int *)&p.y

      p.x = -1;
      p.y = Y;
      MapCheckInX( lpMap, Y, Number, p_x() );

      if (IsValidPoint(p) && (!CheckInErrorList( p, lpList )))
      {
         lpList->Add( CreatePointObject( p ) );
      }

      p.x = X;
      p.y = -1;
      MapCheckInY( lpMap, X, Number, p_y() );

      if (IsValidPoint(p) && (!CheckInErrorList( p, lpList )))
      {
         lpList->Add( CreatePointObject( p ) );
      }

      p.x = p.y = -1;
      MapCheckInCell( lpMap, COORDTOCELL(X, Y), Number, p_y(), p_x() );

      if (IsValidPoint(p) && (!CheckInErrorList( p, lpList )))
      {
         lpList->Add( CreatePointObject( p ) );
      }
   }
}

#if (_MFC_VER >= 1100)
int _random(int max_range)
{
   return(int)(max_range * (((float)rand()) / ((float)(RAND_MAX + 1))));
}
#else
#  define _random(m) std::random((m))
#endif

VOID WINAPI MapCreate(PSUDOKUDIM lpMap)
{
	int x;
	int y;
	int _x;
	int _y;
	int CRC = 0;
	int R;
	int Cell;

   //srand((unsigned)time(NULL));
   srand(_random(RAND_MAX));

	for (Cell = 0; Cell < SUDOKU_CELL_COUNT; Cell++)
   {
		for (y = 0; y < SUDOKU_CELL_Y; y++)
      {
			for (x = 0; x < SUDOKU_CELL_X; x++)
         {

//__CRC_ERROR_CHECK:
            for ( ;; )
            {
				   if (CRC > SUDOKU_DIM_SIZE)
               {
					   CRC  = 0;
					   Cell = Cell - Cell % 3;
					   memset(&lpMap->_nDim[ Cell * SUDOKU_DIM_Y ], 0, SUDOKU_LINE_LENGTH * sizeof(BYTE));
					   y = x = 0;
               }

				   R = 1 + _random(9);

				   if (MapCheckInCell(lpMap, Cell, R))
				   {
					   CRC++;
					   //goto __CRC_ERROR_CHECK;
                  continue;
				   }

				   _x = x + CELLTOX(Cell);
				   _y = y + CELLTOY(Cell);

				   if (MapCheckInX(lpMap, _y, R) || MapCheckInY(lpMap, _x, R))
				   {
					   CRC++;
					   //goto __CRC_ERROR_CHECK;
                  continue;
				   }

               break;
            }

				_x = x + CELLTOX(Cell);
				_y = y + CELLTOY(Cell);

				CRC = 0;
				lpMap->_Numbers[ _y ][ _x ] = R;
         }
      }
   }
}

VOID WINAPI GameMapCreate(PSUDOKUDIM lpSolveMap, PSUDOKUMAP lpSudokuMap, int iLevel)
{
	if ((lpSolveMap) && (lpSudokuMap))
   {
		memset(lpSolveMap, 0, sizeof(SUDOKUDIM));
		memset(lpSudokuMap, 0, sizeof(SUDOKUMAP));

		MapCreate(lpSolveMap);

		int Rcount;
		int x;

		//srand((unsigned)time(NULL));
      srand(_random(RAND_MAX));

		for (int y = 0; y < SUDOKU_DIM_Y; y++)
      {
         Rcount = 1 + _random(6 - iLevel);

			for (int r = 0; r < Rcount; r++)
         {
				for ( ;; )
            {
					x = _random(SUDOKU_DIM_X);
					if (!lpSudokuMap->Check._Checks[ y ][ x ]) break;
            }

				lpSudokuMap->Check._Checks[ y ][ x ] = TRUE;
				lpSudokuMap->Map._Numbers[ y ][ x ]  = lpSolveMap->_Numbers[ y ][ x ];
         }
      }
   }
}

BOOL WINAPI SudokuCheckFinal(PSUDOKUMAP lpSudokuMap)
{
	int T = 0;

	if (lpSudokuMap)
   {
		for (int y = 0; y < SUDOKU_DIM_Y; y++)
      {
			for (int x = 0; x < SUDOKU_DIM_X; x++)
         {
				T += lpSudokuMap->Map._Numbers[ y ][ x ];
         }
      }
   }

	return(BOOL)(T == SUDOKU_CHECKSUM);
}

BOOL WINAPI IsInvalidPoint(PSUDOKUMAP lpMap, int X, int Y)
{
   return(BOOL)(lpMap->Check._Checks[ Y ][ X ] == true);
}

VOID WINAPI SaveSudokuGame(LPCTSTR lpFileName, PSUDOKUMAPFILEDATA lpData)
{
   int file_handle = FileCreate( lpFileName );

   if (file_handle != -1)
   {
      FileWrite( file_handle, lpData, sizeof(SUDOKUMAPFILEDATA) );
      FileClose( file_handle );
   }
}

VOID WINAPI RestoreSudokuGame(LPCTSTR lpFileName, PSUDOKUMAPFILEDATA lpData)
{
   int file_handle = FileOpen( lpFileName, fmOpenReadWrite );

   if (file_handle != -1)
   {
      FileRead( file_handle, lpData, sizeof(SUDOKUMAPFILEDATA) );
      FileClose( file_handle );
   }
}

#if defined(__SUDOKULOGGER__)

static PLOG pSudokuLog = PLOG(0L);

BOOL WINAPI add_eventlog( int iCol, int iRow, int iButtonClicked )
{
   if (pSudokuLog)
   {
      PEVENTLOG   pLog = new EVENTLOG;

      pLog->prev_eventlog = pSudokuLog->event_list;
      pSudokuLog->event_list = pLog;

      pLog->grid_col = iCol;
      pLog->grid_row = iRow;
      pLog->button_clicked = iButtonClicked;

      pSudokuLog->event_count++;

      return(BOOL)TRUE;
   }

   return(BOOL)FALSE;
}

PLOG WINAPI add_log( PSUDOKUMAP lpSolve, const PLOG lpLog )
{
   PLOG pLog = new LOG;

   pLog->prev_log = pSudokuLog;
   pSudokuLog = pLog;


   memmove( &pLog->solve_map, lpSolve, sizeof(SUDOKUMAP) );
   pLog->event_count = 0;
   pLog->event_list = NULL;

   return(PLOG)0L;
}

VOID WINAPI free_log( void )
{
   PLOG        pLog;
   PEVENTLOG   pEventLog;

   while (pSudokuLog)
   {
      pLog = pSudokuLog->prev_log;

      while (pSudokuLog->event_list)
      {
         pEventLog = pSudokuLog->event_list->prev_eventlog;

         delete pSudokuLog->event_list;

         pSudokuLog->event_list = pEventLog;
      }

      delete pSudokuLog;

      pSudokuLog = pLog;
   }
}

VOID WINAPI save_log( LPCTSTR lpLogFile )
{
   int file_handle = FileCreate( lpLogFile );

   if (file_handle != -1)
   {
      PLOG        pLog = pSudokuLog;
      PEVENTLOG   pEventLog;

      while (pLog)
      {
         FileWrite( file_handle, pLog, LOG_DLEN() );

         pEventLog = pLog->event_list;

         while (pEventLog)
         {
            FileWrite( file_handle, pEventLog, EVENTLOG_DLEN() );
            pEventLog = pEventLog->prev_eventlog;
         }

         pLog = pLog->prev_log;
      }

      FileClose( file_handle );
   }
}

#endif
