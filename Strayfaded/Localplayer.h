#include "include.h"

class LocalPlayer
{
public:
	DWORD Get();

	bool Exists();
	
	int GetHealth();
	int GetTeam();
	int CrosshairID();

	Vec3 GetLocation();
	Vec3 GetBonePosition(int Bone);
	Vec2 GetBonePositionScreen(int Bone);
};