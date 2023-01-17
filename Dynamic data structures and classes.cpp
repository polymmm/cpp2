#include <windows.h>
#include <cmath>
#include <iostream>
#include <conio.h>
#define M_PI 3.14159265358979323846264338327950288

class circle
{
public:
	void Run(HWND hWnd)
	{
		HDC hDC;
		XFORM xForm;
		RECT rect;
		hDC = GetDC(hWnd);
		SetGraphicsMode(hDC, GM_ADVANCED);
		SetMapMode(hDC, MM_LOENGLISH);

		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			FillRect(hDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			if (GetAsyncKeyState(VK_LEFT))
			{
				step_w -= 10.0;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				step_w += 10.0;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				step_h -= 10.0;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				step_h += 10.0;
			}

			xForm.eM11 = (FLOAT)cos(0 * M_PI / 180.0);
			xForm.eM12 = (FLOAT)sin(0 * M_PI / 180.0);
			xForm.eM21 = (FLOAT)-sin(0 * M_PI / 180.0);
			xForm.eM22 = (FLOAT)cos(0 * M_PI / 180.0);
			xForm.eDx = (FLOAT)0.0 + step_w;
			xForm.eDy = (FLOAT)0.0 + step_h;

			SetWorldTransform(hDC, &xForm);
			GetClientRect(hWnd, (LPRECT)&rect);
			DPtoLP(hDC, (LPPOINT)&rect, 2);
			SelectObject(hDC, GetStockObject(WHITE_BRUSH));
			Ellipse(hDC, (rect.right / 2 - 100), (rect.bottom / 2 + 100), (rect.right / 2 + 100),
			        (rect.bottom / 2 - 100));
			SelectObject(hDC, GetStockObject(BLACK_BRUSH));
			TextOutA(hDC, rect.right / 2 - 147, rect.bottom / 2, "Use Up/Down/Right/Left to move; Esc to go back", 47);
			SelectObject(hDC, GetStockObject(GRAY_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 13), (rect.bottom / 2 + 113), (rect.right / 2 + 13),
			          (rect.bottom / 2 + 50));
			Sleep(10);
		}
		ReleaseDC(hWnd, hDC);
		system("cls");
	}

	void Rotate(HWND hWnd)
	{
		float phi;
		std::cout << "Enter the angle of the rotation in degrees:\n";
		std::cin >> phi;
		HDC hDC;
		XFORM xForm;
		RECT rect;
		hDC = GetDC(hWnd);
		SetGraphicsMode(hDC, GM_ADVANCED);
		SetMapMode(hDC, MM_LOENGLISH);

		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			FillRect(hDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			if (GetAsyncKeyState(VK_ADD))
			{
				angle += phi;
			}
			if (GetAsyncKeyState(VK_SUBTRACT))
			{
				angle -= phi;
			}

			xForm.eM11 = (FLOAT)cos(angle * M_PI / 180.0);
			xForm.eM12 = (FLOAT)sin(angle * M_PI / 180.0);
			xForm.eM21 = (FLOAT)-sin(angle * M_PI / 180.0);
			xForm.eM22 = (FLOAT)cos(angle * M_PI / 180.0);
			xForm.eDx = (FLOAT)0.0;
			xForm.eDy = (FLOAT)0.0;

			SetWorldTransform(hDC, &xForm);
			GetClientRect(hWnd, (LPRECT)&rect);
			DPtoLP(hDC, (LPPOINT)&rect, 2);
			SelectObject(hDC, GetStockObject(WHITE_BRUSH));
			Ellipse(hDC, (rect.right / 2 - 100), (rect.bottom / 2 + 100), (rect.right / 2 + 100),
			        (rect.bottom / 2 - 100));
			SelectObject(hDC, GetStockObject(BLACK_BRUSH));
			TextOutA(hDC, rect.right / 2 - 68, rect.bottom / 2, "Use +/- to rotate; Esc to go back", 34);
			SelectObject(hDC, GetStockObject(GRAY_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 13), (rect.bottom / 2 + 113), (rect.right / 2 + 13),
			          (rect.bottom / 2 + 50));
			Sleep(100);
		}
		ReleaseDC(hWnd, hDC);
		system("cls");
	}

	void Scale(HWND hWnd)
	{
		HDC hDC;
		XFORM xForm;
		RECT rect;
		hDC = GetDC(hWnd);
		SetGraphicsMode(hDC, GM_ADVANCED);
		SetMapMode(hDC, MM_LOENGLISH);

		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			FillRect(hDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			if (GetAsyncKeyState(VK_ADD))
			{
				scale += 0.05;
			}
			if (GetAsyncKeyState(VK_SUBTRACT))
			{
				scale -= 0.05;
			}

			xForm.eM11 = (FLOAT)scale;
			xForm.eM12 = (FLOAT)0.0;
			xForm.eM21 = (FLOAT)0.0;
			xForm.eM22 = (FLOAT)scale;
			xForm.eDx = (FLOAT)0.0;
			xForm.eDy = (FLOAT)0.0;

			SetWorldTransform(hDC, &xForm);
			GetClientRect(hWnd, (LPRECT)&rect);
			DPtoLP(hDC, (LPPOINT)&rect, 2);
			SelectObject(hDC, GetStockObject(WHITE_BRUSH));
			Ellipse(hDC, (rect.right / 2 - 100), (rect.bottom / 2 + 100), (rect.right / 2 + 100),
			        (rect.bottom / 2 - 100));
			SelectObject(hDC, GetStockObject(BLACK_BRUSH));
			TextOutA(hDC, rect.right / 2 - 67, rect.bottom / 2, "Use +/- to scale; Esc to go back", 33);
			SelectObject(hDC, GetStockObject(GRAY_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 13), (rect.bottom / 2 + 113), (rect.right / 2 + 13),
			          (rect.bottom / 2 + 50));
			Sleep(10);
		}
		ReleaseDC(hWnd, hDC);
		system("cls");
	}

private:
	float angle = 0.0, step_w = 0.0, step_h = 0.0, scale = 0.0;
};

class square
{
public:
	void Run(HWND hWnd)
	{
		HDC hDC;
		XFORM xForm;
		RECT rect;
		hDC = GetDC(hWnd);
		SetGraphicsMode(hDC, GM_ADVANCED);
		SetMapMode(hDC, MM_LOENGLISH);

		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			FillRect(hDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			if (GetAsyncKeyState(VK_LEFT))
			{
				step_w -= 10.0;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				step_w += 10.0;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				step_h -= 10.0;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				step_h += 10.0;
			}

			xForm.eM11 = (FLOAT)cos(0 * M_PI / 180.0);
			xForm.eM12 = (FLOAT)sin(0 * M_PI / 180.0);
			xForm.eM21 = (FLOAT)-sin(0 * M_PI / 180.0);
			xForm.eM22 = (FLOAT)cos(0 * M_PI / 180.0);
			xForm.eDx = (FLOAT)0.0 + step_w;
			xForm.eDy = (FLOAT)0.0 + step_h;

			SetWorldTransform(hDC, &xForm);
			GetClientRect(hWnd, (LPRECT)&rect);
			DPtoLP(hDC, (LPPOINT)&rect, 2);
			SelectObject(hDC, GetStockObject(WHITE_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 100), (rect.bottom / 2 + 100), (rect.right / 2 + 100),
			          (rect.bottom / 2 - 100));
			SelectObject(hDC, GetStockObject(BLACK_BRUSH));
			TextOutA(hDC, rect.right / 2 - 147, rect.bottom / 2, "Use Up/Down/Right/Left to move; Esc to go back", 47);
			SelectObject(hDC, GetStockObject(GRAY_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 13), (rect.bottom / 2 + 113), (rect.right / 2 + 13),
			          (rect.bottom / 2 + 50));
			Sleep(10);
		}
		ReleaseDC(hWnd, hDC);
		system("cls");
	}

	void Rotate(HWND hWnd)
	{
		float phi;
		std::cout << "Enter the angle of the rotation in degrees:\n";
		std::cin >> phi;
		HDC hDC;
		XFORM xForm;
		RECT rect;
		hDC = GetDC(hWnd);
		SetGraphicsMode(hDC, GM_ADVANCED);
		SetMapMode(hDC, MM_LOENGLISH);

		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			FillRect(hDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			if (GetAsyncKeyState(VK_ADD))
			{
				angle += phi;
			}
			if (GetAsyncKeyState(VK_SUBTRACT))
			{
				angle -= phi;
			}

			xForm.eM11 = (FLOAT)cos(angle * M_PI / 180.0);
			xForm.eM12 = (FLOAT)sin(angle * M_PI / 180.0);
			xForm.eM21 = (FLOAT)-sin(angle * M_PI / 180.0);
			xForm.eM22 = (FLOAT)cos(angle * M_PI / 180.0);
			xForm.eDx = (FLOAT)0.0;
			xForm.eDy = (FLOAT)0.0;

			SetWorldTransform(hDC, &xForm);
			GetClientRect(hWnd, (LPRECT)&rect);
			DPtoLP(hDC, (LPPOINT)&rect, 2);
			SelectObject(hDC, GetStockObject(WHITE_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 100), (rect.bottom / 2 + 100), (rect.right / 2 + 100),
			          (rect.bottom / 2 - 100));
			SelectObject(hDC, GetStockObject(BLACK_BRUSH));
			TextOutA(hDC, rect.right / 2 - 68, rect.bottom / 2, "Use +/- to rotate; Esc to go back", 34);
			SelectObject(hDC, GetStockObject(GRAY_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 13), (rect.bottom / 2 + 113), (rect.right / 2 + 13),
			          (rect.bottom / 2 + 50));
			Sleep(100);
		}
		ReleaseDC(hWnd, hDC);
		system("cls");
	}

	void Scale(HWND hWnd)
	{
		HDC hDC;
		XFORM xForm;
		RECT rect;
		hDC = GetDC(hWnd);
		SetGraphicsMode(hDC, GM_ADVANCED);
		SetMapMode(hDC, MM_LOENGLISH);

		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			FillRect(hDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			if (GetAsyncKeyState(VK_ADD))
			{
				scale += 0.05;
			}
			if (GetAsyncKeyState(VK_SUBTRACT))
			{
				scale -= 0.05;
			}

			xForm.eM11 = (FLOAT)scale;
			xForm.eM12 = (FLOAT)0.0;
			xForm.eM21 = (FLOAT)0.0;
			xForm.eM22 = (FLOAT)scale;
			xForm.eDx = (FLOAT)0.0;
			xForm.eDy = (FLOAT)0.0;

			SetWorldTransform(hDC, &xForm);
			GetClientRect(hWnd, (LPRECT)&rect);
			DPtoLP(hDC, (LPPOINT)&rect, 2);
			SelectObject(hDC, GetStockObject(WHITE_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 100), (rect.bottom / 2 + 100), (rect.right / 2 + 100),
			          (rect.bottom / 2 - 100));
			SelectObject(hDC, GetStockObject(BLACK_BRUSH));
			TextOutA(hDC, rect.right / 2 - 67, rect.bottom / 2, "Use +/- to scale; Esc to go back", 33);
			SelectObject(hDC, GetStockObject(GRAY_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 13), (rect.bottom / 2 + 113), (rect.right / 2 + 13),
			          (rect.bottom / 2 + 50));
			Sleep(10);
		}
		ReleaseDC(hWnd, hDC);
		system("cls");
	}

private:
	float angle = 0.0, step_w = 0.0, step_h = 0.0, scale = 0.0;
};

class rectangle
{
public:
	void Run(HWND hWnd)
	{
		HDC hDC;
		XFORM xForm;
		RECT rect;
		hDC = GetDC(hWnd);
		SetGraphicsMode(hDC, GM_ADVANCED);
		SetMapMode(hDC, MM_LOENGLISH);

		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			FillRect(hDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			if (GetAsyncKeyState(VK_LEFT))
			{
				step_w -= 10.0;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				step_w += 10.0;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				step_h -= 10.0;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				step_h += 10.0;
			}

			xForm.eM11 = (FLOAT)cos(0 * M_PI / 180.0);
			xForm.eM12 = (FLOAT)sin(0 * M_PI / 180.0);
			xForm.eM21 = (FLOAT)-sin(0 * M_PI / 180.0);
			xForm.eM22 = (FLOAT)cos(0 * M_PI / 180.0);
			xForm.eDx = (FLOAT)0.0 + step_w;
			xForm.eDy = (FLOAT)0.0 + step_h;

			SetWorldTransform(hDC, &xForm);
			GetClientRect(hWnd, (LPRECT)&rect);
			DPtoLP(hDC, (LPPOINT)&rect, 2);
			SelectObject(hDC, GetStockObject(WHITE_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 100), (rect.bottom / 2 + 60), (rect.right / 2 + 100),
			          (rect.bottom / 2 - 60));
			SelectObject(hDC, GetStockObject(BLACK_BRUSH));
			TextOutA(hDC, rect.right / 2 - 147, rect.bottom / 2, "Use Up/Down/Right/Left to move; Esc to go back", 47);
			SelectObject(hDC, GetStockObject(GRAY_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 13), (rect.bottom / 2 + 113), (rect.right / 2 + 13),
			          (rect.bottom / 2 + 50));
			Sleep(10);
		}
		ReleaseDC(hWnd, hDC);
		system("cls");
	}

	void Rotate(HWND hWnd)
	{
		float phi;
		std::cout << "Enter the angle of the rotation in degrees:\n";
		std::cin >> phi;
		HDC hDC;
		XFORM xForm;
		RECT rect;
		hDC = GetDC(hWnd);
		SetGraphicsMode(hDC, GM_ADVANCED);
		SetMapMode(hDC, MM_LOENGLISH);

		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			FillRect(hDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			if (GetAsyncKeyState(VK_ADD))
			{
				angle += phi;
			}
			if (GetAsyncKeyState(VK_SUBTRACT))
			{
				angle -= phi;
			}

			xForm.eM11 = (FLOAT)cos(angle * M_PI / 180.0);
			xForm.eM12 = (FLOAT)sin(angle * M_PI / 180.0);
			xForm.eM21 = (FLOAT)-sin(angle * M_PI / 180.0);
			xForm.eM22 = (FLOAT)cos(angle * M_PI / 180.0);
			xForm.eDx = (FLOAT)0.0;
			xForm.eDy = (FLOAT)0.0;

			SetWorldTransform(hDC, &xForm);
			GetClientRect(hWnd, (LPRECT)&rect);
			DPtoLP(hDC, (LPPOINT)&rect, 2);
			SelectObject(hDC, GetStockObject(WHITE_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 100), (rect.bottom / 2 + 60), (rect.right / 2 + 100),
			          (rect.bottom / 2 - 60));
			SelectObject(hDC, GetStockObject(BLACK_BRUSH));
			TextOutA(hDC, rect.right / 2 - 68, rect.bottom / 2, "Use +/- to rotate; Esc to go back", 34);
			SelectObject(hDC, GetStockObject(GRAY_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 13), (rect.bottom / 2 + 113), (rect.right / 2 + 13),
			          (rect.bottom / 2 + 50));
			Sleep(100);
		}
		ReleaseDC(hWnd, hDC);
		system("cls");
	}

	void Scale(HWND hWnd)
	{
		HDC hDC;
		XFORM xForm;
		RECT rect;
		hDC = GetDC(hWnd);
		SetGraphicsMode(hDC, GM_ADVANCED);
		SetMapMode(hDC, MM_LOENGLISH);

		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			FillRect(hDC, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
			if (GetAsyncKeyState(VK_ADD))
			{
				scale += 0.05;
			}
			if (GetAsyncKeyState(VK_SUBTRACT))
			{
				scale -= 0.05;
			}

			xForm.eM11 = (FLOAT)scale;
			xForm.eM12 = (FLOAT)0.0;
			xForm.eM21 = (FLOAT)0.0;
			xForm.eM22 = (FLOAT)scale;
			xForm.eDx = (FLOAT)0.0;
			xForm.eDy = (FLOAT)0.0;

			SetWorldTransform(hDC, &xForm);
			GetClientRect(hWnd, (LPRECT)&rect);
			DPtoLP(hDC, (LPPOINT)&rect, 2);
			SelectObject(hDC, GetStockObject(WHITE_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 100), (rect.bottom / 2 + 60), (rect.right / 2 + 100),
			          (rect.bottom / 2 - 60));
			SelectObject(hDC, GetStockObject(BLACK_BRUSH));
			TextOutA(hDC, rect.right / 2 - 67, rect.bottom / 2, "Use +/- to scale; Esc to go back", 33);
			SelectObject(hDC, GetStockObject(GRAY_BRUSH));
			Rectangle(hDC, (rect.right / 2 - 13), (rect.bottom / 2 + 113), (rect.right / 2 + 13),
			          (rect.bottom / 2 + 50));
			Sleep(10);
		}
		ReleaseDC(hWnd, hDC);
		system("cls");
	}

private:
	float angle = 0.0, step_w = 0.0, step_h = 0.0, scale = 0.0;
};


int main()
{
	HWND hWnd = GetConsoleWindow();
	circle cfigure;
	square sfigure;
	rectangle rfigure;

point1:
	system("cls");
	std::cout <<
		"Menu\n\nTap:\n1 to move a circle\n2 to rotate a circle\n3 to scale a circle\n4 to move a square\n5 to rotate a square\n6 to scale a square\n7 to move a rectangle\n8 to rotate a rectangle\n9 to scale a rectangle\nBackspace to exit\n";
	switch (_getch())
	{
	case '1': cfigure.Run(hWnd);
		goto point1;
	case '2': cfigure.Rotate(hWnd);
		goto point1;
	case '3': cfigure.Scale(hWnd);
		goto point1;
	case '4': sfigure.Run(hWnd);
		goto point1;
	case '5': sfigure.Rotate(hWnd);
		goto point1;
	case '6': sfigure.Scale(hWnd);
		goto point1;
	case '7': rfigure.Run(hWnd);
		goto point1;
	case '8': rfigure.Rotate(hWnd);
		goto point1;
	case '9': rfigure.Scale(hWnd);
		goto point1;
	case VK_BACK: system("cls");
		std::cout << "bye-bye\n";
		exit(7);
	default: goto point1;
	}
}
