#pragma once
#include "BaseComponent.h"

class Font;

class TextComponent :
    public BaseComponent
{
public:
	TextComponent() = default;
	virtual ~TextComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;

	void SetText(const std::string& text);

private:
	bool m_NeedsUpdate;
	std::string m_Text;
	std::shared_ptr<Font> m_Font;
};

