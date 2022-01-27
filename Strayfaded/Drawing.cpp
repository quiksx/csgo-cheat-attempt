#include "include.h"

void DrawFilledRect(int x, int y, int w, int h, D3DCOLOR col)
{
	D3DRECT rect = { x, y, x + w, y + h };
	DirectXDevice->Clear(1, &rect, D3DCLEAR_TARGET, col, 0, 0);
}
void DrawLine(int x1, int y1, int x2, int y2, int thickness, bool antialias, D3DCOLOR col)
{
	ID3DXLine* lineL;
	D3DXCreateLine(DirectXDevice, &lineL);

	D3DXVECTOR2 Line[2];
	Line[0] = D3DXVECTOR2(x1, y1);
	Line[1] = D3DXVECTOR2(x2, y2);
	
	lineL->SetWidth(thickness);
	lineL->SetAntialias(antialias);
	lineL->Draw(Line, 2, col);
	lineL->Release();
}
void DrawBoundingBox(int baseX, int baseY, int width, int height, int thickness, bool antialias, D3DCOLOR color)
{
	DrawLine(baseX - width / 2, baseY, baseX + width / 2, baseY, thickness, antialias, color);
	DrawLine(baseX - width / 2, baseY - height, baseX - width / 2, baseY, thickness, antialias, color);
	DrawLine(baseX + width / 2, baseY - height, baseX + width / 2, baseY, thickness, antialias, color);
	DrawLine(baseX - width / 2, baseY - height, baseX + width / 2, baseY - height, thickness, antialias, color);
}