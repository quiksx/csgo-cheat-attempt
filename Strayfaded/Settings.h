#include "include.h"

inline D3DCOLOR ImColor_D3D(ImColor Input)
{
	return D3DCOLOR_RGBA(
		(int)(Input.Value.x * 255.0f),
		(int)(Input.Value.y * 255.0f),
		(int)(Input.Value.z * 255.0f),
		(int)(Input.Value.w * 255.0f)
	);
}

class ASettings
{
public:

	// JRESP
	bool EnableJRESP = false;
	float BoundingBoxesWidth = 0.5f;
	int BoundingBoxesThickness = 1;
	ImColor BoxColor = { 1.0f, 1.0f, 1.0f, 1.0f };

	int TracerBone = 1;
	int TracerThickness = 1;
	ImColor TracerColor = { 1.0f, 1.0f, 1.0f, 1.0f };


	// JRADAR
	bool EnableJRADAR = false;


	// Global
	bool Global_Antialias = true;



};