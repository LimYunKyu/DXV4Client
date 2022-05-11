#pragma once


class Engine
{
public:

	void Init(WindowInfo _info);
	void Update();
	void Render();

private:
	void CreateRenderTargetGroups();
public:
	WindowInfo GetWinfo() { return mWinfo; }
	
private:
	WindowInfo mWinfo;
	//array<shared_ptr<RenderTargetGroup>, RENDER_TARGET_GROUP_COUNT> _rtGroups;
};

