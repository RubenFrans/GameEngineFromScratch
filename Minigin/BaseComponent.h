#pragma once
class BaseComponent
{
public:
	BaseComponent() = default;
	virtual ~BaseComponent() = default;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
private:
};

