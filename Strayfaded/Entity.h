#include "include.h"

class Entity
{
public:
	DWORD Get(int Index);

	int GetHealth(DWORD Entity);
	int GetTeam(DWORD Entity);

	Vec3 GetLocation(DWORD Entity);
	Vec3 GetBonePosition(DWORD Entity, int Bone);
	Vec2 GetBonePositionScreen(DWORD Entity, int Bone);
};