//Headers
#include<windows.h>
//Global function declartation
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//WINMAIN()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Application Started
	MessageBox(NULL,L"App Started",L"WInMAin",MB_ICONHAND);
	//varibale Declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
		
	//code
	//initalization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;

	//regiter above class
	RegisterClassEx(&wndclass);
    
	//create window
	hwnd = CreateWindow(szAppName, TEXT("My Application"), WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

//Defination of second callback function

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{   
	//Char Array declaration for Messagebox string
	TCHAR strToDisplay[] = TEXT("WM_Create message sent");
	TCHAR titleStr[] = TEXT("Messages");

	//Object Declaration for PAINT 
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	 
	//code
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		MessageBox(hwnd,strToDisplay,titleStr,MB_ICONEXCLAMATION);
		break;
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		DrawText(hdc, L"HELLO WORLD", -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER | COLOR_BTNHIGHLIGHT);
		EndPaint(hwnd, &ps);
		break;
	}
	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}







