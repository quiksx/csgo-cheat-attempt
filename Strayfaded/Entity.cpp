#include "include.h"

DWORD Entity::Get(int Index)
{
	return *(DWORD*)(Global_GameModule + dwEntityList + (Index * 0x10));
}
int Entity::GetHealth(DWORD Entity)
{
	return *(int*)(Entity + m_iHealth);
}
int Entity::GetTeam(DWORD Entity)
{
	return *(int*)(Entity + m_iTeamNum);
}


Vec3 Entity::GetLocation(DWORD Entity)
{
		return *(Vec3*)(Entity + m_vecOrigin);
}
Vec3 Entity::GetBonePosition(DWORD Entity, int Bone)
{
	uintptr_t BoneMatrixBase = *(uintptr_t*)(Entity + m_dwBoneMatrix);
	BoneMatrix BoneMat = *(BoneMatrix*)(BoneMatrixBase + sizeof(Bone) * Bone);
	Vec3 Location = { BoneMat.x, BoneMat.y, BoneMat.z };
	return Location;
}
Vec2 Entity::GetBonePositionScreen(DWORD Entity, int Bone)
{
	uintptr_t BoneMatrixBase = *(uintptr_t*)(Entity + m_dwBoneMatrix);
	BoneMatrix BoneMat = *(BoneMatrix*)(BoneMatrixBase + sizeof(Bone) * Bone);
	Vec3 Location = { BoneMat.x, BoneMat.y, BoneMat.z };

	float Matrix[16];
	Vec2 Out;
	memcpy(&Matrix, (PBYTE*)(Global_GameModule + dwViewMatrix), sizeof(Matrix));
	if (WTS(Location, Out, Matrix))
	{
		return Out;
	}
	return { 0, 0 };
}