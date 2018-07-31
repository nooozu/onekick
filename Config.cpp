#include "Config.h"

Config::Config(ISceneChanger* changer) : BaseScene(changer)
{
}

void Config::Initialize()
{
}

void Config::Finalize()
{
}

void Config::Update()
{
}

void Config::Draw()
{
	PutText(L"Config").from(0, 0);
}
