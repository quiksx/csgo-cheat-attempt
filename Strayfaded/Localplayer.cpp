#include "include.h"

DWORD LocalPlayer::Get()
{
	return *(DWORD*)(Global_GameModule + dwLocalPlayer);
}
int LocalPlayer::GetHealth()
{
	DWORD Player = Get();
	if (Player)
		return *(int*)(Player + m_iHealth);
	return -1;
}
int LocalPlayer::GetTeam()
{
	DWORD Player = Get();
	if (Player)
		return *(int*)(Player + m_iTeamNum);
	return -1;
}
int LocalPlayer::CrosshairID()
{
	DWORD Player = Get();
	if (Player)
		return *(int*)(Player + m_iCrosshairId);
	return -1;
}
bool LocalPlayer::Exists()
{
	if (*(DWORD*)(Global_GameModule + dwLocalPlayer))
		return true;
	return false;
}

Vec3 LocalPlayer::GetLocation()
{
	DWORD Player = Get();
	if (Player)
		return *(Vec3*)(Player + m_vecOrigin);
	return { 0, 0, 0, };
}

Vec3 LocalPlayer::GetBonePosition(int Bone)
{
	DWORD Player = Get();
	if (Player)
	{
		uintptr_t BoneMatrixBase = *(uintptr_t*)(Player + m_dwBoneMatrix);
		BoneMatrix BoneMat = *(BoneMatrix*)(BoneMatrixBase + sizeof(Bone) * Bone);
		Vec3 Location = { BoneMat.x, BoneMat.y, BoneMat.z };
		return Location;
	}
	return { 0, 0, 0 };
}
Vec2 LocalPlayer::GetBonePositionScreen(int Bone)
{
	DWORD Player = Get();
	if (Player)
	{
		uintptr_t BoneMatrixBase = *(uintptr_t*)(Player + m_dwBoneMatrix);
		BoneMatrix BoneMat = *(BoneMatrix*)(BoneMatrixBase + sizeof(Bone) * Bone);
		Vec3 Location = { BoneMat.x, BoneMat.y, BoneMat.z };

		float Matrix[16];
		Vec2 Out;
		memcpy(&Matrix, (PBYTE*)(Global_GameModule + dwViewMatrix), sizeof(Matrix));
		if (WTS(Location, Out, Matrix))
		{
			return Out;
		}
	}
	return { 0, 0 };
}