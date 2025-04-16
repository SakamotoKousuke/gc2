#include <Windows.h>
#include <cstdint>


//ウィンドウプロシージャ
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg,
	WPARAM wparam, LPARAM lparam) {


	//メッセージに応じてゲーム固有の処理を行う
	switch(msg) {
		//ウウィンドウが破壊された
		case WM_DESTROY:
			//OSに対して、アプリの終了を伝える
			PostQuitMessage(0);
			return 0;

	}

	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);

}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	OutputDebugStringA("Hello,Directx!\n");



WNDCLASS wc{};
//ウィンドウプロシージャ
wc.lpfnWndProc = WindowProc;
//ウィンドウクラス名
wc.lpszClassName = L"CG2WindowClass";
//インスタンスハンドル
wc.hInstance = GetModuleHandle(nullptr);
//カーソル
wc.hCursor = LoadCursor(nullptr, IDC_ARROW);

//ウィンドウクラスを登録する
RegisterClass(&wc);

//クライアント領域のサイズ
const int32_t kClientWidth = 1280;

const int32_t kClientHeight = 720;


//ウィンドウサイズを表す構造体にクライアント領域を入れる
RECT wrc = { 0,0,kClientWidth,kClientHeight };


//クライアント領域をもとに実際のサイズにwrcを変更してもらう
AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

HWND hwnd = CreateWindow(
	wc.lpszClassName,
	L"CG2",
	WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	wrc.right - wrc.left,
	wrc.bottom - wrc.top,
	nullptr,
	nullptr,
	wc.hInstance,
	nullptr


);

ShowWindow(hwnd, SW_SHOW);

MSG msg{};

while (msg.message != WM_QUIT) {

	if (msg.message != WM_QUIT) {

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {

		}
	}
}


return 0;
}