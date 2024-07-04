#define WIN_MAX_X 1600
#define WIN_MAX_Y 900
#define WIN_POS_X 0
#define WIN_POS_Y 0

#include "DxLib.h"
#include "Sub.h"
#include "Pic.h"
#include "Act.h"

// ÉvÉçÉOÉâÉÄÇÕ WinMain Ç©ÇÁénÇ‹ÇËÇ‹Ç∑
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{

	DxLib_Init();

	//Winddow Init
	SetWindowInitPosition(WIN_POS_X, WIN_POS_Y); //Background position
	SetWindowText("Othello");                    //Background title
	SetGraphMode(WIN_MAX_X, WIN_MAX_Y, 32);      //Background size
	SetBackgroundColor(255, 255, 255);           //Background color
	SetDrawScreen(DX_SCREEN_BACK);

	//Read
	Col.Read();
	Fon.Read();
	Pic.Read();

	//Case Select
	while (ScreenFlip() == 0 &&
		ClearDrawScreen() == 0 &&
		ProcessMessage() == 0 &&
		Key.Read() == 0 &&
		Key.Inf[KEY_INPUT_ESCAPE] == 0)
	{
		Act.Out();
	}

	//WaitKey();				
	DxLib_End();				
	return 0;				 
}
