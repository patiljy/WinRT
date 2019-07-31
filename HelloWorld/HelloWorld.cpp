//headers
#include<Windows.h>

//global function declaration
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline, int iCmdShow)
{
	//varibale declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("HELLOW_WORLD_APP");

	//code
	//Inilazation of Class Param
	wndclass.cbClsExtra = 0;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hInstance = hInstance;
	//Function Pointer
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	//Register aboce class
	RegisterClassEx(&wndclass);

	//create Window
	hwnd = CreateWindow(szAppName,TEXT("Hello World"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

	//ShowWindow
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//message loop

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}

//defination of WndProc
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
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

	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		DrawText(hdc, L"HELLO WORLD", -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER | COLOR_BTNHIGHLIGHT);
		EndPaint(hwnd, &ps);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

